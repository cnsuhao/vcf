#ifndef _VCF_FRAME_H__
#define _VCF_FRAME_H__
//Frame.h

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


#define FRAME_CLASSID			"ED88C0A2-26AB-11d4-B539-00C04F0196DA"

enum FrameStyleType {
	fstSizeable = 0,
	fstNoBorder,
	fstFixed,
	fstNoBorderFixed,
	fstToolbarBorder,
	fstToolbarBorderFixed
};

static String FrameStyleTypeNames[] = { "fstSizeable",
                                         "fstNoBorder",
										 "fstFixed",
										 "fstNoBorderFixed",
										"fstToolbarBorder",
										"fstToolbarBorderFixed"		 };

/**
A frame is a component that houses other components,
plus has special adornments used for interacting with it.
These can include minimize, maximize, restore, system, and help buttons on the caption bar,
which is also part of the frame.

@delegates
	@del Frame::FrameClose
	@del Frame::FrameActivation
	@del Frame::FrameClosing
*/
class APPLICATIONKIT_API Frame : public VCF::Control, public DelegatedContainer<Frame>  {
public:

	class State : public Object, public Persistable{
	public:
		State();

		enum FrameDisplayState{
			fdsMaximized=0,
			fdsMinimized,
			fdsNormal
		};

		void applyState( Frame* frame );

		void initState( Frame* frame );

		virtual void loadFromStream( InputStream* stream );

		virtual void saveToStream( OutputStream* stream );
	protected:
		Rect bounds_;
		bool visible_;
		FrameDisplayState displayState_;
	};



	Frame();

	virtual ~Frame();


	enum FrameEventTypes{
		ACTIVATION_EVENT = CUSTOM_EVENT_TYPES + WINDOW_CONST + 6,
		CLOSE_EVENT = WINDOW_EVENT_CLOSE,
		CLOSING_EVENT = WINDOW_EVENT_CLOSE + 1
	};

	/**
	@delegate FrameClose this is fired when the frame is closed, either in response to
	events from the underlying windowing system, or programmatically by calling the
	close() method.
	@event WindowEvent
	@eventtype Frame::CLOSE_EVENT
	@see close()
	*/
	DELEGATE(FrameClose)

	/**
	@delegate FrameActivation this is called when the frame becomes activated. Typically
	this is a result of events that the framework processes from the underlying
	windowing system. It is also fired when the activate() method is called.
	@event WindowEvent
	@eventtype Frame::ACTIVATION_EVENT
	@see activate()
	*/
	DELEGATE(FrameActivation)

	/**
	@delegate FrameClosing this is fired just before the windowing system attempts to close
	the frame. Depending on how a handler manipulates data on the fired FrameEvent, it
	can prevent the the frame from closing.
	@event FrameEvent
	@eventtype Frame::CLOSING_EVENT
	@see FrameEvent::setOkToClose
	@see allowClose()
	*/
	DELEGATE(FrameClosing)


	/**
	Sets the caption for the frame. While the exact effects of calling this method
	depend on windowing system the VCF is running on, in general a caption is
	displayed on the top of the frame, and is generally a non client area. This
	method will change the text that is displayed there.
	@param String the new caption to display in the Frame's caption area.
	*/
    virtual void setCaption( const String& caption );

	/**
	The current text of the Frame's caption.
	*/
    virtual String getCaption();

	/**
	Sets the client bounds only.
	*/
	virtual void  setClientBounds( Rect* bounds ) = 0;

	virtual void paint( GraphicsContext * context );

	/**
	Shows the frame. Generally the same as calling Control::setVisible(true)
	@see Control::setVisible
	*/
	virtual void show();

	/**
	Hides the frame. Dependending on the underlying windowing system, the frame may
	be minimized.
	*/
	virtual void hide();

	/**
	Closes the Frame. Must be implemented by classes that derive from Frame.
	*/
	virtual void close() = 0;

	/**
	Is this frame the top most frame amongst the application's current collection of
	frame windows.
	@return bool returns true if the frame is topmost, otherwise it returns false.
	*/
	virtual bool isFrameTopmost();

	/**
	Makes this frame a topmost floating window. This is typically used for frames that want
	to behave like toolbars.
	*/
	virtual void setFrameTopmost( const bool& isTopmost );

	/**
	returns the current frame style.
	*/
	virtual FrameStyleType getFrameStyle(){
		return 	frameStyle_;
	};

	/**
	Sets the frame style
	*/
	virtual void setFrameStyle( const FrameStyleType& frameStyle ) = 0;

	/**
	override this function to changes the frame's default
	parenting behaviour. By default a frame may have it's
	parent set to another control without becoming a child
	control itself.
	@return bool returns true if the frame is to be allowed to
	act as a child control when it's setParent() method is called.
	*/
	virtual bool allowFrameAsChildControl() {
		return false;
	}

	/**
	Indicates whether or not this frame is active.
	@return bool returns true if the frame is active otherwise it returns false.
	*/
	bool isActive();

