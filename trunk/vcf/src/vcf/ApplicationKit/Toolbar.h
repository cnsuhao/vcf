#ifndef _VCF_TOOLBAR_H__
#define _VCF_TOOLBAR_H__
//Toolbar.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


#ifndef _VCF_ABSTRACTMODEL_H__
#include "vcf/ApplicationKit/AbstractModel.h"
#endif // _VCF_ABSTRACTMODEL_H__





namespace VCF{

class ToolbarButton;

class ToolbarDock;


class ToolbarPeer;



class APPLICATIONKIT_API ToolbarItem : public Item, public Button {
public:

	ToolbarItem();


	enum {
		tbCaptionChanged = 200431,
		tbTooltipChanged,
		tbSelected,
		tbDimensionsChanged,
		tbAdded,
		tbRemoved,
		tbStateChanged,
		tbImageIndexChanged,
		tbStateImageIndexChanged,
		tbIndexChanged,
		tbItemControlAdded,
		tbItemClicked,
		tbItemUpdate,
		tbGroupChanged,
		tbCheckChanged
	};

	enum ToolbarItemState {
		tisNone = 0,
		tisSeparator = 0x01,
		tisSelected = 0x10,
		tisPressed = 0x20,
		tisEnabled = 0x40,
		tisGrouped = 0x100,
		tisChecked = 0x200
	};

	DELEGATE(ItemPainted);
	DELEGATE(ItemChanged);
	DELEGATE(ItemSelected);
	DELEGATE(ItemAdded);
	DELEGATE(ItemDeleted);

	DELEGATE(ItemClicked);

	DELEGATE(ItemUpdate);


	virtual void addItemPaintHandler( EventHandler* handler ){
		ItemPainted += handler;
	}

	virtual void addItemChangedHandler( EventHandler* handler ) {
		ItemChanged += handler;
	}

	virtual void addItemSelectedHandler( EventHandler* handler ) {
		ItemSelected += handler;
	}

	virtual void addItemAddedHandler( EventHandler* handler ) {
		ItemAdded += handler;
	}

	virtual void addItemDeletedHandler( EventHandler* handler ) {
		ItemDeleted += handler;
	}

	virtual void removeItemPaintHandler( EventHandler* handler ) {
		ItemPainted -= handler;
	}

	virtual void removeItemChangedHandler( EventHandler* handler ) {
		ItemChanged -= handler;
	}

	virtual void removeItemSelectedHandler( EventHandler* handler ) {
		ItemSelected -= handler;
	}

	virtual void removeItemAddedHandler( EventHandler* handler ) {
		ItemAdded -= handler;
	}

	virtual void removeItemDeletedHandler( EventHandler* handler ) {
		ItemDeleted -= handler;
	}

	virtual void addButtonClickHandler( EventHandler* handler ) {
		ItemClicked += handler;
	}

	virtual void removeButtonClickHandler( EventHandler* handler ) {
		ItemClicked -= handler;
	}

	virtual void click();

	virtual void setDefault( const bool& defaultButton ) {}

	virtual bool isDefault(){
		return false;
	};

    virtual bool containsPoint( Point * pt );

	virtual Rect* getBounds() {
		return &bounds_;
	}

	virtual void setBounds( Rect* bounds );

	virtual long getState() {
		return state_;
	}

	virtual void setState( const long& state );

	virtual long getStateImageIndex() {
		return imageStateIndex_;
	}

	virtual void setStateImageIndex( const long& index );

    virtual ulong32 getIndex();

	virtual long getImageIndex() {
		return imageIndex_;
	}

	virtual void setImageIndex( const long& imageIndex );

	virtual void setIndex( const unsigned long& index ) ;

    virtual void* getData() {
		return data_;
	}

	virtual void setData( void* data ) {
		data_ = data;
	}

	virtual Model* getModel() {
		return model_;
	}

	virtual void setModel( Model* model ) {
		model_ = model;
	}

	virtual bool canPaint() {
		return false;
	};

	virtual void paint( GraphicsContext* context, Rect* paintRect ) {};

	virtual bool isSelected() ;

	virtual void setSelected( const bool& selected );

	virtual Control* getControl() {
		return control_;
	}

	virtual void setControl( Control* control ) {
		control_ = control;
	}

	virtual long getTag(){
		return tag_;
	}

	virtual void setTag( const long& tag ) {
		tag_ = tag;
	}



	void setWidth( const double& val );

	String getCaption() {
		return caption_;
	}

	void setCaption( const String& val );

	String getTooltip() {
		if ( getUseLocaleStrings() ) {
			return System::getCurrentThreadLocale()->translate( tooltip_ );
		}
		return tooltip_;
	}

	void setTooltip( const String& val );

	void setAsSeparator();

	void setPressed( bool val );

	void setItemControl( Control* control );

	Control* getItemControl() {
		return itemControl_;
	}

	bool isEnabled();

	void setEnabled( const bool& val );

	/**
	Utility method - not meant for public use
	*/
	void internal_setBounds( Rect& bounds );

	void setGrouped( const bool& val );

	bool isGrouped();

	void setChecked( const bool& val );

	bool isChecked();

	void update();

