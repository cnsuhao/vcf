
/**
Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in
	the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
 OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 NB: This software will not save the world.
 */
 
#ifndef _VCF_OSXTHREAD_H__
#define _VCF_OSXTHREAD_H__

namespace VCF
{

class OSXThread : public ThreadPeer
{

public:

    /* Creates a normal priority, joinable thread */
    OSXThread( Thread* thread );

    /* Cancels the thread if it is still running */
	virtual ~OSXThread();

    /* Start the thread */
	virtual bool start();

    /* Stops the thread.  If called in Thread::run() the thread exits. */
	virtual void stop();

    /* Returns thread id */
	virtual uint32 getThreadID() {
		return threadID_; 
	}
	
	virtual uint32 getHandleID() {
		return threadID_; 
	}

    /* Returns process that created thread.  Is this useful? */
	virtual uint32 getOwningProcessID() {
		return processID_; 
	}

    /* Returns TRUE if thread is running, FALSE if not */
    virtual bool isActive() {
		return isActive_; 
	}

    /* Returns TRUE if thread is detached, FALSE if not */
    virtual bool isDetached() {
		return isDetached_; 
	}

    /* Detaches thread so it does not have to be joined */
    virtual void detach();

    /* Joins with thread if it is not detached.
		Has no affect if called inside the Thread object. */
    virtual void join();

    /* Enables this thread to yield the CPU to another, if any.
		Has no affect if called outside the Thread object.       */
    virtual void yield();

    /* Enables this thread to exit Thread::run at an arbitrary point.
		Has no affect if called outside Thread object.                */
    virtual void exit();

    /* Returns TRUE if called in Thread::run(), FALSE if not */
	/*
    int inThreadProc() {
		return pthread_self() == threadID_; 
	}
	*/

    /* Not implemented yet */
	virtual void sleep( uint32 milliseconds );

    // Not implemented and should be deprecated
	virtual void pause() {}

protected:
	uint32 threadID_;
    uint32 processID_;
	Thread* thread_;
    bool isActive_;
    bool isDetached_;
};

};
 
 
/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
 *migration towards new directory structure
 *
 *Revision 1.3.2.1  2004/04/26 21:58:43  marcelloptr
 *changes for dir reorganization: _VCF_MACRO_H__
 *
 *Revision 1.3  2004/04/03 15:48:42  ddiego
 *Merged over code from the 0-6-3 branch.
 *
 *Revision 1.2.6.1  2004/02/21 03:27:06  ddiego
 *updates for OSX porting
 *
 *Revision 1.2  2003/05/17 20:37:12  ddiego
 *this is the checkin for the 0.6.1 release - represents the merge over from
 *the devmain-0-6-0 branch plus a few minor bug fixes
 *
 *Revision 1.1.2.1  2003/05/15 03:01:01  ddiego
 *added initial osx source( FoundationKit only),
 *plus some fixes to compile under GCC 3.x compilers
 *
 */
 
 
#endif // _VCF_OSXTHREAD_H__
 
 