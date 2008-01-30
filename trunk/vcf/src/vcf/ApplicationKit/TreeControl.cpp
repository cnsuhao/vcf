//TreeControl.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/TreeControl.h"
#include "vcf/ApplicationKit/TreePeer.h"
#include "vcf/ApplicationKit/DefaultTreeModel.h"
#include "vcf/ApplicationKit/TreeItem.h"


using namespace VCF;

TreeControl::TreeControl():
	imageList_(NULL),
	stateImageList_(NULL),
	currentSelectedItem_(NULL),
	controlChangeToModel_(false)
{
	treePeer_ = UIToolkit::createTreePeer( this );
	peer_ = dynamic_cast<ControlPeer*>( treePeer_ );

	if ( NULL == treePeer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};

	peer_->create( this );

	init();

	setVisible( true );
}

TreeControl::~TreeControl()
{

}

void TreeControl::init()
{

	/*
	CallBack* tmh =
		new ClassProcedure1<TreeModelEvent*,TreeControl>( this,
												&TreeControl::onTreeRootNodeChanged,
												"TreeControl::onTreeRootNodeChanged" );



	tmh = new ClassProcedure1<TreeModelEvent*,TreeControl>( this,
													&TreeControl::onTreeNodeAdded,
													"TreeControl::onTreeNodeAdded" );

	tmh = new ClassProcedure1<TreeModelEvent*,TreeControl>( this,
													&TreeControl::onTreeNodeDeleted,
													"TreeControl::onTreeNodeDeleted" );

	
*/

	CallBack* mh = new ClassProcedure1<ModelEvent*,TreeControl>( this, &TreeControl::onModelChanged, "TreeControl::onModelChanged" );


	setViewModel( new DefaultTreeModel() );

	addComponent( getViewModel() );

	setBorder( new Basic3DBorder( true ) );

	setColor( GraphicsToolkit::getSystemColor( SYSCOLOR_WINDOW ) );
}

void TreeControl::modelChanged( Model* oldModel, Model* newModel )
{
	TreeModel* tm = (TreeModel*)oldModel;
	if ( NULL != tm ) {
		//ev = (EventHandler*)getCallback( "TreeControl::onTreeRootNodeChanged" );
		//tm->RootNodeChanged -= ev;

		//EventHandler* ev = (EventHandler*)getCallback( "TreeControl::onTreeNodeAdded" );
		//tm->NodeAdded -= ev;

		//ev = (EventHandler*)getCallback( "TreeControl::onTreeNodeDeleted" );
		//tm->NodeRemoved -= ev;

		CallBack* ev = getCallback( "TreeControl::onModelChanged" );
		tm->ModelChanged -= (ModelHandler*)ev;
	}

	tm = (TreeModel*)newModel;

	if ( NULL != tm ) {

		//tml = (EventHandler*)getCallback( "TreeControl::onTreeRootNodeChanged" );
		//tm->RootNodeChanged += tml;

		//EventHandler* tml = (EventHandler*)getCallback( "TreeControl::onTreeNodeAdded" );
		//tm->NodeAdded += tml;

		//tml = (EventHandler*)getCallback( "TreeControl::onTreeNodeDeleted" );
		//tm->NodeRemoved += tml;		

		tm->ModelChanged += getCallback( "TreeControl::onModelChanged" );
	}

}


TreeModel* TreeControl::getTreeModel()
{
	return (TreeModel*) getViewModel();
}

void TreeControl::setTreeModel( TreeModel* tm )
{	
	setViewModel( tm );
}

ImageList* TreeControl::getImageList()
{
	return imageList_;
}

void TreeControl::setImageList( ImageList* imageList )
{
	imageList_ = imageList;
	treePeer_->setImageList( imageList );
}

void TreeControl::paint( GraphicsContext * context )
{
	Rect innerBounds = getClientBounds( false );	

	context->setColor( getColor() );
			
	context->rectangle( &innerBounds );
			
	context->fillPath();
}

