//OSXFilePeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/OSXFilePeer.h"

//#include "vcf/FoundationKit/regexx.h"

//#include "MoreFilesX.h"

using namespace VCF;

OSXFilePeer::OSXFilePeer( File* file, const String& fileName )  :
	fileHandle_(0),
	file_(file),
	searchStarted_(false)
{
	
}

OSXFilePeer::~OSXFilePeer()
{
	if ( 0 != fileHandle_ ) {
		//close(fileHandle_);
	}
}

void OSXFilePeer::setFile( File* file )
{
	file_ = file;
}


ulong64 OSXFilePeer::getSize()
{
	ulong64 result ;
	
	return result;
}

void OSXFilePeer::updateStat( File::StatMask = File::smMaskDateAll )
{

}

void OSXFilePeer::setFileAttributes( const File::FileAttributes fileAttributes )
{

}


bool OSXFilePeer::isExecutable()
{
	bool result ;
	
	return result;
}

void OSXFilePeer::setDateModified( const DateTime& dateModified )
{

}

DateTime OSXFilePeer::getDateModified()
{
	DateTime result ;
	
	return result;
}

DateTime OSXFilePeer::getDateCreated()
{   
	DateTime result ;
	
	return result;
}

DateTime OSXFilePeer::getDateAccessed()
{
	DateTime result ;
	
	return result;
}

void OSXFilePeer::open( const String& fileName, File::OpenFlags openFlags, File::ShareFlags shareFlags)
{

}

void OSXFilePeer::close()
{

}

void OSXFilePeer::create( File::OpenFlags openFlags )
{

}

void OSXFilePeer::remove()
{

}

void OSXFilePeer::move( const String& newFileName )
{

}

void OSXFilePeer::copyTo( const String& copyFileName )
{

}

void OSXFilePeer::initFileSearch( Directory::Finder* finder )
{

}

File* OSXFilePeer::findNextFileInSearch( Directory::Finder* finder )
{
	File* result ;
	
	return result;
}

void OSXFilePeer::endFileSearch( Directory::Finder* finder )
{

}
	
	
/*
bool OSXFilePeer::beginFileSearch( Directory::Finder* finder )
{
	bool result = false;
	searchFilters_.clear();
	buildSearchFilters( finder->getSearchFilter() );


	FileSearchData fsData;

	//RegExx::Regexx regex;

	return result;
}

String OSXFilePeer::findNextFileInSearch( Directory::Finder* finder )
{
	return "";
}

void OSXFilePeer::endFileSearch( Directory::Finder* finder )
{
}

void OSXFilePeer::buildSearchFilters( const String& searchFilter )
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

void OSXFilePeer::remove()
{

}

void OSXFilePeer::create()
{
    const char* fName = filename_.ansi_c_str();
    fileHandle_ = fopen( fName, "rb" );
    if ( NULL == fileHandle_ ) {
        //create it
        fileHandle_ = fopen( fName, "w" );
        fclose( fileHandle_ );
        fileHandle_ = fopen( fName, "rb" );
    }

    if ( NULL == fileHandle_ ) {
        throw RuntimeException( MAKE_ERROR_MSG_2("OSXFilePeer::create() failed!") );
    }
}


uint32 OSXFilePeer::getSize()
{

	uint32 result = 0;
	fseek( fileHandle_, 0, SEEK_END );
    result = ftell( fileHandle_ );
    fseek( fileHandle_, 0, SEEK_SET );
	return result;
}


void OSXFilePeer::copyTo( const String& copyFileName )
{

}
*/


/**
*CVS Log info
*$Log$
*Revision 1.1.2.8  2004/07/27 04:26:04  ddiego
*updated devmain-0-6-5 branch with osx changes
*
*Revision 1.1.2.7  2004/06/06 07:05:32  marcelloptr
*changed macros, text reformatting, copyright sections
*
*/


