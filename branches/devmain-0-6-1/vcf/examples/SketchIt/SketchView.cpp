#include "ApplicationKit.h"
#include "ModelViewKit.h"
#include "SketchView.h"
#include "SketchDocument.h"
#include "SketchTools.h"


using namespace VCF;


SketchView::SketchView()
{

}

SketchView::~SketchView()
{

}

void SketchView::paintView( GraphicsContext* ctx )
{
	ctx->setColor( Color::getColor( "white" ) );

	ctx->rectangle( getViewControl()->getClientBounds() );
	ctx->fillPath();


	SketchDocument* doc = (SketchDocument*)getViewModel();

	BasicStroke bs;
	ctx->setCurrentStroke( &bs );

	Enumerator<Shape*>* shapes = doc->getShapes();
	while ( shapes->hasMoreElements() ) {
		Shape* shape = shapes->nextElement();

		bs.setColor( &shape->color_ );
		ctx->draw( &shape->polygon_ );
	}

	ctx->setCurrentStroke( NULL );

	Tool* tool = ToolManager::getToolManager()->getCurrentTool();

	if ( NULL != tool ) {
		tool->paintState( ctx );
	}
	/*
	Shape* shape = doc->getSelectedShape();
	if ( NULL != shape ) {
		bs.setAllowAntiAlias( false );
		bs.setColor( Color::getColor( "red" ) );

		ctx->draw( &shape->polygon_ );
	}
	*/


	
}