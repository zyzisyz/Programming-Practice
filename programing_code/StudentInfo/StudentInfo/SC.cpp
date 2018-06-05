// SC.h : CSC 类的实现



// CSC 实现

// 代码生成在 2018年6月5日, 20:53

#include "stdafx.h"
#include "SC.h"
IMPLEMENT_DYNAMIC(CSC, CRecordset)

CSC::CSC(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Sno = "";
	m_CourseNo = "";
	m_Score = 0.0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CSC::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSC::GetDefaultSQL()
{
	return _T("[dbo].[SC]");
}

void CSC::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Sno]"), m_Sno);
	RFX_Text(pFX, _T("[CourseNo]"), m_CourseNo);
	RFX_Single(pFX, _T("[Score]"), m_Score);

}
/////////////////////////////////////////////////////////////////////////////
// CSC 诊断

#ifdef _DEBUG
void CSC::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSC::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


