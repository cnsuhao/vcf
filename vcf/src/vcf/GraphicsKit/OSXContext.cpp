//OSXContext.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/GraphicsKit/GraphicsKitPrivate.h"
#include "vcf/FoundationKit/VCFMath.h"
#include "vcf/GraphicsKit/DrawUIState.h"


using namespace VCF;
/*
class SwitchPort {
public:
    SwitchPort( GrafPtr ptr ) :current(ptr){
        GetPort( &old );
        if ( old != current ) {
            //make switch
            SetPort( current ) ;
        }
    }

    ~SwitchPort() {
        if ( old != current ) {
            //make switch
            SetPort( old ) ;
        }
    }
private:
    GrafPtr current;
    GrafPtr old;
    SwitchPort( const SwitchPort& rhs );
    SwitchPort& operator=(const SwitchPort& rhs );
};
*/



OSXContext::OSXContext():
	contextID_(nil),
    grafPort_(0),
	inMemoryImage_(nil),
    imgWidth_(0),
    imgHeight_(0),
	context_(NULL),
	currentDrawingOperation_(0),
	textLayout_(nil),
    xorModeOn_(false)
{
	init();
}

OSXContext::OSXContext( const unsigned long& width, const unsigned long& height ):
	contextID_(nil),
    grafPort_(0),
	inMemoryImage_(nil),
    imgWidth_(width),
    imgHeight_(height),
	context_(NULL),
	currentDrawingOperation_(0),
	textLayout_(nil),
    xorModeOn_(false)
{
	//allocate a RGBA buffer for use
    inMemoryImage_ = new unsigned char[imgWidth_ * imgHeight_ * 4];
	init();
}

OSXContext::OSXContext( const unsigned long& contextID ):
	contextID_(0),
    grafPort_((GrafPtr)contextID),
	inMemoryImage_(nil),
    imgWidth_(0),
    imgHeight_(0),
	context_(NULL),
	currentDrawingOperation_(0),
	textLayout_(nil),
    xorModeOn_(false)
{
	init();
}

OSXContext::~OSXContext()
{

	if ( nil != textLayout_ ) {
		ATSUDisposeTextLayout( textLayout_ );
	}

    CGContextRelease( contextID_);

    if ( NULL != inMemoryImage_ ) {
        delete [] inMemoryImage_;
        inMemoryImage_ = NULL;
        DisposeGWorld( grafPort_ );
    }


	contextID_ = nil;
}

void OSXContext::setContext( GraphicsContext* context )
{
	context_ = context;
}

GraphicsContext* OSXContext::getContext()
{
	return context_;
}

unsigned long OSXContext::getContextID()
{
	return (unsigned long)grafPort_;
}

void OSXContext::setContextID( const unsigned long& handle )
{
    if ( NULL != inMemoryImage_ ) {
        delete [] inMemoryImage_;
        inMemoryImage_ = 0;
        imgWidth_ = 0;
        imgHeight_ = 0;
        DisposeGWorld( grafPort_ );
    }

	if ( NULL != grafPort_ ) {
		CGContextRelease( contextID_);
		contextID_ = NULL;
    }

	grafPort_ = (GrafPtr)handle;
    init();
}

void OSXContext::setCGContext( CGContextRef cgRef, GrafPtr port, const Rect& ownerRect  )
{
	if ( NULL != inMemoryImage_ ) {
        delete [] inMemoryImage_;
        inMemoryImage_ = 0;
        imgWidth_ = 0;
        imgHeight_ = 0;
        DisposeGWorld( grafPort_ );
    }



	ownerRect_ = ownerRect;
	contextID_ = cgRef;
	grafPort_ = NULL;

	if ( NULL != inMemoryImage_ ) {
        //allocate a new gworld
        GWorldPtr newGworld = 0;

        int bitsPerPix = 32;
        int componentCount = 4;
        int bytesPerRow = (imgWidth_ * (bitsPerPix/componentCount) * componentCount) / 8;
        ::Rect imgRect;
        imgRect.left = 0;
        imgRect.top = 0;
        imgRect.right = imgWidth_;
        imgRect.bottom = imgHeight_;

        OSStatus err = 0;
        err = NewGWorldFromPtr( &newGworld,
                            k32RGBAPixelFormat,
                            &imgRect,
                            NULL,
                            NULL,
                            0,
                            (char*)inMemoryImage_,
                            bytesPerRow );
        if ( noErr == err ) {
            grafPort_ = newGworld;
//            printf( "NewGWorldFromPtr() succeeded, grafPort_: %p\n", grafPort_ );
        }
        else {
            throw RuntimeException( MAKE_ERROR_MSG_2("NewGWorldFromPtr() failed to allocate GWorld") );
        }
    }

	grafPort_ = port;


	if ( nil == textLayout_ ) {
		ATSUCreateTextLayout( &textLayout_ );
	}

	if ( NULL != contextID_ ) {
		ATSUAttributeTag        cgTags[] = {kATSUCGContextTag};
		ByteCount               cgSize[] = {sizeof (contextID_)};
		ATSUAttributeValuePtr   cgValue[] = {&contextID_};

		OSStatus err = ATSUSetLayoutControls (textLayout_,
											  1,
											  cgTags,
											  cgSize,
											  cgValue);
		if ( err != noErr ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("ATSUSetLayoutControls failed.") );
		}
	}
}

