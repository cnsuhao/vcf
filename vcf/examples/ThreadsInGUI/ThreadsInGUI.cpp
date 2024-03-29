//ThreadsInGUI.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "vcf/ApplicationKit/ListItem.h"

using namespace VCF;




/**
This example will demonstrate running a separate thread that
increments a count, and then updating it's state in the user
interface
*/


class CounterThreadEvent : public Event {
public:
	CounterThreadEvent(Object* source, const String& info, int index) : Event(source,0),info_(info),index_(index){
		
	}

	String info_;
	int index_;
};

/**
This is our thread class which does the work of incrementing a
count variable. Our thread class is not an auto-delete thread
and the thread's deletion is done by and event handler that
is notified when the thread is ready to be deleted.
It takes three event handlers in it's constructor, one
for notification of a change in state, one for notification
that the thread has stopped, and one to notify the event
handler's owner that the thread should be deleted.
*/
class CounterThread : public Thread {
public:
	CounterThread( int index, EventHandler* changed,
					EventHandler* stopped,
					EventHandler* deleteMe ):Thread(false),
											index_(index),
											changed_(changed),
											stopped_(stopped),
											deleteMe_(deleteMe),
											currentCount_(0){

	}


	/**
	our run method initializes the currentCount_ to 0
	*/
	virtual bool run() {
		currentCount_ = 0;

		/**
		Loop while we're able to, and increment the count
		each time we do this we'll post an event for this
		see the change() method
		*/
		while ( canContinue() && currentCount_ < 1000 ) {
			currentCount_ ++;

			change();

			sleep( 1 );
		}
		currentCount_ = -1;

		/**
		post the change once more
		*/
		change();

		/**
		post a stop event and a deletion event
		*/
		stopped();
		return true;
	}

	int currentCount() {
		return currentCount_;
	}

	int index() {
		return index_;
	}
protected:
	/**
	This post's an event to the windowing systems event queue,
	which will in turn invoke our changed_ event handler.
	We pass in false, to prevent the UIToolkit from automatically
	deleting the changed_ event handler
	*/
	void change() {
		String s = toString();
		s += " " + StringUtils::toString( currentCount() );

		UIToolkit::postEvent( changed_, new CounterThreadEvent(this,s,index_), false );
	}

	/**
	This post's an stopped event, and then a deletion event.
	When the deletion event handler is invoked, the thread will
	be deleted
	*/
	void stopped() {
		
		String s = toString() + " stopped.";
		UIToolkit::postEvent( stopped_, new CounterThreadEvent(this,s,index_), false );

		
		s = toString() + " thread died and is dead and gone";

		UIToolkit::postEvent( deleteMe_, new CounterThreadEvent(this,s,index_), false );
	}

	int index_;
	int currentCount_;
	EventHandler* changed_;
	EventHandler* stopped_;
	EventHandler* deleteMe_;
};










class MyThreadPool {
public:

	class ThreadPoolThread;




	class ThreadPoolThread : public Thread {
	public:
		ThreadPoolThread(MyThreadPool& pool):threadPool_(pool){}

		virtual bool run() {
			while ( canContinue() ) {
				
				threadPool_.waitForNewThreads();
				StringUtils::trace( "waitForNewThreads done\n" );

				threadPool_.waitForThreadsToFinish();
				StringUtils::trace( "waitForThreadsToFinish done\n" );
			}

			StringUtils::trace( "ThreadPoolThread done\n" );
			return true;
		}

		MyThreadPool& threadPool_;
	};


	MyThreadPool():waiting_(false) {
		waitCondition_ = new Condition( &waitMutex_ );

		poolThread_ = new ThreadPoolThread( *this );
		poolThread_->start();
	}
	
	~MyThreadPool() {
		
		waitCondition_->broadcast();

		StringUtils::trace( "stopping ThreadPoolThread\n" );
		poolThread_->stop();

		StringUtils::trace( "waitCondition_->broadcast()\n" );
		waitCondition_->broadcast();

		

		delete waitCondition_;
	}

	bool waiting() const {
		return waiting_;
	}


	void waitForNewThreads() {
		waitCondition_->wait(1000);
	}
	

