#include <vcf/FoundationKit/FoundationKit.h>
#include <vcf/GraphicsKit/GraphicsKit.h>
#include <vcf/ApplicationKit/ApplicationKit.h>
#include <vcf/OpenGLKit/OpenGLKit.h>

#include "ParticleEditor.h"

class ParticleEditorApplication:public VCF::Application{
public:
	ParticleEditorApplication(int argc,char **argv):VCF::Application(argc,argv){};

	virtual ~ParticleEditorApplication(){};

	virtual bool initRunningApplication(){
		bool result=Application::initRunningApplication();

		VCF::Window *window=new ParticleEditor();

 		setMainWindow(window);
		window->setVisible(true);

		return result;
	}
};

int main(int argc, char **argv){
 	VCF::FoundationKit::init(argc,argv);
	VCF::GraphicsKit::init(argc,argv);
	VCF::ApplicationKit::init(argc,argv);
	VCF::OpenGLKit::init(argc,argv);

	ParticleEditorApplication *app=new ParticleEditorApplication(argc,argv);

	app->main();
	
	return 0;
}

/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/11/01 17:19:00  marcelloptr
*just added few lines at the end of file
*
*Revision 1.1.2.1  2004/11/01 14:38:59  pallindo
*Initial checkin of the particle editor example.  Just shows off a more complex opengl application using the VCF.
*
*/


