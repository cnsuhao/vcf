//Win32FilePeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

Win32FilePeer::Win32FilePeer( File* file, const String& fileName )
{
	fileHandle_ = NULL;


	file_ = file;

	searchStarted_ = false;

	FilePath path = fileName;
	setName( path.transformToOSSpecific() );
}

Win32FilePeer::~Win32FilePeer()
{
	if ( NULL != fileHandle_ ){
		::CloseHandle( fileHandle_ );
	}

	std::map<Directory::Finder*,FileSearchData*>::iterator it = findFileData_.begin();
	while ( it != findFileData_.end() ) {
		FileSearchData* findData = it->second;
		BOOL err = FindClose( findData->searchHandle_ );
		findData->searchHandle_ = NULL;
		it ++;
	}

	findFileData_.clear();
}

void Win32FilePeer::setFile( File* file )
{
	file_ = file;
}

bool Win32FilePeer::beginFileSearch( Directory::Finder* finder )
{
	bool result = false;

	bool unicodeEnabled = System::isUnicodeEnabled();

	FileSearchData* findData = NULL;
	if ( unicodeEnabled ) {
		findData = new FileSearchDataW();
	}
	else {
		findData = new FileSearchDataA();
	}


	searchFilters_.clear();
	buildSearchFilters( finder->getSearchFilter() );

	if ( searchFilters_.empty() ) {
		return false;
	}

	searchFilterIterator_ = searchFilters_.begin();
	String searchFilter = *searchFilterIterator_;

	String searchDirFilter = filename_ + searchFilter;

	if ( unicodeEnabled ) {
		findData->searchHandle_ = ::FindFirstFileW( searchDirFilter.c_str(), &((FileSearchDataW*)findData)->findData_ );
	}
	else {
		findData->searchHandle_ = ::FindFirstFileA( searchDirFilter.ansi_c_str(), &((FileSearchDataA*)findData)->findData_ );
	}


	if ( INVALID_HANDLE_VALUE != findData->searchHandle_ ) {
		result = true;
		findFileData_[finder] = findData;
		searchStarted_ = true;
	}
	else {
		//try other filters
		if ( searchFilterIterator_ != searchFilters_.end() ) {
			searchFilterIterator_++;
			while ( (INVALID_HANDLE_VALUE == findData->searchHandle_) && (searchFilterIterator_ != searchFilters_.end()) ) {

				searchFilter = *searchFilterIterator_;
				searchDirFilter = filename_ + searchFilter;

				if ( unicodeEnabled ) {
					findData->searchHandle_ =
						::FindFirstFileW( searchDirFilter.c_str(), &((FileSearchDataW*)findData)->findData_ );
				}
				else {
					findData->searchHandle_ =
						::FindFirstFileA( searchDirFilter.ansi_c_str(), &((FileSearchDataA*)findData)->findData_ );
				}

				result = (INVALID_HANDLE_VALUE != findData->searchHandle_);

				searchFilterIterator_++;
			}
		}
		if ( true == result ) {
			findFileData_[finder] = findData;
			searchStarted_ = true;
		}
		else {
			delete findData;
			findData = NULL;
		}
	}
	return result;
}

