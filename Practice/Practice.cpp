// Practice.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Practice.h"

#include "DuiMainWnd.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiMainWnd duiFrame;
	duiFrame.Create(NULL, L"DuiFrame", UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	duiFrame.CenterWindow();
	duiFrame.ShowModal();
}


