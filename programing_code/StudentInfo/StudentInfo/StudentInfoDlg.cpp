
// StudentInfoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "StudentInfoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
  public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum
	{
		IDD = IDD_ABOUTBOX
	};
#endif

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	// 实现
  protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	SetBackgroundColor(RGB(255, 255, 255));
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CStudentInfoDlg 对话框

CStudentInfoDlg::CStudentInfoDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTINFO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentInfoDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, List_box);
}

BEGIN_MESSAGE_MAP(CStudentInfoDlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDOK, &CStudentInfoDlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_BN_STUDENT, &CStudentInfoDlg::OnBnClickedBnStudent)
ON_BN_CLICKED(IDC_BN_COURSE, &CStudentInfoDlg::OnBnClickedBnCourse)
ON_BN_CLICKED(IDC_BN_SCCHOICE, &CStudentInfoDlg::OnBnClickedBnScchoice)
ON_BN_CLICKED(IDC_BN_GRADE, &CStudentInfoDlg::OnBnClickedBnGrade)
ON_BN_CLICKED(IDC_ABOUT, &CStudentInfoDlg::OnBnClickedAbout)
END_MESSAGE_MAP()

// CStudentInfoDlg 消息处理程序

BOOL CStudentInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	SetBackgroundColor(RGB(255, 255, 255));

	CMenu *pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);  // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentInfoDlg::OnPaint()
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
HCURSOR CStudentInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CStudentInfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	int nResponse = MessageBox("震惊！是否真的要退出", "提示消息", MB_YESNO);
	if (nResponse == IDYES)
	{
		CDialog::OnOK();
	}
}

void CStudentInfoDlg::OnBnClickedBnCourse()
{
	// TODO: 在此添加控件通知处理程序代码
	CCourseDlg dlg;
	dlg.DoModal();
}

void CStudentInfoDlg::OnBnClickedBnStudent()
{
	// TODO: 在此添加控件通知处理程序代码
	CStudentDlg dlg;
	dlg.DoModal();
}

void CStudentInfoDlg::OnBnClickedBnScchoice()
{
	// TODO: 在此添加控件通知处理程序代码
	CSCChoiceDlg dlg;
	dlg.DoModal();
}

void CStudentInfoDlg::OnBnClickedBnGrade()
{
	// TODO: 在此添加控件通知处理程序代码
	CGradeDlg dlg;
	dlg.DoModal();
}

void CStudentInfoDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg dlg;
	dlg.DoModal();
}
