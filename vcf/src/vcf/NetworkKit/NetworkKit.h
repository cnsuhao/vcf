/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:48  ddiego
*migration towards new directory structure
*
*Revision 1.5.8.1  2004/04/26 21:58:15  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2003/05/17 20:36:59  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.2.1  2003/03/23 03:23:43  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4  2003/02/26 04:30:35  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.3.8.1  2003/01/13 04:57:03  ddiego
*added a fix for the X11COntext::gettextWidth and Height, now returns correct values
*static makefile for the various kits is now ready to use for all
*AbstractX11Controll::keepMouseEvents is now working correctly
*
*Revision 1.3  2002/09/12 03:26:03  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.2.6.1  2002/07/02 05:35:10  marcelloptr
*fixes for vc6, vc7, separated builds, automatic library selection, stlport
*
*Revision 1.2  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.4  2002/04/08 20:55:29  zzack
*changed include style
*
*Revision 1.1.2.3  2002/04/03 19:37:16  zzack
*include style changed
*
*Revision 1.1.2.2  2002/03/25 04:25:42  ddiego
*added some of the BSD license header plus the cvs log stamp to the
*new foundation kit and network global headers
*
*
*/
/**
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

#ifndef _VCF_NETWORKKIT_H__
#define _VCF_NETWORKKIT_H__

#include "vcf/FoundationKit/FoundationKit.h"

#include "vcf/NetworkKit/NetworkKitSelectLib.h"
#include "vcf/NetworkKit/NetToolkit.h"
#include "vcf/NetworkKit/SocketListener.h"
#include "vcf/NetworkKit/SocketEvent.h"
#include "vcf/NetworkKit/Socket.h"
#include "vcf/NetworkKit/SocketPeer.h"
#include "vcf/NetworkKit/SocketListeningLoop.h"
#include "vcf/NetworkKit/DatagramSocket.h"
#include "vcf/NetworkKit/ServerSocketEvent.h"
#include "vcf/NetworkKit/SocketException.h"
#include "vcf/NetworkKit/SocketListeningLoop.h"
#include "vcf/NetworkKit/URL.h"


#endif // _VCF_NETWORKKIT_H__


