#include "StdAfx.h"
#include "GenLoginFile.h"
#include "stdio.h"
GenLoginFile::GenLoginFile(CString filename):IGenFile(filename)
{
	LOGExt(L"GenLoginFile");
	if(L""==filename)
	{
		
	}
}


GenLoginFile::~GenLoginFile(void)
{
	LOGExt(L"~GenLoginFile");
}

int GenLoginFile::doGenFile() const
{
	//this->file
	LOGExt(L"doGenFile");
	CString php_code=L"<?php\r\n"\
				L"     class LoginAction extends Action{\r\n"\
				L"function index(){\r\n"\
				L"	//配置页面显示内容\r\n"\
				L"	$this->assign('title','后台管理系统');\r\n"\
				L"	$this->display();\r\n"\
				L"}\r\n"\
				L"//用户登录页面\r\n"\
				L"function login(){\r\n"\
				L"header(\"Content-Type:text/html; charset=utf-8\");\r\n"\
				L"//首先检查验证码是否正确(验证码存在Session中)\r\n"\
				L"if(	$_SESSION['verify']	!=	md5($_POST['verify'])	){\r\n"\
				L"$this->error('验证码不正确');\r\n"\
				L"}\r\n"\
				L"$user=M('User');//参数的User必须首字母大写，否则自动验证功能失效！\r\n"\
				L"$username=$_POST['username'];\r\n"\
				L"$password=md5($_POST['password']);\r\n"\
				L"if(!$this->checklen($username))\r\n{"\
				L"$this->error('用户名长度必须在6~15个字符之间');\r\n"\
				L"}\r\n"\
				L"//查找输入的用户名是否存在\r\n"\
				L"if($user->where(\"username ='$username' AND password = '$password'\")->find()){\r\n"\
				L"session(username,$username);\r\n"\
				L"$url=U('/Index/index/username/'.$username);\r\n"\
				L"redirect($url,0, '跳转中...');\r\n"\
				L"}else{\r\n"\
				L"$this->error('用户名或密码错误');\r\n"\
				L"}\r\n"\
				L"}\r\n"\
				L"function checklen($data){\r\n"\
				L"if(strlen($data)>15 || strlen($data)<6){\r\n"\
				L"return false;\r\n"\
				L"}\r\n"\
		L"return true;\r\n"\
		L"}\r\n"\
		L"}\r\n"\
		L"?>\r\n";
	LOGExt(php_code);
	int result = 0;
	for(int i=0;i<php_code.GetLength();i++)
	{
		unsigned char str[7]={0};
		result+= Util::enc_unicode_to_utf8_one(php_code[i],str,7); //Convert unicode to utf8
		fputs((char*)str,this->file);
	}	
	return result;//fwprintf(this->file,L"%s",php_code);
}