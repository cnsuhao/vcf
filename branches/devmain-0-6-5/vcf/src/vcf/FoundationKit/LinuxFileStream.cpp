/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.4  2003/05/17 20:37:33  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.14.3  2003/04/19 22:22:56  ddiego
*tested the code developed in windows using gtk in linux. Seems to work ok except for a
*few minor compiler glitches. Had to comment out the partial specialization for
*floating point image bits in include/graphics/ImageBits.h. Also made some
*adjustments in the makefiles for building the GraphicsKit and ApplicationKit
*from the build/make/Makefile.
*
*Revision 1.3.14.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.14.1  2003/03/12 03:12:18  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2002/05/28 03:03:15  ddiego
*added another test: FileStreaming to test out the FileStream class in
*linux. Added some changes to the LinuxFileStream class. Also added the
*LinuxLibraryPeer so the Library class now works in linux.
*
*Revision 1.2  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.4.1  2002/03/26 04:46:34  cesarmello
*Linux headers
*
*Revision 1.1  2002/01/28 02:07:59  cesarmello
*Linux file peer
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
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

#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <errno.h>


using namespace VCF;
using namespace VCFLinux;

LinuxFileStream::LinuxFileStream( const String& filename, const FileStreamAccessType& accessType ):
	fileHandle_(NULL)
{

	filename_ = filename;
	fileHandle_ = fopen( filename_.c_str(), translateAccessType(accessType).c_str() ); // TODO: translateAccessType
	
	if (fileHandle_ < 0)	{
		fileHandle_ = NULL;
		throw FileIOError( CANT_ACCESS_FILE + filename  );
	}
	else {
  	fseek( fileHandle_, 0, SEEK_SET );
	}
}

LinuxFileStream::~LinuxFileStream()
{
	if (fileHandle_ != NULL) {
		fclose( fileHandle_ );
	} 	
}

void LinuxFileStream::seek(const unsigned long& offset, const SeekType& offsetFrom)
{
	int seekType = translateSeekTypeToMoveType( offsetFrom );
	
	int err = fseek( fileHandle_, offset, seekType );

	if (err < 0 ) {		
		int errorCode = errno;
		String errMsg = "Error attempting to seek in stream.\n" + LinuxUtils::getErrorString( errorCode );
		throw FileIOError( MAKE_ERROR_MSG_2(errMsg) );		
	}
}

unsigned long LinuxFileStream::getSize()
{
	unsigned long result = 0;	
	int currentPos = ::ftell( fileHandle_ );
	::fseek( fileHandle_, 0, SEEK_END );

	result = ::ftell( fileHandle_ );

	::fseek( fileHandle_, currentPos, SEEK_SET );
	
	return result;
}

void LinuxFileStream::read( char* bytesToRead, unsigned long sizeOfBytes )
{
	int bytesRead = 0;
	int err = fread( bytesToRead, 1, sizeOfBytes, fileHandle_);
	
	if (err < 0)	{
		// TODO: peer error string
		int errorCode = errno;
		String errMsg = "Error reading data from file stream.\n" + LinuxUtils::getErrorString( errorCode );
		throw FileIOError( MAKE_ERROR_MSG_2(errMsg) );		
	}
	else
	{
		bytesRead = err;
	}
	
	if ( bytesRead != sizeOfBytes ){ //error if we are not read /writing asynchronously !
		//throw exception ?
	}
}
 
void LinuxFileStream::write( const char* bytesToWrite, unsigned long sizeOfBytes )
{
	int bytesWritten = 0;
	int err = ::fwrite( bytesToWrite, 1, sizeOfBytes, fileHandle_ );
	
	if (err < 0)
	{
		int errorCode = errno;
		String errMsg = CANT_WRITE_TO_FILE + filename_ + "\n" + LinuxUtils::getErrorString( errorCode );
		
		throw FileIOError( MAKE_ERROR_MSG_2(errMsg) );
	}
	else
	{
		bytesWritten = err;
	}
	
	if ( bytesWritten != sizeOfBytes ){//error if we are not read /writing asynchronously !
		//throw exception ?
		//throw FileIOError( CANT_WRITE_TO_FILE + filename_ );
	}
}

char* LinuxFileStream::getBuffer()
{
	// ???
	return NULL;
}

String LinuxFileStream::translateAccessType( const FileStreamAccessType& accessType )
{
	
	String result;
	
	
	switch ( accessType ){
		case fsRead : {
			result = "rb";
		}
		break;

		case fsWrite : {
			result = "wb";
		}
		break;

		case fsReadWrite : case fsDontCare : {
			result = "a+b";
		}
		break;
	}
	
	return result;
}


int LinuxFileStream::translateSeekTypeToMoveType( const SeekType& offsetFrom )
{
	int result = 0;
	
	switch ( offsetFrom ){
		case stSeekFromStart : {
			result = SEEK_SET;
		}
		break;

		case stSeekFromRelative : {
			result = SEEK_CUR;
		}
		break;

		case stSeekFromEnd : {
			result = SEEK_END;
		}
		break;
	}
	return result;
}


