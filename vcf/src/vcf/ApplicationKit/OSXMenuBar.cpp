//OSXMenuBar.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXMenuBar.h"
#include "vcf/ApplicationKit/MenuItemPeer.h"


using namespace VCF;


OSXMenuBar::OSXMenuBar(  MenuBar* menuBar  )
{
	frame_ = NULL;
	this->menuRoot_ = menuBar->getRootMenuItem();
}

OSXMenuBar::~OSXMenuBar()
{

}

void OSXMenuBar::setFrame( Frame* frame )
{	
	Frame* oldFrame = frame_;
	frame_ = frame;

	if ( (NULL != frame_) && (NULL != menuRoot_) ){		

	}
	else if ( NULL == frame_ && NULL != oldFrame ) {
			
	}
}

void OSXMenuBar::update()
{
	if ( (NULL != frame_) && (NULL != menuRoot_) ){
		ControlPeer* Peer = frame_->getPeer();
		
	}
}

void OSXMenuBar::setMenuItems( MenuItem* item )
{
	menuRoot_ = item;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/11/10 06:16:40  ddiego
*started adding osx menu code
*
*/

