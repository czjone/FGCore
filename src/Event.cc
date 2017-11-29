#include <FGCore/Event.h>
#include <FGCore/Algorithm.h>

FG_NS_USING;

//--------------------------------------------------------------------------
//Handler:
//
//--------------------------------------------------------------------------
Handler::~Handler(void){

}


//--------------------------------------------------------------------------
//Dispatcher:
//
//--------------------------------------------------------------------------	
void Dispatcher::Dispatch(HandlerType type,void* arg) const {
	auto _itr = handlerList.find(type);
	if(_itr == handlerList.end()) return;
	mut.lock();
	auto evts = _itr->second; // Use a copy of the.
	mut.unlock();
	for(auto& evt:evts) evt->Handle((void*)this,arg);
}

void Dispatcher::AddEventlistener(HandlerType type, Handler *handler,FG_Boolean isOnce){
	mut.lock();
	auto _itr = handlerList.find(type);
	if(_itr == handlerList.end()){
		handlerList[type] = Handlers();
		_itr = handlerList.find(type);
	}
	_itr->second.push_back(handler);
	mut.unlock();
}

void Dispatcher::RemoveEventlistener(HandlerType type, Handler *handler){
	mut.lock();
	auto _itr = handlerList.find(type);
	if(_itr == handlerList.end())return;
	auto handlers = _itr->second;
	handlers.erase(remove(handlers.begin(),handlers.end(),handler),handlers.end());
	if(handlers.size()==0)handlerList.erase(type);
	mut.unlock();
}