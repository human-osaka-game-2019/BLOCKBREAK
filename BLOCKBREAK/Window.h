#ifndef WINDOW
#define WINDOW
#include <Windows.h>
#include <d3dx9.h>

class WindowGeneration // ウィンドウ生成に必要な中身
{
public:
	VOID OutputWindow(WNDCLASSEX WndClass, HINSTANCE hInst);
<<<<<<< HEAD
=======
	
private:
>>>>>>> 77f5110c64b34912bb2ca93e6b52cf4396ab9196

};

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
#endif

