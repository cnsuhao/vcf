//MainWindow.h
#include "ApplicationKit.h"
#include "ControlsKit.h"
#include "MainWindow.h"
#include "QTPlayerApplication.h"
#include "QTPlayerAbout.h"
#include "QuickTimeControl.h"
#include "utils/StringTokenizer.h"

using namespace VCF;



MainQTWindow::MainQTWindow():
	m_quicktimeControl(NULL)
{
	//build main menu
	MenuBar* menuBar = new MenuBar();
	addComponent( menuBar );
	this->setMenuBar( menuBar );
	MenuItem* root = menuBar->getRootMenuItem();
	
	DefaultMenuItem* file = new DefaultMenuItem( "&File", root, menuBar );

	DefaultMenuItem* fileOpen = new DefaultMenuItem( "&Open...", file, menuBar );

	DefaultMenuItem* sep = new DefaultMenuItem( "", file, menuBar );
	sep->setSeparator( true );
	
	DefaultMenuItem* fileExit = new DefaultMenuItem( "E&xit", file, menuBar );


	DefaultMenuItem* movie = new DefaultMenuItem( "&Movie", root, menuBar );	
	DefaultMenuItem* moviePlay = new DefaultMenuItem( "&Play...", movie, menuBar );
	DefaultMenuItem* moviePause = new DefaultMenuItem( "&Pause...", movie, menuBar );
	DefaultMenuItem* movieReset= new DefaultMenuItem( "&Reset...", movie, menuBar );
	DefaultMenuItem* movieStop = new DefaultMenuItem( "&Stop...", movie, menuBar );	


	DefaultMenuItem* view = new DefaultMenuItem( "&View", root, menuBar );
	DefaultMenuItem* viewNormal = new DefaultMenuItem( "&Normal", view, menuBar );
	DefaultMenuItem* viewDouble = new DefaultMenuItem( "&200%", view, menuBar );
	DefaultMenuItem* viewHalf = new DefaultMenuItem( "&50%", view, menuBar );	


	sep = new DefaultMenuItem( "", view, menuBar );
	sep->setSeparator( true );
	DefaultMenuItem* viewResizable = new DefaultMenuItem( "&Resizable", view, menuBar );
	DefaultMenuItem* viewLockAspectRatio = new DefaultMenuItem( "&Lock Aspect Ratio", view, menuBar );	

	//add Help menu
	DefaultMenuItem* help = new DefaultMenuItem( "&Help", root, menuBar );
	DefaultMenuItem* helpAbout = new DefaultMenuItem( "About...", help, menuBar );	


	EventHandler* windowClose = new WindowEventHandler<MainQTWindow>( this, MainQTWindow::onClose, "MainQTWindow::onClose" );
	FrameClose += windowClose;


	
	
	Toolbar* toolbar = new Toolbar();
	toolbar->setName( "Toolbar1" );
	toolbar->setHeight( 25 );
	add( toolbar, AlignTop );
	
	ImageList* il = new ImageList();
	il->setImageHeight( 16 );
	il->setImageWidth( 16 );
	il->setTransparentColor( &Color( 0.0, 1.0, 0.0) );
	addComponent( il );
	
	toolbar->setImageList( il );


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



	ToolbarItem* open = toolbar->addToolBarButton( "Open" );
	open->setImageIndex( 0 );

	toolbar->addToolBarButton("")->setAsSeparator();

	ToolbarItem* reset = toolbar->addToolBarButton( "Reset" );
	reset->setImageIndex( 1 );
	ToolbarItem* play = toolbar->addToolBarButton( "Play" );
	play->setImageIndex( 2 );
	ToolbarItem* pause = toolbar->addToolBarButton( "Pause" );
	pause->setImageIndex( 3 );
	ToolbarItem* stop = toolbar->addToolBarButton( "Stop" );
	stop->setImageIndex( 4 );





	/**
	Actions - this is where the various UI elements get hooked up
	*/


	Action* openAction = new Action();
	addComponent( openAction );
	openAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onFileOpenMovie, "MainQTWindow::onFileOpenMovie" );

	openAction->addTarget( open );
	openAction->addTarget( fileOpen );
	

	Action* resetAction = new Action();
	addComponent( resetAction );
	resetAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMovieReset, "MainQTWindow::onMovieReset" );

	resetAction->addTarget( reset );
	resetAction->addTarget( movieReset );

	Action* playAction = new Action();
	addComponent( playAction );
	playAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMoviePlay, "MainQTWindow::onMoviePlay" );

	playAction->addTarget( play );
	playAction->addTarget( moviePlay );


	Action* pauseAction = new Action();
	addComponent( pauseAction );
	pauseAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMoviePause, "MainQTWindow::onMoviePause" );

	pauseAction->addTarget( pause );
	pauseAction->addTarget( moviePause );


	Action* stopAction = new Action();
	addComponent( stopAction );
	stopAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onMovieStop, "MainQTWindow::onMovieStop" );

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

	viewNormalAction->addTarget( viewNormal );


	Action* viewDoubleAction = new Action();
	addComponent( viewDoubleAction );
	viewDoubleAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewDouble, "MainQTWindow::onViewDouble" );
	
	viewDoubleAction->addTarget( viewDouble );



	Action* viewHalfAction = new Action();
	addComponent( viewHalfAction );
	viewHalfAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewHalf, "MainQTWindow::onViewHalf" );

	viewHalfAction->addTarget( viewHalf );



	Action* viewLockAspectRatioAction = new Action();
	addComponent( viewLockAspectRatioAction );
	viewLockAspectRatioAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewLockAspectRatio, "MainQTWindow::onViewLockAspectRatio" );

	viewLockAspectRatioAction->addTarget( viewLockAspectRatio );



	Action* viewAllowResizeAction = new Action();
	addComponent( viewAllowResizeAction );
	viewAllowResizeAction->Performed += 
			new GenericEventHandler<MainQTWindow>(this, &MainQTWindow::onViewAllowResize, "MainQTWindow::onViewAllowResize" );
	
	viewAllowResizeAction->addTarget( viewResizable );

		
		







	m_quicktimeControl = new QuickTimeControl();
	Light3DBorder* border = new Light3DBorder();
	border->setInverted( true );
	m_quicktimeControl->setBorder( border );
	EventHandler* movieChanged = getEventHandler( "MainQTWindow::onMovieChanged" );
	if ( NULL == movieChanged ) {
		movieChanged = 
			new GenericEventHandler<MainQTWindow>( this, MainQTWindow::onMovieChanged, "MainQTWindow::onMovieChanged" );
	}		
	
	m_quicktimeControl->MovieChanged += movieChanged;
	
	add( m_quicktimeControl, AlignClient );


	Panel* bottom = new Panel();
	bottom->setBorder( NULL );
	bottom->setHeight( bottom->getPreferredHeight() );
	add( bottom, AlignBottom );

	m_timerLabel = new Label();
	m_timerLabel->setWidth( 100 );
	m_timerLabel->setTextAlignment( taTextCenter ) ;
	m_timerLabel->setVerticalAlignment( tvaTextCenter );
	Light3DBorder* border2 = new Light3DBorder();
	border2->setInverted( true );
	m_timerLabel->setBorder( border2 );
	bottom->add( m_timerLabel, AlignLeft );

	
	QuickTimeScrubber* scrubber = new QuickTimeScrubber();
	scrubber->setHeight( scrubber->getPreferredHeight() );
	bottom->add( scrubber, AlignClient );
	scrubber->setQuickTimeControl( m_quicktimeControl );
	

	VCF::DropTarget* qtDropTarget = new VCF::DropTarget( m_quicktimeControl );
	qtDropTarget->setName( "qtDropTarget" );
	addComponent( qtDropTarget );

	qtDropTarget->DropTargetDraggingOver += 
			new VCF::DropEventHandler<MainQTWindow>( this, &MainQTWindow::onDraggingOver, "MainQTWindow::onDraggingOver" );

	qtDropTarget->DropTargetDropped += 
			new VCF::DropEventHandler<MainQTWindow>( this, &MainQTWindow::onFilesDropped, "MainQTWindow::onFilesDropped" );
}

