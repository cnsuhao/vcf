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

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/Win32Toolbar.h"
#include "vcf/ApplicationKit/Toolbar.h"

//Win32Toolbar.cpp

using namespace VCF;


Win32Toolbar::Win32Toolbar(Control* control):
	AbstractWin32Component(control),
	oldToolbarWndProc_(NULL),
	imageListCtrl_(NULL),
	currentlyModifyingItem_(false)
{

}

void Win32Toolbar::create( Control* control ) 
{
	Win32ToolKit* toolkit = (Win32ToolKit*)UIToolkit::internal_getDefaultUIToolkit();
	HWND parent = toolkit->getDummyParent();	


	createParams();

	styleMask_  = WS_CHILD | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT | CCS_NODIVIDER;// | CCS_NORESIZE;

	hwnd_ = ::CreateWindowEx( exStyleMask_, 
		                             TOOLBARCLASSNAME,//"SysListView32",//className.c_str(), 
									 NULL,
									 styleMask_, 
		                             0, 
									 0, 
									 1, 
									 1, 
									 parent, 
									 NULL, 
									 ::GetModuleHandle(NULL), 
									 NULL );
	
	if ( NULL != hwnd_ ) {
		Win32Object::registerWin32Object( this );
		oldToolbarWndProc_ = (WNDPROC)::SetWindowLong( hwnd_, GWL_WNDPROC, (LONG)wndProc_ ); 		

		SendMessage(hwnd_, TB_BUTTONSTRUCTSIZE, (WPARAM) sizeof(TBBUTTON), 0); 
		
		DWORD btnSize = SendMessage(hwnd_, TB_GETBUTTONSIZE, 0, 0 );


		SendMessage(hwnd_, TB_SETIMAGELIST, 0, 0 );
		defaultWndProc_ = NULL;


		currentlyModifyingItem_ = true;
		Size sz;
		sz.width_ = LOWORD(btnSize);
		sz.height_ = HIWORD(btnSize);

		((Toolbar*)peerControl_)->setButtonSize(sz);
		currentlyModifyingItem_ = false;

		SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );
	}
	
	control->getViewModel()->addModelHandler( 
		new ModelEventHandler<Win32Toolbar>( this, &Win32Toolbar::onModelChanged, "Win32Toolbar::onModelChanged" ) );

}

