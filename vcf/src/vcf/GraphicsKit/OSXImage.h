#ifndef _VCF_OSXIMAGE_H__
#define _VCF_OSXIMAGE_H__
//OSXImage.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


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
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
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


