#ifndef _PRINTSESSION_H__
#define _PRINTSESSION_H__


namespace VCF {

	typedef void* PrintInfoHandle;
	
	class PrintSessionPeer;
	class PrintContext;



	class GRAPHICSKIT_API PrintSession : public Object {
	public:

		DELEGATE(PageBegun);
		DELEGATE(PageDone);
		DELEGATE(PrintingBegun);
		DELEGATE(PrintingFinished);

		enum {
			PageBegunEvent = 102231,
			PageDoneEvent,
			PrintingBegunEvent,
			PrintingFinishedEvent
		};

		enum {
			UnknownPage = -1
		};

		enum PrintJob {
			pjPrintAll = 0,
			pjPrintSelectedPage,
			pjPrintRange
		};

		enum PageSize { 
			psA4, 
			psB5,
			psLetter, 
			psLegal, 
			psExecutive, 
			psA0, 
			psA1, 
			psA2, 
			psA3, 
			psA5, 
			psA6, 
			psA7, 
			psA8, 
			psA9, 
			psB0, 
			psB1, 
			psB10, 
			psB2, 
			psB3, 
			psB4, 
			psB6, 
			psB7, 
			psB8, 
			psB9, 
			psC5E, 
			psComm10E, 
			psDLE, 
			psFolio, 
			psLedger, 
			psTabloid, 
			psCustom
		};


		PrintSession();
		virtual ~PrintSession();

		String getTitle();
		void setTitle( const String& title );

		void setDefaultPageSettings();

		Size getPageSize();
		void setPageSize( const Size& pageSize );
		void setStandardPageSize( const PageSize& pageSize );

		void setStartPage( const ulong32& startPage );
		ulong32 getStartPage();

		void setEndPage( const ulong32& endPage );
		ulong32 getEndPage();

		Rect getPageDrawingRect();
		void setPageDrawingRect( const Rect& drawingRect );


		PrintInfoHandle getPrintInfoHandle();
		void setPrintInfoHandle( PrintInfoHandle info );

		void abort();

		PrintContext* beginPrintingDocument();
		void endPrintingDocument();

		void beginPage( PrintContext* context );
		void endPage( PrintContext* context );

		void runDefaultPrintLoop();

	protected:
		String title_;
		PrintSessionPeer* peer_;		
		bool errorDuringPrinting_;
		int currentPage_;
	};

};


#endif //_PRINTSESSION_H__