void OSXContext::init()
{
    if ( NULL != inMemoryImage_ ) {
        //allocate a new gworld
        GWorldPtr newGworld = 0;

        int bitsPerPix = 32;
        int componentCount = 4;
        int bytesPerRow = (imgWidth_ * (bitsPerPix/componentCount) * componentCount) / 8;
        ::Rect imgRect;
        imgRect.left = 0;
        imgRect.top = 0;
        imgRect.right = imgWidth_;
        imgRect.bottom = imgHeight_;

        OSStatus err = 0;
        err = NewGWorldFromPtr( &newGworld,
                            k32RGBAPixelFormat,
                            &imgRect,
                            NULL,
                            NULL,
                            0,
                            (char*)inMemoryImage_,
                            bytesPerRow );
        if ( noErr == err ) {
            grafPort_ = newGworld;
//            printf( "NewGWorldFromPtr() succeeded, grafPort_: %p\n", grafPort_ );
        }
        else {
            throw RuntimeException( MAKE_ERROR_MSG_2("NewGWorldFromPtr() failed to allocate GWorld") );
        }
    }

    if ( NULL != grafPort_ ) {
        CreateCGContextForPort( grafPort_, &contextID_);

		//CGContextSaveGState( contextID_ );
		::Rect portBounds;
        GetPortBounds( grafPort_, &portBounds );


        CGContextTranslateCTM(contextID_, 0,
                                        (float)(portBounds.bottom - portBounds.top));
        CGContextScaleCTM(contextID_, 1, -1);

		if( nil == textLayout_ ) { //only do this once
			ATSUCreateTextLayout( &textLayout_ );
		}

		ATSUAttributeTag        cgTags[] = {kATSUCGContextTag};
		ByteCount               cgSize[] = {sizeof (contextID_)};
		ATSUAttributeValuePtr   cgValue[] = {&contextID_};

		OSStatus err = ATSUSetLayoutControls (textLayout_,
											  1,
											  cgTags,
											  cgSize,
											  cgValue);
		if ( err != noErr ) {
			throw RuntimeException( MAKE_ERROR_MSG_2("ATSUSetLayoutControls failed.") );
		}
	}


}

void OSXContext::textAt( const VCF::Rect& bounds, const String & text, const long& drawOptions )
{
    VCF::Rect offsetBounds = bounds;
    offsetBounds.offset( origin_ );


	//tdoWordWrap=1,
	//tdoLeftAlign=2,
	//tdoCenterHorzAlign=4,
	//tdoRightAlign=8,
	//tdoBottomAlign=16,
	//tdoCenterVertAlign=32,
	//tdoTopAlign=64


	ATSUSetTextPointerLocation( textLayout_,
								text.c_str(),
								kATSUFromTextBeginning,
								kATSUToTextEnd,
								text.length() );

	//CFTextString cfStr;
	//cfStr = text;

    Font* ctxFont = context_->getCurrentFont();
	FontPeer* fontImpl = ctxFont->getFontPeer();
	ATSUStyle fontStyle = (ATSUStyle)fontImpl->getFontHandleID();
	ATSUSetRunStyle( textLayout_, fontStyle, 0, text.length() );

	//::Rect r = RectProxy( bounds );
	//DrawThemeTextBox( cfStr, kThemeCurrentPortFont, kThemeStateActive, false, &r, 0, contextID_ );


	if ( GraphicsContext::tdoWordWrap & drawOptions ) {
		//do word wrap
		VCF::Rect r = offsetBounds;

		atsuDrawTextInBox( r );
	}
	else {
		setLayoutWidth( textLayout_, 0 );
		FixedPointNumber x =  offsetBounds.left_;// + portBounds.left;
		FixedPointNumber y = ((offsetBounds.top_ + getTextHeight("EM"))*-1.0);

		ATSUDrawText( textLayout_,
							kATSUFromTextBeginning,
							kATSUToTextEnd,
							x,  y );

	}

}

void OSXContext::setLayoutWidth( ATSUTextLayout layout, double width )
{
	FixedPointNumber fwidth = width;
	ATSUTextMeasurement textWidth = fwidth;
	ATSUAttributeTag tag = kATSULineWidthTag;
	ByteCount count = sizeof(ATSUTextMeasurement);
	ATSUAttributeValuePtr ptr = &textWidth;
	ATSUSetLayoutControls( layout, 1, &tag, &count, &ptr );

}

VCF::Size OSXContext::getLayoutDimensions( const String& text )
{
	int length = text.length();

	if ( NULL == textLayout_ ) {
		return Size();
	}
	
	ATSUTextLayout tmpTextLayout = NULL;
	OSStatus err = ATSUCreateAndCopyTextLayout( textLayout_, &tmpTextLayout );
	if ( err != noErr ) {
		String msg = StringUtils::format( "ATSUCreateAndCopyTextLayout failed, err: %d, textLayout_: %p, tmpTextLayout: %p", err, textLayout_, tmpTextLayout );
		throw RuntimeException( MAKE_ERROR_MSG_2(msg) );
	}	
	
	ATSUSetTextPointerLocation( tmpTextLayout, text.c_str(), 
                                kATSUFromTextBeginning, 
								kATSUToTextEnd, 
								length );												
	
	setLayoutWidth( tmpTextLayout, 0 );
		
	Font* ctxFont = context_->getCurrentFont();
	FontPeer* fontImpl = ctxFont->getFontPeer();
	ATSUStyle fontStyle = (ATSUStyle)fontImpl->getFontHandleID();
	
											
	ATSUSetRunStyle( tmpTextLayout, fontStyle, 0, length );
	
	
	ItemCount actualBoundsReturned  = 1;
	ATSTrapezoid bounds;
																
	ATSUGetGlyphBounds( tmpTextLayout, 0, 0, 0, length, kATSUseDeviceOrigins, 1, &bounds, &actualBoundsReturned );
					
	
	VCF::Size result;
	FixedPointNumber w = (Fixed)abs(bounds.upperLeft.x - bounds.upperRight.x);

	result.width_ = w.asDouble();

	FixedPointNumber h = (Fixed)(-bounds.upperLeft.y) + bounds.lowerLeft.y;
	result.height_ = h.asDouble();
	
	ATSUDisposeTextLayout( tmpTextLayout );
	
	return  result;
}

double OSXContext::getTextWidth( const String& text )
{
	return getLayoutDimensions(text).width_;
}

double OSXContext::getTextHeight( const String& text )
{
	return getLayoutDimensions(text).height_;
}

void OSXContext::rectangle(const double & x1, const double & y1, const double & x2, const double & y2)
{
	CGRect rect;
	rect.origin.x = x1 + origin_.x_;
	rect.origin.y = y1 + origin_.y_;

	rect.size.width = x2 - x1;
	rect.size.height = y2 - y1;
	//CGContextBeginPath( contextID_ );
	CGContextAddRect( contextID_, rect );
	//CGContextClosePath( contextID_ );
	if ( GraphicsContext::doStroke == currentDrawingOperation_ ) {
		//CGContextStrokePath ( contextID_ );
	}
	else if ( GraphicsContext::doFill == currentDrawingOperation_ ) {
		//CGContextFillPath ( contextID_ );
	}
}

