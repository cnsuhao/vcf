//OSXSystemPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <unistd.h>


using namespace VCF;




OSXSystemPeer::OSXSystemPeer()
{
 	::gettimeofday( &time_, &timeZone_ );
}

OSXSystemPeer::~OSXSystemPeer()
{

}

unsigned long OSXSystemPeer::getTickCount()
{

	struct timeval now = {0};
	struct	timezone timeZone;
	::gettimeofday( &now, &timeZone );

	double t1, t2;

	t1 =  (double)(time_.tv_sec * 1000) +
		(double)time_.tv_usec/(1000);

	t2 =  (double)(now.tv_sec * 1000) + (double)now.tv_usec/(1000); //convert to Milliseconds


	unsigned long result = (unsigned long)(t2 - t1);

	return result;
}

void OSXSystemPeer::sleep( const uint32& milliseconds )
{
	if ( 0 == milliseconds ) {
  	return;
	}
	struct timespec req = {0};
	struct timespec rem = {0};
	req.tv_sec = milliseconds / 1000;
	req.tv_nsec = (milliseconds % 1000) * 1000;
	::nanosleep( &req, &rem );
}

bool OSXSystemPeer::doesFileExist( const String& fileName )
{
	bool result = false;

	return result;
}

String OSXSystemPeer::getCurrentWorkingDirectory()
{
	char tmp[PATH_MAX+1];
	getcwd( tmp, PATH_MAX );
	String result = tmp;
	return result;
}

String OSXSystemPeer::getEnvironmentVariable( const String& variableName )
{
	String result;

	const char* env = getenv( variableName.c_str() );
	if ( NULL != env ) {
		result = env;
	}

	return result;
}

void OSXSystemPeer::setCurrentWorkingDirectory( const String& currentDirectory )
{
	chdir( currentDirectory.c_str() );
}

void OSXSystemPeer::setDateToSystemTime( DateTime* date )
{

}

void OSXSystemPeer::setDateToLocalTime( DateTime* date )
{

}

void OSXSystemPeer::setCurrentThreadLocale( Locale* locale )
{

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.4  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.3.2.1  2004/02/21 03:27:09  ddiego
*updates for OSX porting
*
*Revision 1.2  2003/08/09 02:56:46  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.1.2.2  2003/06/23 23:16:55  ddiego
*added some furtther implementation for the osx port
*
*Revision 1.1.2.1  2003/05/22 04:40:05  ddiego
*removed the .cpp files in favor of .mm files to allow Objective-C++ compiling
*
*/


