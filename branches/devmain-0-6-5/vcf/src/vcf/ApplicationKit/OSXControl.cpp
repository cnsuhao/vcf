/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXControl.h"



class OSXControlView : public TView {
public:

	OSXControlView( HIViewRef inControl ):
		TView(inControl), osxControl_(NULL){
		
		VCF::OSXControl::setCurrentCreateHIView( this );
	}
	
	virtual ~OSXControlView() {
	
	}

	virtual UInt32 GetBehaviors() {
		return TView::GetBehaviors() | kHIViewAllowsSubviews;
	}

	void setOSXControl( VCF::OSXControl* val ) {
		osxControl_ = val ;
	}
									
	virtual ControlKind GetKind() {
		const ControlKind result = { 'vcCv', 'vcCv' };	
		return result;
	}
	
	virtual OSStatus GetRegion( ControlPartCode inPart, RgnHandle outRgn ) {
		OSStatus			err = noErr;
		TRect				bounds;
		Rect				qdBounds;
		
		if ( inPart == kControlContentMetaPart
				|| inPart == kControlStructureMetaPart
				/* || inPart == kControlOpaqueRegionMetaPart */ )
		{
			bounds = Bounds();
			qdBounds = bounds;
		
			RectRgn( outRgn, &qdBounds );
		}
		
		return err;
	}

	virtual void Draw( RgnHandle inLimitRgn, CGContextRef inContext, GrafPtr port ) {
	
	}	
protected:
	VCF::OSXControl* osxControl_;
};


namespace VCF {

static const EventTypeSpec osxHIViewEvents[] =
{	{ kEventClassCommand, kEventCommandProcess },
	{ kEventClassCommand, kEventCommandUpdateStatus },
	
	{ kEventClassControl, kEventControlInitialize },
	{ kEventClassControl, kEventControlDraw },
	{ kEventClassControl, kEventControlHitTest },
	{ kEventClassControl, kEventControlGetPartRegion },
	{ kEventClassControl, kEventControlGetData },
	{ kEventClassControl, kEventControlSetData },
	{ kEventClassControl, kEventControlGetOptimalBounds },
	{ kEventClassControl, kEventControlBoundsChanged },
	{ kEventClassControl, kEventControlTrack },
	{ kEventClassControl, kEventControlGetSizeConstraints },
	{ kEventClassControl, kEventControlHit },
	
	{ kEventClassMouse, kEventMouseDown },
	{ kEventClassMouse, kEventMouseUp },
	{ kEventClassMouse, kEventMouseMoved },
	{ kEventClassMouse, kEventMouseDragged },
	{ kEventClassMouse, kEventMouseEntered },
	{ kEventClassMouse, kEventMouseExited },
	{ kEventClassMouse, kEventMouseWheelMoved },
	{ kEventClassKeyboard, kEventRawKeyDown },
	{ kEventClassKeyboard, kEventRawKeyUp },
							
	{ kEventClassControl, kEventControlHiliteChanged },
	{ kEventClassControl, kEventControlActivate },
	{ kEventClassControl, kEventControlDeactivate },
	{ kEventClassControl, kEventControlValueFieldChanged },
	{ kEventClassControl, kEventControlTitleChanged },
	{ kEventClassControl, kEventControlEnabledStateChanged },
	{ kEventClassControl, kEventControlOwningWindowChanged },
	{ kEventClassControl, kEventControlVisibilityChanged }
};



TView* OSXControl::currentCreatedView = NULL;




OSXControl::OSXControl( Control* control ):
	hiView_(NULL),
	control_(control),
	handlerRef_(NULL)
{

}

OSXControl::~OSXControl()
{

}

void OSXControl::setCurrentCreateHIView( TView* view )
{
	static Mutex* currentCreateMtx = NULL;
	
	if ( NULL == currentCreateMtx ) {
		currentCreateMtx = new Mutex();
	}
	
	Lock l(*currentCreateMtx);
	OSXControl::currentCreatedView = view;
}

long OSXControl::getHandleID()
{
	return (long) hiView_->GetViewRef();
}

EventHandlerUPP OSXControl::getEventHandlerUPP()
{
    static EventHandlerUPP result = NULL;
    if ( NULL == result ) {
        result = NewEventHandlerUPP( OSXControl::handleOSXEvents );
    }
    return result;
}

void OSXControl::create( Control* owningControl )
{
	HIViewRef view = NULL;
	TRect bounds(0,0,0,0);
	
	if ( noErr == ViewCreator<OSXControlView>::create( &view, bounds, NULL ) ) {
		hiView_ = OSXControl::getCurrentCreateHIView();
 		OSXControlView* osxView = (OSXControlView*)hiView_;
		osxView->setOSXControl( this );
		control_ = owningControl;
		
		SetControlProperty( hiView_->GetViewRef(), 'vcfa', 'vcfc', sizeof(void*), (void*)control_ );
		
		
		OSStatus err = InstallEventHandler( GetControlEventTarget( hiView_->GetViewRef() ), 
							OSXControl::getEventHandlerUPP(),
							sizeof(osxHIViewEvents) / sizeof(EventTypeSpec), 
							osxHIViewEvents, 
							this, 
							&handlerRef_ );
							
		if ( err != noErr ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("InstallEventHandler failed for OSXControlView!") );
		}
		
		
        
	}
	else {
		throw RuntimeException( MAKE_ERROR_MSG_2("OSXControlView failed to be created!") );
	}	
}

