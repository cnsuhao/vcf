
#ifndef _VCF_TEXTCODEC_H__
#define _VCF_TEXTCODEC_H__

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


namespace VCF {


/**
The TextCode class represents a way of transforming an ansi or unicode string 
into another form of unicode. It represents the logic required to make this 
transformation as specified in a code page, i.e. translating an ansi string 
into UTF16.
*/
class FRAMEWORK_API TextCodec {
public:
	/**
	converts a unicode string to an ansi string. The function will transform
	ansiStrBufferLength bytes of ansiStrBuffer to an ansii string. Null termination
	of the buffer passed into this function is <b>not</b> performed.
	@param UnicodeString the string to convert from
	@param UnicodeString::AnsiChar* the caller allocated buffer to put the 
	newly transformed ansi string data into. If this is NULL, then 
	the ansiStrBufferLength parameter is to be ignored, and the function
	should return the number of characters that would need to be allocated
	by the caller to successfully hold all of the ansi string.
	@param ulong32 the length of the ansiStrBuffer. The codec will put no more than this
	number of characters into the ansiStrBuffer.
	@return ulong32 the number of characters in the ansi string. Will be less than or
	equal to ansiStrBufferLength.
	*/
	virtual ulong32 convertToAnsiString( const UnicodeString& str, UnicodeString::AnsiChar* ansiStrBuffer, 
										const ulong32& ansiStrBufferLength ) = 0;

	/**
	Transforms a single Unicode character to an ansi character.
	*/
	virtual UnicodeString::AnsiChar convertToAnsiChar( const UnicodeString::UniChar& c ) = 0;

	/**
	Convert one unicode string into the code page type of this codec. 
	*/
	virtual UnicodeString convertToUnicodeString( const UnicodeString& str ) = 0;

	/**
	Converts an ansi string to a unicode string
	*/
	virtual UnicodeString convertToUnicodeString( const UnicodeString::AnsiChar* str, UnicodeString::size_type stringLength ) = 0;

	virtual String getName() = 0;

	/**
	This is a static function to be called in order to register a custom implementation 
	of the TextCodec class with the system's collection of codecs. The collection of codec's
	is a map that is keyed by the name of the codec.
	*/
	static void registerCodec( TextCodec* codec );

	/**
	A static method to retreive a registered codec, by name, from the system's
	collection of codecs.
	@param UnicodeString the name of the code to find
	@return TextCodec a codec that is associated with the codecName argument, or 
	NULL if no matching codec by that name can be found.
	*/
	static TextCodec* getCodec( const String& codecName );


	static void internal_freeAllRegisteredCodecs();

protected:
	static std::map<String,TextCodec*> registeredCodecsMap;
};




};




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.2.2.1  2004/04/26 21:58:49  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2004/04/03 15:48:42  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/16 04:00:30  ddiego
*added some missing files for locales
*
*/



#endif // _VCF_TEXTCODEC_H__



