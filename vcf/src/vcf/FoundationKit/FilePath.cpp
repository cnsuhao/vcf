//FilePath.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;


FilePath::FilePath()
{

}



FilePath::FilePath( const String& filename ):filename_(filename)
{
	convertToNative(filename_);
}



FilePath::FilePath( const FilePath& filePath ):
    Object(filePath),
    filename_(filePath.filename_)
{
	convertToNative(filename_);
}



FilePath::~FilePath()
{

}

String FilePath::getDriveSeparator()
{
#ifdef WIN32
	return ":";
#else
	return "";
#endif
}

String FilePath::getExtension() const
{
	String result;

	result = filename_;

	int lastSlashPos = result.find_last_of( FilePath::getDirectorySeparator() );

	if ( lastSlashPos != String::npos ) {
		result = result.substr( lastSlashPos+1, result.size() - (lastSlashPos) );
	}

	int pos = result.find_last_of( FilePath::getExtensionSeparator() );

	if ( pos != String::npos ) {
		result.erase( 0, pos );
	}
	else {
		result = "";
	}

	return result;
}



String FilePath::getName( const bool& includeExtension ) const
{
	String result;

	result = filename_;

	int lastSlashPos = result.find_last_of( FilePath::getDirectorySeparator() );

	if ( lastSlashPos != String::npos ) {
		result = result.substr( lastSlashPos+1, result.size() - (lastSlashPos) );
	}

	if ( !includeExtension ) {
		int pos = result.find_last_of( FilePath::getExtensionSeparator() );

		if ( pos != String::npos ) {
			result.erase( pos, result.size() - pos );
		}
	}

	return result;
}


String FilePath::getDriveName() const
{
	String result;

	result = filename_;

	int drivePos = result.find_last_of( FilePath::getDriveSeparator() );
	if ( String::npos == drivePos ) {
		result = "";
	}
	else {
		result = result.substr( 0, drivePos );
	}
	return result;
}


String FilePath::getPathName( const bool& includeDriveName ) const
{
	String result;

	result = filename_;

	int drivePos = result.find_last_of( FilePath::getDriveSeparator() );
	if ( String::npos != drivePos ) {
		result.erase( 0, drivePos+1 );
	}

	int lastSlashPos = result.find_last_of( FilePath::getDirectorySeparator() );

	if ( lastSlashPos != String::npos ) {
		result = result.substr( 0, lastSlashPos+1 );
	}
	else {
		result = "";
	}

	if ( includeDriveName ) {
		String tmp = getDriveName();
		if ( false ==  tmp.empty() ) {
			tmp += FilePath::getDriveSeparator();
		}
		result = tmp + result;
	}

	return result;
}



bool FilePath::doesFileExist() const
{
	return System::doesFileExist( filename_ );
}

bool FilePath::isRelativePath() const
{
	bool result = false;
	String drive = getDriveName();

	if ( (filename_[0] != FilePath::DirectorySeparator) && (drive.empty())  ) {
		result = true;
	}
	else {
		int pos = filename_.find( "../" );
		if ( pos == 0 ) {
			result = true;
		}
		else {
			result = (filename_.find( "./" ) == 0);
		}
	}
	return result;
}

bool FilePath::isDirectory() const
{
	bool result = filename_[filename_.size()-1] == FilePath::DirectorySeparator;
	return result;
}

//returns true if s1 == s2
bool compareDirectoryComponent( const String& s1, const String& s2 )
{
	bool result = false;

#ifdef WIN32
	result = (StringUtils::lowerCase(s1) == StringUtils::lowerCase(s2));
#else
	result = (s1 == s2);
#endif

	return result;
}

