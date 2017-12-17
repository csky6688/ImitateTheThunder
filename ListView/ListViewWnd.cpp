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
	
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list"));
	if (pList == NULL)
	{
		::MessageBox(NULL, L"List NULL", L"Error", NULL);
		return;
	}
	else
	{
		/*CListTextElementUI* pItem = new CListTextElementUI();
		pList->Add(pItem);

		pItem->SetText(0, L"1");
		pItem->SetText(1, L"1");
		pItem->SetText(2, L"1");*/
		CDialogBuilder builder;
		CListContainerElementUI* pItem = (CListContainerElementUI*)builder.Create(L"ListItem.xml");
		CTextUI* pText = (CTextUI*)pItem->FindSubControl(L"data");
		CDuiRect rect = pText->GetRelativePos();

		//pItem->SetMinHeight(rect.GetHeight() + 20);



		pItem->SetFixedHeight(rect.GetHeight() + 20);

		pList->Add(pItem);
		/*	CDialogBuilder builder2;
			CListContainerElementUI* pItem1 = (CListContainerElementUI*)builder2.Create(L"ListItem.xml");
			pList->Add(pItem1);
			CDialogBuilder builder3;
			CListContainerElementUI* pItem2 = (CListContainerElementUI*)builder3.Create(L"ListItem.xml");
			pList->Add(pItem2);*/
	}

}