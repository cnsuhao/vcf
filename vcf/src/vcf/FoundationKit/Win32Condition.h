#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_WIN32CONDITION_H__
#define _VCF_WIN32CONDITION_H__


//Win32Condition.h


/**
Note this code is partially (mostly) based on the condition class 
from the Boost Threads library by William Kempf. 


Copyright (C) 2001-2003
William E. Kempf

Permission to use, copy, modify, distribute and sell this software
and its documentation for any purpose is hereby granted without fee,
provided that the above copyright notice appear in all copies and
that both that copyright notice and this permission notice appear
in supporting documentation.  William E. Kempf makes no representations
about the suitability of this software for any purpose.
It is provided "as is" without express or implied warranty.
*/



/**
Copyright (c) 2000-2004, Jim Crafton
All rights reserved.
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


namespace VCF  {

/**
Class Win32Condition documentation
Part/most of the implementation for this class comes from 
William E. Kempf's excellent condition class that is a 
part of the Thread library in Boost. Any mistakes are almost
certainly mine in translating it.
*/
class Win32Condition : public VCF::Object, public ConditionPeer { 
public:

	enum {
		MaxQueue = ((unsigned long)-1)/2
	};

	Win32Condition( Condition* condition );

	virtual ~Win32Condition();

	virtual int wait();

	virtual int wait( uint32 milliseconds );

	virtual void signal();    

    virtual void broadcast();

	virtual uint32 getHandleID() {
		return (uint32)0;
	}
protected:
	Condition* condition_;

	HANDLE gate_;
    HANDLE queue_;
	HANDLE mutex_;

	unsigned gone_;  // # threads that timed out and never made it to queue_
    unsigned long blocked_; // # threads blocked on the condition
    unsigned waiting_; // # threads no longer waiting for the condition but
                        // still waiting to be removed from queue_
};


}; //end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.1  2004/04/26 21:58:43  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.2  2004/03/12 04:05:30  ddiego
*minor documentation for condition stuff
*
*Revision 1.1.2.1  2004/03/11 22:19:58  ddiego
*added condition implementation to FoundationKit.
*added a Conditions example to the examples directory.
*
*/


#endif // _VCF_WIN32CONDITION_H__


