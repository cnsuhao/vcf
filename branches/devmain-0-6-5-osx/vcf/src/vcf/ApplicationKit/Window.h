#ifndef _VCF_WINDOW_H__
#define _VCF_WINDOW_H__
//Window.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */





namespace VCF {

class WindowPeer;


#define WINDOW_CLASSID				"ED88C0A1-26AB-11d4-B539-00C04F0196DA"


/**
A frame with min. max, restore, and system buttons.
Has a caption of the standard height.

@delegates
	@del Window::WindowRestore
	@del Window::WindowMaximize
	@del Window::WindowMinimize
*/
class APPLICATIONKIT_API Window : public Frame {
public:


	Window();

	Window( Control* control );

	enum WindowEvents{
		weRestore
	};

	virtual ~Window();

	/**
	@delegate WindowRestore this is fired when the window is restored back to it's
	original position. This event is generated by the underlying windowing system.
	@event WindowEvent
	@eventtype WINDOW_EVENT_RESTORE
	*/
	DELEGATE(WindowRestore)

	/**
	@delegate WindowMaximize this is fired when the window is maximized.
	This event is generated by the underlying windowing system.
	@event WindowEvent
	@eventtype WINDOW_EVENT_MAXIMIZE
	*/
	DELEGATE(WindowMaximize)

	/**
	@delegate WindowMinimize this is fired when the window is minimized.
	This event is generated by the underlying windowing system.
	@event WindowEvent
	@eventtype WINDOW_EVENT_MINIMIZE
	*/
	DELEGATE(WindowMinimize)


	virtual void setCaption( const String& caption );

	virtual void paint(GraphicsContext * context);

	/**
	*overridden to take into account client bounds
	**/
	virtual void resizeChildren( Control* control ) ;

	/**
	returns the client bounds of a window. This excludes the areas such as
	the nonclient border, the caption bar, etc.
	*/
	virtual Rect getClientBounds(const bool& includeBorder=true);


	virtual void  setClientBounds( Rect* bounds );

	/**
	Returns the menu bar for the window. While this is partially dependent on how
	the underlying windowing system implements menu bars, in general (at least
	on Win32 and most X11 window managers) the menu bar is attached to the window,
	and displayed directly under the caption bar. It is not considered part of the
	client region. By default, a newly created window has no menu bar.
	@return MenuBar the menu bar of the window, may be NULL.
	*/
	MenuBar* getMenuBar();


	/**
	Sets the menu bar for the window. Note, that this <i>currently</i> does
	not add the menuBar as a component of the window.
	*/
	void setMenuBar( MenuBar* menuBar );

	virtual void beforeDestroy( ComponentEvent* event );

	virtual void close();

	virtual void setFrameStyle( const FrameStyleType& frameStyle );

	virtual void setFrameTopmost( const bool& isTopmost );

	virtual double getPreferredWidth();

	virtual double getPreferredHeight();

	/**
	indicates whether or not the window is maximized.
	@return bool true if the window is minimized, otherwise
	it is false.
	*/
	bool isMaximized();

	/**
	Sets whether or not the window is maximized.
	*/
	void setMaximized( const bool maximized );

	/**
	returns whether or not teh window is minimized
	@return bool true if the window is minimized, otherwise false.
	*/
	bool isMinimized();

	/**
	Sets whether or not the window is minimized.
	*/
	void setMinimized( const bool& minimized );

	/**
	restores the window to it's original position prior to being
	minimized or maximized.
	*/
	void restore();

	virtual bool allowsActivation() {
		return true;
	}

	virtual void setIconImage( Image* icon );

	virtual Image* getIconImage();
	
	virtual bool isActiveFrame();

	void handleEvent( Event* event );
protected:
	void postClose( Event* event );
	void onClose( WindowEvent* e );
    WindowPeer * windowPeer_;
	MenuBar* menuBar_;



	virtual void destroy();
};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3.2.1  2004/07/06 03:27:13  ddiego
*more osx updates that add proper support
*for lightweight controls, some fixes to text layout, and some window painting issues. Also a fix
*so that controls and windows paint either their default theme background or their background
*color.
*
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:16  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.21.2.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.21  2004/01/20 01:54:55  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.19.2.1  2004/01/15 05:35:04  ddiego
*making some minor changes so that nested menu components get handled
*correctly and added from a VFF file
*
*Revision 1.19  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.18.4.7  2003/12/08 05:05:28  ddiego
*added a bunch more documentation to classes, and added support for new doc
*keywords (@delegates, @del, @delegate, @event, and @eventtype). This
*makes it easier to see at a glance what events a class fires off.
*Added finishing touches for the Action implementation and have a partially
*complete example for this checked in.
*
*Revision 1.18.4.6  2003/10/12 06:34:29  ddiego
*added some fixes to standard container layout algorithms - thisstill needs
*to be tested, but it looks like it may fix some outstanding issues
*with the layout logic
*
*Revision 1.18.4.5  2003/09/21 04:15:34  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.18.4.4  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.18.4.3  2003/09/06 19:45:45  ddiego
*changes to ensure that the destroy() is properly called.
*Destructors were moved back to pbulic scope in case that was causing a bug.
*Moving them all(all teh component derived classes) to private scope causes
*a complete failure in hte VC6 compiler. Alas...
*So destructors are present, and modal dialogs can still be created on the
*stack, but almost any other component should be created on the heap, and
*gotten rid of via free() NOT using operator delete directly.
*also moved the vcs info to the end of the file for some of the headers
*This will be an ongoing process.
*
*Revision 1.18.4.2  2003/09/05 21:03:39  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.18.4.1  2003/08/18 19:52:32  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.18  2003/05/17 20:37:05  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.17.2.2  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.17.2.1  2003/03/12 03:09:49  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.17  2003/02/26 04:30:38  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.16.2.3  2003/02/24 05:42:18  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.16.2.2  2002/12/27 23:04:33  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.16.2.1  2002/12/25 22:06:20  ddiego
*whole bunch of little changes to the header files used by the ApplicationKit
*to get rid of no newline warnings by gcc.
*fixes to various event handlers in the ApplicationKit to compile with gcc
*since gcc does not like a member function pointer without the "&"
*addressof operator.
*Added initial file for the X11 UIToolkit implementation
*
*Revision 1.16  2002/11/18 00:46:08  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.15.16.1  2002/11/16 22:00:55  ddiego
*this fixes bug [ 633977 ] Windows not self deleteing then closed.
*Fix was simple - just needed to post an event handler after a recv
*a close event, and in the new event handler we delete the window.
*
*Revision 1.15  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_WINDOW_H__


