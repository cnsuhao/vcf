//Colors.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/HorizontalLayoutContainer.h"


using namespace VCF;

String SysColorToString( int i ) {
	String result;

	switch ( i ) {
		case SYSCOLOR_SHADOW : {
			result = "SYSCOLOR_SHADOW";
		}
		break;

		case SYSCOLOR_FACE : {
			result = "SYSCOLOR_FACE";
		}
		break;

		case SYSCOLOR_HIGHLIGHT : {
			result = "SYSCOLOR_HIGHLIGHT";
		}
		break;

		case SYSCOLOR_ACTIVE_CAPTION : {
			result = "SYSCOLOR_ACTIVE_CAPTION";
		}
		break;

		case SYSCOLOR_ACTIVE_BORDER : {
			result = "SYSCOLOR_ACTIVE_BORDER";
		}
		break;

		case SYSCOLOR_DESKTOP : {
			result = "SYSCOLOR_DESKTOP";
		}
		break;

		case SYSCOLOR_CAPTION_TEXT : {
			result = "SYSCOLOR_CAPTION_TEXT";
		}
		break;

		case SYSCOLOR_SELECTION : {
			result = "SYSCOLOR_SELECTION";
		}
		break;

		case SYSCOLOR_SELECTION_TEXT : {
			result = "SYSCOLOR_SELECTION_TEXT";
		}
		break;

		case SYSCOLOR_INACTIVE_BORDER : {
			result = "SYSCOLOR_INACTIVE_BORDER";
		}
		break;

		case SYSCOLOR_INACTIVE_CAPTION : {
			result = "SYSCOLOR_INACTIVE_CAPTION";
		}
		break;

		case SYSCOLOR_TOOLTIP : {
			result = "SYSCOLOR_TOOLTIP";
		}
		break;

		case SYSCOLOR_TOOLTIP_TEXT : {
			result = "SYSCOLOR_TOOLTIP_TEXT";
		}
		break;

		case SYSCOLOR_MENU : {
			result = "SYSCOLOR_MENU";
		}
		break;

		case SYSCOLOR_MENU_TEXT : {
			result = "SYSCOLOR_MENU_TEXT";
		}
		break;

		case SYSCOLOR_WINDOW : {
			result = "SYSCOLOR_WINDOW";
		}
		break;

		case SYSCOLOR_WINDOW_TEXT : {
			result = "SYSCOLOR_WINDOW_TEXT";
		}
		break;

		case SYSCOLOR_WINDOW_FRAME : {
			result = "SYSCOLOR_WINDOW_FRAME";
		}
		break;
	}

	return result;
}


class StandardColorsPanel : public Panel {
public:
	enum {
		NumColorColumns = 10
	};

	StandardColorsPanel() {
		setBorder( NULL );
		
		ToolTipRequested += 
			new ToolTipEventHandler<StandardColorsPanel>(this,&StandardColorsPanel::onToolTipRequested, "StandardColorsPanel::onToolTipRequested" );

	}

	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();

		int cols = NumColorColumns;	
		int width = r.getWidth();
		Rect colorCell;
		colorCell.setRect( r.left_, r.top_, 
							r.left_ + (width/cols),
							r.top_ + (width/cols) );

		for (int i=ColorNames::uniqueColorFirst;i<=ColorNames::numUniqueColorNames;i++ ) {
			Color* color = Color::getColor( ColorNames::at( (ColorNames::ColorID) i ) );
			

			ctx->rectangle( &colorCell );
			ctx->setColor( color );
			ctx->fillPath();

			if ( ((i+1) % cols == 0) ) {
				colorCell.setRect( r.left_, colorCell.bottom_, 
							r.left_ + (width/cols),
							colorCell.bottom_ + (width/cols) );

				//colorCell.offset( 0, 5 );
			}
			else {
				colorCell.offset( colorCell.getWidth(), 0 );
			}

		}
	}

	void onToolTipRequested( ToolTipEvent* e ) {
		e->setToolTipString( "Unknown color" );
		Point pt = Desktop::getDesktop()->getCurrentMousePosition();
		
		translateFromScreenCoords( &pt );


		Rect r = getClientBounds();

		int cols = NumColorColumns;	
		int width = r.getWidth();
		Rect colorCell;
		colorCell.setRect( r.left_, r.top_, 
							r.left_ + (width/cols),
							r.top_ + (width/cols) );

		for (int i=ColorNames::uniqueColorFirst;i<=ColorNames::numUniqueColorNames;i++ ) {
			

			if ( colorCell.containsPt( &pt ) ) {
				e->setToolTipString( "Color name: " + ColorNames::at( (ColorNames::ColorID) i ) );
				break;
			}

			if ( ((i+1) % cols == 0) && (i > ColorNames::uniqueColorFirst) ) {
				colorCell.setRect( r.left_, colorCell.bottom_, 
							r.left_ + (width/cols),
							colorCell.bottom_ + (width/cols) );
			}
			else {
				colorCell.offset( colorCell.getWidth(), 0 );
			}

		}
	}
};



