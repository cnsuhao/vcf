//Sliders.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"

using namespace VCF;


class SlidersWindow : public Window {
public:
	SlidersWindow() {
		setCaption( "Sliders" );
		setWidth( 500 );
		setHeight( 500 );

		Rect r = getClientBounds();

		SliderControl* slider = new SliderControl();
		slider->setBounds( 20, 20, r.getWidth()-40, slider->getPreferredHeight() );
		
		slider->setAnchor( AnchorLeft|AnchorRight);

		slider->setTickMarkStyle( SliderControl::tmsTopLeft );

		add( slider );


		slider = new SliderControl();
		slider->setDisplayOrientation( SliderControl::doVertical );
		slider->setBounds( 20, 100, slider->getPreferredWidth(), 200 );
		
		slider->setAnchor( AnchorTop|AnchorBottom);
		slider->setTickMarkStyle( SliderControl::tmsBottomRight );

		add( slider );

		slider->setEnabled( false );
	}

	virtual ~SlidersWindow(){};

};




class SlidersApplication : public Application {
public:

	SlidersApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new SlidersWindow();
		setMainWindow(mainWindow);
		mainWindow->show();

		
		return result;
	}

};


int main(int argc, char *argv[])
{
	SlidersApplication app( argc, argv );

	Application::main();
	
	return 0;
}



