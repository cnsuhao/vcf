/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2003/07/17 03:02:46  ddiego
*added sketch example
*
*/



#include "ApplicationKit.h"
#include "SketchTools.h"
#include "SketchDocument.h"


using namespace VCF;



void Tool::attach( VCF::Control* control )
{
	EventHandler* ev = getEventHandler( "Tool::onMouseDown" );
	if ( ev == NULL ) {
		ev = new MouseEventHandler<Tool>( this, &Tool::onMouseDown, "Tool::onMouseDown" );
	}

	control->MouseDown += ev;

	ev = getEventHandler( "Tool::onMouseMove" );
	if ( ev == NULL ) {
		ev = new MouseEventHandler<Tool>( this, &Tool::onMouseMove, "Tool::onMouseMove" );
	}

	control->MouseMove += ev;

	ev = getEventHandler( "Tool::onMouseUp" );
	if ( ev == NULL ) {
		ev = new MouseEventHandler<Tool>( this, &Tool::onMouseUp, "Tool::onMouseUp" );
	}

	control->MouseUp += ev;

	ev = getEventHandler( "Tool::onKeyPressed" );
	if ( ev == NULL ) {
		ev = new KeyboardEventHandler<Tool>( this, &Tool::onKeyPressed, "Tool::onKeyPressed" );
	}

	control->KeyPressed += ev;

	ev = getEventHandler( "Tool::onKeyDown" );
	if ( ev == NULL ) {
		ev = new KeyboardEventHandler<Tool>( this, &Tool::onKeyDown, "Tool::onKeyDown" );
	}

	control->KeyDown += ev;

	ev = getEventHandler( "Tool::onKeyUp" );
	if ( ev == NULL ) {
		ev = new KeyboardEventHandler<Tool>( this, &Tool::onKeyUp, "Tool::onKeyUp" );
	}

	control->KeyUp += ev;

	currentControl_ = control;
}

VCF::Control* Tool::detach()
{
	if ( NULL == currentControl_ ) {
		return NULL;
	}


	EventHandler* ev = getEventHandler( "Tool::onMouseDown" );
	if ( ev != NULL ) {
		currentControl_->MouseDown -= ev;
	}

	ev = getEventHandler( "Tool::onMouseMove" );
	if ( ev != NULL ) {
		currentControl_->MouseMove -= ev;
	}

	ev = getEventHandler( "Tool::onMouseUp" );
	if ( ev != NULL ) {
		currentControl_->MouseUp -= ev;
	}
	

	ev = getEventHandler( "Tool::onKeyPressed" );
	if ( ev != NULL ) {
		currentControl_->KeyPressed -= ev;
	}
	

	ev = getEventHandler( "Tool::onKeyDown" );
	if ( ev != NULL ) {
		currentControl_->KeyDown -= ev;
	}

	ev = getEventHandler( "Tool::onKeyUp" );
	if ( ev != NULL ) {
		currentControl_->KeyUp -= ev;
	}

	Control* result = currentControl_;
	currentControl_ = NULL;

	return result;
	
}

ToolManager::ToolManager():
	currentTool_(NULL),
	currentControl_(NULL)
{

}

ToolManager::~ToolManager()
{

}

ToolManager* ToolManager::manager = NULL;

void ToolManager::init()
{	
	ToolManager::manager = new ToolManager();
}

void ToolManager::terminate()
{
	delete ToolManager::manager;
}

ToolManager* ToolManager::getToolManager()
{
	return ToolManager::manager;
}


void ToolManager::registerTool( Tool* tool, MenuItem* item )
{
	toolMap_[item] = tool;
	EventHandler* ev = getEventHandler( "ToolManager::onMenuItemClicked" );
	if ( NULL == ev ) {
		ev = new MenuItemEventHandler<ToolManager>( this, &ToolManager::onMenuItemClicked, "ToolManager::onMenuItemClicked" );
	}
	item->addMenuItemClickedHandler( ev );

	ev = getEventHandler( "ToolManager::onMenuItemUpdate" );
	if ( NULL == ev ) {
		ev = new MenuItemEventHandler<ToolManager>( this, &ToolManager::onMenuItemUpdate, "ToolManager::onMenuItemUpdate" );
	}

	item->addMenuItemUpdateHandler( ev );
}

void ToolManager::onMenuItemClicked( MenuItemEvent* e )
{
	std::map<MenuItem*,Tool*>::iterator found = toolMap_.find( (MenuItem*)e->getSource() );
	if ( NULL != currentTool_ ) {
		currentTool_->detach();
	}

	if ( found != toolMap_.end() ) {		

		currentTool_ = found->second;
		
		currentTool_->attach( currentControl_ );		
	}
	else {
		currentTool_ = NULL;
	}	
}

