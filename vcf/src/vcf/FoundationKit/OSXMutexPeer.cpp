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


