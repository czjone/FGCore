#ifndef FGCORE_TYPES_H
#define FGCORE_TYPES_H 1

/** A 64 - bit architecture and  32 - bit architecture for gcc 4.1*/

typedef unsigned  char 			FG_UByte;
typedef unsigned  char* 		FG_CSTRING;
typedef char 		   			FG_Byte;
typedef short 					FG_Short;
typedef int						FG_Int32;
typedef unsigned  char  		FG_UInt32;
typedef long long 				FG_Long;
typedef unsigned  long long 	FG_ULong;
typedef float					FG_Float;
typedef double 					FG_Double;
typedef FG_Int32 				FG_State;


/** errors */
#define FG_SUCCESS 				0x00000000
#define FG_UNKNOW_ERROR 		-0x00000001

#endif /*end FGCORE_TYPES_H*/
