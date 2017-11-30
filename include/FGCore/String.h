#ifndef FGCORE_STRING_H
#define FGCORE_STRING_H 1
#include <FGCore/Config.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <string>
#include <vector>

FG_NS_BEGIN

FG_NS_USING;

namespace StringHelper{

	typedef std::string String;

	static String ToMd5(const String& rawStr);
	static String ToBase64Decode(const String& rawStr);
	static String ToBase64Encode(const String& rawStr);
	static String ToUrlEncode(const String& rawStr);
	static String ToUrlDecode(const String& rawStr);

	static String tolower(const std::string &val);
	static std::string touper(const std::string &val);
	static std::vector<String> split(std::string& str, std::string& splitstr);
	static String& replace_first(std::string &str, const  std::string &old_value, const  std::string &new_value);
	static String& replace_all(std::string &str, const  std::string &old_value, const  std::string &new_value);
	static String& replace_all_distinct(std::string &str, const  std::string &old_value, const  std::string &new_value);

#if FG_TARGET_PLATFORM == FG_TARGET_WIN 
		/*static void chr2wch(const char* buffer, wchar_t* wBuf);
		static void wch2chr(char* buffer, wchar_t* wBuf);*/
		static char* w2c(char *pcstr, const wchar_t *pwstr, size_t len);
		static void c2w(wchar_t *pwstr, size_t len, const char *str);
		// static wchar_t* ctow(wchar_t *pwstr, const char *str)  = delete ;
#endif

};

FG_NS_END

#endif