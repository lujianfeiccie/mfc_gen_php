#pragma once
#include "igenfile.h"
class GenGlobalConfigFile :
	public IGenFile
{
public:
	GenGlobalConfigFile(CString filename);
	~GenGlobalConfigFile(void);
	int doGenFile() const;
};

