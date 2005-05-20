//MainWindow.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"

#include "vcf/ApplicationKit/DefaultMenuItem.h"
#include "vcf/ApplicationKit/DefaultListItem.h"
#include "vcf/ApplicationKit/TitledBorder.h"
#include "vcf/ApplicationKit/EtchedBorder.h"
#include "vcf/ApplicationKit/ColorEtchedBorder.h"
#include "vcf/ApplicationKit/HorizontalLayoutContainer.h"
#include "vcf/FoundationKit/Dictionary.h"
#include "vcf/ApplicationKit/TextPeer.h"

#include "ControlsApplication.h"
#include "ControlsAbout.h"
#include "Spacers.h"

#include "MainWindow.h"



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
	menuItemHandler = new MenuItemEventHandler<MainWindow>(this, &MainWindow::onHelpAbout, "helpAbout" );
	helpAbout->addMenuItemClickedHandler( menuItemHandler );

	//add TabbedPages
	mainPages_ = new TabbedPages();
	mainPages_->setBorderWidth( 4 );
	( (StandardContainer*)mainPages_->getContainer() )->setBorderWidth( UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta) );
	this->add( mainPages_, AlignClient );

	//add individual TabPage here.
	listBoxPage_ = mainPages_->addNewPage( "ListBoxControl" );
	makeListBoxPage();

	bordersPage_ = mainPages_->addNewPage( "Borders" );
	makeBordersPage();

	buttonsPage_ = mainPages_->addNewPage( "Buttons" );
	makeButtonsPage();

	textPage_ = mainPages_->addNewPage( "Text" );
	makeTextPage();


	treePage_ = mainPages_->addNewPage( "Tree Control" );
	makeTreePage();

	mainPagesModel_ = mainPages_->getModel();
	mainPagesModel_->setSelectedPage( listBoxPage_ );

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


// begin listBoxPage_ code
void MainWindow::makeListBoxPage()
{
	double borderWidth = UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta);

	Panel* panel1 = (Panel*)listBoxPage_->getPageComponent();

	//add a panel for ListBoxControl-related controls
	Panel* listBoxGroup = new Panel();
	( (StandardContainer*)listBoxGroup->getContainer() )->setBorderWidth( borderWidth );
	listBoxGroup->setBorder( new TitledBorder( "ListBoxControl" ) );
	listBoxGroup->setWidth( 160 );
	panel1->add( listBoxGroup, AlignLeft );

	//add a ListBoxControl
	listBox1_ = new ListBoxControl();
	listBox1_->setBorder( new Basic3DBorder( true ) );
	listBox1_->setAllowsMultiSelect( false );
	//add scrollbar to listBox1_
	ScrollbarManager* scrollbarManagerSingle = new ScrollbarManager();
	addComponent( scrollbarManagerSingle );
	scrollbarManagerSingle->setHasVerticalScrollbar( true );
	scrollbarManagerSingle->setHasHorizontalScrollbar( true );
	scrollbarManagerSingle->setTarget( listBox1_ );
	scrollbarManagerSingle->setKeepScrollbarsVisible( false, false );

	listBoxGroup->add( listBox1_, AlignClient );

	//add some items to listBox1_
	ListModel* listBoxModel = listBox1_->getListModel();
	for(int j=0; j<10; j++){
		String indx = StringUtils::toString(j);
		String capt = L"ListItem " + indx;
		listBoxModel->addItem( new DefaultListItem( listBoxModel, capt ) );
	}
	listBoxModel->addItem( new DefaultListItem( listBoxModel, "Add your own item below." ) );


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
	txtCtrlAddToListBox_ = new TextControl();
	txtCtrlAddToListBox_->setHeight( 20 );
	listBoxAddGroup->add( txtCtrlAddToListBox_, AlignTop );

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
	listBox1_->SelectionChanged.addHandler( new ItemEventHandler<MainWindow>(this, &MainWindow::listBox1Change, "MainWindow::listBox1Change"));

	//add ButtonClicked handlers for command button.
	btnRemove->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnRemove, "MainWindow::onbtnRemoveClicked" ) );
	btnDeselect->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnDeselect, "MainWindow::onbtnDeselectClicked" ) );
	btnAddItem->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onbtnAddItemClicked, "MainWindow::onbtnAddItemClicked" ) );
	rbSingleSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbSingleSelClicked, "MainWindow::onrbSingleSelClicked" ) );
	rbMultiSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbMultiSelClicked, "MainWindow::onrbMultiSelClicked" ) );
	rbExtendedSel->ButtonClicked.addHandler( new ButtonEventHandler<MainWindow>( this, &MainWindow::onrbExtendedSelClicked, "MainWindow::onrbExtendedSelClicked" ) );
}

