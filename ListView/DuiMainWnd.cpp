#include "stdafx.h"
#include "DuiMainWnd.h"
//#include <afx.h>

#include "ListItemUI.h"


CDuiMainWnd::CDuiMainWnd()
{
}


CDuiMainWnd::~CDuiMainWnd()
{
}



LPCTSTR CDuiMainWnd::GetWindowClassName() const
{
	return L"ListViewWnd";
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
	CDialogBuilder builder;
	CControlUI* pUI = NULL;
	if (_tcsicmp(pstrClass, L"ListView") == 0)
	{
		pUI = builder.Create(L"ListView.xml");
	}
	if (_tcsicmp(pstrClass, L"ListItem") == 0)
		return	new CListItemUI();

	return pUI;
}

void CDuiMainWnd::InitWindow()
{
	m_PaintManager.AddFont(0, L"ËÎÌו", 18, true, false, false, true);
	m_PaintManager.AddFont(1, L"ËÎÌו", 18, false, false, false, true);
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list"));
	if (pList == NULL)
	{
		::MessageBox(NULL, L"List NULL", L"Error", NULL);
		return;
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			AddListItem();
		}
	}
}

void CDuiMainWnd::AddListItem()
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));
	CDialogBuilder builder;
	CListItemUI* pItem = static_cast<CListItemUI*>(builder.Create(L"ListItemAllLayout.xml", (UINT)0, this, &m_PaintManager));
	//CTextUI* pTextUI = pItem->FindSubControl(L"");
	pItem->SetItemName(L"hahaha");
	pList->Add(pItem);
}


