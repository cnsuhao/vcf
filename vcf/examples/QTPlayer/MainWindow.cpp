//MainWindow.h
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/TitledBorder.h"

#include "MainWindow.h"
#include "QTPlayerApplication.h"
#include "QTPlayerAbout.h"
#include "QuickTimeControl.h"
#include "vcf/FoundationKit/StringTokenizer.h"

#include "StatusBarControl.h"



using namespace VCF;

class PagedContainer : public StandardContainer {
public:

	void first() {
		if ( !pages_.empty() ) {
			//resort the pages_
			Control* control = controls_.front();

			while ( control != pages_.front() ) {
				Control* tmp = pages_.front();
				pages_.pop_front();
				pages_.push_back( tmp );
			}


			std::deque<Control*>::iterator it = pages_.begin();
			while ( it != pages_.end() ) {
				if ( *it != control ) {
					(*it)->setVisible( false );
				}
				it ++;
			}

			control->setVisible( true );
		}
	}

	void last() {
		if ( !pages_.empty() ) {
			Control* control = controls_.back();

			while ( control != pages_.front() ) {
				Control* tmp = pages_.front();
				pages_.pop_front();
				pages_.push_back( tmp );
			}

			std::deque<Control*>::iterator it = pages_.begin();
			while ( it != pages_.end() ) {
				if ( *it != control ) {
					(*it)->setVisible( false );
				}
				it ++;
			}

			control->setVisible( true );
		}
	}

	void next() {
		if ( !pages_.empty() ) {
			Control* control = pages_.front();
			pages_.pop_front();
			pages_.push_back( control );

			control = pages_.front();

			std::deque<Control*>::iterator it = pages_.begin();
			while ( it != pages_.end() ) {
				if ( *it != control ) {
					(*it)->setVisible( false );
				}
				it ++;
			}

			control->setVisible( true );
		}
	}

	virtual void resizeChildren( Control* control ) {
		//controlContainer_ is the control that this container is attached to
		VCF::Rect clientBounds = controlContainer_->getClientBounds();

		if ( clientBounds.isEmpty() ) {
			return; //nothing to do, so just exit the function
		}

		clientBounds.setRect( clientBounds.left_ + leftBorderWidth_,
								clientBounds.top_ + topBorderHeight_,
								clientBounds.right_ - rightBorderWidth_,
								clientBounds.bottom_ - bottomBorderHeight_ );



		bool controlJustAdded = false;
		if ( NULL != control ) {
			//we may have to position this separately - if it is the first time it
			//has been added then it will not be in the child control list
			//search for the control
			std::vector<Control*>::iterator found = std::find( controls_.begin(), controls_.end(), control );

			//if found equals the controls_.end, then control has not been added yet, and this is the first time
			//this control has been positioned for this container
			controlJustAdded = (found == controls_.end());
		}


		if ( controlJustAdded ) {
			control->setBounds( &clientBounds );
			pages_.push_back( control );
		}
		else {
			//note: we could have used the containers vector - this would be ever so slightly faster,
			//but this is a bit cleaner for the sake of an example.
			Enumerator<Control*>* children = AbstractContainer::getChildren();

			while ( children->hasMoreElements() ) {
				Control* child = children->nextElement();
				if ( child->getVisible() ) {
					child->setBounds( &clientBounds );
				}
			}
		}
	}

protected:
	std::deque<Control*> pages_;
};






class HorizontalLayoutContainer : public StandardContainer {
public:

	HorizontalLayoutContainer() {

		setBorderWidth( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta) );

		setNumberOfColumns(2);

		setColumnWidth( 0, 100 );

		setColumnWidth( 1, 100 );

