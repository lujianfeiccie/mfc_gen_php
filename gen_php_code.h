
// gen_php_code.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cgen_php_codeApp:
// �йش����ʵ�֣������ gen_php_code.cpp
//

class Cgen_php_codeApp : public CWinApp
{
public:
	Cgen_php_codeApp();
	virtual ~Cgen_php_codeApp();
	wchar_t *m_tmp_wchar;
	char *m_tmp_char;
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cgen_php_codeApp theApp;