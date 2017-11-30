#ifndef FGCORE_BASE64_H
#define FGCORE_BASE64_H 1

#include <FGCore/Macros.h>
#include <string>

FG_NS_BEGIN

namespace Base64 {
	
	typedef std::string String;
	
	static String Encode(const String& data);

	static String Decode(const String& data);
};

FG_NS_END

#endif