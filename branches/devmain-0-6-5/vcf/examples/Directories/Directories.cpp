//Directories.cpp

#include "vcf/FoundationKit/FoundationKit.h"
//#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;






Directory::Finder::DisplayMode g_displayMode = Directory::Finder::dmAny;
Directory::Finder::DisplayMode g_displayOrder = Directory::Finder::dmAny;

bool g_showFilenames = false;
bool g_showDirnames = false;
bool g_testingFileAttributes = false;
bool g_testingTimeStamps = false;


class FinderTest {
public:
	virtual void loopTest(  const String& filepath, const bool& recurse = false ) {
		return;
	}

public:
	int countFiles_;
	int countDirectories_;
};



class FinderTest1 : public FinderTest {
public:
	virtual void loopTest(  const String& filepath, const bool& recurse = false ) {
		loop(  filepath, recurse, true );
	}

	void loop( const String& filepath, const bool& recurse = false, const bool& start = true ) {
		if ( start ) {
			countFiles_ = 0;
			countDirectories_   = 0;
		}

		String filename, path;
		File* file = NULL;

		Directory dir( FilePath::getExpandedRelativePathName( filepath ) );

		Directory::Finder* finder = dir.findFiles();

		while ( finder->nextElement() ) {
			file = finder->getCurrentElement();

			filename = file->getName();
			path = filepath + filename;

			if ( file->isDirectory() ) {
				VCF_ASSERT( !( filename == L"." || filename == L".." ) );

				countDirectories_ ++;
				if ( g_showDirnames ) printf ( "[%s]\n", path.ansi_c_str() );
				if ( recurse ) {
					this->loop( path + L"/", recurse, false );
				}
			} else {
				countFiles_ ++;
				if ( g_showFilenames ) printf ( "%s\n", path.ansi_c_str() );
			}
		}
		finder->free();

	}

};



FileSearchFilterStandard filterFilesObj2( L"*.h" );

class FinderTest2 : public FinderTest {
public:
	virtual void loopTest(  const String& filepath, const bool& recurse = false ) {
		loop(  filepath, recurse, true );
	}

	void loop( const String& filepath, const bool& recurse = false, const bool& start = true ) {
		if ( start ) {
			countFiles_ = 0;
			countDirectories_   = 0;
		}

		String filename, path;

		File* file = NULL;

		Directory dir( FilePath::getExpandedRelativePathName( filepath ) );

		Directory::Finder* finder = dir.findFiles( &filterFilesObj2 );
		finder->setStatMask( File::smAttributes );
		while ( finder->nextElement() ) {
			file = finder->getCurrentElement();
			filename = file->getName();
			path = filepath + filename;

			if ( file->isDirectory() ) {
				VCF_ASSERT( !( filename == L"." || filename == L".." ) );

				countDirectories_ ++;
				if ( g_showDirnames ) printf ( "[%s]\n", path.ansi_c_str() );
				if ( recurse ) {
					this->loop( path + L"/", recurse, false );
				}
			} else {
				countFiles_ ++;
				if ( g_showFilenames ) printf ( "%s\n", path.ansi_c_str() );
			}
		}
		finder->free();
	}

};



