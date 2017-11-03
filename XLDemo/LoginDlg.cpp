#include "stdafx.h"
#include "LoginDlg.h"


CLoginDlg::CLoginDlg()
{
}


CLoginDlg::~CLoginDlg()
{
}

LPCTSTR CLoginDlg::GetWindowClassName() const
{
	return L"LoginDialog";
}

DuiLib::CDuiString CLoginDlg::GetSkinFile()
{
	return L"Login.xml";
}

DuiLib::CDuiString CLoginDlg::GetSkinFolder()
{
	return L"skin";
}
