//ComponentEditorManager.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//ComponentEditorManager.h
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ComponentEditor.h"
#include "vcf/ApplicationKit/ComponentEditorManager.h"

using namespace VCF;

ComponentEditorManager* ComponentEditorManager::componentEditorMgr = NULL;


ComponentEditorManager::ComponentEditorManager()
{

}

ComponentEditorManager::~ComponentEditorManager()
{
	std::map<String,ComponentEditor*>::iterator it = componentEditorMap_.begin();
	while ( it != componentEditorMap_.end() ) {
		delete it->second;
		it->second = NULL;
		it ++;
	}

	componentEditorMap_.clear();
}

ComponentEditor* ComponentEditorManager::findComponentEditor( const String& className )
{
	ComponentEditor* result = NULL;
	std::map<String,ComponentEditor*>::iterator found =
		ComponentEditorManager::componentEditorMgr->componentEditorMap_.find( className );
	if ( found != ComponentEditorManager::componentEditorMgr->componentEditorMap_.end() ) {
		result = found->second;
	}

	return result;
}

void ComponentEditorManager::registerComponentEditor( ComponentEditor* componentEditor, const String& className )
{
	ComponentEditorManager::componentEditorMgr->componentEditorMap_[className] = componentEditor;
}

void ComponentEditorManager::removeComponentEditor( const String& className )
{
	ComponentEditor* result = NULL;
	std::map<String,ComponentEditor*>::iterator found =
		ComponentEditorManager::componentEditorMgr->componentEditorMap_.find( className );
	if ( found != ComponentEditorManager::componentEditorMgr->componentEditorMap_.end() ) {
		delete found->second;
		ComponentEditorManager::componentEditorMgr->componentEditorMap_.erase( found );
	}
}

void ComponentEditorManager::initComponentEditorManager()
{
	ComponentEditorManager::componentEditorMgr = new ComponentEditorManager();
	ComponentEditorManager::componentEditorMgr->init();
}

void ComponentEditorManager::closeComponentEditorManager()
{

	if ( NULL != ComponentEditorManager::componentEditorMgr ) {
		delete ComponentEditorManager::componentEditorMgr;
	}
	ComponentEditorManager::componentEditorMgr = NULL;

}


/**
*CVS Log info
*$Log$
*Revision 1.3  2006/04/07 02:35:22  ddiego
*initial checkin of merge from 0.6.9 dev branch.
*
*Revision 1.2.6.2  2005/08/28 05:14:17  ddiego
*small changes to component editor class.
*
*Revision 1.2.6.1  2005/08/25 02:38:06  ddiego
*minor update to component editor manager.
*
*Revision 1.2  2004/08/07 02:49:06  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 03:43:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:15  ddiego
*migration towards new directory structure
*
*Revision 1.5  2003/05/17 20:37:47  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.2.2  2003/03/23 03:24:00  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4.2.1  2003/03/12 03:13:03  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.4  2003/02/26 04:30:55  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.3.14.1  2003/01/08 00:19:59  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.3  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.2.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.2  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


