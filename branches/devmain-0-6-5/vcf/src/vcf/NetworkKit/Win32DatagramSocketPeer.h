#ifndef _VCF_WIN32DATAGRAMSOCKETPEER_H__
#define _VCF_WIN32DATAGRAMSOCKETPEER_H__

namespace VCFNet
{

class Win32DatagramSocketPeer : public DatagramSocketPeer 
{
public:
	Win32DatagramSocketPeer(DatagramSocket *);
	Win32DatagramSocketPeer(DatagramSocket *, const int &);
	Win32DatagramSocketPeer(DatagramSocket *, const VCF::String &, const int &);
	~Win32DatagramSocketPeer();
	bool startup();
	virtual int setRemoteHost(const VCF::String &, const int &);
	virtual int send(const char *, const int &);
	virtual int recv(char *, int &);
	virtual VCF::String getRemoteHostName() ;
	virtual int getRemoteHostPort() ;

private:
	DatagramSocket *socket_;
	int port_;
	VCF::String host_;
	int remoteHostPort_;
	VCF::String remoteHostName_;
	SOCKET sock_;
	struct sockaddr_in localHostAddr_;
	struct sockaddr_in remoteHostAddr_;
};

};

#endif // _VCF_WIN32DATAGRAMSOCKETPEER_H__


