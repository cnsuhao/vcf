/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//Win32GraphicsResourceBundle.cpp
#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"
#include "vcf/GraphicsKit/Win32GraphicsResourceBundle.h"


using namespace VCF;



Win32GraphicsResourceBundle::Win32GraphicsResourceBundle()
{

}

Win32GraphicsResourceBundle::~Win32GraphicsResourceBundle()
{

}

Image* Win32GraphicsResourceBundle::getImage( const String& resourceName )
{
	HBITMAP resBMP = NULL;
	if ( System::isUnicodeEnabled() ) {
		resBMP = (HBITMAP)LoadImageW( getResourceInstance(), resourceName.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION );
	}
	else {
		resBMP = (HBITMAP)LoadImageA( getResourceInstance(), resourceName.ansi_c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION );
	}

	//LoadBitmap( getResourceInstance(), resourceName.c_str() );
	if ( NULL != resBMP ){
		return new Win32Image( resBMP );
	}
	else {
		//throw exception- resource not found !!!!
	}
	return NULL;
}






