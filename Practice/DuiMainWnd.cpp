
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
	srand((unsigned int)(time(NULL)));

	m_PaintManager.RemoveAllFonts(true);
	m_PaintManager.AddFont(0, L"Microsoft YaHei UI", 20, false, false, false, true);
	COptionUI* pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optButton")));
	if (pOpt != NULL)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optTile")));
	if (pOpt != NULL)
		pOpt->SetFont(0);
	pOpt = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("optList")));
	if (pOpt != NULL)
		pOpt->SetFont(0);

	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list"));
	if (pList == NULL)
	{
		::MessageBox(NULL, L"List NULL", L"Error", NULL);
		return;
	}

	CDialogBuilder builder;
	CListContainerElementUI* pElem = NULL;

	pElem = (CListContainerElementUI*)builder.Create(L"ListItem.xml");

	pList->Add(pElem);

	ColorInit();


	CTileLayoutUI* pTile = static_cast<CTileLayoutUI*>(m_PaintManager.FindControl(_T("colortile")));

	CButtonUI* pColor = NULL; 
	//CControlUI

	for (size_t i = 0; i < m_colorList.size();i++)
	{
		pColor = new CButtonUI();
		pColor->SetBkColor(m_colorList[i]);
		pTile->Add(pColor);
	}

}


void CDuiMainWnd::ColorInit()
{
	//0 32 64 96 128 160 192 224 256
	
	//for (int i = 0; i < 9; i++)
	{
		list.push_back(0);
		list.push_back(32);
		list.push_back(64);
		list.push_back(96);
		list.push_back(128);
		list.push_back(160);
		list.push_back(192);
		list.push_back(224);
		list.push_back(255);
	}

	int maxLength = 4;
	BYTE* str = new BYTE[4];

	Arr(str,0,4);
}

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define ARGB(a,r,g,b)          ((COLORREF)(((BYTE)(a)|((WORD)((BYTE)(r))<<8))|(((DWORD)(BYTE)(g))<<16)|(((DWORD)(BYTE)(g))<<24)))

DWORD CDuiMainWnd::Array2ARGB(BYTE* array)
{
	return ARGB(array[0], array[1], array[2], array[3] );
}

void CDuiMainWnd::Arr(BYTE* str, int pos, int len)
{
	//CStdioFile file;
	//file.Open(L"array.txt",CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	for (size_t i = 0; i < list.size(); i++)
	{
		str[pos] = list[i];

		if (pos == len - 1)
		{
			if (str[0] == 0) continue;
			CString text;
			text.Format(L"%02x%02x%02x%02x", str[0], str[1], str[2], str[3]);
			LPTSTR pstr = NULL;
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
	CControlUI* pUI = NULL;
	if (_tcsicmp(pstrClassName, L"LeftPane") == 0)
	{
		pUI = builder.Create(L"leftPane.xml");
	}
	else if (_tcsicmp(pstrClassName, L"RightPane") == 0)
	{
		pUI = builder.Create(L"rightPane.xml");
	}
	return pUI;


	//return NULL;
}



void CDuiMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == L"selectchanged")
	{
		CDuiString strName = msg.pSender->GetName();
		CTabLayoutUI* pUI = (CTabLayoutUI*)m_PaintManager.FindControl(L"tab");

		if (strName == L"optButton")
			pUI->SelectItem(0);
		else if (strName == L"optTile")
			pUI->SelectItem(1);
		else if (strName == L"optList")
			pUI->SelectItem(2);
	}
	else if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName();
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list"));
		if (strName == L"addListItem")
		{
			CDialogBuilder builder;
			CListContainerElementUI* pElem = NULL;
			pElem = (CListContainerElementUI*)builder.Create(L"ListItem.xml");

			CControlUI* pImage = pElem->FindSubControl(L"itemimage");
			int index = rand() % 6;
			CString strImage;
			strImage.Format(L"image/practice (%d).png",index+1);
			pImage->SetBkImage(strImage);

			CTextUI* pNick = (CTextUI*)pElem->FindSubControl(L"nick");
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
	}


	__super::Notify(msg);
}
