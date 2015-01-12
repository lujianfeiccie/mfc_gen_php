#include "StdAfx.h"
#include "GenCommonAction.h"


GenCommonAction::GenCommonAction(CString filename):IGenFile(filename)
{

}


GenCommonAction::~GenCommonAction(void)
{
}

int GenCommonAction::doGenFile() const
{
	CString php_code=
	L"<?php"END\
	L"class CommonAction extends  Action{"END\
	L"	function verify(){"END\
	L"		//导入验证码类"END\
	L"		import(\"ORG.Util.Image\");"END\
	L"		/*"END\
	L"		 * 参数1：验证码长度，默认4"END\
	L"		 * 参数2：类型，0为字母，1为数字，2为大写字母，3为小写字母，4为中文"END\
	L"		 * 参数3：图片类型，默认png格式，若服务器没有开PNG，就改成其他格式"END\
	L"		 * 参数4：图片宽度（根据长度自动计算）"END\
	L"		 * 参数5：图片高度，默认22个像素"END\
	L"		 * 参数6：验证码保存在Session的名称 'verify'"END\
	L"		 */"END\
	L"		 ob_end_clean();"END\
	L"		 Image::buildImageVerify(4,1,'png',70,30);//静态方法"END\
	L"	 }"END\
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