#ifndef _VCF_FORMAT_H__
#define _VCF_FORMAT_H__

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {

	/**

	*/
	class Format {
	public:
		
		Format( const String& fmtStr ): fmtStr_(fmtStr),currentPos_(0),
			expectedFormatArgCount_(0), currentFormatArgCount_(0){
			
			expectedFormatArgCount_ = countFormatTokens();
			
			currentPos_ = fmtStr_.find( "%" );
			if ( String::npos == currentPos_ ) {
				output_ += fmtStr_;
				fmtStr_.resize(0);
			}
		}
		
		//should we add virtual here for customizing the class???
		~Format() {
			
		}
		
		template<typename ValType>
			Format& operator% ( const ValType& val ) {
			currentFormatArgCount_  ++;
			
			VCF_ASSERT ( currentFormatArgCount_ <= expectedFormatArgCount_ );
			if ( currentFormatArgCount_ > expectedFormatArgCount_ ) {
				return *this;
			}
			
			if ( !fmtStr_.empty() ) {  
				if ( String::npos != currentPos_ ) {
					//look ahead and see if we have two consecutive %% chars
					//if so treat as one %
					if ( (fmtStr_.size() >= (currentPos_+1)) && (fmtStr_[currentPos_+1] == '%') ) {
						output_ += fmtStr_.substr(0, currentPos_ ); //just copy off the first "%" char
						fmtStr_.erase( 0, currentPos_+1 );//erase up the 2nd "%" pos
					}
					else { //we have to format this string
						int endPos = getNextFormatTokenEndPos( currentPos_ );
						
						output_ += fmtStr_.substr( 0, currentPos_ );
						fmtStr_.erase( 0, currentPos_ );
						String fmt;
						
						if ( String::npos != endPos ) {												
							fmt = fmtStr_.substr( 0, endPos-currentPos_ );			
							
							fmtStr_.erase( 0, endPos-currentPos_ );
						}
						else{
							fmt = fmtStr_;						
							fmtStr_.resize(0);
						}
						
						char tmp[256];
						sprintf( tmp, fmt.ansi_c_str(), val );
						output_ += tmp;
					}
				}
				else {
					output_ += fmtStr_;
					fmtStr_.resize(0);
				}
				
				currentPos_ = fmtStr_.find( "%" );
				if ( String::npos == currentPos_ ) {
					output_ += fmtStr_;
					fmtStr_.resize(0);
				}
			}		
			return *this;
		}
		
		
		
		operator String() const {
			//assert if the % operator wasn't called the correct number of times
			VCF_ASSERT ( currentFormatArgCount_ == expectedFormatArgCount_ );
			return output_;
		}


	protected:
		int countFormatTokens() const {
			int result = 0;
			String searchToken = "%";
			int pos = fmtStr_.find( searchToken );
			
			while ( pos != String::npos ) {
				if ( !( (fmtStr_.size() >= (pos+1)) && (fmtStr_[pos+1] == '%') ) ) {
					result ++;
				}
				pos = fmtStr_.find( searchToken, pos+1);
			}
			
			return result;
		}
		
		int getNextFormatTokenEndPos( int startPos ) const {  
			
			int result = String::npos;
			
			if ( fmtStr_[startPos] != '%' ) {
				return result;
			}
			
			
			//flags: "-+0 #"
			
			//width [1..9,0]*
			
			//precision ".[1..9,0]"
			
			//precision for int? "hlI64L"
			
			//type "cCdiouxXeEfgnpsS"
			
			
			String search = "-+0 #123456789*.hlI64LcCdiouxXeEfgnpsS";
			
			result = fmtStr_.find_first_not_of( search, startPos+1 );
			
			return result;
		}
	private:
		String fmtStr_;
		int currentPos_;
		String output_;
		int expectedFormatArgCount_;
		int currentFormatArgCount_;
	};

};




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2005/03/14 05:44:51  ddiego
*added the Formatter class as part of the process of getting rid of the var arg methods in System and StringUtils.
*
*/

#endif //_VCF_FORMAT_H__

