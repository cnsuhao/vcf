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

TView* OSXControl::currentCreatedView = NULL;


class OSXControlView : public TView {
public:

	OSXControlView( HIViewRef inControl ):
		TView(inControl){
		
	}
	
	virtual ~OSXControlView() {
	
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
		
};


namespace VCF {



OSXControl::OSXControl( Control* control ):
	hiView_(NULL)
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
	
	Lock l(currentCreateMtx);
	OSXControl::currentCreatedView = view;
}

long OSXControl::getHandleID()
{
	return (long) hiView_;
}

void OSXControl::create( Control* owningControl )
{
	if ( noErr == ViewCreator<WndView>::create( &hiView_, r, windowRef_ ) ) {
		//HIViewSetVisible( windowView_, true );		
	}
}

void OSXControl::destroyControl()
{

}


void OSXControl::setBounds( Rect* rect )
{

}

bool OSXControl::beginSetBounds( const ulong32& numberOfChildren )
{

}

void OSXControl::endSetBounds()
{

}

Rect OSXControl::getBounds()
{

}

void OSXControl::setVisible( const bool& visible )
{

}

bool OSXControl::getVisible()
{

}

Control* OSXControl::getControl()
{

}

void OSXControl::setControl( Control* component )
{

}

void OSXControl::setCursor( Cursor* cursor )
{

}

void OSXControl::setParent( Control* parent )
{

}

Control* OSXControl::getParent()
{

}

bool OSXControl::isFocused()
{

}

void OSXControl::setFocused()
{

}

bool OSXControl::isEnabled()
{

}

void OSXControl::setEnabled( const bool& enabled )
{

}

void OSXControl::setFont( Font* font )
{

}

void OSXControl::repaint( Rect* repaintRect=NULL )
{

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
	
};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.4  2004/05/16 02:39:01  ddiego
*OSX code updates
*
*
*/
