/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.3.8.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.2.1  2003/04/14 19:10:30  ddiego
*mods to better support fonts and text using Pango - not finished, and
*may not compile
*
*Revision 1.2  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.1.2.1  2003/02/20 02:46:02  ddiego
*added in the base files for supporting a GTK peer implementation. Core parts
*of the GTKContext work (basic line primitives), and working on the GTKImage
*class.
*
*Auto generated header for class GTKFont
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


#ifndef _VCF_GTKFONT_H__
#define _VCF_GTKFONT_H__


namespace VCF {

/**

*/
class GTKFont : public Object, public FontPeer { 
public:
	GTKFont( const String& fontName );
	
	GTKFont( const String& fontName, const double& pointSize );

	virtual ~GTKFont();

	void init();

	virtual ulong32 getFontHandleID() ;

	virtual String getName() ;

	virtual void setName( const String& name );

	virtual bool isTrueType() ;

	virtual double getPointSize() ;

	virtual void setPointSize( const double pointSize );

	virtual double getPixelSize() ;

	virtual void setPixelSize( const double pixelSize );

	virtual void setBold( const bool& bold );    

	virtual bool getBold() ;

	virtual bool getItalic() ;

	virtual void setItalic( const bool& italic );

	virtual bool getUnderlined() ;

	virtual void setUnderlined( const bool& underlined );

	virtual bool getStrikeOut() ;

	virtual void setStrikeOut( const bool& strikeout );

	virtual double getShear() ;

	virtual void setShear(const double& shear );

	virtual double getAngle() ;

	virtual void setAngle( const double& angle );
    
	virtual void setAttributes( const double& pointSize, const bool& bold, const bool& italic,
					const bool& underlined, const bool& struckOut, const double& shear,
					const double& angle, const String& name );

	virtual double getAscent() ;

	virtual double getDescent() ;

	virtual double getExternalLeading() ;

	virtual double getInternalLeading() ;

	virtual double getHeight() ;

	virtual VCFChar getWordBreakCharacter() ;

	virtual VCFChar getFirstCharacter() ;

	virtual VCFChar getLastCharacter() ;	

	virtual GlyphCollection* getGlyphCollection( const String& text ) ;

	virtual bool isEqual( Object* object );

	PangoFontDescription* getPangoFontDescription() {
		return fontDescriptor_;
	}
protected:
	PangoFontDescription* fontDescriptor_;
};


};



#endif // _VCF_GTKFONT_H__


