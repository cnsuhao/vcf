//File.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;


File::File( const String& fileName, OpenFlags openFlags/*=File::ofNone*/, ShareFlags shareFlags/*=File::shMaskAny*/ )
{
	filePeer_ = NULL;
	fileInputStream_  = NULL;
	fileOutputStream_ = NULL;

	setName( fileName );
}

File::~File()
{
	if ( NULL != filePeer_ ){
		delete filePeer_;
	}
	filePeer_ = NULL;
}

void File::setName( const String& fileName )
{
	// should we do this check ? maybe better not.
	//if ( fileName_ != fileName ) {
	//	return;
	//}

  // or just: fileName_ = fileName ?
	fileName_ = FilePath::transformToOSSpecific( fileName );

	if ( NULL == filePeer_ ) {
		filePeer_ = SystemToolkit::createFilePeer( this );
		if ( NULL == filePeer_ ) {
			throw NoPeerFoundException();
		}
	} else {
		filePeer_->setFile( this );
	}

	resetStats();
}


String File::getOwner()
{
	// gets the owner of the file
	return owner_;
}

void File::updateStat( StatMask statMask/*=File::smStatNone*/ )
{
	filePeer_->updateStat( statMask );
}

void File::setFileAttributes( const File::FileAttributes fileAttributes )
{
	filePeer_->setFileAttributes( fileAttributes );
}

void File::updateTime()
{
	DateTime currentTime = DateTime::now();

	// %%% the time *must* be converted in UTC time now !

	setDateModified ( currentTime );
}

void File::setDateModified( const DateTime& dateModified )
{
	filePeer_->setDateModified( dateModified );
}

/*static*/ bool File::exists( const String& filename )
{
	return System::doesFileExist( filename );
}

void File::create( const String& newFileName )
{
	filePeer_->create();
}

void File::remove()
{
	filePeer_->remove();
}

void File::copyTo( const String& copyFileName )
{
	filePeer_->copyTo( copyFileName );
}

void File::openWithFileName( const String& fileName )
{
}

void File::openWithRights( const String& fileName, OpenFlags openFlags/*=File::ofRead*/, ShareFlags shareFlags/*=File::shMaskAny*/ )
{
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/07/18 14:45:19  ddiego
*integrated Marcello's new File/Directory API changes into both
*the FoundationKit and the ApplicationKit. Many, many thanks go out
*to Marcello for a great job with this. This adds much better file searching
*capabilities, with many options for how to use it and extend it in the
*future.
*
*Revision 1.1.2.2  2004/04/29 04:07:07  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.15  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.14.2.1  2003/08/13 19:01:43  marcelloptr
*made File::getName() const
*
*Revision 1.14  2003/08/09 02:56:46  ddiego
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
*Revision 1.13.2.1  2003/07/24 04:10:45  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.13  2003/05/17 20:37:24  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.12.16.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.12.16.1  2003/03/12 03:12:09  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.12  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.11.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.11  2002/03/18 00:20:44  ddiego
*made changes to foundation kit stuff so that the thread, mutex, semaphore, registry,
*file, filestream, and library class all call the SystemToolkit to create their peer
*instances.
*
*Revision 1.10  2002/01/28 02:09:03  cesarmello
*Linux file peer
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


