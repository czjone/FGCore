#ifndef __CORE_MACROS_H
#define __CORE_MACROS_H 1

#define FG_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define FG_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define FG_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)
#define BREAK_IF(cond)           if(cond) break
#define RETUERN_FAIL_IF(cond)    if(cond) return StateVal::UNKnowError

#define PROPERTY(_T_,NAME)                      \
    private:                                    \
        _T_ _##NAME;                            \
    public:                                     \
            inline _T_ &get_##NAME(){           \
				return _##NAME;                 \
            };                                  \
            inline void set_##NAME(_T_ val){    \
                this->##_##NAME = val;          \
    }                                           \

#define FG_ROOT_NS_NAME FG
#define FG_NS_BEGIN namespace FG_ROOT_NS_NAME {
#define FG_NS_END }
#define FG_NS_USING using namespace FG_ROOT_NS_NAME

#define FG_NS_EXT_NAME Extentions
#define FG_NS_EXT_BEGIN(_NS_) FG_NS_BEGIN namespace _NS_ {
#define FG_NS_EXT_END FG_NS_END }
#define FG_NS_EXT_USING(_NS_) FG_NS_USING;using namespace _NS_

#endif
