#ifndef FGCORE_URL_H
#define FGCORE_URL_H 1

#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <string>

FG_NS_BEGIN

namespace URL {
	
	typedef std::string String;

	String Encode(const String& url);

	String Decode(const String& encode);

}

FG_NS_END

#endif