void MainWindow::onrbSingleSelClicked( VCF::ButtonEvent* ) {
	listBox1_->deselectAllItems();
	listBox1_->setAllowsMultiSelect( false );
}

void MainWindow::onrbMultiSelClicked( VCF::ButtonEvent* ) {
	listBox1_->setAllowsMultiSelect( true );
	listBox1_->setAllowsExtendedSelect( false );
}

void MainWindow::onrbExtendedSelClicked( VCF::ButtonEvent* ) {
	listBox1_->setAllowsExtendedSelect( true );
}

void MainWindow::listBox1Change( VCF::ItemEvent* ) {

}

void MainWindow::onbtnRemove( VCF::ButtonEvent* ) {
	ListModel* LBCModel = (ListModel*)(listBox1_->getListModel());
	Enumerator<ListItem*>* items= LBCModel->getItems();
	int i = 0;
	i = LBCModel->getCount();

	// we reverse iterate here so you don't screw iterators.
	items->reset( true );// set iterator to .end()
	while ( true == items->hasMoreElements( true ) ) {
		ListItem* item = items->prevElement();
		if ( true == item->isSelected() ) {
			listBox1_->eraseFromSelectedItems( item );
			item->setSelected(false);
			LBCModel->deleteItem( item );
		}
	}

}

void MainWindow::onbtnDeselect( VCF::ButtonEvent* ) {
	listBox1_->deselectAllItems();
}

void MainWindow::onbtnAddItemClicked( VCF::ButtonEvent* ) {
	if(listBox1_ != NULL){
		ListModel* LBCModel = (ListModel*)(listBox1_->getListModel());
		TextModel* txtModel = txtCtrlAddToListBox_->getTextModel();
		String text = txtModel->getText();
		LBCModel->addItem( new DefaultListItem( LBCModel, text ) );
	}
}
// end of listBoxPage code




