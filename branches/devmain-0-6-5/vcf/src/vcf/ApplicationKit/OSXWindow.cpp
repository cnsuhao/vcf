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
#include "vcf/ApplicationKit/OSXWindow.h"



class WndSwitchPort {
public:
    WndSwitchPort( WindowRef ptr ) :current(GetWindowPort(ptr)){
        GetPort( &old );
        if ( old != current ) {
            //make switch
            SetPort( current ) ;
        }
    }
    
    ~WndSwitchPort() {
        if ( old != current ) {
            //make switch
            SetPort( old ) ;
        }
    }
    
    operator GrafPtr () {
		return current;
	}
    
    
    
    
private:
    GrafPtr current;
    GrafPtr old;
    WndSwitchPort( const WndSwitchPort& rhs );
    WndSwitchPort& operator=(const WndSwitchPort& rhs );
};


class WndView : public TView {
public:

	WndView( HIViewRef inControl ):
		TView(inControl),
		windowPeer_(NULL){
		
	}
	
	virtual ~WndView() {
	
	}
		
	
									
	virtual ControlKind GetKind() {
		const ControlKind result = { 'vcWv', 'vcWv' };	
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
		if ( NULL == windowPeer_ ) {
			
			WindowRef wnd = GetOwner();
			void* ptr = NULL;
			OSStatus err = GetWindowProperty( wnd, 'vcfa', 'vcfw', sizeof(void*), NULL, &ptr );
			VCF::StringUtils::traceWithArgs( "GetWindowProperty(): %d, wnd: %p, ptr: %p\n", err, wnd, ptr );
			if ( err == noErr ) {
				windowPeer_ = (VCF::OSXWindow*)ptr;
			}
		}	
		
		//windowPeer_->handleWndViewDrawEvent( inLimitRgn, inContext );
		GrafPtr oldPort = 0;
		GetPort( &oldPort );
		SetPort( port );
		TRect portBounds = Bounds();
		::Rect r = portBounds;
		
		VCF::StringUtils::traceWithArgs( "portBounds: %d, %d, %d, %d\n",
									r.left,
									r.top,
									r.right,
									r.bottom );
	
		/*
		::SetThemeBackground( kThemeBrushUtilityWindowBackgroundActive, 32, true ) ;
		EraseRect( &r );
		
		VCF::GraphicsContext gc(0);
		VCF::OSXContext* osxCtx =  (VCF::OSXContext*)gc.getPeer();
		osxCtx->setCGContext( inContext, port, getClientBounds() );
		
		gc.rectangle(r.left,
									r.top,
									r.right,
									r.bottom );
		gc.setColor( VCF::Color::getColor( "gray123" ) );
		gc.fillPath();
		
		osxCtx->setCGContext( NULL, 0, getClientBounds() );
		
		SetPort( oldPort );
		*/
	}
	
	void setWindowPeer( VCF::OSXWindow* peer ) {
		windowPeer_ = peer ;
	}
protected:
	VCF::OSXWindow* windowPeer_;
	
};





