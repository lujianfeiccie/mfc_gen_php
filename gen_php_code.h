
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

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cgen_php_codeApp theApp;