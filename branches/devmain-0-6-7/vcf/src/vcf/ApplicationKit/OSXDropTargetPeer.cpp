//OSXDropTargetPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXDropTargetPeer.h"

using namespace VCF;

OSXDropTargetPeer::OSXDropTargetPeer():
	dropTarget_(NULL)
{
	
}

OSXDropTargetPeer::~OSXDropTargetPeer()
{
	
}

void OSXDropTargetPeer::registerTarget( Control* control )
{

}

void OSXDropTargetPeer::unregisterTarget( Control* control )
{
	
}

VCF::DropTarget* OSXDropTargetPeer::getDropTarget()
{
	return dropTarget_;
}

void OSXDropTargetPeer::setDropTarget( VCF::DropTarget* dropTarget )
{
	dropTarget_ = dropTarget;
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2005/06/22 03:59:30  ddiego
*added osx stub classes for peers
*
*
*/


