//OpenGLContext.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/OpenGLKit/OpenGLKit.h"
#include "vcf/OpenGLKit/OpenGLContext.h"
#include "vcf/OpenGLKit/OpenGLToolkit.h"


using namespace VCF;


OpenGLContext::OpenGLContext( const unsigned long& width, const unsigned long& height ):
	GraphicsContext( width, height )
{
	init();
}

/*
OpenGLContext::OpenGLContext( Control* control ):
	GraphicsContext( control )
{
	init();
}
*/

OpenGLContext::OpenGLContext( const long& contextID ):
	GraphicsContext( contextID )
{
	init();
}

OpenGLContext::~OpenGLContext()
{

}

void OpenGLContext::init()
{
	glPeer_ = OpenGLToolkit::createOpenGLPeer( this );
}

void OpenGLContext::initGL()
{
	this->glPeer_->initGL();
}

void OpenGLContext::swapBuffers()
{
	this->glPeer_->swapBuffers();
}

void OpenGLContext::makeCurrent()
{
	this->glPeer_->makeCurrent();
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/06/06 07:05:34  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 21:13:58  ddiego
*made a few changes to the new OpenGLKit files, adjusting where the
*CVS log was put, and changed a few cases for the export-import definition
*was used. Also added the two projects to the vcfAllProject workspace
*and added the script generated VC7 and VC71 projects as well.
*
*Revision 1.1.2.1  2004/04/29 15:38:12  pallindo
*Initial attempt at an OpenGLKit
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.8  2003/05/17 20:37:22  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.2.1  2003/03/12 03:12:04  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.7  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.6.20.1  2003/01/08 00:19:50  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.6  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

