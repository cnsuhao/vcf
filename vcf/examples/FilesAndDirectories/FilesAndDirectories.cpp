//FilesAndDirectories.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;



/**
This example will demonstrate using the various file and directory classes for
working with the underlying filesystem.
*/

int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	/**
	use a FilePath object to store the file name
	*/
	FilePath fileName = String("tmp-output.txt");

	/**
	Is this a relative file name?
	If so, let's expand the relative and change it to an
	absolute filename using the current directory as our
	reference point
	*/
	if ( fileName.isRelativePath() ) {
		fileName = fileName.expandRelativePathName( System::getCurrentWorkingDirectory() );
	}


	/**
	Lets look at the various file name components
	*/

	String drive = fileName.getDriveName();
	String directoryPath = fileName.getPathName();
	String name = fileName.getBaseName();
	String extension = fileName.getExtension();
	String nativeOSFilePath = FilePath::transformToOSSpecific( fileName );

	System::println( "The filename %ls has the following components:\n"\
						"\tdrive: %ls\n"\
						"\tdirectoryPath: %ls\n"\
						"\tname: %ls\n"\
						"\textension: %ls\n"\
						"\tnativeOSFilePath: %ls",
						fileName.getFileName().c_str(),
						drive.c_str(),
						directoryPath.c_str(),
						name.c_str(),
						extension.c_str(),
						nativeOSFilePath.c_str() );


	/**
	You can also enumerate the path components
	*/
	std::vector<String> pathComponents = fileName.getPathComponents();
	std::vector<String>::iterator it = pathComponents.begin();
	while ( it != pathComponents.end() ) {
		System::println( *it );
		it ++;
	}



	/**
	Create a file and write some text to it
	*/
	FileOutputStream fs(fileName);
	String text = "here's some text to put in the file";
	fs << text;
	System::println( "FileOutputStream current size: %d", fs.getSize() );
	fs.close();


	{

	/**
	Use the file object to access the file
		*/
		File file( fileName );		
		System::println( "The file %S's size: %d", fileName.getFileName().c_str(), file.getSize() );


		/**
		Make a copy of the file
		*/
		file.copyTo( fileName.getPathName(true) +
			FilePath::getDirectorySeparator() +
			fileName.getBaseName() + "-copy" + fileName.getExtension() );

	}



	{
	/**
	Enumerate all files ending with a .txt extension
		*/
		
		Directory dir( fileName.getPathName(true) );
		
		FileSearchFilterStandard filter( L"*.cpp" );
		
		Directory::Finder* finder = dir.findFiles( "*.txt" );
		
		if ( NULL != finder ) {
			finder->setDisplayMode( Directory::Finder::dmFiles );
			
			File* foundFile = finder->nextElement();
			while ( NULL != foundFile) {
				fileName = foundFile->getName();
				
				System::println( fileName );			
				
				try {
					if ( !foundFile->isDirectory() ) {
						foundFile->remove();
					}
				}
				catch ( BasicException& e ) {
					System::errorPrint( &e );
				}
				
				foundFile = finder->nextElement();
			}
			finder->free();
		}
	}



	/**
	File chaining -
	*/

	{
		FileOutputStream textFile( "text-file.txt" );
		TextOutputStream tos(&textFile);

		tos.write( 100 );
		tos.write( 200 );
		tos.write( true );
		tos.write( 12.433 );
		tos.write( String("Hello World") );

		textFile.close();

		int i1;
		int i2;
		bool b1;
		double d1;
		String s;

		FileInputStream fis( "text-file.txt" );
		TextInputStream tis(&fis);
		tis.read( i1 );
		tis.read( i2 );
		tis.read( b1 );
		tis.read( d1 );
		tis.read( s );


	}

	FoundationKit::terminate();
	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.2.4.6  2004/07/19 04:08:52  ddiego
*more files and directories integration. Added Marcello's Directories example as well
*
*Revision 1.2.4.5  2004/05/03 03:44:52  ddiego
*This checks in a bunch of changes to the FoundationKit for OSX
*porting. The thread, mutex, semaphor, condition, and file peers
*have all been implemented and tested. The file peer could be improved
*and needs search functionality. The locale peer is only partially
*complete, but the functions will return values. The unicode transition
*is also finished and works OK now.
*
*Revision 1.2.4.4  2004/04/29 03:40:53  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


