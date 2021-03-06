#include "stdafx.h"
#pragma once

#include "DuiMainWnd.h"

#include "ARGB.h"

CDuiMainWnd::CDuiMainWnd()
{
	pNode = nullptr;
}

CDuiMainWnd::~CDuiMainWnd()
{
}

LPCTSTR CDuiMainWnd::GetWindowClassName() const
{
	return L"DuiMainWnd";
}

CDuiString CDuiMainWnd::GetSkinFile()
{
	return L"mainFrame.xml";
}

CDuiString CDuiMainWnd::GetSkinFolder()
{
	return L"practice";
}

void CDuiMainWnd::InitWindow()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	m_PaintManager.RemoveAllFonts(true);
	m_PaintManager.AddFont(0, L"Microsoft YaHei UI", 20, false, false, false, true);
	COptionUI* pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optButton")));
	if (pOpt != nullptr)
		pOpt->SetFont(0);

	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optTile")));
	if (pOpt != nullptr)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optList")));
	if (pOpt != nullptr)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optGif")));
	if (pOpt != nullptr)
		pOpt->SetFont(0);

	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));
	if (pList == nullptr)
	{
		::MessageBox(nullptr, L"List NULL", L"Error", NULL);
		return;
	}

	CDialogBuilder builder;
	CListContainerElementUI* pElem = nullptr;

	pElem = static_cast<CListContainerElementUI*>(builder.Create(L"ListItem.xml"));

	pList->Add(pElem);

	pNode = static_cast<CTreeNodeUI*>(m_PaintManager.FindControl(_T("tree_node_head")));

	ColorInit();
	CTileLayoutUI* pTile = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(_T("colortile")));
	CButtonUI* pColor = nullptr;
	for (size_t i = 0; i < m_colorList.size(); i++)
	{
		pColor = new CButtonUI();
		pColor->SetBkColor(m_colorList[i]);
		pTile->Add(pColor);

		pColor->OnNotify += MakeDelegate(this, &CDuiMainWnd::OnClickedColorButton);
	}

	CTileLayoutUI* pTileGreen = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(L"gtile"));
	for (WORD i = 0; i < 255; i++)
	{
		pColor = new CButtonUI();
		pColor->SetBkColor(ARGB(255,255,i,255));
		pTileGreen->Add(pColor);

		pColor->OnNotify += MakeDelegate(this, &CDuiMainWnd::OnClickedGreenColorButton);
	}

	CTileLayoutUI* pTile1 = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(L"tilelayout"));
	CTileLayoutUI* pTile2 = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(L"tilelayout2"));

	pTile1->OnNotify += MakeDelegate(this, &CDuiMainWnd::OnClickedTileItem);

	/*CDialogBuilder builder2;
	CContainerUI* pTileItem = (CContainerUI*)builder2.Create(L"TileItem.xml", NULL, NULL, &m_PaintManager, NULL);

	CTileLayoutUI* pTileDemo = (CTileLayoutUI*)m_PaintManager.FindControl(L"tileLarge");
	if (pTileDemo && pTileItem)
		pTileDemo->Add(pTileItem);
	else
		::MessageBox(NULL,L"TileError",NULL,NULL);*/

	CComboUI* pCombo = static_cast<CComboUI*>(m_PaintManager.FindControl(L"combodemo"));
	pCombo->SetHotItemTextColor(0xFFFFFF00);
	pCombo->SetItemTextColor(0xFFFF00FF);
	pCombo->SetSelectedItemTextColor(0xFF00FFFF);
}


bool CDuiMainWnd::OnClickedTileItem(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);

	::MessageBox(nullptr, L"Tile", nullptr,NULL);

	return true;
}

bool CDuiMainWnd::OnClickedColorButton(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);
	CTileLayoutUI* pTile = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(_T("gtile")));
	if (msg->sType = DUI_MSGTYPE_CLICK)
	{
		CButtonUI* pBtn = static_cast<CButtonUI*>(msg->pSender);
		DWORD bkcolor = pBtn->GetBkColor();
		m_PaintManager.FindControl(L"min2")->SetBkColor(bkcolor);
		m_PaintManager.FindControl(L"max2")->SetBkColor(bkcolor);
		m_PaintManager.FindControl(L"restore2")->SetBkColor(bkcolor);

		m_PaintManager.FindControl(L"min")->SetBkColor(bkcolor);
		m_PaintManager.FindControl(L"max")->SetBkColor(bkcolor);
		m_PaintManager.FindControl(L"res")->SetBkColor(bkcolor);


		for (int i = 0; i < 255; i++)
		{
			CButtonUI* pButton = static_cast<CButtonUI*>(pTile->GetItemAt(i));
			pButton->SetBkColor(ARGB(255, GetRValueOfARGB(bkcolor), i, GetBValueOfARGB(bkcolor)));
		}
	}
	return true;
}


