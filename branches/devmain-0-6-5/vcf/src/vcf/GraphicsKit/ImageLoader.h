
#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_IMAGELOADER_H__
#define _VCF_IMAGELOADER_H__



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


//ImageLoader.h


namespace VCF
{

/**
*The ImageLoader interface provides a means to load up images into a generic Bitmap.
*Examples are JPEG ImageLoaders, GIF, BMP, etc ImageLoaders.
*
*@version 1.0
*@author Jim Crafton
*/
/*@interface*/
class GRAPHICSKIT_API ImageLoader {
public:
	virtual ~ImageLoader(){};

	/**
	*loads the image from a file
	*@param String the fully qualified file name that 
	*specifies the image to load
	*/
	virtual Image* loadImageFromFile( const String& fileName )=0;
	
	/**
	*does this ImageLoader support saving the image
	*@return bool returns true if the ImageLoader supports 
	*saving the image, otherwise returns false. If the this 
	*function does return true, then it is safe to call 
	*saveImageToFile()
	*/
	virtual bool canSaveImage() = 0;

	/**
	*Saves the image to file
	*@param String the fully qualified filename that specifies
	*the file to save.
	*@param Image the image object that will be saved
	*/
	virtual void saveImageToFile( const String& fileName, Image* image )=0;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:40  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.14.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.7  2002/09/12 03:26:04  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.6.12.1  2002/08/06 02:57:35  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.6  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

	
#endif // _VCF_IMAGELOADER_H__


