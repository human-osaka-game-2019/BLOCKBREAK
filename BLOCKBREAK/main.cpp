#include "Window.h"
#include "DirectX.h"
#include "Directgraphics.h"
#include <Windows.h>
#include <d3dx9.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow) 
{
	MSG msg;
	HWND hWnd = NULL;
	WINDOWGENERATION WindowGeneration;
	static char szAppName[] = "BLOCKBREAK";
	FLOAT wnd_width = 640;
	FLOAT wnd_height = 360;
	WindowGeneration.OutputWindow(&hWnd, &hInst, szAppName, &wnd_width, &wnd_height);

	CREATEDIRECTX createdirectx;
	if (FAILED(createdirectx.InitD3d(hWnd)))
	{
		return 0;
	}

	// ���C�����[�v
	CUSTOMVERTEX customvertex[4];
	RECTANGLE rectangle = { 100.0f, 100.0f, 100.0f, 100.0f }; // ���㒸�_�Ƌ�`�T�C�Y�̐ݒ�
	SetCoordinate(customvertex, rectangle);

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
				DrawPolygon(customvertex, createdirectx);
				SyncPrev = SyncCurr;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
	return (INT)msg.wParam;
}