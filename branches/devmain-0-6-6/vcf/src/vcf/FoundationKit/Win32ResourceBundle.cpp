//Win32ResourceBundle.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/ResourceBundlePeer.h"
#include "vcf/FoundationKit/Win32ResourceBundle.h"


using namespace VCF;


BOOL CALLBACK Win32ResourceBundle_EnumResTypeProc( HMODULE hModule, LPTSTR lpszType, LPARAM lParam );
BOOL CALLBACK Win32ResourceBundle_EnumResNameProc( HMODULE hModule, LPCTSTR lpszType, LPTSTR lpszName, LPARAM lParam );


#define RT_RCDATA_W           MAKEINTRESOURCEW(10)
#define RT_RCDATA_A           MAKEINTRESOURCEA(10)


static bool foundResName = false;
static String foundResType="Hello";



Win32ResourceBundle::Win32ResourceBundle()
{
	
	//appPeer_ = NULL;
}

Win32ResourceBundle::~Win32ResourceBundle()
{
	
}

String Win32ResourceBundle::getString( const String& resourceName )
{
	/**
	Assume an exe resource by default?
	*/

	bool failedToFindRes = true;
	HINSTANCE hinst = getResourceInstance();
	String result;
	HRSRC resHandle = NULL;
	if ( System::isUnicodeEnabled() ) {
		resHandle = ::FindResourceW( hinst, resourceName.c_str(), RT_RCDATA_W );
	}
	else {
		resHandle = ::FindResourceA( hinst, resourceName.ansi_c_str(), RT_RCDATA_A );
	}

	if ( NULL != resHandle ){
		HGLOBAL	data = ::LoadResource( hinst, resHandle );
		if ( NULL != data ){
			TCHAR* strData = (TCHAR*)::LockResource( data );
			result = strData;
			failedToFindRes = false;
			::FreeResource( data );
		}
	}
	else {		
		//try and see if the resourceName is an int id and find it via 
		//throw exception- resource not found !!!!
		uint32 stringID = 0;
		try {
			StringUtils::fromStringAsUInt(resourceName);
		}
		catch( ... ) {
			result = L"";
			return result;
		}


		if ( stringID > 0 ) {
			if ( System::isUnicodeEnabled() ) {
				wchar_t tmp[256];
				int ret = ::LoadStringW( hinst, stringID, tmp, 255 );
				if ( ret ) {
					tmp[ret] = 0;
					result = tmp;
					failedToFindRes = false;
				}				
			}
			else {
				char tmp[256];
				int ret = ::LoadStringA( hinst, stringID, tmp, 255 );
				if ( ret ) {
					tmp[ret] = 0;
					result = tmp;
					failedToFindRes = false;
				}
			}			
		}
		else {
			failedToFindRes = true;
		}

		if ( failedToFindRes ) {
			//throw exception???
		}
	}


	if ( failedToFindRes ) {
		//look in the resource .strings file 
		
		result = System::getCurrentThreadLocale()->translate( resourceName );		
	}

	return result;
}

String Win32ResourceBundle::getVFF( const String& resourceName )
{
	String result;
	bool failedToFindRes = true;

	HRSRC resHandle = NULL;
	if ( System::isUnicodeEnabled() ) {
		resHandle = ::FindResourceW( getResourceInstance(), resourceName.c_str(), L"VFF" );
	}
	else {
		resHandle = ::FindResourceA( getResourceInstance(), resourceName.ansi_c_str(), "VFF" );
	}

	if ( NULL != resHandle ){
		HGLOBAL	data = ::LoadResource( NULL, resHandle );
		if ( NULL != data ){
			void* dataPtr = ::LockResource( data );
			TCHAR* strData = (TCHAR*)dataPtr;
			int size = SizeofResource( getResourceInstance(), resHandle );
			result = strData;
			int resSize = result.size();
			void *tmp = dataPtr;
			/**
			*this is here to properly skip over '\0' characters in the stream
			*/
			while ( resSize < size ){
				tmp = (void*)((char*)dataPtr + resSize + 1);
				strData = (TCHAR*)tmp;
				result += "\n";
				result += strData;
				resSize = result.size();
				failedToFindRes = false;
			}
			::FreeResource( data );
		}
	}
	else {
		//throw exception- resource not found !!!!
	}


	if ( failedToFindRes ) {
		//try res directory

		String localeName = System::getCurrentThreadLocale()->getName();

		bool fileExists = false;
		String vffFile = System::findResourceDirectory() + localeName + 
					FilePath::getDirectorySeparator() +	resourceName;

		if ( File::exists( vffFile ) ) {
			fileExists = true;
		}
		else {
			vffFile += ".vff";
			if ( File::exists( vffFile ) ) {
				fileExists = true;
			}
		}

		if ( fileExists ) {
			FileInputStream fs(vffFile);

			fs >> result;
		}
	}

	return result;
}


