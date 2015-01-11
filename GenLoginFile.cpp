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
				L"		//����ҳ����ʾ����"END\
				L"		$this->assign('title','��̨����ϵͳ');"END\
				L"		$this->display();"END\
				L"	}"END\
				
				L"	//�û���¼ҳ��"END\
				L"	function login(){"END\
				L"		header(\"Content-Type:text/html; charset=utf-8\");"END\
				L"		//���ȼ����֤���Ƿ���ȷ(��֤�����Session��)"END\
				L"		if(	$_SESSION['verify']	!=	md5($_POST['verify'])	){"END\
				L"			$this->error('��֤�벻��ȷ');"END\
				L"		}"END\
				L"		$user=M('User');//������User��������ĸ��д�������Զ���֤����ʧЧ��"END\
				L"		$username=$_POST['username'];"END\
				L"		$password=md5($_POST['password']);"END\
				L"		if(!$this->checklen($username)){"END\
				L"			$this->error('�û������ȱ�����6~15���ַ�֮��');"END\
				L"		}"END\
				L"		//����������û����Ƿ����"END\
				L"		if($user->where(\"username ='$username' AND password = '$password'\")->find()){"END\
				L"			session(username,$username);"END\
				L"			$url=U('/Index/index/username/'.$username);"END\
				L"			redirect($url,0, '��ת��...');"END\
				L"		}else{"END\
				L"			$this->error('�û������������');"END\
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