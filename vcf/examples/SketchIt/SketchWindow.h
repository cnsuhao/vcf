/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2003/07/17 03:02:46  ddiego
*added sketch example
*
*/


#ifndef _SKETCHWINDOW_H__
#define _SKETCHWINDOW_H__


#define SKETCHWINDOW_CLASSID		"e035e1bd-f375-4b97-9736-710c17e672c8"

/**
class SketchWindow documentation
*/
class SketchWindow : public VCF::Window {
public: 
	BEGIN_CLASSINFO( SketchWindow, "SketchWindow", "VCF::Window", SKETCHWINDOW_CLASSID )
	END_CLASSINFO( SketchWindow )


	SketchWindow();
	virtual ~SketchWindow();


protected:

	void onDocInitialized( VCF::Event* e ) ;
};



#endif //_SKETCHWINDOW_H__



