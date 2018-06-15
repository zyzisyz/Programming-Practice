// CGradeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CGradeDlg.h"
#include "afxdialogex.h"


// CGradeDlg 对话框

IMPLEMENT_DYNAMIC(CGradeDlg, CDialogEx)

CGradeDlg::CGradeDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CGRADE, pParent), m_strSNo_Q(_T("")), m_strCCount(_T("")), m_strCReditS(_T(""))
{
	SetBackgroundColor(RGB(255, 255, 255));
}

CGradeDlg::~CGradeDlg()
{
}

void CGradeDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_SNo_Q, m_strSNo_Q);
	DDX_Text(pDX, IDC_EDIT_CCOUNT, m_strCCount);
	DDX_Text(pDX, IDC_CReditS, m_strCReditS);
}

BEGIN_MESSAGE_MAP(CGradeDlg, CDialogEx)
ON_BN_CLICKED(IDC_BN_EXIT, &CGradeDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()

// CGradeDlg 消息处理程序

void CGradeDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}

BOOL CGradeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//m_strConnCondition = "";
	//m_rsGradeSet.m_strFilter = m_strConnCondition;
	if (!m_rsGradeSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据库打开失败！");
	}
	else
	{
		m_listDisp.InsertColumn(0, "姓名");
		m_listDisp.InsertColumn(1, "课程号");
		m_listDisp.InsertColumn(2, "课程名");
		m_listDisp.InsertColumn(3, "学分");
		m_listDisp.InsertColumn(4, "成绩");

		RECT rect;
		m_listDisp.GetWindowRect(&rect);
		int wid = rect.right - rect.left;
		m_listDisp.SetColumnWidth(0, wid / 5);
		m_listDisp.SetColumnWidth(1, wid / 5);
		m_listDisp.SetColumnWidth(2, wid / 5);
		m_listDisp.SetColumnWidth(3, wid / 5);
		m_listDisp.SetColumnWidth(4, wid / 5);

		m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT |
			LVS_EX_GRIDLINES);
	}
	return TRUE; // return TRUE unless you set the focus to a control
				 // 异常: OCX 属性页应返回 FALSE
}
