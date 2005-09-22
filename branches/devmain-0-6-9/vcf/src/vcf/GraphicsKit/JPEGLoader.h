
#ifndef _VCF_JPEGLOADER_H__
#define _VCF_JPEGLOADER_H__

namespace VCF {

class GRAPHICSKIT_API JPEGLoader : public Object, public ImageLoader {
public:
	JPEGLoader();

	virtual ~JPEGLoader();

	virtual Image* loadImageFromFile( const String& fileName );

	virtual void saveImageToFile( const String& fileName, Image* image );

	virtual bool canSaveImage(){
		return true;
	}

};

};

#endif //_VCF_JPEGLOADER_H__

