//OSXControl.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXControl.h"
#include "vcf/ApplicationKit/WindowPeer.h"
#include "vcf/ApplicationKit/OSXLightweightControl.h"
#include "vcf/ApplicationKit/OSXWindow.h"




class OSXControlView : public TView {
public:
	

	OSXControlView( HIViewRef inControl ):
		TView(inControl){
		
	}
	
	virtual ~OSXControlView() {
	
	}

	virtual OSStatus Initialize( TCarbonEvent& inEvent ) {
		OSStatus res = TView::Initialize( inEvent );
		
		return res;
	}
	
	
	virtual UInt32 GetBehaviors() {
		return TView::GetBehaviors() | kHIViewAllowsSubviews | kHIViewDoesNotUseSpecialParts;
            //kControlSupportsEmbedding | kControlSupportsFocus |
            //kControlWantsActivate | kControlHandlesTracking |
            //kControlGetsFocusOnClick | kControlSupportsClickActivation;
	}
	
	
	virtual ControlPartCode HitTest( const HIPoint& inWhere ) {
		ControlPartCode		part;
		
		// Is the mouse in the view?
		if ( CGRectContainsPoint( Bounds(), inWhere ) )
			part = 1;
		else
			part = kControlNoPart;
		
		return part;
	}

									
	virtual ControlKind GetKind() {
		const ControlKind result = { 'OSXv', 'OSXy' };	
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
	switch ( GetControlHilite( GetViewRef() ) )
	{
		case kControlNoPart:
			CGContextSetRGBFillColor( inContext, 0, 1, 0, 0.25 );
			CGContextSetRGBStrokeColor( inContext, 0, 1, 0, 1 );
			break;

		// Handle synthetic highlights, too
		case kControlInactivePart:
		case kControlDisabledPart:
			CGContextSetRGBFillColor( inContext, 0, 0, 0, 0.10 );
			CGContextSetRGBStrokeColor( inContext, 0, 0, 0, 0.10 );
			break;
		
		default:
			CGContextSetRGBFillColor( inContext, 1, 0, 1, 0.25 );
			CGContextSetRGBStrokeColor( inContext, 1, 0, 1, 1 );
			break;
	}
	CGContextFillRect( inContext, Bounds() );
	CGContextStrokeRect( inContext, Bounds() );
	}	
protected:

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
	
	{ kEventClassKeyboard, kEventRawKeyDown },
	{ kEventClassKeyboard, kEventRawKeyUp },
							
	{ kEventClassControl, kEventControlHiliteChanged },
	{ kEventClassControl, kEventControlActivate },
	{ kEventClassControl, kEventControlDeactivate },
	{ kEventClassControl, kEventControlValueFieldChanged },
	{ kEventClassControl, kEventControlTitleChanged },
	{ kEventClassControl, kEventControlEnabledStateChanged },
	{ kEventClassControl, kEventControlOwningWindowChanged },
    { kEventClassControl, kEventControlSetFocusPart }
    
};





OSXControl::OSXControl( Control* control ):
	hiView_(NULL),
	control_(control),
	handlerRef_(NULL),
	mouseState_(OSXControl::msNoState)
{

}

OSXControl::~OSXControl()
{

}

long OSXControl::getHandleID()
{
	return (long) hiView_;
}

EventHandlerUPP OSXControl::getEventHandlerUPP()
{
    static EventHandlerUPP result = NULL;
    if ( NULL == result ) {
        result = NewEventHandlerUPP( OSXControl::handleOSXEvents );
    }
    return result;
}

OSXControl* OSXControl::getControlFromControlRef( ControlRef control )
{
	OSXControl* result = NULL;
	
	if ( noErr != GetControlProperty( control, VCF_PROPERTY_CREATOR, 
									  VCF_PROPERTY_CONTROL_VAL, 
									  sizeof(OSXControl*), NULL, &result ) ) {
		result = NULL;
	}
	return result;
}

