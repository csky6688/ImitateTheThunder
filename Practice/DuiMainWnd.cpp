
#include "stdafx.h"
#include "DuiMainWnd.h"

//#include "../Ext/UIColorSkin.h"

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
	m_PaintManager.AddFont(0, L"Microsoft YaHei UI", 20, false, false, false, true);
	COptionUI* pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optButton")));
	if (pOpt != NULL)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optTile")));
	if (pOpt != NULL)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optList")));
	if (pOpt != NULL)
		pOpt->SetFont(0);

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


void CDuiMainWnd::TreeNodeItemEvent()
{

}

void CDuiMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == L"selectchanged")
	{
		CDuiString strName = msg.pSender->GetName();
		CTabLayoutUI* pUI = (CTabLayoutUI*)m_PaintManager.FindControl(L"tab");

		if (strName == L"optButton")
			pUI->SelectItem(0);
		else if (strName == L"optTile")
			pUI->SelectItem(1);
		else if (strName == L"optList")
			pUI->SelectItem(2);
	}


	__super::Notify(msg);
}
