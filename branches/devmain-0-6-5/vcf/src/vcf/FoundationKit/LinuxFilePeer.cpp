//LinuxFilePeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

using namespace VCF;
using namespace VCFLinux;


LinuxFilePeer::LinuxFilePeer( File* file, const String& fileName )  :
	fileHandle_(0),
	file_(file),
	searchStarted_(false)
{
	setName( fileName );
}

LinuxFilePeer::~LinuxFilePeer()
{
	if ( 0 != fileHandle_ ) {
		close(fileHandle_);
	}
}

void LinuxFilePeer::setFile( File* file )
{
	file_ = file;
}

bool LinuxFilePeer::beginFileSearch( Directory::Finder* finder )
{
   return false;
}

String LinuxFilePeer::findNextFileInSearch( Directory::Finder* finder )
{
	return "";
}

void LinuxFilePeer::endFileSearch( Directory::Finder* finder )
{

}

void LinuxFilePeer::buildSearchFilters( const String& searchFilter )
{
	String tmp = searchFilter;
	int pos = tmp.find( ";" );
	while ( String::npos != pos ) {
		searchFilters_.push_back( tmp.substr( 0, pos ) );
		tmp.erase( 0, pos+1 );
		pos = tmp.find( ";" );
	}

	if ( !tmp.empty() ) {
		searchFilters_.push_back( tmp );
	}
}

void LinuxFilePeer::remove()
{
	int err = ::remove( filename_.ansi_c_str() );
	if ( -1 == err ) {
  	//somethign bad happened
		int errorCode = errno;
		throw BasicFileError ( MAKE_ERROR_MSG_2(LinuxUtils::getErrorString( errorCode )) );
	}
}

void LinuxFilePeer::create()
{
	if (filename_.empty())
		return; // don't try to create or open if the filename is empty

	if (fileHandle_ != 0)
		close(fileHandle_);

	int openFlags = O_CREAT; //O_RDWR |

	fileHandle_ = ::open( filename_.ansi_c_str(), openFlags, 0666 );

	if (fileHandle_ < 0)
	{
		int fileError = fileHandle_;
		fileHandle_ = 0;
		int errorCode = errno;
		throw BasicFileError ( MAKE_ERROR_MSG_2(LinuxUtils::getErrorString( errorCode )) );
	}
}


uint32 LinuxFilePeer::getSize()
{
	uint32 result = 0;

	if (fileHandle_ != 0)
	{
		struct stat buf;
		if ((lstat(filename_.ansi_c_str(), &buf)) < 0)
		{
			result = 0;
			//probably need to throw an exception
		}
		else
		{
			result = buf.st_size;
		}
	}

	return result;
}

void LinuxFilePeer::setName( const String& fileName )
{

	this->filename_ = fileName;

	create();

}

void LinuxFilePeer::copyTo( const String& copyFileName )
{
	//this is the brute force way - there is surely a better way to
	//do this with system calls - I just don't know what they are yet !
  FILE* sourceFile = fopen( filename_.ansi_c_str(), "rb" );
	if ( NULL != sourceFile ) {
  	fseek( sourceFile, 0, SEEK_END );
		int size = ftell( sourceFile );
		fseek( sourceFile, 0, SEEK_SET );
		unsigned char* tmp = new unsigned char[size];
		fread( tmp, 1, size, sourceFile );
		fclose( sourceFile );
		FILE* destFile = fopen( copyFileName.ansi_c_str(), "wb" );
		if ( NULL != destFile ) {
			fwrite( tmp, 1, size, destFile );
			fclose( destFile );
		}
		else {
			throw BasicFileError( MAKE_ERROR_MSG_2( "Unable to create file \"" + copyFileName + "\" and write data to it.") );
		}
	}
	else {
  	throw BasicFileError( MAKE_ERROR_MSG_2("Unable to open source file \"" + filename_ + "\" and read data from it.") );
	}
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/29 04:07:08  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.2  2004/04/28 18:42:26  ddiego
*migrating over changes for unicode strings.
*This contains fixes for the linux port and changes to the Makefiles
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.5  2003/05/17 20:37:33  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.14.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4.14.1  2003/03/12 03:12:18  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.4  2002/05/27 22:52:34  ddiego
*added two new tests for testing File and System support in the FoudnationKit
*and verified that they work in Linux. Fixed associated code in getting that to
*work.
*
*Revision 1.3  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
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
*/


