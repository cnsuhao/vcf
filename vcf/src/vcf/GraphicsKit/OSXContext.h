

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

#ifndef _VCF_OSXCONTEXT_H__
#define _VCF_OSXCONTEXT_H__



namespace VCF {

class GraphicsContext;


class OSXContext  : public ContextPeer, public Object {
public:
	OSXContext();
	/**
	*Creates a new HDC from scratch
	*/
	OSXContext( const unsigned long& width, const unsigned long& height );	

	OSXContext( const unsigned long& contextID );	

	virtual ~OSXContext();

	virtual void setContext( GraphicsContext* context );

	virtual GraphicsContext* getContext();	

	virtual unsigned long getContextID();

	virtual void setContextID( const unsigned long& handle );
	
	virtual void textAt( const Rect& bounds, const String & text, const long& drawOptions=0 );	

	virtual double getTextWidth( const String& text );

	virtual double getTextHeight( const String& text );

    virtual void rectangle(const double & x1, const double & y1, const double & x2, const double & y2);

	virtual void roundRect(const double & x1, const double & y1, const double & x2, const double & y2,
							 const double & xc, const double & yc);    

    virtual void ellipse(const double & x1, const double & y1, const double & x2, const double & y2 );

	virtual void arc(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3, 
						 const double & y3, const double & x4, const double & y4);

    virtual void polyline(const std::vector<Point>& pts);

    virtual void curve(const double & x1, const double & y1, const double & x2, const double & y2,
                         const double & x3, const double & y3, const double & x4, const double & y4);

    virtual void lineTo(const double & x, const double & y);

    virtual void moveTo(const double & x, const double & y);

	void init();

	virtual void setOrigin( const double& x, const double& y );

	virtual Point getOrigin();

	virtual void copyContext( const Rect& sourceRect, 
								const Rect& destRect, 
								ContextPeer* sourceContext );

	virtual bool isMemoryContext();

	virtual bool prepareForDrawing( long drawingOperation );

	virtual void finishedDrawing( long drawingOperation );

	virtual void drawImage( const double& x, const double& y, Rect* imageBounds, Image* image );
	
	virtual void checkHandle();
	
	virtual void releaseHandle();

	virtual bool isXORModeOn();

	virtual void setXORModeOn( const bool& XORModeOn );

	virtual void setTextAlignment( const bool& alignTobaseline );

	virtual bool isTextAlignedToBaseline();

	virtual void drawSelectionRect( Rect* rect );

	virtual void drawButtonRect( Rect* rect, const bool& isPressed );
	
	virtual void drawCheckboxRect( Rect* rect, const bool& isPressed );
		
	virtual void drawRadioButtonRect( Rect* rect, const bool& isPressed );

	virtual void drawVerticalScrollButtonRect( Rect* rect, const bool& topButton, const bool& isPressed );

	virtual void drawHorizontalScrollButtonRect( Rect* rect, const bool& leftButton, const bool& isPressed );

	virtual void setClippingPath( Path* clippingPath );

	virtual void setClippingRect( Rect* clipRect );

	virtual void drawDisclosureButton( Rect* rect, const long& state );

	virtual void drawTab( Rect* rect, const bool& selected, const String& caption );

	virtual void drawTabPage( Rect* rect );

	virtual void drawHeader( Rect* rect );

	virtual void drawEdge( Rect* rect, const long& edgeSides, const long& edgeStyle );

	virtual void drawSizeGripper( Rect* rect );

	virtual void drawControlBackground( Rect* rect );

	virtual void drawWindowBackground( Rect* rect );
	virtual void drawMenuItemBackground( Rect* rect, const bool& selected );
	
    virtual void drawTickMarks( Rect* rect, const SliderInfo& sliderInfo  );

	virtual void drawSliderThumb( Rect* rect, const SliderInfo& sliderInfo );

	virtual void drawSlider( Rect* rect, const SliderInfo& sliderInfo );
protected:
	CGContextRef contextID_;
    GrafPtr grafPort_;
	unsigned char* inMemoryImage_;
    ulong32 imgWidth_;
    ulong32 imgHeight_;
	GraphicsContext* context_;
	void* bezierPath_;
	long currentDrawingOperation_;
	ATSUTextLayout textLayout_;
	VCF::Point origin_;
    bool xorModeOn_;
    
	void atsuDrawTextInBox(	const VCF::Rect& rect );
	
	double getLayoutWidth( ATSUTextLayout layout );
	
	void setLayoutWidth( ATSUTextLayout layout, double width );
	VCF::Size getLayoutDimensions( const String& text );
};

}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2.2.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:41  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.3  2004/02/23 05:51:42  ddiego
*basic GraphicsKit implementation done for OSX
*
*Revision 1.1.2.2  2004/02/22 06:50:12  ddiego
*more progress with the OSX GraphicsKit - almost done!
*
*Revision 1.1.2.1  2004/02/21 03:27:06  ddiego
*updates for OSX porting
*
*/

#endif // _VCF_OSXCONTEXT_H__






	