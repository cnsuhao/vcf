/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.10.6.1  2004/04/21 02:17:25  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.10  2003/08/09 02:56:46  ddiego
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
*Revision 1.9.2.1  2003/07/24 04:10:45  ddiego
*added fixes for the following tasks:
*Task #82279 ApplicationKit: add static methods to singleton objects
*Task #82277 FoundationKit: add static methods to singleton objects
*this required a bunch of changes in terms of getting rid of older style code
*
*Revision 1.9  2003/05/17 20:37:36  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.2.2  2003/03/23 03:23:57  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.8.2.1  2003/03/12 03:12:38  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2003/02/26 04:30:51  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.7.14.3  2003/02/24 05:42:19  ddiego
*moved the code for the VariantData calss into it's own header
*migrated to the new event style using Delegates instead of relying on
*the ugly macros that we were using before - same functionality though
*made sure everything still works and compiles, including neccessary
*changes in the VCF Builder so that it creates code in the new style
*This changes to teh new style of using Delegates completes task 58837
*
*Revision 1.7.14.2  2003/01/08 04:25:56  marcelloptr
*ColorNames static map and Color::s_ now use String instead than String* - VCF_LARGE_COLOR_LIST introduced
*
*Revision 1.7.14.1  2002/12/28 22:51:32  marcelloptr
*Color Spaces transformations and Color Names
*
*Revision 1.7  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.6.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.6  2002/02/17 01:07:14  ddiego
*removed OpenGL stuff to minimize memory impact. It will be in it's own
*module. Also fixed bugs:
*[ #500694 ] Combo text over writing down arrow
*[ #498481 ] pasting into edit control
*
*Revision 1.5  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//Win32GraphicsToolkit.h
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

Win32FontManager* Win32FontManager::win32FontMgr = NULL;


Win32GraphicsToolkit::Win32GraphicsToolkit()
{
	Win32FontManager::create();

	
	loadSystemColors();
	registerImageLoader( "image/bmp", new BMPLoader() );
	
	initSystemFont();
	
}

Win32GraphicsToolkit::~Win32GraphicsToolkit()
{
	systemFont_->free();
	Win32FontManager::getFontManager()->free();	
}

void Win32GraphicsToolkit::initSystemFont()
{
	systemFont_ = new Font();

	if ( System::isUnicodeEnabled() ) {
		HFONT defGUIFont = (HFONT)GetStockObject( DEFAULT_GUI_FONT );
		LOGFONTW lf = {0};
		GetObjectW( defGUIFont, sizeof(LOGFONTW), &lf );
		
		systemFont_->setAngle( lf.lfEscapement / 10 );
		systemFont_->setBold( (lf.lfWeight == FW_BOLD) ? true : false );
		systemFont_->setItalic( lf.lfItalic == TRUE );
		systemFont_->setUnderlined( lf.lfUnderline == TRUE );
		systemFont_->setStrikeOut( lf.lfStrikeOut == TRUE );
		systemFont_->setPixelSize( lf.lfHeight );
		systemFont_->setName( String(lf.lfFaceName) );
	}
	else {
		HFONT defGUIFont = (HFONT)GetStockObject( DEFAULT_GUI_FONT );
		LOGFONTA lf = {0};
		GetObjectA( defGUIFont, sizeof(LOGFONTA), &lf );
		
		systemFont_->setAngle( lf.lfEscapement / 10 );
		systemFont_->setBold( (lf.lfWeight == FW_BOLD) ? true : false );
		systemFont_->setItalic( lf.lfItalic == TRUE );
		systemFont_->setUnderlined( lf.lfUnderline == TRUE );
		systemFont_->setStrikeOut( lf.lfStrikeOut == TRUE );
		systemFont_->setPixelSize( lf.lfHeight );
		systemFont_->setName( String(lf.lfFaceName) );
	}

	
}

ContextPeer* Win32GraphicsToolkit::internal_createContextPeer( const unsigned long& contextID )
{
	ContextPeer* result = NULL;
	
	result = new Win32Context( contextID );

	return result;
}

ContextPeer* Win32GraphicsToolkit::internal_createContextPeer( const unsigned long& width, const unsigned long& height )
{
	return new Win32Context( width, height );
}

FontPeer* Win32GraphicsToolkit::internal_createFontPeer( const String& fontName )
{
	return new Win32Font( fontName );
}

FontPeer* Win32GraphicsToolkit::internal_createFontPeer( const String& fontName, const double& pointSize )
{
	return new Win32Font( fontName, pointSize );
}

OpenGLPeer* Win32GraphicsToolkit::internal_createOpenGLPeer( GraphicsContext* glContext )
{
#ifdef VCF_OPENGL
	return new Win32OpenGLPeer( glContext );
#else
	return NULL;
#endif
}	

Image* Win32GraphicsToolkit::internal_createImage( const unsigned long& width, const unsigned long& height )
{
	return new Win32Image( width, height );
}

Image* Win32GraphicsToolkit::internal_createImage( GraphicsContext* context, Rect* rect  )
{	
	if ( NULL != context ){
		return new Win32Image( context, rect );
	}
	else {
		return NULL;
	}
}


void Win32GraphicsToolkit::loadSystemColors()
{
	Color* sysColor = NULL;
	sysColor = new Color( ::GetSysColor( COLOR_BTNSHADOW ) );
	systemColors_[SYSCOLOR_SHADOW] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_SHADOW";

	sysColor = new Color( ::GetSysColor( COLOR_3DFACE ) );
	systemColors_[SYSCOLOR_FACE] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_FACE";

	sysColor = new Color( ::GetSysColor( COLOR_3DHILIGHT ) );
	systemColors_[SYSCOLOR_HIGHLIGHT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_HIGHLIGHT";

	sysColor = new Color( ::GetSysColor( COLOR_ACTIVECAPTION ) );
	systemColors_[SYSCOLOR_ACTIVE_CAPTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_ACTIVE_CAPTION";

	sysColor = new Color( ::GetSysColor( COLOR_ACTIVEBORDER ) );
	systemColors_[SYSCOLOR_ACTIVE_BORDER] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_ACTIVE_BORDER";

	sysColor = new Color( ::GetSysColor( COLOR_DESKTOP ) );
	systemColors_[SYSCOLOR_DESKTOP] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_DESKTOP";

	sysColor = new Color( ::GetSysColor( COLOR_CAPTIONTEXT ) );
	systemColors_[SYSCOLOR_CAPTION_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_CAPTION_TEXT";

	sysColor = new Color( ::GetSysColor( COLOR_HIGHLIGHT ) );
	systemColors_[SYSCOLOR_SELECTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_SELECTION";

	sysColor = new Color( ::GetSysColor( COLOR_HIGHLIGHTTEXT ) );
	systemColors_[SYSCOLOR_SELECTION_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_SELECTION_TEXT";

	sysColor = new Color( ::GetSysColor( COLOR_INACTIVEBORDER ) );
	systemColors_[SYSCOLOR_INACTIVE_BORDER] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_INACTIVE_BORDER";

	sysColor = new Color( ::GetSysColor( COLOR_INACTIVECAPTION ) );
	systemColors_[SYSCOLOR_INACTIVE_CAPTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_INACTIVE_CAPTION";

	sysColor = new Color( ::GetSysColor( COLOR_INFOBK ) );
	systemColors_[SYSCOLOR_TOOLTIP] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_TOOLTIP";

	sysColor = new Color( ::GetSysColor( COLOR_INFOTEXT ) );
	systemColors_[SYSCOLOR_TOOLTIP_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_TOOLTIP_TEXT";

	sysColor = new Color( ::GetSysColor( COLOR_MENU ) );
	systemColors_[SYSCOLOR_MENU] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_MENU";

	sysColor = new Color( ::GetSysColor( COLOR_MENUTEXT ) );
	systemColors_[SYSCOLOR_MENU_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_MENU_TEXT";

	sysColor = new Color( ::GetSysColor( COLOR_WINDOW ) );
	systemColors_[SYSCOLOR_WINDOW] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW";

	sysColor = new Color( ::GetSysColor( COLOR_WINDOWTEXT ) );
	systemColors_[SYSCOLOR_WINDOW_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW_TEXT";

	sysColor = new Color( ::GetSysColor( COLOR_WINDOWFRAME ) );
	systemColors_[SYSCOLOR_WINDOW_FRAME] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW_FRAME";

}


