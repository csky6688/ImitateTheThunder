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

void CLoginDlg::InitWindow()
{
	CButtonUI* pClose = (CButtonUI*)m_PaintManager.FindControl(L"close");
	pClose->OnNotify += MakeDelegate(this, &CLoginDlg::OnMyClose);
}


bool CLoginDlg::OnMyClose(void* lParam)
{
	TNotifyUI* msg = (TNotifyUI*)lParam;

	if (msg->sType == DUI_MSGTYPE_CLICK)
	{
		::PostMessage(m_hWnd,WM_CLOSE,NULL,NULL);
	}
	return true;
}