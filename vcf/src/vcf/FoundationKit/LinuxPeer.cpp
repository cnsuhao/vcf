/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.5  2003/05/17 20:37:34  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.14.1  2003/03/23 03:23:57  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4  2002/05/27 22:52:34  ddiego
*added two new tests for testing File and System support in the FoudnationKit
*and verified that they work in Linux. Fixed associated code in getting that to
*work.
*
*Revision 1.3  2002/05/27 15:58:22  ddiego
*added linux peer classes for the FoundationKit port to linux
*this now means the FoundationKit will start up correctly on
*linu thought it is still not 100% functional yet
*
*Revision 1.2  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.4.1  2002/03/26 04:46:34  cesarmello
*Linux headers
*
*Revision 1.1  2002/01/28 02:07:59  cesarmello
*Linux file peer
*
*/

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

//LinuxPeer.cpp
#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


using namespace VCF;
using namespace VCFLinux;


String LinuxUtils::getErrorString( const int& errorCode )
{
	String result;
	//error string based on linux man page docs
	//assumes
	switch ( errorCode ) {
		case EFAULT: {
    	result = "Path points outside your accessible address space.";
		}
		break;

		case EACCES: {
    	result = "Write access to the directory containing the pathname is not allowed\n"\
								"for hte process's effective uid, or one of the directories in the pathname\n"\
								"did not allow search (execute) permission.";
		}
		break;

		case EPERM: {
    	result = "The directory that is represented by the path name has the sticky bit set\n"\
								"and the process's effective uid is neither the uid of the file to be deleted\n"\
								"nor that of the directory containing it.";
			
		}
		break;


		case ENAMETOOLONG: {
    	result = "The pathname was too long.";
		}
		break;

		case ENOENT: {
    	result = "A directory component in the pathname does not exist or is a dangling symbolic link.";
		}
		break;

		case ENOTDIR: {
    	result = "A component used as a directpy in a path is not, in fact, a directory.";
		}
		break;

		case ENOMEM: {
    	result = "Insufficient kernel memory.";
		}
		break;

		case EROFS: {
    	result = "Path refers to a file that is read-only.";
		}
		break;

		case EEXIST: {
    	result = "Path refers to a file that already exists.";
		}
		break;

		case EISDIR: {
    	result = "Path refers to a file that is a directory and write access was requested.";
		}
		break;

		case ENXIO: {
    	result = "O_NONBLOCK or O_WRONLY is set, the named file is a FIFO and no\n"\
								"process has the file open for reading. Or, the file is a device\n"\
								"special file and no corresponding device exists.";
		}
		break;

		case ENODEV: {
    	result = "Path refers to a device special file and no corresponding device exists.";
		}
		break;

		case ELOOP: {
    	result = "Too many symbolic links were were encountered in resolving the pathname\n"\
								"or O_NOFOLLOW was specified but the path was a symbolic link.";
		}
		break;

		case ENFILE: {
    	result = "The limit on the number of open file handles was reached for the OS.";
		}
		break;

		case EMFILE: {
    	result = "The limit on the number of open file handles for the process was reached.";
		}
		break;
	}
	return result;	
}


