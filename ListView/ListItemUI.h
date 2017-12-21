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

	LPCTSTR m_strItemName;
	LPCTSTR m_strItemContent;
	LPCTSTR m_strItemInfo;

	//bool Select(bool bSelect = true, bool bTriggerEvent = true) override;

	void SetActive(bool bActive = true);

	bool m_bActive;

	void SetItemName(LPCTSTR strName);
	void SetItemContent(LPCTSTR strContent);
	void SetItemInfo(LPCTSTR strInfo);
};

