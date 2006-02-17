#ifndef _VCF_WIN32HTMLBROWSERSELECTLIB_H__
#define _VCF_WIN32HTMLBROWSERSELECTLIB_H__
//Win32HTMLBrowserSelectLib.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/**
*Helps linking with the right library
*/


#ifdef _LIB_CPLVERNUM
#		undef _LIB_CPLVERNUM
#endif


# if defined(__INTEL_COMPILER)
#   define _LIB_CPLVERNUM "icl7"
# elif defined(__ICL)
#   define _LIB_CPLVERNUM "icl6"
# else
#   if (_MSC_VER >= 1400)
#     define _LIB_CPLVERNUM "vc80"
#   elif (_MSC_VER >= 1310)
#     define _LIB_CPLVERNUM "vc71"
#   elif (_MSC_VER >= 1300)
#     define _LIB_CPLVERNUM "vc70"
#   elif (_MSC_VER >= 1200)
#		ifdef VCF_GTK
#			define _LIB_CPLVERNUM "gtk"
#		else
#			define _LIB_CPLVERNUM "vc6"
#		endif
#   elif (_MSC_VER >= 1100)
#     define _LIB_CPLVERNUM "vc5"
#		endif
#   ifdef __BORLANDC__
#   define _LIB_CPLVERNUM "bcc"
#   endif
#	ifdef __MWERKS__
#	define _LIB_CPLVERNUM "cw"
#	endif
#	ifdef __MINGW32__
#	define _LIB_CPLVERNUM "mingw"
#	endif
# endif


// We don't need any of this if we've disabled pragma linking
#ifndef VCF_DISABLE_PRAGMA_LINKING
#   ifdef _DEBUG
#       define WIN32HTMLBROWSER_DYNLIB		"Win32HTMLBrowser_"_LIB_CPLVERNUM"_d.dll"
#   else
#       define WIN32HTMLBROWSER_DYNLIB		"Win32HTMLBrowser_"_LIB_CPLVERNUM".dll"
#   endif
#else
#   define STRINGIZE(lex) #lex
#   define STRINGIZE2(lex) STRINGIZE(lex)
#   define WIN32HTMLBROWSER_DYNLIB STRINGIZE2(WIN32HTMLBROWSER_DYNLIB_UNQUOTED)
#endif



#ifdef WIN32HTMLBROWSER_DLL
	#if defined(WIN32HTMLBROWSER_EXPORTS)
		#define WIN32HTMLBROWSER_API __declspec(dllexport)
		#define WIN32HTMLBROWSER_EXPIMP_TEMPLATE
	#else
		#define WIN32HTMLBROWSER_API __declspec(dllimport)
		#define WIN32HTMLBROWSER_EXPIMP_TEMPLATE extern
	#endif
#else
	#define WIN32HTMLBROWSER_API
#endif //WIN32HTMLBROWSER_DLL


// does not preload the library if defined
#ifndef RUNTIME_LOADLIBRARY



#ifdef USE_WIN32HTMLBROWSER_DLL
//	using dynamic link library
#	ifdef _DEBUG
#		pragma comment(lib, "Win32HTMLBrowser_"_LIB_CPLVERNUM"_d.lib")
#	else
#		pragma comment(lib, "Win32HTMLBrowser_"_LIB_CPLVERNUM".lib")
#	endif
#elif defined USE_WIN32HTMLBROWSER_LIB
//	using statically linked library
#	ifdef _DEBUG
#		pragma comment(lib, "Win32HTMLBrowser_"_LIB_CPLVERNUM"_sd.lib")
#	else
#		pragma comment(lib, "Win32HTMLBrowser_"_LIB_CPLVERNUM"_s.lib")
#	endif
#else
//	creating the static or dynamic link library
#endif // WIN32HTMLBROWSER_LIB

#endif // RUNTIME_LOADLIBRARY


/**
*CVS Log info
*$Log$
*Revision 1.4.2.3  2006/02/17 19:09:04  kdmix
*Allows baked makefiles define WIN32HTMLBROWSER_DYNLIB with appropriate library name string.
*
*Revision 1.4.2.2  2005/11/02 04:38:23  obirsoy
*changes required for vc80 support.
*
*Revision 1.4.2.1  2005/10/22 17:04:19  ddiego
*added 2 more patches from kitovyj for mingw.
*
*Revision 1.4  2005/07/09 23:14:58  ddiego
*merging in changes from devmain-0-6-7 branch.
*
*Revision 1.3.2.1  2005/04/11 17:04:51  iamfraggle
*Changes allowing compilation of Win32 port under CodeWarrior
*
*Revision 1.3  2004/12/01 04:31:39  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.2.2.1  2004/08/17 05:01:29  marcelloptr
*improved macros for library selection
*
*Revision 1.2  2004/08/07 02:49:11  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.4  2004/07/30 17:27:14  kiklop74
*Added first release of Borland midifications for VCF
*
*Revision 1.1.2.3  2004/06/29 03:17:40  marcelloptr
*minor fixes on import/export library macros
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:20  ddiego
*migration towards new directory structure
*
*Revision 1.6.2.2  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.6.2.1  2004/04/07 21:58:12  marcelloptr
*some changes related to _LIB_CPLVERNUM
*
*Revision 1.6  2004/03/03 09:40:25  augusto_roman
*Added support for the Intel Compiler v7.1.  Mostly added new project files (icl7), plus support in select lib header files.  Also fixed GraphicsToolKit::getAvailableImageTypes
*
*Revision 1.5  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.4.4.2  2003/12/17 05:11:56  ddiego
*minors mods, mostly to support chnages to the installer and some
*problems with the html help docs abnd MSDN integration
*
*Revision 1.4.4.1  2003/08/23 02:01:28  marcelloptr
*minor fixes + automatic library selection of with vc6, vc70 and vc71
*
*Revision 1.4  2003/05/17 20:37:13  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.1  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.8.2  2002/12/27 23:04:41  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.2.8.1  2002/12/02 00:38:35  ddiego
*more fixes to get the ApplicationKit to compile under mingw. Everything now
*compiles OK at this point.
*
*Revision 1.2  2002/09/12 03:26:04  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.1.2.1  2002/07/02 06:50:01  marcelloptr
*fixes for vc6, vc7, separated builds, automatic library selection, stlport
*
*
*/


#endif // _VCF_WIN32HTMLBROWSERSELECTLIB_H__


