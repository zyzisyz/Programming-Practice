#pragma once
#include "CStudent.h"
#include"Choice.h"
// CStudentDlg 对话框

class CStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentDlg)

  public:
	CStudentDlg(CWnd *pParent = nullptr); // 标准构造函数
	virtual ~CStudentDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum
	{
		IDD = IDD_DIALOG_STUDENT
	};
#endif

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
  public:
	//数据成员
	CStudent m_rsStudentSet; //student表
	bool m_bEmpty;
	bool m_bFirst;
	bool m_bLast;
	bool m_bAdd;
	bool m_bEdit;

	afx_msg void OnBnClickedBnExit();

	//操作数据库的函数
	void ClearEditData(void);
	void ReadRecord(void);
	void WriteRecord(void);
	void SetMoveBNState(void);
	void SetEditState(void);

	//数据
	
	Choice ChoiceSet;

	CString m_strSNo_Q;
	CString m_strSNAME_Q;
	CString m_strSNo;
	CString m_strSSex;
	CString m_strSBDate;
	CString m_strSName;
	CString m_strSMajor;
	CString m_strSSDate;

	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedBnEdit();
	afx_msg void OnBnClickedBnDelete();
	afx_msg void OnBnClickedBnSave();
	afx_msg void OnBnClickedBnQuery();
	afx_msg void OnBnClickedBnFirst();
	afx_msg void OnBnClickedBnPrev();
	afx_msg void OnBnClickedBnNext();
	afx_msg void OnBnClickedBnLast();
	afx_msg void OnBnClickedBnCancel();
};
