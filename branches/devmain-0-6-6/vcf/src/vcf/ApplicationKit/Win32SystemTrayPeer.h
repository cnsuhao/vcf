#ifndef _VCF_WIN32SYSTEMTRAYPEER_H__
#define _VCF_WIN32SYSTEMTRAYPEER_H__
//ControlPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif

namespace VCF {

	class Win32SystemTrayPeer : public Object, public SystemTrayPeer {
	public:
		Win32SystemTrayPeer();

		virtual ~Win32SystemTrayPeer();

		virtual void setIconImage( Image* image ) = 0;

		virtual void setPopupMenu( PopupMenu* popupMenu ) = 0;

		virtual void setTooltipText( const String& tooltipText ) = 0;
	
		virtual void addToTray() = 0;

		virtual void removeFromTray() = 0;

		virtual void showInTray() = 0;

		virtual void hideFromTray() = 0;

	protected:
		static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		HWND trayWnd_;
		bool enabled_;
		bool hidden_;
		bool removed_;
		void* notifyIconData_;

		NOTIFYICONDATAW* notifyIconDataW() {
			return (NOTIFYICONDATAW*)notifyIconData_;
		}

		NOTIFYICONDATAA* notifyIconDataA() {
			return (NOTIFYICONDATAA*)notifyIconData_;
		}
	};
}


#endif //_VCF_WIN32SYSTEMTRAYPEER_H__