LRESULT Win32Toolbar::handleEventMessages( UINT message, WPARAM wParam, LPARAM lParam, WNDPROC defaultWndProc )
{
	LRESULT result = 0;

	switch ( message ) {
		case WM_SIZE : {
			result = AbstractWin32Component::handleEventMessages( message, wParam, lParam );
			
			result = CallWindowProc( oldToolbarWndProc_, hwnd_, message, wParam, lParam );

			DWORD style = ::GetWindowLong( hwnd_, GWL_STYLE );
			
			resizeToolbarItems();			
		}
		break;
		case TBN_GETDISPINFO : {
			NMTBDISPINFO* dispInfo = (NMTBDISPINFO*)lParam;
			ToolbarItem* item = (ToolbarItem*)dispInfo->lParam;
			dispInfo->iImage = item->getImageIndex();

		}
		break;

		case TBN_GETINFOTIP : {
			NMTBGETINFOTIP * dispInfo = (NMTBGETINFOTIP *)lParam;
			ToolbarItem* item = (ToolbarItem*)dispInfo->lParam;
			String tooltip = item->getTooltip();
			int size = minVal<int>(tooltip.size(),dispInfo->cchTextMax);
			tooltip.copy( dispInfo->pszText, size );
			dispInfo->pszText[size] = 0;		
		}
		break;

		case NM_CLICK : {
			TBNOTIFY* tbn = (TBNOTIFY*)lParam;
			
			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_STATE | TBIF_LPARAM ;
			info.cbSize = sizeof(info);
			
			if ( SendMessage( hwnd_, TB_GETBUTTONINFO, tbn->iItem, (LPARAM)&info ) >= 0 ) {
				
				ToolbarItem* item = (ToolbarItem*)info.lParam;
				long state = item->getState();
				
				if ( (TBSTATE_CHECKED  & info.fsState) && ( state & ToolbarItem::tisChecked ) ) {
					state |= ToolbarItem::tisPressed;
				}
				else {
					state &= ~ToolbarItem::tisPressed;
				}
				currentlyModifyingItem_ = true;
				item->setState( state );
				currentlyModifyingItem_ = false;
			}
		}
		break;

		case WM_COMMAND : {
			WORD wNotifyCode = HIWORD(wParam); // notification code 
			WORD wID = LOWORD(wParam);         // item, control, or accelerator identifier 
			HWND hwndCtl = (HWND) lParam; 

			TBBUTTONINFO info = {0};			
			info.cbSize = sizeof(info);
			info.dwMask |= TBIF_LPARAM | TBIF_STATE;
			SendMessage( hwnd_, TB_GETBUTTONINFO, wID, (LPARAM)&info );
			ToolbarItem* item = (ToolbarItem*)info.lParam;
			if ( NULL != item ) {
				

				long state = item->getState();
				
				if ( (TBSTATE_CHECKED  & info.fsState) && ( state & ToolbarItem::tisChecked ) ) {
					state |= ToolbarItem::tisPressed;
				}
				else {
					state &= ~ToolbarItem::tisPressed;
				}
				currentlyModifyingItem_ = true;
				item->setState( state );
				currentlyModifyingItem_ = false;



				item->click();
			}

		}
		break;

		case NM_CUSTOMDRAW : {
			NMTBCUSTOMDRAW* lpNMCustomDraw = (NMTBCUSTOMDRAW*) lParam;
			switch ( lpNMCustomDraw->nmcd.dwDrawStage ) {
				case CDDS_PREPAINT : {
					return CDRF_NOTIFYITEMDRAW  ;
				}
				break;

				case CDDS_ITEMPREPAINT : {

					ToolbarItem* item = (ToolbarItem*)lpNMCustomDraw->nmcd.lItemlParam;
					if ( NULL != item ) {
						
					}
					
					TBBUTTONINFO info = {0};
					info.cbSize = sizeof(info);
					info.dwMask |= TBIF_STATE;
					if ( SendMessage( hwnd_, TB_GETBUTTONINFO, lpNMCustomDraw->nmcd.dwItemSpec, (LPARAM)&info ) >= 0 ) {
						long state = item->getState();
						if ( (TBSTATE_CHECKED  & info.fsState) && ( state & ToolbarItem::tisChecked ) ) {
							state |= ToolbarItem::tisPressed;
						}
						else {
							state &= ~ToolbarItem::tisPressed;
						}

						currentlyModifyingItem_ = true;
						item->setState( state );
						currentlyModifyingItem_ = false;
					}

					return CDRF_DODEFAULT ;
				}
				break;				
			}
		}
		break;

		
		
		default : {
			result = AbstractWin32Component::handleEventMessages( message, wParam, lParam );
			
			result = CallWindowProc( oldToolbarWndProc_, hwnd_, message, wParam, lParam );
			
		}
		break;
	}


	return result;
}

