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


template <typename CharType >
struct VCF_VS_VERSIONINFO { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  CharType szKey[1]; 
  WORD  Padding1[1]; 
  VS_FIXEDFILEINFO Value; 
  WORD  Padding2[1]; 
  WORD  Children[1]; 
};
typedef VCF_VS_VERSIONINFO<VCF::WideChar> VS_VERSIONINFO_W;
typedef VCF_VS_VERSIONINFO<char> VS_VERSIONINFO_A;

template <typename CharType >
struct VCF_String { 
  WORD   wLength; 
  WORD   wValueLength; 
  WORD   wType; 
  CharType  szKey[1]; 
  WORD   Padding[1]; 
  WORD   Value[1]; 
}; 

typedef VCF_String<VCF::WideChar> String_W;
typedef VCF_String<char> String_A;

template <typename CharType >
struct VCF_StringTable { 
  WORD   wLength; 
  WORD   wValueLength; 
  WORD   wType; 
  CharType  szKey[1]; 
  WORD   Padding[1]; 
  VCF_String<CharType> Children[1]; 
};
typedef VCF_StringTable<VCF::WideChar> StringTable_W;
typedef VCF_StringTable<char> StringTable_A;

template <typename CharType >
struct VCF_StringFileInfo { 
  WORD        wLength; 
  WORD        wValueLength; 
  WORD        wType; 
  CharType       szKey[1]; 
  WORD        Padding[1]; 
  VCF_StringTable<CharType> Children[1]; 
};
typedef VCF_StringFileInfo<VCF::WideChar> StringFileInfo_W;
typedef VCF_StringFileInfo<char> StringFileInfo_A;

template <typename CharType >
struct VCF_Var { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  CharType szKey[1]; 
  WORD  Padding[1]; 
  DWORD Value[1]; 
}; 
typedef VCF_Var<VCF::WideChar> Var_W;
typedef VCF_Var<char> Var_A;

template <typename CharType >
struct VCF_VarFileInfo { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  CharType szKey[1]; 
  WORD  Padding[1]; 
  VCF_Var<CharType>  Children[1]; 
}; 
typedef VCF_VarFileInfo<VCF::WideChar> VarFileInfo_W;
typedef VCF_VarFileInfo<char> VarFileInfo_A;


typedef std::map<String,String> VersionMap;


