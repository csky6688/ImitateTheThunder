#include "stdafx.h"
#include "ListViewUI.h"


CListViewUI::CListViewUI()
{
	m_nActiveItem = -1;
	DUI__Trace(L"\t------CListViewUI");
}


CListViewUI::~CListViewUI()
{
}


LPCTSTR CListViewUI::GetClass() const
{
	return _T("CustomLayout");
}
LPVOID CListViewUI::GetInterface(LPCTSTR pstrName)
{
	if (_tcscmp(pstrName, _T("ListView")) == 0) 
		return static_cast<CListViewUI*>(this);
	return CListUI::GetInterface(pstrName);
}
UINT CListViewUI::GetControlFlags() const
{
	return CListUI::GetControlFlags();
}

void CListViewUI::DoInit()
{

	for (int i = 0; i < 20;i++)
	{
		CDialogBuilder builder;
		CListItemUI* pItem = static_cast<CListItemUI*>(builder.Create(L"ListItemAllLayout.xml", (UINT)0, this, m_pManager));

		CDuiString text;
		text.Format(L"test-%02d", i);
		pItem->SetItemName(text);
		Add(pItem);
	}
}


bool CListViewUI::SetActiveItem(int iIndex, bool bTakeFocus)
{
	if (!__super::SelectItem(iIndex,bTakeFocus))
	{
		return false;
	}

	if (m_nActiveItem != -1)
	{
		CListItemUI* pItem = (CListItemUI*)this->GetItemAt(m_nActiveItem);
		pItem->SetActive(false);
	}
	m_nActiveItem = iIndex;
	if (m_nActiveItem != -1)
	{
		CListItemUI* pItem = (CListItemUI*)this->GetItemAt(m_nActiveItem);
		pItem->SetActive(true);
	}

	return true;
}

CControlUI* CListViewUI::CreateControl(LPCTSTR pstrClass)
{
	if (_tcsicmp(pstrClass, L"ListItem") == 0)
		return	new CListItemUI();
	

	return NULL;
}

void CListViewUI::DoEvent(TEventUI& event)
{
	if (event.Type == UIEVENT_MOUSEENTER)
	{
	
	}
	//DUI__Trace(L"\t---------------->%d\n", event.Type);

	CListUI::DoEvent(event);
}
