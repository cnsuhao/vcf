/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:13  ddiego
*migration towards new directory structure
*
*Revision 1.18  2003/08/09 02:56:44  ddiego
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
*Revision 1.17.2.1  2003/08/01 00:49:26  ddiego
*added a fix for popup windows that also fixed a problem with the
*ComboBoxControl drop down list disapearing.
*
*Revision 1.17  2003/05/17 20:37:46  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.16.2.2  2003/03/23 03:23:59  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.16.2.1  2003/03/12 03:12:58  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.16  2003/02/26 04:30:54  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.15.14.2  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.15.14.1  2003/01/08 00:19:57  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.15  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.14.4.2  2002/04/27 15:52:39  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.14.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.14  2002/03/01 01:02:53  ddiego
*fixes bug [ 524006 ] TreeListControl crash
*makes some changes to model classes to utilize event types better
*
*Revision 1.13  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

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

//AbstractTreeModel.cpp
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/AbstractTreeModel.h"


using namespace VCF;

AbstractTreeModel::AbstractTreeModel()
{
	init();	
}

AbstractTreeModel::~AbstractTreeModel()
{
	std::vector<TreeItem*>::iterator it = rootNodes_.begin();
	while ( it != rootNodes_.end() ) {
		TreeItem* rootItem = *it;
		if ( NULL != rootItem ) {
			//rootItem->clearChildren();
			delete rootItem;
		}
		rootItem = NULL;
		it ++;
	}
	rootNodes_.clear();
}

void AbstractTreeModel::init()
{	
	treeItemContainer_.initContainer( rootNodes_ );
}

void AbstractTreeModel::validate()
{

}

void AbstractTreeModel::empty()
{
	std::vector<TreeItem*>::iterator it = rootNodes_.begin();
	while ( it != rootNodes_.end() ) {
		TreeItem* rootItem = *it;
		if ( NULL != rootItem ) {
			rootItem->clearChildren();
			delete rootItem;
		}
		rootItem = NULL;
		it ++;
	}
	rootNodes_.clear();
	ModelEvent event( this, Model::MODEL_EMPTIED );
	ModelEmptied.fireEvent( &event );
}

void AbstractTreeModel::insertNodeItem(TreeItem * node, TreeItem * nodeToInsertAfter)
{
	TreeItem* parent = nodeToInsertAfter->getParent();
	if ( NULL != parent ) {
		parent->insertChild( nodeToInsertAfter->getIndex(), node );
		TreeModelEvent event(this, node, TreeModel::TREEITEM_ADDED );
		NodeAdded.fireEvent( &event );	
	}
	else {
		//bad call throw exception
	}
}

void AbstractTreeModel::deleteNodeItem(TreeItem * nodeToDelete)
{
	TreeItem* parent = nodeToDelete->getParent();

	TreeModelEvent event(this, nodeToDelete, TreeModel::TREEITEM_DELETED );			
	NodeDeleted.fireEvent( &event );	

	if ( NULL != parent ){
		parent->deleteChild( nodeToDelete );
	}
	else {
		std::vector<TreeItem*>::iterator found = std::find( rootNodes_.begin(), rootNodes_.end(), nodeToDelete );
		if ( found != rootNodes_.end() ) {
			TreeItem* item = *found;
			rootNodes_.erase( found );
			delete item;
			item = NULL;
		}
	}	
}

void AbstractTreeModel::addNodeItem( TreeItem * node, TreeItem * nodeParent )
{
	node->setModel( this );
	if ( NULL == nodeParent ){
		rootNodes_.push_back( node );
		TreeModelEvent event(this, node, TreeModel::TREEITEM_ADDED );
		RootNodeChanged.fireEvent( &event );	
	}
	else {
		nodeParent->addChild( node );
	}
	
	TreeModelEvent event(this, node, TreeModel::TREEITEM_ADDED );
	NodeAdded.fireEvent( &event );	
}

void AbstractTreeModel::sort()
{

}

void AbstractTreeModel::onItemPaint( ItemEvent* event )
{

}

void AbstractTreeModel::onItemChanged( ItemEvent* event )
{
	if ( NULL != event ){
		switch ( event->getType() ){
			case ITEM_EVENT_TEXT_CHANGED:{
				
			}
			break;
		}
	}
}

void AbstractTreeModel::onItemSelected( ItemEvent* event )
{

}

void AbstractTreeModel::onItemAdded( ItemEvent* event )
{

}

	
void AbstractTreeModel::onItemDeleted( ItemEvent* event )
{

}

Enumerator<TreeItem*>* AbstractTreeModel::getRootItems()
{
	return treeItemContainer_.getEnumerator();
}


