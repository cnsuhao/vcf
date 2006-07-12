#ifndef _VCF_NOTIMPLEMENTEDEXCEPTION_H__
#define _VCF_NOTIMPLEMENTEDEXCEPTION_H__
//NotImplementedException.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif

#include "vcf/FoundationKit/FrameworkConfig.h"
#include "vcf/FoundationKit/BasicException.h"
#include "vcf/FoundationKit/ErrorStrings.h"

namespace VCF {

class FOUNDATIONKIT_API NotImplementedException : public BasicException {
public:
	NotImplementedException():
		BasicException( NOT_IMPLEMENTED_EXCEPTION ){};

	NotImplementedException( const String & message ):
	  BasicException( message ){};

	NotImplementedException( const String & message, const int lineNumber ):
		BasicException(message, lineNumber){};

	virtual ~NotImplementedException() throw() {};
};

};


#endif // _VCF_NOTIMPLEMENTEDEXCEPTION_H__

/**
$Id$
*/
