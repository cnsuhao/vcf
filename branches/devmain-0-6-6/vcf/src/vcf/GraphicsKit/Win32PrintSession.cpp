//Win32PrintSession.cpp

#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"
#include <commdlg.h>
#include "vcf/GraphicsKit/PrintSession.h"
#include "vcf/GraphicsKit/PrintSessionPeer.h"
#include "vcf/GraphicsKit/Win32PrintSession.h"
#include "vcf/GraphicsKit/PrintContext.h"

using namespace VCF;


Win32PrintSession::Win32PrintSession():
	printerDC_(0)
{
	memset( &info_, 0, sizeof(info_) );

	info_.cbSize = sizeof(info_);

	memset( &printDlg_, 0, sizeof(printDlg_) );
	printDlg_.lStructSize = sizeof(printDlg_);
	printDlg_.Flags |= PD_RETURNDEFAULT;
}

Win32PrintSession::~Win32PrintSession()
{

}


String Win32PrintSession::getTitle()
{
	return "";	
}

void Win32PrintSession::setTitle( const String& title )
{

}

BOOL CALLBACK Win32PrintSession::AbortProc( HDC hdc, int iError )
{
	return TRUE;
}

void Win32PrintSession::setDefaultPageSettings()
{
	printDlg_.Flags |= PD_RETURNDEFAULT;
	::PrintDlg( &printDlg_ );

	LPDEVNAMES devNamesPtr = (LPDEVNAMES)::GlobalLock(printDlg_.hDevNames);
	LPDEVMODE  devModePtr = NULL;
	if ( NULL != printDlg_.hDevMode ) {
		devModePtr = (LPDEVMODE)::GlobalLock(printDlg_.hDevMode);
	}


	if ( NULL == devNamesPtr ) {

		//error!
	}

	HDC hDC = NULL;
	
	hDC = ::CreateDC((LPCTSTR)devNamesPtr + devNamesPtr->wDriverOffset,
					  (LPCTSTR)devNamesPtr + devNamesPtr->wDeviceOffset,
					  (LPCTSTR)devNamesPtr + devNamesPtr->wOutputOffset,
					  devModePtr);

	::GlobalUnlock(printDlg_.hDevNames);

	if ( NULL != printDlg_.hDevMode ) {

		::GlobalUnlock(printDlg_.hDevMode);
	}
	

	info_.lpszDocName = "Untitled";

	printerDC_ = hDC;


	::SetAbortProc( printerDC_, Win32PrintSession::AbortProc );

	RECT r;
	r.left = 0;
	r.top = 0;
	r.right = ::GetDeviceCaps( printerDC_, HORZRES );
	r.bottom = ::GetDeviceCaps( printerDC_, VERTRES );

	DPtoLP( printerDC_, (LPPOINT)&r, 2 );

	pageSize_.width_ = r.right - r.left;
	pageSize_.height_ = r.bottom - r.top;

	startPage_ = 1;
	endPage_ = 1;

	pageDrawingRect_.setRect( 0, 0, pageSize_.width_, pageSize_.height_ );

}

Size Win32PrintSession::getPageSize()
{
	Size result;
	return pageSize_;
}

void Win32PrintSession::setPageSize( const Size& pageSize )
{

}

void Win32PrintSession::setStandardPageSize( const PrintSession::PageSize& pageSize )
{

}

void Win32PrintSession::setStartPage( const ulong32& startPage )
{

}

ulong32 Win32PrintSession::getStartPage()
{
	return startPage_;
}

void Win32PrintSession::setEndPage( const ulong32& endPage )
{

}

ulong32 Win32PrintSession::getEndPage()
{
	return endPage_;

}
Rect Win32PrintSession::getPageDrawingRect()
{	
	return pageDrawingRect_;
}

void Win32PrintSession::setPageDrawingRect( const Rect& drawingRect )
{
	pageDrawingRect_ = drawingRect;
}

PrintInfoHandle Win32PrintSession::getPrintInfoHandle()
{
	return NULL;
}

void Win32PrintSession::setPrintInfoHandle( PrintInfoHandle info )
{

}

void Win32PrintSession::abort()
{
	::AbortDoc( printerDC_ );
}

PrintContext* Win32PrintSession::beginPrintingDocument()
{
	if ( !::StartDoc( printerDC_, &info_ ) ) {
		//throw exception???		
		return NULL;
	}

	PrintContext* result = new PrintContext((ulong32)printerDC_);

	return result;
}

void Win32PrintSession::endPrintingDocument()
{
	if ( !::EndDoc( printerDC_ ) ) {		
		//throw exception???
	}
}

void Win32PrintSession::beginPage( PrintContext* context )
{	
	VCF_ASSERT( (HDC) context->getPeer()->getContextID() == printerDC_ );

	if ( ! ::StartPage( (HDC) context->getPeer()->getContextID() ) ) {
		//throw exception???
	}
}

void Win32PrintSession::endPage( PrintContext* context )
{
	VCF_ASSERT( (HDC) context->getPeer()->getContextID() == printerDC_ );

	if ( ! ::EndPage( (HDC) context->getPeer()->getContextID() ) ) {
		//throw exception???
	}
}