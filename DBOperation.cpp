#include "StdAfx.h"
#include "DBOperation.h"


DBOperation::DBOperation(void)
{
	this->m_mysql = new MYSQL;
}


DBOperation::~DBOperation(void)
{
	delete this->m_mysql;
}


// Create Database
int DBOperation::CreateDatabase(CString dbName)
{
	return 0;
}


// Open Database
int DBOperation::OpenDatabase(void)
{
	int status = -1;
	mysql_init(this->m_mysql); 
     
	int ret=mysql_options(this->m_mysql,MYSQL_SET_CHARSET_NAME,"utf8"); 
	
	if(ret==0) 
	{
		LOGExt(L"mysql options success"); 
	}
	else 
	{
		LOGExt(L"options failed"); 
	}
	WCHAR_TO_CHAR(this->m_username,username);
	WCHAR_TO_CHAR(this->m_password,password);
	WCHAR_TO_CHAR(this->m_database_name,database_name);

	if(mysql_real_connect(this->m_mysql,
							NULL,
							username,
							password,
							database_name,0,NULL,0)) 
	{ 
		LOGExt(L"Database connected"); 
		status = 1;
	} 
	else 
	{ 
		const char* error_code=0; 
		error_code=mysql_error(this->m_mysql); 
		
		LOGExt(L"Error Code:%s",error_code); 
		status - 1;
	} 

	return status;
}


// Close Database
int DBOperation::CloseDatabase(void)
{
	mysql_close(this->m_mysql); //�ر����ݿ����� 
	return 0;
}


void DBOperation::PrintInfo(void)
{
	  //��ѯ 
    CString sql_cmd=L"select *from tb_user"; 
	WCHAR_TO_CHAR(sql_cmd,sql_cmd_str,100);
	int ret=mysql_real_query(this->m_mysql,sql_cmd_str,sql_cmd.GetLength()); 
    if(ret!=0) 
	{ 
		LOGExt(L"fail to query"); 
		return;
	} 

  //��ȡ��ѯ��� 
	MYSQL_RES *res_ptr=mysql_store_result(this->m_mysql); 

	if(res_ptr) 
	{ 
		LOGExt(L"rows number:%ld",(unsigned long)mysql_num_rows(res_ptr));  //���� 
	} 

   //��ʾ�ֶ��� 
	unsigned int num_fields=mysql_num_fields(res_ptr); //��������� 
    MYSQL_FIELD *fields=mysql_fetch_fields(res_ptr);  //�����ֶδ浽�ֶνṹ�� 

	wchar_t fields_str[50];
	for(int ii=0;ii<num_fields;ii++) 
	{ 
    //��ʾ�����ֶ���
	Util::charTowchar(fields[ii].name,fields_str,50);
	LOGExt(L"%s\t",fields_str); 
	} 

///////////////////////��ʾÿ�в�ѯ���
	MYSQL_ROW sqlrow = NULL;
	while(sqlrow=mysql_fetch_row(res_ptr))//ȡ���� 
    { 
	//ÿ�ж������´��� 
	//	string str; 
	wchar_t sqlrow_str[50];
	for(int ii=0;ii<num_fields;ii++) 
	{ 
           
	   Util::charTowchar(sqlrow[ii],sqlrow_str,50);
	   if(sqlrow[ii] !=NULL) 
	   { 
		 LOGExt(L"%s\t",sqlrow_str);
	   } 
	   else 
	   { 
		 LOGExt(L"NULL\t"); 
	   } 
	} 
	} 
}
