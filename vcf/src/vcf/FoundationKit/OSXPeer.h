
/**
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
 
#ifndef _VCF_OSXPEER_H__
#define _VCF_OSXPEER_H__
 

namespace VCF {

	class OSXUtils {
	public:
		static String getErrorString( int errorCode );
	};

    


#define vcf_IntToFixed(a)	   ((Fixed)(a) << 16)
#define vcf_FixedToInt(a)	   ((int)(a) >> 16)

class FixedPointNumber {
public:
	FixedPointNumber() : val_(0){	
	}
	
	FixedPointNumber( Fixed val ) : val_(val){}
	
	FixedPointNumber( const double val ) {
		*this = val;
	}
	
	FixedPointNumber& operator=( Fixed rhs ) {
		val_ = rhs;
		return *this;
	}
	
	FixedPointNumber& operator=( const double& rhs ) {
		assign ( rhs );	
		return *this;
	}
	
	FixedPointNumber& operator=( const float& rhs ) {
		assign ( rhs );	
		return *this;
	}
	
	void assign( const double& val ) {
		int fractional = (val - floor(val)) * 0xffff;
	
		val_ = vcf_IntToFixed((int)(floor(val))) | fractional;
	}
	
	void assign( const int& val ) {	
		val_ = vcf_IntToFixed(val);
	}
	
	int asInt() const {
		return vcf_FixedToInt(val_);
	}
	
	double asDouble() const {
		return (double)vcf_FixedToInt(val_) + ((double)(0xFFFF)/(double)(0xFFFF0000 & val_));
	}
	
	operator double () const {
		return asDouble();
	}
	
	operator Fixed () const {
		return val_;
	}
protected:
	Fixed val_;
};



class CFTextString {
public:
	CFTextString() : cfStringRef(nil), unicodeText(NULL){
		
	}
	
	CFTextString( const String& s ) : cfStringRef(nil), unicodeText(NULL){
		assign( s );
	}
    
    CFTextString( CFStringRef s ) : cfStringRef(nil), unicodeText(NULL){
		assign( s );
	}
	
	~CFTextString() {
		cleanup();
	}
	
	CFTextString& operator=( const String& s ) {
		assign( s );
		return *this;
	}
    
    CFTextString& operator=( CFStringRef s ) {
		assign( s );
		return *this;
	}
	
	int length() const {
		return CFStringGetLength( cfStringRef );
	}
	
	void assign( const String& s ) {
		cleanup();
		cfStringRef = CFStringCreateWithCString( NULL, s.c_str(), CFStringGetSystemEncoding() );
		
		buildUnicodeBuffer();
	}
    
    void assign( CFStringRef s ) {
		cleanup();
        
		cfStringRef = CFStringCreateCopy( NULL, s );
		
		buildUnicodeBuffer();
	}
	
    
    
	CFStringRef ref() const {
		return cfStringRef;
	}
	
	operator CFStringRef () const {
		return cfStringRef;
	}
	
    operator String () const {
        String result = CFStringGetCStringPtr( cfStringRef, CFStringGetSystemEncoding() );
        
        return result;
    }
    
	const UniChar* c_str() const {
		return unicodeText;
	}
	
	operator UniChar* () {
		return unicodeText;
	}
	
	operator const UniChar* () const {
		return unicodeText;
	}
	
protected:
	void cleanup()	{
		if ( NULL != unicodeText ) {
			delete [] unicodeText;
		}
		
		if ( nil != cfStringRef ) {
			CFRelease(cfStringRef);
		}
		cfStringRef = nil;
		unicodeText = NULL;		
	}
	
	void buildUnicodeBuffer() {
		int length = CFStringGetLength( cfStringRef );
		unicodeText = new UniChar[length+1];
		CFRange range = {0,length};	
		CFStringGetCharacters(cfStringRef,range,unicodeText);
		unicodeText[length] = 0;
	}
	CFStringRef cfStringRef;
	UniChar* unicodeText;
	
private:
		CFTextString( const CFTextString& rhs );
		CFTextString& operator=( const CFTextString& rhs );
};


        
};
 
 
/**
*CVS Log info
 *$Log$
 *Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
 *migration towards new directory structure
 *
 *Revision 1.3.2.1  2004/04/26 21:58:43  marcelloptr
 *changes for dir reorganization: _VCF_MACRO_H__
 *
 *Revision 1.3  2004/04/03 15:48:42  ddiego
 *Merged over code from the 0-6-3 branch.
 *
 *Revision 1.2.6.3  2004/02/25 05:17:55  ddiego
 *updates to ApplicationKit to support posting events and timer and idle time handlers for the OSX UI Toolkit.
 *
 *Revision 1.2.6.2  2004/02/24 01:42:43  ddiego
 *initial OSX ApplicationKit port checkin
 *
 *Revision 1.2.6.1  2004/02/21 03:27:06  ddiego
 *updates for OSX porting
 *
 *Revision 1.2  2003/05/17 20:37:12  ddiego
 *this is the checkin for the 0.6.1 release - represents the merge over from
 *the devmain-0-6-0 branch plus a few minor bug fixes
 *
 *Revision 1.1.2.1  2003/05/15 03:01:01  ddiego
 *added initial osx source( FoundationKit only),
 *plus some fixes to compile under GCC 3.x compilers
 *
 */
 
   
#endif // _VCF_OSXPEER_H__
 
 
 