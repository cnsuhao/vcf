#if     _MSC_VER > 1000
#pragma once
#endif




#ifndef _VCF_FILEPATH_H__
#define _VCF_FILEPATH_H__

/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

//FilePath.h



namespace VCF {

	class FRAMEWORK_API FilePath : public VCF::Object {
	public:

		enum {
			DirectorySeparator	= L'/',
			ExtensionCharacter	= L'.',
			DriveSeparator		= L':'
		};

		FilePath();

		FilePath( const String& filename );

		FilePath( const FilePath& filePath );

		virtual ~FilePath();


		static String getDirectorySeparator() {
			return L"/";
		}

		static String getDriveSeparator();

		static String getExtensionSeparator() {
			return L".";
		}
		
		static bool isPathDirectory( const String& path );

		inline FilePath& operator= ( const FilePath& path ){
			filename_ = path.filename_;
			convertToNative(filename_);
			return *this;
		}


		inline FilePath& operator= ( const String& filename ) {
			filename_ = filename;
			convertToNative(filename_);
			return *this;
		}


		inline operator String () const {
			return filename_;
		}


		inline operator String& () {
			return filename_;
		}


		bool empty() const {
			return filename_.empty();
		}

		

		/**
		*returns an extension. The extension is the 
		*<b><i>last</i></b> occurence of the "." to the end
		*of the filename string. For example:<br>
		*If the filename is : "foo/bar/baz.1.2a.text" then 
		*the return value will be ".text"
		*@return String the file name extension including the "." character. 
		*If no extension is found returns an empty string
		*/
		String getExtension() const ;



		/**
		*returns the name component of the filename (i.e without
		*path information )
		*@param true to include the extension in the name
		*/
		String getName( const bool& includeExtension=false ) const;



		/**
		*returns the drivename for filesystems that support them (i.e. 
		*VMS and Win32) on 'nix systems this returns an empty string
		*The 'DriveSeparator' character is excluded
		*/
		String getDriveName() const;


		/**
		*returns the directory portion of the file name including
		*the 'DirectorySeparator' character at the end
		*/
		String getPathName( const bool& includeDriveName=false ) const;


		bool doesFileExist() const;

		bool isRelativePath() const;

		/**
		*returns true if the filename is a directory name (i.e.
		*with the 'DirectorySeparator' character at the end )
		*/
		bool isDirectory() const;

		/**
		*returns the filename converted to the native format ('nix)
		*The filename may not be a full path name
		*/
		String getFileName() const{
			return filename_;
		}

		/**
		*returns the filename converted to the format specific for the OS
		*The filename may not be a full path name
		*/
		String transformToOSSpecific() const;

		/**
		*returns the pathname relative to the working path
		*@param the working path.
		*If not given then working path information is retrieved 
		*from the system
		*/
		String transformToRelativePathName( const String& workingPath="" ) const;

		/**
		*expand a relative pathname into a full pathname based on the 
		*working path
		*@param the working path.
		*If not given then working path information is retrieved 
		*from the system
		*/
		String expandRelativePathName( const String& workingPath=L"" ) const;

		/**
		*returns a vector with all the subdirectory components of the pathname,
		*each one of them with the 'DirectorySeparator' character at the end
		*/
		std::vector<String> getPathComponents() const {
			return separatePathComponents( getPathName() );
		}

	protected:
		std::vector<String> separatePathComponents( const String& path ) const;

		void convertToNative( String& filename ) const;		

		String filename_;

	};

};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.5.4.2  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5.4.1  2004/04/21 02:17:23  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.5  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.4.4.4  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.4.4.3  2003/09/19 21:24:21  ddiego
*small changes
*
*Revision 1.4.4.2  2003/09/02 02:11:14  ddiego
*fixed some glitches in drag drop. also cleaned up the drag drop event
*classes. Began some fixes to the html browser implementation on Win32
*
*Revision 1.4.4.1  2003/08/23 12:44:22  marcelloptr
*improved comments in FilePath
*
*Revision 1.4  2003/05/17 20:37:16  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.10.2  2003/03/23 03:23:53  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.10.1  2003/03/12 03:11:50  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.2.4.4  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.2.4.3  2002/07/16 04:23:18  ddiego
*modified FilePath to get the drivename and path name in one fucntion
*will correctly ignore the drive separator in non WIN32 systems
*mods ot VCFBuilder to load external projects within a workspace
*using relative paths ! - this needs to be migrated over to xmake
*as well
*
*Revision 1.2.4.2  2002/07/15 04:06:14  ddiego
*fixing saving the various project file ot take advantage to relative path
*and the FilePath object
*
*Revision 1.2.4.1  2002/07/14 05:40:01  ddiego
**** empty log message ***
*
*Revision 1.2  2002/06/24 04:24:49  ddiego
*mods to VCFBuilder
*
*Revision 1.1  2002/06/18 21:18:32  ddiego
*added FilePath
*/



#endif // _VCF_FILEPATH_H__


