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
	void ColorInit();
	void Arr(BYTE* str, int pos, int len);
	DWORD Array2ARGB(BYTE* array);
	vector<BYTE> list;
	vector<DWORD> m_colorList;

	CTreeNodeUI* pNode;
};

