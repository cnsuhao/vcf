/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:50  ddiego
*migration towards new directory structure
*
*Revision 1.7  2003/05/17 20:37:51  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.2.1  2003/03/12 03:13:33  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.6  2003/02/26 04:30:57  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.5.14.1  2003/01/08 00:20:04  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.5  2002/05/09 03:10:46  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.4.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.4  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

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
#include "vcf/RemoteObjectKit/RemoteObjectKit.h"


using namespace VCF;
using namespace VCFRemote;
using namespace VCFNet;

InstanceID::InstanceID()
{
	Process thisProcess;
	machineName_ = NetToolkit::getDefaultNetToolkit()->getLocalMachineName();
	processID_ = thisProcess.getID();
	threadID_ = thisProcess.getThreadID();
	memAddress_ = 0;
}

InstanceID::InstanceID( const int& memAddress )
{
	Process thisProcess;
	machineName_ = NetToolkit::getDefaultNetToolkit()->getLocalMachineName();
	processID_ = thisProcess.getID();
	threadID_ = thisProcess.getThreadID();
	memAddress_ = memAddress;
}

InstanceID::InstanceID( const VCF::String& machineName, const int& processID,
					     const int& threadID, const int& memAddress )
{
	this->machineName_ = machineName;
	processID_ = processID;
	threadID_ = threadID;
	memAddress_ = memAddress;
}

void InstanceID::saveToStream( VCF::OutputStream * stream )
{
	stream->write( machineName_ );
	stream->write( processID_ );
	stream->write( threadID_ );
	stream->write( memAddress_ );
}

void InstanceID::loadFromStream( VCF::InputStream * stream )
{
	stream->read( machineName_ );
	stream->read( processID_ );
	stream->read( threadID_ );
	stream->read( memAddress_ );
}