void OSXContext::roundRect(const double & x1, const double & y1, const double & x2, const double & y2,
							 const double & xc, const double & yc)
{

}


void OSXContext::ellipse(const double & x1, const double & y1, const double & x2, const double & y2 )
{
	float a, b;
    CGPoint center;

    center.x = x1 + (x2-x1)/2.0;
	center.y = y1 + (y2-y1)/2.0;

    a = (x2-x1)/2.0;
    b = (y2-y1)/2.0;
    CGContextBeginPath ( contextID_ );
	CGContextSaveGState(contextID_);
    CGContextTranslateCTM(contextID_, center.x, center.y);
    CGContextScaleCTM(contextID_, a, b);
    CGContextMoveToPoint(contextID_, 1, 0);
    CGContextAddArc(contextID_, 0, 0, 1, Math::degreesToRadians(0), Math::degreesToRadians(360), 0);
    CGContextClosePath(contextID_);
    CGContextRestoreGState(contextID_);

	if ( GraphicsContext::doStroke == currentDrawingOperation_ ) {
		CGContextStrokePath(contextID_);
	}
	else if ( GraphicsContext::doFill == currentDrawingOperation_ ) {
		CGContextFillPath ( contextID_ );
	}
}

void OSXContext::arc(const double & x1, const double & y1, const double & x2, const double & y2, const double & x3,
						 const double & y3, const double & x4, const double & y4)
{
	//CGContextAddArc
}


void OSXContext::polyline(const std::vector<Point>& pts )
{

	std::vector<Point>::const_iterator it = pts.begin();
	CGPoint* cgPts = new CGPoint[pts.size()];
	int i = 0;
	while ( it != pts.end() ) {
		const Point& pt = *it;
		cgPts[i].x = pt.x_ + origin_.x_;
		cgPts[i].y = pt.y_ + origin_.y_;
		it ++;
	}

	CGContextAddLines( contextID_, cgPts, pts.size() );

	if ( GraphicsContext::doStroke == currentDrawingOperation_ ) {
		//CGContextStrokePath ( contextID_ );
	}
	else if ( GraphicsContext::doFill == currentDrawingOperation_ ) {
		//CGContextFillPath ( contextID_ );
	}

	delete [] cgPts;
}

void OSXContext::curve(const double & x1, const double & y1, const double & x2, const double & y2,
                         const double & x3, const double & y3, const double & x4, const double & y4)
{
	//CGContextBeginPath( contextID_ );

	CGContextMoveToPoint( contextID_, x1 + origin_.x_, y1 + origin_.y_ );
	CGContextAddCurveToPoint( contextID_, x2 + origin_.x_, y2 + origin_.y_,
                                x3 + origin_.x_, y3 + origin_.y_,
                                x4 + origin_.x_, y4 + origin_.y_ );

	//CGContextClosePath( contextID_ );
	if ( GraphicsContext::doStroke == currentDrawingOperation_ ) {
		//CGContextStrokePath ( contextID_ );
	}
	else if ( GraphicsContext::doFill == currentDrawingOperation_ ) {
		//CGContextFillPath ( contextID_ );
	}
}

void OSXContext::lineTo(const double & x, const double & y)
{
	CGContextAddLineToPoint( contextID_, x + origin_.x_, y + origin_.y_ );
	//CGContextStrokePath ( contextID_ );
}

void OSXContext::moveTo(const double & x, const double & y)
{

	CGContextMoveToPoint( contextID_, x + origin_.x_, y + origin_.y_ );
}


void OSXContext::setOrigin( const double& x, const double& y )
{
    origin_.x_ = x;
    origin_.y_ = y;
}

VCF::Point OSXContext::getOrigin()
{
	return origin_;
}

void OSXContext::copyContext( const Rect& sourceRect,
								const Rect& destRect,
								ContextPeer* sourceContext )
{
    ::Rect srcRect;
    srcRect.left = (int)sourceRect.left_;
    srcRect.right = (int)sourceRect.right_;
    srcRect.top = (int)sourceRect.top_;
    srcRect.bottom = (int)sourceRect.bottom_;

    ::Rect dstRect;
    dstRect.left = (int)(destRect.left_ + origin_.x_);
    dstRect.right = (int)(destRect.right_  + origin_.x_);
    dstRect.top = (int)(destRect.top_ + origin_.y_);
    dstRect.bottom = (int)(destRect.bottom_ + origin_.y_);



    GrafPtr srcPort = (GrafPtr)sourceContext->getContextID();
    GrafPtr destPort = grafPort_;

	CopyBits( GetPortBitMapForCopyBits (srcPort),
                    GetPortBitMapForCopyBits (destPort),
                    &srcRect,
                    &dstRect,
                    srcCopy, 0 );
}

bool OSXContext::isMemoryContext()
{
	return (NULL != inMemoryImage_) ? true : false;
}