// begin bordersPage code
void MainWindow::makeBordersPage()
{
	double borderWidth = UIToolkit::getUIMetricsManager()->getPreferredSpacingFor(UIMetricsManager::stContainerBorderDelta);

	Panel* pagePanel = (Panel*)bordersPage_->getPageComponent();

	// 2 panels, just to aid in layout.
	Panel* leftPanel = new Panel();
	leftPanel->setWidth( 200 );
	leftPanel->setBorder( NULL );
	Panel* rightPanel = new Panel();
	rightPanel->setBorder( NULL );

	pagePanel->add( leftPanel, AlignLeft );
	pagePanel->add( new HorizontalSpacer( 8 ), AlignLeft );
	pagePanel->add( rightPanel, AlignClient );

	// 4 panels with TitledBorders, in which the panels with various border types/styles will reside.
	Panel* basic3DBorderTitledPanel = new Panel();
	TitledBorder* titledBorder1 = new TitledBorder( "Basic3DBorder" );
	( (StandardContainer*)basic3DBorderTitledPanel->getContainer() )->setBorderWidth( 16 );
	basic3DBorderTitledPanel->setBorder( titledBorder1 );
	basic3DBorderTitledPanel->setHeight( 200 );
	leftPanel->add( basic3DBorderTitledPanel, AlignTop );
	leftPanel->add( new VerticalSpacer( 8 ), AlignTop );

	Panel* light3DBorderTitledPanel = new Panel();
	TitledBorder* titledBorder2 = new TitledBorder( "Light3DBorder" );
	( (StandardContainer*)light3DBorderTitledPanel->getContainer() )->setBorderWidth( 16 );
	light3DBorderTitledPanel->setBorder( titledBorder2 );
	leftPanel->add( light3DBorderTitledPanel, AlignClient );

	Panel* etchedBorderTitledPanel = new Panel();
	TitledBorder* titledBorder3 = new TitledBorder( "EtchedBorder" );
	( (StandardContainer*)etchedBorderTitledPanel->getContainer() )->setBorderWidth( 16 );
	etchedBorderTitledPanel->setBorder( titledBorder3 );
	etchedBorderTitledPanel->setHeight( 200 );
	rightPanel->add( etchedBorderTitledPanel, AlignTop );
	rightPanel->add( new VerticalSpacer( 8 ), AlignTop );

	Panel* colorEtchedBorderTitledPanel = new Panel();
	TitledBorder* titledBorder4 = new TitledBorder( "ColorEtchedBorder" );
	( (StandardContainer*)colorEtchedBorderTitledPanel->getContainer() )->setBorderWidth( 16 );
	colorEtchedBorderTitledPanel->setBorder( titledBorder4 );
	rightPanel->add( colorEtchedBorderTitledPanel, AlignClient );

	// now add the panels with specific border types/styles
	basic3DBorderPanel_ = new Panel();
	basic3DBorderTitledPanel->add( basic3DBorderPanel_, AlignClient );

	light3DBorderPanel_ = new Panel();
	light3DBorderTitledPanel->add( light3DBorderPanel_, AlignClient );

	etchedBorderPanel_ = new Panel();
	etchedBorderTitledPanel->add( etchedBorderPanel_, AlignClient );

	colorEtchedBorderPanel_ = new Panel();
	colorEtchedBorderTitledPanel->add( colorEtchedBorderPanel_, AlignClient );

	//set the borders
	basic3DBorderPanel_->setBorder( new Basic3DBorder( false ) );
	light3DBorderPanel_->setBorder( new Light3DBorder( false ) );
	etchedBorderPanel_->setBorder( new EtchedBorder( GraphicsContext::etAllSides, GraphicsContext::etEtched ) );
	colorEtchedBorderPanel_->setBorder( new ColorEtchedBorder() );
	( (ColorEtchedBorder*)colorEtchedBorderPanel_->getBorder() )->setEdgeStyle( GraphicsContext::etEtched );
	( (ColorEtchedBorder*)colorEtchedBorderPanel_->getBorder() )->setHighlight( Color::getColor( "white" ) );
	( (ColorEtchedBorder*)colorEtchedBorderPanel_->getBorder() )->setShadow( Color::getColor( "blue" ) );
}
// end bordersPage code




void MainWindow::makeButtonsPage()
{
	HorizontalLayoutContainer* container = new HorizontalLayoutContainer();
	container->setColumnWidth( 0, 200 );

	buttonsPage_->getPageComponent()->setContainer( container );

	Label* label = new Label();

	container->add( label );

	CommandButton* btn1 = new CommandButton();
	btn1->setCaption(  "Button 1" );

	label->setCaption( btn1->getClassName() + ":" );

	container->add( btn1 );

	label = new Label();
	container->add( label );

	CommandButton* btn2 = new CommandButton();
	btn2->setCaption(  "Button 2" );

	label->setCaption( btn2->getClassName() + " Disabled:" );

	btn2->setEnabled( false );

	container->add( btn2 );


	label = new Label();
	container->add( label );

	PushButton* btn3 = new PushButton();
	btn3->setCaption(  "Button 3" );

	label->setCaption( btn3->getClassName() + ":" );

	container->add( btn3 );


	label = new Label();
	container->add( label );

	PushButton* btn4 = new PushButton();
	btn4->setCaption(  "Button 4" );
	btn4->setEnabled( false );

	label->setCaption( btn4->getClassName()  + " Disabled:" );

	container->add( btn4 );
}



