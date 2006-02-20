//Themes.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/GraphicsKit/DrawUIState.h"


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

class ButtonsPanel : public Panel {
public:
	ButtonsPanel() {
		setBorder( NULL );
	}
	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();

		r.inflate( -10, -10 );

		Rect btn = r;
		Rect textR = r;
		btn.right_ = btn.left_ + btn.getWidth()/2;
		btn.bottom_ = btn.top_ + 35;

		textR.left_ = btn.right_;
		textR.bottom_ = btn.bottom_;

		long options = GraphicsContext::tdoCenterHorzAlign | 
							GraphicsContext::tdoCenterVertAlign;

		ctx->textBoundedBy( &textR, "Button Focus Rect", options );

		
		ctx->drawThemeButtonFocusRect( &btn );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Button Rect", options );

		ButtonState state;
		state.setEnabled( true );
		state.setFocused( false );
		state.setActive( true );

		state.buttonCaption_ = "A Button";
		ctx->drawThemeButtonRect( &btn, state, &btn );


		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Button Rect Pressed", options );
		
		state.setPressed(true);		
		ctx->drawThemeButtonRect( &btn, state, &btn );


		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Button Rect Disabled", options );
		
		state.setPressed(false);		
		state.setEnabled( false );
		ctx->drawThemeButtonRect( &btn, state, &btn );


		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Check box Rect", options );
		
		ButtonState cbState;
		cbState.setEnabled( true );
		cbState.setFocused( false );
		cbState.setActive( true );
		cbState.buttonCaption_ = "A Checkbox";

		ctx->drawThemeCheckboxRect( &btn, cbState );


		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Check box Rect toggled", options );

