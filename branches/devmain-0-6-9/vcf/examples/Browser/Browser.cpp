//Browser.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"


using namespace VCF;


class BrowserWindow : public Window {
public:
	BrowserWindow() {
		setCaption( "Browser" );
		setVisible( true );

		HTMLBrowserControl* browser = new HTMLBrowserControl();
		browser->setDoubleBuffered( false );
		add( browser, AlignClient );

		browser->setCurrentURL( "http://vcf-online.org" );
	}

	virtual ~BrowserWindow(){};

};




class BrowserApplication : public Application {
public:

	BrowserApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new BrowserWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new BrowserApplication( argc, argv );

	Application::main();
	
	return 0;
}


