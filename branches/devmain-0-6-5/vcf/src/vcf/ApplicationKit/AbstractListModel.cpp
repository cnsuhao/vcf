
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

//AbstractListModel.cpp
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ListItem.h"
#include "vcf/ApplicationKit/AbstractListModel.h"

using namespace VCF;

AbstractListModel::AbstractListModel()
{
	listContainer_.initContainer( listItems_ );
}

AbstractListModel::~AbstractListModel()
{
	std::vector<ListItem*>::iterator it = listItems_.begin();	
	while ( it != listItems_.end() ){		
		delete *it;
		it ++;
	}
	listItems_.clear();
}

void AbstractListModel::addItem( ListItem* item )
{
	this->listItems_.push_back( item );
	item->setIndex( listItems_.size() - 1 );
	ListModelEvent event( this, item );
	ItemAdded.fireEvent( &event );
}

void AbstractListModel::deleteItemAtIndex( const unsigned long& index )
{
	ListItem* item = listItems_[index];
	item->setIndex( index );
	ListModelEvent event( this, item );	
	ItemDeleted.fireEvent( &event );	

	delete item;
	listItems_.erase( listItems_.begin() + index );
}

void AbstractListModel::deleteItem( ListItem* item )
{
	std::vector<ListItem*>::iterator it = std::find( listItems_.begin(), listItems_.end(), item );
	if ( it != listItems_.end() ){	
		
		item->setIndex( listItems_.begin() - it );

		ListModelEvent event( this, item );
		ItemDeleted.fireEvent( &event );		
		delete *it;
		listItems_.erase( it );
	}
}

void AbstractListModel::empty()
{
	std::vector<ListItem*>::iterator it = listItems_.begin();
	ListModelEvent itemEvent( this, LIST_MODEL_ITEM_DELETED );
	while ( it != listItems_.end() ){
		itemEvent.setListItem( *it );
		ItemDeleted.fireEvent( &itemEvent );
		delete *it;
		it ++;
	}
	listItems_.clear();

	ListModelEvent event( this, LIST_MODEL_CONTENTS_DELETED );
	ContentsChanged.fireEvent( &event );
	
	ModelEvent modelEvent( this, Model::MODEL_EMPTIED );
	ModelEmptied.fireEvent( &modelEvent );
}

void AbstractListModel::insertItem( const unsigned long& index, ListItem* item )
{
	listItems_.insert( listItems_.begin() + index, item );
	item->setIndex( index );
	ListModelEvent event( this, item );
	ItemAdded.fireEvent( &event );
}

void AbstractListModel::validate()
{

}

ListItem* AbstractListModel::getItemFromIndex( const unsigned long& index )
{
	ListItem* result = NULL;
	if ( index < listItems_.size() ){
		result = listItems_[index];
	}
	return result;
}

ulong32 AbstractListModel::getItemIndex( ListItem* item )
{
	std::vector<ListItem*>::iterator found = std::find( listItems_.begin(), listItems_.end(), item );
	if ( found != listItems_.end() ) {
		return ( found - listItems_.begin() );
	}
	return 0;
}

Enumerator<ListItem*>* AbstractListModel::getItems()
{
	return listContainer_.getEnumerator();	
}

unsigned long AbstractListModel::getCount()
{
	return this->listItems_.size();
}

void AbstractListModel::saveToStream( OutputStream * stream )
{
	Enumerator<ListItem*>* items = this->getItems();
	long count = this->getCount();
	stream->write( count );
	while ( items->hasMoreElements() ){
		ListItem* item = items->nextElement();
		if ( NULL != item ){
			Persistable* persistableItem = dynamic_cast<Persistable*>(item);
			if ( NULL != persistableItem ){
				stream->write( persistableItem );
			}
			else {
				String caption = item->getCaption();
				stream->write( caption );
			}
		}	
	}
}

void AbstractListModel::loadFromStream( InputStream * stream )
{
	long count = 0;
	stream->read( count );
	for (int i=0;i<count;i++){
		String s = "";
		stream->read( s );
	}
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:13  ddiego
*migration towards new directory structure
*
*Revision 1.16  2004/04/03 15:48:43  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.15.6.2  2004/02/12 14:39:09  marcelloptr
*added member function getItemIndex
*
*Revision 1.15  2003/05/17 20:37:45  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.14.2.2  2003/03/23 03:23:59  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.14.2.1  2003/03/12 03:12:55  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.14  2003/02/26 04:30:53  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.13.14.4  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.13.14.3  2003/01/08 00:19:56  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.13.14.2  2002/12/27 23:04:58  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.13.14.1  2002/12/02 00:38:36  ddiego
*more fixes to get the ApplicationKit to compile under mingw. Everything now
*compiles OK at this point.
*
*Revision 1.13  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.12.4.2  2002/04/27 15:52:38  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.12.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.12  2002/03/01 01:02:53  ddiego
*fixes bug [ 524006 ] TreeListControl crash
*makes some changes to model classes to utilize event types better
*
*Revision 1.11  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


