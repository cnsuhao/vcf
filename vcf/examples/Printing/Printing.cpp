//Printing.cpp


/**
WARNING!!!!!!
IN PROGRESS PLEASE DO NOT BUILD!!!!
*/

#include "vcf/ApplicationKit/ApplicationKit.h"
#include <commdlg.h>


namespace VCF {


	class PrintContext_ : public GraphicsContext {
	public:
		PrintContext_():GraphicsContext() {};

		PrintContext_( ulong32 contextID ):GraphicsContext(contextID) {};

	};

	class PrintSession;

	class PrintManager {
	public:
		virtual PrintSession* createPrintSession() = 0;
	};


	typedef void* PrintInfoHandle;


	class PrintSessionPeer; 


	class PrintSession : public Object {
	public:

		DELEGATE(PageBegun);
		DELEGATE(PageDone);
		DELEGATE(PrintingBegun);
		DELEGATE(PrintingFinished);

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

		PrintContext_* beginPrintingDocument();
		void endPrintingDocument();

		void beginPage( PrintContext_* context );
		void endPage( PrintContext_* context );

		void runDefaultPrintLoop();
		
		PrintSessionPeer* peer_;		
		bool errorDuringPrinting_;
	};


	class PrintSessionPeer {
	public:	

		virtual ~PrintSessionPeer(){};

		virtual String getTitle() = 0;
		virtual void setTitle( const String& title ) = 0;

		virtual void setDefaultPageSettings() = 0;

		virtual Size getPageSize() = 0;
		virtual void setPageSize( const Size& pageSize ) = 0;
		virtual void setStandardPageSize( const PrintSession::PageSize& pageSize ) = 0;

		virtual void setStartPage( const ulong32& startPage ) = 0;
		virtual ulong32 getStartPage() = 0;

		virtual void setEndPage( const ulong32& endPage ) = 0;
		virtual ulong32 getEndPage() = 0;

		virtual Rect getPageDrawingRect() = 0;
		virtual void setPageDrawingRect( const Rect& drawingRect ) = 0;


		virtual PrintInfoHandle getPrintInfoHandle() = 0;
		virtual void setPrintInfoHandle( PrintInfoHandle info ) = 0;

		virtual void abort() = 0;

		virtual PrintContext_* beginPrintingDocument() = 0;
		virtual void endPrintingDocument() = 0;

		virtual void beginPage( PrintContext_* context ) = 0;
		virtual void endPage( PrintContext_* context ) = 0;		
	};




	class PrintEvent : public Event {
	public:
		PrintEvent( Object* source ) : Event(source,0){}

		PrintEvent( Object* source, PrintContext_* ctx ): Event(source,0),context_(ctx){}

		PrintEvent( const PrintEvent& rhs ): Event(rhs),context_(rhs.context_) {
			
		}

		PrintContext_* getPrintContext() {
			return context_;
		}


		virtual Object* clone( bool deep=false ) {
			return new PrintEvent(*this);
		}

	protected:
		PrintContext_* context_;
	};





	


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

		virtual PrintContext_* beginPrintingDocument();
		virtual void endPrintingDocument();

		virtual void beginPage( PrintContext_* context );
		virtual void endPage( PrintContext_* context );	
		
		static BOOL CALLBACK AbortProc( HDC hdc, int iError );


		DOCINFO info_;
		HDC printerDC_;
		PRINTDLG printDlg_;
		Size pageSize_;
		ulong32 startPage_;
		ulong32 endPage_;
		Rect pageDrawingRect_;
	};

	class Win32PrintManager : public Object, public PrintManager {
	public:
		Win32PrintManager();
		virtual ~Win32PrintManager();

		virtual PrintSession* createPrintSession();
	};
};





using namespace VCF;


PrintSession::PrintSession():
	peer_(NULL),
	errorDuringPrinting_(false)
{	
	peer_ = new Win32PrintSession();
}

PrintSession::~PrintSession()
{
	delete peer_;
}

String PrintSession::getTitle()
{
	return peer_->getTitle();
}

void PrintSession::setTitle( const String& title )
{
	peer_->setTitle(title);
}

void PrintSession::setDefaultPageSettings()
{
	peer_->setDefaultPageSettings();
}

