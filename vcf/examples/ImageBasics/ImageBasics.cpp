//ImageBasics.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"



namespace VCF {

	class PixelException : public BasicException {
	public:

		PixelException( const String & message ): BasicException( message ){};

		virtual ~PixelException() throw() {};
	};

	template <typename PixelType>
	class Pixels {
	public:
		typedef _typename_ PixelType Type;

		Pixels( Image* img ):buffer_(NULL),currentImage_(NULL),width_(0),height_(0) {
			assign( img );
		}

		~Pixels() {
			unLockImageBuffer( currentImage_ );
		}

		Pixels& operator=( Image* img ) {
			assign( img );
			return *this;
		}


		operator Type* () {
			return (Type*)buffer_;
		}

		operator agg::rendering_buffer& () {
			return renderBuffer_;
		}

		Type& at( uint32 x, uint32 y ) {
			
			return ((Type*)buffer_)[(y*width_)+x];
		}

		Type at( uint32 x, uint32 y ) const {
			
			return ((Type*)buffer_)[(y*width_)+x];
		}


		Type* buffer() {
			return (Type*)buffer_;
		}

		uint32 width() {
			if ( width_ != currentImage_->getWidth() ) {
				throw PixelException( "You've modified an image's width, potentially while it's locked! Any pixel access may be bogus!" );
			}
			return currentImage_->getWidth();
		}

		uint32 height() {
			if ( height_ != currentImage_->getHeight() ) {
				throw PixelException( "You've modified an image's width, potentially while it's locked! Any pixel access may be bogus!" );
			}
			return currentImage_->getHeight();
		}
	protected:

		void assign( Image* img ) {

			if ( NULL != currentImage_ ) {
				unLockImageBuffer( currentImage_ );
			}

			if ( (Type::Traits::getTraitsImageType() != img->getType()) || 
					(Type::ChannelSize != img->getChannelSize()) ) {
				throw PixelException( "Incompatible pixel type for this image. The image channel size doesn't match the pixel's expected size." );
			}
			

			currentImage_ = img;

			lockImageBuffer( currentImage_ );
			
			width_ = currentImage_->getWidth();
			height_ = currentImage_->getHeight();

			buffer_ = currentImage_->getImageBits()->pixels_;

			renderBuffer_.attach( (unsigned char*)buffer_, width_, height_,
								width_ * (Type::Traits::getTraitsImageType()) );
		}

		void lockImageBuffer( Image* img ) {
			
		}

		void unLockImageBuffer( Image* img ) {
			if ( NULL != currentImage_ ) {

				width_ = 0;
				height_ = 0;
				renderBuffer_.attach( NULL, 0, 0, 0 );

				buffer_ = NULL;
				currentImage_ = NULL;
			}
		}

		void* buffer_;
		Image* currentImage_;
		uint32 width_;
		uint32 height_;
		agg::rendering_buffer renderBuffer_;
	private:
		Pixels();
		Pixels(const Pixels&);
		Pixels& operator=(const Pixels&);

	};



	typedef Pixels<SysPixelType> ColorPixels;
	typedef Pixels<SysGrayscalePixelType> GreyPixels;
};



using namespace VCF;

/**
This example will demonstrate some of the basics of
working with images
*/

class ImageBasicsWindow : public Window {
public:
	ImageBasicsWindow() {
		setCaption( "ImageBasics" );
		setVisible( true );
	}

	virtual ~ImageBasicsWindow(){};

