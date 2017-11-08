#pragma once

#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))


#define GetAValueOfARGB(argb) (LOBYTE(argb))
#define GetRValueOfARGB(argb) (LOBYTE(((WORD)(argb)) >> 8)) 
#define GetGValueOfARGB(argb) 
#define GetBValueOfARGB(argb)





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
	bool OnClickedColorButton(void* msg);
	bool OnClickedTileItem(void* param);
	bool OnClickedGreenColorButton(void* param);
	bool OnClickedList(void* param);
	vector<BYTE> list;
	vector<DWORD> m_colorList;

	CTreeNodeUI* pNode;
};