void ToolManager::onMenuItemUpdate( MenuItemEvent* e )
{
	MenuItem* item = (MenuItem*)e->getSource();
	std::map<MenuItem*,Tool*>::iterator found = toolMap_.find( item );

	if ( found != toolMap_.end() ) {
		if ( found->second == currentTool_ ) {
			item->setChecked( true );
		}
		else {
			item->setChecked( false );
		}
	}
}



SelectTool::SelectTool():
	mouseOverShape_(NULL)
{

}

SelectTool::~SelectTool()
{

}

Shape* SelectTool::hitTest( Point& pt )
{
	Shape* result = NULL;

	SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
	Enumerator<Shape*>* shapes = doc->getShapes();
	while ( shapes->hasMoreElements() ) {
		Shape* shape = shapes->nextElement();
		
		if ( shape->polygon_.intersects( pt ) ) {
			
			result = shape;
			break;
		}
	}

	return result;
}

void SelectTool::onMouseDown( VCF::MouseEvent* e )
{
	SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
	if ( e->hasLeftButton() ) {
		Shape* shape =  hitTest( *e->getPoint() );
		if ( shape ) {
			doc->setSelectedShape( shape );
			dragPoint_ = *e->getPoint(); 
			startDragPoint_ = dragPoint_;
/*
			Control* c = (Control*)e->getSource();
			GraphicsContext* ctx = c->getContext();
			ctx->setXORModeOn( true );

			BasicStroke bs;
			ctx->setCurrentStroke( &bs );
			
			bs.setAllowAntiAlias( false );
			bs.setColor( Color::getColor( "green" ) );
			
			ctx->draw( &shape->polygon_ );
			
			ctx->setCurrentStroke( NULL );

			ctx->setXORModeOn( false );
			*/
		}
		else {
			doc->setSelectedShape( NULL );	
		}
		//currentSelectedShapes_
	}
}

void SelectTool::onMouseMove( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {
		SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
		Shape* shape = doc->getSelectedShape();
		

		if ( NULL != shape ) {
			

			Matrix2D m1;
			m1.translate( dragPoint_.x_ - startDragPoint_.x_,
							dragPoint_.y_ - startDragPoint_.y_ );

			m1.invert();
			shape->polygon_.applyTransform( m1 );


			Matrix2D m2;
			m2.translate( e->getPoint()->x_ - startDragPoint_.x_,
							e->getPoint()->y_ - startDragPoint_.y_ );
			
			shape->polygon_.applyTransform( m2 );
			doc->updateAllViews();


			dragPoint_ = *e->getPoint();
		}
	}
	else {
		if ( (!e->hasMiddleButton()) && (!e->hasRightButton()) ) {
			mouseOverShape_ =  hitTest( *e->getPoint() );

			SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
			doc->updateAllViews();
		}
	}
	
	
	//doc->setSelectedShape( shape );	
}

void SelectTool::onMouseUp( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {
		SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
		Shape* shape = doc->getSelectedShape();
		if ( NULL != shape ) {
			

			Matrix2D m1;
			m1.translate( dragPoint_.x_ - startDragPoint_.x_,
							dragPoint_.y_ - startDragPoint_.y_ );

			m1.invert();
			shape->polygon_.applyTransform( m1 );


			Matrix2D m2;
			m2.translate( e->getPoint()->x_ - startDragPoint_.x_,
							e->getPoint()->y_ - startDragPoint_.y_ );
			
			shape->polygon_.applyTransform( m2 );

			
/*
			Control* c = (Control*)e->getSource();
			GraphicsContext* ctx = c->getContext();

			BasicStroke bs;
			ctx->setCurrentStroke( &bs );
			
			bs.setAllowAntiAlias( false );
			bs.setColor( Color::getColor( "green" ) );
			
			ctx->draw( &shape->polygon_ );
			
			ctx->setCurrentStroke( NULL );			
*/
			doc->updateAllViews();
		}
	}
}

void SelectTool::paintState( VCF::GraphicsContext* ctx )
{
	
	SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
	//Shape* shape = doc->getSelectedShape();
	if ( NULL != mouseOverShape_ ) {
		BasicStroke bs;
		ctx->setCurrentStroke( &bs );

		bs.setAllowAntiAlias( false );
		bs.setColor( Color::getColor( "red" ) );

		ctx->draw( &mouseOverShape_->polygon_ );

		ctx->setCurrentStroke( NULL );
	}
	
	BasicStroke bs;
	ctx->setCurrentStroke( &bs );
	bs.setAllowAntiAlias( false );
	bs.setColor( Color::getColor( "green" ) );

	Enumerator<Shape*>* shapes = doc->getSelectedShapes();
	while ( shapes->hasMoreElements() ) {
		Shape* shape = shapes->nextElement();		
		ctx->draw( &shape->polygon_ );
	}

	ctx->setCurrentStroke( NULL );

}


LineTool::LineTool()
{

}

LineTool::~LineTool()
{

}

