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
#include "implementerKit/OSXDesktopPeer.h"
#include "implementerKit/OSXApplicationPeer.h"
#include "implementerKit/OSXControlContextPeer.h"
#include "implementerKit/OSXCursorPeer.h"
#include "implementerKit/OSXWindow.h"



#define kSleepTime	32767


namespace VCF {
//UIMetricsManager implementation for OSX
class OSXUIMetricsManager : public UIMetricsManager {
public:
	OSXUIMetricsManager(){}
		
	virtual ~OSXUIMetricsManager(){}	
	
	virtual VCF::Font getDefaultFontFor( const UIMetricsManager::FontType& type ) {
		VCF::Font result("Arial", 10);			

		result.setColor( GraphicsToolkit::getSystemColor( SYSCOLOR_CAPTION_TEXT ) );
		switch ( type ) {
			case UIMetricsManager::ftMenuItemFont : {
				
			}
			break;

			case UIMetricsManager::ftSelectedMenuItemFont : {
				
			}
			break;

			case UIMetricsManager::ftControlFont :  case UIMetricsManager::ftSystemFont : {
				
			}
			break;			

			case UIMetricsManager::ftMessageFont : {
				
			}
			break;

			case UIMetricsManager::ftToolTipFont : {
				
			}
			break;
		}

		return result;
	}
	
	virtual double getDefaultHeightFor( const UIMetricsManager::HeightType& type )  {
		double result = 0.0;
		switch ( type ) {
			case UIMetricsManager::htLabelHeight : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = f.getHeight() * 1.75; 
			}
			break;

			case UIMetricsManager::htComboBoxHeight : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = f.getHeight() * 2.0; 
			}
			break;

			case UIMetricsManager::htListItemHeight : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = f.getHeight() * 1.65; 
			}
			break;

			case UIMetricsManager::htButtonHeight : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = (f.getHeight() * 1.75) + 2.50; 
			}
			break;

			case UIMetricsManager::htRadioBoxHeight : case UIMetricsManager::htCheckBoxHeight : {
				//in Win32 a radio box or check box is ALWAYS 10 dialog units high
				//dialog units are converted by 
				//(2 * average char height dialog font / average char height system font pixels
				//where average char height dialog font = TEXTMETRIC.tmHeight field or a Font::getHeight()


				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = (9.0 * ((2.0 * f.getHeight()) / f.getHeight())) - 4.0;//0.590909; 
			}
			break;

			case UIMetricsManager::htToolTipHeight : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftToolTipFont );
				result = f.getHeight() * 1.2222; 
			}
			break;

			case UIMetricsManager::htSeparatorHeight : {
				result = 2.0;
			}
			break;

			case UIMetricsManager::htInformationalControl : {
				VCF::Font f = getDefaultFontFor( UIMetricsManager::ftControlFont );
				result = f.getHeight() * 1.75; 
			}
			break;
		}
		return result;

	}
	
	virtual double getPreferredSpacingFor( const UIMetricsManager::SpacingType& type )  {
		double result = 0.0;

		//values largely derived from the Apple HIG at 
		//http://developer.apple.com/techpubs/macosx/Essentials/AquaHIGuidelines/AHIGLayout/index.html
		switch ( type ) {
			case UIMetricsManager::stWindowBorderDelta : {
				result = 20.0;
			}
			break;

			case UIMetricsManager::stContainerBorderDelta : {
				result = 8.0;
			}
			break;

			case UIMetricsManager::stControlVerticalSpacing : {
				result = 14.0;
			}
			break;

			case UIMetricsManager::stControlHorizontalSpacing : {
				result = 10.0;
			}
			break;

			case UIMetricsManager::stInformationControlTopSpacer : {
				result = 2.0;
			}
			break;

			case UIMetricsManager::stInformationControlBottomSpacer : {
				result = 8.0;
			}
			break;
		}

		return result;
	}
	
	virtual Size getDefaultSliderThumbDimensions()  {
		Size result;

		//where the hell do we get these ????
		result.width_ = 22;
		result.height_ = 22;

		return result;
	}
	
	virtual Size getDefaultMenuItemDimensions( const String& caption )  {
		Size result;

		
		return result;
	}
	
	virtual Size getDefaultVerticalScrollButtonDimensions()  {
		Size result;

		result.width_ = 22;
		result.height_ = 22;

		return result;
	}
	
	virtual Size getDefaultHorizontalScrollButtonDimensions()  {
		Size result;

		result.width_ = 22;
		result.height_ = 22;

		return result;
	}
	
	virtual Size getDefaultTabDimensions( const String& caption )  {
		Size result;

		return result;
	}
};

};//end of VCF namespace


