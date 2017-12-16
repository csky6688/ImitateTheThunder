#pragma once
class CListViewWnd:public WindowImplBase
{
public:
	CListViewWnd();
	~CListViewWnd();

	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();

	virtual void InitWindow();

};

