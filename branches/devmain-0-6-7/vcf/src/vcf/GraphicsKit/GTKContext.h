#ifndef _VCF_GTKCONTEXT_H__
#define _VCF_GTKCONTEXT_H__
//GTKContext.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {

class GTKImage;


/**

*/
class GRAPHICSKIT_API GTKContext  : public Object, public ContextPeer  {
public:

	GTKContext();

	GTKContext( const unsigned long& width, const unsigned long& height );

	GTKContext( OSHandleID contextID );

	virtual ~GTKContext();

	void init();

	virtual void setContext( GraphicsContext* context );

	virtual GraphicsContext* getContext();

	virtual OSHandleID getContextID();

	virtual void setContextID( OSHandleID handle );

	virtual void setClippingPath( Path* clippingPath );

	virtual void setClippingRect( Rect* clipRect );

	virtual bool prepareForDrawing( long drawingOperation );

	virtual void finishedDrawing( long drawingOperation );


	virtual void drawImage( const double& x, const double& y, Rect* imageBounds, Image* image );

    virtual void textAt( const Rect& bounds, const String & text, const long& drawOptions=0 );

	virtual double getTextWidth( const String& text );

	virtual double getTextHeight( const String& text );

    virtual void rectangle(const double & x1, const double & y1, const double & x2, const double & y2);
	
	virtual void roundRect( const double & x1, const double & y1,
								const double & x2, const double & y2,
								const double & xc, const double & yc );

    virtual void ellipse(const double & x1, const double & y1, const double & x2, const double & y2 );

	virtual void arc( const double & x1, const double & y1, const double & x2, const double & y2,
                      const double & x3, const double & y3, const double & x4, const double & y4 );


    virtual void polyline( const std::vector<Point>& pts);

    virtual void curve(const double & x1, const double & y1, const double & x2, const double & y2,
                         const double & x3, const double & y3, const double & x4, const double & y4);

    virtual void lineTo(const double & x, const double & y);

    virtual void moveTo(const double & x, const double & y);

	virtual void setOrigin( const double& x, const double& y );

	virtual Point getOrigin();

	virtual void copyContext( const Rect& sourceRect,
											const Rect& destRect,
											ContextPeer* sourceContext );

	virtual bool isMemoryContext();

	virtual void checkHandle();

	virtual void releaseHandle();

	virtual bool isXORModeOn();

	virtual void setXORModeOn( const bool& XORModeOn );

	virtual bool isAntiAliasingOn();
	
	virtual void setAntiAliasingOn( bool antiAliasingOn );
	
	virtual void setTextAlignment( const bool& alignTobaseline );

	virtual bool isTextAlignedToBaseline();

	virtual void drawThemeSelectionRect( Rect* rect, DrawUIState& state );
	
	virtual void drawThemeFocusRect( Rect* rect, DrawUIState& state );
	
	virtual void drawThemeButtonRect( Rect* rect, ButtonState& state );

	virtual void drawThemeCheckboxRect( Rect* rect, ButtonState& state );

	virtual void drawThemeRadioButtonRect( Rect* rect, ButtonState& state );

	virtual void drawThemeComboboxRect( Rect* rect, ButtonState& state );

	virtual void drawThemeScrollButtonRect( Rect* rect, ScrollBarState& state );

	/**
	Draws a button that is used to open up more details, for example
	the button that opens up a tree node to reveal it's children, that is compliant
	with the native windowing systems default look and feel.
	On Win32 this is usually represented by the "+" and "-" look as found on
	the tree controls, while on OSX it is the little triangles
	*/
	virtual void drawThemeDisclosureButton( Rect* rect, DisclosureButtonState& state );