using namespace VCF;



OSXUIToolkit::OSXUIToolkit():
    quitEventLoop_(false),
    eventHandlerRef_(NULL),
    handlerUPP_(NULL),
    timerUPP_(NULL),
    idleTimerUPP_(NULL),
    idleTimerRef_(NULL)
{
    metricsMgr_ = new OSXUIMetricsManager();
    
    //install event loop callbacks
    handlerUPP_ = NewEventHandlerUPP(OSXUIToolkit::handleOSXApplicationEvents);
    static EventTypeSpec eventsToHandle[] ={ 
                            { kEventClassCommand, kEventCommandProcess },
                            { kEventClassCommand, kEventCommandUpdateStatus },
                            { OSXUIToolkit::CustomEventClass, OSXUIToolkit::EventPosted} };
                            
    OSStatus err = InstallEventHandler( GetApplicationEventTarget(),
                                        handlerUPP_,
                                        sizeof(eventsToHandle)/sizeof(eventsToHandle[0]),
                                        eventsToHandle,
                                        this,
                                        &eventHandlerRef_ );

    timerUPP_ = NewEventLoopTimerUPP(OSXUIToolkit::handleTimerEvent);
    idleTimerUPP_ = NewEventLoopIdleTimerUPP(OSXUIToolkit::handleIdleTimer);
    
    InstallEventLoopIdleTimer( GetCurrentEventLoop(), 0, 0.25, 
                                idleTimerUPP_, this, &idleTimerRef_ );
    

    if ( err != noErr ) {
        printf( "InstallEventHandler failed" );
    }                        
}
	
OSXUIToolkit::~OSXUIToolkit()
{
   
    std::map<EventLoopTimerRef,TimeOutHandler>::iterator found = timeoutHandlers_.begin();
    while ( !timeoutHandlers_.empty() ) {        
        internal_unregisterTimerHandler( found->second.handler_ );
        found = timeoutHandlers_.begin();
    }


    DisposeEventHandlerUPP(handlerUPP_);
    DisposeEventLoopTimerUPP(timerUPP_);
    
    RemoveEventLoopTimer( idleTimerRef_ );
    DisposeEventLoopIdleTimerUPP(idleTimerUPP_);
    printf( "OSXUIToolkit destroyed\n");
}

ApplicationPeer* OSXUIToolkit::internal_createApplicationPeer()
{
    return new OSXApplicationPeer();
}
	
TextPeer* OSXUIToolkit::internal_createTextPeer( TextControl* component, const bool& isMultiLineControl, ComponentType componentType)
{
    return NULL;
}

TreePeer* OSXUIToolkit::internal_createTreePeer( TreeControl* component, ComponentType componentType)
{
    return NULL;
}

ListviewPeer* OSXUIToolkit::internal_createListViewPeer( ListViewControl* component, ComponentType componentType)
{
    return NULL;
}

DialogPeer* OSXUIToolkit::internal_createDialogPeer( Control* owner, Dialog* component, ComponentType componentType )
{
    return NULL;
}

DialogPeer* OSXUIToolkit::internal_createDialogPeer()
{
    return NULL;
}

ControlPeer* OSXUIToolkit::internal_createControlPeer( Control* control, ComponentType componentType)
{
    return NULL;
}

WindowPeer* OSXUIToolkit::internal_createWindowPeer( Control* control, Control* owner, ComponentType componentType)
{
    return new OSXWindow( control, owner );
}

ToolbarPeer* OSXUIToolkit::internal_createToolbarPeer( Toolbar* toolbar )
{
    return NULL;
}

MenuItemPeer* OSXUIToolkit::internal_createMenuItemPeer( MenuItem* item )
{
    return NULL;
}

