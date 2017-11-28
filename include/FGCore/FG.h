#ifndef FGCORE_H
#define FGCORE_H 1

#	include <FGCore/Config.h>
#	include <FGCore/Data.h>
#	include <FGCore/Error.h>
#	include <FGCore/Log.h>
#	include <FGCore/Macros.h>
#	include <FGCore/Types.h>

FG_NS_BEGIN

FG_Int32 get_version_code();
FG_CSTRING get_version_name();

FG_NS_END

#endif