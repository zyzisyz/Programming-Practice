// Grade.h : Grade 类的实现



// Grade 实现

// 代码生成在 2018年6月17日, 23:26

#include "stdafx.h"
#include "Grade.h"
IMPLEMENT_DYNAMIC(Grade, CRecordset)

Grade::Grade(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_dboChoiceSNo = "";
	m_dboChoiceCourseNO = "";
	m_dboChoiceSscore = 0;
	m_dboCourseCourseName = "";
	m_dboCourseCourseNO = "";
	m_dboCStudentSName = "";
	m_dboCStudentSNo = "";
	m_dboCStudentSMajor = "";
	m_dboCStudentSSex = "";
	m_dboCStudentSBirthDate = "";
	m_dboCStudentSSchoolDate = "";
	m_nFields = 12;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Grade::GetDefaultConnect()
{
	return _T("DSN=StudentInfoDB;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=DESKTOP-JOCIPPU;DATABASE=StudentInfoDB");
}

CString Grade::GetDefaultSQL()
{
	return _T("[dbo].[Choice],[dbo].[Course],[dbo].[CStudent]");
}

void Grade::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[dbo].[Choice].[SNo]"), m_dboChoiceSNo);
	RFX_Text(pFX, _T("[dbo].[Choice].[CourseNO]"), m_dboChoiceCourseNO);
	RFX_Long(pFX, _T("[dbo].[Choice].[Sscore]"), m_dboChoiceSscore);
	RFX_Text(pFX, _T("[dbo].[Course].[CourseName]"), m_dboCourseCourseName);
	RFX_Text(pFX, _T("[dbo].[Course].[CourseNO]"), m_dboCourseCourseNO);
	RFX_Long(pFX, _T("[dbo].[Course].[CourseCredit]"), m_dboCourseCourseCredit);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SName]"), m_dboCStudentSName);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SNo]"), m_dboCStudentSNo);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SMajor]"), m_dboCStudentSMajor);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SSex]"), m_dboCStudentSSex);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SBirthDate]"), m_dboCStudentSBirthDate);
	RFX_Text(pFX, _T("[dbo].[CStudent].[SSchoolDate]"), m_dboCStudentSSchoolDate);

}
/////////////////////////////////////////////////////////////////////////////
// Grade 诊断

#ifdef _DEBUG
void Grade::AssertValid() const
{
	CRecordset::AssertValid();
}

void Grade::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