		setColumnTweenWidth( 0, UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stControlHorizontalSpacing) );


		setMaxRowHeight( UIToolkit::getUIMetricsManager()->getDefaultHeightFor( UIMetricsManager::htLabelHeight ) );

		setRowSpacerHeight( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stControlVerticalSpacing) );
	}

	void setNumberOfColumns( int numColumns ) {
		columns_.clear();
		columnTweens_.clear();

		columns_.resize( numColumns, 0.0 );

		columnTweens_.resize( numColumns-1, 0.0 );  
	}

	void setColumnWidth( int index, double width ) {
		columns_[index] = width;
	}

	void setColumnTweenWidth( int index, double width ) {
		columnTweens_[index] = width;
	}

	void setMaxRowHeight( double val ) {
		maxRowHeight_ = val;
	}



	virtual void resizeChildren( Control* control ) {
		VCF::Rect clientBounds = controlContainer_->getClientBounds();

		if ( clientBounds.isEmpty() ) {
			return; //nothing to do, so just exit the function
		}

		clientBounds.setRect( clientBounds.left_ + leftBorderWidth_,
			clientBounds.top_ + topBorderHeight_,
			clientBounds.right_ - rightBorderWidth_,
			clientBounds.bottom_ - bottomBorderHeight_ );


		std::vector<Control*>::iterator it = controls_.begin();

		int colCount = columns_.size();
		int tweenCount = columnTweens_.size();

		int col = 0;
		int tween = 0;
		VCF::Rect cell = clientBounds;
		cell.right_ = cell.left_ + columns_[col];

		cell.bottom_ = cell.top_ + maxRowHeight_;

		while ( it != controls_.end() ) {

			Control* control = *it;


			if ( col == (colCount-1) ) {
				cell.right_ = clientBounds.right_;
			}


			control->setBounds( &cell );


			col ++;



			if ( col >= colCount ) {
				col = 0;
				tween = 0;

				cell.offset( 0, maxRowHeight_ + rowSpacerHeight_ );

				cell.left_ = clientBounds.left_;

				cell.right_ = cell.left_ + columns_[col];

			}
			else {
				cell.offset( cell.getWidth() + columnTweens_[tween], 0 );
				tween ++;
			}  


			it ++;
		}
	}


	void setRowSpacerHeight( double val ) {
		rowSpacerHeight_ = val;
	}

	std::vector<double> columns_;
	std::vector<double> columnTweens_;

	double maxRowHeight_;
	double rowSpacerHeight_;
};



class MediaInfoPanel : public Panel {
public:
	MediaInfoPanel() {
		setHeight( 200 );

		HorizontalLayoutContainer* container = new HorizontalLayoutContainer();
		container->setNumberOfColumns( 2 );	
		container->setColumnWidth( 0, 75 );	
		container->setRowSpacerHeight( 0 );

		Font font;
		font.setName( "Tahoma" );
		font.setPointSize( 10 ); 
		container->setMaxRowHeight( font.getHeight() * 1.25 );

		setContainer( container );
	}

	void setMovie( QuickTimeMovie* movie ) {
		Container* container = getContainer();
		while ( container->getChildCount() > 0 ) {
			Control* child = container->getControlAtIndex( 0 );

			container->remove(child);
			removeComponent( child );
			child->free();
		}

		if ( NULL != movie ) {
			std::vector<QuickTimeMovie::MovieMetaInfo> infoList;
			movie->getMovieMetaInfo( infoList );

			std::vector<QuickTimeMovie::MovieMetaInfo>::iterator it = infoList.begin();
			while ( it != infoList.end() ) {
				QuickTimeMovie::MovieMetaInfo& info = *it;

				Label* l = new Label();
				l->getFont()->setName( "Tahoma" );
				l->getFont()->setPointSize( 10 );
				l->getFont()->setBold( true );
				l->setCaption( info.first );
				l->setToolTipText( info.first );
				container->add( l );

				l = new Label();
				l->getFont()->setName( "Tahoma" );
				l->getFont()->setPointSize( 10 );
				l->setCaption( info.second );
				l->setToolTipText( info.second );
				l->setUseLocaleStrings( false );
				container->add( l );

				it ++;
			}			
		}

		container->resizeChildren(NULL);
		repaint();
	}
};




