/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.12  2003/08/09 02:56:45  ddiego
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
*Revision 1.11.2.2  2003/07/24 04:10:44  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.11.2.1  2003/07/10 04:55:16  ddiego
*added more stuff to GTK port - fixed some issues with events, and
*added support for posting events, and the stubs for a ButtonPeer
*
*Revision 1.11  2003/05/17 20:37:21  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.10.2.2  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.10.2.1  2003/03/12 03:12:00  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.10  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.9.2.2  2002/12/27 23:04:47  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.9.2.1  2002/11/28 05:12:04  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.9  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.8.4.3  2002/09/30 21:08:18  ddiego
*piddling stuff
*
*Revision 1.8.4.2  2002/09/28 22:22:46  ddiego
*added some support for font info and determinging the names on the system
*
*Revision 1.8.4.1  2002/09/27 23:38:35  ddiego
*added support for geting various layout information
*added support for drawing various graphics UI primitives like scroll buttons
*tabs, tab pages, etc, partially to have this support in place for use
*in MacOSX.
*Also added scrolling buttons to TabbedPages, this fixes task 56652 in the
*ApplicationKit list
*
*Revision 1.8  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.7.12.2  2002/09/03 05:05:13  ddiego
*fixed some more bugs in getting form building to work again. It now works
*but of course there are new issues, namely reading in nested properties
*in a form file where the properties are objects like:
*font.color.red, so this needs to be fixed in hte VFFInputStream file
*also need to have hte form saved properly
*still miscellaneous crashes but getting closer to an alpha tes state
*
*Revision 1.7.12.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.7  2002/01/24 01:46:49  ddiego
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

//Font.cpp
#include "vcf/GraphicsKit/GraphicsKit.h"


using namespace VCF;

Font::Font()
{

	Peer_ = NULL;
	Peer_ = GraphicsToolkit::createFontPeer( "" ); 
	if ( NULL == Peer_ ){
		throw InvalidPeer( MAKE_ERROR_MSG(NO_PEER), __LINE__ );
	}	
}

Font::Font( const String& fontName )
{
	Peer_ = NULL;
	Peer_ = GraphicsToolkit::createFontPeer( fontName ); 
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
}

Font::Font( const String& fontName, const double& pointSize )
{
	
	Peer_ = NULL;
	Peer_ = GraphicsToolkit::createFontPeer( fontName, pointSize ); 
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
}

Font::Font( const Font& font ):
    Object( font )
{
	Peer_ = NULL;

	Peer_ = GraphicsToolkit::createFontPeer( font.getName() ); 
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	}
	*this = font;
}

Font::~Font()
{
	delete Peer_;
}


Font& Font::operator= (const Font& rhs )
{
	setAttributes( rhs.getPointSize(), rhs.getBold(), rhs.getItalic(), rhs.getUnderlined(),
					rhs.getStrikeOut(), rhs.getShear(), rhs.getAngle(), &rhs.color_, rhs.getName() );

	return *this;
}

bool Font::isTrueType()  const

{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->isTrueType();
}

Color* Font::getColor()  
{
	return &color_;
}

void Font::setColor( Color* color )
{
	if ( NULL != color ) {
		color_ = *color;
	}
}

double Font::getPointSize()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getPointSize();
}

void Font::setPointSize( const double& pointSize )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setPointSize( pointSize );
}

double Font::getPixelSize()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getPixelSize();
}

void Font::setPixelSize( const double& pixelSize )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setPixelSize( pixelSize );
}

void Font::setBold( const bool& bold )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setBold( bold );
}

bool Font::getBold()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getBold();
}	

bool Font::getItalic()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getItalic();
}

void Font::setItalic( const bool& italic )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setItalic( italic );
}

bool Font::getUnderlined()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getUnderlined();
}

void Font::setUnderlined( const bool& underlined )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setUnderlined( underlined );
}

bool Font::getStrikeOut()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getStrikeOut();
}

void Font::setStrikeOut( const bool& strikeout )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setStrikeOut( strikeout );
}

double Font::getShear()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getShear();
}

void Font::setShear(const double& shear )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setShear( shear );
}

double Font::getAngle()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	return Peer_->getAngle();
}

void Font::setAngle( const double& angle )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};	
	Peer_->setAngle( angle );
}

GlyphCollection* Font::getGlyphCollection( const String& text )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};
	return Peer_->getGlyphCollection( text );
}

FontPeer* Font::getFontPeer()  
{
	return Peer_;
}

String Font::getName()  const
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};
	return Peer_->getName();
}

void Font::setName( const String& name )
{
	if ( NULL == Peer_ ){
		throw InvalidPeer(MAKE_ERROR_MSG(NO_PEER), __LINE__);
	};
	Peer_->setName( name );
}

void Font::copy( Object* source )
{
	if ( NULL != source ){
		Font* srcFont = dynamic_cast<Font*>( source );
		if ( NULL != srcFont ){
			setAngle( srcFont->getAngle() );
			setShear( srcFont->getShear() );
			setStrikeOut( srcFont->getStrikeOut() );
			setUnderlined( srcFont->getUnderlined() );
			setBold( srcFont->getBold() );
			setItalic( srcFont->getItalic() );
			setPointSize( srcFont->getPointSize() );
			setName( srcFont->getName() );

			Color* srcColor = srcFont->getColor();
			getColor()->copy( srcColor );
		}
	}
}

double Font::getAscent()  const
{
	return Peer_->getAscent();
}	

double Font::getDescent()  const
{
	return Peer_->getDescent();
}

double Font::getExternalLeading()  const
{	
	return Peer_->getExternalLeading();
}

double Font::getInternalLeading()  const
{
	return Peer_->getInternalLeading();
}	

double Font::getHeight()  const
{
	return Peer_->getHeight();
}

VCFChar Font::getWordBreakCharacter()  const
{
	return Peer_->getWordBreakCharacter();
}

VCFChar Font::getFirstCharacter()  const
{
	return Peer_->getFirstCharacter();
}

VCFChar Font::getLastCharacter()  const
{
	return Peer_->getLastCharacter();
}

void Font::setAttributes( const double& pointSize, const bool& bold, const bool& italic,
								const bool& underlined, const bool& struckOut, const double& shear,
								const double& angle, const Color* color, const String& name )
{

	Peer_->setAttributes( pointSize, bold, italic, underlined, struckOut, shear, angle, name );
	if ( NULL != color ) {
		color_ = *color;
	}
}


