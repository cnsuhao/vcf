//AdvancedUI.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/ModelViewKit.h"
#include "vcf/ApplicationKit/HorizontalLayoutContainer.h"

using namespace VCF;

class WhiteBorder : public Border  {
public:
	Font titleFont_;
	String title_;

	WhiteBorder( const String& title ):title_(title){
		titleFont_.setName( "Tahoma" );
		titleFont_.setBold( true );
		titleFont_.setPointSize( 9 );
		titleFont_.setColor( Color::getColor("black") );
	}

	WhiteBorder(){
		titleFont_.setName( "Tahoma" );
		titleFont_.setBold( true );
		titleFont_.setPointSize( 9 );
		titleFont_.setColor( Color::getColor("black") );
	}

	virtual void paint( Control* control, GraphicsContext* context ) {
		paint( &control->getClientBounds(false), context );
	}

	virtual void paint( Rect* bounds, GraphicsContext* context ) {
		int gcs = context->saveState();

		context->setColor( GraphicsToolkit::getSystemColor(SYSCOLOR_FACE) );

		context->moveTo( bounds->left_-1, bounds->top_ );
		context->lineTo( bounds->right_+1, bounds->top_ );
		context->strokePath();


		context->setColor( Color::getColor("white") );
		context->setStrokeWidth( 1 );
		context->setCurrentFont( &titleFont_ );


		context->moveTo( bounds->left_ +1, bounds->top_ );
		context->lineTo( bounds->right_ -1, bounds->top_ );

		context->moveTo( bounds->right_-1, bounds->top_+1 );
		context->lineTo( bounds->right_-1, bounds->bottom_-1 );
		context->lineTo( bounds->left_, bounds->bottom_-1 );
		context->lineTo( bounds->left_, bounds->top_ );
		context->strokePath();

		context->setCurrentFont( &titleFont_ );

		double h = context->getTextHeight( "EM" ) ;
		Rect titleRect = *bounds;
		titleRect.inflate( -1, -1 );
		titleRect.bottom_ = titleRect.top_ + h;
		Color titleColor((unsigned char)182, (unsigned char)189, (unsigned char)210);
		context->setColor( &titleColor );
		context->rectangle( &titleRect );
		context->fillPath();
		
		titleRect.left_ += 10;
		long options = GraphicsContext::tdoCenterVertAlign;
		context->textBoundedBy( &titleRect, title_, options );		
		context->restoreState( gcs );
	}

	virtual Rect getClientRect( Rect* initialBounds, Control* control ) {
		Rect result = *initialBounds;

		result.inflate( -1, -1 );
		GraphicsContext* ctx = control->getContext();
		Font old = *ctx->getCurrentFont();

		ctx->setCurrentFont(&titleFont_);

		result.top_ += ctx->getTextHeight( "EM" );

		ctx->setCurrentFont(&old);

		return result;
	}
};

class HeaderLabel : public Label {
public:
	HeaderLabel() {
		setHeight( getPreferredHeight() );
		getFont()->setName( "Tahoma" );
		getFont()->setPointSize( 9 );
		getFont()->setBold( true );

	}
	virtual void paint( GraphicsContext* ctx ) {
		Label::paint( ctx );

		Rect r = getClientBounds();
		ctx->setColor( Color::getColor("black") );
		ctx->moveTo( r.left_, r.bottom_-1 );
		ctx->lineTo( r.right_, r.bottom_-1 );
		ctx->strokePath();
	}
};




class CategoryItem : public DefaultTreeItem {
public:
	CategoryItem() {

	}

	virtual bool canPaint() {
		return true;
	}

	virtual void paint( GraphicsContext* ctx, Rect* paintRect ) {
		DefaultTreeItem::paint( ctx, paintRect );

		if ( this->isSelected() ) {
			Color col = *GraphicsToolkit::getSystemColor( SYSCOLOR_FACE );
			double h,l,s;
			col.getHLS(h,l,s);
			l += 0.10;
			col.setHLS( h,l,s );
			ctx->setColor( &col );
			ctx->rectangle( paintRect );
			ctx->fillPath();
		}
		long options = GraphicsContext::tdoCenterVertAlign;
		ctx->textBoundedBy( paintRect, this->getCaption(), options );
	}
};



