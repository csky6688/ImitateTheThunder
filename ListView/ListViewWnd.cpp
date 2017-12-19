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
		/*CDialogBuilder builder;
		CListContainerElementUI* pItem = (CListContainerElementUI*)builder.Create(L"ListItemLayout.xml");
		CTabLayoutUI* pTabUI = (CTabLayoutUI*)pItem->FindSubControl(L"tab");
		pTabUI->SelectItem(0);
		pList->Add(pItem);*/
		for (int i = 0; i < 10; i++)
		{
			AddListItem();
		}
	}
}

void CListViewWnd::AddListItem()
{
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("list")));
	CDialogBuilder builder;
	CListContainerElementUI* pItem = static_cast<CListContainerElementUI*>(builder.Create(L"ListItemLayout.xml"));
	pItem->OnNotify += MakeDelegate(this, &CListViewWnd::OnListItemNotify);

	//CButtonUI* pButtonUI = static_cast<CButtonUI*>(pItem->FindSubControl(L"delete"));
	//pButtonUI->OnNotify += MakeDelegate(this, &CListViewWnd::OnClickedDelete);
	pList->Add(pItem);
}


/**
 * \brief 
 * \param param 
 * \return 
 */
bool CListViewWnd::OnListItemNotify(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);
	if (msg->sType == DUI_MSGTYPE_ITEMCLICK)
	{
		CListContainerElementUI* pItem = static_cast<CListContainerElementUI*>(msg->pSender);
		CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(pItem->FindSubControl(L"tab"));
		pTabUI->SelectItem(1);
	}

	return true;
}

bool CListViewWnd::OnClickedDelete(void* param)
{
	TNotifyUI* msg = static_cast<TNotifyUI*>(param);
	if (msg->sType == DUI_MSGTYPE_CLICK)
	{
		::MessageBoxW(m_hWnd, L"DUI_MSGTYPE_CLICK", L"Text", MB_OK);
	}

	return true;
}