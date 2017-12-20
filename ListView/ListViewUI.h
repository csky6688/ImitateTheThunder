#pragma once
class CListViewUI:public CListUI
{
public:
	CListViewUI();
	~CListViewUI();

	bool SetActive(int iIndex,bool bTakeFocus);
};