	virtual void handleEvent( Event* event );

	
protected:
	Control* control_;
	Control* itemControl_;
	long tag_;
	unsigned long state_;
	Model* model_;
	void* data_;
	long imageIndex_;
	long imageStateIndex_;
	Rect bounds_;
	String caption_;
	String tooltip_;

};





class ToolbarModel;

class APPLICATIONKIT_API ToolbarModelEvent : public ModelEvent {
public:

	ToolbarModelEvent( Object* source, ulong32 type ): ModelEvent(source,type),item_(NULL) {

	}

	ToolbarModel* getToolbarModel() {
		return (ToolbarModel*)getSource();
	}


	ToolbarItem* getItem() {
		return item_;
	}

	void setItem( ToolbarItem* item ) {
		item_ = item;
	}

	ToolbarItem* item_;
};




class APPLICATIONKIT_API ToolbarModel : public AbstractModel {
public:
	ToolbarModel();

	virtual ~ToolbarModel();

	void addItem( ToolbarItem* item );
	void insertItem( ToolbarItem* item, const ulong32& index );
	void removeItem( ToolbarItem* item );


	void itemChanged( const ulong32& eventType, ToolbarItem* item );

	ulong32 getItemIndex( ToolbarItem* item );
	void setItemIndex( ToolbarItem* item, const ulong32& newIndex );

	Enumerator<ToolbarItem*>* getToolbarItems() {
		return itemsContainer_.getEnumerator();
	}
protected:
	std::vector<ToolbarItem*> toolbarItems_;
	EnumeratorContainer<std::vector<ToolbarItem*>,ToolbarItem*> itemsContainer_;
};










#define TOOLBAR_CLASSID		"D8B85915-BCE1-44e3-8FBB-3B43427F99F1"

/**
 *a floating frame that remains top level, has a close button,
 *and a caption height that is shorter than normal.
 */
class APPLICATIONKIT_API Toolbar : public Control {
public:

	Toolbar();

	virtual ~Toolbar();

	ToolbarModel* getToolbarModel() {
		return (ToolbarModel*)getViewModel();
	}	

	ToolbarItem* addToolBarButton( const String& caption ) {
		ToolbarItem* item = new ToolbarItem();
		item->setCaption( caption );
		getToolbarModel()->addItem( item );
		return item;
	}

	void setImageList( ImageList* imageList );

	void setShowButtonCaptions( const bool& val );

	bool getShowButtonCaptions() {
		return showButtonCaptions_;
	}

	Size getButtonSize() {
		return buttonSize_;
	}

	void setButtonSize( const Size& buttonSize );

	void setButtonCaptionsHorizontal( const bool& val );

	bool getButtonCaptionsHorizontal() {
		return buttonCaptionsHorizontal_;
	}

	void setEnableAutoResize( const bool& val );
	bool isAutoResizeEnabled();

	virtual void handleEvent( Event* event );

	virtual void paint( GraphicsContext* context );
protected:
	ToolbarPeer* toolbarPeer_;
	ImageList* imageList_;
	bool showButtonCaptions_;
	bool buttonCaptionsHorizontal_;
	Size buttonSize_;


public:
	/**
	*inner class used by the Toolbar to create a Floating
	*toolbar window when the Toolbar is dragged out of it's dock.
	*/
	class FloatingToolbar : public Window {
	public:
		FloatingToolbar();

		virtual ~FloatingToolbar();
	protected:
	private:
	};

};

};


/**
*CVS Log info
*$Log$
*Revision 1.2  2004/08/07 02:49:10  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.6  2004/07/14 04:56:01  ddiego
*fixed Win32 bugs. Got rid of flicker in the common control
*wrappers and toolbar. tracking down combo box display bugs.
*
*Revision 1.1.2.5  2004/07/11 18:45:34  ddiego
*some toolbar fixes, plus some other minor glithches fixed
*
*Revision 1.1.2.4  2004/07/09 18:48:05  ddiego
*added locale translation support for most classes
*
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.19.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.19  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.18.4.8  2003/12/08 05:05:28  ddiego
*added a bunch more documentation to classes, and added support for new doc
*keywords (@delegates, @del, @delegate, @event, and @eventtype). This
*makes it easier to see at a glance what events a class fires off.
*Added finishing touches for the Action implementation and have a partially
*complete example for this checked in.
*
*Revision 1.18.4.7  2003/12/02 22:11:01  ddiego
*some minor changes to support Actions. Still not done yet.
*
*Revision 1.18.4.6  2003/12/01 03:44:13  ddiego
*added some fixes to the Win32Toolbar impl. A few minor changes to the
*toolbar example (which also got added). Some minor changes to docs
*as well.
*
*Revision 1.18.4.5  2003/10/30 04:23:10  ddiego
*added a toolbar peer so that we have native toolbars (instead of trying
*to implement a half-assed version from scratch)
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
*Revision 1.18  2003/05/17 20:37:04  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.17.2.1  2003/03/12 03:09:46  ddiego
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
*Revision 1.16.14.1  2002/12/25 22:38:00  ddiego
*more stupid fixes to get rid of the damn gcc no newline warning...grrr...
*
*Revision 1.16  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.15.4.1  2002/04/27 15:42:58  ddiego
*removed ApplicationKit.h and optimized header includes as
*well as adding better include guard support
*
*Revision 1.15  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_TOOLBAR_H__


