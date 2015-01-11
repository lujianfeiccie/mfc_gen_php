#include "StdAfx.h"
#include "GenLoginFileHtml.h"


GenLoginFileHtml::GenLoginFileHtml(CString filename):IGenFile(filename)
{
}


GenLoginFileHtml::~GenLoginFileHtml(void)
{
}

int GenLoginFileHtml::doGenFile() const
{
	CString php_code =
		L"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">"END \
		L"<html>"END\
		L"	<head>"END\
		L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">"END\
		L"		<title>{$title}</title>"END\
		L"		<script>"END\
		L"			function show(obj){"END\
		L"			obj.src=\"__APP__/Common/verify/random/\"+Math.random();"END\
		L"			}"END\
		L"		</script>"END\
		L"	</head>"END\
		L"	<body>"END\
		L"		<form action=\"__URL__/login\" method=\"POST\">"END\
		L"			<label for=\"username\">用户名</label><input id=\"username\" type=\"text\"  name=\"username\"/>"END\
		L"			<label for=\"password\">密码</label><input id=\"password\" type=\"password\" name=\"password\"/>"END\
		L"			<label for=\"verify\">验证码</label><input id=\"verify\" type=\"text\" name=\"verify\"/><img src=\"__APP__/Common/verify\"/ onclick=\"show(this)\">"END\
		L"			<input type=\"submit\" value=\"登录\" />"END\
		L"		</form>"END\
		L"	</body>"END\
		L"</html>"END;
	int result = 0;
	for(int i=0;i<php_code.GetLength();i++)
	{
		unsigned char str[7]={0};
		result+= Util::enc_unicode_to_utf8_one(php_code[i],str,7); //Convert unicode to utf8
		fputs((char*)str,this->file);
	}	
	return result;
}