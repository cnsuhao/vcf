#ifndef _VCF_INTERNETKIT_H__
#define _VCF_INTERNETKIT_H__

//InternetKit.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif




/**
Handle the extension based on the compiler
*/
# if defined(__INTEL_COMPILER)
#   define _LIB_CPLVERNUM "icl7"
# elif defined(__ICL)
#   define _LIB_CPLVERNUM "icl6"
# else
#   if (_MSC_VER >= 1310)
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
#  ifdef __BORLANDC__
#     define _LIB_CPLVERNUM "bcc"
#  endif
# endif



//auto link stuff
#if defined(_MSC_VER) || defined(__BORLANDC__)
	#ifdef USE_INTERNETKIT_DLL
		#define INTERNETKIT_DLL
		// using dynamic link library
		#ifdef _DEBUG
			#pragma comment(lib, "InternetKit_"_LIB_CPLVERNUM"_d.lib")
		#else
			#pragma comment(lib, "InternetKit_"_LIB_CPLVERNUM".lib")
		#endif
	#elif defined USE_INTERNETKIT_LIB
		// using statically linked library
		#ifdef _DEBUG
			#pragma comment(lib, "InternetKit_"_LIB_CPLVERNUM"_sd.lib")
		#else
			#pragma comment(lib, "InternetKit_"_LIB_CPLVERNUM"_s.lib")
		#endif
	#endif

	//make sure to link to the urlmon lib
	#pragma comment(lib, "urlmon.lib")
#endif //_MSC_VER



//export crap
#ifdef INTERNETKIT_DLL
	#if defined(INTERNETKIT_EXPORTS)
		#define INTERNETKIT_API __declspec(dllexport)
	#else
		#define INTERNETKIT_API __declspec(dllimport)
	#endif
#else
	#define INTERNETKIT_API
#endif //INTERNETKIT_DLL



#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/InternetKit/InternetToolkit.h"
#include "vcf/InternetKit/URL.h"


namespace VCF {

	class INTERNETKIT_API InternetKit {
	public:
		
		static void init( int argc, char** argv );

		static void terminate();	
	};

};


#endif //_VCF_INTERNETKIT_H__