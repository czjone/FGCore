#include <FGCore/Base64.h>
#include <FGCore/Macros.h>
#include <FGCore/Types.h>
#include <string>

FG_NS_USING;

using namespace Base64;

namespace Base64 {

	static FG_State base64_encode(const std::string &stdstr,std::string &outstr);

	static int base64_decode(const char* str, char* space, int size);

	String Encode(const String& data) {
		std::string outstr;
		auto ret = base64_encode(data, outstr);
		if(ret != FG_SUCCESS) printf("%s\n","base 64 encode data fail.");
		return outstr;
	}

	String Dcode(const String &data) {
		int len = data.length() * 2;
		char* out = (char*)malloc(len);
		int size = base64_decode(data.c_str(), out, len);
		std::string outstr(out,size);
		free(out);
		return outstr;
	}

	//base64 endcode table
	static char base64_table[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
			'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '\0' };

	static char str_pad = '='; //used the '=' to mark code stirng end.

	//in function malloc a memory need to user release it.
	FG_State base64_encode(const std::string &stdstr,std::string &outstr){
		char *result, *p;
		const char *str;
		size_t length = stdstr.length();
		str = stdstr.c_str();
		if (str == NULL || length < 1) return FG_FAIL;
		//4/3
		size_t taglen =  ((length + 2) / 3) * 4;
		result = (char *) malloc(taglen);
		p = result;
		if (result == NULL) return FG_FAIL;
		while (length > 2) {
			*result++ = base64_table[str[0] >> 2];
			*result++ = base64_table[((str[0] & 0x03) << 4) + (str[1] >> 4)];
			*result++ = base64_table[((str[1] & 0x0f) << 2) + (str[2] >> 6)];
			*result++ = base64_table[str[2] & 0x3f];
			length -= 3;
			str += 3;
		}
		if (length != 0) {
			*result++ = base64_table[str[0] >> 2];
			if (length > 1) {
				*result++ = base64_table[((str[0] & 0x03) << 4) + (str[1] >> 4)];
				*result++ = base64_table[(str[1] & 0x0f) << 2];
				*result++ = str_pad;  
			}
			else {
				*result++ = base64_table[(str[0] & 0x03) << 4];
				*result++ = str_pad;  
				*result++ = str_pad;  
			}
		}
		*result = '\0';
		outstr.append(result,taglen);
		return FG_SUCCESS;
	}

/* Base-64 decoding.  This represents binary data as printable ASCII
 ** characters.  Three 8-bit binary bytes are turned into four 6-bit
 ** values, like so:
 **
 ** [11111111] [22222222] [33333333]
 **
 ** [111111] [112222] [222233] [333333]
 **
 ** Then the 6-bit values are represented using the characters "A-Za-z0-9+/".
 */
static int b64_decode_table[256] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1, /* 00-0F */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 10-1F */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, /* 20-2F */
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, /* 30-3F */
		-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, /* 40-4F */
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, /* 50-5F */
		-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, /* 60-6F */
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, /* 70-7F */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 80-8F */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 90-9F */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* A0-AF */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* B0-BF */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* C0-CF */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* D0-DF */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* E0-EF */
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 /* F0-FF */
};

/* Do base-64 decoding on a string. Ignore any non-base64 bytes.
 ** Return the actual number of bytes generated. The decoded size will
 ** be at most 3/4 the size of the encoded, and may be smaller if there
 ** are padding characters (blanks, newlines).
 */
int base64_decode(const char* str, char* space, int size) {
	const char* cp = NULL;
	int space_idx = 0, phase = 0;
	int d = 0, prev_d = 0;
	unsigned char c;
	space_idx = 0;
	phase = 0;
	for (cp = str; *cp != '\0'; ++cp) {
		d = b64_decode_table[(int) *cp];
		if (d != -1) {
			switch (phase) {
			case 0:
				++phase;
				break;
			case 1:
				c = ((prev_d << 2) | ((d & 0x30) >> 4));
				if (space_idx < size)
					space[space_idx++] = c;
				++phase;
				break;
			case 2:
				c = (((prev_d & 0xf) << 4) | ((d & 0x3c) >> 2));
				if (space_idx < size)
					space[space_idx++] = c;
				++phase;
				break;
			case 3:
				c = (((prev_d & 0x03) << 6) | d);
				if (space_idx < size)
					space[space_idx++] = c;
				phase = 0;
				break;
			}
			prev_d = d;
		}
	}
	return space_idx;
}
}

