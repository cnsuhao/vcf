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

#include "ApplicationKit.h"
#include "ApplicationKitPrivate.h"
#include "implementerKit/OSXWindow.h"



namespace VCF {

OSXWindow::OSXWindowMap OSXWindow::osxWindowMap;


OSXWindow::OSXWindow( Control* control, Control* owner ):
    windowRef_(0),
    control_(control),
    handlerRef_(NULL)
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
                kWindowResizableAttribute | kWindowCloseBoxAttribute | 
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
        
        UIToolkit::postEvent( new GenericEventHandler<Control>( owningControl, &Control::handleEvent, "Component::handleEvent" ),
						new VCF::ComponentEvent( owningControl, Component::COMPONENT_CREATED ),	true );
                        
        if ( noErr != err ) {
            throw RuntimeException( MAKE_ERROR_MSG_2("SetWindowProperty() failed!") );
        }
    }
}

void OSXWindow::destroyControl()
{
    
    DisposeWindow( windowRef_ );
    printf( "windowRef_: %p, destroyed\n", windowRef_ );
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
    
    printf( "OSXWindow::setText( \"%s\" )\n", text.c_str() );
}

void OSXWindow::setBounds( Rect* rect )
{
    ::Rect r = RectProxy(rect);
    
    SetWindowBounds( windowRef_, kWindowStructureRgn, &r );
    
    printf( "OSXWindow::setBounds( %s )\n", rect->toString().c_str() );
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
    }
    
    printf( "OSXWindow::setVisible( %s )\n", visible ? "true" : "false" );
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

}

void OSXWindow::setFont( Font* font )
{

}

void OSXWindow::repaint( Rect* repaintRect )
{	
    ::Rect r;
    if ( NULL == repaintRect ) {        
        r = RectProxy( getBounds() );
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

}

void OSXWindow::translateFromScreenCoords( Point* pt )
{

}

OSXWindow* OSXWindow::getOSXWindowFromWindowRef( WindowRef windowRef )
{
    return NULL;
}

Rect OSXWindow::getClientBounds()
{
    ::Rect r;
    GetWindowBounds( windowRef_, kWindowContentRgn, &r );
    
    VCF::Rect result = RectProxy(r);
    
    return result;
}

void  OSXWindow::setClientBounds( Rect* bounds )
{
    ::Rect r = RectProxy(bounds);
    SetWindowBounds( windowRef_, kWindowContentRgn, &r );
    
    printf( "OSXWindow::setClientBounds( %s )\n", bounds->toString().c_str() );
}

void OSXWindow::close()
{

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
                case kEventWindowDrawContent: {
					::CallNextEventHandler( nextHandler, theEvent );
					
                    WindowRef window = 0;
                    
                    
                    OSStatus err = GetEventParameter( theEvent, 
                                                kEventParamDirectObject, 
                                                typeWindowRef,
                                                NULL, 
                                                sizeof( window ), 
                                                NULL, &window );
                    //draw content
                    GrafPtr wndPort = GetWindowPort(window);
                    //VCF::GraphicsContext gc( (VCF::ulong32)thePort );
                    VCF::GraphicsContext* ctx = control_->getContext();
                    ctx->getPeer()->setContextID( (VCF::ulong32)wndPort ); 
                    
                    control_->paint( ctx );	
                    
					result = noErr;
                }
				break;
                
                case kEventWindowBoundsChanged: {
                    ::CallNextEventHandler( nextHandler, theEvent );
                
                /*
					OSStatus err = GetEventParameter( theEvent, 
                                                kEventParamAttributes, 
                                                typeUInt32,
                                                NULL, 
                                                sizeof( UInt32 ), 
                                                NULL, &attributes );
                                
					if ( err == noErr ) 	{
						if ( attributes & kWindowBoundsChangeSizeChanged ) {
							//this->Resized();
                            //updateWindow();
							result = noErr;
						}
						else if ( attributes & kWindowBoundsChangeOriginChanged ) {
							//this->Moved();
                            result = noErr;
						}
                        
					}
                    */
                    
                    if ( NULL != vcfEvent ) {
                        control_->handleEvent( vcfEvent );
                    }
                }
                break;
                    
                default : {
                    result = CallNextEventHandler( nextHandler, theEvent );
                    
                    if ( NULL != vcfEvent ) {
                        control_->handleEvent( vcfEvent );
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

};//end of namespace VCF


/**
*CVS Log info
*$Log$
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






