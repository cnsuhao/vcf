//MainWindow.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "MainWindow.h"

#include "vcf/ApplicationKit/DefaultMenuItem.h"
#include "vcf/ApplicationKit/DefaultListItem.h"
#include "vcf/ApplicationKit/TitledBorder.h"
#include "vcf/ApplicationKit/EtchedBorder.h"

#include "ControlsApplication.h"
#include "ControlsAbout.h"
#include "Spacers.h"

using namespace VCF;



MainWindow::MainWindow()
{
	this->setWidth( 600 );
	this->setHeight( 610 );
	
	//build main menu
	MenuBar* menuBar = new MenuBar( this );
	this->setMenuBar( menuBar );
	
	MenuItem* root = menuBar->getRootMenuItem();
	EventHandler* menuItemHandler = NULL;

	//add Help menu
	DefaultMenuItem* help = new DefaultMenuItem( "&Help", root, menuBar );
	DefaultMenuItem* helpAbout = new DefaultMenuItem( "About...", help, menuBar );
	menuItemHandler = new MenuItemEventHandler<MainWindow>(this, MainWindow::onHelpAbout, "helpAbout" );	
	helpAbout->addMenuItemClickedHandler( menuItemHandler );	

	//add TabbedPages
	mainPages = new TabbedPages();	
	mainPages->setBorderWidth( 4 );
	( (StandardContainer*)mainPages->getContainer() )->setBorderWidth( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta) );
	this->add( mainPages, AlignClient );

	//add individual TabPage here.
	listBoxPage = mainPages->addNewPage( "ListBoxControl" );	
	makeListBoxPage();

	bordersPage = mainPages->addNewPage( "Borders" );
	makeBordersPage();

	mainPagesModel = mainPages->getModel();
	mainPagesModel->setSelectedPage( listBoxPage );				
	setVisible( true );	
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::onHelpAbout( MenuItemEvent* e )
{
	ControlsAbout aboutDlg;

	aboutDlg.showModal();
	
}


