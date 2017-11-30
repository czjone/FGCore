#ifndef FGCORE_LOG_H
#define FGCORE_LOG_H

#include <FGCore/Macros.h>

FG_NS_BEGIN

//     inline void _logd(const char * format, ...) {};

//     inline void _loge(const char * format, ...) {};

//     inline void _save_e(const char * format, ...) { };

//     inline void logd(const char * format, ...)
//     {
//         // va_list args;
//         // va_start(args, format);
//         // _logd(format, args);
//         // va_end(args);
//     };

//     inline void loge(const char * format, ...)
//     {
//         // va_list args;
//         // va_start(args, format);
//         // _loge(format, args);
//         // va_end(args);
//     };

//     inline void save_e(const char * format, ...)
//     {
//         // va_list args;
//         // va_start(args, format);
//         // save_e(format, args);
//         // va_end(args);
//     };

// FG_NS_END

// #ifdef DEBUG
// #   define FGLOG_D(FORMAT,...)           FG::logd(FORMAT,##__VA_ARGS__)
// #   define FGLOG_E(FORMAT,...)           FG::loge(FORMAT,##__VA_ARGS__)
// #   define FGASSERT(EXP,FORMAT,...)     if(!EXP)FG::loge(FORMAT,##__VA_ARGS__)
// #else
// #   define FGLOG_D(FORMAT,...)
// #   define FGLOG_E(FORMAT,...)           FG::save_e(FORMAT,##__VA_ARGS__)
// #   define FGASSERT(FORMAT,...)         if(!EXP)FG::save_e(FORMAT,##__VA_ARGS__)
// #endif


#if ANDROID
#   include <android/log.h>
#   define  SDK_LOG_TAG    "FG Framework"
#   if DEBUG
#       define  FGLOG_D(...)  __android_log_print(ANDROID_LOG_DEBUG,SDK_LOG_TAG,__VA_ARGS__)
#   else
#       define  FGLOG_D(...)
#   endif
#   define  FGLOG_E(...)  __android_log_print(ANDROID_LOG_DEBUG,SDK_LOG_TAG,__VA_ARGS__)
#else
#   include <stdio.h>
#   include <stdlib.h>
//c99
#   define FGLOG_D(format, ...)    fprintf(stdout, format, ##__VA_ARGS__)
#   define FGLOG_E(format, ...)    fprintf(stdout, format, ##__VA_ARGS__)
//gcc
//# define LOG(format, args...) fprintf(stdout, format, ##args)
#endif

// #   define LOG(format, ...)                                   \
// printf("[my tag] ");                                         \
// LOG(format, ##__VA_ARGS__);                                     \
// printf("\n")
// #endif
FG_NS_END
#endif //FGCORE_LOG_H
