#if     _MSC_VER > 1000
#pragma once
#endif


//LibraryApplication.h

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

#ifndef _VCF_LIBRARYAPPLICATION_H__
#define _VCF_LIBRARYAPPLICATION_H__



namespace VCF  {

/**
*Class LibraryApplication documentation
*/
class APPKIT_API LibraryApplication : public AbstractApplication { 
public:
	LibraryApplication();

	virtual ~LibraryApplication();

	virtual bool initRunningApplication(){
		return true;
	}

	virtual void terminateRunningApplication(){};

	virtual void setName( const String& name );

	/**
	*gets a collection of named libraries that have been registered
	*/
	static Enumerator<LibraryApplication*>* getRegisteredLibraries();

	static void registerLibrary( LibraryApplication* libraryApp );	

	static void unRegisterLibrary( LibraryApplication* libraryApp );	

	static LibraryApplication* getRegisteredLibraryApplication( const String& libName );

	static void load( LibraryApplication* libraryApp );

	static void unload( LibraryApplication* libraryApp );

	static void initLibraryRegistrar();

	static void clearLibraryRegistrar();
protected:	
	
private:
	static std::map<String,LibraryApplication*>* namedLibraryAppMap;	
	static EnumeratorMapContainer<std::map<String,LibraryApplication*>, LibraryApplication*>* namedLibAppContainer;
};


}; //end of namespace VCF

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:18  ddiego
*migration towards new directory structure
*
*Revision 1.6.4.1  2004/04/26 21:58:20  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.6  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.5.26.2  2003/09/21 04:15:34  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.5.26.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.5  2002/03/01 05:11:24  ddiego
*added some methods for saving an applications state and doing so
*automatically if the developer wants
*
*Revision 1.4  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_LIBRARYAPPLICATION_H__


