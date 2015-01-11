#pragma once
#include "igenfile.h"
class GenLoginFile :
	public IGenFile
{
public:
	GenLoginFile(CString filename);
	~GenLoginFile(void);
	int doGenFile() const;
};

