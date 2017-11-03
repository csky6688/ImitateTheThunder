#pragma once
#include "stdafx.h"

class CLoginDlg :public WindowImplBase
{
public:
	CLoginDlg();
	~CLoginDlg();

	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
};

