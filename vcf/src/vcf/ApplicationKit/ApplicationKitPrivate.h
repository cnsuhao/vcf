
#if     _MSC_VER > 1000
#pragma once
#endif



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
//ApplicationKitPrivate.h

#ifndef _VCF_APPLICATIONKITPRIVATE_H__
#define _VCF_APPLICATIONKITPRIVATE_H__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif


#include "vcf/GraphicsKit/GraphicsKitPrivate.h"

/****************/
#ifdef WIN32
//controls & GDI stuff
#include <Commdlg.h>
#	include "vcf/ApplicationKit/Win32Peer.h"
#	include "vcf/ApplicationKit/Win32ToolKit.h"
#	include "vcf/ApplicationKit/Win32Object.h"
#	include "vcf/ApplicationKit/AbstractWin32Component.h"
#elif VCF_X11
	#include <unistd.h>
	#include <sys/time.h>

	//X11 stuff
#	include "vcf/ApplicationKit/X11Peer.h"
#	include "vcf/ApplicationKit/X11UIToolkit.h"
#elif VCF_GTK
	
#	include "vcf/ApplicationKit/GTKUIToolkit.h"
#elif VCF_OSX
	
#	include "vcf/ApplicationKit/OSXUIToolkit.h"
#endif




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:13  ddiego
*migration towards new directory structure
*
*Revision 1.6.2.1  2004/04/26 21:58:15  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.6  2004/04/03 15:48:39  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.5.2.1  2004/02/24 01:42:19  ddiego
*initial OSX ApplicationKit port checkin
*
*Revision 1.5  2003/12/18 05:15:56  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.4.4.2  2003/09/21 04:15:15  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.4.4.1  2003/09/12 00:09:31  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.4  2003/05/17 20:36:58  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.2  2003/04/17 04:29:45  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.3.2.1  2003/03/23 03:23:42  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3  2003/02/26 04:30:35  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.14.5  2003/01/08 00:19:41  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.2.14.4  2003/01/03 05:42:49  ddiego
*added some tune ups to the event loop method in the X11UIToolkit
*added code for closing a window and destroying child peers
*trying to track down why a core dump happens in the ApplicationKit::terminate
*method - seems to be due to bad pointers? Very very annoying....
*
*Revision 1.2.14.3  2002/12/27 06:44:45  ddiego
*added initial control peer for X11 controls
*
*Revision 1.2.14.2  2002/12/26 04:32:11  ddiego
*added basic peer implementation to ApplicationKit so that we can now create
*a VERY simple application and terminate correctly. Woohoo! First steps
*of running on linux!
*
*Revision 1.2.14.1  2002/12/25 22:37:59  ddiego
*more stupid fixes to get rid of the damn gcc no newline warning...grrr...
*
*Revision 1.2  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.2  2002/04/27 15:52:15  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*/

#endif // _VCF_APPLICATIONKITPRIVATE_H__


