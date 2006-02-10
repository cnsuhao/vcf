//Browser.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"


using namespace VCF;



class BrowserApp : public Application {
public:

	BrowserApp( int argc, char** argv ) : Application(argc, argv) {

	}
	

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new Window();
		setMainWindow(mainWindow);
		mainWindow->setBounds( 100.0, 100.0, 500.0, 500.0 );

		Toolbar* tb = new Toolbar();
		tb->setName( "Toolbar1" );
		tb->setHeight( 25 );
		mainWindow->add( tb, AlignTop );


		ImageList* il = new ImageList(mainWindow);
		il->setImageHeight( 17 );
		il->setImageWidth( 17 );
		il->setTransparentColor( &Color( (uchar)212, (uchar)208, (uchar)200 ) );		

		tb->setImageList( il );

		GraphicsResourceBundle* resBundle = getResourceBundle();
		Image* img = resBundle->getImage( "back.bmp" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "forward.bmp" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "refresh.bmp" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "home.bmp" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "go.bmp" );
		il->addImage( img );
		delete img;


		ToolbarItem* item = tb->addToolBarButton( "back" );
		item->setImageIndex(0);
		item->setTooltip( "Go back one page" );

		item = tb->addToolBarButton( "forward" );
		item->setImageIndex(1);
		item->setTooltip( "Go forward one page" );

		

		item = tb->addToolBarButton( "refresh" );
		item->setImageIndex(2);
		item->setTooltip( "Reload current page" );

		item = tb->addToolBarButton( "home" );
		item->setImageIndex(3);
		item->setTooltip( "Load home page" );


		item = tb->addToolBarButton( "url" );
		item->setEnabled( false );

		urlBox = new ComboBoxControl();
		urlBox->setWidth( 175 );
		urlBox->setComboBoxStyle( cbsDropDownWithEdit );
		item->setItemControl( urlBox );

		item = tb->addToolBarButton( "go" );
		item->setImageIndex(4);
		item->setTooltip( "Load URL" );


		browser = new HTMLBrowserControl();
		browser->setDoubleBuffered( false );
		mainWindow->add( browser, AlignClient );


		

		//hook up actions
		ToolbarModel* tbModel = tb->getToolbarModel();

		Action* backAction = new Action(mainWindow);		
		backAction->addTarget( tbModel->getItemAtIndex(0) );
		backAction->Performed +=
			new GenericEventHandler<BrowserApp>(this, &BrowserApp::back, "BrowserApp::back" );

		Action* fwdAction = new Action(mainWindow);		
		fwdAction->addTarget( tbModel->getItemAtIndex(1) );
		fwdAction->Performed +=
			new GenericEventHandler<BrowserApp>(this, &BrowserApp::forward, "BrowserApp::forward" );

		Action* refreshAction = new Action(mainWindow);		
		refreshAction->addTarget( tbModel->getItemAtIndex(2) );
		refreshAction->Performed +=
			new GenericEventHandler<BrowserApp>(this, &BrowserApp::refresh, "BrowserApp::refresh" );

		Action* homeAction = new Action(mainWindow);		
		homeAction->addTarget( tbModel->getItemAtIndex(3) );
		homeAction->Performed +=
			new GenericEventHandler<BrowserApp>(this, &BrowserApp::home, "BrowserApp::home" );

		Action* goAction = new Action(mainWindow);		
		goAction->addTarget( tbModel->getItemAtIndex(5) );
		goAction->Performed +=
			new GenericEventHandler<BrowserApp>(this, &BrowserApp::go, "BrowserApp::go" );



		browser->setCurrentURL( "http://vcf-online.org" );

		mainWindow->setCaption( "Browser" );

		mainWindow->show();
		
		return result;
	}

protected:
	HTMLBrowserControl* browser;
	ComboBoxControl* urlBox;

	void go( Event* ) {
		browser->setCurrentURL( urlBox->getCurrentText() );
	}

	void back( Event* ) {
		browser->goBack();
	}

	void forward( Event* ) {
		browser->goForward();
	}

	void home( Event* ) {
		browser->goHome();
	}

	void refresh( Event* ) {
		browser->refresh();
	}
};


int main(int argc, char *argv[])
{
	Application* app = new BrowserApp( argc, argv );

	Application::main();
	
	return 0;
}


