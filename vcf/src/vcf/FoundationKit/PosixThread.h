
/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

#ifndef _VCF_POSIXTHREAD_H__
#define _VCF_POSIXTHREAD_H__

namespace VCF
{

class PosixThread : public ThreadPeer
{

public:

    /* Creates a normal priority, joinable thread */
    PosixThread( Thread* thread );	

    /* Cancels the thread if it is still running */
	virtual ~PosixThread();

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

    
    /* Returns TRUE if called in Thread::run(), FALSE if not */
    int inThreadProc() { 
		return pthread_self() == threadID_; 
	}
   
    /* Not implemented yet */
	virtual void sleep( uint32 milliseconds );
	
	virtual int wait();

	virtual int wait( uint32 milliseconds );

	virtual bool isActive() {
		return isActive_;
	}

	virtual void pause() {} //JC - not implemented
protected:


	pthread_t threadID_;
    pid_t processID_;
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
*Revision 1.4.2.1  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.3.6.1  2004/03/30 01:48:16  ddiego
*updated linux code
*
*Revision 1.3  2003/05/17 20:37:12  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.2.1  2003/03/23 03:23:50  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.2  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.1.2.6  2003/02/19 00:12:33  catwallader
*Fixed comments and added some more to Thread.h.
*
*Revision 1.1.2.5  2003/02/18 20:03:30  catwallader
*Added Condition classes. Also added comments to Thread and Mutex class
*headers.
*
*Revision 1.1.2.4  2003/02/12 19:35:54  catwallader
*Added PosixMutex class.
*
*Revision 1.1.2.3  2003/02/08 18:49:06  ddiego
*added some fixes to handle multiple lines of text. Also made a minor change to
*PosixThread so everything links OK.
*
*Revision 1.1.2.2  2003/02/06 00:22:04  catwallader
*Added thread methods: isActive(), isDetached(), join(), exit(), yield() and detach().  Fleshed out PosixThread::stop().
*
*Revision 1.1.2.1  2003/01/30 22:32:20  catwallader
*Added the PosixThread class.  Modified Makefiles and toolkit files to accomodate it.
*
*/


#endif // _VCF_POSIXTHREAD_H__