MainQTWindow::MainQTWindow():
	quicktimeControl_(NULL),
	movieLoaded_(false)
{
	//build main menu
	MenuBar* menuBar = new MenuBar();
	addComponent( menuBar );
	this->setMenuBar( menuBar );
	MenuItem* root = menuBar->getRootMenuItem();
	
	DefaultMenuItem* file = new DefaultMenuItem( "&File", root, menuBar );

	DefaultMenuItem* fileOpen = new DefaultMenuItem( "&Open...\tCtrl+O", file, menuBar );
	DefaultMenuItem* fileClose = new DefaultMenuItem( "&Close\tC", file, menuBar );

	DefaultMenuItem* sep = new DefaultMenuItem( "", file, menuBar );
	sep->setSeparator( true );
	
	DefaultMenuItem* fileExit = new DefaultMenuItem( "E&xit", file, menuBar );


	DefaultMenuItem* movie = new DefaultMenuItem( "&Movie", root, menuBar );	
	DefaultMenuItem* moviePlay = new DefaultMenuItem( "&Play\tSpace", movie, menuBar );
	DefaultMenuItem* moviePause = new DefaultMenuItem( "&Pause\tSpace", movie, menuBar );
	DefaultMenuItem* movieReset= new DefaultMenuItem( "&Reset", movie, menuBar );
	DefaultMenuItem* movieStop = new DefaultMenuItem( "&Stop\tEsc", movie, menuBar );	


	DefaultMenuItem* view = new DefaultMenuItem( "&View", root, menuBar );
	DefaultMenuItem* viewNormal = new DefaultMenuItem( "&Normal", view, menuBar );
	DefaultMenuItem* viewDouble = new DefaultMenuItem( "&200%", view, menuBar );
	DefaultMenuItem* viewHalf = new DefaultMenuItem( "&50%", view, menuBar );	


	sep = new DefaultMenuItem( "", view, menuBar );
	sep->setSeparator( true );
	DefaultMenuItem* viewResizable = new DefaultMenuItem( "&Resizeable", view, menuBar );
	DefaultMenuItem* viewLockAspectRatio = new DefaultMenuItem( "&Lock Aspect Ratio", view, menuBar );	

	sep = new DefaultMenuItem( "", view, menuBar );
	sep->setSeparator( true );

	DefaultMenuItem* viewSideBar = new DefaultMenuItem( "&Playlist", view, menuBar );

	DefaultMenuItem* viewMediaInfo = new DefaultMenuItem( "&Media Info", view, menuBar );
	DefaultMenuItem* viewSearch = new DefaultMenuItem( "&Search", view, menuBar );
	DefaultMenuItem* viewPlayControls = new DefaultMenuItem( "&Play Controls", view, menuBar );



	//add Help menu
	DefaultMenuItem* help = new DefaultMenuItem( "&Help", root, menuBar );
	DefaultMenuItem* helpAbout = new DefaultMenuItem( "About...", help, menuBar );	

	EventHandler* ev = new GenericEventHandler<MainQTWindow>( this, &MainQTWindow::onHelpAbout, "MainQTWindow::onHelpAbout" );
	helpAbout->addMenuItemClickedHandler( ev );
	


	EventHandler* windowClose = new WindowEventHandler<MainQTWindow>( this, MainQTWindow::onClose, "MainQTWindow::onClose" );
	FrameClose += windowClose;


	ImageList* il = new ImageList();
	il->setImageHeight( 16 );
	il->setImageWidth( 16 );
	il->setTransparentColor( &Color( 0.0, 1.0, 0.0) );
	addComponent( il );

	ResourceBundle* resBundle = Application::getRunningInstance()->getResourceBundle();
	Image* img = resBundle->getImage( "open" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "reset" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "play" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "pause" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "stop" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "viewnormal" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "view200" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "view50" );
	il->addImage( img );
	delete img;





	mediaBar_ = new Panel();
	mediaBar_->setBorder( NULL );
	mediaBar_->setHeight( 45 );
	add( mediaBar_, AlignTop );


	
	playPanel_ = new Panel() ;
	playPanel_->setWidth( 200 );
	playPanel_->setBorder( NULL );

	mediaBar_->add( playPanel_, AlignLeft );
	
	
	
	


	Toolbar* toolbar = new Toolbar();
	toolbar->setName( "Toolbar1" );
	toolbar->setEnableAutoResize( false );

	toolbar->setWidth( il->getImageWidth() * 5 );
	toolbar->setHeight( il->getImageHeight() * 1.5 );
	toolbar->setImageList( il );	
	

	playPanel_->add( toolbar, AlignTop );
	


	ImageControl* mute = new ImageControl();
	img = resBundle->getImage( "mute" );
	img->setTransparencyColor( &Color(0.0,1.0,0.0) );
	mute->setImage( img );
	mute->setTransparent( true );
	mute->setWidth( 11 );
	playPanel_->add( mute, AlignLeft );

	mute->MouseClicked += 
		new GenericEventHandler<MainQTWindow>( this, &MainQTWindow::onVolumeMute, "MainQTWindow::onVolumeMute" ) ;	


	volumeControl_ = new VCF::SliderControl();
	volumeControl_->setTickMarkStyle( SliderControl::tmsBottomRight );
	//volumeControl_->setHasTickMarks( false );
	volumeControl_->setMinValue( 0.0 );
	volumeControl_->setMaxValue( 100.0 );
	volumeControl_->setWidth( 100 );
	volumeControl_->setPosition( 100 );
	volumeControl_->PositionChanged += 
		new GenericEventHandler<MainQTWindow>( this, &MainQTWindow::onVolumeChanged, "MainQTWindow::onVolumeChanged" ) ;

	


	playPanel_->add( volumeControl_, AlignClient );

	ImageControl* fullVol = new ImageControl();
	img = resBundle->getImage( "fullvol" );
	img->setTransparencyColor( &Color(0.0,1.0,0.0) );
	fullVol->setImage( img );
	fullVol->setTransparent( true );
	fullVol->setWidth( 11 );
	playPanel_->add( fullVol, AlignRight );

	fullVol->MouseClicked += 
		new GenericEventHandler<MainQTWindow>( this, &MainQTWindow::onVolumeFull, "MainQTWindow::onVolumeFull" ) ;	

	



	Label* spacer = new Label();
	spacer->setWidth( 40 );
	spacer->setCaption( "" );
	mediaBar_->add( spacer, AlignLeft );




	Panel* currentMediaPanel = new Panel() ;
	currentMediaPanel->setBorder( NULL );
	mediaBar_->add( currentMediaPanel, AlignClient );

	QuickTimeScrubber* scrubber = new QuickTimeScrubber();
	scrubber->setHeight( scrubber->getPreferredHeight() );
	currentMediaPanel->add( scrubber, AlignBottom );
	

	mediaLabel_ = new Label();

	mediaLabel_->setWordWrap( true );
	mediaLabel_->setTextAlignment( taTextCenter );
	mediaLabel_->setVerticalAlignment( tvaTextCenter );
	mediaLabel_->setCaption( Application::getRunningInstance()->getName() + "\nNothing playing");
	mediaLabel_->setColor( &Color((unsigned char)214,(unsigned char)219,(unsigned char)191) );
	mediaLabel_->setTransparent( false );
	mediaLabel_->setUseColorForBackground( true );
	Light3DBorder* bdr = new Light3DBorder();
	bdr->setInverted( true );
	mediaLabel_->setBorder( bdr );
	currentMediaPanel->add( mediaLabel_, AlignClient );










	spacer = new Label();
	spacer->setWidth( 40 );
	spacer->setCaption( "" );
	mediaBar_->add( spacer, AlignRight );


	
	searchPanel_ = new Panel();

	searchPanel_->setBorder( NULL );
	searchPanel_->setWidth( 200 );
	mediaBar_->add( searchPanel_, AlignRight );



	ImageControl* searchIcon = new ImageControl();
	img = resBundle->getImage( "search" );
	img->setTransparencyColor( &Color(0.0,1.0,0.0) );
	searchIcon->setImage( img );
	searchIcon->setTransparent( true );

	searchIcon->MouseClicked += new GenericEventHandler<MainQTWindow>( this,	&MainQTWindow::onSearchIconClick, "MainQTWindow::onSearchIconClick" );

	searchIcon->setBounds( 1, 1, 17, 17 );

	searchPanel_->add( searchIcon );

	PopupMenu* pm = new PopupMenu();
	DefaultMenuItem* pmRoot = new DefaultMenuItem("root",NULL,pm);

	DefaultMenuItem* pmItem = new DefaultMenuItem( "Edit/Create a search Catalog...", pmRoot,pm );

	pm->setRootMenuItem( pmRoot );

	searchIcon->setPopupMenu( pm );


	TextControl* searchText = new TextControl();
	searchText->setBounds( searchIcon->getRight() + 1, 1, 100, searchIcon->getPreferredHeight() );  
	searchPanel_->add( searchText );

	searchText->KeyUp += new KeyboardEventHandler<MainQTWindow>( this, &MainQTWindow::onSearchTextEntered, "MainQTWindow::onSearchTextEntered" );



	/*
	img = resBundle->getImage( "fullvol" );
	il->addImage( img );
	delete img;

	img = resBundle->getImage( "mute" );
	il->addImage( img );
	delete img;
*/


	ToolbarItem* open = toolbar->addToolBarButton( "Open" );
	open->setTooltip( "Open" );
	open->setImageIndex( 0 );

	toolbar->addToolBarButton("")->setAsSeparator();

	ToolbarItem* reset = toolbar->addToolBarButton( "Reset" );
	reset->setTooltip( "Reset" );
	reset->setImageIndex( 1 );
	ToolbarItem* play = toolbar->addToolBarButton( "Play" );
	play->setTooltip( "Play" );
	play->setImageIndex( 2 );
	play->setGrouped(true);
	play->setChecked( true );
	ToolbarItem* pause = toolbar->addToolBarButton( "Pause" );
	pause->setImageIndex( 3 );
	pause->setTooltip( "Pause" );
	pause->setGrouped(true);
	pause->setChecked( true );
	ToolbarItem* stop = toolbar->addToolBarButton( "Stop" );
	stop->setImageIndex( 4 );
	stop->setTooltip( "Stop" );
	stop->setGrouped(true);
	stop->setChecked( true );

	
	/**
	Actions - this is where the various UI elements get hooked up
	*/


	Action* openAction = new Action();
	addComponent( openAction );
	openAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onFileOpenMovie, "MainQTWindow::onFileOpenMovie" );

	openAction->addTarget( open );
	openAction->addTarget( fileOpen );


	Action* fileCloseAction = new Action(this);
	fileCloseAction->Performed += 
		new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onFileCloseMovie, "MainQTWindow::onFileCloseMovie" );
	fileCloseAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateFileCloseMovie, "MainQTWindow::updateFileCloseMovie" );
		
	fileCloseAction->addTarget( fileClose );
	

	Action* resetAction = new Action();
	addComponent( resetAction );
	resetAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMovieReset, "MainQTWindow::onMovieReset" );
	resetAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateReset, "MainQTWindow::updateReset" );

	resetAction->addTarget( reset );
	resetAction->addTarget( movieReset );

	Action* playAction = new Action();
	addComponent( playAction );
	playAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMoviePlay, "MainQTWindow::onMoviePlay" );
	playAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updatePlay, "MainQTWindow::updatePlay" );


	playAction->addTarget( play );
	playAction->addTarget( moviePlay );


	Action* pauseAction = new Action();
	addComponent( pauseAction );
	pauseAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMoviePause, "MainQTWindow::onMoviePause" );
	pauseAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updatePause, "MainQTWindow::updatePause" );

	pauseAction->addTarget( pause );
	pauseAction->addTarget( moviePause );


	Action* stopAction = new Action();
	addComponent( stopAction );
	stopAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMovieStop, "MainQTWindow::onMovieStop" );
	stopAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateStop, "MainQTWindow::updateStop" );


	stopAction->addTarget( stop );
	stopAction->addTarget( movieStop );


	Action* exitAction = new Action();
	addComponent( exitAction );
	exitAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onFileExit, "MainQTWindow::onFileExit" );

	exitAction->addTarget( fileExit );


	Action* viewNormalAction = new Action();
	addComponent( viewNormalAction );
	viewNormalAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewNormal, "MainQTWindow::onViewNormal" );
	viewNormalAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewNormal, "MainQTWindow::updateViewNormal" );


	viewNormalAction->addTarget( viewNormal );
	


	Action* viewDoubleAction = new Action();
	addComponent( viewDoubleAction );
	viewDoubleAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewDouble, "MainQTWindow::onViewDouble" );
	viewDoubleAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewDouble, "MainQTWindow::updateViewDouble" );
	
	viewDoubleAction->addTarget( viewDouble );



	Action* viewHalfAction = new Action();
	addComponent( viewHalfAction );
	viewHalfAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewHalf, "MainQTWindow::onViewHalf" );
	viewHalfAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewHalf, "MainQTWindow::updateViewHalf" );

	viewHalfAction->addTarget( viewHalf );



	Action* viewLockAspectRatioAction = new Action();
	addComponent( viewLockAspectRatioAction );
	viewLockAspectRatioAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewLockAspectRatio, "MainQTWindow::onViewLockAspectRatio" );
	viewLockAspectRatioAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewLock, "MainQTWindow::updateViewLock" );

	viewLockAspectRatioAction->addTarget( viewLockAspectRatio );



	Action* viewAllowResizeAction = new Action();
	addComponent( viewAllowResizeAction );
	viewAllowResizeAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewAllowResize, "MainQTWindow::onViewAllowResize" );
	viewAllowResizeAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewAllowResize, "MainQTWindow::updateViewAllowResize" );
	
	viewAllowResizeAction->addTarget( viewResizable );



	Action* viewSideBarAction = new Action();
	addComponent( viewSideBarAction );
	viewSideBarAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewSideBar, "MainQTWindow::onViewSideBar" );
	viewSideBarAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewSideBar, "MainQTWindow::updateViewSideBar" );
		
	viewSideBarAction->addTarget( viewSideBar );

	Action* viewMediaInfoAction = new Action(this);
	viewMediaInfoAction->Performed += 
		new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewMediaInfo, "MainQTWindow::onViewMediaInfo" );
	viewMediaInfoAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewMediaInfo, "MainQTWindow::updateViewMediaInfo" );
		
	viewMediaInfoAction->addTarget( viewMediaInfo );

	

	Action* viewSearchAction = new Action(this);
	viewSearchAction->Performed += 
		new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewSearch, "MainQTWindow::onViewSearch" );
	viewSearchAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewSearch, "MainQTWindow::updateViewSearch" );
		
	viewSearchAction->addTarget( viewSearch );

	Action* viewPlayControlsAction = new Action(this);
	viewPlayControlsAction->Performed += 
		new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewPlayControls, "MainQTWindow::onViewPlayControls" );
	viewPlayControlsAction->Update += 
		new EventHandlerInstance<MainQTWindow,ActionEvent>(this, &MainQTWindow::updateViewPlayControls, "MainQTWindow::updateViewPlayControls" );
		
	viewPlayControlsAction->addTarget( viewPlayControls );



	mainViewPanel_ = new Panel();
	mainViewPanel_->setBorder( NULL );

	mainViewPanel_->setContainer( new PagedContainer() );
	add( mainViewPanel_, AlignClient );
	

	quicktimeControl_ = new QuickTimeControl();
	Light3DBorder* border = new Light3DBorder();
	border->setInverted( true );
	quicktimeControl_->setBorder( border );
	EventHandler* movieChanged = getEventHandler( "MainQTWindow::onMovieChanged" );
	if ( NULL == movieChanged ) {
		movieChanged = 
			new GenericEventHandler<MainQTWindow>( this, MainQTWindow::onMovieChanged, "MainQTWindow::onMovieChanged" );
	}		
	
	quicktimeControl_->MovieChanged += movieChanged;
	
	mainViewPanel_->add( quicktimeControl_ );

	scrubber->setQuickTimeControl( quicktimeControl_ );
	






	
	/**
	Add accellerators
	*/
	
	addAcceleratorKey( vkSpaceBar, 
						kmUndefined, 
						new KeyboardEventHandler<MainQTWindow>( this, &MainQTWindow::onKeyHandler, "MainQTWindow::onKeyHandler" ) );

						

	addAcceleratorKey( vkUpArrow, kmUndefined, getEventHandler( "MainQTWindow::onKeyHandler" ) );
	addAcceleratorKey( vkDownArrow, kmUndefined, getEventHandler( "MainQTWindow::onKeyHandler" ) );
	addAcceleratorKey( vkLeftArrow, kmUndefined, getEventHandler( "MainQTWindow::onKeyHandler" ) );
	addAcceleratorKey( vkRightArrow, kmUndefined, getEventHandler( "MainQTWindow::onKeyHandler" ) );


	addAcceleratorKey( vkLetterO, kmCtrl, getEventHandler( "MainQTWindow::onFileOpenMovie" ) );	

	addAcceleratorKey( vkEscape, kmUndefined, getEventHandler( "MainQTWindow::onMovieStop" ) );	
	addAcceleratorKey( vkLetterC, kmUndefined, getEventHandler( "MainQTWindow::onFileCloseMovie" ) );	



	VCF::DropTarget* qtDropTarget = new VCF::DropTarget( quicktimeControl_ );
	qtDropTarget->setName( "qtDropTarget" );
	addComponent( qtDropTarget );

	qtDropTarget->DropTargetDraggingOver += 
			new VCF::DropEventHandler<MainQTWindow>( this, &MainQTWindow::onDraggingOver, "MainQTWindow::onDraggingOver" );

	qtDropTarget->DropTargetDropped += 
			new VCF::DropEventHandler<MainQTWindow>( this, &MainQTWindow::onFilesDropped, "MainQTWindow::onFilesDropped" );



	sideBar_ = new Panel();
	sideBar_->setWidth( 200 );
	sideBar_->setBorder( NULL );
	sideBar_->setBorderSize( 5 );
	add( sideBar_, AlignLeft );


	Splitter* splitter = new Splitter();
	add( splitter, AlignLeft );


	playListTree_ = new TreeControl();
	playListTree_->setVisible( true );
	sideBar_->add( playListTree_, AlignClient );
	
	TitledBorder* tb = new TitledBorder();
	tb->setCaption( "Media Info" );
	mediaInfo_ = new MediaInfoPanel();
	mediaInfo_->setBorder( tb );	
	sideBar_->add( mediaInfo_, AlignBottom );
}

