//Printing.cpp


/**
WARNING!!!!!!
IN PROGRESS PLEASE DO NOT BUILD!!!!
*/

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/GraphicsKit/PrintContext.h"


using namespace VCF;





class PrintingWindow : public Window {
public:
	PrintingWindow() {
		setCaption( "Printing" );
		setVisible( true );


		PrintSession ps;

		ps.setDefaultPageSettings();

		PrintContext* ctx = ps.beginPrintingDocument();

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


