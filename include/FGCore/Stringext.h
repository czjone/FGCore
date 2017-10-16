#ifndef STRINGEXT_H
#define STRINGEXT_H 1

#include <vector>
#include <string>
#include <FGCore/Config.h>

namespace FGCore{
	class StrTool{
	public:
		static std::string tolower(const std::string &val);
		static std::string touper(const std::string &val);
		static std::vector<std::string> split(std::string& str, std::string& splitstr);

		static std::string& replace_first(std::string &str, const  std::string &old_value, const  std::string &new_value);
		static std::string& replace_all(std::string &str, const  std::string &old_value, const  std::string &new_value);
		static std::string& replace_all_distinct(std::string &str, const  std::string &old_value, const  std::string &new_value);

#if ARC_WINDOWS
		static char* w2c(char *pcstr, const wchar_t *pwstr, size_t len);
		static void c2w(wchar_t *pwstr, size_t len, const char *str);
		static wchar_t* ctow(wchar_t *pwstr, const char *str)  = delete ; //内在管理有问题，不能直接 使用。

#endif
	};
}

#endif
