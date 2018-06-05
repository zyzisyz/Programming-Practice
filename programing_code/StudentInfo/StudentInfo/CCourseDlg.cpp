// CCourseDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CCourseDlg.h"
#include "afxdialogex.h"


// CCourseDlg 对话框

IMPLEMENT_DYNAMIC(CCourseDlg, CDialogEx)

CCourseDlg::CCourseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COURSE, pParent)

	, CourseNum(_T(""))
	, CourseName(_T(""))
{

}

CCourseDlg::~CCourseDlg()
{
}

void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{

	DDX_Text(pDX, IDC_EDIT_CNO_q, CourseNum);
	DDX_Text(pDX, IDC_EDIT_CNNAME_q, CourseName);
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_BN_EXIT, &CCourseDlg::OnBnClickedBnExit)
	ON_BN_CLICKED(IDC_BN_QUERY, &CCourseDlg::OnBnClickedBnQuery)
END_MESSAGE_MAP()


// CCourseDlg 消息处理程序








void CCourseDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void CCourseDlg::OnBnClickedBnQuery()
{
	// TODO: 在此添加控件通知处理程序代码

}