bool OSXContext::prepareForDrawing( long drawingOperation )
{
	currentDrawingOperation_ = drawingOperation;

    checkHandle();

	Color* currentColor = context_->getColor();
	GrafPtr oldPort;
    GetPort( &oldPort );
    if ( oldPort != grafPort_ ) {
        //SetPort( grafPort_ );
    }

	if ( xorModeOn_ ) {
        PenMode( srcXor );
    }
    else {
        PenMode( srcCopy );
    }

    if ( oldPort != grafPort_ ) {
        //SetPort( oldPort );
    }

	float colorComponents[4] =
			{currentColor->getRed(),
			currentColor->getGreen(),
			currentColor->getBlue(), 1.0};

	switch ( drawingOperation ) {
		case GraphicsContext::doStroke : {
			CGContextSetLineWidth( contextID_, context_->getStrokeWidth() );
			CGContextSetRGBStrokeColor( contextID_, colorComponents[0], colorComponents[1],
										colorComponents[2], colorComponents[3] );
			CGContextBeginPath ( contextID_ );
		}
		break;

		case GraphicsContext::doFill : {
			CGContextSetRGBFillColor( contextID_, colorComponents[0], colorComponents[1],
										colorComponents[2], colorComponents[3] );
			CGContextBeginPath ( contextID_ );
		}
		break;

		case GraphicsContext::doText : {
			//save state
			CGContextSaveGState( contextID_ );

			//change the scaling back to normal otherwise we will have vertically
			//flipped glyphs - and no one wants that!!
			CGAffineTransform xfrm = CGAffineTransformMakeScale( 1, -1 );
			CGContextConcatCTM( contextID_, xfrm );

			//xfrm = CGAffineTransformMakeTranslation( 0, -(ownerRect_.top_) );
			//CGContextConcatCTM( contextID_, xfrm );

            Font* ctxFont = context_->getCurrentFont();
            OSXFont* fontImpl = (OSXFont*)ctxFont->getFontPeer();
            Color* fontColor = ctxFont->getColor();
            fontImpl->setColor( fontColor );

			colorComponents[0] = fontColor->getRed();
			colorComponents[1] = fontColor->getGreen();
			colorComponents[2] = fontColor->getBlue();

            CGContextSetRGBFillColor( contextID_, colorComponents[0], colorComponents[1],
										colorComponents[2], colorComponents[3] );
			CGContextSetRGBStrokeColor( contextID_, colorComponents[0], colorComponents[1],
										colorComponents[2], colorComponents[3] );
		}
		break;

		case GraphicsContext::doImage : {

		}
		break;
	}

	return true;
}

void OSXContext::finishedDrawing( long drawingOperation )
{
	switch ( drawingOperation ) {
		case GraphicsContext::doStroke : {
			//CGContextClosePath( contextID_ );
			CGContextStrokePath ( contextID_ );
		}
		break;

		case GraphicsContext::doFill : {
			//CGContextClosePath( contextID_ );
			CGContextFillPath ( contextID_ );
		}
		break;

		case GraphicsContext::doText : {
			CGContextRestoreGState( contextID_ );
		}
		break;

		case GraphicsContext::doImage : {
		}
		break;
	}

	currentDrawingOperation_ = -1;

	releaseHandle();


}

void OSXContext::drawImage( const double& x, const double& y, Rect* imageBounds, Image* image )
{
    if ( (imageBounds->getWidth() > image->getWidth()) || (imageBounds->getHeight() > image->getHeight()) ) {
		throw BasicException( MAKE_ERROR_MSG("Invalid image bounds requested"), __LINE__);
	}

    OSXImage* osXimage = (OSXImage*)(image);
    ulong32 imgBoundsWidth = imageBounds->getWidth();
    ulong32 imgBoundsHeight = imageBounds->getHeight();

    if ( (imgBoundsWidth == image->getWidth()) && (imgBoundsHeight == image->getHeight()) ) {
        CGImageRef imgRef = osXimage->getCGImage();
        CGRect imgBounds;
        imgBounds.origin.x = x;
        imgBounds.origin.y = y;
        imgBounds.size.width = imgBoundsWidth;
        imgBounds.size.height = imgBoundsHeight;

        CGContextDrawImage( contextID_, imgBounds, imgRef );
    }
    else {
        //create a smaller portion of the image
        int componentCount = image->getType();
        int bitsPerPix = image->getChannelSize() * componentCount;
        int bitsPerComponent = image->getChannelSize();
        int rowStride = ((imgBoundsWidth * bitsPerComponent * componentCount)  + 7)/ 8;

        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        SysPixelType* data = new SysPixelType[imgBoundsWidth*imgBoundsHeight];

        ulong32 imgSize = imgBoundsWidth * imgBoundsHeight * componentCount;
        CGDataProviderRef provider = CGDataProviderCreateWithData( NULL,
                                                                    (char*)data,
                                                                    imgSize,
                                                                    NULL );


        CGImageRef imgRef = CGImageCreate( imgBoundsWidth,
                                   imgBoundsHeight,
                                   image->getChannelSize(),
                                   bitsPerPix,
                                   rowStride,
                                   colorSpace,
                                   kCGImageAlphaNone,
                                   provider,
                                   NULL,
                                   FALSE,
                                   kCGRenderingIntentDefault );

        //copy over bits
        SysPixelType* imageBuf = image->getImageBits()->pixels_;
        SysPixelType* tmpBmpBuf = data;

        ulong32 incr = (ulong32)((imageBounds->top_ * image->getWidth()) + imageBounds->left_);
        imageBuf += incr;
        ulong32 imgWidth = image->getWidth();

        int s = (int)imageBounds->top_;
        int e = (int)imageBounds->bottom_;
        for (int y1=s;y1<e;y1++) {

            memcpy( tmpBmpBuf, imageBuf, imgBoundsWidth*componentCount );

            tmpBmpBuf += imgBoundsWidth;
            imageBuf += imgWidth;
        }

        CGRect imgBounds;
        imgBounds.origin.x = x;
        imgBounds.origin.y = y;
        imgBounds.size.width = imgBoundsWidth;
        imgBounds.size.height = imgBoundsHeight;

        CGContextDrawImage( contextID_, imgBounds, imgRef );

        CGColorSpaceRelease(colorSpace);
        CGDataProviderRelease(provider);
        CGImageRelease( imgRef );
        delete [] data;
    }

}

void OSXContext::checkHandle()
{

}

void OSXContext::releaseHandle()
{

}

bool OSXContext::isXORModeOn()
{
    return xorModeOn_;
}

void OSXContext::setXORModeOn( const bool& XORModeOn )
{
    xorModeOn_ = XORModeOn;
}

void OSXContext::setTextAlignment( const bool& alignTobaseline )
{

}

bool OSXContext::isTextAlignedToBaseline()
{
	return false;
}

double OSXContext::getLayoutWidth( ATSUTextLayout layout )
{
	ATSUTextMeasurement width = 0;
	OSStatus status = ATSUGetLayoutControl( layout,
											kATSULineWidthTag,
											sizeof(ATSUTextMeasurement),
											&width, NULL );

	if ( status == noErr ) {
		return (double)width;
	}
	else {
		//throw exception ??
	}

	return -1.0;
}

