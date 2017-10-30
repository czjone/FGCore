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
	
	protected:

		Server();

	public:
		
		virtual ~Server();

		virtual int Accept();
	};
};

#endif