#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_WINDOWPEER_H__
#define _VCF_WINDOWPEER_H__


/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
*/

namespace VCF{

/** @interface */

class APPKIT_API WindowPeer : public VCF::Interface {
public:
	virtual ~WindowPeer(){};

	virtual Rect getClientBounds() = 0;

	virtual void  setClientBounds( Rect* bounds ) = 0;

	virtual void close() = 0;

	virtual void setFrameStyle( const FrameStyleType& frameStyle ) = 0;

	virtual void setFrameTopmost( const bool& isTopmost ) = 0;

	virtual bool isMaximized() = 0;

	virtual void setMaximized( const bool maximised ) = 0;

	virtual bool isMinimized() = 0;

	virtual void setMinimized( const bool& minimized ) = 0;

	virtual void restore() = 0;

	virtual void setIconImage( Image* icon ) = 0;
};

};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.13.4.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.13  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.12.4.3  2003/09/21 04:15:35  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.12.4.2  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.12.4.1  2003/08/18 19:52:36  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.12  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.11.2.1  2003/03/23 03:23:49  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.11  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.10.20.1  2002/12/25 22:38:00  ddiego
*more stupid fixes to get rid of the damn gcc no newline warning...grrr...
*
*Revision 1.10  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_WINDOWPEER_H__


