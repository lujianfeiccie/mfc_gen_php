#include "StdAfx.h"
#include "GenLoginFile.h"
#include "stdio.h"

GenLoginFile::GenLoginFile(CString filename):IGenFile(filename)
	//this->file
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
	LOGExt(L"doGenFile");
	CString php_code=
				L"<?php"END \
				L"class LoginAction extends Action{"END\
				L"	function index(){"END\
				L"		//配置页面显示内容"END\
				L"		$this->assign('title','后台管理系统');"END\
				L"		$this->display();"END\
				L"	}"END\
				
				L"	//用户登录页面"END\
				L"	function login(){"END\
				L"		header(\"Content-Type:text/html; charset=utf-8\");"END\
				L"		//首先检查验证码是否正确(验证码存在Session中)"END\
				L"		if(	$_SESSION['verify']	!=	md5($_POST['verify'])	){"END\
				L"			$this->error('验证码不正确');"END\
				L"		}"END\
				L"		$user=M('User');//参数的User必须首字母大写，否则自动验证功能失效！"END\
				L"		$username=$_POST['username'];"END\
				L"		$password=md5($_POST['password']);"END\
				L"		if(!$this->checklen($username)){"END\
				L"			$this->error('用户名长度必须在6~15个字符之间');"END\
				L"		}"END\
				L"		//查找输入的用户名是否存在"END\
				L"		if($user->where(\"username ='$username' AND password = '$password'\")->find()){"END\
				L"			session(username,$username);"END\
				L"			$url=U('/Index/index/username/'.$username);"END\
				L"			redirect($url,0, '跳转中...');"END\
				L"		}else{"END\
				L"			$this->error('用户名或密码错误');"END\
				L"		}"END\
				L"	}"END\
				
				L"	function checklen($data){"END\
				L"		if(strlen($data)>15 || strlen($data)<6){"END\
				L"			return false;"END\
				L"		}"END\
				L"			return true;"END\
				L"	}"END\
				L"}"END\
				L"?>"END;
	LOGExt(php_code);
	int result = 0;
	int length = php_code.GetLength();
	unsigned char str[7]={0};
	for(int i=0;i<length;i++)
	{
		result+= Util::enc_unicode_to_utf8_one(php_code[i],str,7); //Convert unicode to utf8
		fputs((char*)str,this->file);
		memset(str,0,7);
	}	
	return result;//fwprintf(this->file,L"%s",php_code);
}