MainQTWindow::~MainQTWindow()
{
	
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
			fileNames.append( stream.getBuffer(), stream.getSize() );
			
			//create a string tokenizer, with the delimeter set to '\n'
			StringTokenizer tok( fileNames, "\n");

			//enumerate through all the file names - open the first for now
			
			if ( tok.hasMoreElements() ) {				
				
				if ( m_quicktimeControl->open( tok.nextElement() ) ) {	
					
					m_quicktimeControl->getMovie()->play();
				}
			}
		}
	}
}

void MainQTWindow::onFileOpenMovie( Event* e )
{
	
	CommonFileOpen openDlg( this );	
	openDlg.addFilter( "Quicktime Movie", "*.mov" );
	openDlg.addFilter( "MPEG movies", "*.mpg;*.mpeg" );
	openDlg.addFilter( "All Files", "*.*" );
	if ( true == openDlg.execute() ) {
		if ( m_quicktimeControl->open( openDlg.getFileName() ) ) {	
			
			m_quicktimeControl->getMovie()->play();

		}
		else {
			
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
	m_quicktimeControl->getMovie()->play();
}

void MainQTWindow::onMovieReset( VCF::Event* e )
{
	m_quicktimeControl->getMovie()->reset();
}

void MainQTWindow::onMovieStop( VCF::Event* e )
{
	m_quicktimeControl->getMovie()->stop();
}

void MainQTWindow::onMoviePause( VCF::Event* e )
{
	m_quicktimeControl->getMovie()->pause();
}

void MainQTWindow::onMovieChanged( Event* movieEvent )
{
	EventHandler* movieFrameChanged = getEventHandler( "MainQTWindow::onMovieFrameChanged" );
	if ( NULL == movieFrameChanged ) {
		movieFrameChanged = 
			new GenericEventHandler<MainQTWindow>( this, MainQTWindow::onMovieFrameChanged, "MainQTWindow::onMovieFrameChanged" );
	}
	
	QuickTimeMovie* movie = m_quicktimeControl->getMovie();
	if ( NULL != movie ) {
		movie->MovieFrameChanged += movieFrameChanged;
	}
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

	String s = StringUtils::format( "%02d:%02d:%02d", hours, minutes, i_seconds );
	m_timerLabel->setCaption( s );
}

void MainQTWindow::onClose( VCF::WindowEvent* event )
{
	QuickTimeMovie* movie = m_quicktimeControl->getMovie();
	if ( NULL != movie ) {
		movie->stop();
		movie->close();
	}
}

void MainQTWindow::onViewNormal( VCF::Event* e )
{
	//MenuItem* item = (MenuItem*)e->getSource();
	//item->setRadioItem( true );
}

void MainQTWindow::onViewDouble( VCF::Event* e )
{
	//MenuItem* item = (MenuItem*)e->getSource();
	//item->setRadioItem( true );
}

void MainQTWindow::onViewHalf( VCF::Event* e )
{
	//MenuItem* item = (MenuItem*)e->getSource();
	//item->setRadioItem( true );
}

void MainQTWindow::onViewLockAspectRatio( VCF::Event* e )
{
	m_quicktimeControl->setLockAspectRatio( !m_quicktimeControl->getLockAspectRatio() );
}

void MainQTWindow::onViewAllowResize( VCF::Event* e )
{
	m_quicktimeControl->setAllowsResizing( !m_quicktimeControl->getAllowsResizing() );
}

void MainQTWindow::onViewSizeUpdate( VCF::Event* e )
{
	
}

void MainQTWindow::onViewLockUpdate( VCF::Event* e )
{
	//MenuItem* item = (MenuItem*)e->getSource();
	//item->setChecked( m_quicktimeControl->getLockAspectRatio() );
}

void MainQTWindow::onViewAllowResizeUpdate( VCF::Event* e )
{
	//MenuItem* item = (MenuItem*)e->getSource();
	//item->setChecked( m_quicktimeControl->getAllowsResizing() );
}


