

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

#include "GraphicsKit.h"
#include "GraphicsKitPrivate.h"



using namespace VCF;

OSXGraphicsToolkit::OSXGraphicsToolkit()
{
	loadSystemColors();
}	

OSXGraphicsToolkit::~OSXGraphicsToolkit()
{
	
}	

void OSXGraphicsToolkit::loadSystemColors()
{
    RGBColor themeColor;
    
	Color* sysColor = NULL;
	sysColor = new Color();    
	systemColors_[SYSCOLOR_SHADOW] = sysColor;
    systemColorNameMap_[*sysColor] = "SYSCOLOR_SHADOW";
    GetThemeBrushAsColor( kThemeBrushButtonActiveDarkShadow, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    
    sysColor = new Color();
	systemColors_[SYSCOLOR_FACE] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_FACE";
    
    GetThemeBrushAsColor( kThemeBrushButtonFaceActive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_HIGHLIGHT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_HIGHLIGHT";
    
    GetThemeBrushAsColor( kThemeBrushButtonActiveLightHighlight, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_ACTIVE_CAPTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_ACTIVE_CAPTION";
    
    GetThemeBrushAsColor( kThemeBrushButtonFaceActive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_ACTIVE_BORDER] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_ACTIVE_BORDER";
    
    GetThemeBrushAsColor( kThemeBrushButtonFrameActive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color( *Color::getColor("gray128") );
	systemColors_[SYSCOLOR_DESKTOP] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_DESKTOP";
    
    
    sysColor = new Color();
	systemColors_[SYSCOLOR_CAPTION_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_CAPTION_TEXT";
    
    GetThemeBrushAsColor( kThemeTextColorBlack, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_SELECTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_SELECTION";
    
    GetThemeBrushAsColor( kThemeBrushFocusHighlight, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_SELECTION_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_SELECTION_TEXT";
    
    GetThemeBrushAsColor( kThemeTextColorBlack, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_INACTIVE_BORDER] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_INACTIVE_BORDER";
    
    GetThemeBrushAsColor( kThemeBrushButtonFrameInactive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_INACTIVE_CAPTION] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_INACTIVE_CAPTION";
    
    GetThemeBrushAsColor( kThemeBrushButtonFaceInactive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
                        
    sysColor = new Color( *Color::getColor("lemonchiffon") );
	systemColors_[SYSCOLOR_TOOLTIP] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_TOOLTIP";
    
    
    sysColor = new Color();
	systemColors_[SYSCOLOR_TOOLTIP_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_TOOLTIP_TEXT";
    
    GetThemeBrushAsColor( kThemeTextColorBlack, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_MENU] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_MENU";
    
    GetThemeBrushAsColor( kThemeBrushMenuBackground, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_MENU_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_MENU_TEXT";
    
    GetThemeBrushAsColor( kThemeTextColorBlack, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_WINDOW] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW";
    
    GetThemeBrushAsColor( kThemeBrushUtilityWindowBackgroundActive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_WINDOW_TEXT] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW_TEXT";
    
    GetThemeBrushAsColor( kThemeTextColorBlack, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
    sysColor = new Color();
	systemColors_[SYSCOLOR_WINDOW_FRAME] = sysColor;
	systemColorNameMap_[*sysColor] = "SYSCOLOR_WINDOW_FRAME";
    
    GetThemeBrushAsColor( kThemeBrushButtonFrameActive, 32, TRUE, &themeColor );
    sysColor->setRGB( ((double)themeColor.red)/65535.0, 
                        ((double)themeColor.green)/65535.0, 
                        ((double)themeColor.blue)/65535.0 );
                        
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
*Revision 1.1.2.5  2004/05/06 03:01:29  ddiego
*checking in OSX updates
*
*Revision 1.1.2.4  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/21 03:27:09  ddiego
*updates for OSX porting
*
*/



  	