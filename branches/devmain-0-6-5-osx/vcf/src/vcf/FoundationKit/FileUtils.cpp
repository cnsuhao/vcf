//FileUtils.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;


FileUtils::FileUtils()
{

}

FileUtils::~FileUtils()
{

}

bool FileUtils::fileExists( const String& fileName )
{
#ifdef WIN32
	return VCFWin32::Win32Utils::fileExists( fileName );
#endif
	return false; //for the moment for other platforms
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:07  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.7  2003/05/17 20:37:24  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.16.1  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.6  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.5.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.5  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


