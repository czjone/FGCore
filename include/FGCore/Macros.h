#ifndef FGCORE_MACROS_H
#define FGCORE_MACROS_H 1

#define FG_DELETE(p)                    do { delete (p); (p) = nullptr; } while(0)
#define FG_DELETE_ARRAY(p)              do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define FG_FREE(p)                      do { if(p) { free(p); (p) = nullptr; } } while(0)
#define FG_BREAK_IF(EXPRESS)            if(EXPRESS) break;

#define FG_ROOT_NS_NAME FG
#define FG_NS_BEGIN namespace FG_ROOT_NS_NAME {
#define FG_NS_END }
#define FG_NS_USING using namespace FG_ROOT_NS_NAME

#define FG_NS_EXT_NAME Extentions
#define FG_NS_EXT_BEGIN(_NS_) FG_NS_BEGIN namespace _NS_ {
#define FG_NS_EXT_END FG_NS_END }
#define FG_NS_EXT_USING(_NS_) FG_NS_USING;using namespace _NS_

#endif
