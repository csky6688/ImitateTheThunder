#include "stdafx.h"
#include "ListItemUI.h"


CListItemUI::CListItemUI()
{
	DUI__Trace(L"\t------CListItemUI");

	m_strItemName = L"test";
	m_strItemContent = L"abc12345lalalala";
	m_strItemInfo = L"Hello World,Hello Duilib";

	m_bActive = false;

	m_wndItemInfo = NULL;
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

	if (!m_bActive)
	{
		if (event.Type == UIEVENT_MOUSEENTER)
		{
			this->SetFixedHeight(50);
			pTabUI->SelectItem(1);
		}
		else if (event.Type == UIEVENT_MOUSELEAVE)
		{
			this->SetFixedHeight(50);
			pTabUI->SelectItem(0);


			//SetTimer(1000);

			if (m_wndItemInfo)
			{
				m_wndItemInfo->Close();
				//delete m_wndItemInfo;
				m_wndItemInfo = NULL;
			}
		}
		else if (event.Type == UIEVENT_MOUSEHOVER)
		{
			if (m_wndItemInfo== NULL)
			{
				RECT rect = GetPos();
				POINT pos;
				pos.x = rect.left;
				pos.y = rect.top;
				::ClientToScreen(m_pManager->GetPaintWindow(), &pos);
				m_wndItemInfo = new CItemInfoWnd();
				m_wndItemInfo->Create(m_pManager->GetPaintWindow(), L"ItemInfo", UI_WNDSTYLE_FRAME,
					WS_EX_WINDOWEDGE, CDuiRect(GetPos().left + 300, GetRelativePos().top, 250, 100));

				::SetWindowPos(m_wndItemInfo->GetHWND(), HWND_TOP, pos.x + 300, pos.y, 250, 100, SWP_SHOWWINDOW);
				m_wndItemInfo->ShowWindow(true);
			}
		}
	}
	CListContainerElementUI::DoEvent(event);
}

void CListItemUI::CloseInfoWnd()
{
	if (m_wndItemInfo)
		::KillTimer(m_wndItemInfo->GetHWND(), 1);
	m_wndItemInfo->Close();
	//delete m_wndItemInfo;
	m_wndItemInfo = NULL;
}


void CListItemUI::SetTimer(UINT uElapse)
{
	if (m_wndItemInfo)
		::SetTimer(m_wndItemInfo->GetHWND(), 1, uElapse, NULL);
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
	m_bActive = bActive;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(L"tab"));


	if (m_bActive)
	{
		this->SetFixedHeight(80);
		pTabUI->SelectItem(2);
	}
	else
	{
		this->SetFixedHeight(50);
		pTabUI->SelectItem(0);
	}
}




