#if     _MSC_VER > 1000
#pragma once
#endif



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

// LightweightComponent.h

#ifndef _VCF_LIGHTWEIGHTCOMPONENT_H__
#define _VCF_LIGHTWEIGHTCOMPONENT_H__


namespace VCF
{

class APPKIT_API LightweightComponent : public Object, public ControlPeer {
public:
	LightweightComponent( Control* component );

	virtual ~LightweightComponent();

	virtual void create( Control* owningControl );
	
	virtual void destroyControl();

    virtual long getHandleID();

    virtual VCF::String getText();

    virtual void setText( const VCF::String& text );

    virtual void setBounds( VCF::Rect* rect );

    virtual VCF::Rect getBounds();

    virtual void setVisible( const bool& visible );

    virtual bool getVisible();

    virtual VCF::Control* getControl();
	
	virtual void setControl( VCF::Control* component );

	virtual void setParent( VCF::Control* parent );

	virtual VCF::Control* getParent();

	virtual bool isFocused();

	virtual void setFocused();

	virtual bool isEnabled();

	virtual void setEnabled( const bool& enabled );

	virtual void setFont( Font* font );

	void repaint( Rect* repaintRect=NULL );

	virtual void keepMouseEvents();

	virtual void releaseMouseEvents();

	virtual void setCursor( Cursor* cursor );

	virtual bool beginSetBounds( const ulong32& numberOfChildren );

	virtual void endSetBounds();

	virtual void translateToScreenCoords( Point* pt );

	virtual void translateFromScreenCoords( Point* pt );
private:
	VCF::Control* getHeavyWeightParent();
	VCF::Control* component_;
	VCF::Rect bounds_;
	bool visible_;
	bool enabled_;
	bool focused_;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.11.4.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.11  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.10.2.4  2003/09/21 04:15:35  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.10.2.3  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.10.2.2  2003/09/05 21:03:39  ddiego
*moved the various control destructor's to protected scope
*migrated code into destroy() overridden methods
*----------------------------------------------------------------------
*
*Revision 1.10.2.1  2003/08/19 04:43:56  ddiego
*further code to support lightweight container implementation. Not quite
*finished
*
*Revision 1.10  2003/08/09 02:56:44  ddiego
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
*Revision 1.9.2.1  2003/05/27 04:45:32  ddiego
*doing some code cleanup to fix some bugs in the way dialogs and popups
*work in Win32 port. Cleaned up the ControlPeer and DialogPeer interfaces
*a bit.
*
*Revision 1.9  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.22.3  2003/04/17 04:29:49  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.8.22.2  2003/03/23 03:23:49  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.8.22.1  2003/03/12 03:10:54  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_LIGHTWEIGHTCOMPONENT_H__


