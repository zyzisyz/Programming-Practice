// CGradeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CGradeDlg.h"
#include "afxdialogex.h"


// CGradeDlg 对话框

IMPLEMENT_DYNAMIC(CGradeDlg, CDialogEx)

CGradeDlg::CGradeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CGRADE, pParent)
{

}

CGradeDlg::~CGradeDlg()
{
}

void CGradeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGradeDlg, CDialogEx)
END_MESSAGE_MAP()


// CGradeDlg 消息处理程序