MenuBarPeer* OSXUIToolkit::internal_createMenuBarPeer( MenuBar* menuBar )
{
    return NULL;
}

PopupMenuPeer* OSXUIToolkit::internal_createPopupMenuPeer( PopupMenu* popupMenu )
{
    return NULL;
}

ButtonPeer* OSXUIToolkit::internal_createButtonPeer( CommandButton* component, ComponentType componentType)
{
    return NULL;
}

HTMLBrowserPeer* OSXUIToolkit::internal_createHTMLBrowserPeer( Control* control )
{
    return NULL;
}

ContextPeer* OSXUIToolkit::internal_createContextPeer( Control* control )
{
    return new OSXControlContextPeer( control->getPeer() );
}

CommonFileDialogPeer* OSXUIToolkit::internal_createCommonFileOpenDialogPeer( Control* owner )
{
    return NULL;
}

CommonFileDialogPeer* OSXUIToolkit::internal_createCommonFileSaveDialogPeer( Control* owner )
{
    return NULL;
}

CommonColorDialogPeer* OSXUIToolkit::internal_createCommonColorDialogPeer( Control* owner )
{
    return NULL;
}

CommonFolderBrowseDialogPeer* OSXUIToolkit::internal_createCommonFolderBrowseDialogPeer( Control* owner )
{
    return NULL;
}

CommonFontDialogPeer* OSXUIToolkit::internal_createCommonFontDialogPeer( Control* owner )
{
    return NULL;
}

DragDropPeer* OSXUIToolkit::internal_createDragDropPeer()
{
    return NULL;
}

DataObjectPeer* OSXUIToolkit::internal_createDataObjectPeer()
{
    return NULL;
}

DropTargetPeer* OSXUIToolkit::internal_createDropTargetPeer()
{
    return NULL;
}

DesktopPeer* OSXUIToolkit::internal_createDesktopPeer( Desktop* desktop )
{
    return new OSXDesktopPeer(desktop);
}

ScrollPeer* OSXUIToolkit::internal_createScrollPeer( Control* control )
{
    return NULL;
}

CursorPeer* OSXUIToolkit::internal_createCursorPeer( Cursor* cursor )
{
    return new OSXCursorPeer(cursor);
}

ClipboardPeer* OSXUIToolkit::internal_createClipboardPeer()
{
    return NULL;
}

bool OSXUIToolkit::internal_createCaret( Control* owningControl, Image* caretImage  )
{
    return false;
}

bool OSXUIToolkit::internal_destroyCaret( Control* owningControl )
{
    return false;
}

void OSXUIToolkit::internal_setCaretVisible( const bool& caretVisible )
{
    
}

void OSXUIToolkit::internal_setCaretPos( Point* point )
{
   
}

void OSXUIToolkit::internal_postEvent( VCF::EventHandler* eventHandler, Event* event, const bool& deleteHandler )
{
    EventRef osxEvent = OSXUIToolkit::createUserCarbonEvent(OSXUIToolkit::EventPosted);
    
    
    SetEventParameter( osxEvent, OSXUIToolkit::EventHandler, 
                        typeUInt32, OSXUIToolkit::SizeOfEventHandler, &eventHandler );
                        
    SetEventParameter( osxEvent, OSXUIToolkit::EventHandlerEvent, 
                        typeUInt32, OSXUIToolkit::SizeOfEventHandlerEvent, &event );

    Boolean val = deleteHandler;
    SetEventParameter( osxEvent, OSXUIToolkit::DeletePostedEvent, 
                        typeBoolean, OSXUIToolkit::SizeOfDeletePostedEvent, &val );
    
    OSStatus err = PostEventToQueue( GetCurrentEventQueue(), osxEvent, kEventPriorityStandard );
    if ( err != noErr ) {
        printf( "PostEventToQueue failed\n" );
    }
                        
}