String FilePath::transformToRelativePathName( const String& workingPath ) const
{
	String result;
	String tmp = filename_;
	String workDir = workingPath;
	if ( workDir.empty() ) {
		workDir = System::getCurrentWorkingDirectory();
	}
	else {
		//make sure it's a dir name
		FilePath dirPath(workingPath);
		workDir = dirPath.getDriveName() + FilePath::getDriveSeparator() + dirPath.getPathName();
	}

	if ( workDir.empty() ) {
		//ok we're screwed - throw an exception
		return "";
	}

	if ( workDir[workDir.size()-1] != FilePath::DirectorySeparator ) {
		workDir += FilePath::getDirectorySeparator();
	}

	FilePath workingDirPath = workDir;

	std::vector<String> workPathComponents = separatePathComponents(workingDirPath);

	std::vector<String> currentPathComponents = separatePathComponents(filename_);

	String workingDrive = workingDirPath.getDriveName();
	String currentDrive	= getDriveName();

	if ( StringUtils::lowerCase(currentDrive) == StringUtils::lowerCase(workingDrive) ) {
		String tmp;
		std::vector<String>::iterator workIt = workPathComponents.begin();
		int workingIndex = 0;
		int currentIndex = 0;
		while ( workIt != workPathComponents.end() ) {
			if ( (!compareDirectoryComponent( *workIt, currentPathComponents[currentIndex] )) || (workingIndex != currentIndex) ) {
				tmp += "../";
			}
			else {
				currentIndex ++;
				if ( currentIndex >= currentPathComponents.size() ) {
					currentIndex = currentPathComponents.size()-1;
				}
			}
			workingIndex ++;
			workIt ++;
		}

		if ( currentIndex > 0 ) { //this is because we are at the root / dir, don't
			//need the duplicate '/' character

			//test to see if we need to add a local dir
			if ( tmp.empty() ) {
				tmp += "./";
			}
			//only go on if we are NOT on the last element
			if ( currentIndex <= currentPathComponents.size()-1 ) {
				for ( int j=currentIndex; j<currentPathComponents.size(); j++ ) {
					if ( j < workPathComponents.size() ) {
						if ( !compareDirectoryComponent( workPathComponents[j], currentPathComponents[j]) ) {
							tmp += currentPathComponents[j];
						}
					}
					else {
						tmp += currentPathComponents[j];
					}
				}
			}
		}

		result = tmp + getName(true);
	}
	else {
		result = filename_;
	}


	return result;
}

String FilePath::expandRelativePathName( const String& workingPath ) const
{
	String result;
	String tmp = filename_;
	String workDir = workingPath;
	if ( workDir.empty() ) {
		workDir = System::getCurrentWorkingDirectory();
	}
	else {
		//make sure it's a dir name
		FilePath dirPath(workingPath);
		workDir = dirPath.getDriveName() + FilePath::getDriveSeparator() + dirPath.getPathName();
	}

	if ( workDir.empty() ) {
		//ok we're screwed - throw an exception
		return "";
	}

	if ( workDir[workDir.size()-1] != FilePath::DirectorySeparator ) {
		workDir += FilePath::getDirectorySeparator();
	}

	convertToNative(workDir);

	//strip drive if present
	String drive;
	int drivePos = workDir.find_last_of( FilePath::getDriveSeparator() );
	if ( String::npos == drivePos ) {
		drive = "";
	}
	else {
		drive = workDir.substr( 0, drivePos );
		//workDir.erase( 0, drivePos );
	}

	std::vector<String> workPathComponents = separatePathComponents(workDir);
	int pos = tmp.find( "../" );
	if ( pos != String::npos ) {

		while ( pos != String::npos ) {
			if ( 0 != pos ) {
				//OOOOHHH error condition this is
				//is a malformed string ! - in other
				//words we have a relative path like foo/../bar - incorrect!!!
				//throw exception

				return "";
			}

			//remove the last dir component
			//equivalent of "going back a dir", or "cd .."
			workPathComponents.pop_back();
			tmp.erase( 0, pos+3 );
			pos = tmp.find( "../", 0 );
		}
		std::vector<String>::iterator it = workPathComponents.begin();
		result = "";
		while ( it != workPathComponents.end() ) {
			result += *it;
			it ++;
		}
		result += tmp;
		result = drive + FilePath::getDriveSeparator() + result;
	}
	else {
		//ok look for ../ series
		pos = tmp.find( "./", 0 );
		//ok simply local working dir
		//remove the ./ notation and prepend the
		//working dir to file name
		if ( pos != String::npos ) {
			tmp.erase( pos, 2 );
			result = workDir + tmp;
		}
		else if ( tmp[0] != FilePath::DirectorySeparator ) {
			result = workDir + tmp;
		}
	}

	return result;
}

std::vector<String> FilePath::separatePathComponents( const String& path ) const
{
	std::vector<String> pathComponents;
	String tmp = path;
	//get rid of drive
	int pos = tmp.find( FilePath::getDriveSeparator() );
	if ( pos != String::npos ) {
		tmp.erase( 0, pos + 1 );
	}

	pos = tmp.find( FilePath::getDirectorySeparator(), 0 );
	int lastPos = 0;
	while ( pos != String::npos ) {
		pathComponents.push_back( tmp.substr( lastPos, (pos - lastPos)+1 ) );
		lastPos = pos+1;
		pos = tmp.find( FilePath::getDirectorySeparator(), pos + 1 );
	}

	return pathComponents;
}

