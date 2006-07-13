//Object.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */
//#include "vcf/FoundationKit/FoundationKit.h"
#include <typeinfo>

#include "vcf/FoundationKit/Class.h"
#include "vcf/FoundationKit/ClassRegistry.h"
#include "vcf/FoundationKit/Format.h"
#include "vcf/FoundationKit/Mutex.h"
#include "vcf/FoundationKit/Object.h"
#include "vcf/FoundationKit/StringUtils.h"

using namespace VCF;

#ifdef USE_VCF_NEW
std::list<void*> Object::allocatedObjects;
#endif

Object::Object()
{
	//initialized to zero
	//so a release after creating this object
	//will automaitically free it
	refCount_ = 0;

}

Object::~Object()
{

}

void Object::init()
{

}

void Object::destroy()
{

}

void Object::free()
{
	refCount_ = 0;

	destroy();

	delete this;
}

uint32 Object::addRef(Object* owner)
{
	refCount_ ++;

	return refCount_;
}

uint32 Object::release(Object* owner)
{
	if ( refCount_ > 0 ) {
		refCount_ --;
	}

	if ( 0 == refCount_ )  {
		free();
		return 0;
	}

	return refCount_;
}

Class* Object::getClass()
{

	Class* result = ClassRegistry::getClass( this );
	if ( NULL != result ){
		result->setSource( this );
	}
	return result;
}

String Object::getClassName()
{
	String result = "";
	Class* clazz = this->getClass();
	if ( NULL != clazz ){
		result = clazz->getClassName();
	}
	else {
#ifdef VCF_RTTI
		result = StringUtils::getClassNameFromTypeInfo( typeid(*this) );
#endif
	}

	return result;
}

String Object::toString()
{
	String result;
	/*
	JC : I commented this out - I think there was some confusion about how this was supposed
	to work. By using %ls we can pass in a WideChar*. If you use an ansi char* I am not sure
	what will happen.
	The simpler solution is to just use the StringUtils::format() function, which
	uses less ansi to wide char transformation.
	I would like to thank Aroman for catching this though!
	char info[256];
	sprintf( info, "%ls @ %p, refcount: %d",
		     this->getClassName().ansi_c_str(), this, (int)refCount_ );
	result += info;
	*/
	//Note: %ls means we can pass in a WideChar* - if we wanted to
	//pass in a char* we would need to use the %s formatter
	result = StringUtils::format( Format("%ls @ %p, refcount: %d") % getClassName().c_str() % this % (int)refCount_ );

	return result;
}

uint32 Object::hash()
{
	return (uint32)this;
}


void Object::trackDebugMemory( const bool& trackMemory )
{
#ifdef _VCF_DEBUG_NEW
	Object::trackingDebugMemory = trackMemory;
#endif //_VCF_DEBUG_NEW
}


bool Object::isDebugMemoryTracked()
{
#ifdef _VCF_DEBUG_NEW
	return Object::trackingDebugMemory;
#else
	return false;
#endif //_VCF_DEBUG_NEW
}


#ifdef _VCF_DEBUG_NEW

Mutex* Object::accessMutex_ = NULL;

bool Object::trackingDebugMemory = true;

std::map<uint32,Object::DebugInfo> Object::debugAllocationMap;



void * Object::operator new( size_t allocationSize )
{

	void *newPtr = ::operator new( allocationSize );
	if ( true == Object::trackingDebugMemory ) {
		if( newPtr != 0 ){
			if ( NULL != Object::accessMutex_ ) {
				Object::accessMutex_->lock();
			}

			DebugInfo info;
			info.objAddress_ = (uint32)newPtr;
			info.objectAllocationSize_ = allocationSize;
			Object::debugAllocationMap[info.objAddress_] = info;

			if ( NULL != Object::accessMutex_ ) {
				Object::accessMutex_->unlock();
			}
		}
	}

    return newPtr;
}

void Object::operator delete( void *objectPointer )
{
	if ( true == Object::trackingDebugMemory ) {
		if ( NULL != Object::accessMutex_ ) {
			Object::accessMutex_->lock();
		}

		std::map<uint32,Object::DebugInfo>::iterator found;
		found = Object::debugAllocationMap.find( (uint32)objectPointer );
		if ( found != Object::debugAllocationMap.end() ) {

			Object::debugAllocationMap.erase( found );
		}

		if ( NULL != Object::accessMutex_ ) {
			Object::accessMutex_->unlock();
		}
	}

	::operator delete ( objectPointer );
}

void Object::dumpDebugInfo()
{
	if ( true == Object::trackingDebugMemory ) {
		if ( !Object::debugAllocationMap.empty() ) {

			StringUtils::trace( "Oops there are objects still left. Dumping memory info...\n" );
			StringUtils::traceWithArgs( Format("There are %d objects still left over that did not get deleted\n") %
				Object::debugAllocationMap.size() );

			int totalAllocationSize = 0;

			std::map<uint32,Object::DebugInfo>::const_iterator it = Object::debugAllocationMap.begin();
			while ( it != Object::debugAllocationMap.end ()  ) {
				const DebugInfo& info = it->second;
				String className = "unknown";

				try {
					Object* o = (Object*)info.objAddress_;
					className = StringUtils::getClassNameFromTypeInfo( typeid(*o) );
				}
				catch ( ... ) {
					className = "unknown<exception occured retreiving class name>";
				}

				StringUtils::traceWithArgs( Format("\tObject (type: %ls) @ %p, allocated size of %d bytes\n") %
												className.c_str() % info.objAddress_ % info.objectAllocationSize_ );

				totalAllocationSize += info.objectAllocationSize_;
				it ++;
			}

			StringUtils::traceWithArgs( Format("Total allocated memory size of %d bytes in %d object(s).\n") %
					totalAllocationSize % Object::debugAllocationMap.size() );

			Object::debugAllocationMap.clear();

			StringUtils::trace( "Finished Object::dumpDebugInfo()\n" );
		}
	}
	else {
		StringUtils::trace( "There is no debug memory information to track because Object::trackingDebugMemory is false \n" );
		StringUtils::trace( "If you would like to track memory, call Object::trackDebugMemory( true ) before initFoundationKit() \n" );
	}
}

#endif //_VCF_DEBUG_NEW

uint32 Object::objectAllocationCount()
{
#ifdef _VCF_DEBUG_NEW
	std::map<uint32,Object::DebugInfo>::const_iterator it = Object::debugAllocationMap.begin();
	uint32 totmem = 0;
	while ( it != Object::debugAllocationMap.end ()  ) {
		const DebugInfo& info = it->second;

		totmem += info.objectAllocationSize_;

		it ++;
	}
	StringUtils::traceWithArgs( Format("Total memory allocated: %d bytes\n") % totmem );

	return Object::debugAllocationMap.size();
#endif
	return 0;
}


/**
$Id$
*/
