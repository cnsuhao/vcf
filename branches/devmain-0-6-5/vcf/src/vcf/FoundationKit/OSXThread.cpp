//OSXThread.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

void* threadProc( void* arg )
{
    Thread* threadPtr = (Thread*)arg;
	threadPtr->run();
    return NULL;
}

OSXThread::OSXThread( Thread* thread ) :
threadID_(0),
//processID_(getpid()),
thread_(thread),
isActive_(false),
isDetached_(false)
{
}

OSXThread::~OSXThread()
{
    stop();
}

bool OSXThread::start()
{
    if ( isActive_ ) return true;
	/*
    if ( pthread_create(&threadID_, NULL, threadProc, this) != 0 )
    {
        isActive_ = true;
        return true;
    }
    else
	*/
	return false;
}

void OSXThread::stop()
{
    if ( isActive_ )
    {
        //pthread_cancel(threadID_);
//        detach();
  //      isActive_ = false;
    }
}

void OSXThread::sleep( uint32 milliseconds )
{
    if ( !isActive_ ) return;
}

void OSXThread::detach()
{
    if ( !isDetached_ )
    {
        //pthread_detach(threadID_);
        //isDetached_ = true;
    }
}

void OSXThread::join()
{
    if ( isActive_ && !isDetached_ ) //&& !inThreadProc() )
    {
//        pthread_join(threadID_, NULL);
        isActive_ = false;
    }
}

void OSXThread::yield()
{
    //if ( isActive_ && inThreadProc() ) sched_yield();
}

void OSXThread::exit()
{
   // if ( isActive_ && inThreadProc() ) pthread_exit(NULL);
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


