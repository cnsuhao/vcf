#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_FIELD_H__
#define _VCF_FIELD_H__

/**
Copyright (c) 2000-2001, Jim Crafton
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

namespace VCF {
	

/**
The Field class allows RTTI introspection to support member variables of 
a class. There are some limits on how it works though, due to some 
features of teh C++ langauge. At the very least you cannot use it 
with member variables whose type is itself a class that has operator& 
overloaded. 
*/
class FRAMEWORK_API Field {
public:
	Field() :source_(NULL){

	}

	Field( const Field& rhs ) :name_(rhs.name_), source_(rhs.source_) {

	}

	virtual ~Field(){}	

	String getName() {
		return name_;
	}

	void setName( const String& name ) {
		name_ = name;
	}

	virtual Field* clone()  = 0;

	virtual ulong32 getFieldSize()  = 0;

	virtual String getFieldTypeName() = 0;

	virtual VariantData* get( Object* source ) = 0;

	virtual void set( Object* source, VariantData* data ) = 0;

	virtual void setSource( Object* source ) {
		source_ = source ;
	};

	VariantData* get() {
		if ( NULL == source_ ) {
			return NULL;
		}
		else {
			return get( source_ );
		}
	}

	void set( VariantData* data ) {
		if ( source_ != NULL ) {
			set( source_, data );
		}
	}
protected:
	String name_;
	Object* source_;
};



};


#endif // _VCF_FIELD_H__




