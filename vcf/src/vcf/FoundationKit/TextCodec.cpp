/**
Copyright (c) 2000-2004, Jim Crafton
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

//TextCodec.cpp


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/TextCodec.h"

using namespace VCF;


std::map<String,TextCodec*> TextCodec::registeredCodecsMap;



void TextCodec::registerCodec( TextCodec* codec )
{
	TextCodec::registeredCodecsMap[codec->getName()] = codec;
}

TextCodec* TextCodec::getCodec( const String& codecName )
{
	TextCodec* result = NULL;
	std::map<String,TextCodec*>::iterator found = TextCodec::registeredCodecsMap.find( codecName );
	if ( found != TextCodec::registeredCodecsMap.end() ) {
		result = found->second;
	}

	return result;
}

void TextCodec::internal_freeAllRegisteredCodecs()
{
	std::map<String,TextCodec*>::iterator it = TextCodec::registeredCodecsMap.begin();
	while ( it != TextCodec::registeredCodecsMap.end() ) {
		delete it->second;
		it++;
	}
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.2  2004/04/03 15:48:50  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.2  2004/02/16 05:34:05  ddiego
*updated linux makefiles as a result of new locale support - pushed in stubs for locale peer impl, but no functionality at this point
*
*Revision 1.1.2.1  2004/02/16 04:00:49  ddiego
*added some missing files for locales
*
*/




