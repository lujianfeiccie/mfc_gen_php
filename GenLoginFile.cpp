#include "StdAfx.h"
#include "GenLoginFile.h"
#include "stdio.h"
GenLoginFile::GenLoginFile(CString filename):IGenFile(filename)
{
	
	if(L""==filename)
	{
		
	}
	
}


GenLoginFile::~GenLoginFile(void)
{
}

int GenLoginFile::doGenFile() const
{
	//this->file
	//fwprintf(this->file,L"");
	return 0;
}