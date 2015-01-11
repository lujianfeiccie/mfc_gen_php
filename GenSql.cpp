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
	L"(9, 'siaweb', '詹姆斯高捧第3座MVP奖杯', 1336912664, 0, '<p>&nbsp;&nbsp;&nbsp;&nbsp;北京时间5月13日凌晨，NBA与热火队在美航中心共同召开新闻发布会并正式宣布勒布朗-詹姆斯荣膺2011-12赛季NBA常规赛最有价值球员（MVP）。这是詹姆斯最近4个赛季第3次获此殊荣，同时“小皇帝”成为继迈克尔-乔丹之后首位至少3夺常规赛MVP之人。在高举MVP奖杯之时，詹姆斯还获得赞助商提供的越野车一辆，热火队核心将捐赠给慈善机构。图为詹姆斯获奖仪式瞬间。</p><p><img style=\"float:none\" title=\"U6594P6T12D6059080F1286DT20120513111916.jpg\" border=\"0\" hspace=\"0\" src=\"/SiaWeb/ueditor/server/upload/uploadimages/37351336912656.jpg\" /></p>'),"END\
	L"(18, 'siaweb', 'hh', 1337178990, 0, '<p>hh</p>'),"END\
	L"(19, 'siaweb', '哈哈', 1337179334, 0, '<p>你好啊</p>');"END;


	int result = 0;
	for(int i=0;i<php_code.GetLength();i++)
	{
		unsigned char str[7]={0};
		result+= Util::enc_unicode_to_utf8_one(php_code[i],str,7); //Convert unicode to utf8
		fputs((char*)str,this->file);
	}	
	return result;
}