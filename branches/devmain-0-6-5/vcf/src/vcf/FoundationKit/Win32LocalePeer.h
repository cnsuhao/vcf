#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_WIN32LOCALEPEER_H__
#define _VCF_WIN32LOCALEPEER_H__


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


class Win32LocalePeer : public LocalePeer {
public:
	Win32LocalePeer();
	

	virtual void setLocale( const UnicodeString& language, const UnicodeString& country, const UnicodeString& variant );

	virtual ulong32 getLanguageCode();
	virtual ulong32 getCountryCode();

	virtual int collate( const UnicodeString& s1, const UnicodeString& s2 );
	virtual int collateCaseInsensitive( const UnicodeString& s1, const UnicodeString& s2 );

	virtual UnicodeString toString( const int& val );
	virtual UnicodeString toString( const unsigned int& val );
	virtual UnicodeString toString( const long& val );
	virtual UnicodeString toString( const unsigned long& val );
	virtual UnicodeString toString( const double& val );
	virtual UnicodeString toString( const float& val );

	virtual UnicodeString toStringFromDate( const DateTime& val, const UnicodeString& format );
	virtual UnicodeString toStringFromTime( const DateTime& val, const UnicodeString& format );


	virtual UnicodeString toStringFromCurrency( const double& val );
	
	virtual int toInt( const UnicodeString& str );
	virtual unsigned int toUInt( const UnicodeString& str );
	virtual double toDouble( const UnicodeString& str );
	virtual float toFloat( const UnicodeString& str );
	virtual double toDoubleAsCurrency( const UnicodeString& str );	

	virtual UnicodeString toLowerCase( const UnicodeString& s );
	virtual UnicodeString toUpperCase( const UnicodeString& s );

	virtual UnicodeString getNumberThousandsSeparator();
	virtual UnicodeString getNumberDecimalPoint();
	virtual UnicodeString getNumberGrouping();
	virtual UnicodeString getCurrencyDecimalPoint();
	virtual UnicodeString getCurrencyThousandsSeparator();
	virtual UnicodeString getCurrencySymbol();	
	virtual int getCurrencyFractionalDigits();
	virtual UnicodeString getCurrencyPositiveSign();
	virtual UnicodeString getCurrencyNegativeSign();

	virtual bool isCharA( const long& charTypeMask, const VCFChar& c );

	virtual UnicodeString translate( const UnicodeString& id );

	virtual ulong32 getHandleID() {
		return (ulong32)lcid_;
	}
protected:
	UnicodeString changeToGenericNumberString( const UnicodeString& str );
	void initNumberFormatForIntW( NUMBERFMTW& fmt );
	void initNumberFormatForIntA( NUMBERFMTA& fmt );
	void initNumberFormatForFloatW( NUMBERFMTW& fmt );
	void initNumberFormatForFloatA( NUMBERFMTA& fmt );
	LCID lcid_;
	UnicodeString crtLocaleStr_;

	static std::map<String,int> langIDs;
	static std::map<String,int> countryIDs;
};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.2  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2.2.1  2004/04/21 02:17:23  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.2  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/16 04:08:44  ddiego
*updates some missing locale impl files
*
*/



};



#endif // _VCF_WIN32LOCALEPEER_H__



