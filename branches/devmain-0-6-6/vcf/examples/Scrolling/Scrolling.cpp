//Scrolling.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/EtchedBorder.h"

using namespace VCF;


class ScrollingWindow : public Window {
public:
	ScrollingWindow(): currentImage_(NULL) {
		setCaption( "Scrolling" );
		setVisible( true );

		//lets create a menu

		//create the menu bar - this will hold the menu items
		MenuBar* menuBar = new MenuBar();

		//set the window's menu bar
		setMenuBar( menuBar );

		//add the menu to this window's components
		addComponent( menuBar );

		/**
		create menu items, first arguemtn is the menu item name,
		then the parent,
		then the owning menu bar
		*/
		MenuItem* fileMenu = new DefaultMenuItem( "File", menuBar->getRootMenuItem(), menuBar );
		MenuItem* fileOpenImageMenu = new DefaultMenuItem( "Open Image...", fileMenu, menuBar );

		//add our event handler to the menu item
		fileOpenImageMenu->addMenuItemClickedHandler(
			new MenuItemEventHandler<ScrollingWindow>( this,ScrollingWindow::openImage, "ScrollingWindow::openImage" ) );

		// Scrollbar menu
		MenuItem* scrollMenu = new DefaultMenuItem( "Scrollbars", menuBar->getRootMenuItem(), menuBar );
		hasHorizontalScrollbarMenu_ = new DefaultMenuItem( "Horizontal", scrollMenu, menuBar );
		hasVerticalScrollbarMenu_ = new DefaultMenuItem( "Vertical", scrollMenu, menuBar );
		MenuItem* separator = new DefaultMenuItem( "", scrollMenu, menuBar );
		separator->setSeparator(true);
		separator->setEnabled( true );
		keepScrollbarsVisibleMenu_   = new DefaultMenuItem( "Keep visible", scrollMenu, menuBar );

		//add our event handler to the scrollbar menu
		hasHorizontalScrollbarMenu_->addMenuItemClickedHandler(
			new MenuItemEventHandler<ScrollingWindow>( this,ScrollingWindow::hasHorizontalScrollbar, "ScrollingWindow::hasHorizontalScrollbar" ) );
		hasVerticalScrollbarMenu_->addMenuItemClickedHandler(
			new MenuItemEventHandler<ScrollingWindow>( this,ScrollingWindow::hasVerticalScrollbar, "ScrollingWindow::hasVerticalScrollbar" ) );
		keepScrollbarsVisibleMenu_->addMenuItemClickedHandler(
			new MenuItemEventHandler<ScrollingWindow>( this,ScrollingWindow::keepScrollbarsVisible, "ScrollingWindow::keepScrollbarsVisible" ) );


		//set the border of the window, this will give us a nice etched border
		EtchedBorder* bdr = new EtchedBorder();
		bdr->setStyle( GraphicsContext::etSunken );
		setBorder( bdr );

		//this is what gives us the capability to easily control the
		//scrollbars for the form window
		scrollBarMgr_ = new ScrollbarManager();
		scrollBarMgr_->setTarget( this );
		addComponent( scrollBarMgr_ );

		scrollBarMgr_->setHasHorizontalScrollbar( true );
		scrollBarMgr_->setHasVerticalScrollbar( true );
		scrollBarMgr_->setKeepScrollbarsVisible( true );
		updateMenuHasHorizontalScrollbar();
		updateMenuHasVerticalScrollbar();
		updateMenuKeepScrollbarsVisible();

		scrollBarMgr_->setHorizontalLeftScrollSpace( 200 );

		panel_ = new Panel();
		add( panel_ );

		infoLabel_ = new Label();
		panel_->add( infoLabel_, AlignClient );

		Rect r;
		Scrollable* scrollable = getScrollable();
		scrollable->getHorizontalScrollRects( NULL, &r );
		panel_->setBounds( &r );
	}

	virtual ~ScrollingWindow(){
		if ( NULL != currentImage_ ) {
			delete currentImage_;
		}
	};

	virtual void handleEvent( Event* e ) {
		Window::handleEvent( e );
		if ( e->getType() == Control::CONTROL_SIZED ) {
			Scrollable* scrollable = getScrollable();
			if ( NULL != scrollable ) {
				Rect r;
				scrollable->getHorizontalScrollRects( NULL, &r );
				panel_->setBounds( &r );
			}
		}
	}

