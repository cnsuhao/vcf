#if     _MSC_VER > 1000
#pragma once
#endif


//ControlContainer.h

#ifndef _VCF_CONTROLCONTAINER_H__
#define _VCF_CONTROLCONTAINER_H__

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


/*
#ifndef _CONTAINERS_H__
#include "vcf/ApplicationKit/Containers.h"
#endif
*/

#define CONTROLCONTAINER_CLASSID		"708b26ee-c180-4e73-89f2-f624d5593d8e"


namespace VCF  {

/**
*Class ControlContainer documentation
*/
class APPKIT_API ControlContainer : public VCF::CustomControl, public DelegatedContainer<ControlContainer> { 
public:

	ControlContainer( const bool& heavyWeight=true );	
	virtual ~ControlContainer();	

	void init();

	double getBottomBorderHeight();

	void setBottomBorderHeight( const double& bottomBorderHeight );

	double getTopBorderHeight();

	void setTopBorderHeight( const double& topBorderHeight );

	double getRightBorderWidth();

	void setRightBorderWidth( const double& rightBorderWidth );

	double getLeftBorderWidth();

	void setLeftBorderWidth( const double& leftBorderWidth );

	double getBorderSize();

	void setBorderSize( const double& borderSize );

	virtual void paint( GraphicsContext* context );

protected:
	
};


}; //end of namespace VCF



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:15  ddiego
*migration towards new directory structure
*
*Revision 1.7.4.1  2004/04/26 21:58:18  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.7  2003/12/18 05:15:56  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.6.4.4  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.6.4.3  2003/09/06 19:45:44  ddiego
*changes to ensure that the destroy() is properly called.
*Destructors were moved back to pbulic scope in case that was causing a bug.
*Moving them all(all teh component derived classes) to private scope causes
*a complete failure in hte VC6 compiler. Alas...
*So destructors are present, and modal dialogs can still be created on the
*stack, but almost any other component should be created on the heap, and
*gotten rid of via free() NOT using operator delete directly.
*also moved the vcs info to the end of the file for some of the headers
*This will be an ongoing process.
*
*Revision 1.6.4.2  2003/09/05 21:03:38  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.6.4.1  2003/08/18 19:52:32  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.6  2003/05/17 20:37:02  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.5.22.1  2003/03/12 03:09:26  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.5  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_CONTROLCONTAINER_H__


