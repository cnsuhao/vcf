//OSXFileStream.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <errno.h>


using namespace VCF;

OSXFileStream::OSXFileStream( const String& filename, const FileStreamAccessType& accessType ):
fileHandle_(NULL)
{

	filename_ = filename;
	fileHandle_ = fopen( filename_.ansi_c_str(), translateAccessType(accessType).ansi_c_str() ); // TODO: translateAccessType

	if (fileHandle_ < 0)	{
		fileHandle_ = NULL;
		throw FileIOError( CANT_ACCESS_FILE + filename  );
	}
	else {
		fseek( fileHandle_, 0, SEEK_SET );
	}
}

OSXFileStream::~OSXFileStream()
{
	if (fileHandle_ != NULL) {
		fclose( fileHandle_ );
	}
}

void OSXFileStream::seek(const unsigned long& offset, const SeekType& offsetFrom)
{
	int seekType = translateSeekTypeToMoveType( offsetFrom );

	int err = fseek( fileHandle_, offset, seekType );

	if (err < 0 ) {
		int errorCode = errno;
		String errMsg = "Error attempting to seek in stream.\n" + OSXUtils::getErrorString( errorCode );
		throw FileIOError( MAKE_ERROR_MSG_2(errMsg) );
	}
}

unsigned long OSXFileStream::getSize()
{
	unsigned long result = 0;
	int currentPos = ::ftell( fileHandle_ );
	::fseek( fileHandle_, 0, SEEK_END );

	result = ::ftell( fileHandle_ );

	::fseek( fileHandle_, currentPos, SEEK_SET );

	return result;
}

void OSXFileStream::read( char* bytesToRead, unsigned long sizeOfBytes )
{
	int bytesRead = 0;
	int err = fread( bytesToRead, 1, sizeOfBytes, fileHandle_);

	if (err < 0)	{
		// TODO: peer error string
		int errorCode = errno;
		String errMsg = "Error reading data from file stream.\n" + OSXUtils::getErrorString( errorCode );
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

void OSXFileStream::write( const char* bytesToWrite, unsigned long sizeOfBytes )
{
	int bytesWritten = 0;
	int err = ::fwrite( bytesToWrite, 1, sizeOfBytes, fileHandle_ );

	if (err < 0)
	{
		int errorCode = errno;
		String errMsg = CANT_WRITE_TO_FILE + filename_ + "\n" + OSXUtils::getErrorString( errorCode );

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

char* OSXFileStream::getBuffer()
{
	// ???
	return NULL;
}

String OSXFileStream::translateAccessType( const FileStreamAccessType& accessType )
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


int OSXFileStream::translateSeekTypeToMoveType( const SeekType& offsetFrom )
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


/**
*CVS Log info
*$Log$
*Revision 1.1.2.5  2004/06/06 04:56:53  marcelloptr
*added binary friend operators to UnicodeString
*
*/


