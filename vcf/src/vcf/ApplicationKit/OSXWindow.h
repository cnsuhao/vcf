#ifndef _VCF_OSXWINDOW_H__
#define _VCF_OSXWINDOW_H__
//OSXWindow.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/WindowPeer.h"

namespace VCF {


class OSXWindow : public Object, public ControlPeer, public WindowPeer {
public:

        enum WindowState{
		wsNone = 0,
		wsMaximized,
		wsMinimized,
		wsNormal
	};

	OSXWindow( Control* control, Control* owner );

	virtual ~OSXWindow();

	virtual long getHandleID() {
		return (long)windowRef_;
	}

	virtual void create( Control* owningControl );

	virtual void destroyControl();

    virtual String getText();

    virtual void setText( const String& text );

    virtual void setBounds( Rect* rect );

	virtual bool beginSetBounds( const ulong32& numberOfChildren );

	virtual void endSetBounds();

    virtual Rect getBounds();

    virtual void setVisible( const bool& visible );

    virtual bool getVisible();

    virtual Control* getControl();

    virtual void setControl( Control* component );

    virtual void setCursor( Cursor* cursor );

	virtual void setParent( Control* parent );

	virtual Control* getParent();

	virtual bool isFocused();

	virtual void setFocused();

	virtual bool isEnabled();

	virtual void setEnabled( const bool& enabled );

	virtual void setFont( Font* font );

	virtual void repaint( Rect* repaintRect=NULL );

	virtual void keepMouseEvents();

	virtual void releaseMouseEvents();

	virtual void translateToScreenCoords( Point* pt );

	virtual void translateFromScreenCoords( Point* pt );

	static OSXWindow* getOSXWindowFromWindowRef( WindowRef windowRef );

	Rect internal_getBounds() {
		return bounds_;
	}

	void internal_setBounds( const Rect& bounds ) {
		bounds_ = bounds;
	}


    //Window peer methods
	virtual Rect getClientBounds();

	virtual void  setClientBounds( Rect* bounds );

	virtual void close();

	virtual void setFrameStyle( const FrameStyleType& frameStyle );

	virtual void setFrameTopmost( const bool& isTopmost );

	virtual bool isMaximized();

	virtual void setMaximized( const bool maximised );

	virtual bool isMinimized();

	virtual void setMinimized( const bool& minimized );

	virtual void restore();

	virtual void setIconImage( Image* icon );

    OSStatus handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent );

	bool isComposited();
protected:
	static EventHandlerUPP getEventHandlerUPP();

	typedef std::map<WindowRef,OSXWindow*> OSXWindowMap;

	static void registerOSXWindow( OSXWindow* osxWindow );
	static void unRegisterOSXWindow( OSXWindow* osxWindow );

	static OSXWindowMap osxWindowMap;


	WindowRef windowRef_;

	Control* control_;

	Rect bounds_;
    EventHandlerRef handlerRef_;
	EventHandlerRef contentViewHandlerRef_;

	RgnHandle determineUnobscuredClientRgn();

	void handleDraw( bool drawingEvent, EventRef event );

    bool internalClose_;

    static OSStatus handleOSXEvents(EventHandlerCallRef nextHandler, EventRef theEvent, void* userData);
    void updateWindow();
};


}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.7  2004/06/06 07:05:30  marcelloptr
*changed macros, text reformatting, copyright sections
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
*Revision 1.2.2.1  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.2  2004/02/25 05:17:55  ddiego
*updates to ApplicationKit to support posting events and timer and idle time handlers for the OSX UI Toolkit.
*
*Revision 1.1.2.1  2004/02/24 01:42:43  ddiego
*initial OSX ApplicationKit port checkin
*
*/


#endif // _VCF_OSXWINDOW_H__