// begin listBoxPage code
void MainWindow::makeListBoxPage()
{
	double borderWidth = UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta);

	Panel* panel1 = (Panel*)listBoxPage->getPageComponent();

	//add a panel for ListBoxControl-related controls
	Panel* listBoxGroup = new Panel();	
	( (StandardContainer*)listBoxGroup->getContainer() )->setBorderWidth( borderWidth );	
	listBoxGroup->setBorder( new TitledBorder( "ListBoxControl" ) );
	listBoxGroup->setWidth( 160 );	
	panel1->add( listBoxGroup, AlignLeft );
	
	//add a ListBoxControl
	listBox1 = new ListBoxControl();		
	listBox1->setBorder( new Basic3DBorder( true ) );
	listBox1->setAllowsMultiSelect( false );
	//add scrollbar to listBox1
	ScrollbarManager* scrollbarManagerSingle = new ScrollbarManager();
	addComponent( scrollbarManagerSingle );
	scrollbarManagerSingle->setHasVerticalScrollbar( true );
	scrollbarManagerSingle->setHasHorizontalScrollbar( true );		
	scrollbarManagerSingle->setTarget( listBox1 );
	scrollbarManagerSingle->setKeepScrollbarsVisible( true );
	//add some items to listBox1
	ListModel* listBoxModel = listBox1->getListModel();	
	for(int j=0; j<10; j++){
		String indx = StringUtils::toString(j);
		String capt = L"ListItem " + indx;		
		listBoxModel->addItem( new DefaultListItem( listBoxModel, capt ) );			
	}
	listBoxModel->addItem( new DefaultListItem( listBoxModel, "Add your own item below." ) );
	
	listBoxGroup->add( listBox1, AlignClient );	

	listBoxGroup->add( new VerticalSpacer( borderWidth ), AlignBottom );
	
	CommandButton* btnDeselect = new CommandButton();	
	btnDeselect->setCaption( "Deselect all" );
	btnDeselect->setHeight( 24 );
	listBoxGroup->add( btnDeselect, AlignBottom );
	
	listBoxGroup->add( new VerticalSpacer( borderWidth ), AlignBottom );	
		
	CommandButton* btnRemove = new CommandButton();	
	btnRemove->setCaption( "Remove selected item" );
	btnRemove->setHeight( 24 );
	listBoxGroup->add( btnRemove, AlignBottom );	

	listBoxGroup->add( new VerticalSpacer( 20 ), AlignBottom );
	
	//add a panel for Adding items	
	Panel* listBoxAddGroup = new Panel();
	StandardContainer* lbAddContainer = new StandardContainer();
	lbAddContainer->setBorderWidth( borderWidth );
	listBoxAddGroup->setContainer( lbAddContainer );
	listBoxAddGroup->setBorder( new TitledBorder( "Add item" ) );	
	//add TextControl to enter item to add
	txtCtrlAddToListBox = new TextControl();	
	txtCtrlAddToListBox->setHeight( 20 );
	listBoxAddGroup->add( txtCtrlAddToListBox, AlignTop );
	
	listBoxAddGroup->add( new VerticalSpacer( borderWidth ), AlignTop );
	
	//add buttons for adding text from textCtrlSingle to listBoxSingl
	CommandButton* btnAddItem = new CommandButton();	
	btnAddItem->setCaption( "Add item to ListBox" );
	btnAddItem->setHeight( 24 );
	listBoxAddGroup->add( btnAddItem, AlignTop );
	listBoxAddGroup->setHeight( 2*borderWidth + 20 + 10 + 24 + 15);
	listBoxGroup->add( listBoxAddGroup, AlignBottom );	

	listBoxGroup->add( new VerticalSpacer( 20 ), AlignBottom );

	//add panel for listbox selection style
	Panel* listBoxSelGroup = new Panel();
	StandardContainer* lbSelContainer = new StandardContainer();
	lbSelContainer->setBorderWidth( borderWidth );
	listBoxSelGroup->setContainer( lbSelContainer );	
	listBoxSelGroup->setBorder( new TitledBorder( "Selection style" ) );
	listBoxSelGroup->setHeight( 98 );
	listBoxGroup->add( listBoxSelGroup, AlignBottom );
	Rect bounds3 = listBoxSelGroup->getClientBounds();
	//add RadioButtonControls to selection style panel
	RadioButtonControl* rbSingleSel = new RadioButtonControl();
	rbSingleSel->setGroupID( 1 );
	rbSingleSel->setCaption("Single selection");
	rbSingleSel->setHeight( rbSingleSel->getPreferredHeight() );	
	listBoxSelGroup->add( rbSingleSel, AlignTop );

	RadioButtonControl* rbMultiSel = new RadioButtonControl();
	rbMultiSel->setGroupID( 1 );
	rbMultiSel->setCaption("Multi selection");
	rbMultiSel->setHeight( rbMultiSel->getPreferredHeight() );
	listBoxSelGroup->add( rbMultiSel, AlignTop );
	
	RadioButtonControl* rbExtendedSel = new RadioButtonControl();
	rbExtendedSel->setGroupID( 1 );
	rbExtendedSel->setCaption("Extended selection");
	rbExtendedSel->setHeight( rbExtendedSel->getPreferredHeight() );
	listBoxSelGroup->add( rbExtendedSel, AlignTop );

	rbSingleSel->setChecked( true );

	// Event Handling for this page
	//add SelectionChanged handlers for listbox.
	listBox1->SelectionChanged.addHandler( new ItemEventHandler<MainWindow>(this, &MainWindow::listBox1Change, "MainWindow::listBox1Change"));
	
	//add ButtonClicked handlers for command button.
	btnRemove->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnRemove, "MainWindow::onbtnRemoveClicked" ) );
	btnDeselect->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnDeselect, "MainWindow::onbtnDeselectClicked" ) );
	btnAddItem->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnAddItemClicked, "MainWindow::onbtnAddItemClicked" ) );
	rbSingleSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbSingleSelClicked, "MainWindow::onrbSingleSelClicked" ) );
	rbMultiSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbMultiSelClicked, "MainWindow::onrbMultiSelClicked" ) );
	rbExtendedSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbExtendedSelClicked, "MainWindow::onrbExtendedSelClicked" ) );
}

void MainWindow::onrbSingleSelClicked( VCF::ButtonEvent* ) {	
	listBox1->deselectAllItems();
	listBox1->setAllowsMultiSelect( false );	
}

void MainWindow::onrbMultiSelClicked( VCF::ButtonEvent* ) {
	listBox1->setAllowsMultiSelect( true );
	listBox1->setAllowsExtendedSelect( false );	
}

void MainWindow::onrbExtendedSelClicked( VCF::ButtonEvent* ) {
	listBox1->setAllowsExtendedSelect( true );	
}

void MainWindow::listBox1Change( VCF::ItemEvent* ) {
	
}

void MainWindow::onbtnRemove( VCF::ButtonEvent* ) {	
	ListModel* LBCModel = (ListModel*)(listBox1->getListModel());
	Enumerator<ListItem*>* items= LBCModel->getItems();
	int i = 0;
	i = LBCModel->getCount();

	// we reverse iterate here so you don't screw iterators.
	items->reset( true );// set iterator to .end()
	while ( true == items->hasMoreElements( true ) ) {
		ListItem* item = items->prevElement();		
		if ( true == item->isSelected() ) {	
			listBox1->eraseFromSelectedItems( item );
			item->setSelected(false);			
			LBCModel->deleteItem( item );			
		}		
	}	
	
}

