//OSXMutexPeer.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

OSXMutex::OSXMutex():
mutex_(0)
{
    //pthread_mutex_init(&mutex_, NULL);
}

OSXMutex::~OSXMutex()
{
//    pthread_mutex_destroy(&mutex_);
}

bool OSXMutex::lock()
{
   // if ( pthread_mutex_lock(&mutex_) == 0 ) return true;
    return false;
}

bool OSXMutex::unlock()
{
    //if ( pthread_mutex_unlock(&mutex_) == 0 ) return true;
    return false;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


