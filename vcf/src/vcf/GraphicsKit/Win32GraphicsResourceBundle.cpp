/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//Win32GraphicsResourceBundle.cpp
#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"

#include "vcf/FoundationKit/ResourceBundlePeer.h"
#include "vcf/GraphicsKit/GraphicsResourceBundlePeer.h"
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
	Image* result = NULL;

	HBITMAP resBMP = NULL;
	if ( System::isUnicodeEnabled() ) {
		resBMP = (HBITMAP)LoadImageW( getResourceInstance(), resourceName.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION );
	}
	else {
		resBMP = (HBITMAP)LoadImageA( getResourceInstance(), resourceName.ansi_c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION );
	}

	//LoadBitmap( getResourceInstance(), resourceName.c_str() );
	if ( NULL != resBMP ){
		result = new Win32Image( resBMP );
	}
	else {
		//throw exception- resource not found !!!!
	}

	if ( NULL == result ) {
		bool fileExists = false;
		String fileName = System::findResourceDirectory() +	resourceName;
		
		if ( File::exists( fileName ) ) {
			result = GraphicsToolkit::createImage( fileName );
		}
	}


	return result;
}






/**
*CVS Log info
*$Log$
*Revision 1.1.2.4  2004/11/18 06:45:44  ddiego
*updated toolbar btn bug, and added text edit sample.
*
*Revision 1.1.2.3  2004/09/15 04:25:53  ddiego
*fixed some issues that duff had with the examples, plu added the ability to get the platforms version and name and compiler
*
*Revision 1.1.2.2  2004/08/27 03:50:47  ddiego
*finished off therest of the resource refactoring code. We
*can now load in resoruces either from the burned in data in the .exe
*or from resource file following the Apple bundle layout scheme.
*
*/