void OSXContext::atsuDrawTextInBox(	const VCF::Rect& rect )
{
	OSStatus 			err = noErr;
	UniCharArrayOffset	textOffset = 0;
	UniCharCount		textLength = 0;
	UniCharArrayOffset*	lineEndOffsets = NULL;

	bool failed = false;

	// the the range of text to be drawn
	err = ATSUGetTextLocation (textLayout_, NULL, NULL, &textOffset, &textLength, NULL);
	if (err == noErr) {
		UniCharArrayOffset lineStartOffset = textOffset;
		UniCharArrayOffset lineEndOffset = 0;

		FixedPointNumber xPos = rect.left_;

		ATSUTextMeasurement	yPos = vcf_IntToFixed((int) ( rect.top_ + getTextHeight("EM") ));

		ATSUTextMeasurement	lineStart = xPos;
		ATSUTextMeasurement	lineEnd = vcf_IntToFixed((int)rect.right_);
		ATSUTextMeasurement	lineWidth = 0;

		//at the moment we are not taking text angle into account
		Fixed textAngle = 0;

		ItemCount lineCount = 0;
		ItemCount softBreakCount = 0;
		ATSUTextMeasurement	maxAscent = 0, maxDescent = 0;
		ulong32 ln = 0;


		// check for linewidth set as a layout control
		//lineWidth = getLayoutWidth( textLayout_ );

		//	if there is no layout control set for width
		//	then set it using the box bounds
		if (lineWidth == 0) {
			lineWidth = lineEnd - lineStart;
		}

		//	Break and measure each line to determine the max ascent and descent;
		//	This is needed because things that end up on different lines
		//	could interact to affect the line height when they're on the same line.
		//	To get the best value we break the lines first, then measure each
		//	line and find the max ascent and descent.
		while (lineStartOffset < textOffset + textLength) {
			ATSUTextMeasurement		ascent = 0, descent = 0;

			// set the soft breaks, we will use them later
			err = ATSUBreakLine(textLayout_, lineStartOffset, lineWidth, true, &lineEndOffset);
			if ( err != noErr ) {
				failed = true;
				printf ( "err: %d, ATSUBreakLine()\n", (int)err );
				goto EXIT;
			}

			// @@@ If you want leave lines that are terminated with a hard break unjustified, this is a
			// good place to set the individual line control to do that.

#if (ATSU_TARG_VERSION >= ATSU_1_1)
			// ATSUGetGlyphBounds is better than ATSUMeasureText if you've got any interesting feature
			// such as justification turned on. The former will do the layout exactly as it will be drawn and cache
			// the result, so things will be faster overall. ATSUMeasureText will turn off justification and end up doing
			// an "extra" layout operation.
			{
				ATSTrapezoid	glyphBounds;	// one should be enough when we're asking for the whole line.

				err = ATSUGetGlyphBounds( textLayout_, 0, 0, lineStartOffset, lineEndOffset - lineStartOffset, kATSUseFractionalOrigins,
												1, &glyphBounds, NULL );
				if ( err != noErr ) {
					failed = true;
					printf ( "err: %d, ATSUGetGlyphBounds()\n", (int)err );
					goto EXIT;
				}

				// The top and bottom of the bounds should be parallel to the baseline. You might want to check that.
				if (textAngle == 0) {
					ascent = -glyphBounds.upperLeft.y;
					descent = glyphBounds.lowerLeft.y;
				} else {
					// This looks strange, but the box you get is rotated, so "upper left" relative to the line is "upper right" in absolute terms.
					ascent = glyphBounds.upperLeft.x;
					descent = -glyphBounds.lowerLeft.x;
				}
			}
#else
			err = ATSUMeasureText(textLayout_, lineStartOffset, lineEndOffset - lineStartOffset, NULL, NULL, &ascent, &descent);
			if ( err != noErr ) {
				failed = true;
				printf ( "err: %d, ATSUMeasureText()\n", err );
				goto EXIT;
			}
#endif

			if (ascent > maxAscent)
				maxAscent = ascent;
			if (descent > maxDescent)
				maxDescent = descent;

			lineStartOffset = lineEndOffset;
			lineCount++;
		}

		lineEndOffsets = (UniCharArrayOffset*) NewPtr(lineCount * sizeof(UniCharArrayOffset));

		err = MemError();
		if ( err != noErr ) {
			failed = true;
			printf ( "err: %d, MemError()\n", (int)err );
			goto EXIT;
		}

		err = ATSUGetSoftLineBreaks(	textLayout_,
											textOffset,
											textLength,
											lineCount,
											lineEndOffsets,
											&softBreakCount);

		//	assert that the number of soft breaks is always one less than the number of lines
		//	since ATSUBreakLine does not insert a softbreak at the end of the text.

		if ( (err != noErr) || (softBreakCount != (lineCount - 1)) ) {
			failed = true;
			printf ( "err: %d, ATSUGetSoftLineBreaks()\n", (int)err );
			goto EXIT;
		}

		lineEndOffsets[softBreakCount] = textOffset + textLength;
		lineStartOffset = textOffset;

		// @@@ If maxAscent or maxDescent are not integers, this code may produce uneven line spacing. It will also
		// not necessarily match the line height used by ATSUI when highlighting. ATSUI highlighting uses
		// vcf_FixedToInt( baseline - ascent ) for the top of the box and vcf_FixedToInt( baseline + descent ) for the bottom.
		// Any other combination of reflection and rounding can result in one-pixel gaps and overlaps.

		// If you're using ATSUGetGlyphBounds above, you could ask for kATSUseDeviceOrigins to have ATSUI do this transformation for you.

		//	draw each line


		for (ln = 0; ln < lineCount; ln++) {
			lineEndOffset = lineEndOffsets[ln];

			err = ATSUDrawText( textLayout_,
										lineStartOffset,
										lineEndOffset - lineStartOffset,
										xPos,
										yPos*-1);

			if ( err != noErr ) {
				failed = true;
				printf ( "err: %d, ATSUDrawText() failed in OSXContect::atsuDrawTextInBox()\n", (int)err );
				goto EXIT;
			}

			lineStartOffset = lineEndOffset;

			yPos += maxAscent;
			yPos += maxDescent;
		}
	}


EXIT:
	if ( failed ) {
		//throw exception ??
		printf( "\n\nWe Blewit !\n\n" );
	}


	if (lineEndOffsets != NULL)  {
		DisposePtr((char*)lineEndOffsets);
	}
}

