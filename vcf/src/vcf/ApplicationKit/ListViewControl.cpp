
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

//ListViewControl.cpp
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ListViewControl.h"
#include "vcf/ApplicationKit/ListviewPeer.h"
#include "vcf/ApplicationKit/DefaultListModel.h"
#include "vcf/ApplicationKit/DefaultListItem.h"
#include "vcf/ApplicationKit/DefaultColumnModel.h"
#include "vcf/ApplicationKit/DefaultColumnItem.h"

using namespace VCF;


ListViewControl::ListViewControl():
	listModel_(NULL),
	selectedItem_(NULL)
{
	listviewPeer_ = UIToolkit::createListViewPeer( this );
	
	peer_ = dynamic_cast<ControlPeer*>(listviewPeer_ );	

	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	peer_->create( this );

	setListModel( new DefaultListModel() );

	

	columnModel_ = new DefaultColumnModel();
	
	EventHandler* cmh = new ColumnModelEventHandler<ListViewControl>( this, &ListViewControl::onColumnItemAdded, "ListViewControl::onColumnItemAdded" );
	columnModel_->addItemAddedHandler( cmh );
	
	cmh = new ColumnModelEventHandler<ListViewControl>( this, &ListViewControl::onColumnItemDeleted, "ListViewControl::onColumnItemDeleted" );
	columnModel_->addItemDeletedHandler( cmh );


	EventHandler* paintHandler = new ItemEventHandler<ListViewControl>( this, &ListViewControl::onItemPaint, "ListViewControl::onItemPaint" );

	ItemSelectionChanged += 
		new ItemEventHandler<ListViewControl>( this, &ListViewControl::onItemSelected, "ListViewControl::onItemSelected" );

	init();
}


ListViewControl::~ListViewControl()
{
	if ( NULL != listModel_ ) {
		listModel_->release();
	}

	if ( NULL != columnModel_ ) {
		columnModel_->release();
	}

	
	
}

void ListViewControl::init()
{
	smallImageList_ = NULL;

	largeImageList_ = NULL;

	stateImageList_ = NULL;

	iconStyle_ = isLargeIcon;

	setColor( GraphicsToolkit::getSystemColor( SYSCOLOR_WINDOW ) );
}

ListModel* ListViewControl::getListModel()
{
	return listModel_;
}

ColumnModel* ListViewControl::getColumnModel()
{
	return columnModel_;
}

void ListViewControl::setListModel(ListModel * model)
{	
	if ( NULL != listModel_ ) {
		listModel_->release();
	}

	listModel_ = model;


	if ( NULL != listModel_ ) {
		listModel_->addRef();
		
		EventHandler* ev = getEventHandler( "ListBoxControl::onItemAdded" );
		if ( NULL == ev ) {
			ev = new ListModelEventHandler<ListViewControl>( this, &ListViewControl::onItemAdded, "ListBoxControl::onItemAdded" );
		}
		
		listModel_->addItemAddedHandler( ev );
		
		ev = getEventHandler( "ListBoxControl::onItemDeleted" );
		if ( NULL == ev ) {
			ev = new ListModelEventHandler<ListViewControl>( this, &ListViewControl::onItemDeleted, "ListBoxControl::onItemDeleted" );
		}

		listModel_->addItemDeletedHandler( ev );
		
		ev = getEventHandler( "ListBoxControl::onListModelContentsChanged" );
		if ( NULL == ev ) {
			ev = new ListModelEventHandler<ListViewControl>( this, &ListViewControl::onListModelContentsChanged, "ListBoxControl::onListModelContentsChanged" );
		}
		
		listModel_->addContentsChangedHandler( ev );
		
	}

	setViewModel( listModel_ );
}

