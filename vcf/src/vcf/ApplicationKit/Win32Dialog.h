#if     _MSC_VER > 1000
#pragma once
#endif

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:20  ddiego
*migration towards new directory structure
*
*Revision 1.22.4.1  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.22  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.21.2.2  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.21.2.1  2003/09/03 01:42:05  ddiego
*some minor fixes
*
*Revision 1.21  2003/08/09 02:56:44  ddiego
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
*Revision 1.20.2.1  2003/05/27 04:45:32  ddiego
*doing some code cleanup to fix some bugs in the way dialogs and popups
*work in Win32 port. Cleaned up the ControlPeer and DialogPeer interfaces
*a bit.
*
*Revision 1.20  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.19.2.2  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.19.2.1  2003/03/12 03:11:16  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.19  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.18.14.1  2003/01/08 00:19:46  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.18  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.17.4.1  2002/04/27 15:52:19  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.17  2002/01/24 01:46:48  ddiego
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

// Win32Dialog.h: interface for the Win32Dialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _VCF_WIN32DIALOG_H__
#define _VCF_WIN32DIALOG_H__

#include "vcf/ApplicationKit/DialogPeer.h"
#include "vcf/ApplicationKit/Win32Window.h"

namespace VCF
{

#define DEFAULT_DLG_WIDTH		120
#define DEFAULT_DLG_HEIGHT		120

class Win32Dialog : public Win32Window, public DialogPeer  
{
public:
	/**
	*default constructor used for showMessage calls
	*/
	Win32Dialog();

	Win32Dialog( Control* owner, Dialog* component );

	virtual ~Win32Dialog();		
    
	virtual void create( Control* owningControl );

	virtual void createParams();

	void init();

	virtual LRESULT handleEventMessages( UINT message, WPARAM wParam, LPARAM lParam, WNDPROC defaultWndProc = NULL );	

	virtual void showMessage( const String& message, const String& caption );

	virtual UIToolkit::ModalReturnType showMessage( const String& message, const String& caption, 
													const long& messageButtons,	const Dialog::MessageStyle& messageStyle );
	
private:	
	Control* owner_;
	Dialog* dialogComponent_;
};


};

#endif // _VCF_WIN32DIALOG_H__


