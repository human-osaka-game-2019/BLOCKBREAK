#include "Window.h"
#include <Windows.h>
#include <d3dx9.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow) 
{
	MSG msg;
	WINDOWGENERATION WindowGeneration;
	static char szAppName[] = "BLOCKBREAK";
	WNDCLASSEX WndClass;

	WindowGeneration.OutputWindow(&WndClass, hInst, szAppName);

	RegisterClassEx(&WndClass);

	HWND hWnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW,
		0, 0, 640, 480, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// ƒƒCƒ“ƒ‹[ƒv
	DWORD SyncPrev = timeGetTime();
	DWORD SyncCurr = 0;
	ZeroMemory(&msg, sizeof(msg));
	timeBeginPeriod(1);
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncCurr = timeGetTime();
			if (SyncCurr - SyncPrev >= 1000 / 60)
			{
				SyncPrev = SyncCurr;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
	return (INT)msg.wParam;
}