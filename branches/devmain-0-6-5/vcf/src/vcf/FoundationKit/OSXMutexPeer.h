#ifndef _VCF_OSXMUTEXPEER_H__
#define _VCF_OSXMUTEXPEER_H__
//OSXMutexPeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF
{

/**
*Class ConditionalPeer documentation
*/
class OSXMutex : public MutexPeer
{
public:
	OSXMutex();
	virtual ~OSXMutex();
	virtual bool lock();
	virtual bool unlock();
	virtual uint32 getHandleID() { return (uint32)&mutex_; }

protected:
	uint32 mutex_;
};

};


/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
 *reformatting of source files: macros and csvlog and copyright sections
 *
 *Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
 *migration towards new directory structure
 *
 *Revision 1.3.2.1  2004/04/26 21:58:42  marcelloptr
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


#endif // _VCF_OSXMUTEXPEER_H__


