#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_WIN32PEER_H__
#define _VCF_WIN32PEER_H__

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

//Win32Peer.h
/**
*Main header for implementation object that Win32 headers
*/


/*
these include have now been moved to FrameworkConfig.h
#include <windows.h>
#include <commctrl.h> //make sure to link with comctl32.lib
#include <shlobj.h>
*/



namespace VCFWin32 {

struct KeyboardData {
	int repeatCount;
	int scanCode;
	bool isExtendedKey;
	bool altKeyDown;
	unsigned short character;
	int VKeyCode;
	UINT keyMask;
};

#define KB_CONTEXT_CODE			29
#define KB_PREVIOUS_STATE		30
#define KB_IS_EXTENDED_KEY		24

#define SHIFT_KEY_DOWN \
	((GetKeyState( VK_SHIFT) & 15 ) == 1)

#define VCF_MESSAGE				WM_USER	+ 100
#define VCF_CONTROL_CREATE		VCF_MESSAGE + 1


/**
*what follows are a set of standard utility functions for Win32
*/
class FRAMEWORK_API Win32Utils {

public:
	static unsigned long translateKeyMask( UINT win32KeyMask );

	static unsigned long translateButtonMask( UINT win32ButtonMask );

	static KeyboardData translateKeyData( HWND wndHandle, LPARAM keyData );

	static DWORD translateStyle( unsigned long style );

	static DWORD translateExStyle( unsigned long style );

	static void trace( const VCF::String& text );

	static WORD	getWin32LangID( VCF::Locale* locale );

	static int getXFromLParam( LPARAM lParam );
	
	static int getYFromLParam( LPARAM lParam );

	static VCF::ulong32 translateVKCode( UINT vkCode );

	static bool fileExists( const VCF::String& fileName );

	static VCF::String getErrorString( const DWORD& errorCode );
};


};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.10.4.1  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.9.6.2  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.9.6.1  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.9  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.8.20.1  2003/01/08 00:19:47  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.8  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_WIN32PEER_H__