void OSXContext::setClippingPath( Path* clippingPath )
{

}

void OSXContext::setClippingRect( Rect* clipRect )
{

}


/*
void OSXContext::drawSelectionRect( VCF::Rect* rect )
{
    ::Rect r = RectProxy(rect);

    DrawThemeFocusRect( &r, TRUE );
}

void OSXContext::drawButtonRect( Rect* rect, const bool& isPressed )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );
    ThemeButtonDrawInfo btnInfo;
    btnInfo.state = isPressed ? kThemeStatePressed : kThemeStateActive;
    btnInfo.value = kThemeButtonOff;
    btnInfo.adornment = kThemeAdornmentNone;


    DrawThemeButton( &r, kThemePushButton, &btnInfo, NULL, NULL, NULL, 0 );
}

void OSXContext::drawCheckboxRect( Rect* rect, const bool& isPressed )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );
    ThemeButtonDrawInfo btnInfo;
    btnInfo.state = isPressed ? kThemeStatePressed : kThemeStateActive;
    btnInfo.value = isPressed ?  kThemeButtonOn : kThemeButtonOff;
    btnInfo.adornment = kThemeAdornmentNone;


    DrawThemeButton( &r, kThemeCheckBox, &btnInfo, NULL, NULL, NULL, 0 );
}

void OSXContext::drawRadioButtonRect( Rect* rect, const bool& isPressed )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );
    ThemeButtonDrawInfo btnInfo;
    btnInfo.state = isPressed ? kThemeStatePressed : kThemeStateActive;
    btnInfo.value = isPressed ?  kThemeButtonOn : kThemeButtonOff;
    btnInfo.adornment = kThemeAdornmentNone;


    DrawThemeButton( &r, kThemeRadioButton, &btnInfo, NULL, NULL, NULL, 0 );
}

void OSXContext::drawVerticalScrollButtonRect( Rect* rect, const bool& topButton, const bool& isPressed )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    //DrawThemeScrollBarArrows( &r,  kThemeTrackNothingToScroll, 0, TRUE, NULL );
}

void OSXContext::drawHorizontalScrollButtonRect( Rect* rect, const bool& leftButton, const bool& isPressed )
{

}



void OSXContext::drawDisclosureButton( Rect* rect, const long& state )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ThemeButtonDrawInfo btnInfo;
    btnInfo.state = kThemeStateActive;
    //btnInfo.value = isPressed ?  kThemeButtonOn : kThemeButtonOff;
    btnInfo.adornment = kThemeAdornmentNone;

    switch ( state ) {
        case GraphicsContext::dsClosed : {
            btnInfo.value = kThemeDisclosureRight;
        }
        break;

        case GraphicsContext::dsPartialOpened : {

        }
        break;

        case GraphicsContext::dsOpened : {
            btnInfo.value = kThemeDisclosureDown;
        }
        break;
    }

    DrawThemeButton( &r, kThemeDisclosureButton, &btnInfo, NULL, NULL, NULL, 0 );
}


void OSXContext::drawTab( Rect* rect, const bool& selected, const String& caption )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );
    //we need more info
    //DrawThemeTab ( &r,
}


void OSXContext::drawTabPage( Rect* rect )
{

}

void OSXContext::drawHeader( Rect* rect )
{

}


void OSXContext::drawEdge( Rect* rect, const long& edgeSides, const long& edgeStyle )
{
    if ( GraphicsContext::etAllSides == edgeSides ) {
        ::Rect r = RectProxy(rect);

        //SwitchPort sw( grafPort_ );

        DrawThemePrimaryGroup( &r, kThemeStateActive );
    }
    else {
        if ( edgeSides & GraphicsContext::etLeftSide ) {
            ::Rect r = RectProxy(rect);
            r.right = r.left;
            DrawThemeSeparator( &r, kThemeStateActive );
        }

        if ( edgeSides & GraphicsContext::etRightSide ) {
            ::Rect r = RectProxy(rect);
            r.left = r.right;
            DrawThemeSeparator( &r, kThemeStateActive );
        }

        if ( edgeSides & GraphicsContext::etTopSide ) {
            ::Rect r = RectProxy(rect);
            r.bottom = r.top;
            DrawThemeSeparator( &r, kThemeStateActive );
        }

        if ( edgeSides & GraphicsContext::etBottomSide ) {
            ::Rect r = RectProxy(rect);
            r.top = r.bottom;
            DrawThemeSeparator( &r, kThemeStateActive );
        }
    }
}

void OSXContext::drawSizeGripper( VCF::Rect* rect )
{
    ::Rect bounds;
    ::Point gripperOrigin;
    gripperOrigin.h = (int)rect->left_;
    gripperOrigin.v = (int)rect->top_;

    //SwitchPort sw( grafPort_ );

    GetThemeStandaloneGrowBoxBounds( gripperOrigin, 0, FALSE, &bounds );
    gripperOrigin.h = (int)(rect->right_ - (bounds.right-bounds.left));
    gripperOrigin.v = (int)(rect->bottom_ - (bounds.bottom-bounds.top));

    DrawThemeStandaloneGrowBox( gripperOrigin, 0, FALSE,  kThemeStateInactive );
}


void OSXContext::drawControlBackground( Rect* rect )
{

}


void OSXContext::drawWindowBackground( Rect* rect )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ::SetThemeBackground( kThemeBrushUtilityWindowBackgroundActive, 32, true ) ;

    ::EraseRect( &r ) ;
}

void OSXContext::drawMenuItemBackground( Rect* rect, const bool& selected )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ::SetThemeBackground( selected ? kThemeBrushMenuBackgroundSelected : kThemeBrushMenuBackground,
                            32,
                            true ) ;

    ::EraseRect( &r ) ;
}

void OSXContext::drawTickMarks( Rect* rect, const SliderInfo& sliderInfo  )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ThemeTrackDrawInfo info;
    info.kind = kThemeMediumSlider;
    info.bounds = r;
    info.min = (int)sliderInfo.min;
    info.max = (int)sliderInfo.max;
    info.value = (int)sliderInfo.position;
    info.attributes = sliderInfo.vertical ? 0 :  kThemeTrackHorizontal;
    info.attributes |= kThemeTrackRightToLeft;

    info.trackInfo.slider.thumbDir = 0;
    info.trackInfo.slider.pressState = 0;


    if ( sliderInfo.pressed ) {
        info.enableState = kThemeTrackActive;
    }
    else if ( !sliderInfo.enabled ) {
        info.enableState = kThemeTrackDisabled;
    }
    else {
        info.enableState = kThemeTrackInactive;
    }

    if ( sliderInfo.bottomRightTicks ) {
        info.trackInfo.slider.thumbDir = kThemeThumbUpward;
    }
    else if( sliderInfo.topLeftTicks ) {
        info.trackInfo.slider.thumbDir = kThemeThumbDownward;
    }

    if ( noErr != DrawThemeTrackTickMarks( &info, sliderInfo.tickCount, NULL, 0 ) ) {
        printf( "DrawThemeTrackTickMarks failed\n" );
    }

}


void OSXContext::drawSliderThumb( Rect* rect, const SliderInfo& sliderInfo )
{
    
    //::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    //ThemeTrackDrawInfo info;
    //info.kind = kThemeMediumSlider;
    //info.bounds = r;
    //info.min = sliderInfo.min;
    //info.max = sliderInfo.max;
    //info.value = sliderInfo.position;
    //info.attributes = sliderInfo.vertical ? 0 :  kThemeTrackHorizontal;
    //info.attributes |= kThemeTrackRightToLeft | kThemeTrackShowThumb;

    //info.trackInfo.slider.thumbDir = 0;
    //info.trackInfo.slider.pressState = 0;


    //if ( sliderInfo.pressed ) {
     //   info.enableState = kThemeTrackActive;
   // }
    //else if ( !sliderInfo.enabled ) {
      //  info.enableState = kThemeTrackDisabled;
   // /}
    //else {
     //   info.enableState = kThemeTrackInactive;
    //}

    //if ( noErr != DrawThemeTrack( &info, NULL, NULL, NULL ) ) {
      //  printf( "DrawThemeTrackTickMarks failed\n" );
   // }
    
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ThemeButtonDrawInfo btnInfo;
    btnInfo.value = 0;
    if ( sliderInfo.pressed ) {
        btnInfo.state = kThemeStatePressedDown;
    }
    else if ( !sliderInfo.enabled ) {
        btnInfo.state = kThemeStateActive;

    }
    else {
        btnInfo.state = kThemeStateInactive;
    }
    btnInfo.value = kThemeButtonOn;//isPressed ?  kThemeButtonOn : kThemeButtonOff;
    btnInfo.adornment = kThemeAdornmentNone;



    DrawThemeButton( &r, kThemeRoundButton, &btnInfo, NULL, NULL, NULL, 0 );
}

void OSXContext::drawSlider( Rect* rect, const SliderInfo& sliderInfo )
{
    ::Rect r = RectProxy(rect);

    //SwitchPort sw( grafPort_ );

    ThemeTrackDrawInfo info;
    info.kind = kThemeMediumSlider;
    info.bounds = r;
    info.min = (int)sliderInfo.min;
    info.max = (int)sliderInfo.max;
    info.value = (int)sliderInfo.position;
    info.attributes = sliderInfo.vertical ? 0 :  kThemeTrackHorizontal;
    info.attributes |= kThemeTrackRightToLeft;

    info.trackInfo.slider.thumbDir = 0;
    info.trackInfo.slider.pressState = 0;


    if ( sliderInfo.pressed ) {
        info.enableState = kThemeTrackActive;
    }
    else if ( !sliderInfo.enabled ) {
        info.enableState = kThemeTrackDisabled;
    }
    else {
        info.enableState = kThemeTrackInactive;
    }

    if ( noErr != DrawThemeTrack( &info, NULL, NULL, NULL ) ) {
        printf( "DrawThemeTrackTickMarks failed\n" );
    }
}
*/






