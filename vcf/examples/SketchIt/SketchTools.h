/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2003/07/17 03:02:46  ddiego
*added sketch example
*
*/



#ifndef _SKETCHTOOLS_H__
#define _SKETCHTOOLS_H__


class Tool : public VCF::ObjectWithEvents {
public:

	Tool() : currentControl_(NULL){

	}

	void attach( VCF::Control* control );

	VCF::Control* detach();


	virtual void paintState( VCF::GraphicsContext* ctx ) {}

	virtual void onMouseDown( VCF::MouseEvent* e ) {

	}

	virtual void onMouseMove( VCF::MouseEvent* e ) {

	}

	virtual void onMouseUp( VCF::MouseEvent* e ) {

	}

	virtual void onKeyPressed( VCF::KeyboardEvent* e ) {

	}

	virtual void onKeyDown( VCF::KeyboardEvent* e ) {

	}

	virtual void onKeyUp( VCF::KeyboardEvent* e ) {

	}

protected:
	VCF::Control* currentControl_;
};



/**
class ToolManager documentation
*/
class ToolManager : public VCF::ObjectWithEvents {
public: 
	
	void registerTool( Tool* tool, VCF::MenuItem* item );

	Tool* getCurrentTool() {
		return currentTool_;
	}

	VCF::Control* getCurrentControl() {
		return currentControl_;
	}

	void setCurrentControl( VCF::Control* val ) {
		currentControl_ = val;
	}

	

	static void init();
	static void terminate();

	static ToolManager* getToolManager();
protected:
	static ToolManager* manager;
	std::map<VCF::MenuItem*,Tool*> toolMap_;
	Tool* currentTool_;
	VCF::Control* currentControl_;
	void onMenuItemClicked( VCF::MenuItemEvent* e );
	void onMenuItemUpdate( VCF::MenuItemEvent* e );
private:
	ToolManager();
	virtual ~ToolManager();
};


class Shape;



/**
class SelectTool documentation
*/
class SelectTool : public Tool{
public: 
	SelectTool();
	virtual ~SelectTool();

	virtual void onMouseDown( VCF::MouseEvent* e );

	virtual void onMouseMove( VCF::MouseEvent* e );

	virtual void onMouseUp( VCF::MouseEvent* e );

	virtual void paintState( VCF::GraphicsContext* ctx );
protected:
	Shape* mouseOverShape_;
	Shape* hitTest( VCF::Point& pt );
	VCF::Point startDragPoint_;
	VCF::Point dragPoint_;
};



/**
class LineTool documentation
*/
class LineTool : public Tool {
public: 
	LineTool();
	virtual ~LineTool();

	virtual void onMouseDown( VCF::MouseEvent* e );

	virtual void onMouseMove( VCF::MouseEvent* e );

	virtual void onMouseUp( VCF::MouseEvent* e );
protected:
	VCF::Point start_;
	VCF::Point end_;
};


class RotateTool : public Tool {
public:
	virtual void paintState( VCF::GraphicsContext* ctx );

	virtual void onMouseDown( VCF::MouseEvent* e );

	virtual void onMouseMove( VCF::MouseEvent* e );

	virtual void onMouseUp( VCF::MouseEvent* e );
protected:
	VCF::Point startDragPoint_;
	VCF::Point dragPoint_;
	double startAngle_;
};


#endif //_SKETCHTOOLS_H__



