#ifndef _VCF_URL_H__
#define _VCF_URL_H__


/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif

namespace VCF {

	class INTERNETKIT_API URL : public Object {
	public:

		enum UrlParts{
			upScheme = 0,
			upUser,
			upPassword,
			upHost,
			upPort,
			upUrlPath,
			upTotalCount
		};

		enum Events {
			evDataReceiving = 0x23123,
			evDataReceived,
			evStatusChanged,
			evAuthenticationRequested
		};


		DELEGATE( DataReceiving );
		DELEGATE( DataReceived );
		DELEGATE( StatusChanged );
		DELEGATE( AuthenticationRequested );

		URL(){}

		URL(const String& urlString ):data_(urlString){
			parse();
		}

		URL& operator=( const String& rhs ) {
			data_ = rhs;
			
			parse();

			return *this;
		}

		operator String() const {
			return data_;
		}

		String getURLString() const {
			return data_;
		}

		void download( OutputStream& stream ) {
			InternetToolkit::getDataFromURL( this, &stream );
		}

		void downloadToFile( const String& fileName ) {
			FileOutputStream fos(fileName);
			download( fos );
		}

		String getScheme() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upScheme];
		}

		String getUser() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upUser];
		}

		String getPassword() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upPassword];
		}

		String getHost() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upHost];
		}

		String getPort() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upPort];
		}

		String getUrlPath() const {
			std::vector<String> parts;
			parse( &parts );

			return parts[URL::upUrlPath];
		}


		std::vector<String> getParts() const {
			std::vector<String> result;
			
			parse( &result );

			return result;
		}

		bool validate() const {
			bool result = true;

			try {
				parse( NULL, true );
			}
			catch ( BasicException& e ) {
				StringUtils::trace( e.getMessage() + "\n" );
			}
			return result;
		}
	protected:
		String data_;

		virtual String parseScheme( String& data, bool validate=false ) const {
			String result ;
			int pos = data.find( "://" );
			if ( pos != String::npos ) {
				result = data.substr( 0, pos );
				data.erase( 0, pos + 3 );
			}

			return result;
		}

		void parse( std::vector<String>* parts=NULL, bool validate=false ) const {


			//based on the spec at RFC 1738
			//http://www.faqs.org/rfcs/rfc1738.html
			String scheme;
			String schemePart;
			String user;
			String pwd;
			String host;
			String port;
			String urlPath = "/";

			schemePart = data_;
			
			//strip out scheme
			scheme = parseScheme(schemePart);


			//strip out url path
			int pos = schemePart.find( "/" );
			if ( pos != String::npos ) {
				urlPath = schemePart.substr(pos,schemePart.size()-(pos));
				schemePart.erase( pos,schemePart.size()-pos);
			}


			pos = schemePart.find( "@" );

			if ( pos != String::npos ) {
				user = schemePart.substr(0,pos);
				schemePart.erase( 0, pos+1);

				pos = user.find( ":" );
				if ( pos != String::npos ) {
					pwd = user.substr(pos+1,user.size()-(pos+1));
					user.erase( pos+1,user.size()-(pos+1));
				}

				if ( validate ) {
					if ( String::npos != schemePart.find( "@" ) ) {
						//oops bad string! you've probable got a '@' in your password
						throw RuntimeException( "Bad URL string! You've probably got a '@' in your password" );
					}
				}
			}
			
			

			pos = schemePart.find( ":" );

			if ( pos != String::npos ) {				
				port = schemePart.substr(pos+1,schemePart.size()-(pos+1));
				schemePart.erase( pos,schemePart.size()-(pos));				
			}

			host = schemePart;

			if ( NULL != parts ) {
				std::vector<String>& tmp = *parts;

				parts->resize(URL::upTotalCount);

				tmp[URL::upScheme] = scheme;
				tmp[URL::upUser] = user;
				tmp[URL::upPassword] = pwd;
				tmp[URL::upHost] = host;
				tmp[URL::upPort] = port;
				tmp[URL::upUrlPath] = urlPath;
			}
		}
	};


	

	class URLAuthenticationEvent : public Event {
	public:
		URLAuthenticationEvent( URL* source ) : Event(source, URL::evAuthenticationRequested){}

		virtual Object* clone( bool deep=false ) {
			return new URLAuthenticationEvent(*this);
		}

		String getUserName() {
			return userName;
		}

		void setUserName( const String& val ) {
			userName = val;
		}

		String getPassword() {
			return password;
		}

		void setPassword( const String& val ) {
			password = val;
		}
	protected:
		String userName;
		String password;

	};

	class URLEvent : public Event {
	public:
		URLEvent( URL* source, ulong32 eventType ): 
		  Event(source,eventType),
			  bytesRecvd_(0),
			  cancelDataTransfer_(false){}

		URLEvent( const URLEvent& rhs ):
			Event(rhs),
			statusText_(rhs.statusText_), 
			bytesRecvd_(rhs.bytesRecvd_), 
			cancelDataTransfer_(rhs.cancelDataTransfer_){}
			
		
		virtual Object* clone( bool deep=false ) {
			return new URLEvent(*this);
		}

		String getStatusText() {
			return statusText_;
		}

		void setStatusText( const String& val ) {
			statusText_ = val;
		}

		uint32 getBytesReceived() {
			return bytesRecvd_;
		}

		void setBytesReceived( const uint32& val ) {
			bytesRecvd_ = val;
		}

		bool shouldCancelDataTransfer() {
			return cancelDataTransfer_;
		}

		void cancelDataTransfer() {
			cancelDataTransfer_ = true;
		}
	protected:
		String statusText_;
		uint32 bytesRecvd_;
		bool cancelDataTransfer_;
	};

	
	
	class URLException : public BasicException{
	public:
		URLException( const String & message ):
		  BasicException( message ){};
		  
		URLException( const String & message, const int lineNumber ):
		  BasicException(message, lineNumber){};
		  
		  virtual ~URLException() throw() {};
	};

};

#endif //_VCF_URL_H__

