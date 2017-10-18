#ifndef __FG_CORE_NETWORK_H
#	define __FG_CORE_NETWORK_H 1
#   include <Core/Macros.h>
#   include <Core/Types.h>
#   include <ostream>
#   include <istream>

#   define NET_WORK_NS Network

FG_NS_EXT_BEGIN(NET_WORK_NS)

class Netio {

public:
	class Package :
	 	basic_istream<char>
	{
		
		friend class Netio;

	public:
		
		Package();

		virtual ~Package(void);

		template<class T>
		Pakage& operator <<(const T & t){
			basic_istream<<t;
			return *this;
		};

	protected:
		
		size_t GetSize(void) const;

		const char* Get_Str(void) const;

	};

public:

	typedef void(*)(void* _this,int error) ErrorHandler;

	typedef void(*)(void* _this,Pakage &package) ReciveHandler;

	virtual ~Netio(void);

	virtual void Close() = 0;

	Netio & operator << (const Package & package);

	void operator >> (Package & package);

protected:

	virtual size_t Write(const char* bytes,size_t len) = 0;

};

#endif