		cbState.setToggled( true );
		ctx->drawThemeCheckboxRect( &btn, cbState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Check box Rect Disabled and toggled", options );

		cbState.setEnabled( false );
		ctx->drawThemeCheckboxRect( &btn, cbState );


		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Radio button Rect", options );

		ButtonState rbState;
		rbState.setEnabled( true );
		rbState.setFocused( false );
		rbState.setActive( true );
		rbState.buttonCaption_ = "A Radio button";

		ctx->drawThemeRadioButtonRect( &btn, rbState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Radio box Rect toggled", options );

		rbState.setToggled( true );
		ctx->drawThemeRadioButtonRect( &btn, rbState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Radio box Rect Disabled and toggled", options );

		rbState.setEnabled( false );
		ctx->drawThemeRadioButtonRect( &btn, rbState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ButtonState cmboState;
		cmboState.setEnabled( true );
		cmboState.setFocused( false );
		cmboState.setActive( true );
		cmboState.buttonCaption_ = "A Combo Box";

		ctx->textBoundedBy( &textR, "Combo box Rect", options );
		ctx->drawThemeComboboxRect( &btn, cmboState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Combo box Rect Disabled", options );

		cmboState.setEnabled( false );
		ctx->drawThemeComboboxRect( &btn, cmboState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ctx->textBoundedBy( &textR, "Combo box Rect Focused", options );

		cmboState.setEnabled( true );
		cmboState.setFocused( true );
		ctx->drawThemeComboboxRect( &btn, cmboState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		ScrollBarState scrollState;
		scrollState.setEnabled( true );
		scrollState.setFocused( false );
		scrollState.setActive( true );		
		scrollState.setButtonType( ScrollBarState::sbUpOrLeftBtn );

		ctx->textBoundedBy( &textR, "Scroll bar btn Rect", options );
		ctx->drawThemeScrollButtonRect( &btn, scrollState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		scrollState.setScrollBarIncrArrowPressed( true );
		ctx->textBoundedBy( &textR, "Scroll bar btn pressed Rect", options );
		ctx->drawThemeScrollButtonRect( &btn, scrollState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		scrollState.setEnabled( false );
		ctx->textBoundedBy( &textR, "Scroll bar btn disabled Rect", options );
		ctx->drawThemeScrollButtonRect( &btn, scrollState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );


		DisclosureButtonState disclState;
		disclState.setEnabled( true );
		disclState.setFocused( false );
		disclState.setActive( true );
		disclState.setClosed( true );
		disclState.setOpened( false );

		ctx->textBoundedBy( &textR, "Disclosure btn Rect - closed", options );
		ctx->drawThemeDisclosureButton( &btn, disclState );

		btn.offset( 0, 40 );
		textR.offset( 0, 40 );

		disclState.setClosed( false );
		disclState.setOpened( true );
		ctx->textBoundedBy( &textR, "Disclosure btn Rect - open", options );
		ctx->drawThemeDisclosureButton( &btn, disclState );
	}
};	



class EdgesPanel : public Panel {
public:
	EdgesPanel() {
		setBorder( NULL );
	}
	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();

		r.inflate( -10, -10 );

		int height = 70;

		Rect edgeR = r;
		Rect textR = r;
		edgeR.right_ = edgeR.left_ + edgeR.getWidth()/2;
		edgeR.bottom_ = edgeR.top_ + height;

		textR.left_ = edgeR.right_;
		textR.bottom_ = edgeR.bottom_;

		long options = GraphicsContext::tdoCenterHorzAlign | 
							GraphicsContext::tdoCenterVertAlign;

		ctx->textBoundedBy( &textR, "Button Focus Rect", options );

		
		ctx->drawThemeButtonFocusRect( &edgeR );

		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );


		ctx->textBoundedBy( &textR, "Selection Rect", options );

		DrawUIState state;
		ctx->drawThemeSelectionRect( &edgeR, state );

		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );



		ctx->textBoundedBy( &textR, "Focus Rect", options );
		ctx->drawThemeFocusRect( &edgeR, state );


		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );
		
		long sides = GraphicsContext::etAllSides;
		long style = GraphicsContext::etRecessed;
		ctx->textBoundedBy( &textR, "Edge Rect - Recessed", options );
		ctx->drawThemeEdge( &edgeR, state, sides, style );

		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );

		style = GraphicsContext::etEtched;
		ctx->textBoundedBy( &textR, "Edge Rect - Etched", options );
		ctx->drawThemeEdge( &edgeR, state, sides, style );

		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );

		style = GraphicsContext::etRaised;
		ctx->textBoundedBy( &textR, "Edge Rect - Raised", options );
		ctx->drawThemeEdge( &edgeR, state, sides, style );

		edgeR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );

		style = GraphicsContext::etSunken;
		ctx->textBoundedBy( &textR, "Edge Rect - Sunken", options );
		ctx->drawThemeEdge( &edgeR, state, sides, style );
		

	}
};	


class TabsPanel : public Panel {
public:
	TabsPanel() {
		setBorder( NULL );
	}
	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();

		r.inflate( -10, -10 );

		int height = 70;

		Rect tabsR = r;
		Rect textR = r;
		tabsR.right_ = tabsR.left_ + tabsR.getWidth()/2;
		tabsR.bottom_ = tabsR.top_ + height;

		textR.left_ = tabsR.right_;
		textR.bottom_ = tabsR.bottom_;

		long options = GraphicsContext::tdoCenterHorzAlign | 
							GraphicsContext::tdoCenterVertAlign;

		ctx->textBoundedBy( &textR, "Tab Rect", options );

		DrawUIState state;
		ctx->drawThemeTabPage( &tabsR, state );

		
		

	}
};	



class SlidersPanel : public Panel {
public:
	SlidersPanel() {
		setBorder( NULL );
	}
	virtual void paint( GraphicsContext* ctx ) {
		Panel::paint( ctx );

		Rect r = getClientBounds();

		r.inflate( -10, -10 );

		int height = 40;

		Rect sliderR = r;
		Rect textR = r;
		sliderR.right_ = sliderR.left_ + sliderR.getWidth()/2;
		sliderR.bottom_ = sliderR.top_ + height;

		textR.left_ = sliderR.right_;
		textR.bottom_ = sliderR.bottom_;

		long options = GraphicsContext::tdoCenterHorzAlign | 
							GraphicsContext::tdoCenterVertAlign;

		ctx->textBoundedBy( &textR, "Horizontal Slider Rect", options );

		SliderState horzState;
		horzState.setEnabled( true );
		horzState.setTickMarkingOnTopLeft( true );
		horzState.setTickMarkingOnBottomRight( false );
		horzState.setVertical( false );
		horzState.min_ = 0;
		horzState.max_ = 100;
		horzState.position_ = 23;
		
		ctx->drawThemeSlider( &sliderR, horzState );
		

		sliderR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );


