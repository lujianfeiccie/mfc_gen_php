
// gen_php_codeDlg.h : ͷ�ļ�
//

#pragma once

#include "DBOperation.h"
// Cgen_php_codeDlg �Ի���
class Cgen_php_codeDlg : public CDialogEx
{
// ����
public:
	Cgen_php_codeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GEN_PHP_CODE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	DBOperation *m_db_operation;
};
