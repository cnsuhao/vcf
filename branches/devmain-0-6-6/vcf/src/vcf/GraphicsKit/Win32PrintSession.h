#ifndef _WIN32PRINTSESSION_H__
#define _WIN32PRINTSESSION_H__



namespace VCF {


	class Win32PrintSession : public Object, public PrintSessionPeer {
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


		DOCINFO info_;
		HDC printerDC_;
		PRINTDLG printDlg_;
		Size pageSize_;
		ulong32 startPage_;
		ulong32 endPage_;
		Rect pageDrawingRect_;
	};

};



#endif //_WIN32PRINTSESSION_H__



