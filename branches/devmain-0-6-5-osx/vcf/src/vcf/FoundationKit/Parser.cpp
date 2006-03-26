//Parser.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;


Parser::Parser( InputStream* is )
{
	stream_ = is;

	buffer_ =  NULL;

	resetStream();
}

Parser::~Parser()
{
	delete [] buffer_;
}

void Parser::resetStream()
{
	if ( NULL != buffer_ ) {
		delete [] buffer_;
	}

	ulong32 strSize = stream_->getSize();
	buffer_ =  new VCFChar[ strSize+1 ];
	memset( buffer_, 0, (strSize+1) * sizeof(VCFChar) );

	char* tmp = new char[ strSize+1 ];
	memset( tmp, 0, (strSize+1) );

	stream_->seek( 0, stSeekFromStart );

	stream_->read( tmp, stream_->getSize() );

	String tmpStr = tmp;
	delete [] tmp;

	tmpStr.copy( buffer_, tmpStr.size() );

	bufPtr_ = buffer_;
	bufEnd_ = bufPtr_ + stream_->getSize();
	sourcePtr_ = buffer_;
	sourceEnd_ = buffer_;
	tokenPtr_ = buffer_;
	sourceLine_ = 1;
	token_ = '\0';
	this->nextToken();
}

void Parser::skipBlanks()
{
	while (true) {
		if ( *sourcePtr_ == 10 ) {
			sourceLine_ ++;
		}
		else if ( (*sourcePtr_ >= 33) && (*sourcePtr_ <= 255) ) {
			return;
		}
		sourcePtr_++;
	}
}

void Parser::checkToken( const VCFChar& T )
{
	if ( token_ != T ) {
		switch ( T ) {
			case TO_SYMBOL: {
				error("Identifier Expected");
			}
			break;

			case TO_STRING: {
				error("String Expected" );
			}
			break;

			case TO_INTEGER: case TO_FLOAT: {
				error("Number Expected");
			}
			break;

			default: {
				error( StringUtils::format( "Char Expected, instead: %c", T ) );
			}
			break;
		}
	}
}

String Parser::binHexToString()
{
	String result;

	skipBlanks();
	VCFChar* tmpBufPtr = sourcePtr_;
	VCFChar* tmpSourcePtr = sourcePtr_;
	while ( *tmpSourcePtr != '}' ) {
		if ( ((*tmpSourcePtr >= '0') && (*tmpSourcePtr <= '9')) || ((*tmpSourcePtr >= 'A') && (*tmpSourcePtr <= 'F'))
				|| ((*tmpSourcePtr >= 'a') && (*tmpSourcePtr <= 'f')) ) {
			sourcePtr_ ++;
		}
		tmpSourcePtr++;
	}
	result.append( tmpBufPtr, sourcePtr_-tmpBufPtr);
	sourcePtr_ = tmpSourcePtr;

	return result;
}

void Parser::checkTokenSymbol( const String& s )
{
	bool tki = tokenSymbolIs( s );
	if ( false == tki ) {
		error( StringUtils::format( "Symbol Expected, instead: %s", s.c_str() ) );
	}
}

void Parser::error( const String& Ident )
{
	errorStr(Ident);
}

void Parser::errorStr( const String& Message)
{
	throw RuntimeException( MAKE_ERROR_MSG_2(StringUtils::format( "Parse Error, message: %s", Message.c_str() )) );
}

