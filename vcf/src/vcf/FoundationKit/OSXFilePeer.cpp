//OSXFilePeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/OSXFilePeer.h"
#include "vcf/FoundationKit/regexx.h"


using namespace VCF;

OSXFilePeer::OSXFilePeer( File* file, const String& fileName )  :
	fileHandle_(0),
	file_(file),
	searchStarted_(false)
{
	setName( fileName );
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

bool OSXFilePeer::beginFileSearch( Directory::Finder* finder )
{
	bool result = false;
	searchFilters_.clear();
	buildSearchFilters( finder->getSearchFilter() );


	FileSearchData fsData;

	RegExx::Regexx regex;

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

}


uint32 OSXFilePeer::getSize()
{

	uint32 result = 0;

	return result;
}

void OSXFilePeer::setName( const String& fileName )
{

	filename_ = fileName;

	create();

}

void OSXFilePeer::copyTo( const String& copyFileName )
{

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


