#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_REGISTRY_H__
#define _VCF_REGISTRY_H__


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


namespace VCF {

enum RegistryKeyType{
	RKT_ROOT=0,
	RKT_CURRENT_USER,
	RKT_LOCAL_MACHINE
};

enum RegistryDataType{
	RDT_STRING = 0,
	RDT_INTEGER,
	RDT_BOOL,
	RDT_BINARY
};


/**
*a class that wraps up a specific registry value that may
*be a string, integer, bool, or stream of binary data
*/
class FRAMEWORK_API RegistryValueInfo : public Object {
public:

	RegistryValueInfo( VariantData* data, const RegistryDataType& dataType, 
		               const String& valueName, char* dataBuffer=NULL, const uint32& dataBufferSize=0  ){		
		
		dataType_ = dataType;

		valueName_ = valueName;
		
		dataBufferSize_ = dataBufferSize;

		dataBuffer_ = NULL;

		if ( NULL != data ){
			switch ( dataType_ ){
				case RDT_STRING :{
					data_ = (String)*data;
				}
				break;

				case RDT_INTEGER :{
					data_ = (ulong32)*data;
				}
				break;

				case RDT_BOOL :{
					data_ = (bool)(*data);
				}
				break;

				case RDT_BINARY :{
					dataBuffer_ = dataBuffer;
				}
				break;
			}	
		}
	}


	virtual ~RegistryValueInfo(){
		if ( NULL != dataBuffer_ ){
			delete dataBuffer_;
		}
	}

	RegistryDataType dataType_;

	VariantData data_; 

	String valueName_;

	char* dataBuffer_;

	uint32 dataBufferSize_;
};



class RegistryPeer;

/**
*The registry represents an external data source that applications
*may store application data in. This may be things like special file names,
*UI positions, application state data etc. The external data may be anything
*depending on the OS. In Win32, this represents a connection to the 
*Win32 registry data base. 
*/
class FRAMEWORK_API Registry  : public Object{

public:
	Registry();

	virtual ~Registry();

	void setRoot( const RegistryKeyType& rootKey );
	
	RegistryKeyType getRoot();

	bool openKey( const String& keyname, const bool& createIfNonExistant=false );

	bool setValue( const String& value, const String& valuename ); 

	bool setValue( const uint32& value, const String& valuename ); 
	
	bool setValue( const bool& value, const String& valuename ); 

	bool setValue( void* dataBuffer, const uint32& dataBufferSize, const String& valuename ); 

	String getStringValue( const String& valuename );

	uint32 getIntValue( const String& valuename );

	bool getBoolValue( const String& valuename );

	void getDataBufValue( const String& valuename, uint32& dataBufferSize, void** dataBuffer );

	Enumerator<String>* getKeyNames();

	Enumerator<RegistryValueInfo*>* getValues();

	String getCurrentKey();
private:
	RegistryPeer* peer_;
};

}; //end of namespace VCF

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.10.2.1  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10  2004/01/20 01:54:55  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.9.2.1  2004/01/18 04:52:46  ddiego
*Added a new EnumSet class that handles manipulating unsigned longs
*as a mask of bits. Adds support for reading in the enum value names and
*ORing them together to form the complete mask value. Also made
*mods to the VFFOutput and VFFInput stream classes so that that the []
*property is correctly read and written
*
*Revision 1.9  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.8.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.8  2003/05/17 20:37:17  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.22.1  2003/03/12 03:11:51  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.7  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_REGISTRY_H__