/**
*this will convert the filename to a standard format:
[<drive_letter>:]/[dir1/][dir2/][dir_n/]
*/
void FilePath::convertToNative( String& filename ) const
{
	std::replace_if( filename.begin(), filename.end(),
					std::bind2nd(std::equal_to<VCFChar>(),'\\') , '/' );


}

String FilePath::transformToOSSpecific() const
{
	VCFChar convertChar = '/';
#ifdef WIN32
	convertChar = '\\';
#endif
	String result = filename_;

	std::replace_if( result.begin(), result.end(),
					std::bind2nd(std::equal_to<VCFChar>(),'/') , convertChar );

	return result;
}

bool FilePath::isPathDirectory( const String& path )
{
	FilePath tmp = path;
	return tmp.isDirectory();
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
*Revision 1.7  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.6.4.4  2003/09/22 01:48:05  ddiego
*some minor additions ot teh DropTarget to allow it to have multiple
*control targets
*also a few other misc fixes
*
*Revision 1.6.4.3  2003/09/19 21:24:20  ddiego
*small changes
*
*Revision 1.6.4.2  2003/09/19 04:11:39  ddiego
*added fix to docmanager
*added fix to handle path components with case insensitivity on Win32
*for file path transformation to relative paths
*
*Revision 1.6.4.1  2003/08/23 12:44:35  marcelloptr
*improved comments in FilePath
*
*Revision 1.6  2003/05/17 20:37:41  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.5.2.2  2003/03/23 03:23:58  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.5.2.1  2003/03/12 03:12:47  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.5  2003/02/26 04:30:53  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.4.2.2  2002/12/27 23:04:57  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.4.2.1  2002/11/28 05:12:05  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.4  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.3.4.2  2002/10/08 04:16:57  ddiego
*fixed a bug in the getClientBounds() that caused a stack overflow! DOH!
*further additions to the TemplateNewClassDlg to sync the various file names
*in the dialog to the lcass name
*
*Revision 1.3.4.1  2002/09/23 21:24:39  ddiego
*more build fixes - there is a serious error with file locks that needs to fixed
*
*Revision 1.3  2002/09/12 03:26:06  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.2.4.10  2002/08/01 19:16:26  ddiego
*added support for create new files from the File | New... menu
*this displays a list of file templates which are read from the Object
*Repository. The FilePath had a bug with the FilePath::isRelative() function
*fixed a display bug with the CheckBoxControl and the fixed size of hte
*of the check box being too small
*
*Revision 1.2.4.9  2002/08/01 05:08:31  ddiego
*made changes to open a file from without being in a project
*started changes for add files from the "File | New..." dialog
*
*Revision 1.2.4.8  2002/07/21 05:02:50  ddiego
*added more stuff for configuration management, fixed the FilePath bug
*add a removeAllHandlers() to VCF::Delegate class
*
*Revision 1.2.4.7  2002/07/19 21:27:40  ddiego
*added tweaks to FilePath - there is still a problem with transformaing certain
*directory paths...fix this !
*
*Revision 1.2.4.6  2002/07/16 21:06:22  ddiego
*mods to the TextEditor to add advanced features for editing
*code
*
*Revision 1.2.4.5  2002/07/16 04:23:19  ddiego
*modified FilePath to get the drivename and path name in one fucntion
*will correctly ignore the drive separator in non WIN32 systems
*mods ot VCFBuilder to load external projects within a workspace
*using relative paths ! - this needs to be migrated over to xmake
*as well
*
*Revision 1.2.4.4  2002/07/15 21:03:11  ddiego
*mods to VCFBuilder, fixed some bugs in FilePath
*
*Revision 1.2.4.3  2002/07/15 04:06:14  ddiego
*fixing saving the various project file ot take advantage to relative path
*and the FilePath object
*
*Revision 1.2.4.2  2002/07/14 05:40:02  ddiego
**** empty log message ***
*
*Revision 1.2  2002/06/24 04:24:49  ddiego
*mods to VCFBuilder
*
*Revision 1.1  2002/06/18 21:18:32  ddiego
*added FilePath
*/


