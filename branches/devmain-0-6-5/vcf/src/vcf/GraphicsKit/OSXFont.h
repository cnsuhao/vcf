#ifndef _VCF_OSXFONT_H__
#define _VCF_OSXFONT_H__
//OSXFont.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


#ifdef __OBJC__
	@class NSFont;
	@class NSDictionary;
	@class NSMutableDictionary;
#else
	class NSFont;
	class NSDictionary;
	class NSMutableDictionary;
#endif


namespace VCF {

class OSXFont : public FontPeer , public Object {

public:

	enum {
		attrFontName = 0,
		attrFontSize = 1,
		attrFontBold = 2,
		attrFontItalic = 3,
		attrFontUnderline=4,
		attrFontColor = 5,
		tagCount = 6
	};

	OSXFont( const String& fontName );

	OSXFont( const String& fontName, const double& pointSize );

	virtual ~OSXFont();

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

	virtual double getAscent()  ;

	virtual double getDescent() ;

	virtual double getExternalLeading() ;

	virtual double getInternalLeading() ;

	virtual double getHeight() ;

	virtual VCFChar getWordBreakCharacter() ;

	virtual VCFChar getFirstCharacter() ;

	virtual VCFChar getLastCharacter()  ;


	virtual VCF::GlyphCollection* getGlyphCollection( const String& text )  ;

	virtual bool isEqual( Object* object );

	ATSUStyle getATSUStyle() {
		return fontStyle_;
	}

    void setColor( Color* color );
protected:
	double shear_;
	double pointSize_;
	String fontName_;
	ATSUStyle fontStyle_;

	ATSUAttributeTag attrTags_[OSXFont::tagCount];
	ByteCount attrSizes_[OSXFont::tagCount];
	ATSUAttributeValuePtr attrValues_[OSXFont::tagCount];
	Boolean attrBold_;
	Boolean attrItalic_;
	Boolean attrUnderlined_;
	ATSURGBAlphaColor attrColor_;
	ATSUFontID attrFontID_;
	Fixed attrSize_;

	void initATSUAttrs();
	void updateStyleWithAttrs();
};

}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:41  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/21 03:27:06  ddiego
*updates for OSX porting
*
*/


#endif // _VCF_OSXFONT_H__


