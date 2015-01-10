#pragma once
#include <WinSock2.h> 
#include"include/mysql.h" 
class DBOperation
{
public:
	DBOperation(void);
	~DBOperation(void);
	// Create Database
	int CreateDatabase(CString dbName);
	// Open Database
	int OpenDatabase(void);
	// Close Database
	int CloseDatabase(void);
	
	CString m_username;
	CString m_password;
	CString m_database_name;

	BOOL m_connecting;

	
	void PrintInfo(void);
private:
	MYSQL *m_mysql; 
};

