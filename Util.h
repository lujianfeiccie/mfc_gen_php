#pragma once
#include "gen_php_code.h"
#define WCHAR_TO_CHAR(wchar,char_str) \
	char char_str[MAX_PATH];\
	  Util::wcharTochar(wchar,char_str,MAX_PATH);   

#define CHAR_TO_WCHAR(char_str,wchar_str) \
	wchar_t wchar_str[MAX_PATH];\
	  Util::charTowchar(char_str,wchar_str,MAX_PATH);   


#define LOGExt(format,...) \
	Util::charTowchar(__FILE__,((Cgen_php_codeApp*)AfxGetApp())->m_tmp_wchar,MAX_PATH);\
	Util::LOG(((Cgen_php_codeApp*)AfxGetApp())->m_tmp_wchar,__LINE__,format,__VA_ARGS__);
class Util
{
public:
 Util(void);
    static void __cdecl LOG(const TCHAR *filename,const int line,const TCHAR *format, ...);
	static void GetFileDirectory(TCHAR* fileDirectory);
	static void GetDirectoryByFileName(const TCHAR* fileName,TCHAR* directory);
	static void charTowchar(const char *chr, wchar_t *wchar, int size);
	static void wcharTochar(const wchar_t *wchar, char *chr, int length);
	static void wcharTochar(CString& str,char*chr,int chrSize);
	static int enc_unicode_to_utf8_one(unsigned long unic, unsigned char *pOutput,  
        int outSize);
	static int enc_utf8_to_unicode_one(const unsigned char* pInput, unsigned long *Unic);
	static CString UrlEncode(CString strUnicode);
	static bool IsExistFile(LPCWSTR pszFileName);
	static CRect getControlPosition(const CWnd& cwnd,LPVOID lpvoid);
	static void setControlPosition(CWnd& cwnd,LPVOID lpvoid,int x,int y);
	static void AddReturnFromXml(CString &str);
	static CString GetFileNameByPath(CString path);
public:
 ~Util(void);
};


