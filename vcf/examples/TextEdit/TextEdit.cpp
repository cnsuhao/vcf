//TextEdit.cpp


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ControlsKit.h"
#include "TextEditDocument.h"
#include "TextEditWindow.h"
#include "FindDialog.h"
#include "ReplaceDialog.h"



using namespace VCF;





class TextEdit : public SDIDocumentBasedApplication {
public:

	TextEdit( int argc, char *argv[] ) : SDIDocumentBasedApplication(argc,argv) {

	}

	FindInfo currentFindInfo_;
	ReplaceInfo currentReplaceInfo_;


	void onFind( VCF::MenuItemEvent* e )	{
		TextEditDocument* currentDoc = (TextEditDocument*)getCurrentDocument();
		currentFindInfo_.position_ = currentDoc->getSelectionStart();

		if ( currentDoc->getSelectionLength() > 0 ) {			
			currentFindInfo_.searchString_ = currentDoc->getText().substr( currentFindInfo_.position_, currentDoc->getSelectionLength() );
		}

		FindDialog* dlg = new FindDialog();
		dlg->caseSensitive_ = currentFindInfo_.caseSensitive_;
		dlg->matchWordOnly_ = currentFindInfo_.matchWordOnly_;
		dlg->searchStrings_ = currentFindInfo_.searchStrings_;
		dlg->searchString_ = currentFindInfo_.searchString_;
		dlg->setFrameTopmost( true );
		dlg->showModal();
		dlg->free();

	}

	void onUpdateFind( VCF::MenuItemEvent* e ) {
		

	}

	void onReplace( VCF::MenuItemEvent* e )	{
		TextEditDocument* currentDoc = (TextEditDocument*)getCurrentDocument();
		if ( NULL != currentDoc ) {
			currentReplaceInfo_.position_ = currentDoc->getSelectionStart();
			
			if ( currentDoc->getSelectionLength() > 0 ) {			
				currentReplaceInfo_.searchString_ = currentDoc->getText().substr( currentReplaceInfo_.position_, currentDoc->getSelectionLength() );
			}
		}
		
		ReplaceDialog * dlg = new ReplaceDialog();
		
		
		dlg->caseSensitive_ = currentReplaceInfo_.caseSensitive_;
		dlg->matchWordOnly_ = currentReplaceInfo_.matchWordOnly_;
		dlg->searchStrings_ = currentReplaceInfo_.searchStrings_;
		dlg->searchString_ = currentReplaceInfo_.searchString_;
		
		dlg->replaceStrings_ = currentReplaceInfo_.replaceStrings_;
		dlg->replaceString_ = currentReplaceInfo_.replaceString_;
		
		dlg->setFrameTopmost( true );
		dlg->showModal();
		dlg->free();
	}

	void onUpdateReplace( VCF::MenuItemEvent* e ) {

	}

	virtual bool initRunningApplication(){

		REGISTER_CLASSINFO( TextEditDocument );
		//REGISTER_CLASSINFO( TextEditView );
		REGISTER_CLASSINFO( TextEditWindow );

		bool result = SDIDocumentBasedApplication::initRunningApplication();	
		if ( result ) {
			/**
			add additional menu items	
			*/
			
			MenuItem* root = getStandardMenu()->getRootMenuItem();
			MenuItem* edit = root->findChildNamedSimilarTo( "edit" );
			ulong32 editCount = edit->getChildCount();
			
			
			MenuItem* find = new DefaultMenuItem( "&Find...\tCtrl+F" );	
			find->setAcceleratorKey( vkLetterF, kmCtrl );
			find->addMenuItemClickedHandler( 
				new MenuItemEventHandler<TextEdit>(this, &TextEdit::onFind, "TextEdit::onFind") );
			
			find->addMenuItemUpdateHandler( 
				new MenuItemEventHandler<TextEdit>(this, &TextEdit::onUpdateFind, "TextEdit::onUpdateFind") );
			
			
			
			DefaultMenuItem* replace = new DefaultMenuItem( "&Replace...\tCtrl+H" );	
			replace->setAcceleratorKey( vkLetterH, kmCtrl );
			
			replace->addMenuItemClickedHandler( 
				new MenuItemEventHandler<TextEdit>(this, &TextEdit::onReplace, "TextEdit::onReplace") );
			
			replace->addMenuItemUpdateHandler( 
				new MenuItemEventHandler<TextEdit>(this, &TextEdit::onUpdateReplace, "TextEdit::onUpdateReplace") );
			

			DefaultMenuItem* sep = new DefaultMenuItem( "" );
			sep->setSeparator( true );
			
			//why -2? Becasue we want to be above the preferences item and the separator 
			//directly above it
			edit->insertChild( editCount-2, sep );
			editCount ++;
			
			edit->insertChild( editCount-2, find );
			editCount ++;		
			
			edit->insertChild( editCount-2, replace );
			editCount ++;
			
			
			newDefaultDocument();
			
			DocumentManager* docMgr = DocumentManager::getDocumentManager();
			docMgr->DocumentInitialized += 
				new GenericEventHandler<TextEdit>( this, &TextEdit::onDocInitialized, "TextEdit::onDocInitialized" );
			
		}
		return result;
	}

	virtual void terminateRunningApplication() {
		SDIDocumentBasedApplication::terminateRunningApplication();

		
	}

	void onDocInitialized( Event* e ) {
		Document* doc = (Document*)e->getSource();		

	}
};


int main(int argc, char *argv[])
{
	Application* app = new TextEdit( argc, argv );

	Application::main();
	
	return 0;
}

