#ifndef __fgame_core_config_h
#define __fgame_core_config_h 1

//define platform
#define FG_TARGET_PLATFORM 			0
#define FG_TARGET_PLATFORM_IOS 		1
#define FG_TARGET_PLATFOMR_MAC 		2
#define FG_TARGET_PLATFORM_ANDROID 	3
#define FG_TARGET_WIN 				4
#define FG_TARGET_LINUX 			5

#ifdef WIN32
#	undef FG_TARGET_PLATFORM
#	define FG_TARGET_PLATFORM FG_TARGET_WIN
#endif

#ifdef MAC
#	undef FG_TARGET_PLATFORM
#	define FG_TARGET_PLATFORM FG_TARGET_PLATFOMR_MAC
#endif

#ifdef IOS
#	undef FG_TARGET_PLATFORM
#	define FG_TARGET_PLATFORM FG_TARGET_PLATFORM_IOS
#endif

#ifdef ANDROID
#	undef FG_TARGET_PLATFORM
#	define FG_TARGET_PLATFORM FG_TARGET_PLATFORM_ANDROID
#endif

#ifdef LINUX
#	undef FG_TARGET_PLATFORM
#	define FG_TARGET_PLATFORM FG_TARGET_LINUX
#endif

using namespace std;

#endif
