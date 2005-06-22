//OSXTree.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXTree.h"
#include "vcf/ApplicationKit/TreeControl.h"
#include "vcf/ApplicationKit/DefaultTreeItem.h"

using namespace VCF;

OSXTree::OSXTree( TreeControl* tree ):
	OSXControl( tree ),
	treeControl_( tree )	
{

}

OSXTree::~OSXTree()
{
	
}

void OSXTree::create( Control* owningControl )
{
		
}


TreeModel* OSXTree::getTreeModel()
{
	return NULL;
}

void OSXTree::setTreeModel( TreeModel* model )
{

}

double OSXTree::getItemIndent()
{
	return 0;
}

void OSXTree::setItemIndent( const double& indent )
{
	
}

ImageList* OSXTree::getImageList()
{
	return NULL;
}

void OSXTree::setImageList( ImageList* imageList )
{

	if ( imageList != NULL ) {
		

		EventHandler* imgListHandler = getEventHandler( "OSXTree::onImageListImageChanged" );
		if ( NULL == imgListHandler ) {
			imgListHandler =
				new ImageListEventHandler<OSXTree>(this, &OSXTree::onImageListImageChanged, "OSXTree::onImageListImageChanged" );

		}
		imageList->SizeChanged.addHandler( imgListHandler );
		imageList->ImageAdded.addHandler( imgListHandler );
		imageList->ImageDeleted.addHandler( imgListHandler );
	}
}


void OSXTree::addItem( TreeItem* item )
{
	
}

void OSXTree::clear()
{
	
}


void OSXTree::onImageListImageChanged( ImageListEvent* event )
{
	ulong32 index = event->getIndexOfImage();
	ImageList* imageList = (ImageList*)event->getSource();
	setImageList( imageList );
}

Rect OSXTree::getItemImageRect( TreeItem* item )
{
	Rect result;

	return result;
}

void OSXTree::onStateImageListImageChanged( ImageListEvent* event )
{
	ImageList* imageList = (ImageList*)event->getSource();
	setStateImageList( imageList );
}

void OSXTree::setStateImageList( ImageList* imageList )
{
	if ( imageList != NULL ) {	
		EventHandler* imgListHandler = getEventHandler( "OSXTree::onStateImageListImageChanged" );
		if ( NULL == imgListHandler ) {
			imgListHandler =
				new ImageListEventHandler<OSXTree>(this, &OSXTree::onStateImageListImageChanged, "OSXTree::onStateImageListImageChanged" );

		}
		imageList->SizeChanged.addHandler( imgListHandler );
		imageList->ImageAdded.addHandler( imgListHandler );
		imageList->ImageDeleted.addHandler( imgListHandler );
	}
}

bool OSXTree::getAllowLabelEditing()
{
	return false;
}

void OSXTree::setAllowLabelEditing( const bool& allowLabelEditing )
{
	
}

void OSXTree::onControlModelChanged( Event* e )
{
	EventHandler* ev = getEventHandler( "OSXTree::onTreeNodeDeleted" );

	if ( NULL == ev ) {
		ev = new TreeModelEventHandler<OSXTree>( this,
													&OSXTree::onTreeNodeDeleted,
													"OSXTree::onTreeNodeDeleted" );
	}
	treeControl_->getTreeModel()->addTreeNodeDeletedHandler( ev );
}

void OSXTree::onTreeNodeDeleted( TreeModelEvent* event )
{
	TreeItem* item = event->getTreeItem();
	if ( NULL != item ){
		
	}
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2005/06/22 03:59:30  ddiego
*added osx stub classes for peers
*
*/


