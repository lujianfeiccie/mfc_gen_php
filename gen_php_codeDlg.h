
// gen_php_codeDlg.h : 头文件
//

#pragma once

#include "DBOperation.h"
// Cgen_php_codeDlg 对话框
class Cgen_php_codeDlg : public CDialogEx
{
// 构造
public:
	Cgen_php_codeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GEN_PHP_CODE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	DBOperation *m_db_operation;
};
