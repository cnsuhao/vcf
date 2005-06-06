#ifndef _VCF_MENUMANAGER_H__
#define _VCF_MENUMANAGER_H__

//MenuManager.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#if _MSC_VER > 1000
#   pragma once
#endif





namespace VCF {

	class MenuManagerPeer;


	class APPLICATIONKIT_API MenuManager : public ObjectWithEvents{
	public:
		static void init();
		static void terminate();

		static MenuItemPeer* getMenuItemPeer( MenuItem* item );

		/**
		Register this frame with the menu manager
		so that it can take note of change to the
		window's menu bar and adjust accordingly
		*/
		static void registerWindow( Window* window );

		static void registerMenuBar( MenuBar* menuBar );

		static Menu* getMainMenu();
	protected:
		MenuManager();
		~MenuManager();

		static MenuManager* menuManager;

		Menu* mainMenu_;
		MenuManagerPeer* peer_;
		
		void onWindowActivated( Event* event );
		void onWindowClosed( Event* event );
		void onMenuItemChange( Event* event );
	};


};



#endif //_VCF_MENUMANAGER_H__

