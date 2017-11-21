// Practice.cpp : 定义应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include "Practice.h"

#include "DuiMainWnd.h"


#include "ARGB.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPTSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{


	DWORD color = RGB(123,234,135);
	DWORD argb = A_RGB(0xff, color);
	COLORREF clr = GetRGB(argb);
	BYTE r = GetRValue(clr);
	BYTE g = GetGValue(clr);
	BYTE b = GetBValue(clr);

	/*DWORD color = ARGB(255,255,255,255);
	color = SetAValueOfARGB(color, 0);
	color = SetBValueOfARGB(color, 0);
	BYTE a = GetAValueOfARGB(color);
	BYTE r = GetRValueOfARGB(color);
	BYTE g = GetGValueOfARGB(color);
	BYTE b = GetBValueOfARGB(color);*/


	//int a = 2;
	//int b = a >> 2; //right
	//int c = a << 2; // left




	CPaintManagerUI::SetInstance(hInstance);

	CDuiMainWnd duiFrame;
	duiFrame.Create(NULL, L"DuiFrame", UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	duiFrame.CenterWindow();
	duiFrame.ShowModal();
}