Resource* Win32ResourceBundle::getResource( const String& resourceName )
{
	Resource* result = NULL;

	bool failedToFindRes = true;

	foundResName = false;
	foundResType = "\0";

	::EnumResourceTypes( getResourceInstance(),
		                 Win32ResourceBundle_EnumResTypeProc,
						 (LPARAM)resourceName.c_str() );
	if ( true == foundResName ){
		HRSRC resHandle = NULL;

		if ( System::isUnicodeEnabled() ) {
			resHandle = ::FindResourceW( getResourceInstance(),
			                              resourceName.c_str(),
										  foundResType.c_str() );
		}
		else {
			resHandle = ::FindResourceA( getResourceInstance(),
			                              resourceName.ansi_c_str(),
										  foundResType.ansi_c_str() );
		}

		if ( NULL != resHandle ){
			HGLOBAL	dataHandle = ::LoadResource( NULL, resHandle );
			if ( NULL != dataHandle ){
				void* data = ::LockResource( dataHandle );
				int size = ::SizeofResource( getResourceInstance(), resHandle );				
				return new Resource( data, size, resourceName );
			}
		}
		else {
			//throw exception- resource not found !!!!
		}
	}

	//if we got this far then look for files!

	String localeName = System::getCurrentThreadLocale()->getName();
	
	bool fileExists = false;
	String fileName = System::findResourceDirectory() + localeName + 
		FilePath::getDirectorySeparator() +	resourceName;
	
	if ( File::exists( fileName ) ) {
		FileInputStream fs(fileName);
		ulong32 size = fs.getSize();
		char* buf = new char[size];
		fs.read( buf, size );
		

		result = new Resource( buf, size, resourceName );
		delete [] buf;
	}

	return result;
}

BOOL CALLBACK Win32ResourceBundle_EnumResTypeProc( HMODULE hModule, LPTSTR lpszType, LPARAM lParam )
{
	
	return ::EnumResourceNames( hModule,
		                        lpszType,
								Win32ResourceBundle_EnumResNameProc,
								lParam );
}

BOOL CALLBACK Win32ResourceBundle_EnumResNameProc( HMODULE hModule, LPCTSTR lpszType, LPTSTR lpszName, LPARAM lParam )
{
	BOOL result = TRUE;
	if ( System::isUnicodeEnabled() ) {
		String resName( (UnicodeString::UniChar*)lParam );
		if ( resName == lpszName ){
			foundResName = true;
			foundResType = lpszType;
			result = FALSE;
		}
	}
	else {
		
		AnsiString resName( (UnicodeString::AnsiChar*)lParam );
		if ( resName == lpszName ){
			foundResName = true;
			foundResType = lpszType;
			result = FALSE;
		}
		
	}
	
	return result;
}

HINSTANCE Win32ResourceBundle::getResourceInstance()
{
	HINSTANCE result = ::GetModuleHandle(NULL);
	
	
	return result;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/08/27 03:50:46  ddiego
*finished off therest of the resource refactoring code. We
*can now load in resoruces either from the burned in data in the .exe
*or from resource file following the Apple bundle layout scheme.
*
*Revision 1.1.2.2  2004/08/26 04:29:28  ddiego
*added support for getting the resource directory to the System class.
*
*Revision 1.1.2.1  2004/08/21 21:06:53  ddiego
*migrated over the Resource code to the FoudationKit.
*Added support for a GraphicsResourceBundle that can get images.
*Changed the AbstractApplication class to call the System::getResourceBundle.
*Updated the various example code accordingly.
*
*Revision 1.2  2004/08/07 02:49:11  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/07/09 18:48:05  ddiego
*added locale translation support for most classes
*
*Revision 1.1.2.2  2004/04/29 03:43:16  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.16.8.1  2004/04/21 02:17:26  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.16  2003/05/17 20:37:38  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.15.2.1  2003/03/12 03:12:41  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.15  2003/02/26 04:30:51  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.14.14.1  2003/01/08 00:19:53  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.14  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.13.4.2  2002/04/27 15:52:31  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.13.4.1  2002/04/08 20:55:30  zzack
*changed include style
*
*Revision 1.13  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


