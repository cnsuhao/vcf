//

//InvalidImplementer.h

#ifndef _VCF_INVALIDIMPLEMENTER_H__
#define _VCF_INVALIDIMPLEMENTER_H__

#include "vcf/FoundationKit/BasicException.h"

namespace VCF
{

class InvalidImplementer : public BasicException{
public:

	InvalidImplementer( const VCF::String & message ):
	  VCF::BasicException( message ){};

	InvalidImplementer():
		VCF::BasicException( NO_IMPLEMENTER ){};

	InvalidImplementer( const VCF::String & message, const int lineNumber ):
		VCF::BasicException(message, lineNumber){};

	virtual ~InvalidImplementer() throw() {};
};


};


#endif // _VCF_INVALIDIMPLEMENTER_H__


