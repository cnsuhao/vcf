//Tables.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"


using namespace VCF;


class TablesWindow : public Window {
public:
	TablesWindow() {
		setCaption( "Tables" );
		setVisible( true );



		TableControl* table = new TableControl();

		add( table, AlignClient );

		TableModel* model = table->getTableModel();

		//model->addColumns( 3 );
		model->addRows(3);

	}

	virtual ~TablesWindow(){};

};




class TablesApplication : public Application {
public:

	TablesApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new TablesWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	TablesApplication app( argc, argv );

	Application::main();
	
	return 0;
}


