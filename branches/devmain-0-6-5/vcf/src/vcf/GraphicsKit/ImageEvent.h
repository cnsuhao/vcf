/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.5.8.1  2004/04/26 21:58:36  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2003/05/17 20:37:07  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.22.4  2003/03/23 06:46:00  marcelloptr
*minor fixes
*
*Revision 1.4.22.3  2003/03/23 03:23:46  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4.22.2  2003/03/13 05:07:25  ddiego
*added some more documentation, and implemented the clone() method in all of the
*core event classes for the FoundationKit, GraphicsKit, and ApplicationKit.
*
*Revision 1.4.22.1  2003/03/12 03:09:54  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.4  2002/01/24 01:46:47  ddiego
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

// ImageEvent.h

#ifndef _VCF_IMAGEEVENT_H__
#define _VCF_IMAGEEVENT_H__


#include "vcf/FoundationKit/Event.h"

#define IMAGE_CONST						200

#define IMAGE_EVENT_HEIGHT_CHANGED		CUSTOM_EVENT_TYPES + IMAGE_CONST + 1
#define IMAGE_EVENT_WIDTH_CHANGED		CUSTOM_EVENT_TYPES + IMAGE_CONST + 2


namespace VCF
{

class ImageEvent : public Event  
{
public:
	ImageEvent( Object* source );
	virtual ~ImageEvent();

	ImageEvent( const ImageEvent& rhs ):Event(rhs) {
		*this = rhs;
	}

	ImageEvent& operator=( const ImageEvent& rhs ) {
		Event::operator =( rhs );
		newWidth_ = rhs.newWidth_;
		newHeight_ = rhs.newHeight_;

		return *this;
	}

	unsigned long getNewWidth();

	void setNewWidth( const unsigned long& newWidth );

	unsigned long getNewHeight();

	void setNewHeight( const unsigned long& newHeight );

	void init();

	virtual Object* clone( bool deep=false ) {
		return new ImageEvent(*this);
	}

private:
	unsigned long newWidth_;
	unsigned long newHeight_;
};


};

#endif // _VCF_IMAGEEVENT_H__