void OSXContext::drawThemeSelectionRect( Rect* rect, DrawUIState& state )
{
	OSXRect r = rect;

    DrawThemeFocusRect( r, state.isFocused() );
}


void OSXContext_drawThemeButtonText( const ::Rect * bounds, ThemeButtonKind kind, 
										const ThemeButtonDrawInfo * info, UInt32 userData,
										SInt16 depth, Boolean isColorDev )
{
	ButtonState* state = (ButtonState*)userData;
	CFTextString cfStr;
	cfStr = state->buttonCaption_;
	
	DrawThemeTextBox( cfStr, kThemePushButtonFont, info->state, FALSE, bounds, 0, NULL );
}


void OSXContext::drawThemeButtonRect( Rect* rect, ButtonState& state )
{
	OSXRect r = rect;
	
    ThemeButtonDrawInfo btnInfo;
	btnInfo.state = kThemeStateInactive ;
	
	if ( state.isPressed() ) {
		btnInfo.state |= kThemeStatePressed;
	}
	
	if ( state.isActive() && state.isEnabled() ) {
		btnInfo.state |= kThemeStateActive;
	}
	
	btnInfo.value = kThemeButtonOff;
	btnInfo.adornment = kThemeAdornmentNone;
	
	if ( state.isFocused() ) {
		btnInfo.adornment |= kThemeAdornmentFocus;
	}	
    
    

	ThemeButtonDrawUPP btnDrawUPP = NewThemeButtonDrawUPP(OSXContext_drawThemeButtonText);
	
    DrawThemeButton( r, kThemePushButton, &btnInfo, NULL, NULL, btnDrawUPP, (UInt32)&state );
	
	DisposeThemeButtonDrawUPP(btnDrawUPP);
}

void OSXContext::drawThemeCheckboxRect( Rect* rect, ButtonState& state )
{
	OSXRect r = rect;
	
    ThemeButtonDrawInfo btnInfo;
	btnInfo.state = kThemeStateInactive ;
	
	btnInfo.value = kThemeButtonOff;
	
	if ( state.isPressed() ) {
		btnInfo.state |= kThemeStatePressed;
		btnInfo.value = kThemeButtonOn;
	}
	
	if ( state.isActive() && state.isEnabled() ) {
		btnInfo.state |= kThemeStateActive;
	}
	
	
	btnInfo.adornment = kThemeAdornmentNone;
	
	if ( state.isFocused() ) {
		btnInfo.adornment |= kThemeAdornmentFocus;
	}	
    
    

	ThemeButtonDrawUPP btnDrawUPP = NewThemeButtonDrawUPP(OSXContext_drawThemeButtonText);
	
    DrawThemeButton( r, kThemeCheckBox, &btnInfo, NULL, NULL, btnDrawUPP, (UInt32)&state );
	
	DisposeThemeButtonDrawUPP(btnDrawUPP);
}

