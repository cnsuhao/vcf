//Alignment.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"

using namespace VCF;

/**
This example will introduce the basics of working with alignments. 
The example will demonstrate how to align by client, top, left, right,
bottom. We'll make use of both heavyweight and lighweight containers.
For a further information on lightweight vs. heavyweight controls,
please see the documentation, or the HeavyAndLight example.
This example will use Panel controls for simplicity, but same techniques can
be used with any control.
*/


class LightWeightControl : public ControlContainer {
public:
	LightWeightControl(): ControlContainer(false){}
	

};



class AlignmentWindow : public Window {
public:
	

	AlignmentWindow() {
		setCaption( "Alignment" );


		//first we create a Panel, this will hold the other controls
		//we don't have to do this - this is strictly to have a control
		//that is aligned as a AlignClient
		Panel* main = new Panel();
		add( main, AlignClient );		

		//create a new container  - agina, by default we do not have top do this
		//as a panel already has a container instance. Setting it here will destroy
		//the previous one
		FixedStandardContainer* container = new FixedStandardContainer();

		//set the border width
		container->setBorderWidth( 10 );

		main->setContainer( container );

		Panel* p1 = new Panel();
		p1->setHeight( 20 );
		main->add( p1, AlignBottom );
		p1->setColor( Color::getColor("yellow") );

		Panel* p2 = new Panel();
		p2->setHeight( 5 );
		main->add( p2, AlignBottom );
		p2->setColor( Color::getColor("blue") );

		Panel* p3 = new Panel();
		p3->setHeight( 20 );
		main->add( p3, AlignBottom );
		p3->setColor( Color::getColor("red") );
		
		Panel* p4 = new Panel();
		p4->setWidth( 23 );
		main->add( p4, AlignLeft );
		p4->setColor( Color::getColor("white") );


		Panel* p4a = new Panel();
		p4a->setWidth( 50 );
		main->add( p4a, AlignLeft );
		p4a->setColor( Color::getColor("gold") );



		Panel* p5 = new Panel();
		p5->setWidth( 45 );
		main->add( p5, AlignRight );
		p5->setColor( Color::getColor("green") );

		Panel* p5a = new Panel();
		p5a->setWidth( 45 );
		main->add( p5a, AlignRight );
		p5a->setColor( Color::getColor("pink") );


		Panel* p6 = new Panel();
		p6->setHeight( 25 );
		main->add( p6, AlignTop );
		p6->setColor( Color::getColor("black") );


		LightWeightControl* clientControl = new LightWeightControl();

		main->add( clientControl, AlignClient );
		clientControl->setBorderSize( 20 );

		Panel* clientP1 = new Panel();
		clientP1->setHeight( 25 );
		clientControl->add( clientP1, AlignTop );

		Label* label1 = new Label();
		label1->setHeight( 35 );
		label1->setColor( Color::getColor("white") );
		label1->setTransparent( false );
		label1->setWordWrap( true );
		label1->setCaption( "This is Label 1" );
		clientControl->add( label1, AlignTop );



		Label* label2 = new Label();
		label2->setHeight( 75 );
		label2->setColor( Color::getColor("gray158") );
		label2->setTransparent( false );
		label2->setWordWrap( true );
		label2->setCaption( "This is Label 2, Aligned to the Bottom!" );
		clientControl->add( label2, AlignBottom );
	}

	virtual ~AlignmentWindow(){};
	
};




class AlignmentApplication : public Application {
public:

	AlignmentApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new AlignmentWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		mainWindow->show();
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	AlignmentApplication app( argc, argv );

	Application::main();
	
	return 0;
}