	virtual void paint( GraphicsContext* ctx ) {
		Window::paint( ctx );


		


		/**
		This will create an image from a given file name
		*/
		Image* logoImage = GraphicsToolkit::createImage( "logo.bmp" );

		{
			ColorPixels pixels = logoImage;

			SysPixelType* p = pixels;

			SysPixelType p1 = pixels[1];
			

			try {
				GreyPixels pixels2 = logoImage;
			}
			catch ( BasicException& e ) {
				StringUtils::trace( "Error: " + e.getMessage() + "\n" );
			}

			pixels = logoImage;
		}


		/**
		Simplest way to draw an image
		*/

		double x = 20;
		double y = 20;

		ctx->drawImage( x, y, logoImage );

		y += logoImage->getHeight() + 20;

		/**
		Draw a portion of the image
		*/

		Rect r( 0, 0, logoImage->getWidth(), logoImage->getHeight() );
		r.offset( x, y );

		//original bounds
		ctx->setColor( Color::getColor("black") );
		ctx->rectangle( &r );
		ctx->strokePath();

		r.inflate( -10, -10 );

		ctx->drawImageWithinBounds( &r, logoImage );

		y += logoImage->getHeight() + 20;

		String imageInfo = Format( "Image width: %d, height: %d")
									 %logoImage->getWidth() % logoImage->getHeight();

		ctx->textAt( x, y, imageInfo );

		y += ctx->getTextHeight( imageInfo ) + 20;

		/**
		draw on the image
		*/
		/**
		first lock the image
		*/
		logoImage->beginDrawing();

		GraphicsContext* imgCtx = logoImage->getImageContext();

		/**
		draw a red rectangle on the image
		*/
		imgCtx->setColor( Color::getColor("red") );

		imgCtx->rectangle( 20, 20, 100, 75 );
		imgCtx->fillPath();

		/**
		unlock the image makes sure the image pixels are uptodate
		*/
		logoImage->finishedDrawing();

		/**
		draw the image again
		*/
		ctx->drawImage( x, y, logoImage );

		y += logoImage->getHeight() + 20;

		/**
		bitblt a portion of the image context to our current ctx
		*/
		logoImage->beginDrawing();
		imgCtx = logoImage->getImageContext();

		Rect src(0,0,100,50);
		Rect dest(10, y, 10 + src.getWidth(), y + src.getHeight() );

		ctx->copyContext( src, dest, imgCtx );

		logoImage->finishedDrawing();

		y += dest.getHeight() + 20;

		/**
		Now draw the image transparently. Note that this does not use any sort
		of alpha channel transparency
		*/

		logoImage->setIsTransparent( true );
		logoImage->setTransparencyColor( Color::getColor("red") );

		ctx->drawImage( x, y, logoImage );

		y += logoImage->getHeight() + 20;


		logoImage->setIsTransparent( false );
		/**
		Manipulate the pixel bits
		*/

		/**
		retrieve the image bits - you'll get a pointer to
		a SysPixelType
		*/
		{
			ColorPixels pix = logoImage;//->getImageBits()->pixels_;
			
										/**
										Calculate the size, width * height
			*/
			int size = logoImage->getHeight() * logoImage->getWidth();
			/**
			manipulate the values of the green color channel
			*/
			for ( int i=0;i<size;i++ ) {
				pix[i].g = minVal<>( 255, pix[i].g + 50 );
			}
			
			
			ctx->drawImage( x, y, logoImage );
		}

		/**
		delete the image cause we don't need it anymore
		*/
		delete logoImage;

	}
};




class ImageBasicsApplication : public Application {
public:

	ImageBasicsApplication( int argc, char** argv ) : Application(argc, argv) {

	}

	virtual bool initRunningApplication(){
		bool result = Application::initRunningApplication();

		Window* mainWindow = new ImageBasicsWindow();
		setMainWindow(mainWindow);
		mainWindow->setBounds( &Rect( 100.0, 100.0, 500.0, 500.0 ) );

		return result;
	}

};


int main(int argc, char *argv[])
{
	Application* app = new ImageBasicsApplication( argc, argv );

	Application::main();

	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.5.2.2  2005/09/14 18:55:15  ddiego
*update to win32window. initial code for new pixels
*type to replace imagebits class.
*
*Revision 1.5.2.1  2005/07/23 21:45:37  ddiego
*merged in marcellos changes from the 0-6-7 dev branch.
*
*Revision 1.4.4.2  2005/04/17 17:19:10  iamfraggle
*Small fixes
*
*Revision 1.4.4.1  2005/04/17 15:11:45  iamfraggle
*Replaced old-style var arg calls with new Format calls.
*
*Revision 1.4  2004/08/07 02:47:09  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.3.2.4  2004/04/29 03:40:54  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*/


