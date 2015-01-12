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
	L"		//������֤����"END\
	L"		import(\"ORG.Util.Image\");"END\
	L"		/*"END\
	L"		 * ����1����֤�볤�ȣ�Ĭ��4"END\
	L"		 * ����2�����ͣ�0Ϊ��ĸ��1Ϊ���֣�2Ϊ��д��ĸ��3ΪСд��ĸ��4Ϊ����"END\
	L"		 * ����3��ͼƬ���ͣ�Ĭ��png��ʽ����������û�п�PNG���͸ĳ�������ʽ"END\
	L"		 * ����4��ͼƬ��ȣ����ݳ����Զ����㣩"END\
	L"		 * ����5��ͼƬ�߶ȣ�Ĭ��22������"END\
	L"		 * ����6����֤�뱣����Session������ 'verify'"END\
	L"		 */"END\
	L"		 ob_end_clean();"END\
	L"		 Image::buildImageVerify(4,1,'png',70,30);//��̬����"END\
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