class SysColorsPanel : public Panel {
public:
	SysColorsPanel() {
		setBorder( NULL );
	}
	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();
		r.inflate( -10, -10 );

		Light3DBorder bdr;

		uint32 colorIdx =  SYSCOLOR_SHADOW ;
		int cols = 4;	
		int width = r.getWidth() - (cols * 5);
		Rect colorCell;
		colorCell.setRect( r.left_, r.top_, 
							r.left_ + (width/cols),
							r.top_ + (width/cols) );

		Rect textRect;

		for (int i=1;i<=18;i++ ) {
			Color* color = GraphicsToolkit::getSystemColor( colorIdx );

			bdr.paint( &colorCell, ctx );

			Rect fill = bdr.getClientRect( &colorCell, NULL );

			ctx->rectangle( &fill );
			ctx->setColor( color );
			Color tmp = *color;

			ctx->fillPath();

			textRect = colorCell;
			textRect.inflate(-5, -5 );
			long options = GraphicsContext::tdoCenterHorzAlign | 
							GraphicsContext::tdoCenterVertAlign;

			tmp = tmp.invert();

			ctx->getCurrentFont()->setPointSize( 6 );
			ctx->getCurrentFont()->setColor( &tmp );

			ctx->textBoundedBy( &textRect, SysColorToString(colorIdx), options );

			if ( i % cols == 0 ) {
				colorCell.setRect( r.left_, colorCell.bottom_, 
							r.left_ + (width/cols),
							colorCell.bottom_ + (width/cols) );

				colorCell.offset( 0, 5 );
			}
			else {
				colorCell.offset( colorCell.getWidth() + 5, 0 );
			}

			colorIdx ++;
		}

	}
};


class RGBPanel : public Panel {
public:

	Panel* colorWell;
	Label* redVal;
	Label* greenVal;
	Label* blueVal;

