#ifndef _VCF_WIN32FILESTREAM_H__
#define _VCF_WIN32FILESTREAM_H__
//Win32FileStream.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


namespace VCF
{

class Win32FileStream : public FileStreamPeer
{
public:
	Win32FileStream( const String& filename, const FileStreamAccessType& accessType );

	Win32FileStream( File* file );

	virtual ~Win32FileStream();

	virtual void seek( const unsigned long& offset, const SeekType& offsetFrom );

	virtual unsigned long getSize();

	virtual unsigned long read( unsigned char* bytesToRead, unsigned long sizeOfBytes );

	virtual unsigned long write( const unsigned char* bytesToWrite, unsigned long sizeOfBytes );

	virtual char* getBuffer();
private:
	HANDLE fileHandle_;
	VCF::String filename_;
	File* file_;
	DWORD translateAccessType( const FileStreamAccessType& accessType );
	DWORD translateAccessTypeToCreationType( const FileStreamAccessType& accessType );
	DWORD translateSeekTypeToMoveType( const SeekType& offsetFrom );
};


};


#endif // _VCF_WIN32FILESTREAM_H__

/**
$Id$
*/
