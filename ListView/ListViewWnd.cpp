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

void CListViewWnd::InitWindow()
{
}