void OSXControl::destroyControl()
{

}


void OSXControl::setBounds( Rect* rect )
{
	TRect r( rect->left_, rect->top_, rect->getWidth(), rect->getHeight() );	
	HIViewSetFrame( hiView_->GetViewRef(), r );
}

bool OSXControl::beginSetBounds( const ulong32& numberOfChildren )
{
	return true;
}

void OSXControl::endSetBounds()
{

}

Rect OSXControl::getBounds()
{
	Rect result;
	
	TRect r = hiView_->Frame();
	
	result.setRect( r.origin.x, r.origin.y, r.origin.x + r.size.width, r.origin.y + r.size.height ); 
	
	return result;
}

void OSXControl::setVisible( const bool& visible )
{
	if ( visible ) {
		hiView_->Show();
	}
	else {
		hiView_->Hide();
	}
}

bool OSXControl::getVisible()
{
	return hiView_->IsVisible() ? true : false;
}

Control* OSXControl::getControl()
{
	return control_;
}

void OSXControl::setControl( Control* component )
{
	control_ = component;
}

void OSXControl::setCursor( Cursor* cursor )
{

}

void OSXControl::setParent( Control* parent )
{
	Window* windowParent = dynamic_cast<Window*>(parent);
	if ( NULL != windowParent ) {
 		WindowRef wndRef = (WindowRef)parent->getPeer()->getHandleID();
		ControlRef root = NULL;
		GetRootControl( wndRef, &root );
		HIViewAddSubview( root, hiView_->GetViewRef() );		
	}
	else {
		ControlRef parentControlRef = (ControlRef)parent->getPeer()->getHandleID();
		OSStatus err = HIViewAddSubview( parentControlRef, hiView_->GetViewRef() );
		if ( err != noErr ) {
			StringUtils::traceWithArgs( "HIViewAddSubview failed, err: %d\n", err );
		}
	}
}

Control* OSXControl::getParent()
{
	Control* result = NULL;
	HIViewRef parentRef = HIViewGetSuperview( hiView_->GetViewRef() );	
	
	void* ptr = NULL;
	OSStatus err = GetControlProperty( parentRef, 'vcfa', 'vcfc', sizeof(void*), NULL, &ptr );
	if ( err == noErr ) {
		result = (VCF::Control*)ptr;
	}	
	return result;
}

bool OSXControl::isFocused()
{
	WindowRef wnd = hiView_->GetOwner();
	ControlRef focusedControl = NULL;
	GetKeyboardFocus( wnd, &focusedControl );	
	
	return ( hiView_->GetViewRef() == focusedControl ) ? true : false;
}

void OSXControl::setFocused()
{
	HIViewSetNextFocus( hiView_->GetViewRef(), NULL );
}

