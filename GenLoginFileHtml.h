#pragma once
#include "igenfile.h"
class GenLoginFileHtml :
	public IGenFile
{
public:
	GenLoginFileHtml(CString filename);
	~GenLoginFileHtml(void);
	int doGenFile() const;
};

