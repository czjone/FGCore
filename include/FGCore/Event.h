#ifndef FGCORE_EVENT_H
#define FGCORE_EVENT_H 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <map>
#include <mutex>
#include <vector>

FG_NS_BEGIN


typedef FG_Int32 HandlerType;

class Dispatcher;

class Handler {
	friend class Dispatcher;
public:
	
	virtual ~Handler(void);

protected:

	virtual FG_State Handle(void* sender,void* arg) = 0;
};

class Dispatcher {

private:
	
	typedef std::vector<Handler*> Handlers;
	
	typedef std::map<HandlerType, Handlers> HandlerList;

	HandlerList handlerList;

	mutable std::mutex mut;

public:
	
	void Dispatch(HandlerType type,void* arg) const;

	void AddEventlistener(HandlerType type, Handler *handler,FG_Boolean isOnce = FG_False);

	void RemoveEventlistener(HandlerType type, Handler *handler);

};

FG_NS_END

#endif