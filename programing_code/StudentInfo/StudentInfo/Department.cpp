// Department.h : CDepartment 类的实现



// CDepartment 实现

// 代码生成在 2018年6月5日, 20:52

#include "stdafx.h"
#include "Department.h"
IMPLEMENT_DYNAMIC(CDepartment, CRecordset)

CDepartment::CDepartment(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Dno = "";
	m_Tno = "";
	m_Dname = "";
	m_nFields = 3;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CDepartment::GetDefaultConnect()
{
	return _T("DSN=teaching;UID=sa;PWD=zy228830;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CDepartment::GetDefaultSQL()
{
	return _T("[dbo].[Department]");
}

void CDepartment::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Dno]"), m_Dno);
	RFX_Text(pFX, _T("[Tno]"), m_Tno);
	RFX_Text(pFX, _T("[Dname]"), m_Dname);

}
/////////////////////////////////////////////////////////////////////////////
// CDepartment 诊断

#ifdef _DEBUG
void CDepartment::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDepartment::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


