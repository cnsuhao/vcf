////Dictionaries.cpp

#include "FoundationKit.h"
#include "utils/Dictionary.h"


using namespace VCF;




int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	Dictionary dict;

	dict["size"] = 200;
	dict["Name"] = "Bob";

	
	Dictionary::iterator it = dict.begin();	
	
	while ( it != dict.end() ) {
		Dictionary::pair& item = *it;

		System::println( "dict[\"%s\"] = %s", item.first.c_str(), item.second.toString().c_str() );
		
		it ++;
	}


	System::println( "Saving dictionary..." );

	{
		FileOutputStream fs("test.dict.txt");
		TextOutputStream tos(&fs);
		
		tos << &dict;
		
	}

	System::println( "Loading dictionary..." );

	{
		FileInputStream fs("test.dict.txt");
		TextInputStream tis(&fs);		
		
		dict.clear();
		
		tis >> &dict;
	}


	it = dict.begin();	
	
	while ( it != dict.end() ) {
		Dictionary::pair& item = *it;

		System::println( "dict[\"%s\"] = %s", item.first.c_str(), item.second.toString().c_str() );
		
		it ++;
	}


	FoundationKit::terminate();
	return 0;
}


