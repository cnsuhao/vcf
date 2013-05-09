//Label.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/Label.h"
#include "vcf/FoundationKit/StringTokenizer.h"


using namespace VCF;

Label::Label():
	CustomControl( false ),
		autoWidth_(true)
{	
	setTransparent( true );
	textAlignment_ = taTextLeft;
	textVerticalAlignment_ = tvaTextCenter;
	focusControl_ = NULL;
	wordWrap_ = false;
	setTabStop( false );
	setUseColorForBackground( true );
}

void Label::paint( GraphicsContext * context )
{
	CustomControl::paint( context );
	context->setCurrentFont( getFont() );
	double y = 0.0;//getBounds()->getHeight() / 4;
	double x = 0.0;

	String caption = getCaption();

	int32 drawOptions = GraphicsContext::tdoNone;

	switch ( textAlignment_ ) {
		case taTextLeft : {
			x += 1.0;
			drawOptions |= GraphicsContext::tdoLeftAlign;
		}
		break;

		case taTextCenter : {
			x = maxVal<>( 1.0, (getWidth()/2.0) - (context->getTextWidth( caption ) / 2.0) );
			drawOptions |= GraphicsContext::tdoCenterHorzAlign;
		}
		break;

		case taTextRight : {
			x = maxVal<>( 1.0, getWidth() - context->getTextWidth( caption ) );
			drawOptions |= GraphicsContext::tdoRightAlign;
		}
		break;
	}

	switch ( textVerticalAlignment_ ) {
		case tvaTextTop : {
			y = 1.0;
			drawOptions |= GraphicsContext::tdoTopAlign;
		}
		break;

		case tvaTextCenter : {
			y = (getHeight()/2.0) - (context->getTextHeight(caption)/2.0);

			drawOptions |= GraphicsContext::tdoCenterVertAlign;
		}
		break;

		case tvaTextBottom : {
			y = getHeight() - context->getTextHeight(caption);
			drawOptions |= GraphicsContext::tdoBottomAlign;
		}
		break;
	}

	Rect bounds = getClientBounds();

	if ( true == wordWrap_ ) {
		drawOptions |= GraphicsContext::tdoWordWrap;
	}

	if ( getUseLocaleStrings() ) {
		String text = System::getCurrentThreadLocale()->translate( caption );
		context->textBoundedBy( &bounds, text, drawOptions );
	}
	else {
		context->textBoundedBy( &bounds, caption, drawOptions );
	}
}

void Label::setCaption( const String& caption )
{
	VirtualKeyCode keyCode = UIToolkit::findMnemonic( caption );

	if ( keyCode != vkUndefined ) {
		AcceleratorKey* newAccelKey = new AcceleratorKey( this, keyCode, kmAlt, NULL, true );
		addAcceleratorKey( newAccelKey );
	}

	caption_ = caption;


	if ( autoWidth_ ) {
		double w = this->getFont()->getTextWidth(caption_);
		setWidth(w);
	}

	repaint();
}

String Label::getCaption()
{
	Model* model  = getViewModel();
	if ( NULL != model ) {
		return model->getValueAsString( getModelKey() );
	}

	return caption_;
}

void Label::setName( const String& name )
{
	CustomControl::setName( name );
	if ( isDesigning() && caption_.empty() ) {
		setCaption( name );
	}
}

void Label::setTextAlignment( const TextAlignmentType& textAlignment )
{
	textAlignment_ = textAlignment;
	repaint();
}

void Label::setVerticalAlignment( const TextVerticalAlignment& verticalAlignment )
{
	textVerticalAlignment_ = verticalAlignment;
	repaint();
}

void Label::setFocusControl( Control* focusControl )
{
	focusControl_ = focusControl;
}

void Label::setWordWrap( const bool& wordWrap )
{
	wordWrap_ = wordWrap;
	repaint();
}

void Label::mnemonicActivate()
{
	if ( NULL != focusControl_ ) {
		focusControl_->setFocused();
	}
	else {
		CustomControl::mnemonicActivate();
	}
}

double Label::getPreferredWidth()
{
	if ( !wordWrap_ ) {		
		if ( NULL != getParent() ) {
			return getFont()->getTextWidth( getCaption() );
		}
	}
	return Control::getPreferredWidth();
}

double Label::getPreferredHeight()
{
	if ( wordWrap_ ) {

		double maxHeight = UIToolkit::getUIMetricValue( UIMetricsManager::mtLabelHeight );

		if ( NULL != getParent() ) {
			double w = getWidth();
			double lineWidth = 0;

			StringTokenizer tok( caption_, " \n\r\t" );
			String currentLine;

			Font* font = getFont();
			while ( tok.hasMoreElements() ) {
				String tmp = tok.nextElement();

				lineWidth += font->getTextWidth( currentLine + tmp );
				if ( lineWidth < w ) {
					currentLine += tmp;
				}
				else {
					maxHeight += font->getTextHeight( currentLine );
					lineWidth = 0;
					currentLine = "";
				}
			}
		}

		return maxHeight;
	}

	return UIToolkit::getUIMetricValue( UIMetricsManager::mtLabelHeight );
}

void Label::setAutoWidth(const bool& val )
{
	autoWidth_ = val;
	if ( autoWidth_ ) {
		setCaption(caption_);
	}
}

/**
$Id$
*/