	/**
	Activates this frame.
	*/
	virtual void activate();

	/*
	Indicates to the framework whether or not this frame should allow activation.
	Som frames do <i>not</i> support becoming activated, for example the tooltip frame,
	or the frame that houses the dropdown list for the ComboBoxControl. Must be implemented
	by derived classes.
	*/
	virtual bool allowsActivation() = 0;

	/**
	Sets the icon image. The behaviour of this is partially windowing system dependent,
	and some systems (Mac OSX, for example, or some X11 window managers) may choose to
	ignore this. However, typically the icon is displayed in the top left corner of the
	frame, in the non client area that houses the caption.

	*/
	virtual void setIconImage( Image* icon ) = 0;

	/**
	Returns the current image for the frames icon.
	*/
	virtual Image* getIconImage() = 0;
	
	virtual bool isActiveFrame() = 0;

	/**
	A static method uses to determine the current active frame.
	@return Frame the currently active frame. This may be NULL.
	*/
	static Frame* getActiveFrame();

	/**
	*don't call - for internal use only
	*/
	void setIsActive( const bool& active );	

	virtual void afterCreate( ComponentEvent* event );

	/**
	This method is called by the framework to determine whetehr or not the frame should
	actually be closed. This method is the first step in determining if a frame can
	be closed. If it returns true, then the FrameClosing is called. Note that the
	frame can still be prevented from closing depending on how the event handlers
	attached to the FrameClosing delegate are implemented. If this method returns
	false then the frame is not closed, and the FrameClosing event is not fired.
	*/
	virtual bool allowClose();

	void setUseColorForBackground( const bool& val ) {
		useColorForBackground_ = val;
		repaint();
	}
	
	bool getUseColorForBackground() {
		return useColorForBackground_;
	}
	/**
	*don't call - for internal use only
	*/
	static void setActiveFrame( Frame* activeFrame );
protected:
	static Frame* currentActiveFrame;
	String caption_;
	FrameStyleType frameStyle_;
	bool isTopmostFrame_;
	bool useColorForBackground_;


	virtual void destroy();

};

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3.2.1  2004/07/06 03:27:12  ddiego
*more osx updates that add proper support
*for lightweight controls, some fixes to text layout, and some window painting issues. Also a fix
*so that controls and windows paint either their default theme background or their background
*color.
*
*Revision 1.1.2.3  2004/06/06 07:05:30  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:13  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.20.4.1  2004/04/26 21:58:19  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.20  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.19.2.5  2003/12/08 05:05:28  ddiego
*added a bunch more documentation to classes, and added support for new doc
*keywords (@delegates, @del, @delegate, @event, and @eventtype). This
*makes it easier to see at a glance what events a class fires off.
*Added finishing touches for the Action implementation and have a partially
*complete example for this checked in.
*
*Revision 1.19.2.4  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.19.2.3  2003/09/06 19:45:44  ddiego
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
*Revision 1.19.2.2  2003/09/05 21:03:38  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.19.2.1  2003/08/18 19:52:32  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.19  2003/08/09 02:56:42  ddiego
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
*Revision 1.18.2.1  2003/05/27 04:45:25  ddiego
*doing some code cleanup to fix some bugs in the way dialogs and popups
*work in Win32 port. Cleaned up the ControlPeer and DialogPeer interfaces
*a bit.
*
*Revision 1.18  2003/05/17 20:37:03  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.17.2.2  2003/03/23 03:23:45  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.17.2.1  2003/03/12 03:09:34  ddiego
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
*Revision 1.16.8.2  2003/02/24 05:42:18  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.16.8.1  2002/12/25 22:06:19  ddiego
*whole bunch of little changes to the header files used by the ApplicationKit
*to get rid of no newline warnings by gcc.
*fixes to various event handlers in the ApplicationKit to compile with gcc
*since gcc does not like a member function pointer without the "&"
*addressof operator.
*Added initial file for the X11 UIToolkit implementation
*
*Revision 1.16  2002/09/12 03:26:03  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.15.12.1  2002/08/13 04:28:22  ddiego
*bugs fixed:
*[ 585085 ] Can't get at multi selected filenames - this was just a matter of exposing a function that was already available in the
*peer class
*
*features:
*58839 Add a method to query closing a Frame, this required a change that included added a new event (FrameEvent and the corresponding
*FrameEventHandler) and a method, bool Frame::allowClose()
*
*Also made fixes in the VCF Builder to now take advantage of this, so the MainWindow class will now register an event
*handler to handler the FrameClosing event, and attempt to set the current workspace to NULL. If this does not happen then
*the closing event will fail and prevent the widnow from being shutdown. Woo hoo !
*
*Revision 1.15  2002/03/01 05:11:24  ddiego
*added some methods for saving an applications state and doing so
*automatically if the developer wants
*
*Revision 1.14  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_FRAME_H__