VCFChar Parser::nextToken()
{
	VCFChar result = '\0';
	long I = 0;
	VCFChar* P = NULL;
	VCFChar* S = NULL;

	skipBlanks();

	P = sourcePtr_;
	tokenPtr_ = P;
	if ( ((*P >= 'A') && (*P <= 'Z')) || ((*P >= 'a') && (*P <= 'z')) || ( *P == '_' ) ) {
		P++;
		while ( ((*P == ':')) || ((*P >= 'A') && (*P <= 'Z')) || ((*P >= 'a') && (*P <= 'z')) || ((*P >= '0') && (*P <= '9')) || ( *P == '_' ) ) {
			P++;
		}
		result = TO_SYMBOL;
	}
	else if ( (*P == '#') || (*P == '\'') ) {
		S = P;
		bool finished = false;
		while ( !finished ) {
			switch ( *P ) {
				case '#' :
				{
					P++;
					I = 0;
					while ( (*P >= '0') && (*P <= '9') ) {
						I = I * 10 + (((int)(*P)) - ((int)('0')));
						P++;
					}
					*S = (VCFChar)I;
					S++;
				}
				break;

				case '\'' :
				{
					P++;
					bool finished2 = false;
					while ( !finished2 ) {
						switch ( *P ) {
							case '\0': case 10: case 13 : {
								error( "Invalid String" );
							}
							break;

							case '\'' : {
								P++;
								if ( *P != '\'' ) {
									finished2 = true;
								}
							}
							break;
						}
						if ( (*P != '\n') && (*P != '\r') ) {
							*S = *P;
						}
						else {
							*S = '\0';
						}
						P++;
						S++;
					}
				}
				break;

				default : {
					finished = true;
				}
				break;
			}
		}
		this->stringPtr_ = S;
		result = TO_STRING;
	}
	else if ( *P == '$' ) {
		P++;
		while ( ((*P >= '0') && (*P <= '9')) || ((*P >= 'A') && (*P <= 'F')) || ((*P >= 'a') && (*P <= 'f')) ) {
			P++;
		}
		result = TO_INTEGER;
	}
    else if ( (*P == '-') ||  ((*P >= '0') && (*P <= '9')) ) {
		P++;
		while ( ((*P >= '0') && (*P <= '9')) ) {
			P++;
		}
		result = TO_INTEGER;
		while ( ((*P >= '0') && (*P <= '9')) || (*P == '.') || (*P == 'e') || (*P == '+') || (*P == '-') ) {
			P++;
			result = TO_FLOAT;
		}
	}
	else {
		result = *P;
		if ( result != TO_EOF ) {
			P++;
		}
	}
	sourcePtr_ = P;
	token_ = result;

	return result;
}

long Parser::sourcePos()
{
	return origin_ + (tokenPtr_ - buffer_);
}

String Parser::tokenComponentIdent()
{

	checkToken( TO_SYMBOL );
	VCFChar* P = sourcePtr_;

	while ( (*P == '.') ) {
		P++;
		bool alpha = ((*P >= 'A') && (*P <= 'Z')) || ((*P >= 'a') && (*P <= 'z')) || ( *P == '_' );
		if ( !alpha ) {
			error( "Identifier Expected" );
		}

		do {
			alpha = ((*P >= 'A') && (*P <= 'Z')) || ((*P >= 'a') && (*P <= 'z')) || ((*P >= '0') && (*P <= '9')) || ( *P == '_' );
			P++;
		}while ( !alpha );
	}

	sourcePtr_ = P;

	return tokenString();
}

double Parser::tokenFloat()
{
	String s = tokenString();
	double result = StringUtils::fromStringAsFloat( s );
	return result;
}

long Parser::tokenInt()
{
	String s = tokenString();
	long result = StringUtils::fromStringAsInt( s );
	return result;
}

String Parser::tokenString()
{
	String result;
	long length = 0;
	if ( token_ == TO_STRING) {
		length = (stringPtr_ - tokenPtr_) - 1;
	}
	else {
		length = sourcePtr_ - tokenPtr_;
	}
	result.append( tokenPtr_, length );

	return result;
}

bool Parser::tokenSymbolIs(const String& s)
{
	//only work under WIN32 for the moment - need to replace _stricmp
#ifdef _MSC_VER
	return (token_ == TO_SYMBOL) && ( _wcsicmp( s.c_str(), tokenString().c_str() ) == 0 );
#else
	return false;
#endif
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.5  2004/06/06 07:05:33  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.1.2.2  2004/04/29 04:07:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.9.8.1  2004/04/21 02:17:27  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.9  2003/05/17 20:37:42  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.8.16.2  2003/03/23 03:23:58  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.8.16.1  2003/03/12 03:12:48  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.8  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.7.4.2  2002/03/25 04:19:46  ddiego
*fixed some file checking problems in xmake and fixed some general
*code to be able to compile with GCC and Borland C++
*
*Revision 1.7.4.1  2002/03/20 21:56:57  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.7  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

