//OpenGLControl.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
//#include "VCFOpenGL.h"
using namespace VCF;

OpenGLControl::OpenGLControl():
	CustomControl( true )
{
	delete this->context_;
	context_ = NULL;
	context_ = new OpenGLControlContext( this );

	setDoubleBuffered( false );
}

OpenGLControl::~OpenGLControl()
{

}

void OpenGLControl::paint(GraphicsContext * context)
{
	CustomControl::paint( context );
	OpenGLControlContext* glCtx = dynamic_cast<OpenGLControlContext*>(context_);
	if ( NULL != glCtx ){
		glCtx->initGL();
		glViewport( 0, 0, 300, 300 );
		glLoadIdentity();
		glOrtho( 0.0f, 300.0f, 0.0f, 300.0f, 1.0f, -1.0f );
		glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );
		glColor3f( 1.0f, 0.0f, 0.0f );
		glRectf( 100.0f, 150.0f, 150.0f, 200.0f );
		auxWireTeapot( 100.0f );
		glFlush();

		glCtx->swapBuffers();
	}
}

void OpenGLControl::afterCreate( ComponentEvent* event )
{
	CustomControl::afterCreate( event );
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:14  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.8  2003/05/17 20:37:49  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.2.1  2003/03/12 03:13:17  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.7  2003/02/26 04:30:56  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.6.14.1  2003/01/08 00:20:00  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.6  2002/05/09 03:10:46  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.5.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.5  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