void OSXUIToolkit::handleIdleTimer( EventLoopTimerRef inTimer, EventLoopIdleTimerMessage inState, void *inUserData )
{
    OSXUIToolkit* toolkit = (OSXUIToolkit*)inUserData;
    
    printf( "idle handler...\n" );
    
    switch ( inState ) {
        case kEventLoopIdleTimerStarted : {
        
        }
        break;
        
        case kEventLoopIdleTimerIdling : {
            printf( "\tkEventLoopIdleTimerIdling...\n" );
            Application* app = Application::getRunningInstance();
            if ( NULL != app ) {				
				app->idleTime();
			}

			//check library apps;
			Enumerator<LibraryApplication*>* registeredLibs = LibraryApplication::getRegisteredLibraries();
			while ( true == registeredLibs->hasMoreElements() ) {
				LibraryApplication* libraryApp = registeredLibs->nextElement();
				libraryApp->idleTime();
			}
        }
        break;
        
        case kEventLoopIdleTimerStopped : {
        
        }
        break;
    }
}

void OSXUIToolkit::handleTimerEvent( EventLoopTimerRef inTimer, void * inUserData )
{
   OSXUIToolkit* toolkit = (OSXUIToolkit*)inUserData;
   std::map<EventLoopTimerRef,TimeOutHandler>::iterator found =
        toolkit->timeoutHandlers_.find( inTimer );
    if ( found != toolkit->timeoutHandlers_.end() ) {
        TimeOutHandler& toh = found->second;
        TimerEvent event( toh.source_, TIMER_EVENT_PULSE );
		toh.handler_->invoke( &event );
    }
}


void OSXUIToolkit::internal_registerTimerHandler( Object* source, VCF::EventHandler* handler, const ulong32& timeoutInMilliSeconds )
{
    TimeOutHandler toh;
    toh.source_ = source;
    toh.handler_ = handler;
    
    
    std::map<EventLoopTimerRef,TimeOutHandler>::iterator found = timeoutHandlers_.begin();
    while ( found != timeoutHandlers_.end() ) {
        TimeOutHandler& tmHandler = found->second;
        if ( tmHandler.handler_ == handler ) {
            RemoveEventLoopTimer( tmHandler.timerRef_ );
            timeoutHandlers_.erase( found );
            break;
        }
        found ++;
    }
    
    double timeout = ((double)timeoutInMilliSeconds/1000.0);
    
    InstallEventLoopTimer( GetCurrentEventLoop(), 
                            timeout, 
                            timeout, 
                            timerUPP_,
                            this, 
                            &toh.timerRef_ );
                            
    timeoutHandlers_[toh.timerRef_] = toh;   
}

void OSXUIToolkit::internal_unregisterTimerHandler( VCF::EventHandler* handler )
{
    std::map<EventLoopTimerRef,TimeOutHandler>::iterator found = timeoutHandlers_.begin();
    while ( found != timeoutHandlers_.end() ) {
        TimeOutHandler& tmHandler = found->second;
        if ( tmHandler.handler_ == handler ) {
            RemoveEventLoopTimer( tmHandler.timerRef_ );
            timeoutHandlers_.erase( found );
            break;
        }
        found ++;
    }
}


void OSXUIToolkit::internal_runEventLoop()
{
    //set to false to begin with
    quitEventLoop_ = false;    
        
    RunApplicationEventLoop();
    
    //reset back to false when finished
    quitEventLoop_ = false;
}

UIToolkit::ModalReturnType OSXUIToolkit::internal_runModalEventLoopFor( Control* control )
{
    return UIToolkit::mrFalse;
}

void OSXUIToolkit::internal_quitCurrentEventLoop()
{
    EventLoopRef currentLoop = GetCurrentEventLoop();
    QuitEventLoop( currentLoop );
    quitEventLoop_ = true;
}

OSStatus OSXUIToolkit::handleOSXApplicationEvents( EventHandlerCallRef nextHandler, EventRef osxEvent, void* userData )
{
    OSXUIToolkit * toolkit = (OSXUIToolkit*)userData;
    return toolkit->handleAppEvents( nextHandler, osxEvent );
}	

