#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _OPENGLKIT_H__
#define _OPENGLKIT_H__

/**
*Copyright (c) 2004, Alan Fischer
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
* Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in 
* the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

/**
All of this nonsense is to properly declare the OPENGLKIT_API
macro so that we'll export/import classes as needed for 
dll builds.
*/
#ifdef _MSC_VER
  #ifndef OPENGLKIT_DLL
    #define OPENGLKIT_API
  #else
    #ifdef OPENGLKIT_EXPORTS
      #define OPENGLKIT_API __declspec(dllexport)
    #else 
      #define OPENGLKIT_API __declspec(dllimport)
    #endif 
  #endif
#else
  #define OPENGLKIT_API
#endif


/**
Handle the extension based on the compiler
*/
# if defined(__ICL)
#   define _LIB_CPLVERNUM "icl6"
# else
#   if (_MSC_VER >= 1310)
#     define _LIB_CPLVERNUM "vc71"
#   elif (_MSC_VER >= 1300)
#     define _LIB_CPLVERNUM "vc70"
#   elif (_MSC_VER >= 1200)
#     define _LIB_CPLVERNUM "vc6"
#   elif (_MSC_VER >= 1100)
#     define _LIB_CPLVERNUM "vc5"
#   endif
# endif



/**
All of this is here so that if we use this kit in our programs, all we
have to do is pull in this one file (OpenGLKit.h) and we'll automatically
link to the correct library! This does mean that our app that uses this 
kit needs to have either "USE_OPENGLKIT_DLL" defined or "USE_OPENGLKIT_LIB"
defined to use the DLL or static libraries.
*/
#ifdef _MSC_VER
	#ifdef USE_OPENGLKIT_DLL
		// using dynamic link library
		#ifdef _DEBUG
			#pragma comment(lib, "OpenGLKit_"_LIB_CPLVERNUM"_d.lib")
		#else
			#pragma comment(lib, "OpenGLKit_"_LIB_CPLVERNUM".lib")
		#endif
	#elif USE_OPENGLKIT_LIB
		// using statically linked library
		#ifdef _DEBUG
			#pragma comment(lib, "OpenGLKit_"_LIB_CPLVERNUM"_sd.lib")
		#else
			#pragma comment(lib, "OpenGLKit_"_LIB_CPLVERNUM"_s.lib")
		#endif
	#endif

	//make sure to link to the open gl libs
	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "glu32.lib")
#endif //_MSC_VER


#include "vcf/ApplicationKit/ApplicationKit.h"

#include "vcf/OpenGLKit/OpenGLPeer.h"
#include "vcf/OpenGLKit/OpenGLContext.h"
#include "vcf/OpenGLKit/OpenGLControlContext.h"
#include "vcf/OpenGLKit/OpenGLControl.h"


namespace VCF {

class  OPENGLKIT_API OpenGLKit {
public:
	static void init( int argc, char** argv ){;}
 
	static void terminate(){;}
};

};



#endif //_OPENGLKIT_H__