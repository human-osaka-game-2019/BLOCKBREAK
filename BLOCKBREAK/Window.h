#ifndef WINDOW
#define WINDOW
#include <Windows.h>
#include <d3dx9.h>

class WINDOWGENERATION // �E�B���h�E�����ɕK�v�Ȓ��g
{
public:
	// �E�B���h�E����
	HWND OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME, FLOAT* wnd_width, FLOAT* wnd_height);
private:

};

// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#endif