void MainWindow::onbtnDeselect( VCF::ButtonEvent* ) {	
	listBox1->deselectAllItems();
}

void MainWindow::onbtnAddItemClicked( VCF::ButtonEvent* ) {	
	if(listBox1 != NULL){
		ListModel* LBCModel = (ListModel*)(listBox1->getListModel());	
		TextModel* txtModel = txtCtrlAddToListBox->getTextModel();
		String text = txtModel->getText();
		LBCModel->addItem( new DefaultListItem( LBCModel, text ) );
	}	
}
// end of listBoxPage code




// begin bordersPage code
void MainWindow::makeBordersPage()
{
	double borderWidth = UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta);

	Panel* panel1 = (Panel*)bordersPage->getPageComponent();	
	
	Panel* topPanel = new Panel();
	topPanel->setBorder( NULL );
	topPanel->setHeight( 200 );

	Panel* bottomPanel = new Panel();	
	TitledBorder* myTitledBorder = new TitledBorder( "Ethed borders (I am a TitledBorder)" );
	( (StandardContainer*)bottomPanel->getContainer() )->setBorderWidth( borderWidth );
	bottomPanel->setBorder( myTitledBorder );

	panel1->add( topPanel, AlignTop );
	panel1->add( new VerticalSpacer( 3*borderWidth ), AlignTop );
	panel1->add( bottomPanel, AlignClient );
	
	
	long rightside = VCF::GraphicsContext::etRightSide;
	long leftside = VCF::GraphicsContext::etLeftSide;
	long topside = VCF::GraphicsContext::etTopSide;
	long bottomside = VCF::GraphicsContext::etBottomSide;
	long allsides = VCF::GraphicsContext::etAllSides;
	const long raised = VCF::GraphicsContext::etRaised;
	const long sunken = VCF::GraphicsContext::etSunken;
	const long recessed = VCF::GraphicsContext::etRecessed;
	const long etched = VCF::GraphicsContext::etEtched;
	
	
	//build panels with borders
	Panel* threeDPanel = new Panel();
	threeDPanel->setBorder( new Basic3DBorder( false ) );

	Panel* threeDinvertedPanel = new Panel();
	threeDinvertedPanel->setBorder( new Basic3DBorder( true ) );
	
	Panel* light3DPanel = new Panel();
	light3DPanel->setBorder( new Light3DBorder( false ) );

	Panel* invertedLight3DPanel = new Panel();
	invertedLight3DPanel->setBorder( new Light3DBorder( true ) );

	Panel* etchedBorderRaisedPanel = new Panel();
	EtchedBorder* etchedRaisedBorder = new EtchedBorder( allsides, raised );
	etchedBorderRaisedPanel->setBorder( etchedRaisedBorder );

	Panel* etchedBorderSunkenPanel = new Panel();
	EtchedBorder* etchedSunkenBorder = new EtchedBorder( allsides, sunken );
	etchedBorderSunkenPanel->setBorder( etchedSunkenBorder );

	Panel* etchedBorderRecessedPanel = new Panel();
	EtchedBorder* etchedRecessedBorder = new EtchedBorder( allsides, recessed );
	etchedBorderRecessedPanel->setBorder( etchedRecessedBorder );

	Panel* etchedBorderEtchedPanel = new Panel();
	EtchedBorder* etchedEthcedBorder = new EtchedBorder( allsides, etched );
	etchedBorderEtchedPanel->setBorder( etchedEthcedBorder );	


	threeDPanel->setWidth( 120 );
	threeDinvertedPanel->setWidth( 120 );
	light3DPanel->setWidth( 120 );
	invertedLight3DPanel->setWidth( 120 );

	etchedBorderRaisedPanel->setWidth( 120 );
	etchedBorderSunkenPanel->setWidth( 120 );
	etchedBorderRecessedPanel->setWidth( 120 );
	etchedBorderEtchedPanel->setWidth( 120 );
		
	topPanel->add( threeDPanel, AlignLeft );
	topPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	topPanel->add( threeDinvertedPanel, AlignLeft );
	topPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	topPanel->add( light3DPanel , AlignLeft );
	topPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	topPanel->add( invertedLight3DPanel , AlignClient );
	
	bottomPanel->add( etchedBorderRaisedPanel , AlignLeft );
	bottomPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	bottomPanel->add( etchedBorderSunkenPanel , AlignLeft );
	bottomPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	bottomPanel->add( etchedBorderRecessedPanel , AlignLeft );
	bottomPanel->add( new HorizontalSpacer( 20 ), AlignLeft );
	bottomPanel->add( etchedBorderEtchedPanel , AlignClient );	
}
// end bordersPage code



/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/08/30 03:50:47  dougtinkham
*added copyright
*
*/