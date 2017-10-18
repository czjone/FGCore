#ifndef __FG_SOCKET_H
#define __FG_SOCKET_H 1
#   include <Core/Macros.h>
#   include <Core/Types.h>
#   include <ostream>
#   include <istream>

#   define NET_WORK_NS Network

FG_NS_EXT_BEGIN( NET_WORK_NS )

class Package :
 	basic_istream<char>
{
	
	friend class Netio;

public:
	
	Package();

	virtual ~Package(void);

	template<class T>
	Pakage& operator <<(const T & t){
		basic_istream<<t;
		return *this;
	};

protected:
	
	size_t GetSize(void) const;

	const char* Get_Str(void) const;

};

class Handler {

public:
	
	virtual ~Handler();

protected:

	virtual void Handle(Package &pakage) = 0;

};


class Channel {
public:
	Client();

   ~Socket();

   bool isValid();

   int getHandle();

private:
	
   int clientId;
};

class Client
{
public:
   Client(std::string host,int port);

   ~Client();

   bool IsValid();

   int GetChannel();
};

class Server
{
public:
   
   ServerSocket(int port) throw(SocketException);
   
   ~ServerSocket();

   bool isValid();
  
private:
   int socketHdlM; // handle of the server socket
};

FG_NS_EXT_END

#endif