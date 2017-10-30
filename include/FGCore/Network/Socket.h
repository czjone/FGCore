#ifndef __FGCORE_NETWORK_SOCKET
#define __FGCORE_NETWORK_SOCKET 1

#include <FGCore/Event.h>


namespace FGSocket {

	using namespace std;
	using namespace FGCore;

	class Session;
	class IOStream;
	class Client;
	class Server;
	class NetArgs;


	typedef enum {
		TCP,
	} Type;

	class IOStream {

	};

	class Package {

	};

	class Session : public EventDispatcher {

	};

	class Client {
	
	protected:
		
		Client();

	public:

		virtual ~Client(void);
	};

	class Server {

	public:
		typedef enum {
			ON_CLIENT_CONNECTED,
			ON_DISCONNECT,
			ON_SHUTDOWN,
			ON_ERROR,
		} EVENTType;
	
	protected:

		Server();

	public:
		
		virtual ~Server();

		virtual int Accept();
	};
};

#endif