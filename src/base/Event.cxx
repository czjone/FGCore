#include <FGCore/Event.h>

using namespace FGCore;

EventArgs::~EventArgs(void){

};

EventArgs::EventArgs(void *_sender,void *_args):
sender(_sender),
args(_args)
{

};

EventHandler::~EventHandler(){

}

void EventDispatcher::addEventlistener(int type,EventHandler * handler){
	EventList::iterator itr = events.find(type);
	if(itr == events.end()){
		std::list<EventHandler*> handlers;
		//events[type]= handler;
		events.insert(std::make_pair(type, handlers));
		itr = events.find(type);
	}
	(itr->second).push_back(handler);
}

void EventDispatcher::removeEventlistener(int type,EventHandler* handler){
	EventList::iterator itr = events.find(type);
	if(itr == events.end()) return;
	itr->second.remove(handler);
}

 void EventDispatcher::Dispatch(int type,void * args){
 	EventList::iterator itr = events.find(type);
 	if(itr == events.end()) return;
 	std::list<EventHandler*> &evts = itr->second;
 	EventArgs eArgs(this,args);
 	for(auto &eItr:evts) eItr->Handle(eArgs);
 }