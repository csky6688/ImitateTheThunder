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

std::string StringFromLPCTSTR(LPCTSTR str) {
#ifdef _UNICODE
	int size_str = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, NULL, NULL);

	char* point_new_array = new char[size_str];

	WideCharToMultiByte(CP_UTF8, 0, str, -1, point_new_array, size_str, NULL, NULL);

	std::string return_string(point_new_array);
	delete[] point_new_array;
	point_new_array = NULL;
	return return_string;
#else
	return std::string(str);
#endif
}


void CLoginDlg::InitWindow()
{
	/*CButtonUI* pClose = (CButtonUI*)m_PaintManager.FindControl(L"close");
	pClose->OnNotify += MakeDelegate(this, &CLoginDlg::OnMyClose);*/
	

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