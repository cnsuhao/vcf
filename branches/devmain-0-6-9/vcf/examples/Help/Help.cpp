//Help.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"

using namespace VCF;


class HelpWindow : public Window {
public:
	

	HelpWindow() {
		setCaption( "Help" );
		setVisible( true );

		CommandButton* showHelpContents = new CommandButton();

		showHelpContents->setBounds( 20, 20, 150, showHelpContents->getPreferredHeight() );
		showHelpContents->setCaption( "Help Contents" );
		showHelpContents->setWhatThisHelpString( "This displays the help contents." );
		add( showHelpContents );

		CommandButton* showHelpIndex = new CommandButton();

		showHelpIndex->setBounds( 20, 70, 150, showHelpIndex->getPreferredHeight() );
		showHelpIndex->setCaption( "Help Index" );
		add( showHelpIndex );

		PopupMenu* whatsThisMenu = new PopupMenu(this);
		DefaultMenuItem* whatsThis = new DefaultMenuItem("What's this?", whatsThisMenu->getRootMenuItem(), whatsThisMenu );
		whatsThis->MenuItemClicked += new GenericEventHandler<HelpWindow>( this, &HelpWindow::whatsThisHelp, "HelpWindow::whatsThisHelp" );

		whatsThis->setData( showHelpContents );

		showHelpContents->setPopupMenu( whatsThisMenu );


		showHelpContents->ButtonClicked += new GenericEventHandler<HelpWindow>( this, &HelpWindow::showContents, "HelpWindow::showContents" );
		showHelpIndex->ButtonClicked += new GenericEventHandler<HelpWindow>( this, &HelpWindow::showIndex, "HelpWindow::showIndex" );
		
	}

	virtual ~HelpWindow(){};

	void showContents( Event* e ) {
		UIToolkit::displayHelpContents();
	}

	void showIndex( Event* e ) {
		UIToolkit::displayHelpIndex();
	}

	void whatsThisHelp( Event* e ) {
		MenuItem* item = (MenuItem*)e->getSource();
		
		UIToolkit::displayContextHelpForControl( (Control*)item->getData() );
	}

};




class HelpApplication : public Application {
public:

	HelpApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){

		bool result = Application::initRunningApplication();

		setName( "Help App" );

		Window* mainWindow = new HelpWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
	
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new HelpApplication( argc, argv );

	Application::main();
	
	return 0;
}


