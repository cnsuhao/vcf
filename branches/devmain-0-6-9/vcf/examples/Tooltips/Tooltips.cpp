//Tooltips.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/HorizontalLayoutContainer.h"

using namespace VCF;

class Cooltip : public CustomControl {
public:
	Cooltip(): CustomControl(false) {
		
	}

	virtual void paint( GraphicsContext* ctx ) {
		CustomControl::paint( ctx );

		Rect r = getClientBounds();

		r.inflate( -5, -5 );
		Basic3DBorder bdr;
		bdr.paint( &r, ctx );
	}
};

class TooltipsWindow : public Window {
public:
	TooltipsWindow() {
		setCaption( "Tooltips" );

		setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );

		Panel* p1 = new Panel();

		HorizontalLayoutContainer* hlc = new HorizontalLayoutContainer();
		hlc->setNumberOfColumns(1);

		p1->setContainer( hlc );

		CheckBoxControl* cb1 = new CheckBoxControl();
		cb1->ToolTip += 
			new ToolTipEventHandler<TooltipsWindow>(this,&TooltipsWindow::onToolTipCB1, "TooltipsWindow::onToolTipCB1" );

		cb1->setToolTipText( "This is a tooltip from check box 1 - see my background color!" );
		cb1->setCaption( "This is a check box" );
		p1->add( cb1 );

		CheckBoxControl* cb2 = new CheckBoxControl();
		cb2->ToolTip += 
			new ToolTipEventHandler<TooltipsWindow>(this,&TooltipsWindow::onToolTipCB2, "TooltipsWindow::onToolTipCB2" );

		cb2->setCaption( "And another checkbox" );
		cb2->setToolTipText( "Yet another tip!" );
		p1->add( cb2 );

		p1->setHeight( 200 );
		add( p1, AlignTop );

		MultilineTextControl* tc = new MultilineTextControl();
		
		tc->setToolTipText( "null" );
		tc->ToolTip += 
			new ToolTipEventHandler<TooltipsWindow>(this,&TooltipsWindow::onToolTip, "TooltipsWindow::onToolTip" );
		add( tc, AlignClient );

	}

	virtual ~TooltipsWindow(){};

	void onToolTipCB1( ToolTipEvent* e ) {
		e->setBackgroundColor( Color::getColor("green") );
	}

	void onToolTipCB2( ToolTipEvent* e ) {
		
	}

	void onToolTip( ToolTipEvent* e ) {
		e->setToolTipSize( &Size(200, 200) );
		Cooltip* cooltip = new Cooltip();

		e->setAutoDestroyEmbeddedControl( true );
		e->setEmbeddedControl( cooltip );
	}
};




class TooltipsApplication : public Application {
public:

	TooltipsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new TooltipsWindow();
		setMainWindow(mainWindow);
		mainWindow->show();
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new TooltipsApplication( argc, argv );

	Application::main();
	
	return 0;
}


