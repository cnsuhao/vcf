#ifndef _VCF_OSXGRAPHICSTOOLKIT_H__
#define _VCF_OSXGRAPHICSTOOLKIT_H__
//OSXGraphicsToolkit.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF  {



/**
Utility class to faciltate the transfer from a VCF::Rect instance to
OSX's ::Rect struct
*/
class RectProxy {
public:
    RectProxy( const ::Rect& r ) {
        r_.left_ = r.left;
        r_.top_ = r.top;
        r_.right_ = r.right;
        r_.bottom_ = r.bottom;
    }

    RectProxy( const VCF::Rect& r ) : r_(r) {}

    RectProxy( VCF::Rect* r ) : r_(*r) {}


    operator ::Rect () {
        ::Rect r;
        r.left = (int)r_.left_;
        r.top = (int)r_.top_;
        r.right = (int)r_.right_;
        r.bottom = (int)r_.bottom_;

        return r;
    }

    operator VCF::Rect () {
        return r_;
    }

    operator VCF::Rect* () {
        return &r_;
    }

    RectProxy& operator=( const ::Rect& r ) {
        r_.left_ = r.left;
        r_.top_ = r.top;
        r_.right_ = r.right;
        r_.bottom_ = r.bottom;
        return *this;
    }

    RectProxy& operator=( ::Rect* r ) {
        r_.left_ = r->left;
        r_.top_ = r->top;
        r_.right_ = r->right;
        r_.bottom_ = r->bottom;
        return *this;
    }

    RectProxy& operator=( const VCF::Rect& r ) {
        r_ = r;
        return *this;
    }

    RectProxy& operator=( VCF::Rect* r ) {
        r_ = *r;
        return *this;
    }

    VCF::Rect r_;
};





/**
*Class OSXGraphicsToolkit documentation
*/
class OSXGraphicsToolkit : public GraphicsToolkit {
public:
	OSXGraphicsToolkit();

	virtual ~OSXGraphicsToolkit();

	virtual ContextPeer* internal_createContextPeer( const unsigned long& width, const unsigned long& height );

	virtual ContextPeer* internal_createContextPeer( const unsigned long& contextID );

	virtual FontPeer* internal_createFontPeer( const String& fontName );

	virtual FontPeer* internal_createFontPeer( const String& fontName, const double& pointSize );

	virtual OpenGLPeer* internal_createOpenGLPeer( GraphicsContext* glContext );

	virtual Image* internal_createImage( const unsigned long& width, const unsigned long& height );

	virtual Image* internal_createImage( GraphicsContext* context, Rect* rect );

	virtual Font* getDefaultSystemFont() {
		return systemFont_;
	}
protected:
	void initSystemFont();
	void loadSystemColors();
	Font* systemFont_;

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
*Revision 1.1.2.2  2004/02/24 01:42:43  ddiego
*initial OSX ApplicationKit port checkin
*
*Revision 1.1.2.1  2004/02/21 03:27:06  ddiego
*updates for OSX porting
*
*/


#endif // _VCF_OSXGRAPHICSTOOLKIT_H__


