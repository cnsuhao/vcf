//Win32SystemTrayPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/SystemTrayPeer.h"
#include <shellapi.h>

#include "vcf/ApplicationKit/Win32SystemTrayPeer.h"


#define WM_WIN32SYTEMTRAY		WM_APP + 405

using namespace VCF;


Win32SystemTrayPeer::Win32SystemTrayPeer():
	trayWnd_(NULL),
	enabled_(false),
	hidden_(true),
	removed_(true),
	notifyIconData_(NULL)
{	
	Win32ToolKit* toolkit = (Win32ToolKit*) UIToolkit::internal_getDefaultUIToolkit();

	HWND parent = toolkit->getDummyParent();

	static bool isWin32SystemTrayPeerWndClassRegistered = false;

	if ( !isWin32SystemTrayPeerWndClassRegistered ) {
		if ( System::isUnicodeEnabled() ) {
			WNDCLASSEXW wcex;

			wcex.cbSize = sizeof(wcex);

			wcex.style			= CS_HREDRAW | CS_VREDRAW;
			wcex.lpfnWndProc	= (WNDPROC)Win32SystemTrayPeer::wndProc;
			wcex.cbClsExtra		= 0;
			wcex.cbWndExtra		= 0;
			wcex.hInstance		= ::GetModuleHandleW( NULL );
			wcex.hIcon			= NULL;
			wcex.hCursor		= NULL;
			wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
			wcex.lpszMenuName	= NULL;
			wcex.lpszClassName	= L"VCF::Win32SytemTray";
			wcex.hIconSm		= NULL;

			RegisterClassExW(&wcex);
		}
		else{
			WNDCLASSEXA wcex;

			wcex.cbSize = sizeof(wcex);

			wcex.style			= CS_HREDRAW | CS_VREDRAW;
			wcex.lpfnWndProc	= (WNDPROC)Win32SystemTrayPeer::wndProc;
			wcex.cbClsExtra		= 0;
			wcex.cbWndExtra		= 0;
			wcex.hInstance		= ::GetModuleHandleA( NULL );
			wcex.hIcon			= NULL;
			wcex.hCursor		= NULL;
			wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
			wcex.lpszMenuName	= NULL;
			wcex.lpszClassName	= "VCF::Win32SytemTray";
			wcex.hIconSm		= NULL;

			RegisterClassExA(&wcex);
		}
	}

	isWin32SystemTrayPeerWndClassRegistered = true;


	if ( System::isUnicodeEnabled() ) {

		notifyIconData_ = new NOTIFYICONDATAW;
		memset( notifyIconData_, 0, sizeof(NOTIFYICONDATAW) );

		trayWnd_ = ::CreateWindowW( L"VCF::Win32SytemTray", NULL, WS_CHILD , 0, 0, 0, 0, parent, NULL, ::GetModuleHandleW( NULL ), NULL );

		NOTIFYICONDATAW& notifyIconData = *notifyIconDataW();

		notifyIconData.cbSize = sizeof(NOTIFYICONDATAW);
		notifyIconData.hWnd = trayWnd_;
		notifyIconData.uID = (UINT)this;
		notifyIconData.uCallbackMessage = WM_WIN32SYTEMTRAY;
		notifyIconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;

	}
	else {
		notifyIconData_ = new NOTIFYICONDATAA;
		memset( notifyIconData_, 0, sizeof(NOTIFYICONDATAA) );

		trayWnd_ = ::CreateWindowA( "VCF::Win32SytemTray", NULL, WS_CHILD , 0, 0, 0, 0, parent, NULL, ::GetModuleHandleA( NULL ), NULL );

		NOTIFYICONDATAA& notifyIconData = *notifyIconDataA();

		notifyIconData.cbSize = sizeof(NOTIFYICONDATAA);
		notifyIconData.hWnd = trayWnd_;
		notifyIconData.uID = (UINT)this;
		notifyIconData.uCallbackMessage = WM_WIN32SYTEMTRAY;
		notifyIconData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	}

}

Win32SystemTrayPeer::~Win32SystemTrayPeer()
{
	::DestroyWindow( trayWnd_);

	if ( System::isUnicodeEnabled() ) {
		NOTIFYICONDATAW* ptr = (NOTIFYICONDATAW*)notifyIconData_;
		delete ptr;
	}
	else {
		NOTIFYICONDATAA* ptr = (NOTIFYICONDATAA*)notifyIconData_;
		delete ptr;
	}
}

void Win32SystemTrayPeer::setIconImage( Image* image )
{

}

void Win32SystemTrayPeer::setPopupMenu( PopupMenu* popupMenu )
{

}

void Win32SystemTrayPeer::setTooltipText( const String& tooltipText )
{

}

void Win32SystemTrayPeer::addToTray()
{
	if (!removed_) {
        removeFromTray();
	}

    if (enabled_)  {

		if ( System::isUnicodeEnabled() ) {
			NOTIFYICONDATAW* notifyIconData = notifyIconDataW();
			if (!Shell_NotifyIconW(NIM_ADD, notifyIconData)) {		
				//  m_bShowIconPending = TRUE;
			}
			else {
				//  m_bRemoved = m_bHidden = FALSE;
			}
		}
		else{

		}
        
		
    }
}

void Win32SystemTrayPeer::removeFromTray()
{

}

void Win32SystemTrayPeer::showInTray()
{

}

void Win32SystemTrayPeer::hideFromTray()
{

}

LRESULT CALLBACK Win32SystemTrayPeer::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

