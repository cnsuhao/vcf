
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

// Basic3DBorder.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"

using namespace VCF;


Basic3DBorder::Basic3DBorder()
{
	
}

Basic3DBorder::~Basic3DBorder()
{
	
}

Rect Basic3DBorder::getClientRect( Control* component )
{
	Rect result;
	if ( NULL != component ){
		result = component->getClientBounds( false );
		result.inflate( -2.0, -2.0 );
	}
	return result;
}

void Basic3DBorder::paint( Rect* bounds, GraphicsContext* context )
{
	if ( NULL != bounds ){ 
		
		Color* hilight = GraphicsToolkit::getSystemColor( SYSCOLOR_HIGHLIGHT );
		
		Color* shadow = GraphicsToolkit::getSystemColor( SYSCOLOR_SHADOW );
		
		Color* face = GraphicsToolkit::getSystemColor( SYSCOLOR_FACE );
		

		
		context->rectangle( bounds->left_, bounds->top_, bounds->right_, bounds->bottom_ );
		context->setColor( face );
		context->fillPath();	
		
		
		context->moveTo( bounds->left_+1, bounds->bottom_-2 );	
		context->lineTo( bounds->left_+1, bounds->top_+1 );	
		context->lineTo( bounds->right_-2, bounds->top_+1 );
		
		context->setColor( hilight );
		
		context->strokePath();
		
		context->moveTo( bounds->right_-2, bounds->top_+1 );	
		context->lineTo( bounds->right_-2, bounds->bottom_-2 );	
		context->lineTo( bounds->left_+1, bounds->bottom_-2 );
		
		
		context->setColor( shadow );
		context->strokePath();
		
		context->moveTo( bounds->right_-1, bounds->top_ );	
		context->lineTo( bounds->right_-1, bounds->bottom_-1 );	
		context->lineTo( bounds->left_, bounds->bottom_-1 );

		context->setColor( &Color(0.0,0.0,0.0) );
		context->strokePath();
	}
}

void Basic3DBorder::paint( Control* component, GraphicsContext* context )
{
	if ( NULL == component ){
		//throw exception
	}
	Rect bounds = component->getClientBounds(false);
	
	if ( !bounds.isEmpty() ) {
		paint( &bounds, context );
	}
	
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:13  ddiego
*migration towards new directory structure
*
*Revision 1.16  2004/04/03 15:48:46  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.15.2.1  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*Revision 1.15  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.14.2.1  2003/08/18 19:52:38  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.14  2003/08/09 02:56:45  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.13.2.1  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.13  2003/05/17 20:37:19  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.12.2.3  2003/04/17 04:29:50  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.12.2.2  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.12.2.1  2003/03/12 03:11:59  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.12  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.11.2.2  2002/12/28 01:56:21  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.11.2.1  2002/12/27 23:04:46  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.11  2002/11/18 00:46:08  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.10.10.2  2002/10/08 04:16:57  ddiego
*fixed a bug in the getClientBounds() that caused a stack overflow! DOH!
*further additions to the TemplateNewClassDlg to sync the various file names
*in the dialog to the lcass name
*
*Revision 1.10.10.1  2002/10/01 20:34:59  ddiego
*borders
*
*Revision 1.10  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.9.4.1  2002/04/08 20:55:30  zzack
*changed include style
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/



