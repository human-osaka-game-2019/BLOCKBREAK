#ifndef WINDOW
#define WINDOW
#include <Windows.h>
#include <d3dx9.h>

class WINDOWGENERATION // ウィンドウ生成に必要な中身
{
public:
	// ウィンドウ生成
	HWND OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME, FLOAT* wnd_width, FLOAT* wnd_height);
private:

};

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#endif

