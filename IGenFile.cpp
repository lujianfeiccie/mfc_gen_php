#include "StdAfx.h"
#include "IGenFile.h"


IGenFile::IGenFile(CString filename)
{
	LOGExt(L"IGenFile");
	this->m_filename = filename;

	if((this->file = _wfopen(filename,L"w+")))
	{
	LOGExt(L"Open succesfully");	
	}
	else
	{
	LOGExt(L"Open failed");	
	}
}


IGenFile::~IGenFile(void)
{
	LOGExt(L"~IGenFile");
	if(this->file!=NULL)
	fclose(this->file);
}
