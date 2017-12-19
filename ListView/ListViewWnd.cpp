#include "stdafx.h"
#include "ListViewWnd.h"


CListViewWnd::CListViewWnd()
{
}


CListViewWnd::~CListViewWnd()
{
}



LPCTSTR CListViewWnd::GetWindowClassName() const
{
	return L"ListViewWnd";
}

DuiLib::CDuiString CListViewWnd::GetSkinFile()
{
	return L"MainFrame.xml";
}

DuiLib::CDuiString CListViewWnd::GetSkinFolder()
{
	return L"list";
}

CControlUI * CListViewWnd::CreateControl(LPCTSTR pstrClass)
{
	CDialogBuilder builder;
	CControlUI* pUI = NULL;
	if (_tcsicmp(pstrClass, L"ListView") == 0)
	{
		pUI = builder.Create(L"ListView.xml");
	}

	return pUI;
}

void CListViewWnd::InitWindow()
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
		for (int i = 0; i < 10;i++)
		{
			AddListItem();
		}
	}
}

void CListViewWnd::AddListItem()
{
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list"));
	CDialogBuilder builder;
	CListContainerElementUI* pItem = (CListContainerElementUI*)builder.Create(L"ListItem.xml");
	pList->Add(pItem);
}