MainQTWindow::~MainQTWindow()
{
	
}

void MainQTWindow::onViewSideBar(  VCF::Event* event )
{
	sideBar_->setVisible( !sideBar_->getVisible() );
}

void MainQTWindow::updateViewSideBar( VCF::ActionEvent* e )
{
	e->setChecked( sideBar_->getVisible() );
}

void MainQTWindow::onDraggingOver( VCF::DropTargetEvent* e )
{
	DataObject* dataObj = e->getDataObject();
	if ( dataObj->isTypeSupported( FILE_DATA_TYPE ) ) {
		e->setActionType( daCopy );
	}
	else {
		e->setActionType( daNone );
	}
}

void MainQTWindow::onFilesDropped( VCF::DropTargetEvent* e )
{
	DataObject* dataObj = e->getDataObject();
	if ( dataObj->isTypeSupported( FILE_DATA_TYPE ) ) {
		//create a basic output stream to write the data to
		BasicOutputStream stream;
		
		//write the data in the data object to the stream
		if ( dataObj->saveToStream( FILE_DATA_TYPE, &stream ) ) {
			//create a string from the output streams data
			String fileNames;
			fileNames.append( (VCF::WideChar*)stream.getBuffer(), stream.getSize()/sizeof(VCF::WideChar) );
			
			//create a string tokenizer, with the delimeter set to '\n'
			StringTokenizer tok( fileNames, "\n");

			//enumerate through all the file names - open the first for now
			
			if ( tok.hasMoreElements() ) {				
				movieLoaded_ = false;
				if ( !quicktimeControl_->open( tok.nextElement() ) ) {											
					((MediaInfoPanel*)mediaInfo_)->setMovie( NULL );
				}
			}
		}
	}
}

