#ifndef __FGCORE_STREAM_H
#define __FGCORE_STREAM_H 1

#include <FGCore/Buffer.h>

namespace FGCore {
	class istream {
	public:
		explicit istream(Buffer *buf);
		virtual ~istream(void);

		template<class T>
		inline istream& read (const T &t){
			return *(buffer) >> t;
		};

		inline istream& read(char* bytes,size_t size){ buffer->read(bytes,size); } ;
		inline size_t size() {return buffer->size();};
		inline bool eof() {return buffer->eof();};
		inline void setPos(size_t pos ){buffer.setPos(pos);};
		inline istream& operator  >> (int &val) { this->read(val); };
		inline istream& operator  >> (long &val) { this->read(val); };
		inline istream& operator  >> (double &val) { this->read(val); };
		inline istream& operator  >> (long long &val) { this->read(val); };
		inline istream& operator  >> (float& val) { this->read(val); };
	
	private:
		Buffer *buffer;

	};

	class ostream {
	public:
		explicit ostream(Buffer *buffer);
		virtual ~ostream(void);

		template<class T> 
		inline ostream &write(const T& t) {
			(*buffer) << t;
			return *this;
		};

		inline void setPos(size_t pos ){buffer->setPos(pos);};
		inline ostream& write(const char* bytes,size_t size) { buffer->write(bytes,size); };

		inline ostream& operator << (const int &val) { this->write(val); };
		inline ostream& operator << (const long &val) { this->write(val); };
		inline ostream& operator << (const double &val) { this->write(val); };
		inline ostream& operator << (const long long &val) { this->write(val); };
		inline ostream& operator << (const float &val) { this->write(val); };

	private:
		Buffer *buffer;
	};

	class iostream :
		virtual public istream,
		virtual public ostream
	{
	public:
		explicit iostream(Buffer* buf);
		virtual ~iostream(void);
	};

	class fstream: virtual public iostream {

	public:

		typedef enum  { 
			ONLY_READ 	=  	0x01 << 1,
			ONLY_WRITE 	= 	0x02 < 2,
			ADW 		= 	0x03 << 3 | 0x01 << 1 | 0x02 < 2,
		} MODEL;

		explicit fstream(const char* path, MODEL = MODEL::ADW);

		virtual ~fstream(void);

		virtual void flush();

		virtual void close();

		virtual void discarded();
	}; 
}

#endif