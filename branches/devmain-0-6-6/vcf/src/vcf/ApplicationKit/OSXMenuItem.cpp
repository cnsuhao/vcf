//OSXMenuItem.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXMenuItem.h"




using namespace VCF;


uint32 OSXMenuItem::globalMenuItemID = 0;

OSXMenuItem::OSXMenuItem( MenuItem* item ):
	itemID_(0),
	menuItem_(item),
	itemHandle_(NULL)
{
	init();
}

OSXMenuItem::OSXMenuItem():
	itemID_(0),
	menuItem_(NULL),
	itemHandle_(NULL)
{
	init();
}

OSXMenuItem::~OSXMenuItem()
{
	
}

void OSXMenuItem::init()
{
	OSXMenuItem::globalMenuItemID ++;
	itemID_ = OSXMenuItem::globalMenuItemID;
}



void OSXMenuItem::addChild( MenuItem* child )
{
	
}

void OSXMenuItem::insertChild( const unsigned long& index, MenuItem* child )
{
	child->setIndex( index );
	
}

void OSXMenuItem::deleteChild( MenuItem* child )
{
	int index = child->getIndex();

	OSXMenuItem* peer = (OSXMenuItem*)child->getPeer();

}

void OSXMenuItem::deleteChild( const unsigned long& index )
{
	MenuItem* child = menuItem_->getChildAt(index);
	OSXMenuItem* peer = (OSXMenuItem*)child->getPeer();
	
}

void OSXMenuItem::clearChildren()
{
	
}

bool OSXMenuItem::isChecked()
{
	return false;
}

void OSXMenuItem::setChecked( const bool& checked )
{
	
}

bool OSXMenuItem::hasParent()
{
	return false;
}

MenuItem* OSXMenuItem::getParent()
{
	return menuItem_->getParent();
}

MenuItem* OSXMenuItem::getChildAt( const unsigned long& index )
{
	return NULL;
}

bool OSXMenuItem::isEnabled()
{
	
	return false;
}

void OSXMenuItem::setEnabled( const bool& enabled )
{
	if ( true == menuItem_->isSeparator() ){
		return;
	}
	
}

bool OSXMenuItem::isVisible()
{
	return true;
}

void OSXMenuItem::setVisible( const bool& visible )
{
	int index = menuItem_->getIndex();
	if ( true == visible ){

	}
	else {
		//RemoveMenu( itemHandle_, index, MF_BYPOSITION );
	}
}

bool OSXMenuItem::getRadioItem()
{
	return false;
}

void OSXMenuItem::setRadioItem( const bool& value )
{
	if ( true == menuItem_->isSeparator() ){
		return;
	}
	int index = menuItem_->getIndex();

	MenuItem* parent = getParent();
	if ( NULL != parent ){
		Enumerator<MenuItem*>* children = parent->getChildren();
		int count = 0;
		while ( children->hasMoreElements() ) {
			count ++;
			children->nextElement();
		}
		
	}
}

void OSXMenuItem::setMenuItem( MenuItem* item )
{
	menuItem_ = item;
}

void OSXMenuItem::setCaption( const String& caption )
{
	if ( true == menuItem_->isSeparator() ){
		return;
	}
	int index = menuItem_->getIndex();

}

ulong32 OSXMenuItem::getMenuID()
{
	if ( NULL != menuItem_ ){
		Menu* menuOwner = menuItem_->getMenuOwner();
		//find our owner
		if ( NULL == menuOwner ){
			MenuItem* parent = menuItem_->getParent();
			while ( parent != NULL ) {
				menuOwner = parent->getMenuOwner();
				if ( NULL != menuOwner ) {
					break;
				}
				parent = parent->getParent();
			}
		}

		if ( (NULL == itemHandle_) && (NULL != menuOwner)  ){
			PopupMenu* popupOwner = dynamic_cast<PopupMenu*>( menuOwner );
			if ( NULL != popupOwner ){
				//itemHandle_ = ::CreatePopupMenu();
				//We need to create a popup menu - i.e. a context menu!
				
			}
			else {
				MenuBar* menuBarOwner = dynamic_cast<MenuBar*>( menuOwner );
				if ( NULL != menuBarOwner ){
					if ( menuItem_->hasParent() ) {
						MenuItem* parent = menuItem_->getParent();
						OSXMenuItem* peer = (OSXMenuItem*)parent->getPeer();
						MenuRef ref = (MenuRef) peer->getMenuID();
						
						CreateNewMenu( itemID_,0,&itemHandle_);
						SetMenuItemHierarchicalMenu( ref, itemID_, itemHandle_ );
					}
					else {
						
						CreateNewMenu( itemID_,0,&itemHandle_);
					}
				}
				else {
					throw RuntimeException(MAKE_ERROR_MSG("Unknown or Invalid Menu Item owner"), __LINE__);
				}
			}

			if ( NULL == itemHandle_  ){
				throw RuntimeException(MAKE_ERROR_MSG("Error allocation Resources for Menu Item Peer"), __LINE__);
			}
		}
	}
	return (ulong32)itemHandle_;
}


void OSXMenuItem::setAsSeparator( const bool& isSeperator )
{
	int index = menuItem_->getIndex();
	
}






/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/11/10 06:16:40  ddiego
*started adding osx menu code
*
*
*/


