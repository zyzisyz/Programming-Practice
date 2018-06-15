// CStudent.h : CStudent 类的实现



// CStudent 实现

// 代码生成在 2018年6月11日, 22:34

#include "stdafx.h"
#include "CStudent.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_SName = "";
	m_SNo = "";
	m_SMajor = "";
	m_SSex = "";
	m_SBirthDate = "";
	m_SSchoolDate = "";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[CStudent]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[SName]"), m_SName);
	RFX_Text(pFX, _T("[SNo]"), m_SNo);
	RFX_Text(pFX, _T("[SMajor]"), m_SMajor);
	RFX_Text(pFX, _T("[SSex]"), m_SSex);
	RFX_Text(pFX, _T("[SBirthDate]"), m_SBirthDate);
	RFX_Text(pFX, _T("[SSchoolDate]"), m_SSchoolDate);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent 诊断

#ifdef _DEBUG
void CStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


