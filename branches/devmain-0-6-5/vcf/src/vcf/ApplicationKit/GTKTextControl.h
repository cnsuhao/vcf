

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

#ifndef _VCF_GTKTEXTCONTROL_H__
#define _VCF_GTKTEXTCONTROL_H__


#ifndef _VCF_TEXTPEER_H__
#	include "vcf/ApplicationKit/TextPeer.h"
#endif // _VCF_TEXTPEER_H__


namespace VCF {

class TextEvent;

/**
class GTKTextControl documentation
*/
class GTKTextControl : public AbstractGTKControl, public VCF::TextPeer {
public: 
	GTKTextControl( TextControl* component, const bool& isMultiLineControl );
	virtual ~GTKTextControl();

	virtual void create( Control* owningControl );

	virtual void setRightMargin( const double & rightMargin );
    
	virtual void setLeftMargin( const double & leftMargin );

    virtual unsigned long getLineCount();

    virtual unsigned long getCurrentLinePosition();

    virtual double getLeftMargin();

    virtual double getRightMargin();

    virtual Point* getPositionFromCharIndex( const unsigned long& index );

    virtual unsigned long getCharIndexFromPosition( Point* point );

	/**
	*returns the current caret position with in the text control
	*this is specified by a zero based number representing the 
	*insertion point with the text control's text (stored in the text
	*control's Model).
	*@return long the index of the current insertion point in the Model's text
	*/
	virtual unsigned long getCaretPosition();

	virtual void setCaretPosition( const unsigned long& caretPos );

	/**
	*returns the zero based index that indicates where the current selection begins
	*may be the same index that getCaretPosition() returns
	*/
	virtual unsigned long getSelectionStart();

	/**
	*returns the number of characters selected
	*@return unsigned long the number of characters selected, a return value of 0
	*indicates that no characters are currently selected
	*/
	virtual unsigned long getSelectionCount();

	virtual void setSelectionMark( const unsigned long& start, const unsigned long& count );

	virtual void setSelectionFont( Font* font );

	virtual void setParagraphAlignment( const TextAlignmentType& alignment );

	virtual void scrollToLine( const ulong32& lineIndex );

	virtual gboolean handleEvent( GdkEvent* gtkEvent );

	virtual String getText();

    virtual void setText( const String& text );

	virtual void scrollToSelection( const bool& showEndSel = false );
	
	virtual void setReadOnly( const bool& readonly );
protected:
	TextControl* textControl_;
	bool isMultiLineControl_;

	GtkEntry* singleLine_;
	GtkTextView* multiLine_;
	bool internalTextChange_;

	void onTextModelTextChanged( TextEvent* e );

};




};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:17  ddiego
*migration towards new directory structure
*
*Revision 1.3.4.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.2.2.2  2003/10/02 04:50:52  ddiego
*changes to ensure the code compiles on linux. made a bunch of updates to
*the makefiles
*
*Revision 1.2.2.1  2003/08/25 03:13:44  ddiego
*adjusted the gtk peers to account for the new toolkit method names
*
*Revision 1.2  2003/08/09 02:56:44  ddiego
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
*Revision 1.1.2.1  2003/07/14 22:52:40  ddiego
*added further GTK support. Fixed some sevent handling issues. Added the
*peer for the CommandButton, and basic text widget support (both multiline and
*single line) and the file open common dialog peer as well.
*
*/

#endif // _VCF_GTKTEXTCONTROL_H__



