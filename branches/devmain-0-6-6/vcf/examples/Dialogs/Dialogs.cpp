//Dialogs.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/HorizontalLayoutContainer.h"


using namespace VCF;

/**
This example demonstrates how to use dialogs
*/


/**
This demonstrates how to create a very simple 
dialog complete with OK/Cancel buttons, and  
horizontal layout that takes into consideration 
the proper (as specified in the UI metrics for the
platform) horizontal and vertial spacing between 
controls.
*/
class MyDialog : public Dialog {
public:
	MyDialog() {
		setWidth( 350 );
		setHeight( 150 );

		Panel* pane1 = new Panel();
		pane1->setBorder( NULL );

		HorizontalLayoutContainer* container = new HorizontalLayoutContainer();		
		pane1->setContainer( container );

		

		Label* lable1 = new Label();
		lable1->setCaption( "Name:" );
		pane1->add( lable1 );

		TextControl* edit1 = new TextControl();
		
		pane1->add( edit1 );


		Label* lable2 = new Label();
		lable2->setCaption( "Are you Mergatroid?:" );
		pane1->add( lable2 );

		CheckBoxControl* checkBox = new CheckBoxControl();
		checkBox->setCaption( "Yes I am!" );
		pane1->add( checkBox );

		add( pane1, AlignClient );

		CommandButton* okBtn = new CommandButton();

		Panel* bottom = new Panel();
		bottom->setBorder( NULL );

		UIMetricsManager* metrics = UIToolkit::getUIMetricsManager();		

		bottom->setHeight( okBtn->getPreferredHeight() + metrics->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta) * 2 );
		

		HorizontalLayoutContainer* container2 = new HorizontalLayoutContainer();
		container2->setLeftBorderWidth( getWidth() / 2.0 );	

		double width = getWidth() / 2.0;
		width -= metrics->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta);
		width -= container2->getColumnTweenWidth( 0 );

		container2->setColumnWidth( 0, width / 2.0 );
		
		bottom->setContainer( container2 );


		
		bottom->add( okBtn );

		CommandButton* cancelBtn = new CommandButton();
		bottom->add( cancelBtn );

		okBtn->setCaption( "OK" );
		okBtn->setCommandType ( BC_OK );
		okBtn->setDefault(true);

		cancelBtn->setCaption( "Cancel" );
		cancelBtn->setCommandType ( BC_CANCEL );

		add( bottom, AlignBottom );

		edit1->setFocused();

		setCaption( "Mergatroid Questionaire" );
	}
};



class DialogsWindow : public Window {
public:
	DialogsWindow() {
		setCaption( "Dialogs" );
		setVisible( true );


		CommandButton* btn1 = new CommandButton();
		btn1->setBounds( 10, 20, 175, btn1->getPreferredHeight() );
		btn1->setCaption( "Dialog::showMessage 1" );
		btn1->ButtonClicked += 
			new GenericEventHandler<DialogsWindow>( this, &DialogsWindow::example1, "DialogsWindow::example1" );
		add( btn1 );


		CommandButton* btn2 = new CommandButton();
		btn2->setBounds( 10, btn1->getBottom() + 20, 175, btn2->getPreferredHeight() );
		btn2->setCaption( "Dialog::showMessage 2" );
		btn2->ButtonClicked += 
			new GenericEventHandler<DialogsWindow>( this, &DialogsWindow::example2, "DialogsWindow::example2" );
		add( btn2 );


		CommandButton* btn3 = new CommandButton();
		btn3->setBounds( 10, btn2->getBottom() + 20, 175, btn3->getPreferredHeight() );
		btn3->setCaption( "Show custom dialog" );
		btn3->ButtonClicked += 
			new GenericEventHandler<DialogsWindow>( this, &DialogsWindow::example3, "DialogsWindow::example3" );
		add( btn3 );
	}

	virtual ~DialogsWindow(){};

	/**
	This example will deomonstrate how to display a modal, information dialog,
	to present some information to a user.
	All you have to pass in is the caption - the title of the dialog will be assigned 
	the name of the application
	*/
	void example1( Event* e ) {
		Dialog::showMessage( "Hello - this is example 1." );
	}


	String modalReturnToString( UIToolkit::ModalReturnType val ) {
		String result;
		switch ( val ) {
			case UIToolkit::mrOK : {
				result = "UIToolkit::mrOK";
			}
			break;

			case UIToolkit::mrCancel : {
				result = "UIToolkit::mrCancel";
			}
			break;

			case UIToolkit::mrYes : {
				result = "UIToolkit::mrYes";
			}
			break;

			case UIToolkit::mrNo : {
				result = "UIToolkit::mrNo";
			}
			break;

			case UIToolkit::mrAbort : {
				result = "UIToolkit::mrAbort";
			}
			break;

			case UIToolkit::mrIgnore : {
				result = "UIToolkit::mrIgnore";
			}
			break;

			case UIToolkit::mrRetry : {
				result = "UIToolkit::mrRetry";
			}
			break;
		}
		return result;
	}

	/**
	This example also displays a modal dialog. You can specify more options
	such as the type of icon to display, the title of the dialog, and the 
	kind of buttons the user can respond with.
	*/
	void example2( Event* e ) {
		UIToolkit::ModalReturnType result;

		result = Dialog::showMessage( "Hello - this is an example using \nOK and Cancel buttons.", 
										"Fluffaluffagus",
										Dialog::mbOKCancel,
										Dialog::msError );

		Dialog::showMessage( "You selected: " + modalReturnToString( result ) );

		result = Dialog::showMessage( "Hello - this is an example using \nYes and No buttons.", 
										"Fluffaluffagus",
										Dialog::mbYesNo,
										Dialog::msWarning );

		Dialog::showMessage( "You selected: " + modalReturnToString( result ) );

		result = Dialog::showMessage( "Hello - this is an example using \nAbort, Retry and Ignore buttons.", 
										"Format your Hard Disk?",
										Dialog::mbAbortRetryIgnore,
										Dialog::msInfo );

		Dialog::showMessage( "You selected: " + modalReturnToString( result ) );
	}

	/**
	This example shows how to launch a custom
	modal dialog
	*/
	void example3( Event* e ) {
		MyDialog* dialog = new MyDialog();
		UIToolkit::ModalReturnType result;

		result = dialog->showModal();

		Dialog::showMessage( "You selected: " + modalReturnToString( result ) );

		dialog->free();
	}
};




class DialogsApplication : public Application {
public:

	DialogsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new DialogsWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new DialogsApplication( argc, argv );

	Application::main();
	
	return 0;
}


