//Processes.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"

/**
A brief example demonstrating how the Process class works
*/
using namespace VCF;



/**
This will demonstrate how to create a process
*/
void example1()
{
	//create a process object
	Process p1;

	//create a process

	p1.createProcess( "XCOPY", "/?" );
}


int main( int argc, char** argv ){

	FoundationKit::init( argc, argv );

	example1();


	FoundationKit::terminate();
	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.2.4.3  2004/04/29 03:10:55  marcelloptr
*reformatting of source files
*
*
*/