void OSXControl::create( Control* owningControl )
{
	TRect bounds(0,0,0,0);
	
	if ( noErr == ViewCreator<OSXControlView>::create( &hiView_, bounds, NULL ) ) {
		//hiView_ = OSXControl::getCurrentCreateHIView();
		//;;VCF::CFTextString classID;
		//;;VCF::String className = VCF::StringUtils::getClassNameFromTypeInfo( typeid(OSXControlView) );
		//classID = className;
		
		//hiView_ =  (TView*) HIObjectDynamicCast( (HIObjectRef)view, classID );
		//printf( "instance: %p\n", hiView_ );
		
 		//OSStatus err = GetControlProperty( view, VCF_PROPERTY_OSXHIVIEW_CREATOR, 
		//							  VCF_PROPERTY_OSXHIVIEW_VAL, 
		//							  sizeof(TView*), NULL, &hiView_ );		
		
		control_ = owningControl;
		OSXControl* thisPtr = this;
		SetControlProperty( hiView_, 
							VCF_PROPERTY_CREATOR, 
							VCF_PROPERTY_CONTROL_VAL, 
							sizeof(thisPtr), 
							&thisPtr );
							
		
		OSStatus err = InstallEventHandler( GetControlEventTarget( hiView_ ), 
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
	HIViewSetFrame( hiView_, r );
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
	
	HIRect		frame;	
	HIViewGetFrame( hiView_, &frame );
	
	TRect r = frame;
	
	result.setRect( r.origin.x, r.origin.y, r.origin.x + r.size.width, r.origin.y + r.size.height ); 
	
	return result;
}

void OSXControl::setVisible( const bool& visible )
{
	HIViewSetVisible( hiView_, visible );
}

bool OSXControl::getVisible()
{
	return IsControlVisible(hiView_) ? true : false;
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
	Window* windowParent = NULL;
	
	if ( parent->isLightWeight() ) {
		OSXLightweightControl* lwPeer = (OSXLightweightControl*) parent->getPeer();
		
		windowParent = dynamic_cast<Window*>(lwPeer->getHeavyWeightParent());
	}
	else {
		windowParent = dynamic_cast<Window*>(parent);
	}
	
	
	if ( NULL != windowParent ) {
 		OSXWindow* osxWnd = (OSXWindow*)parent->getPeer();
		WindowRef wnd = (WindowRef) osxWnd->getHandleID();
		
		ControlRef contentView = osxWnd->getRootControl();
		//HIViewFindByID(HIViewGetRoot(wnd), kHIViewWindowContentID, &contentView);		
					
		OSStatus err = HIViewAddSubview( contentView, hiView_ );		
	}
	else {
		ControlRef parentControlRef = (ControlRef)parent->getPeer()->getHandleID();
		OSStatus err = HIViewAddSubview( parentControlRef, hiView_ );
		//printf( "HIViewAddSubview( parentControlRef: %p, hiView_: %p ): %d\n", parentControlRef, hiView_, err );
		if ( err != noErr ) {
			StringUtils::traceWithArgs( "HIViewAddSubview failed, err: %d\n", err );
		}
	}
}

Control* OSXControl::getParent()
{
	Control* result = NULL;
	HIViewRef parentRef = HIViewGetSuperview( hiView_ );	
	
	OSXControl* parentPeer = OSXControl::getControlFromControlRef( parentRef );
	if ( NULL != parentPeer ) {
		result = parentPeer->getControl();
	}
	
	return result;
}

bool OSXControl::isFocused()
{
	WindowRef wnd = GetControlOwner( hiView_ );
	ControlRef focusedControl = NULL;
	GetKeyboardFocus( wnd, &focusedControl );	
	
	return ( hiView_ == focusedControl ) ? true : false;
}

void OSXControl::setFocused()
{
    EventModifiers mods = 0;
	HIViewAdvanceFocus( hiView_, mods );    
}

bool OSXControl::isEnabled()
{
	return IsControlEnabled( hiView_ ) ? true : false;
}

void OSXControl::setEnabled( const bool& enabled )
{
	if ( enabled ) {
		EnableControl( hiView_ );
	}
	else {
		DisableControl( hiView_ );
	}
}

void OSXControl::setFont( Font* font )
{

}

void OSXControl::repaint( Rect* repaintRect=NULL )
{
	HIViewSetNeedsDisplay( hiView_, true );
}

void OSXControl::keepMouseEvents()
{

}

void OSXControl::releaseMouseEvents()
{

}

void OSXControl::translateToScreenCoords( Point* pt )
{
	HIPoint tmpPt;
	tmpPt.x = pt->x_;
	tmpPt.y = pt->y_;
	
	HIViewConvertPoint( &tmpPt, hiView_, NULL );
	::Rect r;
	GetWindowBounds( GetControlOwner(hiView_), kWindowStructureRgn, &r );
	tmpPt.x += r.left;
	tmpPt.y += r.top;
	
	pt->x_ = tmpPt.x;
	pt->y_ = tmpPt.y;	
}

void OSXControl::translateFromScreenCoords( Point* pt )
{
	HIPoint tmpPt;
	tmpPt.x = pt->x_;
	tmpPt.y = pt->y_;
	::Rect r;
	GetWindowBounds( GetControlOwner(hiView_), kWindowStructureRgn, &r );
	tmpPt.x -= r.left;
	tmpPt.y -= r.top;
	
	HIViewConvertPoint( &tmpPt, NULL, hiView_ );	
	
	pt->x_ = tmpPt.x;
	pt->y_ = tmpPt.y;
}


OSStatus OSXControl::handleOSXEvents(EventHandlerCallRef nextHandler, EventRef theEvent, void* userData)
{
	OSXControl* control = (OSXControl*)userData;
    
    return control->handleOSXEvent( nextHandler, theEvent );
}

void OSXControl::setBorder( Border* border )
{
	//cause the control to repaint itself!
}

OSStatus OSXControl::handleControlTrack( EventRef theEvent )
{
	OSStatus result = noErr;
	
	unsigned long buttonDown = VCF::mbmUndefined;
	
	WindowRef wnd = GetControlOwner(hiView_);
	OSXWindow* osxWnd = OSXWindow::getWindowFromWindowRef( wnd );
	
	
	unsigned long buttonDownVal = osxWnd->getCurrentMouseBtn();
	
	//first fire off a mouse down event!
	OSXEventMsg msg( theEvent, control_ );
	
	Event* mouseDown = UIToolkit::createEventFromNativeOSEventData( &msg );
	if ( NULL != mouseDown ) {
		control_->handleEvent( mouseDown );
		mouseDown->free();
	}
	
	
	::Point lastPt;
	MouseTrackingResult trackMouseRes;
	bool quitTracking = false;
	OSStatus err = 0;
	UInt32 mods = 0;
	
	while ( !quitTracking ) {
		err = TrackMouseLocationWithOptions( NULL, 0, 0.5, &lastPt, &mods, & trackMouseRes );
		
		if ( noErr != err ) {
			quitTracking = true;
			break;
		}
		
		if ( trackMouseRes == kMouseTrackingMouseUp ) {									   
												
			quitTracking = true;
			break;
		}
		else if ( (trackMouseRes == kMouseTrackingMouseMoved) || (trackMouseRes == kMouseTrackingMouseDragged) ) {
			unsigned long mouseBtnDown = 0;
			if ( trackMouseRes == kMouseTrackingMouseMoved ) {
				mouseBtnDown = buttonDown;
			}
			else if ( trackMouseRes == kMouseTrackingMouseDragged ) {
				mouseBtnDown = buttonDownVal;
			}
			LocalToGlobal( &lastPt );
			VCF::Point pt( lastPt.h , lastPt.v );
			//localizes the coords
			translateFromScreenCoords( &pt );	
			
			Scrollable* scrollable = control_->getScrollable();
			if ( NULL != scrollable ) {
				pt.x_ += scrollable->getHorizontalPosition();
				pt.y_ += scrollable->getVerticalPosition();
			}
			
			
			Event* mouseMove = new VCF::MouseEvent ( control_, Control::MOUSE_MOVE,
										   mouseBtnDown,
										   OSXUtils::translateKeyMask( mods ), &pt );
										   
			control_->handleEvent( mouseMove );
			mouseMove->free();
		}		
	}
	
	//fire mouse up!
	LocalToGlobal( &lastPt );
	VCF::Point pt( lastPt.h , lastPt.v );
	
	//localizes the coords
	translateFromScreenCoords( &pt );			
	
	Scrollable* scrollable = control_->getScrollable();
	if ( NULL != scrollable ) {
		pt.x_ += scrollable->getHorizontalPosition();
		pt.y_ += scrollable->getVerticalPosition();
	}
	
	Event* mouseUp = new VCF::MouseEvent ( control_, Control::MOUSE_UP,
										   mbmLeftButton,
										   OSXUtils::translateKeyMask( mods ), &pt );
	control_->handleEvent( mouseUp );
	mouseUp->free();
			
		
	return result;
}

OSStatus OSXControl::handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent )
{
	OSStatus result = eventNotHandledErr;
    
	
    OSXEventMsg msg( theEvent, control_ );
    Event* vcfEvent = UIToolkit::createEventFromNativeOSEventData( &msg );

//	{ kEventClassControl, kEventControlDeactivate },
	
    UInt32 whatHappened = GetEventKind (theEvent);
	TCarbonEvent event( theEvent );
	
	switch ( GetEventClass( theEvent ) )  {	
		case kEventClassControl : {
			switch( whatHappened ) {
				
				case kEventControlHitTest: {
					result = ::CallNextEventHandler( nextHandler, theEvent );
				/*
					HIPoint where;
					ControlPartCode part;
					
					result = noErr;//::CallNextEventHandler( nextHandler, theEvent );
					event.GetParameter<HIPoint>( kEventParamMouseLocation, typeHIPoint, &where );
					//part = HitTest( where );
					if ( CGRectContainsPoint( hiView_->Bounds(), where ) ) {
						part = 1;
					}
					else {
						part = kControlNoPart;
					}
					event.SetParameter<ControlPartCode>( kEventParamControlPart, typeControlPartCode, part );
					
					printf( "\n\nkEventControlHitTest where: %0.3f,%0.3f, part: %d, class: %s\n",
												where.x, where.y, part, control_->getClassName().ansi_c_str() );
												
					if ( !control_->isDestroying() ) {
					
							
						if ( NULL != vcfEvent ) {
							control_->handleEvent( vcfEvent );
						}
					}
					*/		
				}
				break;
				
				case kEventControlTrack : {
					printf( "kEventControlTrack\n" );
					
					//do mouse tracking to catch the rest!
					handleControlTrack( theEvent );
					
					result = noErr;//::CallNextEventHandler( nextHandler, theEvent );
				}
				
				case kEventControlHit: {
					result = ::CallNextEventHandler( nextHandler, theEvent );
				
					/*									
					if ( !control_->isDestroying() && (NULL != vcfEvent) ) {
						
						if ( OSXControl::msNoState == mouseState_ ) {							
							control_->handleEvent( vcfEvent );
							mouseState_ = OSXControl::msDown;
							printf( "kEventControlHit, mouseState_ = OSXControl::msDown\n" );
						}
						else if ( OSXControl::msDown == mouseState_ ) {
							mouseState_ = OSXControl::msUp;
							
							MouseEvent* tmpEvent = (MouseEvent*)vcfEvent;
							
							MouseEvent mouseEvent( tmpEvent->getSource(), Control::MOUSE_UP,
													tmpEvent->getButtonMask(),
													tmpEvent->getKeyMask(),
													tmpEvent->getPoint() );
													
							control_->handleEvent( &mouseEvent );						
							
							mouseState_ = OSXControl::msNoState;
							printf( "kEventControlHit, mouseState_ = OSXControl::msNoState\n" );
						}						
					}
					*/
							
				}
				break;
				

				case kEventControlDraw : {
					//don't call next event handler here
					result = noErr;
				
					if ( !control_->isDestroying() ) {
												
						GrafPtr port = NULL;										
						CGContextRef context = NULL;
						RgnHandle region = NULL;
						
						event.GetParameter( kEventParamRgnHandle, &region );
						event.GetParameter<CGContextRef>( kEventParamCGContextRef, typeCGContextRef, &context );
						event.GetParameter<GrafPtr>( kEventParamGrafPort, typeGrafPtr, &port );						
						
						::Rect rgnBds;
						GetRegionBounds( region, &rgnBds );						
						
						
						VCF::Rect bounds = control_->getClientBounds();									
						
						VCF::GraphicsContext* ctx = control_->getContext();
						
						WindowRef wnd = GetControlOwner( hiView_ );
						::Rect wndR;
						GetWindowBounds( wnd, kWindowContentRgn, &wndR );
						
						
						HIRect bds;
						//bounds = control_->getBounds();
						
						bds.origin.x = bounds.left_;
						bds.origin.y = bounds.top_;
						bds.size.width = bounds.getWidth();
						bds.size.height = bounds.getHeight();
						HIViewConvertRect( &bds, hiView_, NULL );
						
						bounds.setRect( bds.origin.x,
										bds.origin.y, 
										bds.origin.x + bds.size.width,
										bds.origin.y + bds.size.height );
																						
						ctx->setViewableBounds( bounds );
						
						
						OSXContext* osxCtx =  (OSXContext*)ctx->getPeer();
						
						bounds.setRect( 0, 0, wndR.right-wndR.left, wndR.bottom-wndR.top );
						osxCtx->setCGContext( context, port, bounds );
		
						int gcs = ctx->saveState();
		
						control_->paintBorder( ctx );
		
						control_->paint( ctx );	
						
						ctx->restoreState( gcs );
						
						osxCtx->setCGContext( NULL, 0, bounds );		
	
						
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
*Revision 1.2.2.1  2004/10/10 15:23:12  ddiego
*updated os x code
*
*Revision 1.2  2004/08/07 02:49:08  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.12  2004/07/27 04:26:04  ddiego
*updated devmain-0-6-5 branch with osx changes
*
*Revision 1.1.2.11.2.3  2004/07/09 02:01:28  ddiego
*more osx updates
*
*Revision 1.1.2.11.2.2  2004/07/06 03:27:12  ddiego
*more osx updates that add proper support
*for lightweight controls, some fixes to text layout, and some window painting issues. Also a fix
*so that controls and windows paint either their default theme background or their background
*color.
*
*Revision 1.1.2.11.2.1  2004/06/27 18:19:15  ddiego
*more osx updates
*
*Revision 1.1.2.11  2004/06/07 03:07:07  ddiego
*more osx updates dealing with mouse handling
*
*Revision 1.1.2.9  2004/05/31 22:24:52  ddiego
*OSX code for handling focus events
*
*Revision 1.1.2.6  2004/05/23 14:11:59  ddiego
*osx updates
*$Log$
*Revision 1.2.2.1  2004/10/10 15:23:12  ddiego
*updated os x code
*
*Revision 1.2  2004/08/07 02:49:08  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.12  2004/07/27 04:26:04  ddiego
*updated devmain-0-6-5 branch with osx changes
*
*Revision 1.1.2.11.2.3  2004/07/09 02:01:28  ddiego
*more osx updates
*
*Revision 1.1.2.11.2.2  2004/07/06 03:27:12  ddiego
*more osx updates that add proper support
*for lightweight controls, some fixes to text layout, and some window painting issues. Also a fix
*so that controls and windows paint either their default theme background or their background
*color.
*
*Revision 1.1.2.11.2.1  2004/06/27 18:19:15  ddiego
*more osx updates
*
*Revision 1.1.2.11  2004/06/07 03:07:07  ddiego
*more osx updates dealing with mouse handling
*
*Revision 1.1.2.9  2004/05/31 22:24:52  ddiego
*OSX code for handling focus events
*
*Revision 1.1.2.8  2004/05/31 19:42:52  ddiego
*more osx updates
*
*Revision 1.1.2.7  2004/05/31 13:20:57  ddiego
*more osx updates
*
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
