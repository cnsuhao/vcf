//Win32FilePeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

/*static*/ void internal_initFileAttributesConversionTable()
{
}


Win32FilePeer::Win32FilePeer( File* file )
{
	findData_ = NULL;
	searchHandle_ = NULL;

	file_ = file;

	// will have a value when opening the file
	fileHandle_ = NULL;
}

Win32FilePeer::~Win32FilePeer()
{
	if ( NULL != findData_ ) {
		delete findData_;
	}
}

void Win32FilePeer::setFile( File* file )
{
	// close any open handles
	close(); // %%%

	findData_ = NULL;
	searchHandle_ = NULL;

	file_ = file;

	// will have a value when opening the file
		fileHandle_ = NULL;
}

void Win32FilePeer::create()
{
	String filename = getName();

	if ( false == filename.empty() ){
		if ( NULL != fileHandle_ ){
			::CloseHandle( fileHandle_ );
		}
		if ( filename[filename.size()-1] == '\\' ) {
			fileHandle_ = NULL;
			std::vector<String> dirPaths;
			String tmp = filename;
			int pos = tmp.find( "\\" );
			while ( pos != String::npos ) {
				dirPaths.push_back( tmp.substr( 0, pos ) );
				tmp.erase( 0, pos+1 );
				pos = tmp.find( "\\" );
			}
			if ( dirPaths.size() == 1 ) {
				String dir = dirPaths[0];
				if ( dir[dir.size()-1] != ':' ) {
					throw BasicFileError( "Unable to create directory \"" + filename + "\", path too short or incorrect." );
				}
			}
			else if ( dirPaths.size() < 2 ) {
				throw BasicFileError( "Unable to create directory \"" + filename + "\", path too short or incorrect." );
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
						throw BasicFileError( "Unable to create directory \"" + filename + "\"" );
					}
				}
				it++;
			}
		}
		else {
			//attach to the file
			FilePath fp = filename;
			String fileDir = fp.getPathName(true);
			if ( true == fileDir.empty() ){
				TCHAR currentDir[MAX_PATH];
				memset( currentDir, 0 , MAX_PATH );
				GetCurrentDirectory( MAX_PATH, currentDir );
				filename = "\\" + filename;
				filename = currentDir +  filename;
			}

			if ( System::isUnicodeEnabled() ) {
				fileHandle_ = ::CreateFileW( filename.c_str(),
											GENERIC_READ | GENERIC_WRITE,
											FILE_SHARE_READ | FILE_SHARE_WRITE,
											NULL,
											OPEN_EXISTING,
											FILE_ATTRIBUTE_NORMAL,
											NULL );
			}
			else {
				fileHandle_ = ::CreateFileA( filename.ansi_c_str(),
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


ulong64 Win32FilePeer::getSize()
{
	uint32 resultLow = 0;
	uint32 resultHigh = 0;
	if ( NULL != fileHandle_ ){
		resultLow = ::GetFileSize( fileHandle_, (DWORD*)&resultHigh );
	}
	//return ulong64( resultLow, resultHigh );
	ulong64 size( resultLow,resultHigh );
	//size.hi(  );

	file_->internal_addToStatMask( File::smSize );

	return size;
}



// directory search support
void Win32FilePeer::initDataSearch()
{
	if ( NULL == findData_ ) {
		if ( System::isUnicodeEnabled() ) {
			findData_ = new Win32FindDataW;
		} else {
			findData_ = new Win32FindDataA;
		}
		if ( NULL == findData_ ) {
			throw NoFreeMemException(); 
		}
	}
}

void Win32FilePeer::initFileSearch( Directory::Finder* finder )
{
	initDataSearch();

	searchHandle_ = NULL;

	// other initialize of the finder before starting the search in it

	finder->internal_updateToActiveFinder();
}

File* Win32FilePeer::findNextFileInSearch( Directory::Finder* finder )
{
	// ::FindFirstFileEx is better suited to look for subdirectories but it is unsupported by win98

	File* file = NULL;

	bool unicodeEnabled = System::isUnicodeEnabled();

	bool isDir = false;

	bool ok;
	ulong32 fAttribs;

	// looping until we find the directory/file matching the filter
	while ( true )
	{
		file = NULL;
		finder->getFileInfo().internal_setStatMask( File::smStatNone );
		isDir = false;

		// are we starting a new search ?
		if ( NULL == searchHandle_ ) {
			// Remarks: 1 - do not use searchPostfix_ != L"*", like: L"*.cpp", because there is 
			//				      there is a bug that gives error when the directory is empty! :(
			//				      Is this happening only with Unicode ? or with the searchPrefix_ ?
			//
			//				  2 - Do not use '\\' and '/' at the same time, beside the prefix L"\\\\?\\",
			//              otherwise ::FindFirstFileW() could fail.
			String searchDirFilter = String( L"\\\\?\\" )+ getName() + String( L"*" );

			if ( unicodeEnabled ) {
				searchHandle_ = ::FindFirstFileW( searchDirFilter.c_str(), &((Win32FindDataW*)findData_)->findData_ );
			} else {
				searchHandle_ = ::FindFirstFileA( searchDirFilter.ansi_c_str(), &((Win32FindDataA*)findData_)->findData_ );
			}
			ok = ( INVALID_HANDLE_VALUE != searchHandle_ );

		} else {
			if ( unicodeEnabled ) {
				ok = ( 0 != ::FindNextFileW( searchHandle_, &((Win32FindDataW*)findData_)->findData_ ) );
			} else {
				ok = ( 0 != ::FindNextFileA( searchHandle_, &((Win32FindDataA*)findData_)->findData_ ) );
			}
		}

		if  ( ok ) {
			if ( unicodeEnabled ) {
				fAttribs = Win32FilePeer::convertAttributesFromSystemSpecific( ((Win32FindDataW*)findData_)->findData_.dwFileAttributes );
			} else {
				fAttribs = Win32FilePeer::convertAttributesFromSystemSpecific( ((Win32FindDataA*)findData_)->findData_.dwFileAttributes );
			}
			
			// first filtering for attributes
			isDir = ( 0 != ( fAttribs & File::faDirectory ) );
			if ( ( isDir && finder->getCurrentDisplayOrder() == Directory::Finder::dmFiles ) ||
			     ( !isDir && ( ( finder->getCurrentDisplayOrder() == Directory::Finder::dmDirs ) ||
			                   ( ( File::faNone != finder->getMaskFilterFileAttribs() ) && 
			                     ( 0 == ( fAttribs & finder->getMaskFilterFileAttribs() ) ) ) ) ) ) {
				continue;
			}

			// to test the time: with and without
			file = updateFindDataInfos( &finder->getFileInfo(), findData_, (File::StatMask)( finder->getStatMask() & ~File::smAttributes ) );
			file->internal_setFileAttributes( fAttribs );
			file->internal_addToStatMask( File::smAttributes );

			if ( isDir && !finder->getAllowSpecialDirs() ) {
				if ( file->getName() == L"." || file->getName() == L".." ) {
					continue;
				}
			}

			// finally the full filename
			file->internal_setFileName( file_->getName() + file->getName() );
		}


		if ( NULL != file ) {
			// filtering
			FileSearchFilter* filter = finder->getSearchFilterFileObject();
			if ( NULL != filter ) {
				file = filter->passSearchFilter( file, dynamic_cast<const Directory*>(file_), finder );
			}

			// recursion management
			if ( NULL != file ) {
				// ok we found a subdirectory matching the filter
				// now recursion into this subdirectory
				if ( isDir ) {
					if ( finder->getRecurse() ) {
						if ( finder->canRecurseDown() )	{
							this->goDirDown( finder, file );
						} 
						else {
							// continue the search in the next subdirectory
							continueSearch( finder, file );
						}
					}
				}

				if ( NULL != file ) {
					// file found
					break;
				}
			}
		} else {
			// end of search or error
			if ( ::GetLastError() == ERROR_NO_MORE_FILES )  {
				if ( INVALID_HANDLE_VALUE != searchHandle_ ) {
					this->endFileSearch( finder );

					// what do we need to do next ?
					continueSearch( finder, file );
				}
				break;
			} else {
				String error = "findNextFileInSearch: " + VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		}

	} // while ( true )

	finder->setCurrentElement( file );

	return file;
}

void Win32FilePeer::endFileSearch( Directory::Finder* finder )
{
	if ( NULL != searchHandle_ && INVALID_HANDLE_VALUE != searchHandle_ ) {
		if ( !::FindClose( searchHandle_ )) {
			String error = "endFileSearch: " + VCFWin32::Win32Utils::getErrorString( GetLastError() );
			throw BasicException( error );
		}
	}

	searchHandle_ = NULL;
}

void Win32FilePeer::continueSearch( Directory::Finder* finder, File* file )
{
	finder->continueSearch( file );
	/*
	Directory::Finder::DisplayMode displayOrder1 = Directory::Finder::dmAny;
	Directory::Finder::DisplayMode displayOrder2 = Directory::Finder::dmAny;

	Directory::Finder::DisplayMode finderDispOrder = finder->getDisplayOrder();
	Directory::Finder::DisplayMode finderCurrentOrder = finder->getCurrentDisplayOrder();

	if ( Directory::Finder::dmFiles == finderDispOrder ) {
		displayOrder1 = Directory::Finder::dmFiles;
		displayOrder2 = Directory::Finder::dmDirs;
	} else if ( Directory::Finder::dmDirs == finderDispOrder ) {
		displayOrder1 = Directory::Finder::dmDirs;
		displayOrder2 = Directory::Finder::dmFiles;
	}

	if ( Directory::Finder::dmAny != finderCurrentOrder && 
		   displayOrder1 == finderCurrentOrder ) {
		// 1st step done: we were searching for dir, now we search for files
		Directory::Finder* activeFinder = finder->activeFinder();
		VCF_ASSERT( activeFinder == finder );

		finder->setCurrentDisplayOrder( displayOrder2 );

		// the 'dirs' search was completed. We need to state that it is not
		activeFinder->setSearchHasMoreElements( true );
		activeFinder->setSearchAgain( true );
	} 
	else { // if ( finder->displayOrderCurrent_ == displayOrder2 ) {
		if ( finder->getRecurse() ) {
			this->goDirUp( finder, file );
		} 
		else {
			finder->activeFinder()->setSearchAgain( false );
		}
	}
	*/
}

void Win32FilePeer::goDirDown( Directory::Finder* finder, File* file )
{
	
	finder->goDownDir( file );




	/*

	finderSubdir->setRecursion( finder->recurse_, finder->recursionLevelMax_ ); // finder->recurse_ always true here
	finderSubdir->setDisplayMode( finder->getDisplayMode() );
	finderSubdir->setDisplayOrder( finder->getDisplayOrder() );

	// relative path for files in this subdir
	finderSubdir->setRelativePathToRootSearch( finder->getRelativePathToRootSearch() + relPath );

	//finderSubdir->displayOrderCurrent_ = Directory::Finder::dmDirs;

	// inherits information from the parent finder
	finderSubdir->rootSearchFinder_				= finder->rootSearchFinder_;
	finderSubdir->maskFilterFileAttribs_	= finder->maskFilterFileAttribs_;
	finderSubdir->statMask_								= finder->statMask_;
	finderSubdir->setAllowSpecialDirs( finder->getAllowSpecialDirs() );

	// set the newly created subdir-finder as the active one
	finderSubdir->rootSearchFinder_->activeFinder_ = finderSubdir;

	// this will force the initialization of this new finder
	finderSubdir->rootSearchFinder_->activeFinder_->currentElement_ = NULL;

	finderSubdir->parentFinder_ = finder;
	finder->childFinder_ = finderSubdir;

	// one level down
	// set the current subdirectory level for the active finder
	// attention: at this precise point the active finder is *not* exactly the current finder
	finder->rootSearchFinder_->activeFinder_->recursionLevel_ = previousRecursionLevel + 1;

	// do not adjust this here, it is too soon ( do it inside initFileSearch instead )
	// finder->rootSearchFinder_->relativePathToRootSearch_= finderSubdir->relativePathToRootSearch_;

	VCF_ASSERT( finder->childFinder_->parentFinder_ == finder );

  */


}

void Win32FilePeer::goDirUp( Directory::Finder* finder, File* file )
{

	finder->goUpDir( file );

	/*
	// Remark:
	// 1) it doesn't change file
	// 2) it doesn't change the finder
	// 3) it changes the rootSearchFinder_->activeFinder_ which is the first up-dir with more elements to search

	// - please remove or comment the VCF_ASSERT in the future

	//VCF_ASSERT( NULL != finder->parentFinder_ ); // should be false only when finder->rootSearchFinder_

	if ( NULL != finder->parentFinder_ ) {
		VCF_ASSERT( finder->rootSearchFinder_->activeFinder_ == finder );

		// we need to state right away here, that the search in this subdirectory was completed
		finder->currentElement_ = file;
		finder->searchHasMoreElements_ = ( NULL != finder->currentElement_ ); // i.e. false. 

		// store the current subdirectory level before switching subdir
		int previousRecursionLevel = finder->rootSearchFinder_->activeFinder_->recursionLevel_;

		// we go up one or more levels until we find one with the search not completed yet
		while( finder->rootSearchFinder_->activeFinder_ != finder->rootSearchFinder_ &&
						!finder->rootSearchFinder_->activeFinder_->searchHasMoreElements_ ) {
				// detach this child from parent
				finder->parentFinder_->childFinder_ = NULL;

				// set the parent as the active one
				finder->rootSearchFinder_->activeFinder_ = finder->rootSearchFinder_->activeFinder_->parentFinder_;

				// we just finished a search in the child, but we need to continue 
				// the search in the parent dir if it had more elements to search
				VCF_ASSERT( finder->parentFinder_->searchHasMoreElements_ == true );
				finder->rootSearchFinder_->activeFinder_->goSearchAgain_ = finder->parentFinder_->searchHasMoreElements_;

				// one level up
				previousRecursionLevel--;
		}
		// set the current subdirectory level for the active finder ( not exactly the current one )
		finder->rootSearchFinder_->activeFinder_->recursionLevel_ = previousRecursionLevel;

		finder->rootSearchFinder_->relativePathToRootSearch_= finder->rootSearchFinder_->activeFinder_->relativePathToRootSearch_;
		if ( NULL == finder->rootSearchFinder_->activeFinder_->parentFinder_ ) {
			finder->rootSearchFinder_->relativePathToRootSearch_.erase();
			finder->rootSearchFinder_->activeFinder_->relativePathToRootSearch_.erase();
		}
	} else {
		// in the root directory for this recursive search we don't want to go forever
		finder->rootSearchFinder_->activeFinder_->goSearchAgain_ = false;

		finder->rootSearchFinder_->relativePathToRootSearch_.erase();
		finder->rootSearchFinder_->activeFinder_->relativePathToRootSearch_.erase();
	}
	*/

}

/*static*/ void Win32FilePeer::copyFromAttributeData( File* file, WIN32_FILE_ATTRIBUTE_DATA& fileAttribData, File::StatMask statMask/*=File::smMaskAll*/ )
{
	// throw if errors
	file->internal_removeFromStatMask( statMask );

	if ( statMask & File::smSize ) {
		file->internal_setFileSize( ulong64(fileAttribData.nFileSizeLow,fileAttribData.nFileSizeHigh) );
	}

	if ( statMask & File::smAttributes ) {
		file->internal_setFileAttributes( Win32FilePeer::convertAttributesFromSystemSpecific( fileAttribData.dwFileAttributes ) );
	}

	if ( statMask & File::smMaskDateAll ) {
		if ( statMask & File::smDateCreation ) {
			file->internal_setCreationDate( Win32FilePeer::convertFileTimeToDateTime( fileAttribData.ftCreationTime ) );
		}

		if ( statMask & File::smDateAccess ) {
			file->internal_setAccessDate( Win32FilePeer::convertFileTimeToDateTime( fileAttribData.ftLastAccessTime ) );
		}

		if ( statMask & File::smDateModified ) {
			file->internal_setModifiedDate( Win32FilePeer::convertFileTimeToDateTime( fileAttribData.ftLastWriteTime ) );
		}

	}

	// we are ok if here
	file->internal_addToStatMask( statMask );
}

/*static*/ File* Win32FilePeer::updateFindDataInfos( File* file, Win32FindData* findData, File::StatMask statMask/*=File::smMaskAll*/ )
{
	// throw in copyFromAttributeData if errors

	file->internal_removeFromStatMask( statMask );

	WIN32_FILE_ATTRIBUTE_DATA fileAttribData;
	if ( System::isUnicodeEnabled() ) {
			Win32FindDataW* w = ((Win32FindDataW*)findData);
			WIN32_FIND_DATAW& dataW2 = w->findData_ ;

			WIN32_FIND_DATAW& dataW = ((Win32FindDataW*)findData)->findData_ ;

			file->internal_setFileName( dataW.cFileName );

      fileAttribData.dwFileAttributes = dataW.dwFileAttributes ;
      fileAttribData.ftCreationTime   = dataW.ftCreationTime   ;
      fileAttribData.ftLastAccessTime = dataW.ftLastAccessTime ;
      fileAttribData.ftLastWriteTime  = dataW.ftLastWriteTime  ;
      fileAttribData.nFileSizeHigh    = dataW.nFileSizeHigh    ;
      fileAttribData.nFileSizeLow     = dataW.nFileSizeLow     ;

			copyFromAttributeData( file, fileAttribData, statMask );
	} else {
			WIN32_FIND_DATAA& dataA = ((Win32FindDataA*)findData)->findData_ ;

			file->internal_setFileName( dataA.cFileName );

      fileAttribData.dwFileAttributes = dataA.dwFileAttributes ;
      fileAttribData.ftCreationTime   = dataA.ftCreationTime   ;
      fileAttribData.ftLastAccessTime = dataA.ftLastAccessTime ;
      fileAttribData.ftLastWriteTime  = dataA.ftLastWriteTime  ;
      fileAttribData.nFileSizeHigh    = dataA.nFileSizeHigh    ;
      fileAttribData.nFileSizeLow     = dataA.nFileSizeLow     ;

			copyFromAttributeData( file, fileAttribData, statMask );
	}

	//file->fileType_          = 0;
	//file->creatorType_       = 0;
	//file->finderFlags_       = 0;

	file->internal_addToStatMask( statMask );

	return file;
}

void Win32FilePeer::updateStat( File::StatMask statMask/*=File::smMaskAll*/ )
{
	// this is very similar to updateFindDataInfos but using a different data structure

	VCF_ASSERT( !FilePath::getPathName( getName(), true ).empty() );

	WIN32_FILE_ATTRIBUTE_DATA fileAttribData;

	file_->internal_removeFromStatMask( statMask );

	int res;
	if ( System::isUnicodeEnabled() ) {
		if ( res = ::GetFileAttributesExW( getName().c_str(), ::GetFileExInfoStandard, (void*)&fileAttribData ) ) {
			copyFromAttributeData( file_, fileAttribData, statMask );
		}
	} else {
		if ( res = ::GetFileAttributesExA( getName().ansi_c_str(), ::GetFileExInfoStandard, (void*)&fileAttribData ) ) {
			copyFromAttributeData( file_, fileAttribData, statMask );
		}
	}

	if( !res ) {
		String error = "updateStat: " + VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw BasicException( error );
	}
}

/*virtual*/ void Win32FilePeer::setFileAttributes( const File::FileAttributes fileAttributes )
{
	file_->internal_removeFromStatMask( File::smAttributes );

	try {
		bool unicodeEnabled = System::isUnicodeEnabled();
		if ( unicodeEnabled ) {
			ulong32 dwFileAttributes = Win32FilePeer::convertAttributesToSystemSpecific( fileAttributes );
			if ( ! ::SetFileAttributesW( file_->getName().c_str(), dwFileAttributes ) ) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		} else {
			ulong32 dwFileAttributes = Win32FilePeer::convertAttributesToSystemSpecific( fileAttributes );
			if ( ! ::SetFileAttributesA( file_->getName().ansi_c_str(), dwFileAttributes ) ) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		}
	}
	catch ( BasicException& /*be*/ ) {
		throw; // re-throw
	}
	catch( ... ) {
		String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw RuntimeException( MAKE_ERROR_MSG_2( error ) );
	}

	file_->internal_setFileAttributes( fileAttributes );
	file_->internal_addToStatMask( File::smAttributes );
	return;
}

/*virtual*/ void Win32FilePeer::setDateModified( const DateTime& dateModified )
{
	// see CFile::SetStatus(LPCTSTR lpszFileName, const CFileStatus& status)
	// see AfxTimeToFileTime;

	file_->internal_removeFromStatMask( File::smDateModified );

	try {
		bool unicodeEnabled = System::isUnicodeEnabled();

		// DateTime --> systemTime
		SYSTEMTIME st;
		FILETIME   ftUTC;
		HANDLE hFile = NULL;

		st.wYear = dateModified.getYear();
		st.wMonth = dateModified.getMonth();
		st.wDayOfWeek = dateModified.getWeekDay();
		st.wDay = dateModified.getDay();
		st.wHour = dateModified.getHour();
		st.wMinute = dateModified.getMinute();
		st.wSecond = dateModified.getSeconds();
		st.wMilliseconds = dateModified.getMilliSeconds();

		// convert system time to filetime
		if ( !::SystemTimeToFileTime( &st, &ftUTC ) ) { // stUTC --> ftUTC
			String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
			throw BasicException( error );
		}

		if ( unicodeEnabled ) {
			hFile = ::CreateFileW( file_->getName().c_str(), GENERIC_READ|GENERIC_WRITE,
				FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == INVALID_HANDLE_VALUE) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		} 
		else {			
			hFile = ::CreateFileA( file_->getName().ansi_c_str(), GENERIC_READ|GENERIC_WRITE,
				FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == INVALID_HANDLE_VALUE) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		}

		if (! ::SetFileTime( hFile, NULL, NULL, &ftUTC ) ) {
			String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
			throw BasicException( error );
		}

		if (! ::CloseHandle(hFile)) {
			String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
			throw BasicException( error );
		}

	}
	catch ( BasicException& /*be*/ ) {
		throw; // re-throw
	}
	catch( ... ) {
		String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw RuntimeException( MAKE_ERROR_MSG_2( error ) );
	}

	file_->internal_setModifiedDate( dateModified );
	file_->internal_addToStatMask( File::smDateModified );
}

/*static*/ ulong32 Win32FilePeer::convertAttributesFromSystemSpecific( const ulong32& dwAttributes )
{
	ulong32 fileAttributes = File::faNone;

	if ( dwAttributes & FILE_ATTRIBUTE_READONLY ) {
		fileAttributes += File::faReadOnly;
	}
	if ( dwAttributes & FILE_ATTRIBUTE_HIDDEN ) {
		fileAttributes += File::faHidden;
	}
	if ( dwAttributes & FILE_ATTRIBUTE_SYSTEM ) {
		fileAttributes += File::faSystem;
	}
	if ( dwAttributes & FILE_ATTRIBUTE_DIRECTORY ) {
		fileAttributes += File::faDirectory;
	}
	if ( dwAttributes & FILE_ATTRIBUTE_ARCHIVE ) {
		fileAttributes += File::faArchive;
	}
#if (_MSC_VER >= 1300)
	// vc7 and above
	if ( dwAttributes & FILE_ATTRIBUTE_DEVICE ) {
		fileAttributes += File::faDevice;
	}
#endif
	if ( dwAttributes & FILE_ATTRIBUTE_NORMAL ) {
		fileAttributes += File::faNormal;
	}

	return fileAttributes;
}

/*static*/ ulong32 Win32FilePeer::convertAttributesToSystemSpecific( File::FileAttributes fileAttributes )
{
	ulong32 dwAttributes = 0;

	if ( fileAttributes & File::faReadOnly ) {
		dwAttributes += FILE_ATTRIBUTE_READONLY;
	}
	if ( fileAttributes & File::faHidden ) {
		dwAttributes += FILE_ATTRIBUTE_HIDDEN;
	}
	if ( fileAttributes & File::faSystem ) {
		dwAttributes += FILE_ATTRIBUTE_SYSTEM;
	}
	if ( fileAttributes & File::faDirectory ) {
		dwAttributes += FILE_ATTRIBUTE_DIRECTORY;
	}
	if ( fileAttributes & File::faArchive ) {
		dwAttributes += FILE_ATTRIBUTE_ARCHIVE;
	}
#if (_MSC_VER >= 1300)
	// vc7 and above
	if ( fileAttributes & File::faDevice ) {
		dwAttributes += FILE_ATTRIBUTE_DEVICE;
	}
#endif
	if ( fileAttributes & File::faNormal ) {
		dwAttributes += FILE_ATTRIBUTE_NORMAL;
	}

	return dwAttributes;
}

void Win32FilePeer::open()
{
}

void Win32FilePeer::openWithFileName( const String& fileName )
{
}

void Win32FilePeer::openWithRights( const String& fileName, File::OpenFlags openFlags/*=File::ofRead*/, File::ShareFlags shareFlags/*=File::shMaskAny*/ )
{
}

void Win32FilePeer::close()
{
}

void Win32FilePeer::remove()
{
	if ( NULL != fileHandle_ ){
		::CloseHandle( fileHandle_ );
		fileHandle_ = NULL;
	}

	String filename = getName();
	if ( filename[filename.size()-1] == '\\' ) {
		BOOL res = FALSE;
		if ( System::isUnicodeEnabled() ) {
			res = ::RemoveDirectoryW( filename.c_str() );
		}
		else {
			res = ::RemoveDirectoryA( filename.ansi_c_str() );
		}

		if ( !res ) {
			throw BasicFileError( "Unable to remove directory \"" + filename + "\",\nprobably because the directory still contains objects." );
		}
	}
	else {
		BOOL res = FALSE;
		if ( System::isUnicodeEnabled() ) {
			res = ::DeleteFileW( filename.c_str() );
		}
		else {
			res = ::DeleteFileA( filename.ansi_c_str() );
		}

		if ( !res ) {
			throw BasicFileError( "Unable to remove file \"" + filename + "\"." );
		}
	}
}

void Win32FilePeer::move( const String& newFileName )
{
}

void Win32FilePeer::copyTo( const String& copyFileName )
{
	BOOL res = FALSE;

	if ( System::isUnicodeEnabled() ) {
		res = ::CopyFileW( getName().c_str(), FilePath::transformToOSSpecific( copyFileName ).c_str(), FALSE );
	}
	else {
		res = ::CopyFileA( getName().ansi_c_str(), FilePath::transformToOSSpecific( copyFileName ).ansi_c_str(), FALSE );
	}

	if ( ! res ) {
		throw BasicFileError("File \"" + copyFileName + "\" already exists." );
	}

}


/*static*/ DateTime Win32FilePeer::convertFileTimeToDateTime( const FILETIME& ft )
{
	bool ok = false;
	DateTime dt;

	SYSTEMTIME st;

	// ft --> st
	if ( ::FileTimeToSystemTime( &ft, &st ) ) {
		dt.set( st.wYear, st.wMonth, st.wDay,
							st.wHour, st.wMinute, st.wSecond, 
							st.wMilliseconds );
		ok = true;
	}

	if ( !ok ) {
		String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw BasicException( error );
	}

	return dt;
}

/*static*/ DateTime Win32FilePeer::convertUtcFileTimeToLocalDateTime( const FILETIME& ftUtc )
{
	bool ok = false;
	FILETIME ftLoc;
	SYSTEMTIME stLoc;
	DateTime dt;

	// ftUTC --> ftLocal
	// see help of VisualStudio.net for "File Times", at the end, though 
	if ( ::FileTimeToLocalFileTime( &ftUtc, &ftLoc ) ) {
		// ftLocal --> stLocal
		if ( ::FileTimeToSystemTime( &ftLoc, &stLoc ) ) {
			dt.set( stLoc.wYear, stLoc.wMonth, stLoc.wDay,
								stLoc.wHour, stLoc.wMinute, stLoc.wSecond, 
								stLoc.wMilliseconds );
			ok = true;
		}
	}

	if ( !ok ) {
		String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw BasicException( error );
	}

	return dt;
}

/*static*/ String Win32FilePeer::getAlternateFileName( const String& fileName )
{
	String dosName;

	try {
		bool unicodeEnabled = System::isUnicodeEnabled();
		if ( unicodeEnabled ) {
			WIN32_FIND_DATAW findData;
			HANDLE searchHandle = ::FindFirstFileW( fileName.c_str(), &findData );
			if ( INVALID_HANDLE_VALUE != searchHandle ) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
			dosName = findData.cAlternateFileName;
		} else {
			WIN32_FIND_DATAA findData;
			HANDLE searchHandle = ::FindFirstFileA( fileName.ansi_c_str(), &findData );
			dosName = findData.cAlternateFileName;
			if ( INVALID_HANDLE_VALUE != searchHandle ) {
				String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
				throw BasicException( error );
			}
		}
	}
	catch( ... ) {
		String error = VCFWin32::Win32Utils::getErrorString( GetLastError() );
		throw RuntimeException( MAKE_ERROR_MSG_2( error ) );
	}

	return dosName;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/07/18 14:45:19  ddiego
*integrated Marcello's new File/Directory API changes into both
*the FoundationKit and the ApplicationKit. Many, many thanks go out
*to Marcello for a great job with this. This adds much better file searching
*capabilities, with many options for how to use it and extend it in the
*future.
*
*Revision 1.1.2.1  2004/06/05 01:18:41  marcelloptr
*moved some files to the directory where they logically belong
*
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