OSStatus OSXUIToolkit::handleAppEvents( EventHandlerCallRef nextHandler, EventRef osxEvent )
{
    OSStatus result = eventNotHandledErr;
    switch ( GetEventClass( osxEvent ) ) {
        case OSXUIToolkit::CustomEventClass : {
            switch ( GetEventKind( osxEvent ) ) {
                case OSXUIToolkit::EventPosted : {
                    
                    UInt32 val;
                    Boolean deleteHandler;
                    GetEventParameter( osxEvent, 
                                        OSXUIToolkit::EventHandler, 
                                        typeUInt32,
                                        NULL,
                                        OSXUIToolkit::SizeOfEventHandler,
                                        NULL,                                        
                                        &val );
                                        
                    VCF::EventHandler* eventHandler  = (VCF::EventHandler*)val;
                    
                    GetEventParameter( osxEvent, 
                                        OSXUIToolkit::EventHandlerEvent, 
                                        typeUInt32,NULL,
                                        OSXUIToolkit::SizeOfEventHandlerEvent,NULL,
                                        &val );
                    Event* e = (Event*)val;
                     
                    GetEventParameter( osxEvent, 
                                        OSXUIToolkit::DeletePostedEvent, 
                                        typeUInt32,NULL,
                                        OSXUIToolkit::SizeOfDeletePostedEvent,NULL,
                                        &deleteHandler );
                    if ( (NULL != eventHandler) && (NULL != e ) ) {
                        printf( "event handler (%p) and event (%p) recv'd! Calling event handler's invoke()\n",
                                    eventHandler, e );
                        eventHandler->invoke( e );
                        
                        if ( deleteHandler ) {
                            delete eventHandler;
                        }
                        delete e;
                    }
                    
                    result = noErr;
                }
                break;
            }
        }
        break;
        
        default : {
            return ::CallNextEventHandler( nextHandler, osxEvent );
        }
        break;
    }
    
    return result;
}

VCF::ulong32 translateButtonMask( EventMouseButton button )
{
    VCF::ulong32 result = 0;
    
    if ( button == kEventMouseButtonPrimary ) {
        result = mbmLeftButton;
    }
    else if ( button == kEventMouseButtonSecondary ) {
        result = mbmRightButton;
    }
    else if ( button == kEventMouseButtonTertiary ) {
        result = mbmMiddleButton;
    }
    
    return result;
}

