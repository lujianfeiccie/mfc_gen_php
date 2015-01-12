#include "StdAfx.h"
#include "GenConfigFile.h"


GenConfigFile::GenConfigFile(CString filename):IGenFile(filename)
{
}


GenConfigFile::~GenConfigFile(void)
{
}

int GenConfigFile::doGenFile() const
{
	LOGExt(L"doGenFile");
	CString php_code=
		L"<?php"END\
		L"	$arr1=array("END\
		L"		//'配置项'=>'配置值'"END\
		L"		'URL_MODEL'	=>	1,//path-info 模式"END\
		L"		//'SHOW_PAGE_TRACE' =>true,"END\
		L"		//'SHOW_RUN_TIME' =>true,   //显示运行时间"END\
		L"		//'SHOW_ADV_TIME' =>true,   //显示详细的运行时间"END\
		L"		//'SHOW_DB_TIMES'=>true,//显示数据库操作次数"END\
		L"		//'SHOW_CACHE_TIMES'=>true,//显示缓存操作次数"END\
		L"		//'SHOW_USE_MEM'=>true,//显示内存开销"END\
		L"	);"END\
		END\
		L"	$arr2=include './config.inc.php';"END\
		L"	return array_merge($arr1,$arr2);"END\
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