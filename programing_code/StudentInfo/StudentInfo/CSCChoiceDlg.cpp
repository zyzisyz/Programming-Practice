// CSCChoiceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentInfo.h"
#include "CSCChoiceDlg.h"
#include "afxdialogex.h"

// CSCChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CSCChoiceDlg, CDialogEx)

CSCChoiceDlg::CSCChoiceDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SCCHOICE, pParent)
	, StudentNo_Q(_T(""))
	, CourseNo_Q(_T(""))
	, StudentNo(_T(""))
	, CourseNo(_T(""))
	, Score(_T(""))
{
	SetBackgroundColor(RGB(255, 255, 255));
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
}

CSCChoiceDlg::~CSCChoiceDlg()
{
}

void CSCChoiceDlg::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX, IDC_EDIT_SNo_Q, StudentNo_Q);
	DDX_Text(pDX, IDC_EDIT_CNO_q, CourseNo_Q);
	DDX_Text(pDX, IDC_EDIT_SNo, StudentNo);
	DDX_Text(pDX, IDC_EDIT_CNO, CourseNo);
	DDX_Text(pDX, IDC_EDIT_SCGRADE, Score);
}

BEGIN_MESSAGE_MAP(CSCChoiceDlg, CDialogEx)
ON_BN_CLICKED(IDC_BN_EXIT, &CSCChoiceDlg::OnBnClickedBnExit)
ON_BN_CLICKED(IDC_BN_QUERY, &CSCChoiceDlg::OnBnClickedBnQuery)
ON_BN_CLICKED(IDC_BN_FIRST, &CSCChoiceDlg::OnBnClickedBnFirst)
ON_BN_CLICKED(IDC_BN_PREV, &CSCChoiceDlg::OnBnClickedBnPrev)
ON_BN_CLICKED(IDC_BN_NEXT, &CSCChoiceDlg::OnBnClickedBnNext)
ON_BN_CLICKED(IDC_BN_LAST, &CSCChoiceDlg::OnBnClickedBnLast)
ON_BN_CLICKED(IDC_ADD, &CSCChoiceDlg::OnBnClickedAdd)
ON_BN_CLICKED(IDC_BN_EDIT, &CSCChoiceDlg::OnBnClickedBnEdit)
ON_BN_CLICKED(IDC_BN_DELETE, &CSCChoiceDlg::OnBnClickedBnDelete)
ON_BN_CLICKED(IDC_BN_SAVE, &CSCChoiceDlg::OnBnClickedBnSave)
ON_BN_CLICKED(IDC_BN_CANCEL, &CSCChoiceDlg::OnBnClickedBnCancel)
END_MESSAGE_MAP()

// CSCChoiceDlg 消息处理程序

void CSCChoiceDlg::OnBnClickedBnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void CSCChoiceDlg::ClearEditData(void)
{
	StudentNo_Q = "";
	CourseNo_Q = "";
	StudentNo = "";
	CourseNo = "";
	Score = "";
	UpdateData(FALSE);
	return;
}

void CSCChoiceDlg::WriteRecord(void)
{
	UpdateData(TRUE);
	GradeSet.m_CourseNO = CourseNo;
	GradeSet.m_Sscore = atoi(Score);
	GradeSet.m_SNo = StudentNo;
}

void CSCChoiceDlg::ReadRecord(void)
{
	CourseNo = GradeSet.m_CourseNO;
	StudentNo = GradeSet.m_SNo;
	Score.Format("%d", GradeSet.m_Sscore);

	UpdateData(FALSE);
}

void CSCChoiceDlg::SetMoveBNState(void)
{
	{
		CWnd *pWnd;
		if (m_bEmpty || m_bEdit)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(FALSE);
		}
		if (m_bFirst)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(TRUE);
		}
		else if (m_bLast)
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(FALSE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(FALSE);
		}
		else
		{
			pWnd = GetDlgItem(IDC_BN_FIRST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_PREV);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_LAST);
			pWnd->EnableWindow(TRUE);

			pWnd = GetDlgItem(IDC_BN_NEXT);
			pWnd->EnableWindow(TRUE);
		}
	}
}

void CSCChoiceDlg::SetEditState(void)
{
	CWnd *pWnd;
	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_ADD);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_EDIT);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_DELETE);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_SAVE);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_CANCEL);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_CNO);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_EDIT_SCGRADE);
		pWnd->EnableWindow(TRUE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_ADD);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_EDIT);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_DELETE);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_QUERY);
		pWnd->EnableWindow(TRUE);

		pWnd = GetDlgItem(IDC_BN_SAVE);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_BN_CANCEL);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_CNO);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_EDIT_SCGRADE);
		pWnd->EnableWindow(FALSE);
	}
}