Size PrintSession::getPageSize()
{
	return peer_->getPageSize();
}

void PrintSession::setPageSize( const Size& pageSize )
{
	peer_->setPageSize(pageSize);
}

void PrintSession::setStandardPageSize( const PageSize& pageSize )
{
	peer_->setStandardPageSize(pageSize);
}

void PrintSession::setStartPage( const ulong32& startPage )
{
	peer_->setStartPage(startPage);
}

ulong32 PrintSession::getStartPage()
{
	return peer_->getStartPage();
}

void PrintSession::setEndPage( const ulong32& endPage )
{
	peer_->setEndPage(endPage);
}

ulong32 PrintSession::getEndPage()
{
	return peer_->getEndPage();
}

Rect PrintSession::getPageDrawingRect()
{
	return peer_->getPageDrawingRect();
}

void PrintSession::setPageDrawingRect( const Rect& drawingRect )
{
	peer_->setPageDrawingRect( drawingRect );
}


PrintInfoHandle PrintSession::getPrintInfoHandle()
{
	return peer_->getPrintInfoHandle();
}

void PrintSession::setPrintInfoHandle( PrintInfoHandle info )
{
	peer_->setPrintInfoHandle( info );
}

void PrintSession::abort()
{
	peer_->abort();
}

PrintContext_* PrintSession::beginPrintingDocument()
{
	errorDuringPrinting_ = false;
	PrintContext_* result = peer_->beginPrintingDocument();

	result->setViewableBounds( getPageDrawingRect() );

	return result;
}

void PrintSession::endPrintingDocument()
{
	try {
		peer_->endPrintingDocument();
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::beginPage( PrintContext_* context )
{
	try {
		peer_->beginPage( context );
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::endPage( PrintContext_* context )
{
	try {
		peer_->endPage( context );
	}
	catch ( BasicException& ) {
		errorDuringPrinting_ = true;
	}
}

void PrintSession::runDefaultPrintLoop() 
{
	errorDuringPrinting_ = false;
}






Win32PrintManager::Win32PrintManager()
{

}

Win32PrintManager::~Win32PrintManager()
{

}

PrintSession* Win32PrintManager::createPrintSession()
{
	return new PrintSession();
}









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

PrintContext_* Win32PrintSession::beginPrintingDocument()
{
	if ( !::StartDoc( printerDC_, &info_ ) ) {
		//throw exception???		
		return NULL;
	}

	PrintContext_* result = new PrintContext_((ulong32)printerDC_);

	return result;
}

void Win32PrintSession::endPrintingDocument()
{
	if ( !::EndDoc( printerDC_ ) ) {		
		//throw exception???
	}
}

void Win32PrintSession::beginPage( PrintContext_* context )
{	
	VCF_ASSERT( (HDC) context->getPeer()->getContextID() == printerDC_ );

	if ( ! ::StartPage( (HDC) context->getPeer()->getContextID() ) ) {
		//throw exception???
	}
}

void Win32PrintSession::endPage( PrintContext_* context )
{
	VCF_ASSERT( (HDC) context->getPeer()->getContextID() == printerDC_ );

	if ( ! ::EndPage( (HDC) context->getPeer()->getContextID() ) ) {
		//throw exception???
	}
}



















class PrintingWindow : public Window {
public:
	PrintingWindow() {
		setCaption( "Printing" );
		setVisible( true );


		PrintSession ps;

		ps.setDefaultPageSettings();

		PrintContext_* ctx = ps.beginPrintingDocument();

		ps.beginPage( ctx );

		//ctx->rectangle( &ctx->getViewableBounds() );

		//ctx->rectangle( 20, 100, 200, 700 );
		//ctx->strokePath();
		ctx->getCurrentFont()->setName( "Arial" ); 
		ctx->getCurrentFont()->setPointSize( 9 );
		ctx->textAt( 0, 0, "Hello World" );

		ps.endPage( ctx );

		ps.endPrintingDocument();

		
		ctx->free();
		
	}

	virtual ~PrintingWindow(){};

};




class PrintingApplication : public Application {
public:

	PrintingApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new PrintingWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new PrintingApplication( argc, argv );

	Application::main();
	
	return 0;
}


