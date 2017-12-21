#include "stdafx.h"
#include "DuiMainWnd.h"

#include "ListViewUI.h"


CDuiMainWnd::CDuiMainWnd()
{
}


CDuiMainWnd::~CDuiMainWnd()
{
}



LPCTSTR CDuiMainWnd::GetWindowClassName() const
{
	return L"DuiMainWnd";
}

DuiLib::CDuiString CDuiMainWnd::GetSkinFile()
{
	return L"MainFrame.xml";
}

DuiLib::CDuiString CDuiMainWnd::GetSkinFolder()
{
	return L"list";
}

CControlUI * CDuiMainWnd::CreateControl(LPCTSTR pstrClass)
{
	CControlUI* pUI = NULL;
	if (_tcsicmp(pstrClass, L"ListView") == 0)
		return	new CListViewUI();

	return pUI;
}

void CDuiMainWnd::InitWindow()
{
	m_PaintManager.AddFont(0, L"ËÎÌו", 18, true, false, false, true);
	m_PaintManager.AddFont(1, L"ËÎÌו", 18, false, false, false, true);
}

void CDuiMainWnd::Notify(TNotifyUI& msg)
{
	CListViewUI* pListView = (CListViewUI*)m_PaintManager.FindControl(L"mylist");

	if (msg.sType == DUI_MSGTYPE_ITEMSELECT)
	{
		int index = pListView->GetCurSel();
		pListView->SetActiveItem(index, true);
	}

	__super::Notify(msg);
}