void OSXContext::drawThemeRadioButtonRect( Rect* rect, ButtonState& state )
{
	OSXRect r = rect;
	
    ThemeButtonDrawInfo btnInfo;
	btnInfo.state = kThemeStateInactive ;
	
	btnInfo.value = kThemeButtonOff;
	
	if ( state.isPressed() ) {
		btnInfo.state |= kThemeStatePressed;
		btnInfo.value = kThemeButtonOn;
	}
	
	if ( state.isActive() && state.isEnabled() ) {
		btnInfo.state |= kThemeStateActive;
	}
	
	
	btnInfo.adornment = kThemeAdornmentNone;
	
	if ( state.isFocused() ) {
		btnInfo.adornment |= kThemeAdornmentFocus;
	}	
    
    

	ThemeButtonDrawUPP btnDrawUPP = NewThemeButtonDrawUPP(OSXContext_drawThemeButtonText);
	
    DrawThemeButton( r, kThemeRadioButton, &btnInfo, NULL, NULL, btnDrawUPP, (UInt32)&state );
	
	DisposeThemeButtonDrawUPP(btnDrawUPP);
}

void OSXContext::drawThemeScrollButtonRect( Rect* rect, DrawUIState& state )
{
	
}

void OSXContext::drawThemeDisclosureButton( Rect* rect, DisclosureButtonState& state )
{
	OSXRect r = rect;
	
    ThemeButtonDrawInfo btnInfo;
	btnInfo.state = kThemeStateInactive ;
	
	btnInfo.value = kThemeButtonOff;
	
	if ( state.isClosed() ) {		
		btnInfo.value = kThemeDisclosureRight;
	}
	else if ( state.isOpened() ) {		
		btnInfo.value = kThemeDisclosureDown;
	}
	
	if ( state.isActive() && state.isEnabled() ) {
		btnInfo.state |= kThemeStateActive;
	}
	
	
	btnInfo.adornment = kThemeAdornmentNone;		    

    DrawThemeButton( r, kThemeDisclosureButton, &btnInfo, NULL, NULL, NULL, 0 );
	
}

void OSXContext::drawThemeTab( Rect* rect, DrawUIState& state )
{
	OSXRect r = rect;
	
	TabState* ts = (TabState*)&state;
	
	ThemeTabStyle tabStyle = kThemeTabNonFront;
	if ( ts->isPressed() ) {
		tabStyle |= kThemeTabFront;
	}
	
	if ( !ts->isActive() ) {		
		if ( ts->isPressed() ) {
			tabStyle |= kThemeTabFrontInactive;
		}
		else {
			tabStyle |= kThemeTabNonFrontInactive;
		}
	}
	
	ThemeTabDirection dir = 0;
	
	if ( ts->isTabOnTop() ) {
		dir = kThemeTabNorth;
	}
	else if ( ts->isTabOnBottom() ) {
		dir = kThemeTabSouth;
	}
	else if ( ts->isTabOnLeft() ) {
		dir = kThemeTabWest;
	}
	else if ( ts->isTabOnRight() ) {
		dir = kThemeTabEast;
	}	
	
	
	DrawThemeTab( r, tabStyle, dir, NULL, 0 );
}

void OSXContext::drawThemeTabPage( Rect* rect, DrawUIState& state )
{
	OSXRect r = rect;
	DrawThemeTabPane( r, state.isActive() ? kThemeStateActive : kThemeStateInactive );
}

void OSXContext::drawThemeTickMarks( Rect* rect, DrawUIState& state )
{
	
}

void OSXContext::drawThemeSlider( Rect* rect, DrawUIState& state )
{

}

void OSXContext::drawThemeProgress( Rect* rect, ProgressState& state )
{

}

void OSXContext::drawThemeImage( Rect* rect, Image* image, DrawUIState& state )
{

}

void OSXContext::drawThemeHeader( Rect* rect, DrawUIState& state )
{

}

void OSXContext::drawThemeEdge( Rect* rect, DrawUIState& state, const long& edgeSides, const long& edgeStyle )
{

}

void OSXContext::drawThemeSizeGripper( Rect* rect, DrawUIState& state )
{

}

void OSXContext::drawThemeBackground( Rect* rect, BackgroundState& state )
{

}

void OSXContext::drawThemeMenuItem( Rect* rect, MenuState& state )
{

}

void OSXContext::drawThemeText( Rect* rect, const String& text, DrawUIState& state, bool wrapText )
{

}
	
	
	
/**
*CVS Log info
*$Log$
*Revision 1.1.2.10.2.1  2004/06/15 04:04:38  ddiego
*revamped osx theme drawing API
*
*Revision 1.1.2.10  2004/06/07 03:07:07  ddiego
*more osx updates dealing with mouse handling
*
*Revision 1.1.2.9  2004/06/06 07:05:34  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.8  2004/05/31 19:42:53  ddiego
*more osx updates
*
*Revision 1.1.2.7  2004/05/31 13:20:58  ddiego
*more osx updates
*
*Revision 1.1.2.6  2004/05/23 14:12:18  ddiego
*osx updates
*
*Revision 1.1.2.5  2004/05/16 02:39:10  ddiego
*OSX code updates
*
*Revision 1.1.2.4  2004/05/07 23:23:33  ddiego
*more osx changes
*
*Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:46  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.4  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*Revision 1.1.2.3  2004/02/23 05:51:31  ddiego
*basic GraphicsKit implementation done for OSX
*
*Revision 1.1.2.2  2004/02/22 06:50:22  ddiego
*more progress with the OSX GraphicsKit - almost done!
*
*Revision 1.1.2.1  2004/02/21 03:27:09  ddiego
*updates for OSX porting
*
*/


