/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.11.4.1  2004/04/21 02:17:26  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.11  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.10.4.1  2003/08/25 03:46:38  ddiego
*some fixes to some of the stream impls
*
*Revision 1.10  2003/05/17 20:37:25  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.9.14.2  2003/03/23 03:23:56  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.9.14.1  2003/03/12 03:12:16  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.9  2002/05/26 21:19:54  ddiego
*added and fixed xmake makefiles for FoundationKit and for the RTTI test
*so that this now runs under linux (should work fine for Solaris as well).
*Made some changes to Object for removing one of the operator delete() when
*using GCC
*Other minor changes to files to ensure that they end with a carriage return
*
*Revision 1.8  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.7.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.7  2002/02/28 01:07:23  ddiego
*fixed bug [ 523259 ] InputStream::read(String&) is incorrect
*added new virtual function Stream::getCurrentSeekPos to help fix the problem.
*Made apropriate changes to all stream headers and implementation to account
*for thisd
*
*Revision 1.6  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

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

// TextInputStream.cpp

#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;

TextInputStream::TextInputStream( InputStream* inStream )
{
	this->init();
	this->inStream_ = inStream;
	if ( NULL != inStream_ ){
		this->size_ = this->inStream_->getSize();
	}	
}

TextInputStream::~TextInputStream()
{

}

void TextInputStream::seek(const unsigned long& offset, const SeekType& offsetFrom )
{
	if ( NULL != inStream_ ){
		inStream_->seek( offset, offsetFrom );
	}
}

unsigned long TextInputStream::getSize()
{
	return size_;
}

char* TextInputStream::getBuffer()
{
	return NULL;
}

void TextInputStream::read( char* bytesToRead, unsigned long sizeOfBytes )
{
	if ( NULL != inStream_ ){
		inStream_->read( bytesToRead, sizeOfBytes );
	}
}

void TextInputStream::read( short& val )
{
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();		
		int i = val = 0;
		swscanf( tmp.c_str(), W_STR_INT_CONVERSION, &i );
		val = (short)i;		
	}
}
	
void TextInputStream::read( long& val )
{
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();		
		int i = val = 0;
		swscanf( tmp.c_str(), W_STR_INT_CONVERSION, &i );
		val = i;		
	}
}

void TextInputStream::read( int& val )
{
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();		
		int i = val = 0;
		swscanf( tmp.c_str(), W_STR_INT_CONVERSION, &i );
		val = i;
	}
}

void TextInputStream::read( bool& val )
{
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();
		if ( tmp == W_STR_BOOL_CONVERSION_TRUE ){
			val = true;
		}
		else if ( tmp == W_STR_BOOL_CONVERSION_FALSE ){
			val = false;
		}
	}
}

void TextInputStream::read( float& val )
{	
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();
		val = 0.0;
		float f = 0.0;
		swscanf( tmp.c_str(), W_STR_DOUBLE_CONVERSION, &f );
		val = f;
	}
}

void TextInputStream::read( double& val )
{
	if ( NULL != this->inStream_ ){
		String tmp = readTillWhiteSpace();
		val = 0.0;
		float f = 0.0;
		swscanf( tmp.c_str(), W_STR_DOUBLE_CONVERSION, &f );
		val = f;
	}
}

void TextInputStream::read( String& val )
{
	//val = readTillTokenPair( '\n' );

	readLine( val );
}


void TextInputStream::init()
{
	this->inStream_ = NULL;
	this->size_ = 0;
	totCharRead_ = 0;
}

void TextInputStream::readLine( String& line )
{
	if ( NULL != this->inStream_ )
	{
		char c = '\0';
		inStream_->read( &c, sizeof(c) );
		totCharRead_++;
		while ( (c != '\n' && c!= '\r') && (totCharRead_ < size_) )
		{ 
			line += c;
			inStream_->read( &c, sizeof(c) );			
			totCharRead_++;
		}
	}
}

String TextInputStream::readTillWhiteSpace()
{	
	String result = "";
	if ( NULL != this->inStream_ ){				
		char c = '\0';
		inStream_->read( &c, sizeof(c) );
		totCharRead_++;
		
		while ( ((c == ' ') || (c == '\0')) && (totCharRead_ < size_) ){			
			inStream_->read( &c, sizeof(c) );			
			totCharRead_++;
		}
		//get all the nonwhitespace characters
		while ( (c != ' ') && (c != '\0')  && (totCharRead_ < size_) ){
			result += c;
			inStream_->read( &c, sizeof(c) );
			totCharRead_++;
		}				
	}
	return result;
}

String TextInputStream::readTillTokenPair( const char& token )
{
	String result = "";
	if ( NULL != this->inStream_ ){				
		char c = '\0';
		inStream_->read( &c, sizeof(c) );
		totCharRead_++;
		
		while ( (c != token) && (c != ' ') && (totCharRead_ < size_) ){
			inStream_->read( &c, sizeof(c) );
			totCharRead_++;
		}
		
		while ( (c != token) && (totCharRead_ < size_) ){
			result += c;
			inStream_->read( &c, sizeof(c) );
			totCharRead_++;
		}
	}
	return result;
}

ulong32 TextInputStream::getCurrentSeekPos()
{
	if ( NULL != inStream_ ) {
		return inStream_->getCurrentSeekPos();
	}
	return 0;
}