void MainWindow::makeTextPage()
{
	HorizontalLayoutContainer* container = new HorizontalLayoutContainer();
	container->setColumnWidth( 0, 200 );

	textPage_->getPageComponent()->setContainer( container );

	Label* label = new Label();

	label->setCaption( "Single Line Text:" );
	container->add( label );

	TextControl* singleTextCtrl = new TextControl();
	container->add( singleTextCtrl );

	singleTextCtrl->setReadOnly( true );

	singleTextCtrl->getTextModel()->insertText( 0, "Hello, here's some text!" );

	Dictionary styles;
	styles [ Text::fsColor ] = Color::getColor("green");
	styles [ Text::fsBold ] = true;
	styles [ Text::fsPointSize ] = 15.0;
	styles [ Text::fsItalic ] = true;  // MP-
	styles [ Text::fsStrikeout ] = true; // MP-
	styles [ Text::fsUnderlined ] = Text::utDotted;
	styles [ Text::fsFontName ] = "Arial";
	singleTextCtrl->setStyle( 7, 6, styles );





	label = new Label();

	label->setCaption( "Multi Line Text:" );
	container->add( label );


	MultilineTextControl* multiTextCtrl = new MultilineTextControl();
	multiTextCtrl->setHeight( 200 );
	container->add( multiTextCtrl );
}



void MainWindow::makeTreePage()
{
	Container* container = treePage_->getPageComponent()->getContainer();

	Label* label = new Label();
	label->setWidth( 200 );
	container->add( label, AlignLeft );
	label->setWordWrap( true );

	String s = "This is a TreeControl.\n"\
				"Many neat things can be done with it. For Win32 "\
				"platforms this is a direct wrapper around the TREEVIEW "\
				"control.";
	label->setCaption( s );
	TreeControl* tc = new TreeControl();

	TreeItem* i = tc->addItem( NULL, "Item 1" );
	tc->addItem( i, "Item 1a" );
	tc->addItem( i, "Item 1b" );
	tc->addItem( i, "Item 1c" );
	tc->addItem( i, "Item 1d" );
	tc->addItem( i, "Item 1e" );
	tc->addItem( i, "Item 1f" );
	tc->addItem( i, "Item 1g" );
	tc->addItem( i, "Item 1h" );
	tc->addItem( i, "Item 1i" );

	container->add( tc, AlignClient );
}


/**
*CVS Log info
*$Log$
*Revision 1.2.2.9  2005/05/20 17:25:31  marcelloptr
*added all remaining style examples
*
*Revision 1.2.2.8  2005/05/20 03:04:00  ddiego
*minor mods to set focused control.
*
*Revision 1.2.2.7  2005/05/05 16:00:26  marcelloptr
*standard VCF formatting
*
*Revision 1.2.2.5  2005/05/05 12:42:25  ddiego
*this adds initial support for run loops,
*fixes to some bugs in the win32 control peers, some fixes to the win32 edit
*changes to teh etxt model so that notification of text change is more
*appropriate.
*
*Revision 1.2.2.4  2005/05/04 01:20:35  marcelloptr
*member variables following VCF standard
*
*Revision 1.2.2.3  2005/04/25 00:11:54  ddiego
*added more advanced text support. fixed some memory leaks. fixed some other miscellaneous things as well.
*
*Revision 1.2.2.2  2005/03/06 22:50:53  ddiego
*overhaul of RTTI macros. this includes changes to various examples to accommadate the new changes.
*
*Revision 1.2  2004/12/01 04:15:00  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.1.2.10  2004/10/07 00:59:56  kiklop74
*Added Set of makefiles and batch files for building part of VCF samples
*
*Revision 1.1.2.9  2004/10/01 17:05:27  dougtinkham
*updated Borders tab page
*
*Revision 1.1.2.8  2004/09/21 05:58:24  dougtinkham
*setKeepScrollbarsVisible back to false
*
*Revision 1.1.2.7  2004/09/19 20:10:30  marcelloptr
*minor changes
*
*Revision 1.1.2.5  2004/09/14 18:24:14  dougtinkham
*changed keepScrollbarsVisible from true to false
*
*Revision 1.1.2.4  2004/09/11 08:19:58  dougtinkham
*moved line adding listbox to panel to before items added to listbox
*
*Revision 1.1.2.3  2004/08/30 03:50:47  dougtinkham
*added copyright
*
*/