String Win32FilePeer::findNextFileInSearch( Directory::Finder* finder )
{
	String result;

	bool unicodeEnabled = System::isUnicodeEnabled();

	std::map<Directory::Finder*,FileSearchData*>::iterator found = findFileData_.find( finder );
	if ( found != findFileData_.end() ) {
		FileSearchData* findData = found->second;

		if( true == searchStarted_ ) {
			if ( unicodeEnabled ) {
				result = ((FileSearchDataW*)findData)->findData_.cFileName;
			}
			else {
				result = ((FileSearchDataA*)findData)->findData_.cFileName;
			}
		}
		else {
			int err = 0;
			if ( unicodeEnabled ) {
				err =
					::FindNextFileW( findData->searchHandle_, &((FileSearchDataW*)findData)->findData_ );
			}
			else {
				err =
					::FindNextFileA( findData->searchHandle_, &((FileSearchDataA*)findData)->findData_ );
			}

			if ( !err ) {
				if ( unicodeEnabled ) {
					((FileSearchDataW*)findData)->findData_.cFileName[0] = '\0';
				}
				else {
					((FileSearchDataA*)findData)->findData_.cFileName[0] = '\0';
				}


				err = ::GetLastError();
				if ( ERROR_NO_MORE_FILES == err ) {

					err = ::FindClose( findData->searchHandle_ );

					findData->searchHandle_ = INVALID_HANDLE_VALUE;
					//try the next search filter
					if ( searchFilterIterator_ != searchFilters_.end() ) {
						searchFilterIterator_++;

						while ( (INVALID_HANDLE_VALUE == findData->searchHandle_) &&
							(searchFilterIterator_ != searchFilters_.end()) ) {

							String searchFilter = *searchFilterIterator_;
							String searchDirFilter = filename_ + searchFilter;

							//reset back to the start with a new filter
							if ( unicodeEnabled ) {
								findData->searchHandle_ =
									::FindFirstFileW( searchDirFilter.c_str(), &((FileSearchDataW*)findData)->findData_ );
							}
							else {
								findData->searchHandle_ =
									::FindFirstFileA( searchDirFilter.ansi_c_str(), &((FileSearchDataA*)findData)->findData_ );
							}

							searchFilterIterator_++;
						}

						if ( INVALID_HANDLE_VALUE == findData->searchHandle_ ) {
							if ( unicodeEnabled ) {
								((FileSearchDataW*)findData)->findData_.cFileName[0] = '\0';
							}
							else {
								((FileSearchDataA*)findData)->findData_.cFileName[0] = '\0';
							}
						}
					}
				}
			}

			if ( unicodeEnabled ) {
				result = ((FileSearchDataW*)findData)->findData_.cFileName;
			}
			else {
				result = ((FileSearchDataA*)findData)->findData_.cFileName;
			}
		}
	}

	searchStarted_ = false;
	return result;
}

void Win32FilePeer::endFileSearch( Directory::Finder* finder )
{
	std::map<Directory::Finder*,FileSearchData*>::iterator found = findFileData_.find( finder );
	if ( found != findFileData_.end() ) {
		FileSearchData* findData = found->second;

		::FindClose( findData->searchHandle_ );

		findData->searchHandle_ = NULL;
		delete findData;
		findData = NULL;

		findFileData_.erase( found );
	}
}

void Win32FilePeer::buildSearchFilters( const String& searchFilter )
{
	String tmp = searchFilter;
	int pos = tmp.find( ";" );
	while ( String::npos != pos ) {
		searchFilters_.push_back( tmp.substr( 0, pos ) );
		tmp.erase( 0, pos+1 );
		pos = tmp.find( ";" );
	}

	if ( !tmp.empty() ) {
		searchFilters_.push_back( tmp );
	}
}

void Win32FilePeer::remove()
{
	if ( NULL != fileHandle_ ){
		::CloseHandle( fileHandle_ );
		fileHandle_ = NULL;
	}
	if ( filename_[filename_.size()-1] == '\\' ) {
		BOOL res = FALSE;
		if ( System::isUnicodeEnabled() ) {
			res = ::RemoveDirectoryW( filename_.c_str() );
		}
		else {
			res = ::RemoveDirectoryA( filename_.ansi_c_str() );
		}

		if ( !res ) {
			throw BasicFileError( "Unable to remove directory \"" + filename_ + "\",\nprobably because the directory still contains objects." );
		}
	}
	else {
		BOOL res = FALSE;
		if ( System::isUnicodeEnabled() ) {
			res = ::DeleteFileW( filename_.c_str() );
		}
		else {
			res = ::DeleteFileA( filename_.ansi_c_str() );
		}

		if ( !res ) {
			throw BasicFileError( "Unable to remove file \"" + filename_ + "\"." );
		}
	}
}

