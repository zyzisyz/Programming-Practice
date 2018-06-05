// Schedule.h : CSchedule 类的实现



// CSchedule 实现

// 代码生成在 2018年6月5日, 20:54

#include "stdafx.h"
#include "Schedule.h"
IMPLEMENT_DYNAMIC(CSchedule, CRecordset)

CSchedule::CSchedule(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CourseNo = "";
	m_StartYear;
	m_ClassNo = "";
	m_Teacher = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CSchedule::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSchedule::GetDefaultSQL()
{
	return _T("[dbo].[Schedule]");
}

void CSchedule::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[CourseNo]"), m_CourseNo);
	RFX_Date(pFX, _T("[StartYear]"), m_StartYear);
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Text(pFX, _T("[Teacher]"), m_Teacher);

}
/////////////////////////////////////////////////////////////////////////////
// CSchedule 诊断

#ifdef _DEBUG
void CSchedule::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSchedule::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


