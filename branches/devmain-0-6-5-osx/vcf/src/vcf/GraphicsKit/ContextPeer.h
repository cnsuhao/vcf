#ifndef _VCF_CONTEXTPEER_H__
#define _VCF_CONTEXTPEER_H__
//ContextPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


namespace VCF{

class Path;
class Font;
class Point;
class Image;
class GraphicsContext;
class DrawUIState;
class MenuState;
class ButtonState;
class DisclosureButtonState;
class ProgressState ;
class SliderState;
class ScrollBarState;
class TabState;
class BackgroundState;
class TextState;

/**
*The ContextPeer serves as a platform neutral interface
*for a set of standard drawing methods that should provide
*the following functionality:
*<ul>
*	<li>A base set of 2D drawing primitives, like lines, ellipse,
*		rectangles, etc.
*	<li>The ability to specify line width, line color, and simple line patterns
*	<li>The ability to fill or stroke the various graphics primitives
*	<li>Basic text functions
*	<li>a set of utility methods for drawing common UI shapes, like a
*		selection rectangle, tab, scroll buttons, or a 3D button frame, etc. These may be
*		drawn differently depending on the underlying windowing system
*</ul>
*/
class GRAPHICSKIT_API ContextPeer {
public:

	virtual ~ContextPeer(){};

	virtual void setContext( GraphicsContext* context ) = 0;

	virtual GraphicsContext* getContext() = 0;

	virtual unsigned long getContextID() = 0;

	virtual void setContextID( const unsigned long& contextID ) = 0;

	/**
	this method is called for the peer to initialize any graphics resources
	before calling the following methods:
	<ul>
		<li>textAt</li>
		<li>getTextWidth</li>
		<li>getTextHeight</li>
		<li>rectangle</li>
		<li>ellipse</li>
		<li>arc</li>
		<li>polyline</li>
		<li>curve</li>
		<li>moveTo</li>
		<li>lineTo</li>
	</ul>
	Since the drawing primitives like (rectangle, moveTo, etc) are executed as a series
	of operations by the GraphicsContext, this means that prepareForDrawing() will
	get called as part of the GraphicsContext::fillPath(), GraphicsContext::strokePath(),
	or GraphicsContext::textAtXXX() methods. prepareForDrawing() will be called <i>prior</i>
	to any of the drawing primitive functions in the above list, allowing the peer to initialize
	whatever graphics resources need to be as specified by the GraphicsContext.
	*/
	virtual bool prepareForDrawing( long drawingOperation ) = 0;

	virtual void finishedDrawing( long drawingOperation ) = 0;

	/**
	*sets the current clipping path to be used for the duration of the Contexts lifetime or
	*until it has been changed
	*/
	virtual void setClippingPath( Path* clippingPath ) = 0;

	virtual void setClippingRect( Rect* clipRect ) = 0;

	/**
	*this is used to determine how to
	*align text when the windowing systems
	*draws it. Currently the choices are 2:
	*either it is aligned to the top, or in other
	*words the coordinates specified represent the
	*top, left position to start rendering the text,
	*or aligned to the baseline, in which the top,
	*left coordinates represent the baseline point of
	*origin. The latter setting is useful when
	*drawing text whith different font styles
	*/
	virtual void setTextAlignment( const bool& alignTobaseline ) = 0;

	virtual bool isTextAlignedToBaseline() = 0;

	virtual void textAt( const Rect& bounds, const String & text, const long& drawOptions=0 ) = 0;

	virtual double getTextWidth( const String& text ) = 0;

	virtual double getTextHeight( const String& text ) = 0;

	virtual void rectangle( const double & x1, const double & y1,
								const double & x2, const double & y2 ) = 0;

	virtual void ellipse( const double & x1, const double & y1,
							const double & x2, const double & y2 ) = 0;

	virtual void arc( const double & x1, const double & y1,
						const double & x2, const double & y2,
						const double & x3, const double & y3,
						const double & x4, const double & y4 ) = 0;

    virtual void polyline( const std::vector<Point>& pts ) = 0;

	virtual void curve( const double & x1, const double & y1, const double & x2, const double & y2,
                        const double & x3, const double & y3, const double & x4, const double & y4 ) = 0;

	virtual void moveTo( const double & x, const double & y ) = 0;

	virtual void lineTo( const double & x, const double & y ) = 0;


	virtual void setOrigin( const double& x, const double& y ) = 0;

 	virtual Point getOrigin() = 0;

	virtual void copyContext( const Rect& sourceRect,
								const Rect& destRect,
								ContextPeer* sourceContext ) = 0;

	/**
	*is this context Peer in memory or does it associated with a
	*component ?
	*@return bool true if the context is on memory, otherwise false
	*/
	virtual bool isMemoryContext() = 0;

	/**
	*returns whether or not the XOR Mode is turned on.
	*@return bool if the return is true then the
	*XOR mode is on, which means that colors are alternated
	*at the pixel level. Thus a line drawn once, and then
	*a second time at the same coordinates will erase itself
	*/
	virtual bool isXORModeOn() = 0;

	/**
	*Turns the XOR mode on or off.
	*@param bool XORModeOn, if true then turns the XORMode on
	*otherwise if it's false it turns it off.
	*/
	virtual void setXORModeOn( const bool& XORModeOn ) = 0;


	virtual void drawImage( const double& x, const double& y, Rect* imageBounds, Image* image ) = 0;


