#pragma once

#include "stdafx.h"
#include "ListItemUI.h"

class CListViewUI:public CListUI,public IDialogBuilderCallback/*,INotifyUI*/
{
public:
	CListViewUI();
	~CListViewUI();

	LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);
	UINT GetControlFlags() const;

	void DoInit();

	void DoEvent(TEventUI& event);

	int m_nActiveItem;
	bool SetActiveItem(int iIndex,bool bTakeFocus);
	CControlUI* CreateControl(LPCTSTR pstrClass);
};

