//SketchIt.cpp


#include "ApplicationKit.h"
#include "SketchDocument.h"
#include "SketchWindow.h"
#include "SketchView.h"
#include "SketchTools.h"


using namespace VCF;




class SketchIt : public SDIDocumentBasedApplication {
public:

	virtual void terminateRunningApplication() {
		SDIDocumentBasedApplication::terminateRunningApplication();

		ToolManager::terminate();
	}

	virtual bool initRunningApplication(){
		REGISTER_CLASSINFO( SketchDocument );
		REGISTER_CLASSINFO( SketchWindow );
		REGISTER_CLASSINFO( SketchView );

		bool result = SDIDocumentBasedApplication::initRunningApplication();
		
		ToolManager::init();

		DocumentManager* docMgr = DocumentManager::getDocumentManager();
		docMgr->DocumentInitialized += new GenericEventHandler<SketchIt>( this, 
																			&SketchIt::onDocInitialized,
																			"SketchIt::onDocInitialized" );

		newDefaultDocument();
		
		return result;
	}

	void onDocInitialized( Event* e ) {
		Document* doc = (Document*)e->getSource();
		
		
		
		static bool firstTime = true;
		
		if ( firstTime )  {
			MenuBar* menuBar = doc->getWindow()->getMenuBar();
			
			MenuItem* root = menuBar->getRootMenuItem();
			MenuItem* view = new DefaultMenuItem( "&View", root, menuBar );
			MenuItem* viewAA = new DefaultMenuItem( "&Anti-Aliased", view, menuBar );

			viewAA->addMenuItemClickedHandler( 
				new MenuItemEventHandler<SketchIt>( this, 
													&SketchIt::onToggleAntiAliasing,
													"SketchIt::onToggleAntiAliasing" ) );

			viewAA->addMenuItemUpdateHandler( 
				new MenuItemEventHandler<SketchIt>( this, 
													&SketchIt::onUpdateToggleAntiAliasing,
													"SketchIt::onUpdateToggleAntiAliasing" ) );


			MenuItem* tools = new DefaultMenuItem( "&Tools", root, menuBar );
			
			MenuItem* toolsSelect = new DefaultMenuItem( "&Select", tools, menuBar );
			
			MenuItem* toolsLine = new DefaultMenuItem( "&Line", tools, menuBar );
			
			ToolManager::getToolManager()->setCurrentControl( doc->getWindow() );
			
			Tool* tool = new SelectTool();
			
			ToolManager::getToolManager()->registerTool( tool, toolsSelect );
			
			tool = new LineTool();
			ToolManager::getToolManager()->registerTool( tool, toolsLine );
		
			MenuItem* toolsXForm = new DefaultMenuItem( "&Transform", tools, menuBar );
			MenuItem* toolsXFormRotate = new DefaultMenuItem( "&Rotate", toolsXForm, menuBar );
			MenuItem* toolsXFormScale = new DefaultMenuItem( "&Scale", toolsXForm, menuBar );
			MenuItem* toolsXFormSkew = new DefaultMenuItem( "S&kew", toolsXForm, menuBar );
			
			tool = new RotateTool();
			ToolManager::getToolManager()->registerTool( tool, toolsXFormRotate );

			ToolManager::getToolManager()->registerTool( new ScaleTool(), toolsXFormScale );

			ToolManager::getToolManager()->registerTool( new SkewTool(), toolsXFormSkew );
			
		}

		firstTime = false;
	}

	void onToggleAntiAliasing( MenuItemEvent* e ) {
		getMainWindow()->setUsingRenderBuffer( !getMainWindow()->isUsingRenderBuffer() );	
		GraphicsContext* ctx = getMainWindow()->getContext();
		if ( getMainWindow()->isUsingRenderBuffer() ) {
			ctx->setDrawingArea( *getMainWindow()->getClientBounds() );
		}

		getMainWindow()->repaint();
	}

	void onUpdateToggleAntiAliasing( MenuItemEvent* e ) {
		MenuItem* item = (MenuItem*)e->getSource();
		item->setChecked( getMainWindow()->isUsingRenderBuffer() );
	}
};


int main(int argc, char *argv[])
{
	SketchIt app;

	Application::main( argc, argv );
	
	return 0;
}


