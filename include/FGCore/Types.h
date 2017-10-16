#ifndef TYPES_H
#define TYPES_H 1

#include "Config.h"
//types
//#if(ARCHITECTURE_DEF==ARCHITECTURE_64)
//	typedef short 				Int32;
//	typedef int 				Int64;
//	typedef unsigned short 		UInt32;
//	typedef unsigned int 		UInt64;
//	typedef unsigned char* 		cstring;
//	typedef unsigned char		byte;
//	typedef unsigned char* 		bytes;
//	typedef bool		 		Bool;
//	typedef Int32				State;
//#else
	typedef int 				Int32;
	typedef long 				Int64;
	typedef unsigned int 		UInt32;
	typedef unsigned int 		UInt64;
	typedef unsigned char* 		cstring;
	typedef unsigned char		byte;
	typedef unsigned char* 		bytes;
	typedef bool		 		Bool;
	typedef Int32				State;
//#endif


	typedef enum {
		Success =				 0	,
		UNKnowError =			-1	,
	} StateVal;

#endif /*end TYPES_H*/