void MainQTWindow::onFileOpenMovie( Event* e )
{
	movieLoaded_ = false;
	CommonFileOpen openDlg( this );	
	openDlg.addFilter( "Quicktime Movie", "*.mov" );
	openDlg.addFilter( "MPEG movies", "*.mpg;*.mpeg" );
	openDlg.addFilter( "AVI movies", "*.avi" );
	openDlg.addFilter( "Soundtracks", "*.mp3;*.wav;*.au;*.aac;*.mid" );
	openDlg.addFilter( "All Files", "*.*" );
	if ( true == openDlg.execute() ) {
		if ( !quicktimeControl_->open( openDlg.getFileName() ) ) {				
			((MediaInfoPanel*)mediaInfo_)->setMovie( NULL );
		}
	}
	
}

void MainQTWindow::onFileExit( Event* e )
{
	close();
}

void MainQTWindow::onHelpAbout( Event* e )
{
	QTPlayerAbout aboutDlg;

	aboutDlg.showModal();
	
}


void MainQTWindow::onMoviePlay( VCF::Event* e )
{
	quicktimeControl_->getMovie()->play();
}

void MainQTWindow::onMovieReset( VCF::Event* e )
{
	quicktimeControl_->getMovie()->reset();
}

void MainQTWindow::onMovieStop( VCF::Event* e )
{
	quicktimeControl_->getMovie()->stop();
}

