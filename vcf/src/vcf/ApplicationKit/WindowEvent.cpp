


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

//WindowEvent.cpp
#include "vcf/ApplicationKit/ApplicationKit.h"


using namespace VCF;

WindowEvent::WindowEvent( Object* source ):
	Event( source )
{

}

WindowEvent::WindowEvent( Object* source, const unsigned long& eventType ):
	Event( source, eventType )
{

}

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.8  2004/04/03 15:48:45  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.7.16.2  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*Revision 1.7  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.6.6.1  2002/08/13 04:28:23  ddiego
*bugs fixed:
*[ 585085 ] Can't get at multi selected filenames - this was just a matter of exposing a function that was already available in the
*peer class
*
*features:
*58839 Add a method to query closing a Frame, this required a change that included added a new event (FrameEvent and the corresponding
*FrameEventHandler) and a method, bool Frame::allowClose()
*
*Also made fixes in the VCF Builder to now take advantage of this, so the MainWindow class will now register an event
*handler to handler the FrameClosing event, and attempt to set the current workspace to NULL. If this does not happen then
*the closing event will fail and prevent the widnow from being shutdown. Woo hoo !
*
*Revision 1.6  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.5.4.1  2002/04/08 20:55:30  zzack
*changed include style
*
*Revision 1.5  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/