/*

 * Copyright (c) 2002 by Ted Peck <tpeck@roundwave.com>
 * Permission is given by the author to freely redistribute and include
 * this code in any program as long as this credit is given where due.
 *
 * THIS CODE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTY
 * OF ANY KIND, EITHER EXPRESSED OR IMPLIED. IN PARTICULAR, NO WARRANTY IS MADE
 * THAT THE CODE IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
 * OR NON-INFRINGING. IN NO EVENT WILL THE AUTHOR BE LIABLE FOR ANY COSTS OR DAMAGES 
 * ARISING FROM ANY USE OF THIS CODE. NO USE OF THIS CODE IS AUTHORIZED EXCEPT UNDER
 * THIS DISCLAIMER.
 *
 * Use at your own risk!
 
struct VS_VERSIONINFO { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  WCHAR szKey[1]; 
  WORD  Padding1[1]; 
  VS_FIXEDFILEINFO Value; 
  WORD  Padding2[1]; 
  WORD  Children[1]; 
};

struct String { 
  WORD   wLength; 
  WORD   wValueLength; 
  WORD   wType; 
  WCHAR  szKey[1]; 
  WORD   Padding[1]; 
  WORD   Value[1]; 
}; 

struct StringTable { 
  WORD   wLength; 
  WORD   wValueLength; 
  WORD   wType; 
  WCHAR  szKey[1]; 
  WORD   Padding[1]; 
  String Children[1]; 
};

struct StringFileInfo { 
  WORD        wLength; 
  WORD        wValueLength; 
  WORD        wType; 
  WCHAR       szKey[1]; 
  WORD        Padding[1]; 
  StringTable Children[1]; 
};

struct Var { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  WCHAR szKey[1]; 
  WORD  Padding[1]; 
  DWORD Value[1]; 
}; 

struct VarFileInfo { 
  WORD  wLength; 
  WORD  wValueLength; 
  WORD  wType; 
  WCHAR szKey[1]; 
  WORD  Padding[1]; 
  Var   Children[1]; 
}; 

// ----------------------------------------------------------------------------

int showVer(void* pVer, DWORD size)
{
	// Interpret the VS_VERSIONINFO header pseudo-struct
	VS_VERSIONINFO* pVS = (VS_VERSIONINFO*)pVer;
#define roundoffs(a,b,r)	(((byte*)(b) - (byte*)(a) + ((r)-1)) & ~((r)-1))
#define roundpos(b, a, r)	(((byte*)(a))+roundoffs(a,b,r))
//	byte* nEndRaw   = roundpos((((byte*)pVer) + size), pVer, 4);
//	byte* nEndNamed = roundpos((((byte*) pVS) + pVS->wLength), pVS, 4);
//	ASSERT(nEndRaw == nEndNamed); // size reported from GetFileVersionInfoSize is much padded for some reason...

	ASSERT(!wcscmp(pVS->szKey, L"VS_VERSION_INFO"));
	printf(" (type:%d)\n", pVS->wType);
	byte* pVt = (byte*) &pVS->szKey[wcslen(pVS->szKey)+1];
	VS_FIXEDFILEINFO* pValue = (VS_FIXEDFILEINFO*) roundpos(pVt, pVS, 4);
	if (pVS->wValueLength) {
		showFIXEDFILEINFO(pValue);	// Show the 'Value' element
	}
	// Iterate over the 'Children' elements of VS_VERSIONINFO (either StringFileInfo or VarFileInfo)
	StringFileInfo* pSFI = (StringFileInfo*) roundpos(((byte*)pValue) + pVS->wValueLength, pValue, 4);
	for ( ; ((byte*) pSFI) < (((byte*) pVS) + pVS->wLength); pSFI = (StringFileInfo*)roundpos((((byte*) pSFI) + pSFI->wLength), pSFI, 4)) { // StringFileInfo / VarFileInfo
		if (!wcscmp(pSFI->szKey, L"StringFileInfo")) {
			// The current child is a StringFileInfo element
			ASSERT(1 == pSFI->wType);
			ASSERT(!pSFI->wValueLength);
			// Iterate through the StringTable elements of StringFileInfo
			StringTable* pST = (StringTable*) roundpos(&pSFI->szKey[wcslen(pSFI->szKey)+1], pSFI, 4);
			for ( ; ((byte*) pST) < (((byte*) pSFI) + pSFI->wLength); pST = (StringTable*)roundpos((((byte*) pST) + pST->wLength), pST, 4)) {
				printf(" LangID: %S\n", pST->szKey);
				ASSERT(!pST->wValueLength);
				// Iterate through the String elements of StringTable
				String* pS = (String*) roundpos(&pST->szKey[wcslen(pST->szKey)+1], pST, 4);
				for ( ; ((byte*) pS) < (((byte*) pST) + pST->wLength); pS = (String*) roundpos((((byte*) pS) + pS->wLength), pS, 4)) {
					wchar_t* psVal = (wchar_t*) roundpos(&pS->szKey[wcslen(pS->szKey)+1], pS, 4);
					printf("  %-18S: %.*S\n", pS->szKey, pS->wValueLength, psVal); // print <sKey> : <sValue>
				}
			}
		}
		else {
			// The current child is a VarFileInfo element
			ASSERT(1 == pSFI->wType); // ?? it just seems to be this way...
			VarFileInfo* pVFI = (VarFileInfo*) pSFI;
			ASSERT(!wcscmp(pVFI->szKey, L"VarFileInfo"));
			ASSERT(!pVFI->wValueLength);
			// Iterate through the Var elements of VarFileInfo (there should be only one, but just in case...)
			Var* pV = (Var*) roundpos(&pVFI->szKey[wcslen(pVFI->szKey)+1], pVFI, 4);
			for ( ; ((byte*) pV) < (((byte*) pVFI) + pVFI->wLength); pV = (Var*)roundpos((((byte*) pV) + pV->wLength), pV, 4)) {
				printf(" %S: ", pV->szKey);
				// Iterate through the array of pairs of 16-bit language ID values that make up the standard 'Translation' VarFileInfo element.
				WORD* pwV = (WORD*) roundpos(&pV->szKey[wcslen(pV->szKey)+1], pV, 4);
				for (WORD* wpos = pwV ; ((byte*) wpos) < (((byte*) pwV) + pV->wValueLength); wpos+=2) {
					printf("%04x%04x ", (int)*wpos++, (int)(*(wpos+1)));
				}
				printf("\n");
			}
		}
	}
	ASSERT((byte*) pSFI == roundpos((((byte*) pVS) + pVS->wLength), pVS, 4));
	return pValue->dwFileVersionMS; // !!! return major version number
}
*/

void getVersionInfoW( VersionMap& map, HINSTANCE instance )
{
	VCF::WideChar fileName[MAX_PATH];
	::GetModuleFileNameW( instance, fileName, MAX_PATH );

	DWORD dummy;
	DWORD size = GetFileVersionInfoSizeW( fileName, &dummy);
	unsigned char* buf = new unsigned char[size];
	memset(buf, 0, size);

	

	if ( !GetFileVersionInfoW(fileName, 0, size, buf) ) {
		return;
	}

	VS_VERSIONINFO_W* versionInfo = (VS_VERSIONINFO_W*)buf;


}

ProgramInfo* Win32ResourceBundle::getProgramInfo()
{
	ProgramInfo* result = NULL;

	return result;
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.4  2004/09/15 21:14:28  ddiego
*added support for getting program info from resource bundle.
*
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


