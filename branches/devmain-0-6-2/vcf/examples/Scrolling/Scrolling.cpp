//Scrolling.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"
#include "graphics/EtchedBorder.h"

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



		//set the border of the window, this will give us a nice etched border
		EtchedBorder* bdr = new EtchedBorder();
		bdr->setStyle( GraphicsContext::etSunken );
		setBorder( bdr );

		scrollBarMgr_ = new ScrollbarManager();
		scrollBarMgr_->setTarget( this );
		addComponent( scrollBarMgr_ );

		scrollBarMgr_->setHasHorizontalScrollbar( true );
		scrollBarMgr_->setHasVerticalScrollbar( true );
	}

	virtual ~ScrollingWindow(){
		if ( NULL != currentImage_ ) {
			delete currentImage_;
		}
	};


	virtual void paint( GraphicsContext* ctx ) {
		Window::paint(ctx);		

		if ( NULL != currentImage_ ) {

			Rect r = getClientBounds();

			r.inflate( -5, -5 );

			Rect viewBounds = ctx->getViewableBounds();

			/**
			if we have an image, draw it centered within the available client
			rect
			*/
			Rect imageRect(0,0,currentImage_->getWidth(),currentImage_->getHeight());
			

			//adjust the rect to the bare minimum rect needed 
			


			imageRect.offset( r.getTopLeft() );
			
			//this positions the rect correctly
			if ( r.getWidth() > imageRect.getWidth() ) {
				imageRect.offset( r.getWidth()/2 - imageRect.getWidth()/2, 0 );
			}
			else {
				if ( viewBounds.getWidth() < currentImage_->getWidth() ) {
					imageRect.left_ = viewBounds.left_;
					imageRect.right_ = viewBounds.right_;
				}
			}

			if ( r.getHeight() > imageRect.getHeight() ) {
				imageRect.offset( 0, r.getHeight()/2 - imageRect.getHeight()/2 );
			}
			else {
				if ( viewBounds.getHeight() < currentImage_->getHeight() ) {
					imageRect.top_ = viewBounds.top_;
					imageRect.bottom_ = viewBounds.bottom_;
				}
			}
			
			ctx->drawPartialImage( viewBounds.getTopLeft(), &imageRect, currentImage_ );			


			//ctx->setColor( Color::getColor( "red" ) );
			//ctx->rectangle( &viewBounds );
			//ctx->strokePath();
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

			scrollBarMgr_->setVirtualViewWidth( currentImage_->getWidth() );
			scrollBarMgr_->setVirtualViewHeight( currentImage_->getHeight() );
			repaint(); //repaint ourselves to update the new image
		}
	}

	Image* currentImage_;

	ScrollbarManager* scrollBarMgr_;
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
	ScrollingApplication app( argc, argv );

	Application::main();
	
	return 0;
}


