//OSXDesktopPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/OSXDesktopPeer.h"

using namespace VCF;

OSXDesktopPeer::OSXDesktopPeer( Desktop* desktop )
{

}

OSXDesktopPeer::~OSXDesktopPeer()
{

}


void OSXDesktopPeer::desktopBeginPainting( Rect* clippingRect )
{

}

/**
*called after finished painting on the desktop
*allows for native Windowing system cleanup to happen
*/
void OSXDesktopPeer::desktopEndPainting()
{

}

bool OSXDesktopPeer::desktopSupportsVirtualDirectories()
{
	bool result = false;

	return result;
}

bool OSXDesktopPeer::desktopHasFileSystemDirectory()
{
	bool result = true;

	return result;
}

String OSXDesktopPeer::desktopGetDirectory()
{
    String result;
    FSRef desktopFolder;
    if ( noErr == FSFindFolder( kUserDomain, kDesktopFolderType, kDontCreateFolder, &desktopFolder ) ) {
        char tmp[256];
        FSRefMakePath( &desktopFolder, tmp, sizeof(tmp)-1 );
        result = tmp;
    }
    else {

    }

	return result;
}

ulong32 OSXDesktopPeer::desktopGetHandleID()
{
	ulong32 result = 0;


	return result;
}

ulong32 OSXDesktopPeer::desktopGetGraphicsContextHandleID()
{

	return desktopGetHandleID();
}

void OSXDesktopPeer::desktopSetDesktop( Desktop* desktop )
{

}

ulong32 OSXDesktopPeer::desktopGetWidth()
{
	return CGDisplayPixelsWide( CGMainDisplayID() );
}

ulong32 OSXDesktopPeer::desktopGetHeight()
{

	return CGDisplayPixelsHigh( CGMainDisplayID() );
}


VCF::Rect OSXDesktopPeer::desktopGetUsableBounds()
{
	VCF::Rect result;

	result.left_ = 0.0;
	result.top_ = GetMBarHeight();

	result.right_ = desktopGetWidth();
	result.bottom_ = desktopGetHeight();

	return result;
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


