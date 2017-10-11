#pragma once
class CDuiMainWnd :public WindowImplBase
{
public:
	CDuiMainWnd();
	~CDuiMainWnd();

	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();

	virtual void InitWindow();

	virtual CControlUI* CreateControl(LPCTSTR pstrClassName);
};

