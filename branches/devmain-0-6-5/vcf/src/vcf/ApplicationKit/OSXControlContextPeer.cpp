//OSXControlContextPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXControl.h"
#include "vcf/ApplicationKit/OSXControlContextPeer.h"


using namespace VCF;

OSXControlContextPeer::OSXControlContextPeer( ControlPeer* controlPeer )
{
	OSXContext::init();
}

OSXControlContextPeer::~OSXControlContextPeer()
{

}


void OSXControlContextPeer::setContext( GraphicsContext* context )
{
	OSXContext::setContext ( context );
	owningControlCtx_  = (ControlGraphicsContext*)( context );
}

Control* OSXControlContextPeer::getOwningControl()
{
	Control* result = NULL;

	if ( NULL != owningControlCtx_ ){
		result = owningControlCtx_->getOwningControl();
	}
	return result;
}

void OSXControlContextPeer::checkHandle()
{
	OSXContext::checkHandle();
}

void OSXControlContextPeer::releaseHandle()
{
	OSXContext::releaseHandle();
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*/


