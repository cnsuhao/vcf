//Accelerators.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/GraphicsKit/DrawUIState.h"

using namespace VCF;


class FocusPanel : public Panel {
public:

	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		if ( Panel::isFocused() ) {
			Rect r = getClientBounds();
			r.inflate( -5, -5 );

			ctx->drawThemeFocusRect( &r, DrawUIState() );
		}
	}
};


class AcceleratorsWindow : public Window {
public:
	AcceleratorsWindow() {
		setCaption( "Accelerators" );
		
		MenuBar* mb = new MenuBar( this );
		setMenuBar( mb );

		MenuItem* root = mb->getRootMenuItem();

		MenuItem* edit = new DefaultMenuItem( "Edit", root, mb);
		MenuItem* editUndo = new DefaultMenuItem( "Undo", edit, mb);
		MenuItem* editCopy = new DefaultMenuItem( "Copy", edit, mb);

		MenuItem* panels = new DefaultMenuItem( "Panels", root, mb);
		MenuItem* panelsChangeColor = new DefaultMenuItem( "Change Color", panels, mb);

		EventHandler* ehEditUndo1 = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onEditUndo1, "AcceleratorsWindow::onEditUndo1" );

		EventHandler* ehUpdateEditUndo1 = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onUpdateEditUndo1, "AcceleratorsWindow::onUpdateEditUndo1" );

		EventHandler* ehEditUndo2 = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onEditUndo2, "AcceleratorsWindow::onEditUndo2" );
					
		EventHandler* ehUpdateEditUndo2 = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onUpdateEditUndo2, "AcceleratorsWindow::onUpdateEditUndo2" );


		EventHandler* ehEditCopy = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onEditCopy, "AcceleratorsWindow::onEditCopy" );
					
		EventHandler* ehUpdateEditCopy = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onUpdateEditCopy, "AcceleratorsWindow::onUpdateEditCopy" );

		EventHandler* ehUpdateEditCopy2 = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onUpdateEditCopy2, "AcceleratorsWindow::onUpdateEditCopy2" );

		

		EventHandler* ehPanelsChangeColors = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onPanelsChangeColors, "AcceleratorsWindow::onPanelsChangeColors" );

		EventHandler* ehUpdatePanelsChangeColors = 
			new GenericEventHandler<AcceleratorsWindow>( this, &AcceleratorsWindow::onUpdatePanelsChangeColors, "AcceleratorsWindow::onUpdatePanelsChangeColors" );




		editUndo->setAcceleratorKey( vkLetterZ, kmCtrl );
		editUndo->addMenuItemClickedHandler( ehEditUndo1 );
		editUndo->addMenuItemUpdateHandler( ehUpdateEditUndo1 );


		panelsChangeColor->addMenuItemClickedHandler( ehPanelsChangeColors );
		panelsChangeColor->addMenuItemUpdateHandler( ehUpdatePanelsChangeColors );


		TabbedPages* tabs = new TabbedPages();
		tabs->setName( "Tabs" );
		add( tabs, AlignClient );


		TabPage* tab = tabs->addNewPage( "Page 1" );

		TextControl* tc = new TextControl();
		tc->setTag( 100 );

		tc->setBounds( 10, 10, 100, tc->getPreferredHeight() );
		tab->getPageComponent()->getContainer()->add (tc);


		TextControl* tc2 = new TextControl();
		tc2->setBounds( 10, 60, 100, tc2->getPreferredHeight() );
		tc2->setTag( 101 );
		tab->getPageComponent()->getContainer()->add (tc2);


		

		tab = tabs->addNewPage( "Page 2" );
		
		FocusPanel* p1 = new FocusPanel();
		p1->setBounds( 20, 40, 100, 40 );
		p1->setName( "Panel1" );
		Label* l = new Label();
		l->setCaption( "Click top panel to set it's focus, then click the Panels > Change Colors menu" );
		l->setHeight( 30 );

		tab->getPageComponent()->getContainer()->add( l, AlignTop );

		tab->getPageComponent()->getContainer()->add (p1);

		FocusPanel* p2 = new FocusPanel();
		p2->setBounds( 20, 90, 100, 40 );
		p2->setName( "Panel2" );
		tab->getPageComponent()->getContainer()->add (p2);

		FocusPanel* p3 = new FocusPanel();
		p3->setBounds( 20, 150, 100, 40 );
		p3->setName( "Panel3" );
		tab->getPageComponent()->getContainer()->add (p3);


		Action* copyAction = new Action(this);

		copyAction->Performed += ehEditCopy;
		copyAction->Update += ehUpdateEditCopy;
		copyAction->Update += ehUpdateEditCopy2;


		copyAction->addTarget( editCopy );
		copyAction->setAcceleratorKey( vkLetterC, kmCtrl );


		tc2->addAcceleratorKey( vkLetterC, kmCtrl, copyAction );
	}

	void onEditUndo1( Event* e ) {
		Dialog::showMessage( "Hello World!" );
	}

	void onUpdateEditUndo1( Event* e ) {
		MenuItem* item = (MenuItem*)e->getSource();

		Control* focusedControl = Control::getCurrentFocusedControl();

		switch ( focusedControl->getTag() ) {

			case 100 : {
				item->setEnabled( true );
				item->setCaption( "Undo" );
			}
			break;

			case 101 : {
				item->setEnabled( false );
				item->setCaption( "Undo, Sorry, no dice!!!" );
			}
			break;

			default : {
				item->setEnabled( true );
				item->setCaption( "Undo - no text control selected!" );
			}
			break;
			
		}
	}


	void onEditUndo2( Event* e ) {
		Dialog::showMessage( "onEditUndo2" );
	}

	void onUpdateEditUndo2( Event* e ) {

	}

	void onEditCopy( Event* e ) {
		Dialog::showMessage( "onEditCopy!" );
	}

	void onUpdateEditCopy( Event* e ) {
		ActionEvent* ae = (ActionEvent*)e;

		Control* focusedControl = Control::getCurrentFocusedControl();

		ae->setEnabled( true );

		switch ( focusedControl->getTag() ) {

			case 100 : {
				ae->setEnabled( false );
			}
			break;
			
		}		
	}

	void onUpdateEditCopy2( Event* e ) {
		ActionEvent* ae = (ActionEvent*)e;

		Control* focusedControl = Control::getCurrentFocusedControl();

		ae->setEnabled( true );

		switch ( focusedControl->getTag() ) {

			case 101 : {
				ae->setEnabled( false );
			}
			break;
			
		}	
	}


	void onPanelsChangeColors( Event* e ) {
		double r = rand() % (255 - 0 + 1) + 0;
		double g = rand() % (255 - 0 + 1) + 0;
		double b = rand() % (255 - 0 + 1) + 0;
		Color c( r/255.0,g/255.0,b/255.0 );


		Panel* panel1 = (Panel*) Control::findComponent( "Panel1", true );

		panel1->setUseColorForBackground( true );
		panel1->setColor( &c );
	}

	void onUpdatePanelsChangeColors( Event* e ) {
		MenuItem* item = (MenuItem*)e->getSource();

		Control* focusedControl = Control::getCurrentFocusedControl();

		if ( focusedControl->getName() == "Panel1" ) {
			item->setEnabled(true);
		}
		else {
			item->setEnabled(false);
		}
	}

	virtual ~AcceleratorsWindow(){};

};




class AcceleratorsApplication : public Application {
public:

	AcceleratorsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new AcceleratorsWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( 100.0, 100.0, 500.0, 500.0 );
		mainWindow->show();
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new AcceleratorsApplication( argc, argv );

	Application::main();
	
	return 0;
}