void MainQTWindow::onMoviePause( VCF::Event* e )
{
	quicktimeControl_->getMovie()->pause();
}

void MainQTWindow::onMovieChanged( Event* movieEvent )
{
	EventHandler* movieFrameChanged = getEventHandler( "MainQTWindow::onMovieFrameChanged" );
	if ( NULL == movieFrameChanged ) {
		movieFrameChanged = 
			new GenericEventHandler<MainQTWindow>( this, MainQTWindow::onMovieFrameChanged, "MainQTWindow::onMovieFrameChanged" );
	}
	
	QuickTimeMovie* movie = quicktimeControl_->getMovie();
	if ( NULL != movie ) {
		movie->MovieFrameChanged += movieFrameChanged;
	}

	movieLoaded_ = true;
	
	short vol = (volumeControl_->getPosition()/100.0) * 255.0;	
	
	((MediaInfoPanel*)mediaInfo_)->setMovie( movie );
	
	::SetMovieVolume( *movie, vol );
	
	setCaption( Application::getRunningInstance()->getName() + L" - " + movie->getTitle() );

	mediaLabel_->setCaption( movie->getTitle() + "\n00:00:00" );

	onMoviePlay( NULL );
}

void MainQTWindow::onMovieFrameChanged( Event* movieEvent )
{
	QuickTimeMovie* movie = (QuickTimeMovie*) movieEvent->getSource();

	static double prev = 0;

	TimeRecord time = movie->getCurrentTime();

	double scale = time.scale;	
	double seconds = time.value.lo / scale;
	
	int i_seconds = seconds;
	int hours = i_seconds / 3600;
	i_seconds = i_seconds - (hours*3600);
	int minutes = i_seconds / 60;
	i_seconds = i_seconds - (minutes*60);

	short tmp = ::GetMovieVolume( *movie ) * 100;
	int volume = tmp / 255;

	String s = StringUtils::format( "%02d:%02d:%02d", hours, minutes, i_seconds );		

	mediaLabel_->setCaption( movie->getTitle() + "\n" + s );
}

