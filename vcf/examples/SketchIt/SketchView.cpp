#include "ApplicationKit.h"
#include "ModelViewKit.h"
#include "SketchView.h"
#include "SketchDocument.h"
#include "SketchTools.h"



#include "graphics/AggCommon.h"


#include "../../thirdparty/common/agg/include/agg_image_transform.h"
#include "../../thirdparty/common/agg/include/agg_span_bgra32_image.h"


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
	BasicFill bf;
	ctx->setCurrentStroke( &bs );
	

	Enumerator<Shape*>* shapes = doc->getShapes();
	while ( shapes->hasMoreElements() ) {
		Shape* shape = shapes->nextElement();

		bs.setColor( &shape->strokeColor_ );		
		bs.setOpacity( shape->opacity_ );
		bs.setWidth( shape->width_ );

		if ( shape->fill_ ) {
			bf.setColor( shape->fillColor_ );
			bf.setOpacity( shape->opacity_ );
			ctx->setCurrentFill( &bf );
		}
		else {
			ctx->setCurrentFill( NULL );
		}

		ctx->draw( &shape->polygon_ );

		if ( NULL != shape->image_ ) {
			Rect bounds = shape->polygon_.getBounds();

			//ctx->drawImage( bounds.left_, bounds.top_, shape->image_ );

			if ( this->getViewControl()->isUsingRenderBuffer() ) {
				agg::rendering_buffer* renderingBuffer = ctx->getRenderingBuffer();

				agg::rendering_buffer* imgRenderingBuffer = shape->image_->getImageBits()->renderBuffer_;

				typedef agg::image_transform_attr<agg::null_distortions, 
                                          agg::image_brightness_alpha_u8, 
                                          agg::null_gradient_alpha> attr_type;

				typedef agg::span_bgra32_image_bilinear<attr_type> renderer_t;

				renderer_solid rs( *renderingBuffer );
				agg::renderer_u8<renderer_t> renderer( *renderingBuffer );

				agg::rasterizer<agg::scanline_u8> rasterizer;
				agg::affine_matrix src_mtx;
				//src_mtx *= agg::translation_matrix(-shape->image_->getWidth()/2, -shape->image_->getHeight()/2);
				//src_mtx *= agg::rotation_matrix(10.0 * agg::pi / 180.0);
				//src_mtx *= agg::translation_matrix(shape->image_->getWidth()/2, shape->image_->getHeight()/2);

				
				unsigned char brightness_alpha_array[agg::image_brightness_alpha_u8::array_size];
				
				unsigned i;
				for(i = 0; i < agg::image_brightness_alpha_u8::array_size; i++)
				{
					brightness_alpha_array[i] = 
						unsigned(1.0 * 255.0);
				}

				agg::null_distortions           distortions; 
				agg::image_brightness_alpha_u8  color_alpha(brightness_alpha_array);
				agg::null_gradient_alpha        gradient_alpha;

				attr_type attr( *imgRenderingBuffer, src_mtx, distortions, color_alpha, gradient_alpha);

				renderer.attribute(attr);

				rasterizer.render(renderer, shape->image_->getWidth(), shape->image_->getHeight());
			}
		}
	}

	ctx->setCurrentStroke( NULL );
	ctx->setCurrentFill( NULL );

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