		horzState.setEnabled( false );
		horzState.position_ = 65;
		horzState.setTickMarkingOnBottomRight(true);
		horzState.setTickMarkingOnTopLeft( false );
		

		ctx->textBoundedBy( &textR, "Horizontal Slider disabled Rect", options );
		ctx->drawThemeSlider( &sliderR, horzState );

		sliderR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );


		horzState.setEnabled( true );
		horzState.position_ = 37;
		horzState.setTickMarkingOnBottomRight(false);
		horzState.setTickMarkingOnTopLeft( false );
		horzState.setPressed( true );

		ctx->textBoundedBy( &textR, "Horizontal Slider pressed Rect", options );
		ctx->drawThemeSlider( &sliderR, horzState );

		sliderR.offset( 0, height + 10 );
		textR.offset( 0, height + 10 );

		sliderR.bottom_ += 40;
		textR.bottom_ += 40;


		ctx->textBoundedBy( &textR, "Vertical Slider Rect", options );

		SliderState vertState;
		vertState.setEnabled( true );
		vertState.setTickMarkingOnTopLeft( true );
		vertState.setTickMarkingOnBottomRight( false );
		vertState.setVertical( true );
		vertState.min_ = 0;
		vertState.max_ = 100;
		vertState.position_ = 23;
		
		ctx->drawThemeSlider( &sliderR, vertState );

		sliderR.offset( 0, sliderR.getHeight() + 10 );
		textR.offset( 0, textR.getHeight() + 10 );

		ctx->textBoundedBy( &textR, "Vertical Slider Rect disabled", options );
		vertState.setEnabled( false );
		vertState.position_ = 65;
		vertState.setTickMarkingOnBottomRight(true);
		vertState.setTickMarkingOnTopLeft( false );
		ctx->drawThemeSlider( &sliderR, vertState );

		sliderR.offset( 0, sliderR.getHeight() + 10 );
		textR.offset( 0, textR.getHeight() + 10 );


		vertState.setEnabled( true );
		vertState.position_ = 37;
		vertState.setTickMarkingOnBottomRight(false);
		vertState.setTickMarkingOnTopLeft( false );
		vertState.setPressed( true );

		ctx->textBoundedBy( &textR, "Vertical Slider pressed Rect", options );
		ctx->drawThemeSlider( &sliderR, vertState );
	}
};	



class ThemesWindow : public Window {
public:
	ThemesWindow() {
		setCaption( "Themes" );	
		

		TabbedPages* pages = new TabbedPages();
		add( pages, AlignClient );

		pages->addNewPage( "System Colors" )->getPageComponent()->getContainer()->add( new SysColorsPanel(), AlignClient );

		pages->addNewPage( "Buttons" )->getPageComponent()->getContainer()->add( new ButtonsPanel(), AlignClient );

		pages->addNewPage( "Edges and Stuff" )->getPageComponent()->getContainer()->add( new EdgesPanel(), AlignClient );

		pages->addNewPage( "Tabs" )->getPageComponent()->getContainer()->add( new TabsPanel(), AlignClient );

		pages->addNewPage( "Sliders" )->getPageComponent()->getContainer()->add( new SlidersPanel(), AlignClient );
	
		
	}

	virtual ~ThemesWindow(){
		
	};
};




class ThemesApplication : public Application {
public:

	ThemesApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new ThemesWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( 100.0, 100.0, 500.0, 500.0 );
		mainWindow->show();

		
		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new ThemesApplication( argc, argv );

	Application::main();
	
	return 0;
}


