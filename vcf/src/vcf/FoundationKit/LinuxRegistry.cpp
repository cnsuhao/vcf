/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.3  2003/05/17 20:37:34  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.2.1  2003/03/12 03:12:18  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2003/02/26 04:30:49  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.1.12.2  2003/01/08 00:19:52  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.1.12.1  2002/12/03 01:15:50  ddiego
*stuff
*
*Revision 1.1  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*
*/

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
#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"

using namespace VCF;

LinuxRegistry::LinuxRegistry()
{
		
	
}

LinuxRegistry::~LinuxRegistry()
{
	
}

void LinuxRegistry::setRoot( const RegistryKeyType& rootKey )
{
	
}

RegistryKeyType LinuxRegistry::getRoot()
{
	return rootKeyType_;
}

bool LinuxRegistry::openKey( const String& keyname, const bool& createIfNonExistant )
{
	bool result = false;

	return result;
	
}

bool LinuxRegistry::setValue( const String& value, const String& valuename )
{
	return false;
}

bool LinuxRegistry::setValue( const uint32& value, const String& valuename )
{	

	return false;
}

bool LinuxRegistry::setValue( const bool& value, const String& valuename )
{
	return false;
}

bool LinuxRegistry::setValue( void* dataBuffer, const uint32& dataBufferSize, const String& valuename )
{

	return false;
}

String LinuxRegistry::getStringValue( const String& valuename )
{
	String result;
	return result;
}

uint32 LinuxRegistry::getIntValue( const String& valuename )
{
	return 0;
}

bool LinuxRegistry::getBoolValue( const String& valuename )
{
	bool result = false;	

	return result;
}

void LinuxRegistry::getDataBufValue( const String& valuename, uint32& dataBufferSize, void** dataBuffer )
{

}

Enumerator<String>* LinuxRegistry::getKeyNames()
{	
	
	keys_.clear();
	keysContainer_.initContainer( keys_ );
	
	return keysContainer_.getEnumerator();
}

Enumerator<RegistryValueInfo*>* LinuxRegistry::getValues()
{
	values_.clear();
	valuesContainer_.initContainer( values_ );

	return valuesContainer_.getEnumerator();
}

String LinuxRegistry::getCurrentKey()
{
	return currentRegKey_;
}