void Win32Toolbar::onModelChanged( ModelEvent* e )
{
	if ( currentlyModifyingItem_ ) {
		return;
	}

	switch( e->getType() ) {

		case ToolbarItem::tbCaptionChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			if ( System::isUnicodeEnabled() ) {
				TBBUTTONINFOW info = {0};
				info.dwMask = TBIF_TEXT ;
				info.cbSize = sizeof(info);
				VCFChar tmp[256];
				String caption = tme->getItem()->getCaption();
				int size = minVal<int>(caption.size(), 255);
				caption.copy( tmp, size );
				tmp[size] = 0;
				
				info.cchText = size;
				info.pszText = tmp;
				
				SendMessage( hwnd_, TB_SETBUTTONINFOW, tme->getItem()->getIndex(), (LPARAM)&info );
			}
			else {
				TBBUTTONINFOA info = {0};
				info.dwMask = TBIF_TEXT ;
				info.cbSize = sizeof(info);
				char tmp[256];
				AnsiString caption = tme->getItem()->getCaption();
				int size = minVal<int>(caption.size(), 255);
				caption.copy( tmp, size );
				tmp[size] = 0;
				
				info.cchText = size;
				info.pszText = tmp;
				
				SendMessage( hwnd_, TB_SETBUTTONINFOA, tme->getItem()->getIndex(), (LPARAM)&info );
			}
			

			resizeToolbarItems();
		}
		break;		

		
		case ToolbarItem::tbImageIndexChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_IMAGE  ;
			info.cbSize = sizeof(info);

			int index = tme->getItem()->getIndex();
			SendMessage( hwnd_, TB_GETBUTTONINFO, index, (LPARAM)&info );

			info.iImage = tme->getItem()->getImageIndex();

			SendMessage( hwnd_, TB_SETBUTTONINFO, index, (LPARAM)&info );
		}
		break;


		case ToolbarItem::tbSelected : {
		
		}
		break;

		case ToolbarItem::tbGroupChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_STYLE  ;
			info.cbSize = sizeof(info);

			SendMessage( hwnd_, TB_GETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info );

			if ( tme->getItem()->isGrouped() ) {
				info.fsStyle |= TBSTYLE_GROUP;
			}
			else {
				info.fsStyle &= ~TBSTYLE_GROUP;
			}

			SendMessage( hwnd_, TB_SETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info );
		}
		break;

		case ToolbarItem::tbCheckChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_STYLE  ;
			info.cbSize = sizeof(info);

			if ( SendMessage( hwnd_, TB_GETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info ) >= 0 ) {
				
				if ( tme->getItem()->isChecked() ) {
					info.fsStyle |= TBSTYLE_CHECK;
				}
				else {
					info.fsStyle &= ~TBSTYLE_CHECK;
				}
				
				int i = SendMessage( hwnd_, TB_SETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info );
			}
			else {
				int err = GetLastError();
			}
		}
		break;

		case ToolbarItem::tbItemControlAdded : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_STYLE;
			info.fsStyle = TBSTYLE_SEP ;
			info.cbSize = sizeof(info);			

			int index = tme->getItem()->getIndex();			

			SendMessage( hwnd_, TB_SETBUTTONINFO, index, (LPARAM)&info );


			Control* addedControl = tme->getItem()->getItemControl();
			Rect r = addedControl->getBounds();


			memset( &info, 0, sizeof(info) );
			info.dwMask = TBIF_SIZE;
			info.cbSize = sizeof(info);			
			info.cx = r.getWidth();

			SendMessage( hwnd_, TB_SETBUTTONINFO, index, (LPARAM)&info );

			resizeToolbarItems();

			currentlyModifyingItem_ = true;

			
			RECT tbRect = {0};
			if ( SendMessage( hwnd_, TB_GETITEMRECT, index, (LPARAM)&tbRect ) ) {
				tme->getItem()->internal_setBounds( Rect(tbRect.left,tbRect.top,tbRect.right,tbRect.bottom) );

				Container* container = this->peerControl_->getContainer();
				if ( NULL != container ) {
					container->add( addedControl );
					addedControl->setBounds( &Rect(tbRect.left,tbRect.top,tbRect.right,tbRect.bottom) );
					addedControl->setVisible( true );
				}
				else {
					throw RuntimeException( MAKE_ERROR_MSG_2("No container found - unable to add control to toolbar") );
				}

			}
			

			currentlyModifyingItem_ = false;
		}
		break;

		
		case ToolbarItem::tbDimensionsChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			TBBUTTONINFO info = {0};
			info.dwMask = TBIF_SIZE ;
			info.cbSize = sizeof(info);			
			Rect r = *tme->getItem()->getBounds();

			info.cx = r.getWidth();

			SendMessage( hwnd_, TB_SETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info );
			resizeToolbarItems();
		}
		break;

		case ToolbarItem::tbAdded : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			bool val = ((Toolbar*)peerControl_)->getShowButtonCaptions();

			insertToolbarButton( tme->getItem()->getIndex(), tme->getItem(), val );
		}
		break;

		case ToolbarItem::tbRemoved : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
			SendMessage( hwnd_, TB_DELETEBUTTON, tme->getItem()->getIndex(), 0 );
			resizeToolbarItems();
		}
		break;

		case ToolbarItem::tbStateChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
			long state = tme->getItem()->getState();


			TBBUTTONINFO info = {0};			
			info.cbSize = sizeof(info);
			
			if ( state == ToolbarItem::tisSeparator ) {
				info.dwMask = TBIF_STYLE | TBIF_SIZE;
				info.fsStyle = TBSTYLE_SEP ;
				info.cx = 5;
			}
			else {
				if ( state & ToolbarItem::tisPressed ) {					
					if ( state & ToolbarItem::tisChecked ) {
						info.dwMask |= TBIF_STATE ;
						info.fsState |= TBSTATE_CHECKED  ;
					}					
				}

				if ( state & ToolbarItem::tisGrouped ) {
					info.dwMask |= TBIF_STYLE ;
					info.fsStyle |= TBSTYLE_GROUP  ;
				}

				if ( state & ToolbarItem::tisChecked ) {
					info.dwMask |= TBIF_STYLE ;
					info.fsStyle |= TBSTYLE_CHECK  ;
				}

				if ( state & ToolbarItem::tisEnabled ) {
					info.dwMask |= TBIF_STATE ;
					info.fsState |= TBSTATE_ENABLED  ;
				}
				else {
					info.dwMask |= TBIF_STATE ;
					info.fsState &= ~TBSTATE_ENABLED  ;
				}
			}

			SendMessage( hwnd_, TB_SETBUTTONINFO, tme->getItem()->getIndex(), (LPARAM)&info );
		}
		break;		

		case ToolbarItem::tbIndexChanged  : {
			
		}
		break;

		default : {

		}
		break;
	}
}

