#include "stdafx.h"
#include "ListItemUI.h"


CListItemUI::CListItemUI()

{
	DUI__Trace(L"\t-----------------%dCListItemUI\n");
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
	if (event.Type == UIEVENT_MOUSEENTER)
	{
		::MessageBox(NULL,L"UIEVENT_MOUSEENTER",L"Event",MB_OK);
	}

	DUI__Trace(L"\t-----------------%d\n", event.Type);
	
	CListContainerElementUI::DoEvent(event);
}

LPVOID CListItemUI::GetInterface(LPCTSTR pstrName)
{
	if (_tcscmp(pstrName, L"ListItem") == 0) 
		return static_cast<CListItemUI*>(this);
	return CListContainerElementUI::GetInterface(pstrName);
}
