////Conditions.cpp

#include "FoundationKit.h"

using namespace VCF;


static Mutex* theMutex = NULL;
static Condition* theCondition = NULL;
static producerDone = false;

class Reporter : public Runnable {
public:
	virtual bool run() {
		int count = 0;
		System::println( "Reporter %p starting...", this );

		while ( count < 10 && !producerDone ) {
			Lock l(*theMutex);
			
			theCondition->wait();

			System::println( "Reporter: Done waiting report %d, reporting from %p:\n\tNews Flash! Yada yada yada!", count + 1, this );
			count ++;
		}

		System::println( "Reporter done!" );

		return true;
	}

	virtual void stop() {
		System::println( "The Reporter has left the building!" );
	}
};


class Producer : public Runnable {
public:
	virtual bool run() {
		int count = 0;
		while ( count < 10 ) {
			Lock l(*theMutex);

			System::println("Producer chomping %d vitamins...\n\tchomp, chomp, chomp...", count );
			System::sleep( 300 );
			System::println( "Yawn...Burp!" );
			System::sleep( 100 );
			System::println( "...Fart!" );



			theCondition->broadcast();

			System::println( "Done chomping!" );


			count++;
		}

		System::println( "Producer done!" );
		producerDone = true;
		theCondition->broadcast();

		return true;
	}

	virtual void stop() {
		
	}
};




int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	theMutex = new Mutex();

	theCondition = new Condition( theMutex );


	Thread* th1 = new Thread( new Reporter() );
	th1->start();	

	Thread* th2 = new Thread( new Reporter() );
	th2->start();


	Thread* producer = new Thread( new Producer() );
	producer->start();
	
	producer->wait();
	
	
	//theCondition->broadcast();	

	System::sleep( 100 );


	theMutex->free();
	theCondition->free();

	FoundationKit::terminate();
	return 0;
}


