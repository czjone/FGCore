#include <FGCore/Communication.h>
#include <clsocket/src/ActiveSocket.h>
#include <clsocket/src/PassiveSocket.h>

using namespace FG;
using namespace Communication;

//--------------------------------------------------------------------------
//Package:
//
//--------------------------------------------------------------------------
//class Package { };


//--------------------------------------------------------------------------
//Handler:
//
//--------------------------------------------------------------------------
 Communication::Handler::~Handler(void){

}

//--------------------------------------------------------------------------
//Session:
//
//--------------------------------------------------------------------------
Communication::Session::Session(void* _bllNetio):
bllNetio(_bllNetio){

}

Communication::Session::~Session(void){
	delete ((CActiveSocket*)(this->bllNetio));
}

//--------------------------------------------------------------------------
//Client:
//
//--------------------------------------------------------------------------
Communication::Client::Client(Node node){

}

void Communication::Client::Connect(){

}

void Communication::Client::ConnectAsy(){

}

Session &Communication::Client::getSession(){
	return *(this->session);
}


//--------------------------------------------------------------------------
//Server:
//
//--------------------------------------------------------------------------
Communication::Server::Server(Node node):mNode(node){
	
}

Communication::Server::~Server(){

}

void Communication::Server::StartAsy(){

}

void Communication::Server::Start(){
	Node &n = this->mNode;
	switch(n.type) {
		case Communication::Type::TCP:{
			CPassiveSocket socket;
			CActiveSocket *pClient = nullptr;

			socket.Initialize();
			socket.Listen(n.host.c_str(), n.port);
			while (true) {
			    if ((pClient = socket.Accept()) != nullptr)
			    {
			        Session *_session = new Session((void*)pClient);
			        sessionMut.lock();
			        this->sessions.push_back(_session);
			        sessionMut.unlock();
			    }
			}
			break;
		}
		default:
			break;
	}
}

void Communication::Server::Stop(){

}