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

}

CSCChoiceDlg::~CSCChoiceDlg()
{
}

void CSCChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSCChoiceDlg, CDialogEx)
END_MESSAGE_MAP()


// CSCChoiceDlg 消息处理程序
