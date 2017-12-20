#include "stdafx.h"
#include "ListViewUI.h"


CListViewUI::CListViewUI()
{
}


CListViewUI::~CListViewUI()
{
}

bool CListViewUI::SetActive(int iIndex, bool bTakeFocus)
{
	if (!__super::SelectItem(iIndex,bTakeFocus))
	{
		return false;
	}

	return true;
}