void MainQTWindow::onClose( VCF::WindowEvent* event )
{
	QuickTimeMovie* movie = quicktimeControl_->getMovie();
	if ( NULL != movie ) {
		movie->stop();
		movie->close();
	}
}

void MainQTWindow::onViewNormal( VCF::Event* e )
{
	quicktimeControl_->setViewNormalSize();
}

void MainQTWindow::onViewDouble( VCF::Event* e )
{
	quicktimeControl_->setViewDoubleSize();
}

void MainQTWindow::onViewHalf( VCF::Event* e )
{
	quicktimeControl_->setViewHalfSize();
}

void MainQTWindow::onViewLockAspectRatio( VCF::Event* e )
{
	quicktimeControl_->setLockAspectRatio( !quicktimeControl_->getLockAspectRatio() );
}

void MainQTWindow::onViewAllowResize( VCF::Event* e )
{
	quicktimeControl_->setAllowsResizing( !quicktimeControl_->getAllowsResizing() );
}

void MainQTWindow::updatePlay( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );

	QuickTimeMovie* movie = quicktimeControl_->getMovie();

	if ( movie->isPlaying() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}
}

void MainQTWindow::updateReset( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );

}

void MainQTWindow::updateStop( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );
	QuickTimeMovie* movie = quicktimeControl_->getMovie();

	if ( movie->isStopped() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}
}

void MainQTWindow::updatePause( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );

	QuickTimeMovie* movie = quicktimeControl_->getMovie();

	if ( movie->isPaused() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}
}

void MainQTWindow::updateViewNormal( VCF::ActionEvent* e )
{
	if ( quicktimeControl_->isNormalSize() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}

	e->setEnabled( movieLoaded_ );
}

