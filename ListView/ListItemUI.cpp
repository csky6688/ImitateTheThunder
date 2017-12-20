#include "stdafx.h"
#include "ListItemUI.h"


CListItemUI::CListItemUI()
{
	DUI__Trace(L"\t------CListItemUI\n");

	m_strItemName = L"test";
	m_strItemContent = L"abc12345lalalala";
	m_strItemInfo = L"Hello World,Hello Duilib";
}


CListItemUI::~CListItemUI()
{
}

LPCTSTR CListItemUI::GetClass() const
{
	return L"ListItemUI";
}

void CListItemUI::DoEvent(TEventUI& event)
{
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));

	if (event.Type == UIEVENT_MOUSEENTER)
	{
		this->SetFixedHeight(50);
		pTabUI->SelectItem(1);
	}
	else if (event.Type == UIEVENT_MOUSELEAVE)
	{
		this->SetFixedHeight(50);
		pTabUI->SelectItem(0);
	}

	DUI__Trace(L"\t---------------->%d\n", event.Type);

	CListContainerElementUI::DoEvent(event);
}

LPVOID CListItemUI::GetInterface(LPCTSTR pstrName)
{
	if (_tcscmp(pstrName, L"ListItem") == 0) 
		return static_cast<CListItemUI*>(this);
	return CListContainerElementUI::GetInterface(pstrName);
}

void CListItemUI::SetItemName(LPCTSTR strName)
{
	m_strItemName = strName;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));
	int count = 3/*pTabUI->GetCount()*/;
	for (int i = 0; i < count; i++)
	{
		CContainerUI* pContainerUI = static_cast<CContainerUI*>(pTabUI->GetItemAt(i));
		CTextUI* pTextUI = static_cast<CTextUI*>(pContainerUI->FindSubControl(L"name"));
		pTextUI->SetText(strName);
	}

	//this->Invalidate();
}

void CListItemUI::SetItemContent(LPCTSTR strContent)
{
	m_strItemContent = strContent;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));
	int count = 3 /*pTabUI->GetCount()*/;
	for (int i = 0; i < count; i++)
	{
		CContainerUI* pContainerUI = static_cast<CContainerUI*>(pTabUI->GetItemAt(i));
		CTextUI* pTextUI = static_cast<CTextUI*>(pContainerUI->FindSubControl(L"content"));
		pTextUI->SetText(strContent);
	}
}

void CListItemUI::SetItemInfo(LPCTSTR strInfo)
{
	m_strItemInfo = strInfo;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));

	CContainerUI* pContainerUI = static_cast<CContainerUI*>(pTabUI->GetItemAt(2));
	CTextUI* pTextUI = static_cast<CTextUI*>(pContainerUI->FindSubControl(L"info"));
	pTextUI->SetText(strInfo);
}

void CListItemUI::SetActive(bool bActive /*= true*/)
{
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));

	this->SetFixedHeight(80);
	pTabUI->SelectItem(2);
}

//bool CListItemUI::Select(bool bSelect /*= true*/, bool bTriggerEvent /*= true*/)
//{
//	return CListContainerElementUI::Select(bSelect, bTriggerEvent);
//}
