//OSXGraphicsToolkit.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
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
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
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


