
/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
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

#include "vcf/OpenGLKit/OpenGLKit.h"
#include "vcf/GraphicsKit/ContextPeer.h"
#include "vcf/GraphicsKit/Win32Context.h"
#include "vcf/OpenGLKit/Win32OpenGLPeer.h"
#include "vcf/OpenGLKit/VCFOpenGL.h"


using namespace VCF;

Win32OpenGLPeer::Win32OpenGLPeer( GraphicsContext* glContext )
{
	this->glContext_ = glContext;
	isInitialized_ = false;
}

Win32OpenGLPeer::~Win32OpenGLPeer()
{
	if ( NULL != glContext_ ){
		Win32Context* win32Ctx = dynamic_cast<Win32Context*>(glContext_->getPeer());
		if ( NULL == win32Ctx ){
			//throw exception - we are screwed !!!!
		}
		HDC dc = (HDC)win32Ctx->getContextID();
		wglMakeCurrent( dc, NULL );
		wglDeleteContext( hrc_ );
	}
}

void Win32OpenGLPeer::initGL()
{
	if ( true == isInitialized_ ){
		return;
	}
	if ( NULL != glContext_ ){
		Win32Context* win32Ctx = dynamic_cast<Win32Context*>(glContext_->getPeer());
		if ( NULL == win32Ctx ){
			//throw exception - we are screwed !!!!
		}
		
		win32Ctx->checkHandle();

		HDC dc = (HDC)win32Ctx->getContextID();
		if ( NULL != dc ){
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
					1,                              // version number
					PFD_DRAW_TO_WINDOW |            // support window
					PFD_SUPPORT_OPENGL |          // support OpenGL
					PFD_DOUBLEBUFFER,             // double buffered
					PFD_TYPE_RGBA,                  // RGBA type
					24,                             // 24-bit color depth
					0, 0, 0, 0, 0, 0,               // color bits ignored
					0,                              // no alpha buffer
					0,                              // shift bit ignored
					0,                              // no accumulation buffer
					0, 0, 0, 0,                     // accum bits ignored
					32,                             // 32-bit z-buffer
					0,                              // no stencil buffer
					0,                              // no auxiliary buffer
					PFD_MAIN_PLANE,                 // main layer
					0,                              // reserved
					0, 0, 0                         // layer masks ignored
			};
			
			int pixelformat = ChoosePixelFormat( dc, &pfd );
			if ( pixelformat == 0 ){
				//throw exception
				pixelformat = GetPixelFormat( dc ); 
				DescribePixelFormat( dc, pixelformat, 
					                 sizeof(PIXELFORMATDESCRIPTOR), &pfd); 

			}
			
			if ( FALSE == SetPixelFormat( dc, pixelformat, &pfd ) ){
				//throw exception
			}
			
			hrc_ = wglCreateContext( dc );
			isInitialized_ = ( wglMakeCurrent( dc, hrc_ ) ) ? true : false;
			win32Ctx->releaseHandle();
		}
	}
}

void Win32OpenGLPeer::swapBuffers()
{
	if ( NULL != glContext_ ){
		Win32Context* win32Ctx = dynamic_cast<Win32Context*>(glContext_->getPeer());
		if ( NULL == win32Ctx ){
			//throw exception - we are screwed !!!!
		}
		win32Ctx->checkHandle();

		HDC dc = (HDC)win32Ctx->getContextID();		

		::SwapBuffers( dc );

		win32Ctx->releaseHandle();
	}
}

void Win32OpenGLPeer::makeCurrent()
{
	if ( NULL != glContext_ ){
		Win32Context* win32Ctx = dynamic_cast<Win32Context*>(glContext_->getPeer());
		if ( NULL == win32Ctx ){
			//throw exception - we are screwed !!!!
		}
		win32Ctx->checkHandle();

		HDC dc = (HDC)win32Ctx->getContextID();

		wglMakeCurrent( dc, hrc_ );

		win32Ctx->releaseHandle();
	}
}

/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 21:13:58  ddiego
*made a few changes to the new OpenGLKit files, adjusting where the
*CVS log was put, and changed a few cases for the export-import definition
*was used. Also added the two projects to the vcfAllProject workspace
*and added the script generated VC7 and VC71 projects as well.
*
*Revision 1.1.2.1  2004/04/29 15:38:12  pallindo
*Initial attempt at an OpenGLKit
*
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.11  2003/05/17 20:37:38  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.10.16.2  2003/03/23 03:23:58  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.10.16.1  2003/03/12 03:12:40  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.10  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.9.4.1  2002/04/08 20:55:30  zzack
*changed include style
*
*Revision 1.9  2002/01/29 04:41:43  ddiego
*fixed leak in Win32Button, plus cleaned up some other GetDC stuff and
*fixed the Tab problem in Win98.
*
*Revision 1.8  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

