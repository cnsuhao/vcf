//Controls.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "ControlsApplication.h"

#include "MainWindow.h"



using namespace VCF;



int main(int argc, char *argv[])
{
	Application* app = new ControlsApplication( argc, argv );


	Application::main();
	
	return 0;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/08/30 03:50:47  dougtinkham
*added copyright
*
*/