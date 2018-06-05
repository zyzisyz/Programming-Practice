// SClass.h : CSClass 类的实现



// CSClass 实现

// 代码生成在 2018年6月5日, 20:57

#include "stdafx.h"
#include "SClass.h"
IMPLEMENT_DYNAMIC(CSClass, CRecordset)

CSClass::CSClass(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ClassNo = "";
	m_ClassName = "";
	m_Major = "";
	m_Grade = "";
	m_Number = 0;
	m_Advisor = "";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CSClass::GetDefaultConnect()
{
	return _T("DSN=teaching;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=teaching");
}

CString CSClass::GetDefaultSQL()
{
	return _T("[dbo].[SClass]");
}

void CSClass::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[ClassNo]"), m_ClassNo);
	RFX_Text(pFX, _T("[ClassName]"), m_ClassName);
	RFX_Text(pFX, _T("[Major]"), m_Major);
	RFX_Text(pFX, _T("[Grade]"), m_Grade);
	RFX_Int(pFX, _T("[Number]"), m_Number);
	RFX_Text(pFX, _T("[Advisor]"), m_Advisor);

}
/////////////////////////////////////////////////////////////////////////////
// CSClass 诊断

#ifdef _DEBUG
void CSClass::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSClass::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


