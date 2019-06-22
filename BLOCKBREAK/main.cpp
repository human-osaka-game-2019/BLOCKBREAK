#include "Window.h"
#include <Windows.h>
#include <d3dx9.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow) 
{
	MSG msg;
	HWND hWnd = NULL;
	WINDOWGENERATION WindowGeneration;
	static char szAppName[] = "BLOCKBREAK";
	int wndwidth = 680;	//ウィンドウの幅
	int wndhight = 360; //ウィンドウの高さ
	//第一引数　ウィンドウハンドル、第二引数　インスタンス、第三引数　名前、第四引数　ウィンドウの幅、第五引数　ウィンドウの高さ。
	WindowGeneration.OutputWindow(&hWnd, &hInst, szAppName,&wndwidth,&wndhight);

	// メインループ
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