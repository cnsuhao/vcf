//Controls.cpp


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


