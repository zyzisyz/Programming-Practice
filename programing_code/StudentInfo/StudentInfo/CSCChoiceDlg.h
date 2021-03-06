#pragma once
#include"Choice.h"
// CSCChoiceDlg 对话框

class CSCChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSCChoiceDlg)

  public:
	CSCChoiceDlg(CWnd *pParent = nullptr); // 标准构造函数
	virtual ~CSCChoiceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum
	{
		IDD = IDD_DIALOG_SCCHOICE
	};
#endif

  protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
  public:
	afx_msg void OnBnClickedBnExit();

	bool m_bEmpty;
	bool m_bFirst;
	bool m_bLast;
	bool m_bAdd;
	bool m_bEdit;
	
	CString StudentNo_Q;
	CString CourseNo_Q;
	CString StudentNo;
	CString CourseNo;
	CString Score;

	Choice GradeSet;

	void ClearEditData(void);
	void WriteRecord(void);
	void ReadRecord(void);
	void SetMoveBNState(void);
	void SetEditState(void);

	afx_msg void OnBnClickedBnQuery();
	afx_msg void OnBnClickedBnFirst();
	afx_msg void OnBnClickedBnPrev();
	afx_msg void OnBnClickedBnNext();
	afx_msg void OnBnClickedBnLast();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedBnEdit();
	afx_msg void OnBnClickedBnDelete();
	afx_msg void OnBnClickedBnSave();
	afx_msg void OnBnClickedBnCancel();
	virtual BOOL OnInitDialog();
};