void MainQTWindow::updateViewDouble( VCF::ActionEvent* e )
{	
	if ( quicktimeControl_->isDoubleSize() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}

	e->setEnabled( movieLoaded_ );
}

void MainQTWindow::updateViewHalf( VCF::ActionEvent* e )
{
	if ( quicktimeControl_->isHalfSize() ) {
		e->setChecked( true );
		e->setState( e->getState() | ToolbarItem::tisPressed );
	}
	else {
		e->setChecked( false );
		e->setState( e->getState() & ~ToolbarItem::tisPressed );
	}
	e->setEnabled( movieLoaded_ );
}

void MainQTWindow::updateViewLock( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );
	e->setChecked( quicktimeControl_->getLockAspectRatio() );
}

void MainQTWindow::updateViewAllowResize( VCF::ActionEvent* e )
{
	e->setEnabled( movieLoaded_ );
	e->setChecked( quicktimeControl_->getAllowsResizing() );
}

void MainQTWindow::onVolumeChanged( VCF::Event* event )
{
	short vol = (volumeControl_->getPosition()/100.0) * 255.0;

	QuickTimeMovie& movie = *quicktimeControl_->getMovie();	

	::SetMovieVolume( movie, vol );

	vol = ::GetMovieVolume( movie ) * 100;
}

void MainQTWindow::onVolumeMute( VCF::Event* event )
{
	volumeControl_->setPosition( 0 );
}

void MainQTWindow::onVolumeFull( VCF::Event* event )
{
	volumeControl_->setPosition( 25500 / 100 );
}

void MainQTWindow::onKeyHandler( VCF::KeyboardEvent* event )
{
	QuickTimeMovie& movie = *quicktimeControl_->getMovie();	

	switch ( event->getVirtualCode() ) {
		case vkRightArrow : {
			if ( movie.isPlaying() ){
				onMoviePause( NULL );
			}

			movie.nextFrame();
		}
		break;

		case vkLeftArrow : {
			if ( movie.isPlaying() ){
				onMoviePause( NULL );
			}

			movie.previousFrame();
		}
		break;

		case vkUpArrow : {
			volumeControl_->setPosition( minVal<int>( 100, 10 + volumeControl_->getPosition() ) );
		}
		break;

		case vkDownArrow : {
			volumeControl_->setPosition( maxVal<int>( 0, volumeControl_->getPosition() - 10 ) );
		}
		break;

		case vkSpaceBar : {
			if ( movie.isPlaying() ){
				onMoviePause( NULL );
			}
			else {
				onMoviePlay( NULL );
			}
		}
		break;
	}
}

void MainQTWindow::onViewMediaInfo(  VCF::Event* event )
{
	mediaInfo_->setVisible( !mediaInfo_->getVisible() );
}

void MainQTWindow::updateViewMediaInfo( VCF::ActionEvent* e )
{
	e->setChecked( mediaInfo_->getVisible() );
	e->setEnabled( sideBar_->getVisible() );
}

void MainQTWindow::onFileCloseMovie( VCF::Event* e )
{
	onMovieStop(NULL);
	QuickTimeMovie& movie = *quicktimeControl_->getMovie();
	movie.close();	

	mediaLabel_->setCaption( Application::getRunningInstance()->getName() + "\nNothing playing");

	quicktimeControl_->repaint();

	movieLoaded_ = false;

	((MediaInfoPanel*)mediaInfo_)->setMovie( NULL );
}

void MainQTWindow::updateFileCloseMovie( VCF::ActionEvent* e )
{
	QuickTimeMovie& movie = *quicktimeControl_->getMovie();	

	e->setEnabled( movie.isOpen() );
}


void MainQTWindow::onViewSearch(  VCF::Event* event )
{
	searchPanel_->setVisible( !searchPanel_->getVisible() );
}

void MainQTWindow::updateViewSearch( VCF::ActionEvent* e )
{
	e->setChecked( searchPanel_->getVisible() );
}

void MainQTWindow::onViewPlayControls(  VCF::Event* event )
{
	playPanel_->setVisible( !playPanel_->getVisible() );
}

void MainQTWindow::updateViewPlayControls( VCF::ActionEvent* e )
{
	e->setChecked( playPanel_->getVisible() );
}

void MainQTWindow::onSearchIconClick( VCF::Event* e )
{
	Control* control = (Control*) e->getSource();
	PopupMenu* pm = control->getPopupMenu();

	VCF::Point pt = control->getBounds().getBottomLeft();
	pm->popup( &pt );
}

void MainQTWindow::onSearchTextEntered( VCF::KeyboardEvent* e )
{

	TextControl* textCtrl = (TextControl*)e->getSource();
	StringUtils::traceWithArgs( "Searching for \"" + textCtrl->getTextModel()->getText() + "\"...\n" );
}