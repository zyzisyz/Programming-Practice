// Choice.h : Choice 类的实现



// Choice 实现

// 代码生成在 2018年6月17日, 23:20

#include "stdafx.h"
#include "Choice.h"
IMPLEMENT_DYNAMIC(Choice, CRecordset)

Choice::Choice(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_SNo = "";
	m_CourseNO = "";
	m_Sscore = 0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Choice::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString Choice::GetDefaultSQL()
{
	return _T("[dbo].[Choice]");
}

void Choice::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[SNo]"), m_SNo);
	RFX_Text(pFX, _T("[CourseNO]"), m_CourseNO);
	RFX_Long(pFX, _T("[Sscore]"), m_Sscore);

}
/////////////////////////////////////////////////////////////////////////////
// Choice 诊断

#ifdef _DEBUG
void Choice::AssertValid() const
{
	CRecordset::AssertValid();
}

void Choice::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


