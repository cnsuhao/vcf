#ifndef _VCF_MENUITEM_H__
#define _VCF_MENUITEM_H__
//MenuItem.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */

#ifndef _VCF_MENUITEMEVENT_H__
	#include "vcf/ApplicationKit/MenuItemEvent.h"
#endif //_VCF_MENUITEMEVENT_H__



namespace VCF
{

class MenuItemPeer;

class MenuItemListener;

class Menu;

class AcceleratorKey;

#define MENUITEM_CLASSID		"1E8CBE22-2915-11d4-8E88-00207811CFAB"

/**
\class MenuItem MenuItem.h "vcf/ApplicationKit/MenuItem.h"
*/
class APPLICATIONKIT_API MenuItem : public Item {
public:

	enum MenuItemEvents {		
		miAdded = ItemEvent::Added,
		miRemoved = ItemEvent::Removed,
		miCaptionChanged = ItemEvent::TextChanged,
		miStateChanged = ItemEvent::Changed,
		miImageIndexChanged = 400431,
		miStateImageIndexChanged,
		miIndexChanged,
		miAcceleratorChanged,
		miSelected,
		miSeparatorStateChanged,
		miCheckStateChanged,
		miRadioStateChanged,
		miVisibleStateChanged,
		miEnabledStateChanged,
		miCanPaintStateChanged,
		miItemClicked = MENU_ITEM_EVENT_CLICKED,
		miItemUpdate = MENU_ITEM_EVENT_UPDATED
	};

	enum MenuItemDisplayState{
		mdsChecked = idsChecked,
		mdsUnChecked = idsUnChecked,
		mdsRadioUnpressed = idsRadioUnpressed,
		mdsRadioPressed = idsRadioPressed,
		mdsVisible =		0x0100,
		mdsSelected =		0x0200,
		mdsEnabled =		0x0400,
		mdsRadioItem =		0x0800,
		mdsSeparator =		0x1000,
		mdsHighlighted =	0x2000,
		/**
		This state value indicates that the menu item
		has been bound/associated with a real menu item 
		peer
		*/
		mdsBoundToMenuPeer = 0x01000000
	};

	enum {
		InvalidMenuIndex = (uint32)-1
	};

	MenuItem(){

	};

	virtual ~MenuItem(){};
	
	DELEGATE(MenuItemDelegate,MenuItemClicked);
	DELEGATE(MenuItemDelegate,MenuItemUpdate);



	virtual Enumerator<MenuItem*>* getChildren() = 0;

	virtual void addChild( MenuItem* child ) = 0;

	virtual void insertChild( const uint32& index, MenuItem* child ) = 0;

	virtual void deleteChild( MenuItem* child ) = 0;

	virtual void deleteChild( const uint32& index ) = 0;

	virtual void clearChildren() = 0;

	virtual bool isChecked() = 0;

	virtual void setChecked( const bool& checked ) = 0;

	virtual void setCanPaint( const bool& val ) = 0;

	virtual bool hasParent() const = 0;

	virtual bool hasChildren() const = 0;

	virtual uint32 getChildCount() const = 0;

	virtual uint32 getIndex() const = 0;

	virtual void setIndex( const uint32& index ) = 0;


	/**
	Searches all the children of this menu item for the first child menu item
	whose name \em exactly matches the name parameter. This search is 
	case sensitive.
	@param String the name to match against
	@param bool indicates whether or not the match should be exact. If it's
	true the mactch is exact, if it's false the search is case insensitive. 
	For example, if you were to pass in "foo" for name, and false for exactMatch
	and a menu item had a name of "FooBar" a match would occur.
	@return MenuItem the found menu item. If no item is found, return is NULL.
	*/
	virtual MenuItem* findChildNamed( const String& name, const bool& exactMatch=true ) = 0;
	
	/**
	*returns the owner of the menu item. This generally
	is either a MenuBar or a PopupMenu
	*/
	virtual Menu* getMenuOwner() const = 0;

	/**
	*sets the Owner for the MenuItem and for all it's children as
	*well
	*/
	virtual void setMenuOwner( Menu* menuOwner ) = 0;

	virtual MenuItem* getParent() const = 0;

	virtual void setParent( MenuItem* parent ) = 0;

	virtual MenuItem* getChildAt( const uint32& index ) = 0;

	virtual bool isEnabled() = 0;

	virtual void setEnabled( const bool& enabled ) = 0;

	virtual bool isVisible() const = 0;

	virtual void setVisible( const bool& visible ) = 0;

	virtual bool getRadioItem()  = 0;

	virtual void setRadioItem( const bool& value ) = 0;

	virtual void setCaption( const String& caption ) = 0;

	virtual String getCaption() = 0;

	virtual MenuItemPeer* getPeer() const = 0;

	virtual bool isSeparator()  = 0;

	virtual void setSeparator( const bool& separator ) = 0;

	virtual bool isHighlighted() const = 0;

	virtual void setHighlighted( const bool& val ) = 0;

	virtual void click() = 0;

	virtual void update() = 0;

	/**
	\p
	This sets the accelerator key object for the menu item. If one already exists
	it is removed for this menu item. The accelerator is assigned the 
	key code and modifier mask passed in, and is given a default event handler,
	determined by the implementor.
	\p
	A menu item may have only one accelerator associated with it at any given time.
	*/
	virtual void setAcceleratorKeyInfo( const VirtualKeyCode& keyCode, const uint32& modifierMask ) = 0;

	/**
	Sets the acclerator object for this menu item. If one already exists then it is removed.
	*/
	virtual void setAcceleratorKey( AcceleratorKey* accelerator ) = 0;

	/**
	Returns the accelerator for the menu item.
	*/
	virtual AcceleratorKey* getAccelerator()  = 0;

	virtual uint32 getChildIndex( MenuItem* child ) = 0;	
};

};


#endif // _VCF_MENUITEM_H__

/**
$Id$
*/