class CategoryTemplatePanel : public Panel {
public:
	CategoryTemplatePanel() {
		setBorder( new WhiteBorder("Choose Wank Style") );

		HorizontalLayoutContainer* container = new HorizontalLayoutContainer();
		container->setMaximizeLastRow( true );
		container->setBorderWidth( 15 );
		container->setColumnTweenWidth( 0, 55 );
		container->setColumnWidth( 0, 200 );
		container->setRowSpacerHeight( 15 );

		setContainer( container );

		setColor( Color::getColor("white") );
		this->setUseColorForBackground(true);

		HeaderLabel* label = new HeaderLabel();

		label->setCaption( "Category" );
		add( label );

		HeaderLabel* label2 = new HeaderLabel();
		label2->setCaption( "Template" );
		add( label2 );

		categories_ = new TreeControl();		
		categories_->setVisible( true );
		categories_->setBorder( NULL );
		add( categories_ );


		CategoryItem* item = new CategoryItem();
		categories_->getTreeModel()->addNodeItem( item );
		item->setCaption( "Block Diagrams" );

		item = new CategoryItem();
		categories_->getTreeModel()->addNodeItem( item );
		item->setCaption( "Really Big Block Diagrams" );

		item = new CategoryItem();
		categories_->getTreeModel()->addNodeItem( item );
		item->setCaption( "Really Ugly Diagrams" );

		item = new CategoryItem();
		categories_->getTreeModel()->addNodeItem( item );
		item->setCaption( "Tea and Crumpets Diagrams" );



		Color col = *GraphicsToolkit::getSystemColor( SYSCOLOR_FACE );
		double h,l,s;
		col.getHLS(h,l,s);
		l += 0.10;
		col.setHLS( h,l,s );
		

		templates_ = new ListViewControl();		
		templates_->setVisible( true );
		templates_->setColor( &col );
		templates_->setBorder( NULL );
		add( templates_ );
	}

	ListViewControl* templates_;
	TreeControl* categories_;


	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		int gcs = ctx->saveState();

		Rect templateBounds = templates_->getBounds();
		templateBounds.inflate( 5, 5 );
		Rect catBounds = categories_->getBounds();
		catBounds.inflate( 5, 5 );

		std::vector<Point> pts(9);
		pts[0].x_ = catBounds.left_;
		pts[0].y_ = catBounds.top_ + 50;

		pts[1].x_ = templateBounds.left_;
		pts[1].y_ = catBounds.top_ + 50;

		pts[2].x_ = templateBounds.left_;
		pts[2].y_ = templateBounds.top_;

		pts[3].x_ = templateBounds.right_;
		pts[3].y_ = templateBounds.top_;

		pts[4].x_ = templateBounds.right_;
		pts[4].y_ = templateBounds.bottom_;

		pts[5].x_ = templateBounds.left_;
		pts[5].y_ = templateBounds.bottom_;

		pts[6].x_ = templateBounds.left_;
		pts[6].y_ = catBounds.top_ + 50 + 20;

		pts[7].x_ = catBounds.left_;
		pts[7].y_ = catBounds.top_ + 50 + 20;

		pts[8].x_ = catBounds.left_;
		pts[8].y_ = catBounds.top_ + 50;


		Color col = *GraphicsToolkit::getSystemColor( SYSCOLOR_FACE );
		double h,l,s;
		col.getHLS(h,l,s);
		l += 0.10;
		col.setHLS( h,l,s );
		ctx->setColor( &col );

		
		
		Point rrSize(20,20);

		//ctx->roundRect( &templateBounds, &rrSize );
		ctx->polyline( pts );
		ctx->fillPath();

		ctx->setColor( Color::getColor("black") );
		ctx->strokePath();



		ctx->restoreState( gcs );
	}
};	

class AdvancedUIWindow : public Window {
public:
	AdvancedUIWindow() {
		setCaption( "AdvancedUI" );
		setVisible( true );

		Panel* p = new CategoryTemplatePanel();

		add( p, AlignClient );

		
	}

	virtual ~AdvancedUIWindow(){};

};




class AdvancedUIApplication : public Application {
public:

	AdvancedUIApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new AdvancedUIWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new AdvancedUIApplication( argc, argv );

	Application::main();
	
	return 0;
}


