#ifndef __FG_CORE_EVENT_H
#define __FG_CORE_EVENT_H 1

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
		events[type] = handler;
		itr = events[type];
	}
	itr.push_back(handler);
}

void EventDispatcher::removeEventlistener(int type,EventHandler* handler){
	EventList::iterator itr = events.find(type);
	if(itr == events.end()) return;
	itr.erase(handler);
}

 void EventDispatcher::Dispatch(void * args){
 	EventList::iterator itr = events.find(type);
 	if(itr == events.end()) return;
 	std::list<list> &evts = itr.second;
 	EventArgs eArgs;
 	eArgs.sender = this;
 	eArgs.args = args;
 	for(auto &eItr:evts){
 		eItr->handler(eArgs);
 	}
 }