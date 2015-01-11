#pragma once
#include "igenfile.h"
class GenConfigFile :
	public IGenFile
{
public:
	GenConfigFile(CString filename);
	~GenConfigFile(void);
	int doGenFile() const;
};