void Win32Toolbar::resizeToolbarItems( int startAt )
{
	
	int buttonCount = SendMessage( hwnd_, TB_BUTTONCOUNT, 0, 0 );
	int index = (startAt >= 0) ? startAt : 0;	

	for (index=0;index<buttonCount;index++ ) {
		RECT tbRect = {0};
		if ( SendMessage( hwnd_, TB_GETITEMRECT, index, (LPARAM)&tbRect ) ) {
			
			TBBUTTONINFO info = {0};			
			info.cbSize = sizeof(info);
			info.dwMask |= TBIF_LPARAM;
			SendMessage( hwnd_, TB_GETBUTTONINFO, index, (LPARAM)&info );
			ToolbarItem* item = (ToolbarItem*)info.lParam;
			item->internal_setBounds( Rect(tbRect.left,tbRect.top,tbRect.right,tbRect.bottom) );			
		}
	}
}

void Win32Toolbar::insertToolbarButton( const ulong32& index, ToolbarItem* item, bool showCaption )
{
	currentlyModifyingItem_ = true;
	TBBUTTON btn = {0};
	btn.dwData = (DWORD)item;
	btn.iBitmap = item->getImageIndex();

	String caption = item->getCaption();

	VCFChar* tmp = new VCFChar[caption.size()+2];
	memset( tmp, 0, caption.size()+2);
	caption.copy( tmp, caption.size() );	


	btn.iString = SendMessage( hwnd_, TB_ADDSTRING, (WPARAM) 0, (LPARAM) (LPSTR) tmp); 
	buttonCaptionsMap_[caption] = btn.iString;

	if ( buttonCaptionsMap_.size() == 1 ) {
		SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );
	}

	if ( !showCaption ) {
		btn.iString = -1;
	}
	
	btn.fsState = TBSTATE_ENABLED;
	btn.fsStyle = TBSTYLE_BUTTON | TBSTYLE_AUTOSIZE ;
	btn.idCommand = index;

	if ( !SendMessage( hwnd_, TB_INSERTBUTTON, (WPARAM) index, (LPARAM)&btn ) ) {
		int err = GetLastError();
	}

	TBBUTTONINFO info = {0};
	//info.dwMask = TBIF_IMAGE;
	info.cbSize = sizeof(info);


	if ( !SendMessage( hwnd_, TB_GETBUTTONINFO, 0, (LPARAM)&info ) ) {
		int err = GetLastError();
	}

	info.dwMask |= TBIF_LPARAM;
	info.lParam = (LPARAM)item;

	long state = item->getState();
	
	if ( state == ToolbarItem::tisSeparator ) {
		info.dwMask = TBIF_STYLE | TBIF_SIZE;
		info.fsStyle = TBSTYLE_SEP ;
		info.cx = 5;
	}
	else {
		if ( state & ToolbarItem::tisPressed ) {
			//info.dwMask |= TBIF_STATE ;
			//info.fsState |= TBSTATE_PRESSED  ;
			if ( state & ToolbarItem::tisChecked ) {
				info.dwMask |= TBIF_STATE ;
				info.fsState |= TBSTATE_CHECKED ;
			}
		}

		if ( state & ToolbarItem::tisGrouped ) {
			info.dwMask |= TBIF_STYLE ;
			info.fsStyle |= TBSTYLE_GROUP  ;
		}
		
		if ( state & ToolbarItem::tisChecked ) {
			info.dwMask |= TBIF_STYLE ;
			info.fsStyle |= TBSTYLE_CHECK  ;
		}
		
		if ( state & ToolbarItem::tisEnabled ) {
			info.dwMask |= TBIF_STATE ;
			info.fsState |= TBSTATE_ENABLED  ;
		}
		else {
			info.dwMask |= TBIF_STATE ;
			info.fsState &= ~TBSTATE_ENABLED  ;
		}
	}

	if ( NULL != item->getItemControl() ) {
		Rect bounds = item->getItemControl()->getBounds();
		info.cx = bounds.getWidth();
		info.dwMask = TBIF_STYLE | TBIF_SIZE;
		info.fsStyle = TBSTYLE_SEP ;
	}

	//info.iImage = I_IMAGECALLBACK;
	SendMessage( hwnd_, TB_SETBUTTONINFO, index, (LPARAM)&info );


	resizeToolbarItems();

	currentlyModifyingItem_ = false;

	

	delete [] tmp;	
}

