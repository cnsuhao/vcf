//LinuxThread.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

LinuxThread::LinuxThread( Thread* thread, const bool& runInLoop ):
	threadID_(0),
	threadHandle_(0),
	thread_(thread),
	runInLoop_(runInLoop),
	owningProcessID_(0)
{

}

LinuxThread::~LinuxThread()
{

}

bool LinuxThread::start()
{
	if ( false == runInLoop_ ){
		//threadHandle_ = _beginthreadex( security_, stackSize_, LinuxThread::threadProc, (void*)this, initFlags_, &threadID_ );
	}
	else {
		//threadHandle_ = _beginthreadex( security_, stackSize_, LinuxThread::loopThreadProc, (void*)this, initFlags_, &threadID_ );
	}

	return false;
}

void LinuxThread::pause()
{

}

void LinuxThread::stop()
{

}

ulong32 LinuxThread::threadProc( void* param )
{
	/*
	LinuxThread* peer = (LinuxThread*)param;
	if ( NULL != peer->thread_ ){

		peer->thread_->run();

		if ( true == peer->thread_->canAutoDelete() )
		{
			delete peer->thread_;
		}
	}
	*/
	return 0;
}

ulong32 LinuxThread::loopThreadProc( void* param )
{
	/*
	LinuxThread* peer = (LinuxThread*)param;
	if ( NULL != peer->thread_ ){
		bool runResult = true;
		while ( (peer->thread_->canContinue()) && (true == runResult) ){
			runResult = peer->thread_->run();
			Sleep( 0 );
		}
		if ( (true == peer->thread_->canAutoDelete()) && peer->thread_->canContinue() )	{
			delete peer->thread_;
		}
	}
	*/
	return 0;
}

void LinuxThread::sleep( unsigned int milliseconds )
{

}

int LinuxThread::wait()
{
	return -1;
}

int LinuxThread::wait( uint32 milliseconds )
{
	return -1;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:08  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.5  2004/04/03 15:48:46  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.4.6.1  2004/03/30 01:48:26  ddiego
*updated linux code
*
*Revision 1.4  2003/05/17 20:37:34  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.2  2003/03/23 03:23:57  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.2.1  2003/03/12 03:12:18  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2003/02/26 04:30:49  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.2.1  2002/12/27 23:04:51  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.2  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.1.8.1  2002/09/27 01:54:58  ddiego
*added support for bezier curves - remeber to change over to using teh MgcBeziers in Win32 too
*
*Revision 1.1  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*/