void ListViewControl::onItemPaint( ItemEvent* event )
{
	return;

	ListItem* item = (ListItem*)event->getSource();
	GraphicsContext* context = event->getContext();
	if ( NULL != context ) {
		ImageList* il = NULL;
		
		if (  isLargeIcon == iconStyle_ ) {
			il = getLargeImageList();
		}
		else {
			il = getSmallImageList();
		}
		if ( NULL != il ) {
			Rect imgRect = *(item->getBounds());

			imgRect.left_ = imgRect.left_ + (imgRect.getWidth()/2.0 - il->getImageWidth()/2.0);
			imgRect.right_ = imgRect.left_ + il->getImageWidth();
			imgRect.bottom_ = imgRect.top_ + il->getImageHeight();

			context->setColor( GraphicsToolkit::getSystemColor( SYSCOLOR_WINDOW ) );
			context->rectangle( &imgRect );
			context->fillPath();

			if ( true == item->isSelected() ) {
				if ( NULL != stateImageList_ ) {
					//stateImageList_->draw( context, item->getSelectedImageIndex(), &imgRect );
				}
				else {
					il->draw( context, item->getImageIndex(), &imgRect );
				}	
			}
			else {				
				il->draw( context, item->getImageIndex(), &imgRect );				
			}			
		}
	}
}

void ListViewControl::onListModelContentsChanged( ListModelEvent* event )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	if ( NULL != event ){
		switch ( event->getType() ){
			case LIST_MODEL_CONTENTS_DELETED: {
				listviewPeer_->clear();
			}
			break;

			case LIST_MODEL_ITEM_CHANGED: {
				ListItem* item = event->getListItem();
				if ( NULL != item ){
					listviewPeer_->deleteItem( item );
					listviewPeer_->insertItem( item->getIndex(), item );
				}
			}
			break; 
		}
	}
}

void ListViewControl::onItemAdded( ListModelEvent* event )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	
	EventHandler* paintHandler = this->getEventHandler( "ListViewControl::onItemPaint" );
	ListItem* item = event->getListItem();
	if ( NULL != paintHandler ) {
		item->addItemPaintHandler( paintHandler );
	}

	listviewPeer_->addItem( item );
}

void ListViewControl::onItemDeleted( ListModelEvent* event )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->deleteItem( event->getListItem() );
}

ColumnItem* ListViewControl::addHeaderColumn( const String& columnName, const double& width )
{
	ColumnItem* result = NULL;
	result = new DefaultColumnItem();
	result->setCaption( columnName );
	result->setWidth( width );	
	columnModel_->addItem( result );

	return result;
}

void ListViewControl::addHeaderColumn( ColumnItem* column )
{
	columnModel_->addItem( column );
}

void ListViewControl::insertHeaderColumn( const unsigned long& index, ColumnItem* column )
{
	columnModel_->insertItem( index, column );
}

ColumnItem* ListViewControl::insertHeaderColumn( const unsigned long& index, const String& columnName, const double& width )
{
	ColumnItem* result = NULL;
	result = new DefaultColumnItem();
	result->setCaption( columnName );
	result->setWidth( width );
	columnModel_->insertItem( index, result );

	return result;
}

void ListViewControl::deleteHeaderColumn( const unsigned long& index )
{
	columnModel_->deleteItem( index );
}

String ListViewControl::getColumnName( const unsigned long& index )
{
	ColumnItem* item = columnModel_->getItemFromIndex( index );
	return item->getCaption();
}

void ListViewControl::setColumnName( const unsigned long& index, const String& columnName )
{
	ColumnItem* item = columnModel_->getItemFromIndex( index );
	item->setCaption( columnName );
}

double ListViewControl::getColumnWidth( const unsigned long& index )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	return listviewPeer_->getColumnWidth( index );
}

void ListViewControl::setColumnWidth( const unsigned long& index, const double& width, ListViewControl::AutoSizeType type )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->setColumnWidth( index, width, type );
}

void ListViewControl::setColumnsWidth( const double& width, ListViewControl::AutoSizeType type )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	for ( int i = 0; i < columnModel_->getCount(); ++i ) {
		listviewPeer_->setColumnWidth( i, width, type );
	}
}

IconStyleType ListViewControl::getIconStyle()
{
	//if ( NULL == this->listviewPeer_ ){
	//	throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	//};
	return iconStyle_;// listviewPeer_->getIconStyle();
}

void ListViewControl::setIconStyle( const IconStyleType& iconStyle )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	iconStyle_ = iconStyle;
	listviewPeer_->setIconStyle( iconStyle_ );
}