void Win32Toolbar::resetItems( std::vector<ToolbarItem*>& items )
{
	int buttonCount = SendMessage( hwnd_, TB_BUTTONCOUNT, 0, 0 );
	int index = 0;	

	items.resize(buttonCount);


	for (index=0;index<buttonCount;index++ ) {
		TBBUTTONINFO info = {0};			
		info.cbSize = sizeof(info);
		info.dwMask |= TBIF_LPARAM | TBIF_STYLE | TBIF_STATE;
		SendMessage( hwnd_, TB_GETBUTTONINFO, index, (LPARAM)&info );
		ToolbarItem* item = (ToolbarItem*)info.lParam;
		items[index] = item;
		
		long state = item->getState();

		if ( (TBSTATE_CHECKED  & info.fsState) && ( state & ToolbarItem::tisChecked ) ) {
			state |= ToolbarItem::tisPressed;
		}
		else {
			state &= ~ToolbarItem::tisPressed;
		}
		currentlyModifyingItem_ = true;
		item->setState( state );
		currentlyModifyingItem_ = false;


		SendMessage( hwnd_, TB_DELETEBUTTON, 0, 0 );
	}

	
}

void Win32Toolbar::showButtonCaptions( const bool& val )
{
	peerControl_->setVisible( false );	
	
	int index = 0;	

	std::vector<ToolbarItem*> items;

	resetItems( items );	

	for (index=0;index<items.size();index++ ) {		
		insertToolbarButton( index, items[index], val );		
	}

	SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );	

	peerControl_->setVisible( true );	
}