	virtual void drawThemeSelectionRect( Rect* rect, DrawUIState& state ) = 0;

	virtual void drawThemeButtonRect( Rect* rect, ButtonState& state ) = 0;

	virtual void drawThemeCheckboxRect( Rect* rect, ButtonState& state ) = 0;

	virtual void drawThemeRadioButtonRect( Rect* rect, ButtonState& state ) = 0;

	virtual void drawThemeScrollButtonRect( Rect* rect, DrawUIState& state ) = 0;

	/**
	Draws a button that is used to open up more details, for example
	the button that opens up a tree node to reveal it's children, that is compliant
	with the native windowing systems default look and feel.
	On Win32 this is usually represented by the "+" and "-" look as found on
	the tree controls, while on OSX it is the little triangles
	*/
	virtual void drawThemeDisclosureButton( Rect* rect, DisclosureButtonState& state ) = 0;

	/**
	Draws a tab, the part of the TabbedPages control that acts like a
	little button to activate a page, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTab( Rect* rect, TabState& state ) = 0;

	/**
	Draws a tab page - the page on which other controls for the page are
	parented to, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTabPage( Rect* rect, DrawUIState& state ) = 0;

	/**
	Draws a tick mark, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeTickMarks( Rect* rect, SliderState& state ) = 0;
	
	/**
	Draws a slider control, like that used for a slider control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeSlider( Rect* rect, SliderState& state ) = 0;
	
	/**
	Draws a progress bar control, that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeProgress( Rect* rect, ProgressState& state ) = 0;	
	
	virtual void drawThemeImage( Rect* rect, Image* image, DrawUIState& state ) = 0;

	/**
	Draws a header control that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeHeader( Rect* rect, DrawUIState& state ) = 0;

	/**
	draws edges, useful for separators, that is compliant
	with the native windowing systems default look and feel.
	use a mask or 1 or more values of type ContextPeer::EdgeType
	to indicate which sides of the rect to draw an edge on
	*/
	virtual void drawThemeEdge( Rect* rect, DrawUIState& state, const long& edgeSides, const long& edgeStyle ) = 0;

	/**
	Draws a size gripper for resizing a control/window that is compliant
	with the native windowing systems default look and feel
	*/
	virtual void drawThemeSizeGripper( Rect* rect, DrawUIState& state ) = 0;

	/**
	Draws a them compliant background
	*/
	virtual void drawThemeBackground( Rect* rect, BackgroundState& state ) = 0;

	/**
	Draws the background appropriate for a menu item that is compliant
	with the native windowing systems default look and feel.
	This is typically called first by a menu item to give it a standard
	look and feel in it's background before drawing any thing else
	*/
	virtual void drawThemeMenuItem( Rect* rect, MenuState& state ) = 0;

	virtual void drawThemeText( Rect* rect, TextState& state ) = 0;

};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2.2.3  2004/06/20 00:36:11  ddiego
*finished the new theme API updates
*
*Revision 1.1.2.2.2.2  2004/06/16 05:18:56  ddiego
*further updates to OSX theme compliant drawing code
*
*Revision 1.1.2.2.2.1  2004/06/15 04:04:38  ddiego
*revamped osx theme drawing API
*
*Revision 1.1.2.2  2004/04/29 04:10:26  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.6.4.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.6  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.5.2.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.5  2003/08/09 02:56:44  ddiego
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
*Revision 1.4.2.2  2003/06/16 03:09:39  ddiego
*beginning to add support for AGG into the VCF GraphicsKit
*added some missing files
*added some changes to the new version of xmake
*
*Revision 1.4.2.1  2003/06/05 03:48:53  ddiego
*added a way to get part of a graphics context into an image - no
*implementation yet.
*
*Revision 1.4  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.3  2003/05/13 03:57:13  ddiego
*cleaned up the GraphicsKit, got rid of some old crap files, cleaned
*up the ContextPeer so that tehre are fewer methods to implement, and
*moved the repetitive fillPath and strokePath code that was copied into
*all the context peers back into the GraphicsContext where it belongs
*
*Revision 1.3.2.2  2003/04/17 04:29:47  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.3.2.1  2003/03/23 03:23:49  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.2.4  2003/02/20 02:46:01  ddiego
*added in the base files for supporting a GTK peer implementation. Core parts
*of the GTKContext work (basic line primitives), and working on the GTKImage
*class.
*
*Revision 1.2.2.3  2003/01/08 00:19:45  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.2.2.2  2002/12/31 07:02:16  ddiego
*trying to track issues with parenting in X. Made some fixes in the Color class
*and the ContextPeer class to work in gcc/X
*
*Revision 1.2.2.1  2002/12/28 21:51:18  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.2  2002/11/17 18:13:26  ddiego
*added the "new" ContextPeer.h back into cvs
*
*Revision 1.1.4.3  2002/10/04 05:02:54  ddiego
*added beggining support for add new classes. Basic GUI is now in place.
*Also preliminary support for class templates and class wizards
*some documentation done on the format for the XML based class template
*
*Revision 1.1.4.2  2002/09/27 23:31:19  ddiego
**** empty log message ***
*
*Revision 1.1.4.1  2002/09/27 00:44:54  ddiego
*added the renamed ContextPeer.h file back to CVS
*
*Revision 1.12  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.11.4.1  2002/04/27 15:52:18  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.11  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_CONTEXTPEER_H__


