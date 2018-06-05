// CSCChoiceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CSCChoiceDlg.h"
#include "afxdialogex.h"


// CSCChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CSCChoiceDlg, CDialogEx)

CSCChoiceDlg::CSCChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SCCHOICE, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CSCChoiceDlg::~CSCChoiceDlg()
{
}

void CSCChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	
}


BEGIN_MESSAGE_MAP(CSCChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BN_EXIT, &CSCChoiceDlg::OnBnClickedBnExit)
END_MESSAGE_MAP()


// CSCChoiceDlg 消息处理程序


void CSCChoiceDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
