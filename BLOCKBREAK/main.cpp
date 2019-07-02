#include "Window.h"
#include "Directgraphics.h"
#include <Windows.h>
#include <d3dx9.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	MSG msg;
	HWND hWnd = NULL;
	WINDOWGENERATION WindowGeneration;
	static CHAR szAppName[] = "BLOCKBREAK";
	FLOAT wnd_width = 640;
	FLOAT wnd_height = 360;
	WindowGeneration.OutputWindow(&hWnd, &hInst, szAppName, &wnd_width, &wnd_height);

	CREATEDIRECTX createdirectx;

	createdirectx.filename[0] = { "outerwall035.jpg" };
	createdirectx.filename[1] = { "1704.png" };

	// Direct3Dの初期化
	if (FAILED(createdirectx.InitD3d(hWnd)))
	{
		return 0;
	}

	VERTEXINITIALIZATION VertexInitialization[number_of_polygons];

	// 背景テクスチャ
	VertexInitialization[0].rectangle = { 640.0f, 360.0f, 0.0f, 0.0f };										// 矩形サイズ(width, height)と左上頂点(x, y)の設定
	SetCoordinate(VertexInitialization[0].customvertex, VertexInitialization[0].rectangle);				// ポリゴンの各頂点を初期化

	// 自機テクスチャ
	VertexInitialization[1].rectangle = { 100.0f, 10.0f, 100.0f, 300.0f };											// 矩形サイズ(width, height)と左上頂点(x, y)の設定
	SetCoordinate(VertexInitialization[1].customvertex, VertexInitialization[1].rectangle);				// ポリゴンの各頂点を初期化

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
				DrawPolygon(VertexInitialization, createdirectx);
				SyncPrev = SyncCurr;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
	return (INT)msg.wParam;
}