

/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world. 
*/

#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"



using namespace VCF;

OSXGraphicsToolkit::OSXGraphicsToolkit()
{
	
}	

OSXGraphicsToolkit::~OSXGraphicsToolkit()
{
	
}	

ContextPeer* OSXGraphicsToolkit::internal_createContextPeer( const unsigned long& width, const unsigned long& height )
{
	return new OSXContext( width, height );
}	

ContextPeer* OSXGraphicsToolkit::internal_createContextPeer( const unsigned long& contextID )
{
	return new OSXContext( contextID );
}	

FontPeer* OSXGraphicsToolkit::internal_createFontPeer( const String& fontName )
{
	return new OSXFont( fontName );
}	

FontPeer* OSXGraphicsToolkit::internal_createFontPeer( const String& fontName, const double& pointSize )
{
	return new OSXFont( fontName, pointSize );
}	
	
OpenGLPeer* OSXGraphicsToolkit::internal_createOpenGLPeer( GraphicsContext* glContext )
{
	return NULL;
}	
	
Image* OSXGraphicsToolkit::internal_createImage( const unsigned long& width, const unsigned long& height )
{
	return new OSXImage(width, height);
}	

Image* OSXGraphicsToolkit::internal_createImage( GraphicsContext* context, Rect* rect )
{
	return new OSXImage( context, rect ) ;
}



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/21 03:27:09  ddiego
*updates for OSX porting
*
*/



  	