bool CDuiMainWnd::OnClickedGreenColorButton(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);
	CTileLayoutUI* pTile = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(_T("colortile")));
	if (msg->sType == DUI_MSGTYPE_CLICK)
	{
		CButtonUI* pBtn = static_cast<CButtonUI*>(msg->pSender);
		DWORD gColor = pBtn->GetBkColor();

		for (size_t i = 0; i < m_colorList.size(); i++)
		{
			CButtonUI* pButton = static_cast<CButtonUI*>(pTile->GetItemAt(i));
			DWORD bkcolor2 = pButton->GetBkColor();
			DWORD bkcolor = SetGValueOfARGB(bkcolor2, GetGValueOfARGB(gColor));
			pButton->SetBkColor(bkcolor);
		}
	}

	return true;
}

void CDuiMainWnd::ColorInit()
{
	BYTE color[4];
	memset(color, 0, 4);
	color[0] = 0xff;
	color[2] = 100;
	for (int i = 0; i < 255; i++)
	{
		color[1] = i;
		for (int j = 0; j < 255; j++)
		{
			color[3] = j;

			CString text;
			text.Format(L"%02x%02x%02x%02x", color[0], color[1], color[2], color[3]);
			LPTSTR pstr = nullptr;
			m_colorList.push_back(_tcstoul(text, &pstr, 16));
		}
	}
}


DWORD CDuiMainWnd::Array2ARGB(BYTE* array)
{
	return ARGB(array[0], array[1], array[2], array[3] );
}

void CDuiMainWnd::Arr(BYTE* str, int pos, int len)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		str[pos] = list[i];

		if (pos == len - 1)
		{
			if (str[0] == 0) continue;
			CString text;
			text.Format(L"%02x%02x%02x%02x", str[0], str[1], str[2], str[3]);
			LPTSTR pstr = nullptr;
			m_colorList.push_back(_tcstoul(text, &pstr, 16));
		}
		else
		{
			Arr(str, pos + 1, len);
		}
	}
}


CControlUI* CDuiMainWnd::CreateControl(LPCTSTR pstrClassName)
{
	CDialogBuilder builder;
	CControlUI* pUI = nullptr;
	if (_tcsicmp(pstrClassName, L"LeftPane") == 0)
	{
		pUI = builder.Create(L"leftPane.xml");
	}
	else if (_tcsicmp(pstrClassName, L"RightPane") == 0)
	{
		pUI = builder.Create(L"rightPane.xml");
	}
	return pUI;
}


void CDuiMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == L"selectchanged")
	{
		CDuiString strName = msg.pSender->GetName();
		CTabLayoutUI* pUI = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(L"tab"));

		if (strName == L"optButton")
			pUI->SelectItem(0);
		else if (strName == L"optTile")
			pUI->SelectItem(1);
		else if (strName == L"optList")
			pUI->SelectItem(2);
		else if (strName == L"optGif")
			pUI->SelectItem(3);
	}
	else if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetParent()->GetName() == L"tilelayout")
		{
			CTileLayoutUI* pTile = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(L"tilelayout"));

			CButtonUI* pButton = static_cast<CButtonUI*>(msg.pSender);
			int index = pTile->GetItemIndex(msg.pSender);
			CDuiString text;
			text.Format(L"%d", index);
			pButton->SetText(text);
			pButton->SetFont(0);
		}
		CDuiString strName = msg.pSender->GetName();
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));
		CTreeViewUI* pTree = static_cast<CTreeViewUI*>(m_PaintManager.FindControl(_T("tree")));
		CDialogBuilder builder;
		if (strName == L"addListItem")
		{
			CListContainerElementUI* pElem = nullptr;
			pElem = static_cast<CListContainerElementUI*>(builder.Create(L"ListItem.xml"));

			CControlUI* pImage = pElem->FindSubControl(L"itemimage");
			int index = rand() % 6;
			CString strImage;
			strImage.Format(L"image/practice (%d).png", index + 1);
			pImage->SetBkImage(strImage);

			CTextUI* pNick = static_cast<CTextUI*>(pElem->FindSubControl(L"nick"));
			CString strNick;
			strNick.Format(L"NickName%ld", rand());
			pNick->SetText(strNick);

			pList->Add(pElem);
		}
		else if (strName == L"delListItem")
		{
			int index = pList->GetCurSel();
			int count = pList->GetCount();

			if (index > -1 && index < count)
			{
				pList->RemoveAt(index);
			}
		}
		else if (strName == L"addTreeNode")
		{
		}
	}

	else if (msg.sType == DUI_MSGTYPE_ITEMCLICK)
	{
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));

		pList->OnNotify += MakeDelegate(this, &CDuiMainWnd::OnClickedList);
	}

	__super::Notify(msg);
}


bool CDuiMainWnd::OnClickedList(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));
	if (msg->sType == DUI_MSGTYPE_ITEMSELECT)
	{
		int nIndex = pList->GetCurSel();
		CString text;
		text.Format(L"%d", nIndex);
		::MessageBox(nullptr, text, L"2", MB_OK);
	}
	return true;
}
