#ifndef FGCORE_COMMUNICATION_H
#define  FGCORE_COMMUNICATION_H 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <FGCore/Event.h>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <mutex>

FG_NS_BEGIN

namespace Communication {

	FG_NS_USING;

	enum Type{
		TCP ,
		// UDP = delete,
	};

	struct Node {
		int port;
		Type type;
		std::string host;
	};

	class Package {

	};

	class Handler {

	public:

		virtual ~Handler(void);

		virtual FG_State Handle(Package &pakage) = 0;
	};

	class Session : virtual public Dispatcher{

	public:

		enum EventType
		{
			ON_ERROR 		= 1,
			ON_CLOSED 		= 2,
			ON_RECIVED 		= 3,
			ON_TIME_OUT		= 4,
		};

		Session(void* _bllNetio);

		virtual ~Session(void);


	private:
		void* bllNetio;
	};

	class Client : virtual public Dispatcher{

	private:

		Session *session;
	
	public:

		enum EventType
		{
			ON_CONNECTED 	= 1,
			ON_DISCONNECT	= 2,
			ON_ERROR 		= 3,
			ON_CLOSED 		= 4,
			ON_RECIVED 		= 5,
			ON_TIME_OUT		= 6,
		};

		explicit Client(Node node);

		void Connect();

		void ConnectAsy();

		Session &getSession();
	};

	class Server : virtual public Dispatcher{

		public:

			enum EventType
			{
				ON_NEW_CLIENT_CONNECTED,
				ON_STOP,
				ON_START,
				ON_ERROR,
			};

			explicit Server(Node node);

			virtual ~Server();

			void StartAsy();

			void Start();

			void Stop();

		private:

			std::vector<Session*> sessions;

			Node mNode;

			mutable std::mutex sessionMut;
	};


}

FG_NS_END

#endif