void LineTool::onMouseDown( VCF::MouseEvent* e )
{
	start_ = *e->getPoint();
	end_ = start_;
	Control* c = (Control*)e->getSource();
	GraphicsContext* ctx = c->getContext();
	ctx->setColor( Color::getColor("blue") );
	ctx->setXORModeOn( true );
	ctx->moveTo( start_ );
	ctx->lineTo( end_ );
	ctx->strokePath();
	ctx->setXORModeOn( false );
}

void LineTool::onMouseMove( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {
		
		Control* c = (Control*)e->getSource();
		GraphicsContext* ctx = c->getContext();
		ctx->setColor( Color::getColor("blue") );
		ctx->setXORModeOn( true );
		ctx->moveTo( start_ );
		ctx->lineTo( end_ );
		ctx->strokePath();

		end_ = *e->getPoint();

		ctx->moveTo( start_ );
		ctx->lineTo( end_ );
		ctx->strokePath();

		ctx->setXORModeOn( false );
		
	}
}

void LineTool::onMouseUp( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {
		Control* c = (Control*)e->getSource();
		GraphicsContext* ctx = c->getContext();
		ctx->setColor( Color::getColor("blue") );
		ctx->setXORModeOn( true );
		ctx->moveTo( start_ );
		ctx->lineTo( end_ );
		ctx->strokePath();

		end_ = *e->getPoint();

		ctx->moveTo( start_ );
		ctx->lineTo( end_ );
		ctx->strokePath();

		ctx->setXORModeOn( false );

		SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
		Shape shape;
		shape.polygon_.moveTo( start_.x_, start_.y_ );
		shape.polygon_.lineTo( end_.x_, end_.y_ );
		doc->addShape( shape );
	}
}



#define _EPSILON_		0.000000000001

#define radiansToDegrees( rads ) \
	rads*(180.0/M_PI)

double arcSin (double fValue)
{
    if ( -1.0f < fValue )   {
        if ( fValue < 1.0f )
            return (double)asin(fValue);
        else
            return -(M_PI/2.0);
    }
    else {
        return M_PI/2.0;
    }
}


double getAngleFromLine( Point p1, Point p2 )
{
	double result;

	double a,b,c,d;	

	a = fabs(p1.y_-p2.y_); 
	b = fabs(p1.x_-p2.x_);

	c = sqrt(a*a+b*b);

	

	c = (c <= _EPSILON_) ? 0.0 : b/c;

	d = radiansToDegrees(arcSin(c));

	if ( (p1.x_ >= p2.x_) && (p1.y_ <= p2.y_)) {
		result = 90-d;
	}
	else if ((p1.x_ < p2.x_) && (p1.y_ <= p2.y_)) {
		result = d+90;
	}
	else if ((p1.x_ < p2.x_) && (p1.y_ > p2.y_)) {
		result = 180+(90-d);
	}
	else if ((p1.x_ >=  p2.x_) && (p1.y_ > p2.y_)) {
		result = 270+d;
	}

	result = 360.00 - result;
		
	return result;
}

void RotateTool::paintState( VCF::GraphicsContext* ctx )
{

}

void RotateTool::onMouseDown( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {
		startDragPoint_ = dragPoint_ = *e->getPoint();
		startAngle_ = getAngleFromLine( dragPoint_, startDragPoint_ );
		
		SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();

		Shape* shape = doc->getSelectedShape();

		Matrix2D m2;
		m2.rotate( 2 );

		Matrix2D m3;
		m3.scale( -1.0, -1.0 );

		shape->polygon_.applyTransform( *m3.multiply( &m3, &m2 ) );

		doc->updateAllViews();
	}
}

void RotateTool::onMouseMove( VCF::MouseEvent* e )
{
	if ( e->hasLeftButton() ) {		

		SketchDocument* doc = (SketchDocument*) DocumentManager::getDocumentManager()->getCurrentDocument();
		Shape* shape = doc->getSelectedShape();

		if ( NULL == shape ) {
			return;
		}



		StringUtils::traceWithArgs( "angle: %.03f\n", getAngleFromLine( dragPoint_, startDragPoint_ ) );
		
		Matrix2D m1;
		m1.translate( dragPoint_.x_ - startDragPoint_.x_,
							dragPoint_.y_ - startDragPoint_.y_ );

		m1.invert();
		//shape->polygon_.applyTransform( m1 );
		
		
		Matrix2D m2;
		m2.rotate( 2 );//getAngleFromLine( *e->getPoint(), startDragPoint_ ) - getAngleFromLine( dragPoint_, startDragPoint_ ) );		
		
		m1.identity();

		m1.translate( e->getPoint()->x_ - startDragPoint_.x_,
							e->getPoint()->y_ - startDragPoint_.y_ );

		shape->polygon_.applyTransform( m2 );

		Matrix2D* m = m2.multiply( &m1, &m2 );
		if ( NULL != m ) {
			
		}
		doc->updateAllViews();

		dragPoint_ = *e->getPoint();
	}
}

void RotateTool::onMouseUp( VCF::MouseEvent* e )
{	
	if ( e->hasLeftButton() ) {

	}
}