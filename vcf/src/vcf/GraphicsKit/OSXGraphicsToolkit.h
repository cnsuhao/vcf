

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


#ifndef _VCF_OSXGRAPHICSTOOLKIT_H__
#define _VCF_OSXGRAPHICSTOOLKIT_H__



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



