//DateTimeUI.cpp


#include "ApplicationKit.h"
#include "ControlsKit.h"
#include "utils/DateTime.h"


using namespace VCF;


class Calendar : public CustomControl {
public:


	Calendar() {
	
		EventHandler* ev = new KeyboardEventHandler<Calendar>( this, &Calendar::onUpArrow, "Calendar::onUpArrow" );

		Application::getRunningInstance()->addAcceleratorKey( vkUpArrow, 0, ev );

		Application::getRunningInstance()->addAcceleratorKey( vkUpArrow, kmCtrl, ev );

		Application::getRunningInstance()->addAcceleratorKey( vkUpArrow, kmCtrl | kmShift, ev );

		ev = new KeyboardEventHandler<Calendar>( this, &Calendar::onDownArrow, "Calendar::onDownArrow" );

		Application::getRunningInstance()->addAcceleratorKey( vkDownArrow, 0, ev );

		Application::getRunningInstance()->addAcceleratorKey( vkDownArrow, kmCtrl, ev );

		Application::getRunningInstance()->addAcceleratorKey( vkDownArrow, kmCtrl | kmShift, ev );
	}


	virtual void paint( GraphicsContext* ctx ) {
		CustomControl::paint( ctx );

		DateTime tmp( current.getYear(), current.getMonth(), 1 );
		DateTime::Iterator<ByDay> dayIter = tmp;

		Rect rect = getClientBounds();

		ctx->setColor( Color::getColor("black") );
		ctx->rectangle( &rect );
		ctx->strokePath();

		Rect textRect = rect;

		textRect.bottom_ = 100;
		textRect.inflate( -5, -5 );

		String s = 
			StringUtils::format( "%s. %s", 
						StringUtils::format( tmp, "The current month starts on %A, %B %d, %Y" ).c_str(),
						StringUtils::format( current, "Today is %A, %B %d, %Y week %#W" ).c_str() );

		String s2 = 
			StringUtils::format( "\nThe current month has %d days in it, and the current year has %d days in it, starts on week %d,\nand has %d total weeks in the year\n",
										tmp.getNumberOfDaysInMonth(), 
										tmp.getDaysInYear(),
										tmp.getWeekOfYearStartingMon(),
										tmp.getWeeksInYear() );

		s += s2;
		s += StringUtils::format( current, "The current time is %#I:%M:%S" );

		s += current.isAM() ? " AM" : " PM";

		ctx->textBoundedBy( &textRect, s );

		rect.top_ += 100;


		Size sz;
		sz.width_ = rect.getWidth() / 7 - 2;
		sz.height_ = rect.getHeight() / 7 - 2;
		

		int x,y;
		x = y = 1;
		y = rect.top_ + 1;
		Rect cellRect;

		for ( int i=0;i<7;i++ ) {		
			for ( int j=0;j<7;j++) {
				ctx->setColor( Color::getColor("black") );
				cellRect.setRect( x, y, x + sz.width_, y + sz.height_ );
				ctx->rectangle( &cellRect );
				ctx->strokePath();
				
				if ( 0 == i ) {
					cellRect.inflate( -1, -1 );
					
					ctx->setColor( &Color(0.8,0.8,0.8) );
					ctx->rectangle( &cellRect );
					ctx->fillPath();
					
					switch ( j ) {
						case 0 : {
							ctx->textBoundedBy( &cellRect, "Sun" );
						}
						break;

						case 1 : {
							ctx->textBoundedBy( &cellRect, "Mon" );
						}
						break;

						case 2 : {
							ctx->textBoundedBy( &cellRect, "Tues" );
						}
						break;

						case 3 : {
							ctx->textBoundedBy( &cellRect, "Wed" );
						}
						break;

						case 4 : {
							ctx->textBoundedBy( &cellRect, "Thurs" );
						}
						break;

						case 5 : {
							ctx->textBoundedBy( &cellRect, "Fri" );
						}
						break;

						case 6 : {
							ctx->textBoundedBy( &cellRect, "Sat" );
						}
						break;

					}
				}
				else {
					cellRect.inflate( -3, -3 );
					DateTime dt = *dayIter;
					bool drawText = false;
					if ( 1 == i ) {
						if ( j >= dt.getWeekDay() ) {
							drawText = true;
						}
					}
					else if (dt.getMonth() == tmp.getMonth()) {
						drawText = true;
					}			
					
					if ( drawText == true ) {
						if ( dt.getDayOfYear() == current.getDayOfYear() ) {							
							ctx->setColor( &Color(1.0,0.8,0.0) );
							ctx->rectangle( &cellRect );
							ctx->fillPath();
						}
						ctx->textBoundedBy( &cellRect, StringUtils::format( dt, "%#d") );

						dayIter ++;
					}
					
				}
				

				x += sz.width_;
			}
			y += sz.height_;
			x = 1;
		}

	}



	void onUpArrow( KeyboardEvent* e ) {

		if ( e->hasShiftKey() && e->hasControlKey() ) {
			current.incrDay();
		}
		else if ( e->hasControlKey() ) {
			current.incrMonth();
		}
		else {
			current.incrYear();
		}

		repaint();
	}

	void onDownArrow( KeyboardEvent* e ) {

		if ( e->hasShiftKey() && e->hasControlKey() ) {
			current.decrDay();
		}
		else if ( e->hasControlKey() ) {
			current.decrMonth();
		}
		else {
			current.decrYear();
		}

		repaint();
	}

	DateTime current;
};


class DateTimeUIWindow : public Window {
public:
	DateTimeUIWindow() {
		setCaption( "DateTimeUI" );
		setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );

		setVisible( true );

		Calendar* calendar = new Calendar();

		Rect r = getClientBounds();
		r.inflate( -10, -10 );
		calendar->setBounds( &r );
		calendar->setAnchor( AnchorTop|AnchorBottom|AnchorRight|AnchorLeft);
		calendar->setColor( Color::getColor("white") );

		calendar->current = DateTime::now();
		add( calendar );
	}

	virtual ~DateTimeUIWindow(){};

};




class DateTimeUIApplication : public Application {
public:

	DateTimeUIApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();
		
		Window* mainWindow = new DateTimeUIWindow();
		setMainWindow(mainWindow);
		
		
		return result;
	}

};


int main(int argc, char *argv[])
{
	DateTimeUIApplication app( argc, argv );

	Application::main();
	
	return 0;
}


