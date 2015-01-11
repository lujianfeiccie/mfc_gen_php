
// gen_php_code.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cgen_php_codeApp:
// 有关此类的实现，请参阅 gen_php_code.cpp
//

class Cgen_php_codeApp : public CWinApp
{
public:
	Cgen_php_codeApp();
	virtual ~Cgen_php_codeApp();
	wchar_t *m_tmp_wchar;
	char *m_tmp_char;
// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cgen_php_codeApp theApp;