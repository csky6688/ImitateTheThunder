#pragma once
#include "stdafx.h"


class CListItemUI:public CListContainerElementUI
{
public:
	CListItemUI();
	~CListItemUI();

	LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);
	void DoEvent(TEventUI& event);
};

