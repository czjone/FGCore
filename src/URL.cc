#include <FGCore/URL.h>
#include <iostream>
#include <stdio.h>

namespace URL {

	static unsigned char char_to_hex(unsigned char x) {
		return (unsigned char) (x > 9 ? x + 55 : x + 48);
	}

	static int is_alpha_number_char(unsigned char c) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9'))
			return 1;
		return 0;
	}

	std::string Encode(std::string url) {
		unsigned char ch;
		int len = 0;
		const char * src = url.c_str();
		int src_len = url.length();

		int buflen = url.length() * 3;
		char* p =  (char*)malloc(buflen);

		char * dest = (char*)p;
		int dest_len = buflen;

		while (len < (dest_len - 4) && *src) {
			ch = (unsigned char) *src;
			if (*src == ' ') {
				*dest++ = '+';
			} else if (is_alpha_number_char(ch) || strchr("=!~*'()", ch)) {
				*dest++ = *src;
			} else {
				*dest++ = '%';
				*dest++ = char_to_hex((unsigned char) (ch >> 4));
				*dest++ = char_to_hex((unsigned char) (ch % 16));
			}
			++src;
			++len;
		}

		std::string encode((char*)p,len);
		*dest = 0;
		free(p);
		return encode;
	}

	void Decode(unsigned char * src, int src_len, unsigned char * dest,
			int dest_len) {
		unsigned char ch;
		int len = 0;

		while (len < (dest_len - 4) && *src) {
			ch = (unsigned char) *src;
			if (*src == ' ') {
				*dest++ = '+';
			} else if (is_alpha_number_char(ch) || strchr("=!~*'()", ch)) {
				*dest++ = *src;
			} else {
				*dest++ = '%';
				*dest++ = char_to_hex((unsigned char) (ch >> 4));
				*dest++ = char_to_hex((unsigned char) (ch % 16));
			}
			++src;
			++len;
		}
		*dest = 0;
		return;
	}

	// url decode
	std::string urldecode(std::string encode) {
		int j, i;
		char *cd = (char*) encode.c_str();
		char *decd = (char*)malloc(encode.length());
		char p[2];
		unsigned int num;
		j = 0;

		for (i = 0; i < encode.length(); i++) {
			memset(p, '\0', 2);
			if (cd[i] != '%') {
				decd[j++] = cd[i];
				continue;
			}

			p[0] = cd[++i];
			p[1] = cd[++i];

			p[0] = p[0] - 48 - ((p[0] >= 'A') ? 7 : 0) - ((p[0] >= 'a') ? 32 : 0);
			p[1] = p[1] - 48 - ((p[1] >= 'A') ? 7 : 0) - ((p[1] >= 'a') ? 32 : 0);
			decd[j++] = (unsigned char) (p[0] * 16 + p[1]);

		}
		decd[j] = '\0';

		std::string decode(decd, j);
		free(decd);
		return decode;
	}

	// url encode
	unsigned char* urldecode(unsigned char* encd, unsigned char* decd) {
		int j, i;
		char *cd = (char*) encd;
		char p[2];
		unsigned int num;
		j = 0;

		for (i = 0; i < strlen(cd); i++) {
			memset(p, '\0', 2);
			if (cd[i] != '%') {
				decd[j++] = cd[i];
				continue;
			}

			p[0] = cd[++i];
			p[1] = cd[++i];

			p[0] = p[0] - 48 - ((p[0] >= 'A') ? 7 : 0) - ((p[0] >= 'a') ? 32 : 0);
			p[1] = p[1] - 48 - ((p[1] >= 'A') ? 7 : 0) - ((p[1] >= 'a') ? 32 : 0);
			decd[j++] = (unsigned char) (p[0] * 16 + p[1]);

		}
		decd[j] = '\0';

		return decd;
	}
}
//int main()
//{
//	 //char *s00 = "data={\"version\":\"1\",\"token\":\"9F6B77DC1AABAFBAD461239AB55E4578\",\"uid\":\"407775551EC4736C60D9ABFA8E300540\",\"server_id\":\"20000\",\"pid\":\"tencentmsdkandroid\",\"nikename\":\"{\"openkey\":\"9F6B77DC1AABAFBAD461239AB55E4578\",\"pay_token\":\"2B876D24EF0A28A7C32DD7BDDBE4BDFF\",\"pf\":\"desktop_m_qq-10000144-android-10000144-qq-1000001292-407775551EC4736C60D9ABFA8E300540\",\"session_id\":\"openid\",\"appid\":\"1000001292\",\"session_type\":\"kp_actoken\",\"openid\":\"407775551EC4736C60D9ABFA8E300540\",\"pfkey\":\"06e6b01dd9055b5996ab88eab8e9645b\",\"ip\":\"192.168.0.168\"}\",\"accesstoken\":\"0\",\"callbackcheckaddress\":\"0\"}";
//	char *s ="data={\"version\":\"1\",\"token\":\"9F6B77DC1AABAFBAD461239AB55E4578\",\"uid\":\"407775551EC4736C60D9ABFA8E300540\",\"server_id\":\"20000\",\"pid\":\"tencentmsdkandroid\",\"nikename\":\"{\\\"openkey\\\":\\\"9F6B77DC1AABAFBAD461239AB55E4578\\\",\\\"pay_token\\\":\\\"2B876D24EF0A28A7C32DD7BDDBE4BDFF\\\",\\\"pf\\\":\\\"desktop_m_qq-10000144-android-10000144-qq-1000001292-407775551EC4736C60D9ABFA8E300540\\\",\\\"session_id\\\":\\\"openid\\\",\\\"appid\\\":\\\"1000001292\\\",\\\"session_type\\\":\\\"kp_actoken\\\",\\\"openid\\\":\\\"407775551EC4736C60D9ABFA8E300540\\\",\\\"pfkey\\\":\\\"06e6b01dd9055b5996ab88eab8e9645b\\\",\\\"ip\\\":\\\"192.168.0.168\\\"}\",\"accesstoken\":\"0\",\"callbackcheckaddress\":\"0\"}";
//	//char *q = "data={\"version\":\"1\",\"token\":\"455\"}";
//	cout<<s<<endl;
//	int y = 0;
//	 char *re=(char*)malloc(strlen(s)*3);
//	 char srcBuff[2048];
//	 sprintf(srcBuff, "%s", s);
//	 cout<<"srcBuff:\n"<<srcBuff<<endl;
//	urlencode((unsigned char*)srcBuff,strlen(s),(unsigned char*)re,strlen(s)*3);
//	cout<<re<<endl;
//	cout<<strlen(re)<<endl;
//	char *tar = (char*)malloc(strlen(re));
//	string sf;
//	if(y>0)
//	{
//		cout<<y<<endl;
//		cout<<"encode: \n"<<tar<<endl;
//	}
//
//	char* c = "data=%7B%22version%22%3A%221%22%2C%22token%22%3A%229F6B77DC1AABAFBAD461239AB55E4578%22%2C%22uid%22%3A%22407775551EC4736C60D9ABFA8E300540%22%2C%22server%5Fid%22%3A%2220000%22%2C%22pid%22%3A%22tencentmsdkandroid%22%2C%22nikename%22%3A%22%7B%5C%22openkey%5C%22%3A%5C%229F6B77DC1AABAFBAD461239AB55E4578%5C%22%2C%5C%22pay%5Ftoken%5C%22%3A%5C%222B876D24EF0A28A7C32DD7BDDBE4BDFF%5C%22%2C%5C%22pf%5C%22%3A%5C%22desktop%5Fm%5Fqq%2D10000144%2Dandroid%2D10000144%2Dqq%2D1000001292%2D407775551EC4736C60D9ABFA8E300540%5C%22%2C%5C%22session%5Fid%5C%22%3A%5C%22openid%5C%22%2C%5C%22appid%5C%22%3A%5C%221000001292%5C%22%2C%5C%22session%5Ftype%5C%22%3A%5C%22kp%5Factoken%5C%22%2C%5C%22openid%5C%22%3A%5C%22407775551EC4736C60D9ABFA8E300540%5C%22%2C%5C%22pfkey%5C%22%3A%5C%2206e6b01dd9055b5996ab88eab8e9645b%5C%22%2C%5C%22ip%5C%22%3A%5C%22192%2E168%2E0%2E168%5C%22%7D%22%2C%22accesstoken%22%3A%220%22%2C%22callbackcheckaddress%22%3A%220%22%7D";
//	char* c9= "data=%7B%22version%7B%22version%5c%22%7B";
//	int len = strlen(c);
//	char* xs = (char*)malloc(len*3);
//	urldecode((unsigned char*)c,(unsigned char*)xs);
//	while(*xs != 0)
//	{
//		cout<<*xs++;
//	}
//	cout<<endl;
//	//cout<<xs<<endl;
//	char *ll="%";
//	cout<<ll<<endl;
//
//	return 0;
//}