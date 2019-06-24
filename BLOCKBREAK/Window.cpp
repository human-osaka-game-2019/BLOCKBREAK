#include "Window.h"
#include <Windows.h>
#include <d3dx9.h>

// ウィンドウ生成を行う
HWND WINDOWGENERATION::OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME, FLOAT* wnd_width, FLOAT* wnd_height)
{
	// Wndclassの初期化
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;											// ウィンドウスタイル
	Wndclass.lpfnWndProc = WndProc;																// ウィンドウプロシージャ
	Wndclass.cbClsExtra = 0;																				// メモリ確保
	Wndclass.cbWndExtra = 0;																			// メモリ確保
	Wndclass.hInstance = *hInstance;																// ハンドルインスタンス
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);									// アイコン
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);										// カーソル
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);			// 背景のブラシ,色
	Wndclass.lpszMenuName = NULL;																// メニュー画面の名前
	Wndclass.lpszClassName = API_NAME;															// アプリケーションの名前

	// ウィンドウクラスの登録
	RegisterClass(&Wndclass);

	// ウィンドウハンドルにcreatewindow関数で作った情報を代入
	return *hWnd = CreateWindow(
		API_NAME,																								// クラスの名前
		API_NAME,																								// アプリケーションのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,												// ウィンドウのスタイル
		0,		            																						// xの位置
		0,		            																						// yの位置
		*wnd_width,																							// 幅
		*wnd_height,																							// 高さ
		NULL,																									// 親ウィンドウのハンドル
		NULL,																									// メニューのハンドル
		*hInstance,																							// インスタンスハンドル
		NULL																										// メッセージに渡されるパラメータ
	);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
