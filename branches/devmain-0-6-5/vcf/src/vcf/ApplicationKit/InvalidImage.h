// InvalidImage.h

#ifndef _VCF_INVALIDIMAGE_H__
#define _VCF_INVALIDIMAGE_H__



namespace VCF
{

class GRAPHICSKIT_API InvalidImage : public BasicException  
{
public:

	InvalidImage(const VCF::String & message):
	  VCF::BasicException( message ){};

	InvalidImage():
		VCF::BasicException( INVALID_IMAGE ){};

	InvalidImage( const VCF::String & message, const int lineNumber ):
		VCF::BasicException(message, lineNumber){};



};

};

#endif // _VCF_INVALIDIMAGE_H__
 


