#ifndef __FGCORE_BUFFER_H
#define __FGCORE_BUFFER_H 1

namespace FGCore {
	
	#define BUF_MIN_SIZE  8

	class Buffer {
	public:

		Buffer();

		virtual ~Buffer(void);

		template<class T>
		inline Buffer& operator <<(const T& t) {
			char* bytes = (char*)(t);
			size_t size = sizeof(T);
			this->write(bytes,size);
			return *this;
		};

		template<class T> 
		inline  Buffer& operator >> (T& t){
			char * bytes = (char*)t;
			size_t size = sizeof(T);
			this -> write (bytes,size);
		};

		inline Buffer& write(char* bytes,size_t size) {
			this->check_cap(size);
			memcpy(bytes,this->ptr + this-> pos , size);
			this->pos += size;
		};

		inline Buffer& resize(size_t size) {
			if(size > this->cap) {
				char* _ptr = (char*)malloc(this->cap = size);
				memcpy(_ptr,ptr,this->size);
				free(ptr);
				ptr = _ptr;
			}
			return *this;
		}

		inline size_t size(){ return this->size_t; }

		inline bool eof(){ return this->pos >= this->size; }

		inline bool setPos(size_t pos){
			if(pos < 0 || pos >= this->size) {
				return false;
			}else {
				this->pos = pos;
				return true;
			}
		};

	protected:

		inline Buffer& check_cap(size_t needsize){
			while(this->cap < this->pos + needsize){
				this->resize(this->cap * 2);
			}
		};

	private:
		size_t pos;
		size_t size;
		size_t cap;
		char* ptr;
	};
}

#endif