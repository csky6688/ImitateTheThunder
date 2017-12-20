#pragma once

#include "stdafx.h"
#include "ListItemUI.h"

class CListViewUI:public CListUI
{
public:
	CListViewUI(CPaintManagerUI& paintManager);
	~CListViewUI();

	int m_nActiveItem;
	CPaintManagerUI& m_paintManager;
	bool SetActiveItem(int iIndex,bool bTakeFocus);
	CControlUI* CreateControl(LPCTSTR pstrClass);
};

