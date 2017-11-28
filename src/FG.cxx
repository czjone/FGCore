#include <FGCore/FG.h>
#define FG_CORE_VERSION_CODE 1
#define FG_CORE_VERSION_NAME "0.0.1"

FG_NS_BEGIN

FG_Int32 get_version_code(){
	return FG_CORE_VERSION_CODE;
}
FG_CSTRING get_version_name(){
	return FG_CORE_VERSION_NAME;
}

FG_NS_END