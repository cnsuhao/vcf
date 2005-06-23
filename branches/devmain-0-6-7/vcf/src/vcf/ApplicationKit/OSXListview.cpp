//OSXListview.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/ListViewControl.h"

#include "vcf/ApplicationKit/OSXControl.h"

#include "vcf/ApplicationKit/OSXListview.h"



using namespace VCF;


OSXListview::OSXListview( ListViewControl* listviewControl ):
	OSXControl( listviewControl ),
	listviewControl_( listviewControl )
{

}

OSXListview::~OSXListview()
{
	
}


void OSXListview::create( Control* owningControl )
{

}



void OSXListview::addItem( ListItem * item )
{

}

void OSXListview::insertItem( const unsigned long& index, ListItem * item )
{

}

void OSXListview::clear()
{
	
}

void OSXListview::deleteItem( ListItem* item )
{
	
}

bool OSXListview::ensureVisible(ListItem * item, bool partialOK )
{
	//LVM_ENSUREVISIBLE
	bool result = false;
	
	return result;
}

void OSXListview::setFocusedItem(ListItem * item)
{
	
}

void OSXListview::selectItem(ListItem * item)
{
	
}

VCF::Rect* OSXListview::getItemRect( ListItem* item )
{
	
	
	return NULL;
}

bool OSXListview::isItemSelected(ListItem* item)
{
	bool result = false;
	
	return result;
}

ListItem* OSXListview::isPtOverItem( Point* point )
{
	ListItem* result = NULL;

	
	return result;
}

ListItem* OSXListview::getFocusedItem()
{
	ListItem* result = NULL;

	
	return result;
}

ListItem* OSXListview::getSelectedItem()
{
	ListItem* result = NULL;

	
	return result;
}

Enumerator<ListItem*>* OSXListview::getSelectedItems()
{
	//int index = ListView_GetSelectionMark( hwnd_ );

	ListItem* item = NULL;
	
	return NULL;
}

void OSXListview::rangeSelect( Rect* selectionRect )
{

}

void OSXListview::addHeaderColumn( const String& columnName, const double& width )
{
	
}

void OSXListview::insertHeaderColumn( const unsigned long& index, const String& columnName, const double& width )
{
	
}

void OSXListview::deleteHeaderColumn( const unsigned long& index )
{
	
}

IconStyleType OSXListview::getIconStyle()
{
	return 0;
}

void OSXListview::setIconStyle( const IconStyleType& iconStyle )
{
	
}

bool OSXListview::getAllowsMultiSelect()
{
	return false;
}

void OSXListview::setAllowsMultiSelect( const bool& allowsMultiSelect )
{
	
}

IconAlignType OSXListview::getIconAlignment()
{
	return 0;
}

void OSXListview::setIconAlignment( const IconAlignType& iconAlignType )
{
	
}

bool OSXListview::getAllowLabelEditing()
{
	return false;
}

void OSXListview::setAllowLabelEditing( const bool& allowLabelEditing )
{
	
}





void OSXListview::setColumnWidth( const unsigned long& index, const double& width, ListViewControl::AutoSizeType type )
{
	
}

double OSXListview::getColumnWidth( const unsigned long& index )
{
	double result = 0.0;
	
	
	
	return result;
}

void OSXListview::setColumnName( const unsigned long& index, const String& columnName )
{
	
}

String OSXListview::getColumnName( const unsigned long& index )
{
	String result;	

	return result;
}


void OSXListview::sort( ItemSort* itemSortFunctor )
{
	
}


void OSXListview::setLargeImageList( ImageList* imageList )
{
	
}

void OSXListview::setSmallImageList( ImageList* imageList )
{
	
}

VCF::Rect OSXListview::getItemImageRect( ListItem* item )
{
	VCF::Rect result;

	return result;
}

long OSXListview::getDisplayOptions()
{
	long result = lvdoDefault;
	

	return result;
}

void OSXListview::setDisplayOptions( const long& displayOptions )
{
	
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2005/06/23 01:26:55  ddiego
*build updates
*
*Revision 1.1.2.1  2005/06/22 03:59:30  ddiego
*added osx stub classes for peers
*
*/