bool OSXControl::isEnabled()
{
	return hiView_->IsEnabled() ? true : false;
}

void OSXControl::setEnabled( const bool& enabled )
{
	if ( enabled ) {
		EnableControl( hiView_->GetViewRef() );
	}
	else {
		DisableControl( hiView_->GetViewRef() );
	}
}

void OSXControl::setFont( Font* font )
{

}

void OSXControl::repaint( Rect* repaintRect=NULL )
{
	hiView_->Invalidate();
}

void OSXControl::keepMouseEvents()
{

}

void OSXControl::releaseMouseEvents()
{

}

void OSXControl::translateToScreenCoords( Point* pt )
{

}

void OSXControl::translateFromScreenCoords( Point* pt )
{

}


OSStatus OSXControl::handleOSXEvents(EventHandlerCallRef nextHandler, EventRef theEvent, void* userData)
{
	OSXControl* control = (OSXControl*)userData;
    
    return control->handleOSXEvent( nextHandler, theEvent );
}

OSStatus OSXControl::handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent )
{
	OSStatus result = eventNotHandledErr;
    
    OSXEventMsg msg( theEvent, control_ );
    Event* vcfEvent = UIToolkit::createEventFromNativeOSEventData( &msg );

//	{ kEventClassControl, kEventControlDeactivate },
	
    UInt32 whatHappened = GetEventKind (theEvent);
	switch ( GetEventClass( theEvent ) )  {	
		case kEventClassControl : {
			switch( whatHappened ) {
				case kEventControlActivate : {
					result = ::CallNextEventHandler( nextHandler, theEvent ); 
					
					hiView_->Invalidate();					
					
					if ( !control_->isDestroying() ) {
					
							
						if ( NULL != vcfEvent ) {
							control_->handleEvent( vcfEvent );
						}
					}
				}
				break;

				case kEventControlDraw : {
					result = ::CallNextEventHandler( nextHandler, theEvent ); 
				
					if ( !control_->isDestroying() ) {
						TCarbonEvent		event( theEvent );
						
						StringUtils::trace( "OSXControl::handleOSXEvent(), kEventClassControl, kEventControlDraw\n" );
						
						GrafPtr port = NULL;										
						CGContextRef context = NULL;
						RgnHandle region = NULL;
						
						event.GetParameter( kEventParamRgnHandle, &region );
						event.GetParameter<CGContextRef>( kEventParamCGContextRef, typeCGContextRef, &context );
						event.GetParameter<GrafPtr>( kEventParamGrafPort, typeGrafPtr, &port );						
						
						GrafPtr oldPort;
						//GetPort( &oldPort );
						//SetPort( port );
						
						::Rect bounds = RectProxy( control_->getClientBounds() );
						
						EraseRect( &bounds );
						//EraseRgn( region );
						
						VCF::GraphicsContext* ctx = control_->getContext();
						
						ctx->setViewableBounds( control_->getClientBounds() );
						
						OSXContext* osxCtx =  (OSXContext*)ctx->getPeer();
						osxCtx->setCGContext( context, port );
		
						control_->paint( ctx );	
						
						osxCtx->setCGContext( NULL, 0 );
		
						//SetPort( oldPort );
		
						result = noErr;
					}
				}
				break;
				
				default : {
                    result = CallNextEventHandler( nextHandler, theEvent );
					
                    if ( !control_->isDestroying() ) {
						if ( NULL != vcfEvent ) {
							control_->handleEvent( vcfEvent );
						}
					}
                }
                break;
			}
		}
		break;
		
		default : {
            result = CallNextEventHandler( nextHandler, theEvent );
        }
        break; 
	}
	
	if ( NULL != vcfEvent ) {
        delete vcfEvent;
    }
	
	return result;
}


	
};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.6  2004/05/23 14:11:59  ddiego
*osx updates
*
*Revision 1.1.2.5  2004/05/16 05:31:06  ddiego
*OSX code updates. Add basics for custom control peers.
*
*Revision 1.1.2.4  2004/05/16 02:39:01  ddiego
*OSX code updates
*
*
*/
