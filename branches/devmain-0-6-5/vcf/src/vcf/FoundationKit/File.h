#ifndef _VCF_FILE_H__
#define _VCF_FILE_H__
//File.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {


class FilePeer;

/**
*The File class represents a single file or
*directory.
*/
class FRAMEWORK_API File : public Object{

public:

	File( const String& fileName = "");

	virtual ~File();

	/**
	*removes the file from the file system.
	*If the file is a directory then the contents
	*are removed as well
	*/
	void remove();

	/**
	*creates a new file
	*if the last character in the filename is a
	*directory character, then a directory is created
	*instead of a file.
	*/
	void create();


	/**
	*returns the size of the file in bytes
	*returns 0 if the file is a directory
	*/
	uint32 getSize();

	/**
	*returns the name of the file/directory
	*/
	String getName() const;

	/**
	*sets the name of the file object
	*/
	void setName( const String& fileName );

	/**
	*copies the contents of the file to the specified directory
	*/
	void copyTo( const String& copyFileName );

	/**
	*is this File object a directory
	*@return bool true if the object represents a directory, otherwise false.
	*/
	bool isDirectory();

	FilePeer* getPeer() {
		return filePeer_;
	}
protected:
	FilePeer* filePeer_;
};

}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:07  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.10.4.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.9.4.2  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.9.4.1  2003/08/13 19:01:43  marcelloptr
*made File::getName() const
*
*Revision 1.9  2003/05/17 20:37:14  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.22.2  2003/03/23 03:23:52  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.8.22.1  2003/03/12 03:11:43  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_FILE_H__