	RGBPanel() {
		setBorder( NULL );

		HorizontalLayoutContainer* hc = new HorizontalLayoutContainer();	
		hc->setNumberOfColumns( 3 );
		hc->setColumnWidth( 0, 100 );
		hc->setColumnWidth( 1, 100 );
		hc->setColumnWidth( 2, 100 );

		hc->setColumnTweenWidth( 0, UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing ) );
		hc->setColumnTweenWidth( 1, UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing ) );


		setContainer( hc );

		colorWell = new Panel();
		colorWell->setUseColorForBackground(true);

		Label* label = new Label();
		label->setCaption( "Red:" );
		add( label );

		SliderControl* slider = new SliderControl();			
		slider->setPosition( colorWell->getColor()->getRed() * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<RGBPanel>( this, &RGBPanel::onRedChanged, "RGBPanel::onRedChanged" );

		add( slider );

		redVal = new Label();
		redVal->setCaption( "???" );
		add( redVal );


		label = new Label();
		label->setCaption( "Green:" );
		add( label );

		slider = new SliderControl();	
		slider->setPosition( colorWell->getColor()->getGreen() * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<RGBPanel>( this, &RGBPanel::onGreenChanged, "RGBPanel::onGreenChanged" );
		add( slider );

		greenVal = new Label();
		greenVal->setCaption( "???" );
		add( greenVal );


		label = new Label();
		label->setCaption( "Blue:" );
		add( label );

		slider = new SliderControl();	
		slider->setPosition( colorWell->getColor()->getBlue() * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<RGBPanel>( this, &RGBPanel::onBlueChanged, "RGBPanel::onBlueChanged" );

		add( slider );

		blueVal = new Label();
		blueVal->setCaption( "???" );
		add( blueVal );

		

		add( colorWell );
	}

	void onRedChanged( Event* e ) {
		Color color = *colorWell->getColor();

		SliderControl* slider = (SliderControl*)e->getSource();
		color.setRed( slider->getPosition() / 100.0 );

		colorWell->setColor( &color );

		redVal->setCaption( Format("%.3f (#%02X)") % color.getRed() %
								(uchar)(color.getRed() * 255.0) );
	}

	void onGreenChanged( Event* e ) {
		Color color = *colorWell->getColor();

		SliderControl* slider = (SliderControl*)e->getSource();
		color.setGreen( slider->getPosition() / 100.0 );

		colorWell->setColor( &color );

		greenVal->setCaption( Format("%.3f (#%02X)") % color.getGreen() %
								(uchar)(color.getGreen() * 255.0) );
	}

	void onBlueChanged( Event* e ) {
		Color color = *colorWell->getColor();

		SliderControl* slider = (SliderControl*)e->getSource();
		color.setBlue( slider->getPosition() / 100.0 );

		colorWell->setColor( &color );

		blueVal->setCaption( Format("%.3f (#%02X)") % color.getBlue() %
								(uchar)(color.getBlue() * 255.0) );
	}
};





class HSLPanel : public Panel {
public:

	Panel* colorWell;
	Label* hueVal;
	Label* saturationVal;
	Label* luminanceVal;

	HSLPanel() {
		setBorder( NULL );

		HorizontalLayoutContainer* hc = new HorizontalLayoutContainer();	
		hc->setNumberOfColumns( 3 );
		hc->setColumnWidth( 0, 100 );
		hc->setColumnWidth( 1, 100 );
		hc->setColumnWidth( 2, 100 );

		hc->setColumnTweenWidth( 0, UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing ) );
		hc->setColumnTweenWidth( 1, UIToolkit::getUIMetricValue( UIMetricsManager::mtControlHorizontalSpacing ) );


		setContainer( hc );

		colorWell = new Panel();
		colorWell->setUseColorForBackground(true);

		Label* label = new Label();
		label->setCaption( "Hue:" );
		add( label );

		double h,s,l;

		colorWell->getColor()->getHSL( h,s,l );

		SliderControl* slider = new SliderControl();			
		slider->setPosition( h * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<HSLPanel>( this, &HSLPanel::onRedChanged, "HSLPanel::onRedChanged" );

		slider->setTickFrequency(0);
		add( slider );

		hueVal = new Label();
		hueVal->setCaption( "???" );
		add( hueVal );


		label = new Label();
		label->setCaption( "Saturation:" );
		add( label );

		slider = new SliderControl();	
		slider->setPosition( s * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<HSLPanel>( this, &HSLPanel::onGreenChanged, "HSLPanel::onGreenChanged" );
		add( slider );

		saturationVal = new Label();
		saturationVal->setCaption( "???" );
		add( saturationVal );


		label = new Label();
		label->setCaption( "Luminance:" );
		add( label );

		slider = new SliderControl();	
		slider->setPosition( l * 100.0 );
		slider->PositionChanged +=
			new GenericEventHandler<HSLPanel>( this, &HSLPanel::onBlueChanged, "HSLPanel::onBlueChanged" );

		add( slider );

		luminanceVal = new Label();
		luminanceVal->setCaption( "???" );
		add( luminanceVal );

		

		add( colorWell );
	}

	void onRedChanged( Event* e ) {
		Color color = *colorWell->getColor();

		double h,s,l;

		color.getHSL( h,s,l );

		SliderControl* slider = (SliderControl*)e->getSource();
		h = (slider->getPosition() / 100.0) * 6.0;

		color.setHSL( h,s,l );

		colorWell->setColor( &color );		

		hueVal->setCaption( Format("%.3f") % h  );
	}

	void onGreenChanged( Event* e ) {
		Color color = *colorWell->getColor();

		double h,s,l;

		color.getHSL( h,s,l );

		SliderControl* slider = (SliderControl*)e->getSource();
		s = slider->getPosition() / 100.0;

		color.setHSL( h,s,l );

		colorWell->setColor( &color );		

		saturationVal->setCaption( Format("%.3f") % s  );
	}

	void onBlueChanged( Event* e ) {
		Color color = *colorWell->getColor();

		double h,s,l;

		color.getHSL( h,s,l );

		SliderControl* slider = (SliderControl*)e->getSource();
		l = slider->getPosition() / 100.0;

		color.setHSL( h,s,l );

		colorWell->setColor( &color );		

		luminanceVal->setCaption( Format("%.3f") % l  );
	}
};


class ColorsApplication : public Application {
public:

	ColorsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();

		Window* mainWindow = new Window();


		TabbedPages* tabs = new TabbedPages();

		tabs->addNewPage( "System Colors" )->getPageComponent()->getContainer()->add( new SysColorsPanel(), AlignClient );
		tabs->addNewPage( "Standard Colors" )->getPageComponent()->getContainer()->add( new StandardColorsPanel(), AlignClient );
		tabs->addNewPage( "RGB Colors" )->getPageComponent()->getContainer()->add( new RGBPanel(), AlignClient );
		tabs->addNewPage( "HSL Colors" )->getPageComponent()->getContainer()->add( new HSLPanel(), AlignClient );

		
		
		mainWindow->add( tabs, AlignClient );


		setMainWindow(mainWindow);
		mainWindow->setBounds( 100.0, 100.0, 500.0, 500.0 );
		mainWindow->show();

		return result;
	}

};

int main(int argc, char *argv[])
{
	Application* app = new ColorsApplication( argc, argv );

	Application::main();

	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.2.4.1  2006/03/10 21:49:31  ddiego
*updates to color example and some documentation.
*
*Revision 1.2  2004/12/01 04:14:59  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.1.2.1  2004/08/27 22:27:50  marcelloptr
*added Colors example. It will be improved.
*
*/


