#if     _MSC_VER > 1000
#pragma once
#endif
// MenuItemPeer.h


#ifndef _VCF_MENUITEMPEER_H__
#define _VCF_MENUITEMPEER_H__


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


namespace VCF
{

class MenuItem;

class APPKIT_API MenuItemPeer  
{
public:
	virtual ~MenuItemPeer(){};

	virtual ulong32 getMenuID() = 0;

	virtual void addChild( MenuItem* child ) = 0;

	virtual void insertChild( const unsigned long& index, MenuItem* child ) = 0;
	
	virtual void deleteChild( MenuItem* child ) = 0;

	virtual void deleteChild( const unsigned long& index ) = 0;

	virtual void clearChildren() = 0;

	virtual bool isChecked() = 0;

	virtual void setChecked( const bool& checked ) = 0;

	virtual MenuItem* getParent() = 0;

	virtual bool hasParent() = 0;

	virtual MenuItem* getChildAt( const unsigned long& index ) = 0;

	virtual bool isEnabled() = 0;

	virtual void setEnabled( const bool& enabled ) = 0;

	virtual bool isVisible() = 0;

	virtual void setVisible( const bool& visible ) = 0;

	virtual bool getRadioItem() = 0;

	virtual void setRadioItem( const bool& value ) = 0;

	virtual void setMenuItem( MenuItem* item ) = 0;

	virtual void setCaption( const String& caption ) = 0;

	virtual void setAsSeparator( const bool& isSeperator ) = 0;
};

};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.7.4.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.7  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.6.4.2  2003/09/21 04:15:35  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.6.4.1  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.6  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.5.22.1  2003/03/23 03:23:49  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.5  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/



#endif // _VCF_MENUITEMPEER_H__