/*////MVC
void TreeControl::onTreeRootNodeChanged( TreeModelEvent* event )
{
////MVC	TreeItem* item = event->getTreeItem();
	//treePeer_->addItem( item );
}

void TreeControl::onTreeNodeAdded( TreeModelEvent* event )
{

	
////MVC	TreeItem* item = event->getTreeItem();

	
//	item->setControl( this );

//	treePeer_->addItem( item );
//	CallBack* il = getCallback( "TreeItemListener" );
//	if  ( il == NULL ) {
//		il = new ClassProcedure1<ItemEvent*,TreeControl>( this, &TreeControl::onTreeItemPaint, "TreeItemListener" );
//	}
//	item->ItemPaint += il;

}

void TreeControl::onTreeNodeDeleted( TreeModelEvent* event )
{

	if ( currentSelectedItem_ == event->getTreeItem() ) {
		currentSelectedItem_ = NULL;
	}
	
}
*/


void TreeControl::onModelChanged( ModelEvent* event )
{
	//treePeer_->clear();
	//currentSelectedItem_ = NULL;

	if ( !controlChangeToModel_ ) {
		switch ( event->getType() ) {
			
			case TreeModel::ContentsDeleted : {
				std::map<TreeModel::Key,TreeItem*>::iterator it = itemMap_.begin();
				while ( it != itemMap_.end() ) {
					TreeItem* item = it->second;
					
					removeComponent( item );
					item->free();

					++it;
				}

				itemMap_.clear();
			}
			break;
		}
	}
}

TreeItem* TreeControl::hitTestForItem( Point* pt, TreeItem* item )
{
	TreeItem* result = NULL;
	if ( item->containsPoint( pt ) ) {
		result = item;
	}
	else if ( !item->isLeaf() && item->isExpanded() ){
	/*
		Enumerator<TreeItem*>* children = item->getChildren();
		while ( children->hasMoreElements() ) {
			TreeItem* childItem = children->nextElement();
			result = hitTestForItem( pt, childItem );
			if ( result != NULL ) {
				break;
			}
		}
		*/
	}

	return result;
}

TreeItem* TreeControl::findItem( Point* pt )
{
	TreeItem* result = NULL;
/*////MVC
	Enumerator<TreeItem*>* rootItems = treeModel_->getRootItems();
	while ( true == rootItems->hasMoreElements() ) {
		TreeItem* item = rootItems->nextElement();
		result = hitTestForItem( pt, item );
		if ( NULL != result ) {
			break;
		}
	}
*/
	return result;
}

double TreeControl::getItemIndent()
{
	return treePeer_->getItemIndent();
}

void TreeControl::setItemIndent( const double& indent )
{
	treePeer_->setItemIndent( indent );
}

