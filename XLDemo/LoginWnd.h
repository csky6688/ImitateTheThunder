#pragma once
#include "stdafx.h"

class CLoginWnd:public WindowImplBase
{
public:
	CLoginWnd();
	~CLoginWnd();


	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
};

