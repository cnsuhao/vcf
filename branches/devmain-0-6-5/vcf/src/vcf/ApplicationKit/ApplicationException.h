#ifndef _VCF_APPLICATIONEXCEPTION_H__
#define _VCF_APPLICATIONEXCEPTION_H__
//ApplicationException.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF
{


/**
*Application level exceptions
*
*@version 1.0
*@author Jim Crafton
*/
class APPKIT_API ApplicationException : public BasicException {
public:
	ApplicationException( const VCF::String & message ):
		BasicException( message ){};

	ApplicationException():
		BasicException( APPLICATION_EXCEPTION ){};

	ApplicationException( const VCF::String & message, const int lineNumber ):
		VCF::BasicException(message, lineNumber){};


};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


#endif // _VCF_APPLICATIONEXCEPTION_H__