void TreeControl::onTreeItemPaint( ItemEvent* event )
{
	return ;

	TreeItem* item = (TreeItem*)event->getSource();
	GraphicsContext* context = event->getContext();
	if ( NULL != context ) {
		ImageList* il = getImageList();
		if ( NULL != il ) {
			Rect imgRect = item->getBounds();
			imgRect.left_ += (item->getLevel()+1) * getItemIndent();
			imgRect.right_ = imgRect.left_ + il->getImageWidth();
			context->setColor( GraphicsToolkit::getSystemColor( SYSCOLOR_WINDOW ) );
			context->rectangle( &imgRect );
			context->fillPath();

			if ( stateImageList_ == NULL ) {
				il->draw( context, item->getImageIndex(), &imgRect );
			}
			else {
				if ( true == item->isSelected() ) {
					if ( true == item->isExpanded() ) {
						if ( item->getExpandedImageIndex() >= 0 ) {
							stateImageList_->draw( context, item->getExpandedImageIndex(), &imgRect );
						}
						else if ( item->getSelectedImageIndex() >= 0 ) {
							stateImageList_->draw( context, item->getSelectedImageIndex(), &imgRect );
						}
						else {
							il->draw( context, item->getImageIndex(), &imgRect );
						}
					}
					else {
						if ( item->getSelectedImageIndex() >= 0 ) {
							stateImageList_->draw( context, item->getSelectedImageIndex(), &imgRect );
						}
						else {
							il->draw( context, item->getImageIndex(), &imgRect );
						}
					}
				}
				else {
					if ( true == item->isExpanded() ) {
						if ( item->getExpandedImageIndex() >= 0 ) {
							stateImageList_->draw( context, item->getExpandedImageIndex(), &imgRect );
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
	}
}

void TreeControl::setStateImageList( ImageList* imageList )
{
	stateImageList_ = imageList;
	treePeer_->setStateImageList( imageList );
}

ImageList* TreeControl::getStateImageList()
{
	return stateImageList_;
}

void TreeControl::addItem( TreeItem* parent, TreeItem* item )
{
////MVC	treeModel_->addNodeItem( item, parent );
}

TreeItem* TreeControl::addItem( TreeItem* parent, const String& caption, const uint32 imageIndex )
{
	TreeItem* result = NULL;
	//result = new DefaultTreeItem( caption, this, treeModel_ );
	//result->setImageIndex( imageIndex );
////MVC	treeModel_->addNodeItem( result, parent );
	return result;
}

void TreeControl::removeItem( TreeItem* item )
{
////MVC	treeModel_->deleteNodeItem( item );
}

TreeItem* TreeControl::getSelectedItem()
{
	return currentSelectedItem_;
}

Rect TreeControl::getItemImageRect( TreeItem* item )
{
	return treePeer_->getItemImageRect( item );
}

void TreeControl::handleEvent( Event* event )
{
	Control::handleEvent( event );
	switch ( event->getType() ) {
		case TREEITEM_SELECTED : {
			currentSelectedItem_ = (TreeItem*)event->getUserData();

			ItemSelected( (ItemEvent*)event );
		}
		break;

		case TREEITEM_EXPANDED : {
			ItemExpanded( (ItemEvent*)event );
		}
		break;

		case TreeControl::ITEM_STATECHANGE_REQUESTED : {
			ItemStateChangeRequested( (ItemEvent*)event );
		}
		break;

	}
}

bool TreeControl::getAllowLabelEditing()
{
	return treePeer_->getAllowLabelEditing();
}

void TreeControl::setAllowLabelEditing( const bool& allowLabelEditing )
{
	treePeer_->setAllowLabelEditing( allowLabelEditing );
}

Rect TreeControl::getItemRect( TreeItem* item )
{
	return treePeer_->getItemRect( item );
}

TreeItem* TreeControl::getItemParent( TreeItem* item )
{
	TreeItem* result = NULL;

	TreeModel::Key parent = getTreeModel()->getParent( item->getKey() );
	if ( parent != TreeModel::RootKey ) {
		
	}

	return result;
}

void TreeControl::setItemParent( TreeItem* item, TreeItem* parent )
{

}

void TreeControl::addChildItem( TreeItem* item, TreeItem* child )
{

}

void TreeControl::removeChildItem( TreeItem* item, TreeItem* child )
{

}

TreeItem* TreeControl::getItemFromKey( const TreeModel::Key& key )
{
	TreeItem* result = NULL;

	if ( key != TreeModel::InvalidKey ) {
		std::map<TreeModel::Key,TreeItem*>::iterator found =
			itemMap_.find( key );
		if ( found != itemMap_.end() ) {
			result = found->second;
		}
		else {
			result = new TreeItem();

			itemMap_[key] = result;
		}
	}

	return result;
}

void TreeControl::setItemKey( TreeItem* item, const TreeModel::Key& key )
{
	itemMap_[key] = item;
}

bool TreeControl::getItemChildren( TreeItem* item, std::vector<TreeItem*>& children )
{
	return !children.empty();
}

void TreeControl::insertItemSubItem( TreeItem* item, const uint32& index, TreeSubItem* subItem )
{

}

void TreeControl::removeItemSubItem( TreeItem* item, TreeSubItem* subItem )
{

}

bool TreeControl::getItemSubItems( TreeItem* item, std::vector<TreeSubItem*>& subItems )
{
	return !subItems.empty();
}

TreeSubItem* TreeControl::getItemSubItem( TreeItem* item, const uint32& index )
{
	TreeSubItem* result = NULL;

	return result;
}

uint32 TreeControl::getItemSubItemCount( TreeItem* item )
{
	return 0;
}


/**
$Id$
*/
