//Actions.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"
#include "core/Action.h"
#include "events/ActionEvent.h"


using namespace VCF;


class ActionsWindow : public Window {
public:
	ActionsWindow() {
		setCaption( "Actions" );		


		Toolbar* tb = new Toolbar();
		tb->setName( "Toolbar1" );
		tb->setHeight( 25 );
		add( tb, AlignTop );

		ImageList* il = new ImageList();
		il->setImageHeight( 19 );
		il->setImageWidth( 19 );
		il->setTransparentColor( &Color( 0.0, 1.0, 0.0) );
		addComponent( il );

		tb->setImageList( il );

		ResourceBundle* resBundle = Application::getRunningInstance()->getResourceBundle();
		Image* img = resBundle->getImage( "new" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "open" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "save" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "saveall" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "copy" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "paste" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "undo" );
		il->addImage( img );
		delete img;


		img = resBundle->getImage( "side" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "hammer" );
		il->addImage( img );
		delete img;

		img = resBundle->getImage( "wnd" );
		il->addImage( img );
		delete img;


		MenuBar* menuBar = new MenuBar();
		setMenuBar( menuBar );
		addComponent( menuBar ); 

		MenuItem* root = menuBar->getRootMenuItem();

		DefaultMenuItem* file = new DefaultMenuItem( "&File", root, menuBar );

		DefaultMenuItem* fileNew = new DefaultMenuItem( "&New", file, menuBar );
		
		DefaultMenuItem* menuSep = new DefaultMenuItem( "", file, menuBar );
		menuSep->setSeparator( true );

		DefaultMenuItem* fileOpen = new DefaultMenuItem( "&Open", file, menuBar );
		DefaultMenuItem* fileSave = new DefaultMenuItem( "&Save", file, menuBar );
		DefaultMenuItem* fileSaveAll = new DefaultMenuItem( "Save &All", file, menuBar );

		DefaultMenuItem* edit = new DefaultMenuItem( "&Edit", root, menuBar );
		
		DefaultMenuItem* editUndo = new DefaultMenuItem( "&Undo", edit, menuBar );

		menuSep = new DefaultMenuItem( "", edit, menuBar );
		menuSep->setSeparator( true );

		DefaultMenuItem* editCopy = new DefaultMenuItem( "&Copy", edit, menuBar );
		DefaultMenuItem* editPaste = new DefaultMenuItem( "&Paste", edit, menuBar );


		DefaultMenuItem* view = new DefaultMenuItem( "&View", root, menuBar );
		DefaultMenuItem* viewSidebar = new DefaultMenuItem( "&Side Bar", view, menuBar );
		DefaultMenuItem* viewHammer = new DefaultMenuItem( "&Hammer", view, menuBar );
		DefaultMenuItem* viewWindows = new DefaultMenuItem( "Show &Window List", view, menuBar );


		ToolbarItem* newTBitem = tb->addToolBarButton( "New" );
		newTBitem->setTooltip( "New Item" );

		tb->addToolBarButton( "" )->setAsSeparator();

		ToolbarItem* openTBitem = tb->addToolBarButton( "Open" );
		openTBitem->setImageIndex( 1 );
		openTBitem->setTooltip( "Open from file" );

		ToolbarItem* saveTBitem = tb->addToolBarButton( "Save" );
		saveTBitem->setImageIndex( 2 );
		saveTBitem->setTooltip( "Save to file" );

		ToolbarItem* saveAllTBitem = tb->addToolBarButton( "Save All" );
		saveAllTBitem->setImageIndex( 3 );
		saveAllTBitem->setTooltip( "Save All to file" );

		tb->addToolBarButton( "" )->setAsSeparator();

		ToolbarItem* copyTBitem = tb->addToolBarButton( "Copy" );
		copyTBitem->setImageIndex( 4 );
		copyTBitem->setTooltip( "Copy to clipboard" );

		ToolbarItem* pasteTBitem = tb->addToolBarButton( "Paste" );
		pasteTBitem->setImageIndex( 5 );
		pasteTBitem->setTooltip( "Paste from clipboard" );

		tb->addToolBarButton( "" )->setAsSeparator();

		ToolbarItem* undoTBitem = tb->addToolBarButton( "Undo" );
		undoTBitem->setImageIndex( 6 );
		undoTBitem->setTooltip( "Undo last action" );

		tb->addToolBarButton( "" )->setAsSeparator();

		ToolbarItem* sidebarTBitem = tb->addToolBarButton( "Sidebar" );
		sidebarTBitem->setImageIndex( 7 );
		sidebarTBitem->setChecked(true);
		sidebarTBitem->setTooltip( "Toggle Sidebar" );

		ToolbarItem* hammerTBitem = tb->addToolBarButton( "Hammer" );
		hammerTBitem->setImageIndex( 8 );
		hammerTBitem->setChecked(true);
		hammerTBitem->setTooltip( "Toggle Hammer" );

		ToolbarItem* windowsTBitem = tb->addToolBarButton( "Windows" );
		windowsTBitem->setImageIndex( 9 );
		windowsTBitem->setTooltip( "Show Window List" );

		sideBar_ = new Panel();
		sideBar_->setColor( Color::getColor("white") );
		sideBar_->setWidth( 100 );
		add( sideBar_, AlignLeft );


		Action* viewSidebarAction = new Action();
		addComponent( viewSidebar );

		viewSidebarAction->addTarget( viewSidebar );
		//viewSidebarAction->addTarget( sidebarTBitem );

		viewSidebarAction->Performed += 
			new GenericEventHandler<ActionsWindow>(this, &ActionsWindow::onViewSidebar, "ActionsWindow::onViewSidebar" );

		viewSidebarAction->Update += 
			new EventHandlerInstance<ActionsWindow,ActionEvent>(this, &ActionsWindow::onUpdateViewSidebar, "ActionsWindow::onUpdateViewSidebar" );

	}

	virtual ~ActionsWindow(){};

	Panel* sideBar_;

	void onViewSidebar( Event* e ) {
		sideBar_->setVisible( !sideBar_->getVisible() );
	}

	void onUpdateViewSidebar( ActionEvent* e ) {

	}

};




class ActionsApplication : public Application {
public:

	ActionsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new ActionsWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		mainWindow->show();
		
		return result;
	}

	virtual void idleTime() {

	}
};


int main(int argc, char *argv[])
{
	ActionsApplication app( argc, argv );

	Application::main();
	
	return 0;
}


