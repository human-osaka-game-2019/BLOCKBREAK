#ifndef WINDOW
#define WINDOW
#include <Windows.h>
#include <d3dx9.h>

class WINDOWGENERATION // �E�B���h�E�����ɕK�v�Ȓ��g
{
public:
	HWND OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME,int* wndwidht,int* wndhight);
private:

};

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#endif

