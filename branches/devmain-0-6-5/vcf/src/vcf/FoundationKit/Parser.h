#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_PARSER_H__
#define _VCF_PARSER_H__
//Parser.h
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

class InputStream;

#define PARSE_BUF_SIZE		4096

#define TO_EOF				0
#define TO_SYMBOL			1
#define TO_STRING			2
#define TO_INTEGER			3
#define TO_FLOAT			4


/**
*A parsing utility class, at this moment (8/25/2001) meant 
*for internal use only
*/
class FRAMEWORK_API Parser : public Object {
public:

	Parser( InputStream* is );

	virtual ~Parser();

	void resetStream();

	void checkToken( const VCFChar& T );
    
	void checkTokenSymbol( const String& s );
    
	void error( const String& Ident );
    
	void errorStr( const String& Message);	
    
	VCFChar nextToken();
    
	long sourcePos();
    
	String tokenComponentIdent();
    
	double tokenFloat();
    
	long tokenInt();
    
	String tokenString();
    
	bool tokenSymbolIs(const String& s);

    long getSourceLine() {
		return sourceLine_;
	}

    VCFChar getToken(){
		return token_;
	}

	String binHexToString();

protected:
	InputStream* stream_;
    long origin_;
    VCFChar* buffer_;
	VCFChar* bufPtr_;
	VCFChar* bufEnd_;
	VCFChar* sourcePtr_;	
    VCFChar* sourceEnd_;
    VCFChar* tokenPtr_;
    VCFChar* stringPtr_;
    long sourceLine_;
    VCFChar saveChar_;
    VCFChar token_;
    
    void skipBlanks();
};


};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.7.4.1  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.7  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.6.4.1  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.6  2003/05/17 20:37:17  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.5.22.1  2003/03/12 03:11:50  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.5  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_PARSER_H__


