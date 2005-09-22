//PNGLoader.cpp

#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"
#include "vcf/GraphicsKit/PNGLoader.h"


// ----------------------------------------------------------

#define PNG_ASSEMBLER_CODE_SUPPORTED
#define PNG_BYTES_TO_CHECK 8

// ----------------------------------------------------------

#include "thirdparty/common/LibPNG/png.h"


static VCF::InputStream* pngInStream = NULL;
static VCF::OutputStream* pngOutStream = NULL;


static void
error_handler(struct png_struct_def *, const char *error) {
	throw VCF::RuntimeException( MAKE_ERROR_MSG_2(VCF::String(error)) );
}

// warnings disabled for now

static void
warning_handler(struct png_struct_def *, const char *warning) {
}


static void
pngLoader_ReadProc(struct png_struct_def *, unsigned char *data, unsigned int size) {
	pngInStream->read( data, size );
}

static void
pngLoader_writeProc(struct png_struct_def *, unsigned char *data, unsigned int size) {
	pngOutStream->write( data, size );
}

static void
pngLoader_FlushProc(png_structp png_ptr) {
	// empty flush implementation
}

using namespace VCF;

PNGLoader::PNGLoader()
{

}

PNGLoader::~PNGLoader()
{

}

Image* PNGLoader::loadImageFromFile( const String& fileName )
{
	Image* result = NULL;

	png_structp png_ptr;
	png_infop info_ptr;
	png_uint_32 width, height;
	png_colorp png_palette;
	int bpp, color_type, palette_entries;
	
	png_bytepp  row_pointers = NULL;
	int i;

	FileInputStream fis(fileName);

	
	unsigned char png_check[PNG_BYTES_TO_CHECK];

	fis.read( png_check, PNG_BYTES_TO_CHECK );

	if ( png_sig_cmp(png_check, (png_size_t)0, PNG_BYTES_TO_CHECK) != 0) {
		return result;
	}
		
	//valid PNG file

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, (png_voidp)error_handler, error_handler, warning_handler);

	if (NULL == png_ptr ) {
		return result;
	}

	// create the info structure
	info_ptr = png_create_info_struct(png_ptr);

	if ( NULL == info_ptr) {
		png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);				
		return result;
	}

	// init the IO
	
	png_set_read_fn(png_ptr, info_ptr, pngLoader_ReadProc);
	
	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		return result;
	}

	// Because we have already read the signature...
	
	png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK);
	
	// read the IHDR chunk
	
	png_read_info(png_ptr, info_ptr);
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bpp, &color_type, NULL, NULL, NULL);
	
	// DIB's don't support >8 bits per sample
	// => tell libpng to strip 16 bit/color files down to 8 bits/color
	
	if (bpp == 16) {
		png_set_strip_16(png_ptr);
		bpp = 8;
	}
	
	// Set some additional flags

	switch(color_type) {
		case PNG_COLOR_TYPE_RGB:
		case PNG_COLOR_TYPE_RGB_ALPHA:
			// Flip the RGB pixels to BGR (or RGBA to BGRA)

			png_set_bgr(png_ptr);
			break;

		case PNG_COLOR_TYPE_PALETTE:
			// Expand palette images to the full 8 bits from 2 or 4 bits/pixel

			if ((bpp == 2) || (bpp == 4)) {
				png_set_packing(png_ptr);
				bpp = 8;
			}					

			break;

		case PNG_COLOR_TYPE_GRAY:
		case PNG_COLOR_TYPE_GRAY_ALPHA:
			// Expand grayscale images to the full 8 bits from 2 or 4 bits/pixel

			if ((bpp == 2) || (bpp == 4)) {
				png_set_expand(png_ptr);
				bpp = 8;
			}

			break;

		default:
			throw RuntimeException( MAKE_ERROR_MSG_2("PNG format not supported"));
	}
	return result;
}

void PNGLoader::saveImageToFile( const String& fileName, Image* image )
{

	
}