void Win32Toolbar::setButtonCaptionPlacementHorizontal( const bool& val )
{
	if ( currentlyModifyingItem_ ) {
		return;
	}

	currentlyModifyingItem_ = true;

	peerControl_->setVisible( false );
	
	int index = 0;	

	std::vector<ToolbarItem*> items;

	resetItems( items );

	DWORD style = GetWindowLong( hwnd_, GWL_STYLE );

	if ( val ) {
		style |= TBSTYLE_LIST;
	}
	else {
		style &= ~TBSTYLE_LIST;
	}

	SetWindowLong( hwnd_, GWL_STYLE, style );	

	::SetWindowPos(hwnd_, NULL, 0, 0, 0, 0,
			SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	
	

	bool showCaptions = ((Toolbar*)peerControl_)->getShowButtonCaptions();

	for (index=0;index<items.size();index++ ) {		
		insertToolbarButton( index, items[index], showCaptions );		
	}

	SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );	

	peerControl_->setVisible( true );

	currentlyModifyingItem_ = false;
}

void Win32Toolbar::setButtonSize( const Size& buttonSize )
{
	if ( currentlyModifyingItem_ ) {
		return;
	}

	currentlyModifyingItem_ = true;

	peerControl_->setVisible( false );

	int buttonCount = SendMessage( hwnd_, TB_BUTTONCOUNT, 0, 0 );
	int index = 0;	

	std::vector<ToolbarItem*> items;

	resetItems( items );

	SendMessage( hwnd_, TB_SETIMAGELIST, 0, 0 );

	DWORD style = GetWindowLong( hwnd_, GWL_STYLE );	


	SetWindowLong( hwnd_, GWL_STYLE, style|TBSTYLE_TRANSPARENT|TBSTYLE_FLAT );

	::SetWindowPos(hwnd_, NULL, 0, 0, 0, 0,
			SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

	SendMessage( hwnd_, TB_SETBUTTONSIZE, 0, (LPARAM) MAKELONG((short)buttonSize.width_, (short)buttonSize.height_) );	

	
	SetWindowLong( hwnd_, GWL_STYLE, style );


	SendMessage( hwnd_, TB_SETIMAGELIST, 0, (LPARAM)imageListCtrl_ );

	

	bool val = ((Toolbar*)peerControl_)->getShowButtonCaptions();

	for (index=0;index<items.size();index++ ) {		
		insertToolbarButton( index, items[index], val );		
	}
	
	SetWindowLong( hwnd_, GWL_STYLE, style );

	SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );

	peerControl_->setVisible( true );
/*
	Container* container = peerControl_->getParent()->getContainer();
	if ( NULL != container ) {
		container->resizeChildren(NULL);
	}
*/	
	currentlyModifyingItem_ = false;
	
}

void Win32Toolbar::removeToolbarButton( ToolbarItem* item )
{
	SendMessage( hwnd_, TB_DELETEBUTTON, item->getIndex(), 0 );
	resizeToolbarItems();
}

void Win32Toolbar::onImageListImageChanged( ImageListEvent* e )
{
	ImageList* imageList = (ImageList*)e->getSource();

	switch ( e->getType() ) {
		case IMAGELIST_EVENT_WIDTH_CHANGED : case IMAGELIST_EVENT_HEIGHT_CHANGED :{
			int cx = imageList->getImageWidth();
			int cy = imageList->getImageHeight();
			int err = ImageList_SetIconSize( imageListCtrl_, cx, cy );

			//reset the contents
			Win32Image* win32Img = (Win32Image*)imageList->getMasterImage();
			HBITMAP hbmImage = win32Img->getBitmap();
			
			HBITMAP hCopyImg = (HBITMAP)CopyImage( hbmImage, IMAGE_BITMAP, 0, 0, NULL );


			Color* transparentColor = imageList->getTransparentColor();			

			err = ImageList_AddMasked( imageListCtrl_, hCopyImg, (COLORREF)transparentColor->getRGB() );
			if ( err < 0 ) {
				//error condition !
			}
			DeleteObject( hCopyImg );
		}
		break;

		case IMAGELIST_EVENT_ITEM_ADDED : {

			Win32Image* win32Img = (Win32Image*)e->getImage();
			HBITMAP hbmImage = win32Img->getBitmap();
			
			HBITMAP hCopyImg = (HBITMAP)CopyImage( hbmImage, IMAGE_BITMAP, 0, 0, NULL );
			
			Color* transparentColor = imageList->getTransparentColor();			

			int err = ImageList_AddMasked( imageListCtrl_, hCopyImg, (COLORREF)transparentColor->getRGB() );
			
			::DeleteObject( hCopyImg );	
		}
		break;

		case IMAGELIST_EVENT_ITEM_DELETED : {
			
		}
		break;
	}
}