void CSCChoiceDlg::OnBnClickedBnQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (StudentNo_Q.IsEmpty() && CourseNo_Q.IsEmpty())
	{
		GradeSet.m_strFilter = "";
		GradeSet.Requery();
		if (GradeSet.IsBOF())
		{
			AfxMessageBox("数据集空！");
			m_bEmpty = true;
			ClearEditData();
			SetMoveBNState();
		}
		else
		{
			m_bEmpty = false;
			GradeSet.MoveFirst();
			m_bFirst = true;
			m_bLast = false;
			ReadRecord();
			SetMoveBNState();
		}
		return;
	}
	BOOL mbSNoQInput = FALSE;
	if (!StudentNo_Q.IsEmpty())
	{
		GradeSet.m_strFilter = "SNO='" + StudentNo_Q;
		GradeSet.m_strFilter = GradeSet.m_strFilter + "'";

		mbSNoQInput = TRUE;
	}
	if (!CourseNo_Q.IsEmpty())
	{
		if (mbSNoQInput)
		{
			GradeSet.m_strFilter = GradeSet.m_strFilter + " AND CourseNo='";
			GradeSet.m_strFilter = GradeSet.m_strFilter + CourseNo_Q;
			GradeSet.m_strFilter = GradeSet.m_strFilter + "'";
		}
		else
		{
			GradeSet.m_strFilter = "CourseName='" + CourseNo_Q;
			GradeSet.m_strFilter = GradeSet.m_strFilter + "'";
		}
	}
	GradeSet.Requery();
	if (GradeSet.IsEOF())
	{
		AfxMessageBox("没有查到相关记录！");
		m_bEmpty = true;
		ClearEditData();
		SetMoveBNState();
	}
	else
	{
		m_bEmpty = false;
		GradeSet.MoveFirst();
		m_bFirst = true;
		ReadRecord();
		SetMoveBNState();
	}
	
}


void CSCChoiceDlg::OnBnClickedBnFirst()
{
	// TODO: 在此添加控件通知处理程序代码
	GradeSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	SetMoveBNState();
	ReadRecord();
}


void CSCChoiceDlg::OnBnClickedBnPrev()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	GradeSet.MovePrev();
	if (GradeSet.IsBOF())
	{
		GradeSet.MoveFirst();
		m_bFirst = TRUE;
	}
	SetMoveBNState();
	ReadRecord();
}


void CSCChoiceDlg::OnBnClickedBnNext()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bFirst = false;
	m_bLast = false;
	GradeSet.MoveNext();
	if (GradeSet.IsEOF())
	{
		GradeSet.MoveLast();
		m_bLast = true;
	}
	SetMoveBNState();
	ReadRecord();
}


void CSCChoiceDlg::OnBnClickedBnLast()
{
	// TODO: 在此添加控件通知处理程序代码
	GradeSet.MoveLast();
	m_bFirst = false;
	m_bLast = true;
	SetMoveBNState();
	ReadRecord();
}


void CSCChoiceDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ClearEditData();
	m_bEdit = true;
	m_bAdd = true;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNo);
}


void CSCChoiceDlg::OnBnClickedBnEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bEdit = true;
	m_bAdd = false;
	SetMoveBNState();
	SetEditState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_EDIT_SNAME);
}


void CSCChoiceDlg::OnBnClickedBnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	if (AfxMessageBox("震惊！是否要删除该记录？", MB_YESNO | MB_ICONSTOP) == IDYES)
	{
		GradeSet.Delete();
		GradeSet.Requery();
		ClearEditData();
		if (GradeSet.IsBOF())
		{
			AfxMessageBox("什么？表中居然已经没有记录了！");
			ClearEditData();
			m_bEmpty = true;
			SetMoveBNState();
			return;
		}
		m_bFirst = true;
		m_bLast = false;
		ReadRecord();
		SetMoveBNState();
	}
}


void CSCChoiceDlg::OnBnClickedBnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (StudentNo.IsEmpty() || CourseNo.IsEmpty()||Score.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		CWnd *pWnd;
		pWnd = GetDlgItem(IDC_EDIT_SNo);
		pWnd->SetFocus();
		return;
	}
	if (m_bAdd)
	{
		GradeSet.AddNew();
	}
	else
	{
		GradeSet.Edit();
	}
	WriteRecord();
	GradeSet.Update();
	GradeSet.Requery();
	GradeSet.MoveFirst();
	m_bFirst = true;
	m_bLast = false;
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}


void CSCChoiceDlg::OnBnClickedBnCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bAdd = false;
	m_bEdit = false;
	ReadRecord();
	SetMoveBNState();
	SetEditState();
}


BOOL CSCChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GradeSet.Open(AFX_DB_USE_DEFAULT_TYPE);
	if (!GradeSet.IsOpen())
	{
		AfxMessageBox("数据打开失败!");
		return TRUE;
	}
	else if (GradeSet.IsBOF())
	{
		AfxMessageBox("数据集空!");
		m_bEmpty = true;
		ClearEditData();
		SetMoveBNState();
		SetEditState();
	}
	else
	{
		m_bEmpty = false;
		m_bFirst = true;
		m_bLast = false;
		ReadRecord();
		SetMoveBNState();
		SetEditState();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
