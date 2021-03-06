
// StudentInfoDlg.h: 头文件
//

#pragma once

//其他的头文件
#include"CStudentDlg.h"
#include"CCourseDlg.h"
#include"CGradeDlg.h"
#include"CSCChoiceDlg.h"



// CStudentInfoDlg 对话框
class CStudentInfoDlg : public CDialogEx
{
// 构造
public:
	CStudentInfoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTINFO_DIALOG };
#endif

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
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBnStudent();
	afx_msg void OnBnClickedBnCourse();
	afx_msg void OnBnClickedBnScchoice();
	afx_msg void OnBnClickedBnGrade();
	afx_msg void OnBnClickedAbout();
	CListBox List_box;
};
