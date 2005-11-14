//OSXRegistry.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


OSXRegistry::OSXRegistry()
{
	valuesContainer_.initContainer( values_ );
	keysContainer_.initContainer( keys_ );
}

OSXRegistry::~OSXRegistry()
{

}

void OSXRegistry::setRoot( const RegistryKeyType& rootKey )
{
	rootKeyType_ = rootKey;
}

RegistryKeyType OSXRegistry::getRoot()
{
	return rootKeyType_;
}

bool OSXRegistry::openKey( const String& keyname, const bool& createIfNonExistant )
{
	bool result = false;
	return result;
}

bool OSXRegistry::setValue( const String& value, const String& valuename )
{
	bool result = false;
	return result;
}

bool OSXRegistry::setValue( const uint32& value, const String& valuename )
{
	bool result = false;
	return result;
}

bool OSXRegistry::setValue( const bool& value, const String& valuename )
{
	bool result = false;
	return result;
}

bool OSXRegistry::OSXRegistry::setValue( void* dataBuffer, const uint32& dataBufferSize, const String& valuename )
{
	bool result = false;
	return result;
}

bool OSXRegistry::getStringValue( const String& valuename, String& value )
{
	bool result = false;
	return result;
}

bool OSXRegistry::getIntValue( const String& valuename, uint32& value )
{
	bool result = false;
	return result;
}

bool OSXRegistry::getBoolValue( const String& valuename, bool& value )
{
	bool result = false;
	return result;
}

bool OSXRegistry::getDataBufValue( const String& valuename, uint32& dataBufferSize, void** dataBuffer )
{
	bool result = false;
	return result;
}

Enumerator<String>* OSXRegistry::getKeyNames()
{
	return keysContainer_.getEnumerator();
}

Enumerator<RegistryValueInfo*>* OSXRegistry::getValues()
{
	return valuesContainer_.getEnumerator();
}

String OSXRegistry::getCurrentKey()
{
	return currentRegKey_;
}

/**
*CVS Log info
*$Log$
*Revision 1.2.6.1  2005/11/14 22:05:42  ddiego
*osx update.
*
*Revision 1.2  2004/08/07 02:49:14  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.6  2004/06/06 07:05:32  marcelloptr
*changed macros, text reformatting, copyright sections
*
*/


