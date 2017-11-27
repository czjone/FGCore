#ifndef FGCORE_ERROR_H
#define FGCORE_ERROR_H 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <string>

FG_NS_BEGIN

    class Error {
    private:
        FG_State state;
        std::string message;

    public:
        Error(FG_State state,std::string msg);
        Error(FG_State state,const char* msg);

        inline FG_State getCode() {return this->state;};
        inline std::string getMsg(){return this->message;};
    };

FG_NS_END

#endif //FGCORE_ERROR_H
