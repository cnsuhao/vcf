/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
*/

#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/LocalePeer.h"
#include "vcf/FoundationKit/OSXLocalePeer.h"
#include "vcf/FoundationKit/DateTime.h"



using namespace VCF;



OSXLocalePeer::OSXLocalePeer()
{
	
}

void OSXLocalePeer::setLocale( const UnicodeString& language, const UnicodeString& country, const UnicodeString& variant )
{
	if ( language.empty() && country.empty() ) {
		
	}
	else {
		
	}
}	

int OSXLocalePeer::collate( const UnicodeString& s1, const UnicodeString& s2 )
{
	return 0;
}


int OSXLocalePeer::collateCaseInsensitive( const UnicodeString& s1, const UnicodeString& s2 )
{
	return 0;
}


UnicodeString OSXLocalePeer::toString( const int& val )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::toString( const unsigned int& val )
{
	UnicodeString result;
	return result;
}

UnicodeString OSXLocalePeer::toString( const long& val )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::toString( const unsigned long& val )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::toString( const double& val )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::toString( const float& val )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::toStringFromCurrency( const double& val )
{
	UnicodeString result;

	return result;
}




int OSXLocalePeer::toInt( const UnicodeString& str )
{
	int result;
	return result;
}

unsigned int OSXLocalePeer::toUInt( const UnicodeString& str )
{
	unsigned int result;

	return result;
}

double OSXLocalePeer::toDouble( const UnicodeString& str )
{
	double result;
	
	
	return result;
}

float OSXLocalePeer::toFloat( const UnicodeString& str )
{
	float result;
	

	return result;
}

double OSXLocalePeer::toDoubleAsCurrency( const UnicodeString& str )
{
	double result;


	return result;
}



UnicodeString OSXLocalePeer::toLowerCase( const UnicodeString& s )
{
	UnicodeString result;
	

	return result;
}

UnicodeString OSXLocalePeer::toUpperCase( const UnicodeString& s )
{
	UnicodeString result;

	return result;
}

UnicodeString OSXLocalePeer::getNumberThousandsSeparator()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getNumberDecimalPoint()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getNumberGrouping()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getCurrencyDecimalPoint()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getCurrencyThousandsSeparator()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getCurrencySymbol()
{
	UnicodeString result;
	
	return result;
}

int OSXLocalePeer::getCurrencyFractionalDigits()
{
	int result = 0;
	
	return result;
}

UnicodeString OSXLocalePeer::getCurrencyPositiveSign()
{
	UnicodeString result;
	
	return result;
}

UnicodeString OSXLocalePeer::getCurrencyNegativeSign()
{
	UnicodeString result;
	
	return result;
}

bool OSXLocalePeer::isCharA( const long& charTypeMask, const VCFChar& c )
{
	long mask = 0;

	UnicodeString oldLocaleStr = setlocale( LC_CTYPE, NULL );

	setlocale( LC_CTYPE, crtLocaleStr_.ansi_c_str() );

	if ( charTypeMask & ctSpace ) {
		if ( isspace( c ) ) {
			mask |= ctSpace;
		}
	}

	if ( charTypeMask & ctPrint ) {
		if ( isprint( c ) ) {
			mask |= ctPrint;
		}
	}

	if ( charTypeMask & ctCntrl ) {
		if ( isprint( c ) ) {
			mask |= ctCntrl;
		}
	}

	if ( charTypeMask & ctCntrl ) {
		if ( iscntrl( c ) ) {
			mask |= ctCntrl;
		}
	}

	if ( charTypeMask & ctUpper ) {
		if ( isupper( c ) ) {
			mask |= ctUpper;
		}
	}

	if ( charTypeMask & ctLower ) {
		if ( islower( c ) ) {
			mask |= ctLower;
		}
	}

	if ( charTypeMask & ctDigit ) {
		if ( isdigit( c ) ) {
			mask |= ctDigit;
		}
	}

	if ( charTypeMask & ctPunct ) {
		if ( ispunct( c ) ) {
			mask |= ctPunct;
		}
	}

	if ( charTypeMask & ctHexDigit ) {
		if ( isxdigit( c ) ) {
			mask |= ctHexDigit;
		}
	}

	if ( charTypeMask & ctAlpha ) {
		if ( isalpha( c ) ) {
			mask |= ctAlpha;
		}
	}

	if ( charTypeMask & ctAlphaNumeric ) {
		if ( isalnum( c ) ) {
			mask |= ctAlphaNumeric;
		}
	}

	if ( charTypeMask & ctGraph ) {
		if ( isgraph( c ) ) {
			mask |= ctGraph;
		}
	}

	setlocale( LC_CTYPE, oldLocaleStr.ansi_c_str() );

	return (0 == mask) ? false : true;
}

UnicodeString OSXLocalePeer::translate( const UnicodeString& id )
{
	return "";
}

UnicodeString OSXLocalePeer::toStringFromDate( const DateTime& val, const UnicodeString& format )
{
	
	UnicodeString result;	

	return result;
}

UnicodeString OSXLocalePeer::toStringFromTime( const DateTime& val, const UnicodeString& format )
{	
	UnicodeString result;	

	return result;
}

ulong32 OSXLocalePeer::getLanguageCode()
{
	return 0;

}



ulong32 OSXLocalePeer::getCountryCode()
{
	
	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/30 05:44:34  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/21 03:27:09  ddiego
*updates for OSX porting
*
*Revision 1.1.2.1  2004/02/16 05:38:10  ddiego
*updated linux makefiles as a result of new locale support - pushed in stubs for locale peer impl, but no functionality at this point
*
*Revision 1.1.2.1  2004/02/16 04:08:44  ddiego
*updates some missing locale impl files
*
*/


