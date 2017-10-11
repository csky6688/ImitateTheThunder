#include "stdafx.h"
#include "DuiMainWnd.h"


CDuiMainWnd::CDuiMainWnd()
{
}


CDuiMainWnd::~CDuiMainWnd()
{
}



LPCTSTR CDuiMainWnd::GetWindowClassName() const
{
	return L"DuiMainFrame";
}

DuiLib::CDuiString CDuiMainWnd::GetSkinFile()
{
	return L"mainFrame.xml";
}

DuiLib::CDuiString CDuiMainWnd::GetSkinFolder()
{
	return L"practice";
}

void CDuiMainWnd::InitWindow()
{
	m_PaintManager.RemoveAllFonts(true);
	m_PaintManager.AddFont(0, L"Microsoft YaHei UI", 20, false, false, true, true);
	CTextUI* pLabel = (CTextUI*)m_PaintManager.FindControl(_T("itemText1"));
	if (pLabel != NULL)
	{
		pLabel->SetFont(0);
	}
}

CControlUI* CDuiMainWnd::CreateControl(LPCTSTR pstrClassName)
{
	CDialogBuilder builder;
	CControlUI* pUI = NULL;
	if (_tcsicmp(pstrClassName, L"LeftPane") == 0)
	{
		pUI = builder.Create(L"leftPane.xml");
	}
	else if (_tcsicmp(pstrClassName, L"RightPane") == 0)
	{
		pUI = builder.Create(L"rightPane.xml");
	}
	return pUI;

	//return NULL;
}

