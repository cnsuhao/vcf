#ifndef _VCF_OSXDIALOG_H__
#define _VCF_OSXDIALOG_H__
//OSXDialog.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/

#include "vcf/ApplicationKit/OSXWindow.h"
#include "vcf/ApplicationKit/DialogPeer.h"

namespace VCF
{

#define DEFAULT_DLG_WIDTH		120
#define DEFAULT_DLG_HEIGHT		120

class OSXDialog : public OSXWindow, public DialogPeer
{
public:
	/**
	*default constructor used for showMessage calls
	*/
	OSXDialog();

	OSXDialog( Control* owner, Dialog* component );

	virtual ~OSXDialog();

	virtual void create( Control* owningControl );
	
	virtual void showMessage( const String& message, const String& caption );
	
	
	virtual void setVisible( const bool& visible );

	virtual UIToolkit::ModalReturnType showMessage( const String& message, const String& caption,
													const long& messageButtons,	const Dialog::MessageStyle& messageStyle );

	void init();

	virtual OSStatus handleOSXEvent( EventHandlerCallRef nextHandler, EventRef theEvent );
	
	virtual WindowAttributes getCreationWinAttrs();
	
	virtual void close();
private:
	Control* owner_;
	Dialog* dialogComponent_;
	DialogRef dialogRef_;
	WindowRef sheetParent_;
};


};




/**
*CVS Log info
*$Log$
*Revision 1.2.2.2  2004/10/23 18:10:43  ddiego
*mac osx updates, some more fixes for dialog code and for command button peer functionality
*
*Revision 1.2.2.1  2004/10/18 03:10:30  ddiego
*osx updates - add initial command button support, fixed rpoblem in mouse handling, and added dialog support.
*
*Revision 1.2  2004/08/07 02:49:08  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.4  2004/06/06 07:05:30  marcelloptr
*changed macros, text reformatting, copyright sections
*
*/


#endif // _VCF_OSXDIALOG_H__


