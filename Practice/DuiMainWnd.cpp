
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
	CLabelUI* pLabel = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("btndemotext")));
	if (pLabel != NULL)
	{
		pLabel->SetFont(0);
	}
	pLabel = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("tiledemotext")));
	if (pLabel != NULL)
	{
		pLabel->SetFont(0);
	}

	CTreeNodeUI* pTab = static_cast<CTreeNodeUI*>(m_PaintManager.FindControl(_T("tiledemo")));
	pTab->OnNotify += MakeDelegate(this,&TreeNodeItemEvent);
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
	/*else if (_tcscmp(pstrClassName, L"MyColorSkin") == 0)
	{
	CColorSkinUI* color = new CColorSkinUI();
	pUI = color;
	}*/
	return pUI;

	//return NULL;
}


void CDuiMainWnd::TreeNodeItemEvent()
{

}

void CDuiMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType = DUI_MSGTYPE_ITEMACTIVATE)
	{
		if (msg.pSender->GetName() == L"tiledemo")
		{
			MessageBox(NULL, L"1", L"123", NULL);

			CTabLayoutUI* pTab = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab")));
			pTab->SelectItem(1);
		}
		else
		{
			CTabLayoutUI* pTab = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab")));
			pTab->SelectItem(0);
		}
	}

	__super::Notify(msg);
}
