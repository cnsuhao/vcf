#if     _MSC_VER > 1000
#pragma once
#endif

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.4.2.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2004/04/03 15:48:41  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.3.2.1  2004/03/21 20:25:03  marcelloptr
*Scrollable automatically calculates the scroll given the line where to go
*
*Revision 1.3  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.2.20.3  2003/10/13 04:01:50  ddiego
*fixed some issues with calculating the view bounds if scrollbar
*are present as well as adding some functions to get teh bounds of
*left/right and top/bottom spaces that can surround a scrollbar.
*
*Revision 1.2.20.2  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.2.20.1  2003/09/08 05:23:35  ddiego
*additions to scrolling to determine the correct width/height of scroll
*bars
*fixed problem in text model with inserting text
*optimized ListBoxControl, performs much much better now
*
*Revision 1.2  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.1  2002/05/01 01:19:50  ddiego
*added remaining new files from switching stuff around
*like the peer classes and some of the drag drop stuff
*
*Revision 1.3  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//ScrollPeer.h

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

#ifndef _VCF_SCROLLPEER_H__
#define _VCF_SCROLLPEER_H__




namespace VCF  {

class Control;

class Scrollable;

/**
*Class ScrollPeer documentation
*/
class APPKIT_API ScrollPeer : public Interface { 
public:
	virtual ~ScrollPeer(){};

	virtual void scrollTo( const double& xPosition, const double& yPosition ) = 0;

	virtual void getAdjustedPositions( double& xPosition, double& yPosition ) = 0;

	virtual void recalcScrollPositions( Scrollable* scrollable ) = 0;

	virtual Control* getScrollableControl() = 0;

	virtual void setScrollableControl( Control* scrollableControl ) = 0;

	virtual double getHorizontalScrollbarHeight() = 0;

	virtual double getVerticalScrollbarWidth() = 0;

	virtual void getHorizontalScrollRects( Rect* scrollBounds, Rect* leftBounds=NULL, Rect* rightBounds=NULL ) = 0;

	virtual void getVerticalScrollRects( Rect* scrollBounds, Rect* topBounds=NULL, Rect* bottomBounds=NULL ) = 0;
};


}; //end of namespace VCF

#endif // _VCF_SCROLLPEER_H__