bool ListViewControl::getAllowsMultiSelect()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	return listviewPeer_->getAllowsMultiSelect();
}

void ListViewControl::setAllowsMultiSelect( const bool& allowsMultiSelect )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->setAllowsMultiSelect( allowsMultiSelect );
}

IconAlignType ListViewControl::getIconAlignment()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	return listviewPeer_->getIconAlignment();
}

void ListViewControl::setIconAlignment( const IconAlignType& iconAlignType )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->setIconAlignment( iconAlignType );
}

bool ListViewControl::getAllowLabelEditing()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	return listviewPeer_->getAllowLabelEditing();
}

void ListViewControl::setAllowLabelEditing( const bool& allowLabelEditing )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->setAllowLabelEditing( allowLabelEditing );
}

void ListViewControl::setItemFocused( ListItem* item )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->setFocusedItem( item );
}

void ListViewControl::onListModelEmptied( ModelEvent* event )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	listviewPeer_->clear();
}

void ListViewControl::onColumnItemAdded( ColumnModelEvent* event )
{
	ColumnItem* item = event->getColumnItem();
	
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->insertHeaderColumn( item->getIndex(), item->getCaption(), item->getWidth() );

	EventHandler* columnItemChanged = getEventHandler( "ListViewControl::onColumnItemChanged" );
	if ( NULL == columnItemChanged ) {
		columnItemChanged = new ItemEventHandler<ListViewControl>( this, 
																	&ListViewControl::onColumnItemChanged, 
																	"ListViewControl::onColumnItemChanged" );
	}

	item->addItemChangedHandler( columnItemChanged );

}

void ListViewControl::onColumnItemDeleted( ColumnModelEvent* event )
{
	ColumnItem* item = event->getColumnItem();

	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	listviewPeer_->deleteHeaderColumn( item->getIndex() );
}

void ListViewControl::onColumnItemChanged( ItemEvent* event )
{
	ColumnItem* item = (ColumnItem*)event->getSource();

	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	unsigned long index = item->getIndex();
	listviewPeer_->setColumnName( index, item->getCaption() );
	listviewPeer_->setColumnWidth( index, item->getWidth() );
}

void ListViewControl::sort( ItemSort* itemSortFunctor )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	listviewPeer_->sort( itemSortFunctor );
}

ListItem* ListViewControl::isPtOverItem(Point* point)
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	
	return listviewPeer_->isPtOverItem( point );
}

ListItem* ListViewControl::getFocusedItem()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	
	return listviewPeer_->getFocusedItem();
}

ListItem* ListViewControl::getSelectedItem()
{
	return this->selectedItem_;// 
}

Enumerator<ListItem*>* ListViewControl::getSelectedItems()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	
	return listviewPeer_->getSelectedItems();
}

void ListViewControl::rangeSelect( Rect* selectionRect )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	
	listviewPeer_->rangeSelect( selectionRect );
}

ListItem* ListViewControl::addItem( const String& caption, const ulong32 imageIndex )
{
	ListItem* result = NULL;

	result  = new DefaultListItem();
	result->setCaption( caption );
	result->setImageIndex( imageIndex );
	listModel_->addItem( result );

	return result;
}

void ListViewControl::addItem( ListItem* item )
{
	listModel_->addItem( item );
}

ListItem* ListViewControl::insertItem( const ulong32& index, const String& caption, const ulong32 imageIndex )
{
	ListItem* result = NULL;

	result  = new DefaultListItem();
	result->setCaption( caption );
	result->setImageIndex( imageIndex );
	listModel_->insertItem( index, result );

	return result;
}

void ListViewControl::insertItem( const ulong32& index, ListItem* item )
{
	listModel_->insertItem( index, item );
}	

void ListViewControl::setSmallImageList( ImageList* imageList )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	smallImageList_ = imageList;

	listviewPeer_->setSmallImageList( smallImageList_ );
}

void ListViewControl::setLargeImageList( ImageList* imageList )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}	
	
	largeImageList_ = imageList;

	listviewPeer_->setLargeImageList( largeImageList_ );
}