	virtual void paint( GraphicsContext* ctx ) {
		Window::paint(ctx);

		if ( NULL != currentImage_ ) {

			Rect viewBounds = ctx->getViewableBounds();

			/**
			if we have an image, draw it centered within the available client
			rect
			*/
			Rect imageRect(0,0,currentImage_->getWidth(),currentImage_->getHeight());

			Point imagePos;
			imagePos = viewBounds.getTopLeft();


			//adjust the imagePos to be centered if neccessary
			if ( viewBounds.getWidth() > imageRect.getWidth() ) {
				imagePos.x_ = viewBounds.getWidth()/2.0 - imageRect.getWidth()/2.0;
			}

			if ( viewBounds.getHeight() > imageRect.getHeight() ) {
				imagePos.y_ = viewBounds.getHeight()/2.0 - imageRect.getHeight()/2.0;
			}


			//adjust the rect to the bare minimum rect needed
			imageRect.left_ = maxVal<>( 0.0,viewBounds.left_ );
			imageRect.right_ = minVal<double>( currentImage_->getWidth(), viewBounds.right_ );

			imageRect.top_ = maxVal<>( 0.0,viewBounds.top_ );
			imageRect.bottom_ = minVal<double>( currentImage_->getHeight(), viewBounds.bottom_ );

			ctx->drawPartialImage( imagePos, &imageRect , currentImage_ );
		}
	}

	void openImage( MenuItemEvent* e ) {
		CommonFileOpen dlg( this );

		//get the available image loader extensions
		std::vector< std::pair<String,String> > contentTypes;

		/**
		this will get a list of all current available types that
		can currently be loaded by the VCF. The list is a series
		of std::pair objects. the std::pair.first element is a string
		that represents the file extension, and the std::pair.second
		represents a string that is the mime type for the extension
		*/
		GraphicsToolkit::getAvailableImageTypes( contentTypes );
		std::vector< std::pair<String,String> >::iterator it = contentTypes.begin();

		/*
		For each type, add a new filter to the dialog
		*/
		while ( it != contentTypes.end() ) {
			std::pair<String,String>& type = *it;

			dlg.addFilter( type.second + " (*." + type.first + " )", "*." + type.first );
			it ++;
		}


		if ( dlg.execute() ) {
			if ( NULL != currentImage_ ) {
				//delete our old image
				delete currentImage_;
			}

			//create a new image from the file name
			currentImage_ = GraphicsToolkit::createImage( dlg.getFileName() );
			
			scrollBarMgr_->updateVirtualViewSize( currentImage_->getWidth(), currentImage_->getHeight() );
			repaint(); //repaint ourselves to update the new image

			FilePath fp = dlg.getFileName();
			infoLabel_->setCaption( StringUtils::format( "Image: %s Size: %d, %d",
															fp.getBaseName(true).c_str(),
															currentImage_->getWidth(),
															currentImage_->getHeight() ) );
		}
	}

	void hasHorizontalScrollbar( MenuItemEvent* e ) {
		scrollBarMgr_->setHasHorizontalScrollbar( !scrollBarMgr_->hasHorizontalScrollBar() );
		updateMenuHasHorizontalScrollbar();
	}

	void hasVerticalScrollbar( MenuItemEvent* e ) {
		scrollBarMgr_->setHasVerticalScrollbar( !scrollBarMgr_->hasVerticalScrollBar() );
		updateMenuHasVerticalScrollbar();
	}

	void keepScrollbarsVisible( MenuItemEvent* e ) {
		scrollBarMgr_->setKeepScrollbarsVisible( !scrollBarMgr_->getKeepScrollbarsVisible() );
		updateMenuKeepScrollbarsVisible();
	}

	void updateMenuHasHorizontalScrollbar() {
		bool has = scrollBarMgr_->hasHorizontalScrollBar();
		hasHorizontalScrollbarMenu_->setChecked( has );
	}

	void updateMenuHasVerticalScrollbar() {
		bool has = scrollBarMgr_->hasVerticalScrollBar();
		hasVerticalScrollbarMenu_->setChecked( has );
	}

	void updateMenuKeepScrollbarsVisible() {
		bool visible = scrollBarMgr_->getKeepScrollbarsVisible();
		keepScrollbarsVisibleMenu_->setChecked( visible );
	}

public:
	Image* currentImage_;
	Panel* panel_;

	Label* infoLabel_;
	ScrollbarManager* scrollBarMgr_;

	MenuItem* hasHorizontalScrollbarMenu_;
	MenuItem* hasVerticalScrollbarMenu_;
	MenuItem* keepScrollbarsVisibleMenu_;
};




class ScrollingApplication : public Application {
public:

	ScrollingApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();

		Window* mainWindow = new ScrollingWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );

		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new ScrollingApplication( argc, argv );


	Application::main();

	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.4.2.4  2004/09/17 11:38:05  ddiego
*added program info support in library and process classes.
*
*Revision 1.4.2.3  2004/09/16 15:24:29  marcelloptr
*changed a name to the menu
*
*Revision 1.4.2.2  2004/09/15 22:18:37  dougtinkham
*replaced setVirtualViewWidth/Height with updateVirtualViewSize
*
*Revision 1.4.2.1  2004/09/15 14:19:13  marcelloptr
*added scrollbar menu
*
*Revision 1.4  2004/08/07 02:47:36  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.3.2.4  2004/04/29 03:40:56  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


