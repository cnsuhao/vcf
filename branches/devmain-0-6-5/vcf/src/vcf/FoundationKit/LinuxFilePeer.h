#ifndef _VCF_LINUXFILEPEER_H__
#define _VCF_LINUXFILEPEER_H__
//LinuxFilePeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


//#include "FilePeer.h"


namespace VCF {

class FRAMEWORK_API LinuxFilePeer : public Object, public FilePeer{

public:

	class FileSearchData {
	public:
		//FileSearchData() {
		//	searchHandle_ = NULL;
		//	memset( &findData_, 0, sizeof( LINUX_FIND_DATA ) );
		//}

		//LINUX_FIND_DATA findData_;
		//HANDLE searchHandle_;
	};

	LinuxFilePeer( File* file, const String& fileName="" );

	virtual ~LinuxFilePeer();

	virtual void setFile( File* file );

	virtual void remove();

	/**
	*creates a new file
	*if the last character in the filename_ is a
	*directory character, then a directory is created
	*instead of a file.
	*/
	virtual void create();


	/**
	*returns the size of the file in bytes
	*/
	virtual uint32 getSize();

	virtual String getName(){
		return filename_;
	};

	virtual void setName( const String& fileName );

	virtual void copyTo( const String& copyFileName );

	virtual bool beginFileSearch( Directory::Finder* finder );

	virtual String findNextFileInSearch( Directory::Finder* finder );

	virtual void endFileSearch( Directory::Finder* finder );
private:
	String filename_;
	int fileHandle_;
	File* file_;
	bool searchStarted_;
	std::vector<String> searchFilters_;
	std::vector<String>::iterator searchFilterIterator_;
	std::map<Directory::Finder*,FileSearchData*> findFileData_;

	void buildSearchFilters( const String& searchFilter );
};

}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:08  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.3.8.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.16.1  2003/03/12 03:10:55  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.4.1  2002/03/26 04:46:10  cesarmello
*Linux headers
*
*Revision 1.1  2002/01/28 02:04:54  cesarmello
*Linux file peer implementation
*
*/


#endif // _VCF_LINUXFILEPEER_H__


