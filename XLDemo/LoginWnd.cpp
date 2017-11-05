#include "stdafx.h"
#include "LoginWnd.h"

using namespace DuiLib;


CLoginWnd::CLoginWnd()
{
}


CLoginWnd::~CLoginWnd()
{
}


LPCTSTR CLoginWnd::GetWindowClassName() const
{
	return L"LoginDialog";
}

CDuiString CLoginWnd::GetSkinFile()
{
	return L"Login.xml";
}

CDuiString CLoginWnd::GetSkinFolder()
{
	return L"skin";
}
