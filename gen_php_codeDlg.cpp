
// gen_php_codeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "gen_php_code.h"
#include "gen_php_codeDlg.h"
#include "afxdialogex.h"
#include "IGenFile.h"
#include "GenLoginFile.h"
#include "GenLoginFileHtml.h"
#include "GenSql.h"
#include "GenGlobalConfigFile.h"
#include "GenConfigFile.h"
#include "GenCommonAction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cgen_php_codeDlg 对话框




Cgen_php_codeDlg::Cgen_php_codeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cgen_php_codeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cgen_php_codeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cgen_php_codeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Cgen_php_codeDlg 消息处理程序

BOOL Cgen_php_codeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	/*m_db_operation = new DBOperation;
	m_db_operation->m_database_name = L"db_test";
	m_db_operation->m_username = L"root";
	m_db_operation->m_password = L"123";
	m_db_operation->OpenDatabase();
	m_db_operation->PrintInfo();
	m_db_operation->CloseDatabase();
	*/
	TCHAR szPath[MAX_PATH];
	SHGetSpecialFolderPath(NULL,szPath,CSIDL_DESKTOP,0);
	CString filename;
	//filename.Format(L"%s\\LoginAction.class.php",szPath);
	//filename.Format(L"%s\\index.html",szPath);
	//filename.Format(L"%s\\db.sql",szPath);
	//filename.Format(L"%s\\config.php",szPath);
	filename.Format(L"%s\\CommonAction.class.php",szPath);
	IGenFile *file = new GenCommonAction(filename);
	file->doGenFile();
	delete file;
	//LOGExt(L"nimei=%d",12);
	//	m_db_operation->m_username.GetLength()
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cgen_php_codeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cgen_php_codeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cgen_php_codeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

