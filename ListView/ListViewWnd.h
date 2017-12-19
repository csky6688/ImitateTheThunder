#pragma once
class CListViewWnd:public WindowImplBase
{
public:
	CListViewWnd();
	~CListViewWnd();

	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual void InitWindow();
	void AddListItem();
};

