
#ifndef _VCF_INTERNETTOOLKIT_H__
#define _VCF_INTERNETTOOLKIT_H__

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF {
	class URL;

	class INTERNETKIT_API InternetToolkit {
	public:
		static void getDataFromURL( URL* url, OutputStream* stream ) {
			InternetToolkit::inetKitInstance->internal_getDataFromURL( url, stream );
		}

		static void create();

		static void terminate();
	protected:
		virtual ~InternetToolkit(){}
		InternetToolkit(){};

		static InternetToolkit* inetKitInstance;

		virtual void internal_getDataFromURL( URL* url, OutputStream* stream ) = 0; 

	private:		
		InternetToolkit(const InternetToolkit&);
		InternetToolkit& operator=(const InternetToolkit&);

	};
};

#endif //_VCF_INTERNETTOOLKIT_H__


