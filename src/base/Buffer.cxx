#include <FGCore/Buffer.h>

using namespace FGCore;

Buffer::Buffer(){
	ptr = (char*)malloc(BUF_MIN_SIZE);
}


Buffer::~Buffer(){
	free(ptr);
	this->ptr = nullptr;
}