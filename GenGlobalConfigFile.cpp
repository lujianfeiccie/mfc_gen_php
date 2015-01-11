#include "StdAfx.h"
#include "GenGlobalConfigFile.h"


GenGlobalConfigFile::GenGlobalConfigFile(CString filename):IGenFile(filename)
{
}

GenGlobalConfigFile::~GenGlobalConfigFile(void)
{
}

int GenGlobalConfigFile::doGenFile() const
{
	LOGExt(L"doGenFile");
	CString php_code=
		L"<?php"END\
		L"	//For remote SAE"END\
		L"	if($IS_SAE){"END\
		L"		return array("END\
		L"			'DB_HOST'	=>	SAE_MYSQL_HOST_S,"END\
		L"			'DB_USER'	=>	SAE_MYSQL_USER,"END\
		L"			'DB_PWD'	=>	SAE_MYSQL_PASS,"END\
		L"			'DB_NAME'	=>	SAE_MYSQL_DB,"END\
		L"			'DB_PREFIX'	=>	'think_',"END\
		L"		);"END\
		L"	}"END\
		L"	else{"END\
		L"	//For localhost"END\
		L"		return array("END\
		L"			'DB_TYPE'	=>	'mysql',"END\
		L"			'DB_HOST'	=>	'localhost',"END\
		L"			'DB_NAME'	=>	'rubydb',"END\
		L"			'DB_USER'	=>	'root',"END\
		L"			'DB_PWD'	=>	'123',"END\
		L"			'DB_PORT'	=>	'3306',"END\
		L"			'DB_PREFIX'	=>	'think_',"END\
		L"		);"END\
		L"	}"END\
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