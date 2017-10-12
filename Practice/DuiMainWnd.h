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

	virtual void Notify(TNotifyUI& msg);

	virtual CControlUI* CreateControl(LPCTSTR pstrClassName);
	void TreeNodeItemEvent();
};

