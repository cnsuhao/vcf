

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
#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <dlfcn.h>


using namespace VCF;

LinuxLibraryPeer::LinuxLibraryPeer():
	libHandle_(NULL)
{

}

LinuxLibraryPeer::~LinuxLibraryPeer()
{

}


void LinuxLibraryPeer::load( const String& libraryFilename )
{
	//for now, till we find a better way, we are going
	//do default to Lazy loading - the alternate is
	//have all the symbols of libary resolved at once,
	//which would mean this call would block till that was
	//done
	libHandle_ = ::dlopen( libraryFilename.ansi_c_str(), RTLD_LAZY );
	StringUtils::traceWithArgs( "dlopen( %s ) returned %p\n",
				libraryFilename.c_str(),  libHandle_ );

	if ( NULL == libHandle_ ) {
  	String errMessage = dlerror();
		throw RuntimeException( MAKE_ERROR_MSG_2( errMessage ) );		
	}
}

void* LinuxLibraryPeer::getFunction( const String& functionName )
{
	void* result = NULL;
	if ( NULL == libHandle_ ) {
		throw InvalidPointerException( MAKE_ERROR_MSG_2( "You are trying to get function adress without a valid handle to a library" ) );  	
	}
	result = dlsym( libHandle_, functionName.ansi_c_str() );
	StringUtils::traceWithArgs( "error are: %s\n", dlerror() );
	return result;
}

void LinuxLibraryPeer::unload()
{
	if ( NULL != libHandle_ ) {
  	dlclose( libHandle_ );
	}
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/28 18:42:26  ddiego
*migrating over changes for unicode strings.
*This contains fixes for the linux port and changes to the Makefiles
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.3  2003/05/17 20:37:34  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.14.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.2.14.1  2003/03/12 03:12:18  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/05/28 03:03:15  ddiego
*added another test: FileStreaming to test out the FileStream class in
*linux. Added some changes to the LinuxFileStream class. Also added the
*LinuxLibraryPeer so the Library class now works in linux.
*
*Revision 1.1  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*/


