#ifndef _VCF_MIMETYPE_H__
#define _VCF_MIMETYPE_H__


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
class MIMEType documentation
Specification for this MIME Types may be found at 
RFC 2045 http://www.faqs.org/rfcs/rfc2045.html.
*/
class FRAMEWORK_API MIMEType {
public: 
	typedef std::pair<String,String> Parameter;

	MIMEType();

	MIMEType( const String& data );

	MIMEType( const String& type, const String& subType );

	MIMEType( const String& type, const String& subType, const std::vector<Parameter>& parameters );

	

	operator String () const {
		return data_;
	}

	MIMEType& operator=( const String& rhs ) {
		data_ = rhs;
		return *this;
	}

	MIMEType& operator=( const FilePath& rhs ) {
		setFromFileName( rhs );
		return *this;
	}

	bool operator==( const MIMEType& rhs ) const {
		return compare( rhs );
	}

	bool operator!=( const MIMEType& rhs ) const {
		return !compare( rhs );
	}

	void setFromFileName( const String& fileName ) {
		setFromFileName( FilePath(fileName) );
	}


	String getType() const;

	String getSubType() const;

	std::vector<Parameter> getParameters() const;

	
	bool isTextType() const;

	bool isImageType() const;

	bool isAudioType() const;

	bool isVideoType() const;

	bool isApplicationType() const;


	static void registerExtension( const String& extension, const String& mimeType );

protected:
	static std::map<String,String> registeredFileExtensions;

	void setFromFileName( const FilePath& fileName );
	String data_;

	bool compare( const MIMEType& rhs ) const;

	static String canonicalValue( const String& value );
};




};




#endif // _VCF_MIMETYPE_H__



