#ifndef _VCF_OSXCONTROL_H__
#define _VCF_OSXCONTROL_H__

// OSXControl.h


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


namespace VCF {


class OSXControl : public Object, public ControlPeer {
public:

	OSXControl( Control* control );
	
	virtual ~OSXControl();

	virtual long getHandleID();
	
	virtual void create( Control* owningControl );
	
	virtual void destroyControl();
	
    virtual String getText() { 
		return String();
	}

    virtual void setText( const String& text ){};

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
	
	static void setCurrentCreateHIView( TView* view );
	
	static TView* getCurrentCreateHIView() {
		return OSXControl::currentCreatedView;
	}
protected:
	TView* hiView_;
	Control* control_;
	EventHandlerRef handlerRef_;
	
	OSStatus handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent );
	
	static TView* currentCreatedView;
	
	static EventHandlerUPP getEventHandlerUPP();
	static OSStatus handleOSXEvents(EventHandlerCallRef nextHandler, EventRef theEvent, void* userData); 
};


}; //end of namespace VCF



#endif // _VCF_OSXCONTROL_H__

