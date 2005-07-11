////CommonDirectories.cpp

#include "vcf/FoundationKit/FoundationKit.h"

using namespace VCF;


/**
This is a trivial program to show how to retreive
common directories.
*/
int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	String dir;

	System::println( Format("Get information for User: %s on computer: %s\n") 
						% System::getUserName() 
						% System::getComputerName() );

	dir = System::getCommonDirectory( System::cdUserHome );	
	System::println( Format("System::cdUserHome: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdUserProgramData );	
	System::println( Format("System::cdUserProgramData: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdUserDesktop );	
	System::println( Format("System::cdUserDesktop: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdUserFavorites );	
	System::println( Format("System::cdUserFavorites: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdUserDocuments );	
	System::println( Format("System::cdUserDocuments: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdUserTemp );	
	System::println( Format("System::cdUserTemp: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdSystemPrograms );	
	System::println( Format("System::cdSystemPrograms: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdSystemTemp );	
	System::println( Format("System::cdSystemTemp: %s\n") % dir );

	dir = System::getCommonDirectory( System::cdSystemRoot );	
	System::println( Format("System::cdSystemRoot: %s\n") % dir );


	FoundationKit::terminate();
	return 0;
}


