//Win32PrintDialog.cpp

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"

#include "vcf/GraphicsKit/PrintSession.h"
#include "vcf/GraphicsKit/PrintSessionPeer.h"
#include "vcf/GraphicsKit/Win32PrintSession.h"
#include "vcf/ApplicationKit/Win32PrintDialog.h"



using namespace VCF;



Win32PrintDialog::Win32PrintDialog( Control* owner ):
	owner_(owner)
{		
	printInfo_.printDlg_.lStructSize = sizeof(printInfo_.printDlg_);
}

Win32PrintDialog::~Win32PrintDialog()
{

}

UINT CALLBACK Win32PrintDialog::PrintHookProc( HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam )
{
	if ( WM_INITDIALOG  == uiMsg ) {
		PRINTDLG* printInfo = (PRINTDLG*)lParam;
		Win32PrintDialog* thisPtr = (Win32PrintDialog*)printInfo->lCustData;
		
		if ( !thisPtr->title_.empty() ) {
			SetWindowText( hdlg, thisPtr->title_.ansi_c_str() );
		}

		/*
		if ( System::isUnicodeEnabled() ) {
			
		}
		else {
			SetWindowTextA( hdlg, thisPtr->title_.ansi_c_str() );
		}
		*/
		return TRUE;
	}
	
	return 0;//::DefWindowProc( hdlg, uiMsg, wParam, lParam );
}

void Win32PrintDialog::setTitle( const String& title )
{
	this->title_ = title;
}

bool Win32PrintDialog::execute()
{
	bool result = false;

	printInfo_.printDlg_.Flags |= PD_ENABLEPRINTHOOK | PD_RETURNDC;
	printInfo_.printDlg_.hDC = NULL;
	printInfo_.printDlg_.lCustData = (DWORD) this;
	printInfo_.printDlg_.hwndOwner = NULL;

	if ( NULL != owner_ ) {
		printInfo_.printDlg_.hwndOwner = (HWND)owner_->getPeer()->getHandleID();
	}
	
	printInfo_.printDlg_.lpfnPrintHook = Win32PrintDialog::PrintHookProc;

	if ( PrintDlg( &printInfo_.printDlg_ ) ) {
		result = true;
		
		
		RECT r;
		r.left = 0;
		r.top = 0;
		r.right = ::GetDeviceCaps( printInfo_.printDlg_.hDC, HORZRES );
		r.bottom = ::GetDeviceCaps( printInfo_.printDlg_.hDC, VERTRES );
		
		DPtoLP( printInfo_.printDlg_.hDC, (LPPOINT)&r, 2 );
		
		printInfo_.pageSize_.width_ = r.right - r.left;
		printInfo_.pageSize_.height_ = r.bottom - r.top;
		
		printInfo_.startPage_ = printInfo_.printDlg_.nFromPage;
		printInfo_.endPage_ = printInfo_.printDlg_.nToPage;
		
		printInfo_.pageDrawingRect_.setRect( 0, 0, printInfo_.pageSize_.width_, printInfo_.pageSize_.height_ );
	}

	return result;
}

void Win32PrintDialog::setPrintInfo( PrintInfoHandle info )
{
	Win32PrintInfo* infoPtr = (Win32PrintInfo*)info;

	if ( NULL != infoPtr ) {
		printInfo_ = *infoPtr;
	}
}

PrintInfoHandle Win32PrintDialog::getPrintInfo()
{
	return (PrintInfoHandle)&printInfo_;
}

void Win32PrintDialog::setNumberOfCopies( const ulong32& val )
{
	printInfo_.printDlg_.nCopies = val;
}

ulong32 Win32PrintDialog::getNumberOfCopies()
{
	return printInfo_.printDlg_.nCopies;
}

void Win32PrintDialog::setStartPage( const ulong32& val )
{
	printInfo_.printDlg_.nFromPage = val;
}

ulong32 Win32PrintDialog::getStartPage()
{
	return printInfo_.printDlg_.nFromPage;
}

void Win32PrintDialog::setEndPage( const ulong32& val )
{
	printInfo_.printDlg_.nToPage = val;
}

ulong32 Win32PrintDialog::getEndPage()
{
	return printInfo_.printDlg_.nToPage;
}

void Win32PrintDialog::setPrintJobType( PrintSession::PrintJob val )
{
	switch ( val ) {
		case PrintSession::pjPrintAll :  {
			printInfo_.printDlg_.Flags &= ~PD_SELECTION;
			printInfo_.printDlg_.Flags &= ~PD_PAGENUMS;
			printInfo_.printDlg_.Flags |= PD_ALLPAGES;			
		}
		break;

		case PrintSession::pjPrintSelectedPage : {
			printInfo_.printDlg_.Flags &= ~PD_PAGENUMS;
			printInfo_.printDlg_.Flags &= ~PD_ALLPAGES;
			printInfo_.printDlg_.Flags |= PD_SELECTION;
		}
		break;

		case PrintSession::pjPrintRange : {
			printInfo_.printDlg_.Flags &= ~PD_ALLPAGES;
			printInfo_.printDlg_.Flags &= ~PD_SELECTION;
			printInfo_.printDlg_.Flags |= PD_PAGENUMS;			

		}
		break;
	}
}

PrintSession::PrintJob Win32PrintDialog::getPrintJobType()
{
	PrintSession::PrintJob result;
	if ( printInfo_.printDlg_.Flags & PD_ALLPAGES ) {
		result = PrintSession::pjPrintAll;
	}
	else if ( printInfo_.printDlg_.Flags & PD_SELECTION ) {
		result = PrintSession::pjPrintSelectedPage;
	}
	else if ( printInfo_.printDlg_.Flags & PD_PAGENUMS ) {
		result = PrintSession::pjPrintRange;
	}
	return result;
}











/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/08/31 04:12:12  ddiego
*cleaned up the GraphicsContext class - made more pervasive use
*of transformation matrix. Added common print dialog class. Fleshed out
*printing example more.
*
*/

