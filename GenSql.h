#pragma once
#include "igenfile.h"
class GenSql :
	public IGenFile
{
public:
	GenSql(CString filename);
	~GenSql(void);
	int doGenFile() const;
};