class FinderTest3 : public FinderTest {
public:
	virtual void loopTest(  const String& filepath, const bool& recurse = false ) {

		countFiles_ = 0;
		countDirectories_   = 0;

		String filename;

		File* file = NULL;
		DateTime dt;

		Directory dir( FilePath::getExpandedRelativePathName( filepath ) );

		FileSearchFilterStandard filterFilesObj3( L"*.cpp"/*, L"c/g"*/ );

		Directory::Finder* finder = dir.findFiles( &filterFilesObj3, false );
		finder->setDisplayMode( g_displayMode ); //Directory::Finder::dmAny );
		finder->setDisplayOrder( g_displayOrder ); //Directory::Finder::dmFiles );
		finder->setKeepOSSpecificFormat( true );
		finder->setMaskFilterFileAttribs ( File::faMaskAll );
		finder->ignoreStat( File::smMaskDateAll | File::smSize );
		finder->setRecursion( recurse, 10 );

		while ( finder->nextElement() ) {
			file = finder->getCurrentElement();
			filename = file->getName();

			if ( file->isDirectory() ) {
				VCF_ASSERT( !( filename == L"." || filename == L".." ) );

				countDirectories_ ++;
				dt = System::convertUTCTimeToLocalTime( file->getDateModified() );
				String st = StringUtils::format( dt, L"%d/%m/%Y %H:%M:%S" );
				//String st = StringUtils::format( L"%s", L"%d/%m/%Y %H:%M:%S" );
				if ( g_showDirnames ) printf ( "[%d] %s %10s %5s [%s]\n", finder->getRecursionLevel(), st.ansi_c_str(), "", "", filename.ansi_c_str() );
				StringUtils::traceWithArgs( L"[%d] %s %10s %5s [%s]\n", finder->getRecursionLevel(), st.c_str(), L"", L"", filename.c_str() );
			} 
			else {
				countFiles_ ++;
				String sz = StringUtils::toString( file->getSize() );
				String sz2 = StringUtils::toString( file->getPeer()->getSize() );
				
				dt = System::convertUTCTimeToLocalTime( file->getDateModified() );

				String st = StringUtils::format( dt, L"%d/%m/%Y %H:%M:%S" );
				String sa = StringUtils::format( "%c%c%c%c%c", file->isArchive()?'a':' ', file->isReadOnly()?'r':' ', 
																					file->isHidden()?'h':' ', file->isSystem()?'s':' ', file->isExecutable()?'x':' ' );
				if ( g_showFilenames ) printf ( "[%d] %s %10s %s  %s\n", finder->getRecursionLevel(), st.ansi_c_str(), sz.ansi_c_str(), sa.ansi_c_str(), filename.ansi_c_str() );
				StringUtils::traceWithArgs( L"[%d] %s %10s %s  %s\n", finder->getRecursionLevel(), st.c_str(), sz.c_str(), sa.c_str(), filename.c_str() );

				// setting file attributes
				if ( g_testingFileAttributes ) {
					File::FileAttributes fa = file->getFileAttributes();
					file->setFileAttributes( (File::FileAttributes) ( fa | File::faReadOnly ) );
					fa = file->getFileAttributes();
					sa = StringUtils::format( "%c%c%c%c%c", file->isArchive()?'a':' ', file->isReadOnly()?'r':' ', 
																						file->isHidden()?'h':' ', file->isSystem()?'s':' ', file->isExecutable()?'x':' ' );
					StringUtils::traceWithArgs( L"[%d]*%s %10s %s  %s\n", finder->getRecursionLevel(), st.c_str(), sz.c_str(), sa.c_str(), filename.c_str() );
				}

				// setting time stamp
				if ( g_testingTimeStamps ) {
					// this increase the timestamp of one day
					dt = file->getDateModified();
					dt.incrDay( 1 );
					file->setDateModified( dt );

					// this set the time of the file to now
					// this function must be completed though !
					// see its implementation
					//file->updateTime();
				}

			}
		}


		Object::objectAllocationCount();

		//Object::dumpDebugInfo();

		finder->free();

		Object::objectAllocationCount();

		//Object::dumpDebugInfo();
	}

};




void test( FinderTest& finder, const String& name, const bool& recurse = false )
{
	printf( String( "\nTesting: " + name + "\n" ).ansi_c_str() );

	DateTime startTime, stopTime;
	int countTot = 0;

	startTime = DateTime::now();

	String vcfIncludes = System::getEnvironmentVariable( "VCF_INCLUDE" );

	if ( vcfIncludes.empty() ) {
		printf( "No \"VCF_INCLUDE\" environment variable found!\n" );
		return;
	}

	finder.loopTest( vcfIncludes, recurse );

	stopTime = DateTime::now();
	DateTimeSpan deltaTime = stopTime - startTime;
	double td = (1.0 * (double)deltaTime.getTotalMilliseconds())/1000;
	printf( "[%s] files: %d, subdirs: %d  Total time: %.3f seconds\n", name.ansi_c_str(), finder.countFiles_, finder.countDirectories_, td );
	printf( "\n" );
}

void test()
{
	g_showDirnames = true;
	g_showFilenames = true;

	//FinderTest1 finderTest0 = FinderTest1();
	//test( finderTest0, L"t0 (*)", false );

	//FinderTest1 finderTest1 = FinderTest1();
	//test( finderTest1, L"t1 (*)", true );

	//FinderTest2 finderTest2 = FinderTest2();
	//test( finderTest2, L"t2 (*.h)", true );

	FinderTest3 finderTest3 = FinderTest3();
	test( finderTest3, L"t3 (*.cpp)", true );
}

void getArguments()
{
	CommandLine cmdLine = FoundationKit::getCommandLine();

	if ( cmdLine.hasSwitch( "a" ) ){
		g_displayMode = Directory::Finder::dmAny;
	}
	if ( cmdLine.hasSwitch( "f" ) ){
		g_displayMode = Directory::Finder::dmFiles;
	}

	if ( cmdLine.hasSwitch( "d" ) ){
		g_displayMode = Directory::Finder::dmDirs;
	}	
}

int main(int argc, char *argv[])
{
	FoundationKit::init( argc, argv );

	getArguments();

	try {
		test();
		printf( "\n" );
	}
	catch ( BasicException& /*be*/ ) {
		// the error message is already shown !
		//printf( "%s", be.getMessage().ansi_c_str() );
	}

	FoundationKit::terminate();

	return 0;
}