VCF::ulong32 translateKeyMask( UInt32 keyMod )
{
    VCF::ulong32 result = 0;
    
    if ( keyMod & shiftKey ) {
        result |= kmShift;
    }
    
    if ( keyMod & cmdKey ) {
        result |= kmAlt;
    }
    
    if ( keyMod & controlKey ) {
        result |= kmCtrl;
    }
    return result;
}

   
VCF::Event* OSXUIToolkit::internal_createEventFromNativeOSEventData( void* eventData )
{	
    VCF::Event* result = NULL;
    OSXEventMsg* msg = (OSXEventMsg*)eventData;
    UInt32 whatHappened = GetEventKind( msg->osxEvent_ );
    
    UInt32 type = GetEventClass( msg->osxEvent_ );
    
    switch ( type ) {
        case kEventClassMouse : {    
            EventMouseButton button = kEventMouseButtonPrimary;
            GetEventParameter( msg->osxEvent_, kEventParamMouseButton, typeMouseButton, NULL,
                                sizeof (EventMouseButton), NULL, &button);
                                
            UInt32 keyboardModifier = 0;            
            GetEventParameter( msg->osxEvent_, kEventParamKeyModifiers, typeUInt32, NULL,
                                sizeof (keyboardModifier), NULL, &keyboardModifier);
            
            ::Point mousePos;
            GetEventParameter( msg->osxEvent_, kEventParamMouseLocation, typeQDPoint, NULL,
                                sizeof (mousePos), NULL, &mousePos);
            
            
            UInt32 clickCount = 0;            
            GetEventParameter( msg->osxEvent_, kEventParamClickCount, typeUInt32, NULL,
                                sizeof (clickCount), NULL, &clickCount);
                                
            VCF::Point pt( mousePos.h , 
						   mousePos.v );
            
            
            
            switch ( whatHappened ) {            
                case kEventMouseDown : {
                    printf( "kEventMouseDown\n" );
                    
                    Scrollable* scrollable = msg->control_->getScrollable();
                    if ( NULL != scrollable ) {
                        pt.x_ += scrollable->getHorizontalPosition();
                        pt.y_ += scrollable->getVerticalPosition();
                    }
            
                    result = new VCF::MouseEvent( msg->control_, Control::MOUSE_DOWN,
											translateButtonMask( button ),
											translateKeyMask( keyboardModifier ), &pt );
                    
                }
                break;
                
                case kEventMouseUp : {
                    Scrollable* scrollable = msg->control_->getScrollable();
                    if ( NULL != scrollable ) {
                        pt.x_ += scrollable->getHorizontalPosition();
                        pt.y_ += scrollable->getVerticalPosition();
                    }
            
                    result = new VCF::MouseEvent( msg->control_, Control::MOUSE_UP,
											translateButtonMask( button ),
											translateKeyMask( keyboardModifier ), &pt );
                }
                break;
                
                case kEventMouseMoved : {
                
                    Scrollable* scrollable = msg->control_->getScrollable();
                    if ( NULL != scrollable ) {
                        pt.x_ += scrollable->getHorizontalPosition();
                        pt.y_ += scrollable->getVerticalPosition();
                    }
                    
                    result = new VCF::MouseEvent ( msg->control_, Control::MOUSE_MOVE,
                                                translateButtonMask( button ),
                                                translateKeyMask( keyboardModifier ), &pt );
                }
                break;
                
                case kEventMouseDragged : {
                
                }
                break;
                
                case kEventMouseEntered : {
                    Scrollable* scrollable = msg->control_->getScrollable();
                    if ( NULL != scrollable ) {
                        pt.x_ += scrollable->getHorizontalPosition();
                        pt.y_ += scrollable->getVerticalPosition();
                    }
        
                    result = new VCF::MouseEvent( msg->control_, Control::MOUSE_ENTERED,
                                                    translateButtonMask( 0 ),
                                                    translateKeyMask( 0 ), &pt );
                }
                break;
                
                case kEventMouseExited : {
                    Scrollable* scrollable = msg->control_->getScrollable();
                    if ( NULL != scrollable ) {
                        pt.x_ += scrollable->getHorizontalPosition();
                        pt.y_ += scrollable->getVerticalPosition();
                    }
        
                    result = new VCF::MouseEvent( msg->control_, Control::MOUSE_LEAVE,
                                                    translateButtonMask( 0 ),
                                                    translateKeyMask( 0 ), &pt );
                }
                break;
                
                case kEventMouseWheelMoved : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassKeyboard : {
            switch ( whatHappened ) {
                case kEventRawKeyDown : {
                
                }
                break;
                
                case kEventRawKeyRepeat : {
                
                }
                break;
                
                case kEventRawKeyUp : {
                
                }
                break;
                
                case kEventRawKeyModifiersChanged : {
                
                }
                break;
                
                case kEventHotKeyPressed : {
                
                }
                break;
                
                case kEventHotKeyReleased : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassTextInput : {
            switch ( whatHappened ) {
                
            }
        }
        break;
        
        case kEventClassApplication : {
            switch ( whatHappened ) {
                case kEventAppActivated : {
                
                }
                break;
                
                case kEventAppDeactivated : {
                
                }
                break;
                
                case kEventAppQuit : {
                
                }
                break;
                
                case kEventAppLaunchNotification : {
                
                }
                break;
                
                case kEventAppLaunched : {
                
                }
                break;
                
                case kEventAppTerminated : {
                
                }
                break;
                
                case kEventAppFrontSwitched : {
                
                }
                break;
                
                case kEventAppFocusMenuBar : {
                
                }
                break;
                
                case kEventAppFocusNextDocumentWindow : {
                
                }
                break;
                
                case kEventAppFocusNextFloatingWindow : {
                
                }
                break;
                
                case kEventAppFocusToolbar : {
                
                }
                break;
                
                case kEventAppGetDockTileMenu : {
                
                }
                break;
                
                case kEventAppHidden : {
                
                }
                break;
                
                case kEventAppShown : {
                
                }
                break;
                
                case kEventAppSystemUIModeChanged : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassAppleEvent : {
        
        }
        break;
        
        case kEventClassMenu : {
            switch ( whatHappened ) {
                case kEventMenuBeginTracking : {
                
                }
                break;
                
                case kEventMenuEndTracking : {
                
                }
                break;
                
                case kEventMenuChangeTrackingMode : {
                
                }
                break;
                
                case kEventMenuOpening : {
                
                }
                break;
                
                case kEventMenuClosed : {
                
                }
                break;
                
                case kEventMenuTargetItem : {
                
                }
                break;
                
                case kEventMenuMatchKey : {
                
                }
                break;
                
                case kEventMenuEnableItems : {
                
                }
                break;
                
                case kEventMenuPopulate : {
                
                }
                break;
                
                case kEventMenuMeasureItemWidth : {
                
                }
                break;
                
                case kEventMenuMeasureItemHeight : {
                
                }
                break;
                
                case kEventMenuDrawItem : {
                
                }
                break;
                
                case kEventMenuDrawItemContent : {
                
                }
                break;
                
                case kEventMenuDispose : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassWindow : {
            switch ( whatHappened ) {
                case kEventWindowCollapse : {
                
                }
                break;
                
                case kEventWindowCollapseAll : {
                
                }
                break;
                
                case kEventWindowExpand : {
                
                }
                break;
                
                case kEventWindowExpandAll : {
                
                }
                break;
                
                case kEventWindowClose : {
                    result = new VCF::ComponentEvent( msg->control_, Component::COMPONENT_DELETED );
                }
                break;
                
                case kEventWindowCloseAll : {
                
                }
                break;
                
                case kEventWindowZoom : {
                
                }
                break;
                
                case kEventWindowZoomAll : {
                
                }
                break;
                
                case kEventWindowContextualMenuSelect : {
                
                }
                break;
                
                case kEventWindowPathSelect : {
                
                }
                break;
                
                case kEventWindowGetIdealSize : {
                
                }
                break;
                
                case kEventWindowGetMinimumSize : {
                
                }
                break;
                
                case kEventWindowGetMaximumSize : {
                
                }
                break;
                
                case kEventWindowBoundsChanged: {
                    UInt32 attributes = 0; 
					OSStatus err = GetEventParameter( msg->osxEvent_, 
                                                kEventParamAttributes, 
                                                typeUInt32,
                                                NULL, 
                                                sizeof( UInt32 ), 
                                                NULL, &attributes );
                                
					if ( err == noErr ) 	{
                        ::Rect currentBounds;
                            GetEventParameter( msg->osxEvent_, kEventParamCurrentBounds, typeQDRectangle,
                                                NULL, sizeof(currentBounds), NULL, &currentBounds);

						if ( attributes & kWindowBoundsChangeSizeChanged ) {
							
                            VCF::Size sz( abs(currentBounds.right - currentBounds.left), 
                                            abs(currentBounds.bottom - currentBounds.top) );				
                            result = new ControlEvent( msg->control_, sz );
						}
						else if ( attributes & kWindowBoundsChangeOriginChanged ) {
							VCF::Point pt( currentBounds.left , currentBounds.top );
                            result = new VCF::ControlEvent( msg->control_, pt );
						}
					}
                }
                break;
                
                case kEventWindowConstrain : {
                
                }
                break;
                
                case kEventWindowHandleContentClick : {
                
                }
                break;
                
                case kEventWindowGetDockTileMenu : {
                
                }
                break;
                
                case kEventWindowProxyBeginDrag : {
                
                }
                break;
                
                case kEventWindowProxyEndDrag : {
                
                }
                break;
                
                case kEventWindowToolbarSwitchMode : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassControl : {
            switch ( whatHappened ) {
            
                case kEventControlInitialize : {
                
                }
                break;
                
                case kEventControlDispose : {
                
                }
                break;
                
                case kEventControlGetOptimalBounds : {
                
                }
                break;
                
                case kEventControlHit : {
                
                }
                break;
                
                case kEventControlSimulateHit : {
                
                }
                break;
                
                case kEventControlHitTest : {
                
                }
                break;
                
                case kEventControlDraw : {
                
                }
                break;
                
                case kEventControlApplyBackground : {
                
                }
                break;
                
                case kEventControlApplyTextColor : {
                
                }
                break;
                
                case kEventControlSetFocusPart : {
                
                }
                break;
                
                case kEventControlGetFocusPart : {
                
                }
                break;
                
                case kEventControlActivate : {
                
                }
                break;
                
                case kEventControlDeactivate : {
                
                }
                break;
                
                case kEventControlSetCursor : {
                
                }
                break;
                
                case kEventControlContextualMenuClick : {
                
                }
                break;
                
                case kEventControlClick : {
                
                }
                break;
                
                case kEventControlGetNextFocusCandidate : {
                
                }
                break;
                
                case kEventControlGetAutoToggleValue : {
                
                }
                break;
                
                case kEventControlInterceptSubviewClick : {
                
                }
                break;
                
                case kEventControlGetClickActivation : {
                
                }
                break;
                
                case kEventControlDragEnter : {
                
                }
                break;
                
                case kEventControlDragWithin : {
                
                }
                break;
                
                case kEventControlDragLeave : {
                
                }
                break;
                
                case kEventControlDragReceive : {
                
                }
                break;
                
                case kEventControlTrack : {
                
                }
                break;
                
                case kEventControlGetScrollToHereStartPoint : {
                
                }
                break;
                
                case kEventControlGetIndicatorDragConstraint : {
                
                }
                break;
                
                case kEventControlIndicatorMoved : {
                
                }
                break;
                
                case kEventControlGhostingFinished : {
                
                }
                break;
                
                case kEventControlGetActionProcPart : {
                
                }
                break;
                
                case kEventControlGetPartRegion : {
                
                }
                break;
                
                case kEventControlGetPartBounds : {
                
                }
                break;
                
                case kEventControlSetData : {
                
                }
                break;
                
                case kEventControlGetData : {
                
                }
                break;
                
                case kEventControlGetSizeConstraints : {
                
                }
                break;
                
                case kEventControlValueFieldChanged : {
                
                }
                break;
                
                case kEventControlAddedSubControl : {
                
                }
                break;
                
                case kEventControlRemovingSubControl : {
                
                }
                break;
                
                case kEventControlBoundsChanged : {
                
                }
                break;
                
                case kEventControlTitleChanged : {
                
                }
                break;
                
                case kEventControlOwningWindowChanged : {
                
                }
                break;
                
                case kEventControlHiliteChanged : {
                
                }
                break;
                
                case kEventControlEnabledStateChanged : {
                
                }
                break;
                
                case kEventControlArbitraryMessage : {
                
                }
                break;            
            }
        }
        break;
        
        case kEventClassCommand : {
            switch ( whatHappened ) {
                case kEventProcessCommand : {
                
                }
                break;
                
                case kEventCommandUpdateStatus : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassTablet : {
        
        }
        break;
        
        case kEventClassVolume : {
        
        }
        break;
        
        case kEventClassAppearance : {
            switch ( whatHappened ) {
                case kEventParamNewScrollBarVariant : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassService : {
            switch ( whatHappened ) {
                case kEventServiceCopy : {
                
                }
                break;
                
                case kEventServicePaste : {
                
                }
                break;
                
                case kEventServiceGetTypes : {
                
                }
                break;
                
                case kEventServicePerform : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassToolbar : {
            switch ( whatHappened ) {
                case kEventParamToolbar : {
                
                }
                break;
                
                case kEventParamToolbarItem : {
                
                }
                break;
                
                case kEventParamToolbarItemIdentifier : {
                
                }
                break;
                
                case kEventParamToolbarItemConfigData : {
                
                }
                break;
            }
        }
        break;
        
        case kEventClassToolbarItem : {
        
        }
        break;
        
        case kEventClassAccessibility : {
        
        }
        break;
    }
    return result;
}

EventRef OSXUIToolkit::createUserCarbonEvent( UInt32 eventType )
{
    EventRef result = NULL;
    
    OSStatus err = CreateEvent( NULL, 
                                OSXUIToolkit::CustomEventClass, 
                                eventType, 
                                GetCurrentEventTime(), 
                                kEventAttributeUserEvent,
                                &result );
                                
    if ( err != noErr ) {
        printf( "OSXUIToolkit::createUserCarbonEvent CreateEvent failed!\n" );
    }
    else {
        
    }
    
    return result;
}

VCF::Size OSXUIToolkit::internal_getDragDropDelta()
{
    Size result;
    return result;
}


