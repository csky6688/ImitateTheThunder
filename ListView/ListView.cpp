// ListView.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ListView.h"

#include "ListViewWnd.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CListViewWnd duiFrame;
	duiFrame.Create(NULL, L"DuiFrame", UI_WNDSTYLE_FRAME/*WS_CLIPSIBLINGS*/, WS_EX_WINDOWEDGE);

	duiFrame.CenterWindow();
	duiFrame.ShowModal();
}

