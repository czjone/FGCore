#include <FGCore/Network/Socket.h>
#include <iostream>

static const char send_msg[] = "The quick brown fox jumps over the lazy dog";

using namespace FGSocket;
using namespace NET;

Client::Client(){

}
 Client::~Client(void){

 }

Server::Server(){

}

Server::~Server(){

}

int Server::Accept(){
	return -1;
}