//TitledBorder.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/TitledBorder.h"
#include "vcf/GraphicsKit/DrawUIState.h"


using namespace VCF;

TitledBorder::TitledBorder():
	sidesToPaint_(GraphicsContext::etAllSides)
{

}


void TitledBorder::paint( Control* control, GraphicsContext* context )
{
	if ( NULL == control ) {
		throw InvalidPointerException( MAKE_ERROR_MSG_2( "can't paint a border on a NULL Control." ) );
	}
	context->setColor( control->getColor() );
	paint( &control->getClientBounds(false), context );
}

void TitledBorder::paint( Rect* bounds, GraphicsContext* context )
{
	Rect edgeRect = *bounds;


	Rect textRect;
	Font* oldFont = context->getCurrentFont();
	context->setCurrentFont( &font_ );

	double textHeight = context->getTextHeight( "EM" );
	double textWidth = maxVal<double>( context->getTextWidth( "EM" ), context->getTextWidth( caption_ ) );

	edgeRect.top_ += textHeight/2.0;



	double y = edgeRect.top_ - textHeight/2.0;
	double x = edgeRect.left_ + 10;
	textRect.setRect( x, y, x + textWidth, y + textHeight );

	context->rectangle( &Rect(bounds->left_, bounds->top_, bounds->right_, bounds->top_ + textHeight + 1 ) );
	context->fillPath();

	DrawUIState state;
	state.setActive( true );
	
	context->drawThemeEdge( &edgeRect, state, sidesToPaint_, GraphicsContext::etEtched );

	textRect.inflate( 5, 0 );
	context->rectangle( &textRect );
	textRect.inflate( -5, 0 );
	context->fillPath();

	context->textBoundedBy( &textRect, caption_, false );

	context->setCurrentFont( oldFont );
}

Rect TitledBorder::getClientRect( Control* control )
{
	Rect result;
	if ( NULL != control ){
		GraphicsContext* context = control->getContext();

		result = control->getClientBounds( false );
		result.inflate( -2.0, 0.0 );
		result.bottom_ -= 2.0;

		Font* oldFont = context->getCurrentFont();
		context->setCurrentFont( &font_ );

		result.top_ += context->getTextHeight( "EM" );
		context->setCurrentFont( oldFont );
	}
	return result;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2.2.1  2004/06/27 18:19:15  ddiego
*more osx updates
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.5  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.4.4.1  2003/08/18 19:52:38  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*Revision 1.4  2003/05/17 20:37:22  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.1  2003/03/12 03:12:07  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2003/02/26 04:30:47  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.2.2  2002/12/28 01:56:21  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.2.2.1  2002/12/27 23:04:47  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.2  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.1.2.3  2002/10/18 03:06:35  ddiego
*changes to get the new form dialogs working
*
*Revision 1.1.2.2  2002/10/08 04:16:57  ddiego
*fixed a bug in the getClientBounds() that caused a stack overflow! DOH!
*further additions to the TemplateNewClassDlg to sync the various file names
*in the dialog to the lcass name
*
*Revision 1.1.2.1  2002/10/01 20:34:59  ddiego
*borders
*
*/

