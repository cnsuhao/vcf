#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_DIRECTORY_H__
#define _VCF_DIRECTORY_H__


//Directory.h

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



namespace VCF  {

/**
*A Directory represents a directory in a file system.
*Directories have all the features of a File, and in addition
*they may be searched for files based on a search filter.
*/
class FRAMEWORK_API Directory : public File { 
public:
	/**
	*A Finder object is used to iterate a 
	*set of files contained in a Directory object
	*that represents the directory.
	*Only Directory objects may create a Finder object.
	*A Finder is used just like an Enumerator, allowing 
	*the user to enumerate through the file names of the 
	*search. The only difference is that the very last element 
	*will be an empty string, so callers should test for this 
	*when retrieving the value from the nextElement() method.
	*/
	class FRAMEWORK_API Finder : public Object, public Enumerator<String>{
	public:

		virtual ~Finder();

		/*
		*Are there any more elements in this Finder ?
		*@param bool backward is ignored and makes no difference
		*in the enumeration order
		*/
		virtual bool hasMoreElements(const bool& backward=false);

		/**
		*gets the next file name in the search.
		*Test for an empty string, as the last element in the 
		*search will be empty.
		*/
		virtual String nextElement();

		/**
		*same as nextElement()
		*/
		virtual String prevElement();

		/**
		*resets the search. The backward parameter is 
		*ignored
		*@param bool backward ignored
		*/
		virtual void reset(const bool& backward=false);			
		
		/**
		*returns the Directory object that created
		*this Finder.
		*@return Directory the owning directory for this finder.
		*/
		Directory* getOwningDirectory() {
			return owningDirectory_;
		}
		
		/**
		*returns the search filter used by this 
		*Finder. See Directory::findFiles() for 
		*more information about how the 
		*search filter is constructed
		*@return String the search filter used by this Finder
		*/
		String getSearchFilter() {
			return searchFilter_;
		}
		
		friend class Directory;		

	protected:
		Finder( Directory* directoryToSearch, const String& filter );

		Directory* owningDirectory_;
		String searchFilter_;
		bool searchHasElements_;
		String currentElement_;
	};

	/**
	*Directory takes a file name for the constructor
	*argument, with by default is empty. Unlike a 
	*File, passing a name with out an ending "\" will
	*still work, as the "\" will be automatically added 
	*for you.
	*/
	Directory( const String& fileName = "" );

	virtual ~Directory();

	/**
	*performs a search of files under this Directory object.
	*@param String a filter that represents one or more wildcards. Each wild
	*card expression (*foo, or *.txt, etc) should be separated by a ";" 
	*character.
	*@return Finder 
	*/
	Finder* findFiles( const String& filter );
protected:

private:
};


}; //end of namespace VCF

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.4.4.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.3.4.2  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.3.4.1  2003/08/25 03:46:38  ddiego
*some fixes to some of the stream impls
*
*Revision 1.3  2003/05/17 20:37:14  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.22.1  2003/03/12 03:11:43  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_DIRECTORY_H__


