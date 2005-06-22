//OSXDragDropPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/OSXDragDropPeer.h"

using namespace VCF;

OSXDragDropPeer::OSXDragDropPeer():
	dragSrc_(NULL),
	dataObj_(NULL),
	actionType_(0)
{
	
}

OSXDragDropPeer::~OSXDragDropPeer()
{
	
}

DragActionType OSXDragDropPeer::startDragDrop( DataObject* cdo )
{

	clipDataObj_ = cdo;

	return actionType_;

}

void OSXDragDropPeer::setActionType( const VCF::DragActionType& actionType )
{
	actionType_ = actionType;
}


void OSXDragDropPeer::setDragSource( VCF::DragSource* dragSource )
{
	dragSrc_ = dragSource;
}




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2005/06/22 03:59:30  ddiego
*added osx stub classes for peers
*
*/