void Win32Toolbar::setImageList( ImageList* imageList )
{
	if ( NULL != imageListCtrl_ ) {
		//destroy the old one
		int err = ImageList_Destroy( imageListCtrl_ );
		imageListCtrl_ = NULL;
	}

	if ( NULL != imageList ) {

		peerControl_->setVisible( false );
		
		
		int buttonCount = SendMessage( hwnd_, TB_BUTTONCOUNT, 0, 0 );
		int index = 0;	
		
		std::vector<ToolbarItem*> items;
		
		resetItems( items );
		
		
		
		
		SendMessage( hwnd_, TB_SETBITMAPSIZE, 0, (LPARAM) MAKELONG(imageList->getImageWidth(), imageList->getImageHeight()) );

		EventHandler* imgListHandler = getEventHandler( "Win32Toolbar::onImageListImageChanged" );
		
		imageListCtrl_ = ImageList_Create( imageList->getImageWidth(), imageList->getImageHeight(), 
											ILC_COLOR24  | ILC_MASK, imageList->getImageCount(), 4 );
		
		if ( imageList->getImageCount() > 0 ) {
			Win32Image* win32Img = (Win32Image*)imageList->getMasterImage();
			HBITMAP hbmImage = win32Img->getBitmap();
			
			HBITMAP hCopyImg = (HBITMAP)CopyImage( hbmImage, IMAGE_BITMAP, 0, 0, NULL );
			
			Color* transparentColor = imageList->getTransparentColor();

			int err = ImageList_AddMasked( imageListCtrl_, hCopyImg, (COLORREF)transparentColor->getRGB() );
			
			::DeleteObject( hCopyImg );	
		}

		SendMessage( hwnd_, TB_SETIMAGELIST, 0, (LPARAM)imageListCtrl_ );

		if ( NULL == imgListHandler ) {
			imgListHandler = 
				new ImageListEventHandler<Win32Toolbar>(this, Win32Toolbar::onImageListImageChanged, "Win32Toolbar::onImageListImageChanged" );			
		}
		
		imageList->SizeChanged.addHandler( imgListHandler );
		imageList->ImageAdded.addHandler( imgListHandler );
		imageList->ImageDeleted.addHandler( imgListHandler );


		bool val = ((Toolbar*)peerControl_)->getShowButtonCaptions();

		for (index=0;index<items.size();index++ ) {		
			insertToolbarButton( index, items[index], val );		
		}	


		SendMessage(hwnd_, TB_AUTOSIZE, 0, 0 );
	

		peerControl_->setVisible( true );
	}
}





/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.2.4.1  2004/04/21 02:17:26  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.2  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.4  2003/12/08 05:05:28  ddiego
*added a bunch more documentation to classes, and added support for new doc
*keywords (@delegates, @del, @delegate, @event, and @eventtype). This
*makes it easier to see at a glance what events a class fires off.
*Added finishing touches for the Action implementation and have a partially
*complete example for this checked in.
*
*Revision 1.1.2.3  2003/12/02 22:11:31  ddiego
*some minor changes to support Actions. Still not done yet.
*
*Revision 1.1.2.2  2003/12/01 03:44:13  ddiego
*added some fixes to the Win32Toolbar impl. A few minor changes to the
*toolbar example (which also got added). Some minor changes to docs
*as well.
*
*Revision 1.1.2.1  2003/10/31 05:06:38  ddiego
*added toolbar impl
*
*/




