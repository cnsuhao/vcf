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
*Revision 1.1.2.4  2004/05/06 02:56:35  ddiego
*checking in OSX updates
*
*Revision 1.1.2.3  2004/04/30 05:44:33  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*/





