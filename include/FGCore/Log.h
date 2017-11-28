#ifndef FGCORE_LOG_H
#define FGCORE_LOG_H

#include <FGCore/Macros.h>

#define LOG_TAG "FG PRINT"

FG_NS_BEGIN

    inline void _logd(const char * format, ...) {};

    inline void _loge(const char * format, ...) {};

    inline void _save_e(const char * format, ...) { };

    inline void logd(const char * format, ...)
    {
        // va_list args;
        // va_start(args, format);
        // _logd(format, args);
        // va_end(args);
    };

    inline void loge(const char * format, ...)
    {
        // va_list args;
        // va_start(args, format);
        // _loge(format, args);
        // va_end(args);
    };

    inline void save_e(const char * format, ...)
    {
        // va_list args;
        // va_start(args, format);
        // save_e(format, args);
        // va_end(args);
    };

FG_NS_END

#ifdef DEBUG
#   define FGLOG_D(FORMAT,...)           FG::logd(FORMAT,##__VA_ARGS__)
#   define FGLOG_E(FORMAT,...)           FG::loge(FORMAT,##__VA_ARGS__)
#   define FGASSERT(EXP,FORMAT,...)     if(!EXP)FG::loge(FORMAT,##__VA_ARGS__)
#else
#   define FGLOG_D(FORMAT,...)
#   define FGLOG_E(FORMAT,...)           FG::save_e(FORMAT,##__VA_ARGS__)
#   define FGASSERT(FORMAT,...)         if(!EXP)FG::save_e(FORMAT,##__VA_ARGS__)
#endif

#endif //FGCORE_LOG_H
