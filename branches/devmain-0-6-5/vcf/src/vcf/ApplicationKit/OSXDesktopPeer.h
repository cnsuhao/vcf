#ifndef _VCF_OSXDESKTOPPEER_H__
#define _VCF_OSXDESKTOPPEER_H__
//OSXDesktopPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


#include "vcf/ApplicationKit/DesktopPeer.h"


namespace VCF {

/**

*/
class OSXDesktopPeer :  public Object, public DesktopPeer {
public:

	OSXDesktopPeer( Desktop* desktop );

	virtual ~OSXDesktopPeer();

	virtual void desktopBeginPainting( Rect* clippingRect );

	virtual void desktopEndPainting();

	virtual bool desktopSupportsVirtualDirectories();

	virtual bool desktopHasFileSystemDirectory();

	virtual String desktopGetDirectory();

	virtual ulong32 desktopGetHandleID();

	virtual ulong32 desktopGetGraphicsContextHandleID();

	virtual void desktopSetDesktop( Desktop* desktop );

	virtual ulong32 desktopGetWidth();

	virtual ulong32 desktopGetHeight();

	virtual Rect desktopGetUsableBounds();
protected:

};



}; //end of namespace VCF;


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:41  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/24 01:42:43  ddiego
*initial OSX ApplicationKit port checkin
*
*/


#endif // _VCF_OSXDESKTOPPEER_H__


