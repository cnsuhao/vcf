////CreateBundle.cpp

#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;


#define USAGE	"Proper arguments to send to me are:\n\t-src <source dir>\n\t-dest <destination dir>\n\t-bundle <bundle name>"

int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	CommandLine cmdLine = FoundationKit::getCommandLine();
	if ( !cmdLine.hasSwitch( "-src" ) ) {
		System::println( "Please supply a source directory!" );
		System::println( USAGE );
		return 1;	
	}
	
	if ( !cmdLine.hasSwitch( "-dest" ) ) {
		System::println( "Please supply a dest directory!" );
		System::println( USAGE );
		return 1;	
	}

	if ( !cmdLine.hasSwitch( "-bundle" ) ) {
		System::println( "Please supply a bundle name!" );
		System::println( USAGE );
		return 1;	
	}

	
	String bundleName = cmdLine.getArgument( "-bundle", 0 );
	FilePath srcDir = cmdLine.getArgument( "-src", 0 );
	FilePath destDir = cmdLine.getArgument( "-dest", 0 );

	if ( srcDir.isRelativePath() ) {
		//expand it completely using the current working dir
		srcDir = FilePath::makeDirectoryName( srcDir.expandRelativePathName( System::getCurrentWorkingDirectory() ) );
	}

	if ( destDir.isRelativePath() ) {
		//expand it completely using the current working dir
		destDir = FilePath::makeDirectoryName( destDir.expandRelativePathName( System::getCurrentWorkingDirectory() ) );
	}

	String contentDir = destDir + "Contents" + FilePath::getDirectorySeparator();


	if ( System::getOSName().find( "Windows" ) != String::npos ) {
		//Windows!
		String infoFileName = srcDir + "Info.plist";

		if ( !File::exists( infoFileName ) ) {
			infoFileName = srcDir + "Info.xml";
			if ( !File::exists( infoFileName ) ) {
				infoFileName = "";
			}
		}


		if ( !infoFileName.empty() ) {
			try { 

				if ( !File::exists( contentDir ) ) {
					//create the output dir!
					Directory dir;
					dir.create( contentDir, File::ofRead | File::ofWrite );
				}

				File infoFile( infoFileName, File::ofRead, File::shRead );
				
				FilePath fp = infoFileName;
				
				//special block
				try {
					infoFile.copyTo( contentDir + fp.getBaseName(true) );
				}
				catch ( BasicFileError& e ) {
					//is it already there?
					if ( !File::exists( contentDir ) ) {
						//nope, throw the exception to our outer handler !
						throw; //we're done
					}
				}
				
				String resDir = contentDir + "Resources" + FilePath::getDirectorySeparator();
				if ( !File::exists( resDir ) ) {
					//create the output dir!
					Directory dir;
					dir.create( resDir, File::ofRead | File::ofWrite );
				}

				String binDir = contentDir + System::getOSName() + FilePath::getDirectorySeparator() +
								System::getCompiler() + FilePath::getDirectorySeparator();

				if ( !File::exists( binDir ) ) {
					//create the output dir!
					Directory dir;
					dir.create( binDir, File::ofRead | File::ofWrite );
				}

				String srcIcoFile = srcDir + bundleName + ".ico";
				String missingIcoFile;

				if ( File::exists( srcIcoFile ) ) {
					//copy it over!	
					File ico(srcIcoFile);
					try { 
						ico.copyTo( resDir + bundleName + ".ico" );
					}
					catch ( BasicException& ) {
						System::println( "Warning: failed to copy over bundle .ico file." );
					}
				}
				else {
					//warn about the lack of an ico file!
					missingIcoFile = ";Please put a valid ICO file in the Contents\\Resources\\ directory!\r\n";
				}

				//create Desktop.ini				
				String desktopIni = "[.ShellClassInfo]\r\n" + missingIcoFile + ""\
									"IconFile=\"Contents\\Resources\\" + bundleName + ".ico\"\r\n"\
									"IconIndex=0\r";

				//add extraneous info just to be cool!

				ProgramInfo* progInfo = System::getProgramInfoFromFileName( destDir );
				if ( NULL != progInfo ) {

					desktopIni +="\nInfoTip=";
					desktopIni += "Application bundle: " + bundleName + ". " + progInfo->getCopyright();
					
					desktopIni += "\r";
					delete progInfo;
				}



				FileOutputStream fs ( destDir + "Desktop.ini" );
				TextOutputStream ts(&fs);
				ts << desktopIni;
				fs.close();

				Process proc;
				String dest = destDir;
				if ( dest[dest.size()-1] == FilePath::DirectorySeparator ) {
					//remove it, the attrib command doesn't like it???

					dest.erase( dest.size()-1, 1 );
				}
				proc.createProcess( "attrib", "+s " + FilePath::transformToOSSpecific(dest) );

			}
			catch ( BasicException& e ) {
				System::println( e.getMessage() );
				return 1;
			}
		}
		else {
			//bail!!!!
			System::println( "You don't have the right info - please create a valid Info.plist or Info.xml file in your source directory." );
			return 1;
		}
	}


	FoundationKit::terminate();
	return 0;
}


