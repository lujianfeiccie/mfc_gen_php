#include "StdAfx.h"
#include "GenSql.h"


GenSql::GenSql(CString filename):IGenFile(filename)
{

}


GenSql::~GenSql(void)
{
}

int GenSql::doGenFile() const
{
	CString php_code=
	L"CREATE TABLE IF NOT EXISTS `think_user` ("END\
	L"	`id` int(11) NOT NULL AUTO_INCREMENT,"END\
	L"	`username` char(15) NOT NULL,"END\
	L"	`password` char(32) NOT NULL,"END\
	L"	`createtime` int(11) NOT NULL,"END\
	L"	`ip` char(16) NOT NULL,"END\
	L"PRIMARY KEY (`id`)"END\
	L") ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=18 ;"END\
	END\
	L"INSERT INTO `think_user` (`id`, `username`, `password`, `createtime`, `ip`) VALUES"END\
	L"(17, 'ruby97', '405958c9e0888f6ddc6221f90576490c', 1337216331, '127.0.0.1');"END\
	END\
	L"CREATE TABLE IF NOT EXISTS `think_article` ("END\
	L"	`id` int(11) NOT NULL AUTO_INCREMENT,"END\
	L"	`author` varchar(15) NOT NULL,"END\
	L"	`subject` varchar(256) NOT NULL,"END\
	L"	`createtime` int(11) NOT NULL,"END\
	L"	`lastmodifytime` int(11) NOT NULL,"END\
	L"	`message` mediumtext NOT NULL,"END\
	L"	PRIMARY KEY (`id`)"END\
	L") ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=20 ;"END\
	END\
	L"INSERT INTO `think_article` (`id`, `author`, `subject`, `createtime`, `lastmodifytime`, `message`) VALUES"END\
	L"(9, 'siaweb', 'ղķ˹������3��MVP����', 1336912664, 0, '<p>&nbsp;&nbsp;&nbsp;&nbsp;����ʱ��5��13���賿��NBA���Ȼ�����������Ĺ�ͬ�ٿ����ŷ����Ტ��ʽ�����ղ���-ղķ˹����2011-12����NBA���������м�ֵ��Ա��MVP��������ղķ˹���4��������3�λ�����٣�ͬʱ��С�ʵۡ���Ϊ�����˶�-�ǵ�֮����λ����3�᳣����MVP֮�ˡ��ڸ߾�MVP����֮ʱ��ղķ˹������������ṩ��ԽҰ��һ�����Ȼ�Ӻ��Ľ����������ƻ�����ͼΪղķ˹����ʽ˲�䡣</p><p><img style=\"float:none\" title=\"U6594P6T12D6059080F1286DT20120513111916.jpg\" border=\"0\" hspace=\"0\" src=\"/SiaWeb/ueditor/server/upload/uploadimages/37351336912656.jpg\" /></p>'),"END\
	L"(18, 'siaweb', 'hh', 1337178990, 0, '<p>hh</p>'),"END\
	L"(19, 'siaweb', '����', 1337179334, 0, '<p>��ð�</p>');"END;


	int result = 0;
	for(int i=0;i<php_code.GetLength();i++)
	{
		unsigned char str[7]={0};
		result+= Util::enc_unicode_to_utf8_one(php_code[i],str,7); //Convert unicode to utf8
		fputs((char*)str,this->file);
	}	
	return result;
}