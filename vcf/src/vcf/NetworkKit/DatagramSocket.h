/*
 * DatagramSocket is a thin wrapper around the socket using
 * connectionless oriented protocol.
 * -- by Ning Ke
 */

#ifndef _VCF_DATAGRAMSOCKET_H__
#define _VCF_DATAGRAMSOCKET_H__

namespace VCFNet
{

class NETKIT_API DatagramSocketPeer
{
public:
	virtual ~DatagramSocketPeer() {};
	virtual int setRemoteHost(const VCF::String &, const int &) = 0;
	virtual int send(const char *, const int &) = 0;
	virtual int recv(char *, int &) = 0;
	virtual VCF::String getRemoteHostName() = 0;
	virtual int getRemoteHostPort() = 0;
};


class NETKIT_API DatagramSocket : public VCF::Object {
public:
	DatagramSocket();
	DatagramSocket(const int &);
	DatagramSocket(const VCF::String &, const int &);
	virtual ~DatagramSocket();
	// Sender must set remote address before it can send data.
	int setRemoteHost(const VCF::String &, const int &);
	int send(const char *, const int &);
	int recv(char *, int &);
	// returns the name and port of the local socket's address.
	VCF::String getLocalHostName() ;
	int getLocalHostPort() ;
	// return the name and port of the address the socket is connected to.
	VCF::String getRemoteHostName() ;
	int getRemoteHostPort() ;
	bool isInitialized(int &);
	bool isInitialized(VCF::String &);

protected:
	int port_;
	VCF::String host_;
	DatagramSocketPeer *peer_;	
};
};

#endif // _VCF_DATAGRAMSOCKET_H__