void Win32FilePeer::create()
{
	if ( false == filename_.empty() ){
		if ( NULL != fileHandle_ ){
			::CloseHandle( fileHandle_ );
		}
		if ( filename_[filename_.size()-1] == '\\' ) {
			fileHandle_ = NULL;
			std::vector<String> dirPaths;
			String tmp = filename_;
			int pos = tmp.find( "\\" );
			while ( pos != String::npos ) {
				dirPaths.push_back( tmp.substr( 0, pos ) );
				tmp.erase( 0, pos+1 );
				pos = tmp.find( "\\" );
			}
			if ( dirPaths.size() == 1 ) {
				String dir = dirPaths[0];
				if ( dir[dir.size()-1] != ':' ) {
					throw BasicFileError( "Unable to create directory \"" + filename_ + "\", path too short or incorrect." );
				}
			}
			else if ( dirPaths.size() < 2 ) {
				throw BasicFileError( "Unable to create directory \"" + filename_ + "\", path too short or incorrect." );
			}
			std::vector<String>::iterator it = dirPaths.begin();
			String dirPath = *it;
			it++;
			while ( it != dirPaths.end() ) {
				dirPath += "\\" + *it;

				BOOL res = FALSE;
				if ( System::isUnicodeEnabled() ) {
					::CreateDirectoryW( dirPath.c_str(), NULL );
				}
				else {
					::CreateDirectoryA( dirPath.ansi_c_str(), NULL );
				}

				if ( !res ) {
					int err = GetLastError();
					if ( ERROR_ALREADY_EXISTS != err ) {
						throw BasicFileError( "Unable to create directory \"" + filename_ + "\"" );
					}
				}
				it++;
			}
		}
		else {
			//attach to the file
			FilePath fp = filename_;
			String fileDir = fp.getPathName(true);
			if ( true == fileDir.empty() ){
				TCHAR currentDir[MAX_PATH];
				memset( currentDir, 0 , MAX_PATH );
				GetCurrentDirectory( MAX_PATH, currentDir );
				filename_ = "\\" + filename_;
				filename_ = currentDir +  filename_;
			}

			if ( System::isUnicodeEnabled() ) {
				fileHandle_ = ::CreateFileW( filename_.c_str(),
											GENERIC_READ | GENERIC_WRITE,
											FILE_SHARE_READ | FILE_SHARE_WRITE,
											NULL,
											OPEN_EXISTING,
											FILE_ATTRIBUTE_NORMAL,
											NULL );
			}
			else {
				fileHandle_ = ::CreateFileA( filename_.ansi_c_str(),
											GENERIC_READ | GENERIC_WRITE,
											FILE_SHARE_READ | FILE_SHARE_WRITE,
											NULL,
											OPEN_EXISTING,
											FILE_ATTRIBUTE_NORMAL,
											NULL );
			}


			if ( (NULL == fileHandle_) || (INVALID_HANDLE_VALUE == fileHandle_) ){
				fileHandle_ = NULL;
				//throw exception
				throw BasicFileError("Unable to create or attach to the specified file");
			}
		}
	}
}


uint32 Win32FilePeer::getSize()
{
	uint32 resultLow = 0;
	uint32 resultHigh = 0;
	if ( NULL != fileHandle_ ){
		resultLow = GetFileSize( fileHandle_, (DWORD*)&resultHigh );
	}
	return resultLow;
}

void Win32FilePeer::setName( const String& fileName )
{
	this->filename_ = fileName;

	create();
}

void Win32FilePeer::copyTo( const String& copyFileName )
{
	FilePath copyPath = copyFileName;
	BOOL res = FALSE;

	if ( System::isUnicodeEnabled() ) {
		res = CopyFileW( filename_.c_str(), copyPath.transformToOSSpecific().c_str(), FALSE );
	}
	else {
		res = CopyFileA( filename_.ansi_c_str(), copyPath.transformToOSSpecific().ansi_c_str(), FALSE );
	}

	if ( ! res ) {
		throw BasicFileError("File \"" + copyFileName + "\" already exists." );
	}

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:20  ddiego
*migration towards new directory structure
*
*Revision 1.16.2.1  2004/04/21 02:17:25  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.16  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.15.2.1  2004/03/19 21:25:57  ddiego
*just some minor noodlin
*
*Revision 1.15  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.14.4.1  2003/08/20 22:55:18  ddiego
*got rid of some older methods for StringUtils, should be using the FilePath
*class instead
*
*Revision 1.14  2003/05/17 20:37:36  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.13.2.1  2003/03/12 03:12:34  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.13  2003/02/26 04:30:50  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.12.8.1  2003/01/08 00:19:53  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.12  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.11.6.2  2002/07/29 04:46:40  ddiego
*add some files to docs and added navigating to a file when
*clicking on a class node in the workspace tree
*
*Revision 1.11.6.1  2002/07/15 21:03:11  ddiego
*mods to VCFBuilder, fixed some bugs in FilePath
*
*Revision 1.11  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.10.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.10  2002/01/29 04:41:43  ddiego
*fixed leak in Win32Button, plus cleaned up some other GetDC stuff and
*fixed the Tab problem in Win98.
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


