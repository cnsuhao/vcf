#if     _MSC_VER > 1000
#pragma once
#endif

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.4.1  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.7  2003/05/17 20:37:13  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.22.1  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.6  2002/01/24 01:46:48  ddiego
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

// Win32ResourceStream.h

#ifndef _VCF_WIN32RESOURCESTREAM_H__
#define _VCF_WIN32RESOURCESTREAM_H__



namespace VCF
{

class Win32ResourceStream : public ResourceStreamPeer  
{
public:
	Win32ResourceStream();

	virtual ~Win32ResourceStream();

	virtual void seek(const unsigned long& offset, const SeekType& offsetFrom);	

	virtual void read( char* bytesToRead, unsigned long sizeOfBytes );

};

};
#endif // _VCF_WIN32RESOURCESTREAM_H__


