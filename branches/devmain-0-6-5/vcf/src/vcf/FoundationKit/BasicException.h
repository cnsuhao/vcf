#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_BASICEXCEPTION_H__
#define _VCF_BASICEXCEPTION_H__

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


namespace VCF{

/**
*The base exception class in the Framework. 
*All exceptions should try and describe what went wrong as clearly as possible.
*For convenience a basic set of error strings are defined in ErrorStrings.h.
*
*@version 1.0
*@author Jim Crafton
*/
class FRAMEWORK_API BasicException : public std::exception {
public:

	/**
	*Basic constructor
	*All Exceptions take a text message identifying (in human readable terms ) what
	*went wrong. 
	*/
	BasicException( const VCF::String & message );
	
	BasicException( const VCF::String & message, const int lineNumber );

	virtual ~BasicException() throw() {} ;

	/**
	*returns the message text associated with the exception
	*@return String - the error text
	*/
    VCF::String getMessage();  


	/**
	overrides the std::exception's what() method to return the same as 
	getMessage() does, making this exception (and all it's derivations)
	suitable for use in try/catch blocks where the catch traps std::exception&.
	*/
	virtual const char* what() const throw() {
		return message_.ansi_c_str();
	}

	/**
	*set the error text to be associated with the exception
	* so it is possible to add informations and rethrow the same exception
	*/
	void setMessage( const VCF::String& message );

private:
    VCF::String message_;
};

};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.10.2.2  2004/04/26 21:58:37  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.10.2.1  2004/04/21 02:17:07  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.10  2004/04/03 15:48:40  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.9  2004/01/20 01:54:55  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.8.2.1  2004/01/17 06:09:49  ddiego
*integrated the DateTime class into the VCF FoundationKit.
*
*Revision 1.8.2.3  2004/03/21 00:39:22  ddiego
*merged vc7.1 changes into dev branch
*
*Revision 1.8.2.2  2004/01/25 22:37:35  marcelloptr
*changes related to rethrowing exceptions
*
*Revision 1.8.2.1  2004/01/17 06:09:49  ddiego
*integrated the DateTime class into the VCF FoundationKit.
*
*Revision 1.8  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*/


#endif // _VCF_BASICEXCEPTION_H__


