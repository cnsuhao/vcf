#ifndef _VCF_WIN32FILEPEER_H__
#define _VCF_WIN32FILEPEER_H__
//Win32FilePeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {

class Win32FilePeer : public Object, public FilePeer{

public:

	class FileSearchData {
	public:
		FileSearchData() {
			searchHandle_ = NULL;
		}

		virtual ~FileSearchData(){}
		HANDLE searchHandle_;
	};

	class FileSearchDataA : public FileSearchData {
	public:
		FileSearchDataA() {
			memset( &findData_, 0, sizeof( WIN32_FIND_DATAA ) );
		}

		WIN32_FIND_DATAA findData_;
	};

	class FileSearchDataW : public FileSearchData {
	public:
		FileSearchDataW() {
			memset( &findData_, 0, sizeof( WIN32_FIND_DATAW ) );
		}

		WIN32_FIND_DATAW findData_;
	};



	Win32FilePeer( File* file, const String& fileName="" );

	virtual ~Win32FilePeer();

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
	HANDLE fileHandle_;
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
*Revision 1.1.2.2  2004/04/29 04:07:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.10.4.2  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10.4.1  2004/04/21 02:17:23  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.10  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.9.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.9  2003/05/17 20:37:13  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.16.1  2003/03/12 03:11:19  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.7.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.7  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_WIN32FILEPEER_H__

