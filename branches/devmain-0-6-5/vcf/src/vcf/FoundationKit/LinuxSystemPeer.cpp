
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

// LinuxSystemPeer.cpp

#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <unistd.h>



using namespace VCF;


struct timezone LinuxSystemPeer::timeZone;
struct timeval LinuxSystemPeer::time;

LinuxSystemPeer::LinuxSystemPeer()
{ 	
 	::gettimeofday( &LinuxSystemPeer::time, &LinuxSystemPeer::timeZone );
}

LinuxSystemPeer::~LinuxSystemPeer()
{

}

unsigned long LinuxSystemPeer::getTickCount()
{
	struct timeval now = {0};
	struct	timezone timeZone;
	::gettimeofday( &now, &timeZone );

	double t1, t2;

	t1 =  (double)(LinuxSystemPeer::time.tv_sec * 1000) + 
		(double)LinuxSystemPeer::time.tv_usec/(1000);
	
	t2 =  (double)(now.tv_sec * 1000) + (double)now.tv_usec/(1000); //convert to Milliseconds

	
	unsigned long result = (unsigned long)(t2 - t1);
		
	return result;
}

void LinuxSystemPeer::sleep( const uint32& milliseconds )
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

bool LinuxSystemPeer::doesFileExist( const String& fileName )
{
	return false;
}

String LinuxSystemPeer::getCurrentWorkingDirectory()
{
	char tmp[PATH_MAX+1];
	getcwd( tmp, PATH_MAX );
	String result = tmp;
	return result;
}

String LinuxSystemPeer::getEnvironmentVariable( const String& variableName )
{
	String result;
	
	const char* env = getenv( variableName.ansi_c_str() );
	if ( NULL != env ) {
		result = env;
	}
	
	return result;
}

void LinuxSystemPeer::setCurrentWorkingDirectory( const String& currentDirectory )
{
	chdir( currentDirectory.ansi_c_str() );
}

void LinuxSystemPeer::setDateToSystemTime( DateTime* date )
{

}

void LinuxSystemPeer::setDateToLocalTime( DateTime* date )
{

}

void LinuxSystemPeer::setCurrentThreadLocale( Locale* locale )
{

}

/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/28 18:42:26  ddiego
*migrating over changes for unicode strings.
*This contains fixes for the linux port and changes to the Makefiles
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.6  2004/04/03 15:48:46  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.5.8.1  2004/02/16 05:34:05  ddiego
*updated linux makefiles as a result of new locale support - pushed in stubs for locale peer impl, but no functionality at this point
*
*Revision 1.5  2003/02/26 04:30:49  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.4.2.4  2003/01/08 00:19:52  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.4.2.3  2002/12/27 23:04:51  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.4.2.2  2002/12/23 04:36:32  ddiego
*finished very basic support for fonts - so we can at least draw simple
*text now. Woohoo! and they are anti aliased at that!
*
*Revision 1.4.2.1  2002/12/03 01:15:50  ddiego
*stuff
*
*Revision 1.4  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.3.4.1  2002/09/27 01:54:58  ddiego
*added support for bezier curves - remeber to change over to using teh MgcBeziers in Win32 too
*
*Revision 1.3  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.2.4.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.2  2002/05/27 22:52:34  ddiego
*added two new tests for testing File and System support in the FoudnationKit
*and verified that they work in Linux. Fixed associated code in getting that to
*work.
*
*Revision 1.1  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*/