namespace VCF {

OSXWindow::OSXWindowMap OSXWindow::osxWindowMap;


OSXWindow::OSXWindow( Control* control, Control* owner ):
    windowRef_(0),
    control_(control),
    handlerRef_(NULL),
    internalClose_(false)
{

}

OSXWindow::~OSXWindow()
{
	
}

EventHandlerUPP OSXWindow::getEventHandlerUPP()
{
    static EventHandlerUPP result = NULL;
    if ( NULL == result ) {
        result = NewEventHandlerUPP( OSXWindow::handleOSXEvents );
    }
    return result;
}

void OSXWindow::create( Control* owningControl )
{
    WindowAttributes attrs = 0;
    attrs |=  kWindowCloseBoxAttribute | kWindowFullZoomAttribute | kWindowCollapseBoxAttribute |
                kWindowResizableAttribute | kWindowCloseBoxAttribute | kWindowCompositingAttribute |
                kWindowStandardHandlerAttribute | kWindowLiveResizeAttribute | kWindowInWindowMenuAttribute;
                
    ::Rect bounds = {0,0,0,0};
    
    OSStatus err = CreateNewWindow( kDocumentWindowClass, attrs, &bounds, &windowRef_ );
    if ( noErr != err ) {
        throw RuntimeException( MAKE_ERROR_MSG_2("CreateNewWindow() failed!") );
    }
    else {
        err = SetWindowProperty( windowRef_, 'vcfa', 'vcfw', sizeof(void*), (void*)this );
        
        static EventTypeSpec eventsToHandle[] ={ 
                            // { kEventClassWindow, kEventWindowGetIdealSize },
                            //{ kEventClassCommand, kEventCommandProcess },
                            //{ kEventClassCommand, kEventCommandUpdateStatus },
                            { kEventClassWindow, kEventWindowClose },
                            { kEventClassWindow, kEventWindowActivated },
                            { kEventClassWindow, kEventWindowDeactivated },
                            { kEventClassWindow, kEventWindowDrawContent },
                            { kEventClassMouse, kEventMouseDown },
                            { kEventClassMouse, kEventMouseUp },
                            { kEventClassMouse, kEventMouseMoved },
                            { kEventClassMouse, kEventMouseDragged },
                            { kEventClassMouse, kEventMouseEntered },
                            { kEventClassMouse, kEventMouseExited },
                            { kEventClassMouse, kEventMouseWheelMoved },
                            { kEventClassKeyboard, kEventRawKeyDown },
                            { kEventClassKeyboard, kEventRawKeyUp },
                            { kEventClassWindow, kEventWindowBoundsChanged } };
                            

        InstallWindowEventHandler( windowRef_, 
                                    OSXWindow::getEventHandlerUPP(), 
                                    sizeof(eventsToHandle)/sizeof(eventsToHandle[0]),
                                    eventsToHandle, 
                                    this, 
                                    &handlerRef_ );
									
		/*	
		windowView_ = NULL;
		CFTextString s;
		
		TRect r(0,0,100,200);
		
		if ( noErr == ViewCreator<WndView>::create( &windowView_, r, windowRef_ ) ) {
			HIViewSetVisible( windowView_, true );			
		}
		*/
		
        UIToolkit::postEvent( new GenericEventHandler<Control>( owningControl, &Control::handleEvent ),
						new VCF::ComponentEvent( owningControl, Component::COMPONENT_CREATED ),	true );
         
		setVisible( true );
        if ( noErr != err ) {
            throw RuntimeException( MAKE_ERROR_MSG_2("SetWindowProperty() failed!") );
        }
    }
}

void OSXWindow::destroyControl()
{
    //StringUtils::trace( "OSXWindow::destroyControl\n" );
	//VCF::ComponentEvent event( control_, Component::COMPONENT_DELETED );
	
	//control_->handleEvent( &event );
	
    DisposeWindow( windowRef_ );
    StringUtils::traceWithArgs( "windowRef_: %p, destroyed\n", windowRef_ );
	
	windowRef_ = NULL;
}

String OSXWindow::getText()
{
    VCF::String result;
    CFStringRef wndTitle;
    CopyWindowTitleAsCFString( windowRef_, &wndTitle );
    
    CFTextString text;
    text = wndTitle;    
    result = text;
    
    return result;
}

void OSXWindow::setText( const String& text )
{
    CFTextString wndTitle;
    wndTitle = text;
    SetWindowTitleWithCFString( windowRef_, wndTitle );
}

void OSXWindow::setBounds( Rect* rect )
{
    ::Rect r = RectProxy(rect);
    
    SetWindowBounds( windowRef_, kWindowStructureRgn, &r );
}

bool OSXWindow::beginSetBounds( const ulong32& numberOfChildren )
{
    return true;
}

void OSXWindow::endSetBounds()
{

}

Rect OSXWindow::getBounds()
{
    ::Rect r;
    GetWindowBounds( windowRef_, kWindowStructureRgn, &r );
    
    VCF::Rect result = RectProxy(r);
    
    return result;
}

void OSXWindow::setVisible( const bool& visible )
{
    if ( !visible ) {
        HideWindow( windowRef_ );
    }	
    else {
        ShowWindow( windowRef_ );
		repaint( NULL );
    }
}

bool OSXWindow::getVisible()
{
    return IsWindowVisible( windowRef_ ) ? true : false;
}

Control* OSXWindow::getControl()
{
    return control_;
}

void OSXWindow::setControl( Control* control )
{
    control_ = control;
}

void OSXWindow::setCursor( Cursor* cursor )
{

}

void OSXWindow::setParent( Control* parent )
{

}

Control* OSXWindow::getParent()
{
    return NULL;
}

bool OSXWindow::isFocused()
{
    WindowRef wndRef = GetUserFocusWindow();
    return (wndRef == windowRef_) ? true : false;
}

void OSXWindow::setFocused()
{
    SetUserFocusWindow( windowRef_ );
}

bool OSXWindow::isEnabled()
{
    return IsWindowActive( windowRef_ ) ? true : false;
}

void OSXWindow::setEnabled( const bool& enabled )
{
	ActivateWindow( windowRef_, enabled ? TRUE : FALSE );
}

void OSXWindow::setFont( Font* font )
{

}

void OSXWindow::repaint( Rect* repaintRect )
{	
    ::Rect r;
    if ( NULL == repaintRect ) {        
        r = RectProxy( getClientBounds() );
    }
    else {
        r = RectProxy(repaintRect);
    }
    
    InvalWindowRect( windowRef_, &r );
}

void OSXWindow::keepMouseEvents()
{

}

void OSXWindow::releaseMouseEvents()
{

}

void OSXWindow::translateToScreenCoords( Point* pt )
{
	WndSwitchPort port(windowRef_);
	
	::Point point;
    point.h = pt->x_;
    point.v = pt->y_;
	
	LocalToGlobal( &point );
	
	pt->x_ = point.h;
	pt->y_ = point.v;
}

void OSXWindow::translateFromScreenCoords( Point* pt )
{
	WndSwitchPort port(windowRef_);
	
	::Point point;
    point.h = pt->x_;
    point.v = pt->y_;
	
	GlobalToLocal( &point );
	
	pt->x_ = point.h;
	pt->y_ = point.v;
}

OSXWindow* OSXWindow::getOSXWindowFromWindowRef( WindowRef windowRef )
{
    return NULL;
}

Rect OSXWindow::getClientBounds()
{
    ::Rect r;
    GetWindowBounds( windowRef_, kWindowContentRgn, &r );
    
    WndSwitchPort port(windowRef_);
    
    ::Point pt;
    pt.h = r.left;
    pt.v = r.top;
    
    VCF::Rect result;
    
    GlobalToLocal(&pt); 
    
    result.left_ = pt.h;
    result.top_ = pt.v;
    
    pt.h = r.right;
    pt.v = r.bottom;
    
    GlobalToLocal(&pt); 
    
    result.right_ = pt.h;
    result.bottom_ = pt.v;
    
	
    return result;
}

void  OSXWindow::setClientBounds( Rect* bounds )
{
    ::Rect r = RectProxy(bounds);
    SetWindowBounds( windowRef_, kWindowContentRgn, &r );
}

void OSXWindow::close()
{
    if ( !internalClose_ ){
		internalClose_ = true;
		Application* app = Application::getRunningInstance();
		if ( NULL != app ){
			Window* mainWindow = app->getMainWindow();
			if ( mainWindow == getControl() ){
				//::PostMessage( hwnd_, WM_QUIT, 0, 0 );
			}
		}
	}

	//::PostMessage( hwnd_, WM_CLOSE, 0, 0 );
}

void OSXWindow::setFrameStyle( const FrameStyleType& frameStyle )
{

}

void OSXWindow::setFrameTopmost( const bool& isTopmost )
{

}

bool OSXWindow::isMaximized()
{
    return IsWindowInStandardState( windowRef_, NULL, NULL ) ? true : false;
}

void OSXWindow::setMaximized( const bool maximised )
{
    if ( maximised ) {
        ZoomWindow( windowRef_, inZoomOut, true );
    }
    else {
        ZoomWindow( windowRef_, inZoomIn, false );
    }
}

bool OSXWindow::isMinimized()
{
    return IsWindowCollapsed( windowRef_ ) ? true : false;
}

void OSXWindow::setMinimized( const bool& minimized )
{
    CollapseWindow( windowRef_, minimized );
}

void OSXWindow::restore()
{

}

void OSXWindow::setIconImage( Image* icon )
{

}

OSStatus OSXWindow::handleOSXEvent(  EventHandlerCallRef nextHandler, EventRef theEvent )
{
    OSStatus result = eventNotHandledErr;
    
    OSXEventMsg msg( theEvent, control_ );
    Event* vcfEvent = UIToolkit::createEventFromNativeOSEventData( &msg );
    
    UInt32 whatHappened = GetEventKind (theEvent);
    UInt32 attributes = 0;   
	
	                        
    switch ( GetEventClass( theEvent ) )  {				
		
        case kEventClassWindow : {
            switch( whatHappened ) {
                case kEventWindowClose : {
					
                    result = noErr;//::CallNextEventHandler( nextHandler, theEvent ); 
                    
                    VCF::Window* window = (VCF::Window*)getControl();

                    if ( window->allowClose() ) {
        
                        VCF::WindowEvent event( getControl(), WINDOW_EVENT_CLOSE );
        
        
                        window->FrameClose.fireEvent( &event );
        
                        if ( false == internalClose_ ){
                            //check if the main window is clossing - if it is
                            //then close the app !
        
                            Application* app = Application::getRunningInstance();
                            if ( NULL != app ){
                                Window* mainWindow = app->getMainWindow();
                                if ( mainWindow == getControl() ){
                                    //::PostMessage( hwnd_, WM_QUIT, 0, 0 );
                                }
                            }
                        }
						
						result = ::CallNextEventHandler( nextHandler, theEvent ); 						
						
                    }
					else {
						result = noErr;
					}
                }
                break;
                
                case kEventWindowDrawContent: {
					result = ::CallNextEventHandler( nextHandler, theEvent );
					
					handleDraw( true, theEvent );
                }
				break;
                
				
				case kEventWindowDeactivated: case kEventWindowActivated: {
					result = CallNextEventHandler( nextHandler, theEvent );
					
                    if ( !control_->isDestroying() ) {
						handleDraw( false, theEvent );
					
						if ( NULL != vcfEvent ) {
							control_->handleEvent( vcfEvent );
						}
					}
				}
				break;
				
                case kEventWindowBoundsChanged: {
					
					if ( !control_->isDestroying() ) {
                
						OSStatus err = GetEventParameter( theEvent, 
													kEventParamAttributes, 
													typeUInt32,
													NULL, 
													sizeof( UInt32 ), 
													NULL, &attributes );
									
						if ( err == noErr ) 	{
							if ( attributes & kWindowBoundsChangeSizeChanged ) {
								handleDraw( false, theEvent );
							}                        
						}
						
						result = ::CallNextEventHandler( nextHandler, theEvent );
						
						if ( NULL != vcfEvent ) {
							control_->handleEvent( vcfEvent );
						}
					}
					else {
						result = ::CallNextEventHandler( nextHandler, theEvent );
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

void OSXWindow::updateWindow()
{
	if ( IsWindowUpdatePending( windowRef_ ) )
	{
		OSStatus	err;
		EventRef	event;
		
		err = CreateEvent( NULL, kEventClassWindow, kEventWindowUpdate,
				GetCurrentEventTime(), 0, &event );
		if ( err == noErr ) {
			WindowRef	window = windowRef_;
			
			SetEventParameter( event, kEventParamDirectObject, typeWindowRef,
				sizeof( WindowRef ), &window );
		
			SendEventToEventTarget( event, GetWindowEventTarget( window ) );
			ReleaseEvent( event );
		}
	}
}

OSStatus OSXWindow::handleOSXEvents( EventHandlerCallRef nextHandler, EventRef theEvent, void* userData)
{
    OSXWindow* window = (OSXWindow*)userData;
    
    return window->handleOSXEvent( nextHandler, theEvent );
}

bool OSXWindow::isComposited()
{
	bool result = false;
	WindowAttributes attrs = 0;
	if ( noErr == GetWindowAttributes( windowRef_, &attrs ) ) {
		if ( attrs & kWindowCompositingAttribute ) {
			result = true;
		}
	}
	
	return result;
}

void OSXWindow::handleDraw( bool drawingEvent, EventRef event )
{	
	if ( drawingEvent ) {
	TCarbonEvent		carbonEvent( event );

	
	SetPortWindowPort( windowRef_ );	
	
	RgnHandle rgn = determineUnobscuredClientRgn();		
	
	::Rect r;
	GetRegionBounds( rgn, &r );
	StringUtils::traceWithArgs( "Rgn bounds: left: %d, top: %d, right: %d, bottom: %d\n",
									r.left, r.top, r.right, r.bottom );
	
	EraseRgn( rgn );	
	
	DisposeRgn( rgn );
	
	GrafPtr wndPort = GetWindowPort(windowRef_);	
	
	VCF::GraphicsContext* ctx = control_->getContext();
	ctx->getPeer()->setContextID( (VCF::ulong32)wndPort ); 
	
	control_->paint( ctx );
	
	ctx->getPeer()->setContextID( 0 );		
	}
}

RgnHandle OSXWindow::determineUnobscuredClientRgn()
{
	StringUtils::trace( "determineUnobscuredClientRgn()\n" );
	
	RgnHandle result = NewRgn();	
		
	VCF::Rect currentClientBounds = getClientBounds();
	
	SetRectRgn( result, (int)currentClientBounds.left_,
					(int)currentClientBounds.top_,
					(int)currentClientBounds.right_,
					(int)currentClientBounds.bottom_ );
					
					
	
	
	VCF::Rect bounds;
	RgnHandle childRgn = NewRgn();
	
	Container* container = control_->getContainer();
	if ( NULL != container ) {
		Enumerator<Control*>* children = container->getChildren();
		
		while ( children->hasMoreElements() ) {
			Control* child = children->nextElement();
			
			if ( !child->isLightWeight() ) {
				bounds = child->getBounds();
				
				SetRectRgn( childRgn, (int)bounds.left_,
					(int)bounds.top_,
					(int)bounds.right_,
					(int)bounds.bottom_ );
				
				::Rect r;
	GetRegionBounds( childRgn, &r );
	StringUtils::traceWithArgs( "childRgn bounds: left: %d, top: %d, right: %d, bottom: %d\n",
									r.left, r.top, r.right, r.bottom );
										
				DiffRgn( result, childRgn, result );
			}
		}
	}
	
	DisposeRgn( childRgn );
	
	return result;
}

};//end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.8  2004/05/31 13:20:57  ddiego
*more osx updates
*
*Revision 1.1.2.7  2004/05/23 14:11:59  ddiego
*osx updates
*
*Revision 1.1.2.6  2004/05/16 02:39:01  ddiego
*OSX code updates
*
*Revision 1.1.2.5  2004/05/07 23:22:45  ddiego
*more osx changes
*
*Revision 1.1.2.4  2004/05/06 02:56:35  ddiego
*checking in OSX updates
*
*Revision 1.1.2.3  2004/04/30 05:44:33  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.2  2004/02/25 05:18:23  ddiego
*updates to ApplicationKit to support posting events and timer and idle time handlers for the OSX UI Toolkit.
*
*Revision 1.1.2.1  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*/






