#ifndef _VCF_OSXFILEPEER_H__
#define _VCF_OSXFILEPEER_H__
//OSXFilePeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {

class OSXFilePeer : public Object, public FilePeer{

public:

	class FileSearchData {
	public:

		FileSearchData() {

		}
	};

	OSXFilePeer( File* file, const String& fileName="" );

	virtual ~OSXFilePeer();

	virtual void setFile( File* file );

	virtual void remove();

	virtual void create();

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


	std::map<Directory::Finder*,FileSearchData> searchMap_;

	void buildSearchFilters( const String& searchFilter );
};

}; //end of namespace VCF


/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
 *reformatting of source files: macros and csvlog and copyright sections
 *
 *Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
 *migration towards new directory structure
 *
 *Revision 1.4.2.1  2004/04/26 21:58:42  marcelloptr
 *changes for dir reorganization: _VCF_MACRO_H__
 *
 *Revision 1.4  2004/04/03 15:48:41  ddiego
 *Merged over code from the 0-6-3 branch.
 *
 *Revision 1.3.4.1  2004/02/21 03:27:06  ddiego
 *updates for OSX porting
 *
 *Revision 1.3  2003/08/09 02:56:44  ddiego
 *merge over from the devmain-0-6-1 branch
 *Changes
 *Features:
 *-Added additional implementation to better support the MVC architecture in
 *the VCF
 *
 *-Added a Document/View architecure that is similar to MFC's or NextSteps's
 *Doc/View architectures
 *
 *-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
 *now basic support for it in terms of drawing vector shapes
 *(fills and strokes). Image support will come in the next release
 *
 *-Added several documented graphics tutorials
 *
 *Bugfixes:
 *
 *[ 775744 ] wrong buttons on a dialog
 *[ 585239 ] Painting weirdness in a modal dialog ?
 *[ 585238 ] Modal dialog which makes a modal Dialog
 *[ 509004 ] Opening a modal Dialog causes flicker
 *[ 524878 ] onDropped not called for MLTcontrol
 *
 *Plus an issue with some focus and getting the right popup window to activate
 *has also been fixed
 *
 *Revision 1.2.2.1  2003/06/23 23:16:55  ddiego
 *added some furtther implementation for the osx port
 *
 *Revision 1.2  2003/05/17 20:37:12  ddiego
 *this is the checkin for the 0.6.1 release - represents the merge over from
 *the devmain-0-6-0 branch plus a few minor bug fixes
 *
 *Revision 1.1.2.1  2003/05/15 03:01:01  ddiego
 *added initial osx source( FoundationKit only),
 *plus some fixes to compile under GCC 3.x compilers
 *
 */


#endif // _VCF_OSXFILEPEER_H__


