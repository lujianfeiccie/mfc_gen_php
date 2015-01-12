#pragma once
#include "igenfile.h"
class GenCommonAction :
	public IGenFile
{
public:
	GenCommonAction(CString filename);
	~GenCommonAction(void);
	int doGenFile() const;
};

