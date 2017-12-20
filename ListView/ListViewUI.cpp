#include "stdafx.h"
#include "ListViewUI.h"


CListViewUI::CListViewUI(CPaintManagerUI& paintManager)
	:m_paintManager(paintManager)
{
	m_nActiveItem = -1;
	//m_paintManager = paintManager;
}


CListViewUI::~CListViewUI()
{
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