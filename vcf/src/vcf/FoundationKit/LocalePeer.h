
#if     _MSC_VER > 1000
#pragma once
#endif


#ifndef _VCF_LOCALEPEER_H__
#define _VCF_LOCALEPEER_H__

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


namespace VCF {




enum CharacterType{
	ctSpace = 0x1,
	ctPrint = 0x2, 
	ctCntrl = 0x04,
	ctUpper = 0x500, 
	ctLower = 0x600, 
	ctDigit = 0x10,
	ctPunct = 0x20, 
	ctHexDigit = 0x40,
	ctAlpha = 0x08, 
	ctAlphaNumeric = ctDigit | ctAlpha, 
	ctGraph = ctAlphaNumeric | ctPunct
};

class DateTime;



class FRAMEWORK_API LocalePeer {
public:
	virtual ~LocalePeer(){}

	/**
	Sets the locale specified by the langauge and country code.
	If language, country, and variant are empty, then the peer 
	must use the current locale of the system.
	*/
	virtual void setLocale( const UnicodeString& language, const UnicodeString& country, const UnicodeString& variant ) = 0;

	virtual ulong32 getLanguageCode() = 0;
	virtual ulong32 getCountryCode() = 0;

	virtual int collate( const UnicodeString& s1, const UnicodeString& s2 ) = 0;
	virtual int collateCaseInsensitive( const UnicodeString& s1, const UnicodeString& s2 ) = 0;

	virtual UnicodeString toString( const int& val ) = 0;
	virtual UnicodeString toString( const unsigned int& val ) = 0;
	virtual UnicodeString toString( const long& val ) = 0;
	virtual UnicodeString toString( const unsigned long& val ) = 0;
	virtual UnicodeString toString( const double& val ) = 0;
	virtual UnicodeString toString( const float& val ) = 0;
	
	virtual UnicodeString toStringFromDate( const DateTime& val, const UnicodeString& format ) = 0;
	virtual UnicodeString toStringFromTime( const DateTime& val, const UnicodeString& format ) = 0;

	virtual UnicodeString toStringFromCurrency( const double& val ) = 0;
	
	virtual int toInt( const UnicodeString& str ) = 0;
	virtual unsigned int toUInt( const UnicodeString& str ) = 0;
	virtual double toDouble( const UnicodeString& str ) = 0;
	virtual float toFloat( const UnicodeString& str ) = 0;
	virtual double toDoubleAsCurrency( const UnicodeString& str ) = 0;	

	virtual UnicodeString toLowerCase( const UnicodeString& s ) = 0;
	virtual UnicodeString toUpperCase( const UnicodeString& s ) = 0;

	virtual UnicodeString getNumberThousandsSeparator() = 0;
	virtual UnicodeString getNumberDecimalPoint() = 0;
	virtual UnicodeString getNumberGrouping() = 0;
	virtual UnicodeString getCurrencyDecimalPoint() = 0;
	virtual UnicodeString getCurrencyThousandsSeparator() = 0;
	virtual UnicodeString getCurrencySymbol() = 0;	
	virtual int getCurrencyFractionalDigits() = 0;
	virtual UnicodeString getCurrencyPositiveSign() = 0;
	virtual UnicodeString getCurrencyNegativeSign() = 0;

	virtual bool isCharA( const long& charTypeMask, const VCFChar& c ) = 0;

	virtual UnicodeString translate( const UnicodeString& id ) = 0;	

	/**
	returns a handler or otehr numeric identifier for hte locale. For Win32
	systems this will be the LCID value of the locale
	*/
	virtual ulong32 getHandleID() = 0;
};

};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:41  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/16 04:08:43  ddiego
*updates some missing locale impl files
*
*/



#endif // _VCF_LOCALEPEER_H__



