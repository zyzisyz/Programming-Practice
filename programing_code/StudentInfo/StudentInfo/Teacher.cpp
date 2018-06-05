// Teacher.h : CTeacher 类的实现



// CTeacher 实现

// 代码生成在 2018年6月5日, 20:59

#include "stdafx.h"
#include "Teacher.h"
IMPLEMENT_DYNAMIC(CTeacher, CRecordset)

CTeacher::CTeacher(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Tno = "";
	m_Dno = "";
	m_Tname = "";
	m_Tsex = "";
	m_Tage = 0;
	m_Tworking;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CTeacher::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CTeacher::GetDefaultSQL()
{
	return _T("[dbo].[Teacher]");
}

void CTeacher::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Tno]"), m_Tno);
	RFX_Text(pFX, _T("[Dno]"), m_Dno);
	RFX_Text(pFX, _T("[Tname]"), m_Tname);
	RFX_Text(pFX, _T("[Tsex]"), m_Tsex);
	RFX_Int(pFX, _T("[Tage]"), m_Tage);
	RFX_Date(pFX, _T("[Tworking]"), m_Tworking);

}
/////////////////////////////////////////////////////////////////////////////
// CTeacher 诊断

#ifdef _DEBUG
void CTeacher::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTeacher::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


