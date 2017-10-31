#include <FGCore/stream.h>
#include <FGCore/Buffer.h>

using namespace FGCore;

istream::istream(Buffer *buf):buffer(buf){

}

istream::~istream(void){

}
ostream::ostream(Buffer *buffer):buffer(buffer){

}

ostream::~ostream(void){

}

iostream::iostream(Buffer* buf):istream(buf),ostream(buf){

}

iostream::~iostream(void){

}

fstream::fstream(const char* path, MODEL = MODEL::ADW){

}

fstream::~fstream(void){

}

 void fstream::flush(){

}

 void fstream::close(){

}

 void fstream::discarded(){

}
