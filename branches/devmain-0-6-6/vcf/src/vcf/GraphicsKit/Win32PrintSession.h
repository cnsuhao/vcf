#ifndef _WIN32PRINTSESSION_H__
#define _WIN32PRINTSESSION_H__



namespace VCF {

	struct GRAPHICSKIT_API  Win32PrintInfo {
		Win32PrintInfo() {
			memset( &docInfo_, 0, sizeof(docInfo_) );
			memset( &printDlg_, 0, sizeof(printDlg_) );
		}

		Win32PrintInfo( const Win32PrintInfo& rhs ) {
			*this = rhs;
		}

		Win32PrintInfo& operator=( const Win32PrintInfo& rhs ) {
			memcpy( &docInfo_, &rhs.docInfo_, sizeof(docInfo_) );
			memcpy( &printDlg_, &rhs.printDlg_, sizeof(printDlg_) );

			pageSize_ = rhs.pageSize_;
			startPage_ = rhs.startPage_;
			endPage_ = rhs.endPage_;
			pageDrawingRect_ = rhs.pageDrawingRect_;

			return *this;
		}

		DOCINFO docInfo_;
		PRINTDLG printDlg_;
		Size pageSize_;
		ulong32 startPage_;
		ulong32 endPage_;
		Rect pageDrawingRect_;
	};

	class GRAPHICSKIT_API Win32PrintSession : public Object, public PrintSessionPeer {
	public:
		Win32PrintSession();
		virtual ~Win32PrintSession();

		virtual String getTitle();
		virtual void setTitle( const String& title );

		virtual void setDefaultPageSettings();

		virtual Size getPageSize();
		virtual void setPageSize( const Size& pageSize );
		virtual void setStandardPageSize( const PrintSession::PageSize& pageSize );

		virtual void setStartPage( const ulong32& startPage );
		virtual ulong32 getStartPage();

		virtual void setEndPage( const ulong32& endPage );
		virtual ulong32 getEndPage();

		virtual Rect getPageDrawingRect();
		virtual void setPageDrawingRect( const Rect& drawingRect );


		virtual PrintInfoHandle getPrintInfoHandle();
		virtual void setPrintInfoHandle( PrintInfoHandle info );

		virtual void abort();

		virtual PrintContext* beginPrintingDocument();
		virtual void endPrintingDocument();

		virtual void beginPage( PrintContext* context );
		virtual void endPage( PrintContext* context );	
		
		static BOOL CALLBACK AbortProc( HDC hdc, int iError );


		Win32PrintInfo printInfo_;
		HDC printerDC_;		
	};

};



#endif //_WIN32PRINTSESSION_H__



