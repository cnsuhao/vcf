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

#define OSX_LISTVIEW_CTRL_PRIMARY_COL		'PRIM'

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
	::Rect r;
	r.left = 0;
	r.top = 0;
	r.right = 0;
	r.bottom = 0;
	
	OSStatus err;
	if ( noErr == CreateDataBrowserControl( NULL, &r, kDataBrowserListView, &hiView_ ) ) {
		DataBrowserCallbacks callbacks;
		callbacks.version = kDataBrowserLatestCallbacks;
		err = InitDataBrowserCallbacks( &callbacks ); 	
		callbacks.u.v1.itemDataCallback = OSXListview::DBItemDataCallback;
		callbacks.u.v1.itemNotificationCallback = OSXListview::DBItemNotificationCallback;
		
		err = SetDataBrowserCallbacks( hiView_, &callbacks );
		
		
		//create initial column (DataBrowser doesn't work without at least one column
		DataBrowserListViewColumnDesc col;
		col.propertyDesc.propertyID = OSX_LISTVIEW_CTRL_PRIMARY_COL;
		col.propertyDesc.propertyType =  kDataBrowserTextType;
		col.propertyDesc.propertyFlags =  kDataBrowserListViewSelectionColumn;
		
		col.headerBtnDesc.version = kDataBrowserListViewLatestHeaderDesc;
		col.headerBtnDesc.minimumWidth = 10;
		col.headerBtnDesc.maximumWidth = 200;
		col.headerBtnDesc.titleOffset = 0;
		col.headerBtnDesc.titleString = NULL;
		col.headerBtnDesc.initialOrder = kDataBrowserOrderIncreasing;
		col.headerBtnDesc.btnFontStyle.flags = 0;
		col.headerBtnDesc.btnFontStyle.font = 0;
		col.headerBtnDesc.btnFontStyle.size = 0;
		col.headerBtnDesc.btnFontStyle.style = 0;
		col.headerBtnDesc.btnFontStyle.mode = 0;
		col.headerBtnDesc.btnFontStyle.just = 0;
		
		col.headerBtnDesc.btnContentInfo.contentType = kControlContentTextOnly;
		
		AddDataBrowserListViewColumn( hiView_, &col, 0 );
		
		SetDataBrowserSelectionFlags( hiView_, kDataBrowserSelectOnlyOne | kDataBrowserResetSelection );
		
		
		OSXControl* thisPtr = this;
		SetControlProperty( hiView_, 
							VCF_PROPERTY_CREATOR, 
							VCF_PROPERTY_CONTROL_VAL, 
							sizeof(thisPtr), 
							&thisPtr );
							
		err = OSXControl::installStdControlHandler();
							
		if ( err != noErr ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("InstallEventHandler failed for OSXTree!") );
		}
							
	}
	else {
		throw RuntimeException( MAKE_ERROR_MSG_2("CreateDataBrowserControl failed to create view!") );
	}
}


OSStatus OSXListview::DBItemDataCallback( ControlRef browser, DataBrowserItemID item, 
										DataBrowserPropertyID property, DataBrowserItemDataRef itemData,
										Boolean setValue )
{
	OSStatus err = noErr;
	
	if ( !setValue ) {
		switch ( property ) {

			case OSX_LISTVIEW_CTRL_PRIMARY_COL : {
				ListItem* listItem	 = (ListItem*)item;
				CFTextString tmp;
				tmp = listItem->getCaption();
				SetDataBrowserItemDataText( itemData, tmp );
			}
			break;
			
			case kDataBrowserItemIsSelectableProperty : {
				err = SetDataBrowserItemDataBooleanValue( itemData, true );
			}
			break;
			
			case kDataBrowserItemIsContainerProperty : {
				SetDataBrowserItemDataBooleanValue( itemData, false );				
			}
			break;
			
			default: {
				err = errDataBrowserPropertyNotSupported;				
			}
			break;
		}		
	}
	else {
		err = errDataBrowserPropertyNotSupported;
	}
	
	return err;
}


OSStatus OSXListview::DBItemNotificationCallback( ControlRef browser, DataBrowserItemID itemID, 
															DataBrowserItemNotification message)
{
	OSStatus status = noErr;
    switch (message)
    {
        case kDataBrowserContainerOpened:  {		
              
        }
		break;
		   
		case kDataBrowserItemSelected : {
			SetDataBrowserSelectedItems( browser, 1, &itemID, kDataBrowserItemsAdd );
		}
		break;
		
		case kDataBrowserItemDeselected : {
			SetDataBrowserSelectedItems( browser, 1, &itemID, kDataBrowserItemsRemove );		
		}
		break;
		
    }
    return status;
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
	ListItem* item = NULL;
	
	return NULL;
}

void OSXListview::rangeSelect( Rect* selectionRect )
{

}

void OSXListview::addHeaderColumn( const String& columnName, const double& width )
{
	unsigned int columnCount = 0;
	GetDataBrowserTableViewColumnCount( hiView_, &columnCount );
	
	insertHeaderColumn( columnCount, columnName, width );
}

void OSXListview::insertHeaderColumn( const unsigned long& index, const String& columnName, const double& width )
{
	if ( index == 0 ) {
	
	}
	else {
		DataBrowserListViewColumnDesc col;
		col.propertyDesc.propertyID = 'TEST';
		col.propertyDesc.propertyType =  kDataBrowserTextType;
		col.propertyDesc.propertyFlags =  kDataBrowserListViewSelectionColumn;
		
		col.headerBtnDesc.version = kDataBrowserListViewLatestHeaderDesc;
		col.headerBtnDesc.minimumWidth = 10;
		col.headerBtnDesc.maximumWidth = width;
		col.headerBtnDesc.titleOffset = 0;
		
		CFTextString tmp(columnName);
		
		col.headerBtnDesc.titleString = tmp;
		col.headerBtnDesc.initialOrder = kDataBrowserOrderIncreasing;
		col.headerBtnDesc.btnFontStyle.flags = 0;
		col.headerBtnDesc.btnFontStyle.font = 0;
		col.headerBtnDesc.btnFontStyle.size = 0;
		col.headerBtnDesc.btnFontStyle.style = 0;
		col.headerBtnDesc.btnFontStyle.mode = 0;
		col.headerBtnDesc.btnFontStyle.just = 0;
		
		col.headerBtnDesc.btnContentInfo.contentType = kControlContentTextOnly;
		
		AddDataBrowserListViewColumn( hiView_, &col, index );
	}
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

void OSXListview::addListItems()
{
	ListModel* listModel = listviewControl_->getListModel();
	
	unsigned long count = listModel->getCount();
	int i = 0;
	DataBrowserItemID* dbItems = new DataBrowserItemID[count];
	
	Enumerator<ListItem*>* items = listModel->getItems();
	while ( items->hasMoreElements() ) {
		ListItem* item = items->nextElement();
		dbItems[i] = (DataBrowserItemID)item;
		
		i++;
	}
	
	AddDataBrowserItems( hiView_, kDataBrowserNoItem, count, dbItems, kDataBrowserItemNoProperty );
	
	delete [] dbItems;
}
/**
*CVS Log info
*$Log$
*Revision 1.1.2.4  2005/06/30 02:29:12  ddiego
*more osx work on list view
*
*Revision 1.1.2.3  2005/06/29 03:46:13  ddiego
*more osx tree and list coding.
*
*Revision 1.1.2.2  2005/06/23 01:26:55  ddiego
*build updates
*
*Revision 1.1.2.1  2005/06/22 03:59:30  ddiego
*added osx stub classes for peers
*
*/