	/**
	Draws a tab, the part of the TabbedPages control that acts like a
	little button to activate a page, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTab( Rect* rect, TabState& state );

	/**
	Draws a tab page - the page on which other controls for the page are
	parented to, that is compliant) = 0;
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTabPage( Rect* rect, DrawUIState& state );

	/**
	Draws a tick mark, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTickMarks( Rect* rect, SliderState& state );
	
	/**
	Draws a slider control, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeSlider( Rect* rect, SliderState& state );
	
	/**
	Draws a progress bar control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeProgress( Rect* rect, ProgressState& state );	
	
	virtual void drawThemeImage( Rect* rect, Image* image, DrawUIState& state );

	/**
	Draws a header control that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeHeader( Rect* rect, ButtonState& state );

	/**
	draws edges, useful for separators, that is compliant
	with the native windowing systems default look and feel.
	use a mask or 1 or more values of type ContextPeer::EdgeType
	to indicate which sides of the rect to draw an edge on
	*/
	virtual void drawThemeEdge( Rect* rect, DrawUIState& state, const long& edgeSides, const long& edgeStyle );

	/**
	Draws a size gripper for resizing a control/window that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeSizeGripper( Rect* rect, DrawUIState& state );

	/**
	Draws a them compliant background
	*/
	virtual void drawThemeBackground( Rect* rect, BackgroundState& state );

	/**
	Draws the background appropriate for a menu item that is compliant
	with the native windowing systems default look and feel.
	This is typically called first by a menu item to give it a standard
	look and feel in it's background before drawing any thing else
	*/
	virtual void drawThemeMenuItem( Rect* rect, MenuState& state );

	virtual void drawThemeMenuItemText( Rect* rect, MenuState& state );

	virtual void drawThemeText( Rect* rect, TextState& state );
	
	void setParentImage( GTKImage* image ) {
		parentImage_ = image;
	}

	GdkDrawable* getDrawable() {
		return drawable_;
	}

	GdkGC* getGC() {
		return gdkGC_;
	}

protected:

	GdkDrawable* drawable_;
	GdkGC* gdkGC_;
	PangoContext* pangoCtx_;
	PangoLayout* pangoLayout_;

	unsigned long pixmapWidth_;
	unsigned long pixmapHeight_;


	//std::vector<PointOperation*> pathOperations_;
	//std::vector<TextOperation*> textOperations_;

	Point currentMoveTo_;
	Point oldOrigin_;
	Point origin_;

	bool inFillPath_;
	bool isMemoryCtx_;
	//bool pathStarted_;
	bool isXORModeOn_;
	bool alignToBaseline_;


	GraphicsContext* context_;

	GTKImage* parentImage_;

	GtkStyle* getGTKStyle( GtkWidget* widget );
	GtkStateType getGTKState( GtkWidget* widget );

	//void clearBuffer();
	//void clearPathBuffer();
	//void clearTextBuffer();
	//void testBuffer();

	//void execPathOperations();
};

};


/**
*CVS Log info
*$Log$
*Revision 1.2.4.1  2005/04/17 16:11:32  ddiego
*brought the foundation, agg, and graphics kits uptodate on linux
*
*Revision 1.2  2004/08/07 02:49:17  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.5.4.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.4.2.1  2003/11/01 20:39:35  ddiego
*added gtk toolbar - no implementation yet
*
*Revision 1.4  2003/08/09 02:56:44  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.3.2.2  2003/06/01 16:43:58  ddiego
*further GTK support added
*
*Revision 1.3.2.1  2003/05/30 04:13:10  ddiego
*added the commandLine class
*changed the intialization functions for teh FoundationKit, GraphicsKit, and
*ApplicationKit to take command line parameters
*FoundationKit now allows you to retreive the commandline (it's stored)
*start up has changed from appMain() to main()
*added a custom GTK widget class for use in the various GTK peers - this will
*allow us to specify absolute positioning and let the VCF handle layout
*issues
*Miscellaneous clean in various interfaces
*removed the Rect, Point, and Size classes from the FoundationKit
*and moved them to the GraphicsKit
*
*Revision 1.3  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.2.2  2003/04/17 04:29:48  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.2.2.1  2003/03/12 03:10:53  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.1.2.2  2003/02/23 05:08:14  ddiego
*finished up the GTKImage class. Now putting in text rendering with pango support
*
*Revision 1.1.2.1  2003/02/20 02:46:02  ddiego
*added in the base files for supporting a GTK peer implementation. Core parts
*of the GTKContext work (basic line primitives), and working on the GTKImage
*class.
*
*Auto generated header for class GTKContext
*/


#endif // _VCF_GTKCONTEXT_H__

