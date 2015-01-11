#pragma once
class IGenFile
{
protected:
	CString m_filename;
	FILE *file;
public:
	IGenFile(CString filename);
	virtual ~IGenFile(void);
	virtual int doGenFile() const=0;
};

