/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.20  2003/12/18 05:16:00  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.19.2.3  2003/09/22 01:48:04  ddiego
*some minor additions ot teh DropTarget to allow it to have multiple
*control targets
*also a few other misc fixes
*
*Revision 1.19.2.2  2003/09/05 21:03:21  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.19.2.1  2003/08/22 16:34:39  ddiego
*fixed a mistake in the tabbed pages modle and item
*
*Revision 1.19  2003/08/09 02:56:45  ddiego
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
*Revision 1.18.2.2  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.18.2.1  2003/06/30 02:53:16  ddiego
*Allow getting the selected filter from a CommonFileDialog
*Added a quitCurrentEventLoop to the UIToolkit to allow programatic
*termination of a program if there is no main window specified
*added a getTag method to the Item class
*
*Revision 1.18  2003/05/17 20:37:48  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.17.2.2  2003/03/23 03:24:00  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.17.2.1  2003/03/12 03:13:07  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.17  2003/02/26 04:30:56  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.16.8.2  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.16.8.1  2003/01/08 00:19:59  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.16  2002/09/12 03:26:06  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.15.6.1  2002/07/26 04:24:29  ddiego
*added more support for properly querying modified document, and removing the
*documents from the doc tab pages, made some changes in TabbedPages to support
*this as well
*
*Revision 1.15  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.14.4.2  2002/04/27 15:52:46  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.14.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.14  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

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
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/DefaultTabPage.h"


using namespace VCF;

DefaultTabPage::DefaultTabPage( Control* component ):
	data_(NULL),
	preferredHeight_(8),
	imageIndex_(0),
	component_(NULL),
	owningControl_(NULL),
	tag_(-1)
{

	setPageComponent( component );
}

DefaultTabPage::~DefaultTabPage()
{

}

bool DefaultTabPage::containsPoint( Point * pt )
{
	return bounds_.containsPt( pt );
}

unsigned long DefaultTabPage::getIndex()
{
	return index_;
}

void DefaultTabPage::setIndex( const unsigned long& index )
{
	index_ = index;
}

void* DefaultTabPage::getData()
{
	return data_;
}

void DefaultTabPage::setData( void* data )
{
	data_ = data;
}

Model* DefaultTabPage::getModel()
{
	return model_;
}

void DefaultTabPage::setModel( Model* model )
{
	model_ = model;
}

void DefaultTabPage::setPageName( const String& name )
{
	pageName_ = name;
	ItemEvent event( this, ITEM_EVENT_TEXT_CHANGED );
	ItemChanged.fireEvent( &event );
}

String DefaultTabPage::getPageName()
{
	return pageName_;
}

Control* DefaultTabPage::getPageComponent()
{
	return component_;
}

void DefaultTabPage::setPageComponent( Control* component )
{
	if ( NULL != component_ ){
		//component_->free();
		component_ = NULL;
	}
	component_ = component;
	
}

bool DefaultTabPage::isSelected()
{
	return selected_;
}

void DefaultTabPage::setSelected( const bool& selected )
{
	selected_ = selected;
	ItemEvent event( this, ITEM_EVENT_SELECTED );
	ItemSelected.fireEvent( &event );	
}

void DefaultTabPage::paint( GraphicsContext* context, Rect* paintRect )
{
	Color* hilite = GraphicsToolkit::getSystemColor(SYSCOLOR_HIGHLIGHT);
	Color* shadow = GraphicsToolkit::getSystemColor(SYSCOLOR_SHADOW);
	Color* face = GraphicsToolkit::getSystemColor(SYSCOLOR_FACE);
	Color* textColor = GraphicsToolkit::getSystemColor( SYSCOLOR_WINDOW_TEXT );
	Color* selectedTextColor = GraphicsToolkit::getSystemColor( SYSCOLOR_SELECTION_TEXT );
	context->setColor( shadow );
	context->rectangle( paintRect );
	context->fillPath();
	Color oldFontColor;
	
	oldFontColor = *context->getCurrentFont()->getColor();

	context->getCurrentFont()->setColor( selectedTextColor );	

	if ( true == isSelected() ) {
		context->setColor( face );
		context->rectangle( paintRect );
		context->fillPath();

		context->getCurrentFont()->setColor( textColor );
		
		context->setColor( Color::getColor( "black" ) );		
		context->moveTo( paintRect->right_-1, paintRect->top_ );
		context->lineTo( paintRect->right_-1, paintRect->bottom_ );
		context->strokePath();

		context->setColor( hilite );
		context->moveTo( paintRect->left_, paintRect->top_ );
		context->lineTo( paintRect->right_-1, paintRect->top_ );
		context->moveTo( paintRect->left_, paintRect->top_+1 );
		context->lineTo( paintRect->left_, paintRect->bottom_ );
		context->strokePath();

		context->setColor( shadow );

		context->moveTo( paintRect->right_-2, paintRect->top_+1 );
		context->lineTo( paintRect->right_-2, paintRect->bottom_ );
		context->strokePath();
	}
	else {
		context->setColor( face );
		context->moveTo( paintRect->left_, paintRect->top_ );
		context->lineTo( paintRect->left_, paintRect->bottom_ );

		context->moveTo( paintRect->right_, paintRect->top_ );
		context->lineTo( paintRect->right_, paintRect->bottom_ );

		context->strokePath();
	}

	Rect tmpR = *paintRect;
	
	tmpR.left_ = tmpR.left_ + (tmpR.getWidth()/2.0 - context->getTextWidth( pageName_ )/2.0);

	tmpR.top_ = tmpR.top_ + (tmpR.getHeight()/2.0 - context->getTextHeight( "EM" )/2.0);

	context->textBoundedBy( &tmpR, pageName_, false );

	context->getCurrentFont()->setColor( &oldFontColor );

	bounds_.setRect( paintRect->left_, paintRect->top_, paintRect->right_, paintRect->bottom_ );
}

ulong32 DefaultTabPage::getPreferredHeight()
{
	ulong32 result = preferredHeight_;
	Control* control = getPageComponent();
	if ( NULL != control ) {
		result = (ulong32)control->getContext()->getTextHeight( "EM" );
	}
	return result;	
}


void DefaultTabPage::setImageIndex( const long& imageIndex )
{
	imageIndex_ = imageIndex;
}

void DefaultTabPage::setBounds( Rect* bounds ) 
{
	bounds_ = *bounds;
}


