//Directory.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//Directory.h
#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;


Directory::Finder::Finder( Directory* directoryToSearch, const String& filter )
{
	owningDirectory_ = directoryToSearch;
	searchFilter_ = filter;
	reset();
}

Directory::Finder::~Finder()
{
	FilePeer* dirPeer = owningDirectory_->getPeer();
	if ( NULL != dirPeer ) {
		dirPeer->endFileSearch( this );
	}
}

bool Directory::Finder::hasMoreElements( const bool& backward )
{
	if ( false == searchHasElements_ ) {
		FilePeer* dirPeer = owningDirectory_->getPeer();
		if ( NULL != dirPeer ) {
			dirPeer->endFileSearch( this );
		}
		else {
			//throw exception
		}
	}
	return searchHasElements_;
}

String Directory::Finder::nextElement()
{
	String result;
	FilePeer* dirPeer = owningDirectory_->getPeer();
	if ( NULL != dirPeer ) {
		result = currentElement_;
		currentElement_ = dirPeer->findNextFileInSearch( this );
		searchHasElements_ = !currentElement_.empty();
	}
	else {
		//throw exception
	}

	return result;
}

String Directory::Finder::prevElement()
{
	return nextElement();
}

void Directory::Finder::reset( const bool& backward )
{
	FilePeer* dirPeer = owningDirectory_->getPeer();
	currentElement_ = L"";

	if ( NULL != dirPeer ) {
		searchHasElements_ = dirPeer->beginFileSearch( this );
		if ( searchHasElements_ ) {
			currentElement_ = dirPeer->findNextFileInSearch( this );
		}

		searchHasElements_ = !currentElement_.empty();
	}
	else {
		//throw exception
	}
}


Directory::Directory( const String& fileName ):
	File( "" )
{
	FilePath fp = fileName;
	String tmp = fp.getFileName();
	if ( tmp[tmp.size()-1] != FilePath::getDirectorySeparator()[0] ) {
		tmp += FilePath::getDirectorySeparator();
		fp = tmp;
	}
	setName( fp.transformToOSSpecific() );
}

Directory::~Directory()
{

}

Directory::Finder* Directory::findFiles( const String& filter )
{
	Directory::Finder* result = new Directory::Finder( this, filter );

	return result;
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
*Revision 1.7.2.1  2004/04/21 02:17:26  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.7  2004/04/03 15:48:48  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.6.2.1  2004/03/19 21:25:57  ddiego
*just some minor noodlin
*
*Revision 1.6  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.5.4.3  2003/09/27 14:57:24  marcelloptr
*bugfix [813573] Directory ctor adds one separator too much
*
*Revision 1.5.4.2  2003/08/25 03:46:38  ddiego
*some fixes to some of the stream impls
*
*Revision 1.5.4.1  2003/08/22 04:39:18  ddiego
*minor improvemtn to Diretory constructor, fixed bug in DefaultTableCellItem
*
*Revision 1.5  2003/05/17 20:37:24  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.16.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4.16.1  2003/03/12 03:12:09  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.4  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.3.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.3  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


