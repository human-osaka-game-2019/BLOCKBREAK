#ifndef WINDOW
#define WINDOW
#include <Windows.h>
#include <d3dx9.h>

class WINDOWGENERATION // ウィンドウ生成に必要な中身
{
public:
	VOID OutputWindow(WNDCLASSEX* WndClass, HINSTANCE hInst, CHAR* szAppName);
private:

};

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#endif