	void addThread( Thread* th ) {
		Lock l(poolMutex_);
		threads_.push_back( th );
		th->start();

		waitCondition_->broadcast();
	}
	
	
	void waitForThreadsToFinish() {		

		waiting_ = true;
		
		std::vector<Thread*>::iterator first = threads_.begin();
		while ( first != threads_.end() ) {
			poolMutex_.lock();
			Thread* thread = *first;

			threads_.erase(first);

			StringUtils::trace( "Removed thread\n" );
			poolMutex_.unlock();
			

			thread->wait();
			

			if ( !thread->canAutoDelete() ) {
				delete thread;
				StringUtils::trace( "Freed thread\n" );
			}
			

			first = threads_.begin();
		}		

		waiting_ = false;
	}
	
protected:
	Mutex waitMutex_;
	Condition* waitCondition_;
	Mutex poolMutex_;
	std::vector<Thread*> threads_;
	bool waiting_;

	Thread* poolThread_;
	
};







/**
*/
class ThreadsInGUIWindow : public Window {
public:
	ThreadsInGUIWindow() {
		setCaption( "ThreadsInGUI" );

		setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );

		EventHandler* ev =
			new ClassProcedure1<Event*,ThreadsInGUIWindow>( this,
														&ThreadsInGUIWindow::threadChanged,
														"ThreadsInGUIWindow::threadChanged" );

		ev =
			new ClassProcedure1<Event*,ThreadsInGUIWindow>( this,
														&ThreadsInGUIWindow::threadStopped,
														"ThreadsInGUIWindow::threadStopped" );

		ev =
			new ClassProcedure1<Event*,ThreadsInGUIWindow>( this,
														&ThreadsInGUIWindow::deleteThread,
														"ThreadsInGUIWindow::deleteThread" );

		CommandButton* btn = new CommandButton();
		btn->setBounds( 20, 20, 100, btn->getPreferredHeight() );
		btn->setCaption( "Start Thread" );
		add( btn );

		btn->ButtonClicked += new ClassProcedure1<ButtonEvent*,ThreadsInGUIWindow>( this,
														&ThreadsInGUIWindow::addThread,
														"ThreadsInGUIWindow::addThread" );


		listBox_ = new ListBoxControl();

		Rect bounds = getClientBounds();
		bounds.inflate( -5, -5 );

		bounds.top_ += (btn->getTop() + btn->getHeight());

		listBox_->setAnchor( AnchorLeft | AnchorTop | AnchorBottom | AnchorRight );
		listBox_->setBounds( &bounds );

		add( listBox_ );


		setVisible( true );
	}

	void addThread( ButtonEvent* e ) {
		ListModel* lm = listBox_->getListModel();		
		lm->add( "" );

		
		Thread* thread = new CounterThread( lm->getCount()-1, 
										(EventHandler*)getCallback("ThreadsInGUIWindow::threadChanged"),
										(EventHandler*)getCallback("ThreadsInGUIWindow::threadStopped"),
										(EventHandler*)getCallback("ThreadsInGUIWindow::deleteThread") );

		pool.addThread( thread );
	}

	virtual ~ThreadsInGUIWindow(){};

	void threadStopped( Event* e ) {
		CounterThreadEvent* thEvent = (CounterThreadEvent*)e;

		ListModel* lm = listBox_->getListModel();
		lm->setAsString( thEvent->index_, thEvent->info_ );		
		listBox_->repaint();
	}

	void threadChanged( Event* e ) {
		CounterThreadEvent* thEvent = (CounterThreadEvent*)e;

		ListModel* lm = listBox_->getListModel();
		lm->setAsString( thEvent->index_, thEvent->info_ );	
		listBox_->repaint();
	}

	void deleteThread( Event* e ) {
		CounterThreadEvent* thEvent = (CounterThreadEvent*)e;

		ListModel* lm = listBox_->getListModel();
		lm->setAsString( thEvent->index_, thEvent->info_ );	
		listBox_->repaint();
	}

	ListBoxControl* listBox_;

	MyThreadPool pool;
};




class ThreadsInGUIApplication : public Application {
public:

	ThreadsInGUIApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();

		Window* mainWindow = new ThreadsInGUIWindow();
		setMainWindow(mainWindow);


		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new ThreadsInGUIApplication( argc, argv );

	Application::main();

	return 0;
}


/**
$Id$
*/
