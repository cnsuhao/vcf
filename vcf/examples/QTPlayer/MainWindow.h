//MainWindow.h

#ifndef _MAINWINDOW_H__
#define _MAINWINDOW_H__


class QuickTimeMovie;
class QuickTimeControl;

namespace VCF {
	class Label;
	class DropTargetEvent;
};


/**
*Class MainQTWindow documentation
*/
class MainQTWindow : public VCF::Window { 
public:
	MainQTWindow();

	virtual ~MainQTWindow();	

protected:
	void onFileOpenMovie( VCF::Event* e );

	void onFileExit( VCF::Event* e );
	void onHelpAbout( VCF::Event* e );

	void onMoviePlay( VCF::Event* e );
	void onMovieReset( VCF::Event* e );
	void onMovieStop( VCF::Event* e );
	void onMoviePause( VCF::Event* e );

	void onViewNormal( VCF::Event* e );
	void onViewDouble( VCF::Event* e );
	void onViewHalf( VCF::Event* e );

	void onViewLockAspectRatio( VCF::Event* e );
	void onViewAllowResize( VCF::Event* e );

	void onViewSizeUpdate( VCF::Event* e );

	void onViewLockUpdate( VCF::Event* e );
	void onViewAllowResizeUpdate( VCF::Event* e );

	void onClose( VCF::WindowEvent* event );
	void onMovieChanged( VCF::Event* movieEvent );
	void onMovieFrameChanged( VCF::Event* movieEvent );

	void onDraggingOver( VCF::DropTargetEvent* e );
	void onFilesDropped( VCF::DropTargetEvent* e );

	QuickTimeControl* m_quicktimeControl;
	VCF::Label* m_timerLabel;
};


#endif //_MAINWINDOW_H__


