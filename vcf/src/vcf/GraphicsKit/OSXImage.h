

/**
*Copyright (c) 2000-2004, Jim Crafton
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

// OSXImage.h

#ifndef _VCF_OSXIMAGE_H__
#define _VCF_OSXIMAGE_H__


namespace VCF
{

class OSXImage : public AbstractImage  
{
public:
	OSXImage();	
	
	OSXImage( const unsigned long& width, const unsigned long& height );
	
	OSXImage( GraphicsContext* context, Rect* rect );
	
    virtual ~OSXImage();

	void init();

	virtual void setSize( const unsigned long & width, const unsigned long & height );		

	virtual void beginDrawing();

	virtual void finishedDrawing();	

    CGImageRef getCGImage() {
        return imageRef_;
    }
protected:
    void createBMP();
    GrafPtr grafPort_;
    CGImageRef imageRef_;

};



};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2.2.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.2  2004/02/23 05:51:42  ddiego
*basic GraphicsKit implementation done for OSX
*
*Revision 1.1.2.1  2004/02/21 03:27:06  ddiego
*updates for OSX porting
*
*
*/

#endif // _VCF_OSXIMAGE_H__