void ListViewControl::setStateImageList( ImageList* imageList )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}	

	stateImageList_ = imageList;	
}

Rect ListViewControl::getItemImageRect( ListItem* item )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	return listviewPeer_->getItemImageRect( item );
}

long ListViewControl::getDisplayOptions()
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	return listviewPeer_->getDisplayOptions();
}

void ListViewControl::setDisplayOptions( const long& displayOptions )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	listviewPeer_->setDisplayOptions( displayOptions );
}

void ListViewControl::selectItem( ListItem* item )
{
	if ( NULL == this->listviewPeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}

	listviewPeer_->selectItem( item );
}

void ListViewControl::handleEvent( Event* event )
{
	Control::handleEvent( event );
	switch ( event->getType() ) {
		case ListViewControl::COLUMN_MOUSE_EVENT_CLICK : {
			ColumnItemClicked.fireEvent( (MouseEvent*)event );
		}
		break;
	}
}

void ListViewControl::onItemSelected( ItemEvent* event )
{
	selectedItem_ = listviewPeer_->getSelectedItem();	
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.27.4.1  2004/04/08 21:08:34  ddiego
*little chocolate cupcakes.
*
*Revision 1.27  2003/12/18 05:16:00  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.26.2.3  2003/10/07 21:25:49  ddiego
*minor adj to listview to get selected item correctly
*
*Revision 1.26.2.2  2003/09/09 19:32:03  marcelloptr
*minor changes and autoresizing of listbox columns
*
*Revision 1.26.2.1  2003/09/09 04:22:40  ddiego
*added a readonly method to the text peer interface
*patched in Marcellos changes to the ListViewControl for autosizing
*column headers
*made adjustment to default height calculations in UIMEtricManager impl
*
*Revision 1.26  2003/08/09 02:56:45  ddiego
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
*Revision 1.25.2.4  2003/08/06 21:27:49  ddiego
*minor changes
*
*Revision 1.25.2.3  2003/08/01 00:49:26  ddiego
*added a fix for popup windows that also fixed a problem with the
*ComboBoxControl drop down list disapearing.
*
*Revision 1.25.2.2  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.25.2.1  2003/05/27 04:45:40  ddiego
*doing some code cleanup to fix some bugs in the way dialogs and popups
*work in Win32 port. Cleaned up the ControlPeer and DialogPeer interfaces
*a bit.
*
*Revision 1.25  2003/05/17 20:37:49  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.24.2.3  2003/04/17 04:29:53  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.24.2.2  2003/03/23 03:24:01  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.24.2.1  2003/03/12 03:13:14  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.24  2003/02/26 04:30:56  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.23.2.5  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.23.2.4  2003/01/08 00:20:00  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.23.2.3  2002/12/28 01:56:22  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.23.2.2  2002/12/27 23:05:06  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.23.2.1  2002/12/25 22:06:35  ddiego
*whole bunch of little changes to the header files used by the ApplicationKit
*to get rid of no newline warnings by gcc.
*fixes to various event handlers in the ApplicationKit to compile with gcc
*since gcc does not like a member function pointer without the "&"
*addressof operator.
*Added initial file for the X11 UIToolkit implementation
*
*Revision 1.23  2002/11/18 00:46:10  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.22.10.1  2002/11/16 20:31:35  ddiego
*this fixes the following bugs:
*632802 TextControl's setViewModel not called
*639416 ListViewControl's setViewModel not called
*639417 TreeControl's setViewModel not called
*639418 ListBoxControl's setViewModel not called
*639419 ComboBoxControl's setViewModel not called
*639420 TreeListControl's setViewModel not called
*basically just required that setViewModel() get called. Also made changes to
*the TableControl and teh TabbedPages control
*
*Revision 1.22  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.21.4.2  2002/04/27 15:52:51  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.21.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.21  2002/02/20 04:07:59  ddiego
*consolidated event handling code a bit
*introduced a virtual handleEvent() method to Component
*clean up some of the event constants, so they are now localized in the
*appropriate control classes.
*
*Revision 1.20  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/



