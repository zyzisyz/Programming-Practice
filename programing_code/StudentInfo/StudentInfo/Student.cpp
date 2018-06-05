// Student.h : CStudent 类的实现



// CStudent 实现

// 代码生成在 2018年6月5日, 20:41

#include "stdafx.h"
#include "Student.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Sno = "";
	m_Sname = "";
	m_Ssex = "";
	m_ClassNo = "";
	m_Sbirth;
	m_Status = "";
	m_Hometown = "";
	m_Enrollment;
	m_Telephone = "";
	m_Resume = "";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Sno]"), m_Sno);
	RFX_Text(pFX, _T("[Sname]"), m_Sname);
	RFX_Text(pFX, _T("[Ssex]"), m_Ssex);
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Date(pFX, _T("[Sbirth]"), m_Sbirth);
	RFX_Text(pFX, _T("[Status]"), m_Status);
	RFX_Text(pFX, _T("[Hometown]"), m_Hometown);
	RFX_Date(pFX, _T("[Enrollment]"), m_Enrollment);
	RFX_Text(pFX, _T("[Telephone]"), m_Telephone);
	RFX_Text(pFX, _T("[Resume]"), m_Resume);

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


