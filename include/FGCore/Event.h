#ifndef __FGCORE_EVENT_H
#define __FGCORE_EVENT_H 1

#include <functional>
#include <map>
#include <list>

namespace FGCore {

	using namespace std;

	class EventDispatcher;

	class EventArgs{

	public:

		virtual ~EventArgs(void);

	protected:

		EventArgs(void *_sender,void *_args);

	public:
		template<class T>
		inline T& getArgs(void) const{
			T& val = *(dynamic_cast<T*>(this->args));
			return val;
		};

		template<class T> 
		T& getSender(void) const{
			T& val = *(dynamic_cast<T*>(this->args));
			return val;
		}

	private:
		
		void *sender;

		void *args;
	};

	class EventHandler {

	public:

		virtual ~EventHandler();

	protected:

		virtual void Handle(const EventArgs& arg) = 0 ;
	};

	class EventDispatcher {

	public:

		void addEventlistener(int ,EventHandler * handler);

		void removeEventlistener(int,EventHandler* handler);

	protected:

		virtual void Dispatch(void* args);

	private:

		typedef std::map<int,std::list<EventHandler*> > EventList;
		
		EventList events;

	};
}

#endif