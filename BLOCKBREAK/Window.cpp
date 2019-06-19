#include "Window.h"
#include <Windows.h>
#include <d3dx9.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

VOID WindowGeneration::OutputWindow(WNDCLASSEX WndClass, HINSTANCE hInst)
{
	static char szAppName[] = "BLOCKBREAK";

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInst;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = szAppName;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

}
<<<<<<< HEAD

=======
>>>>>>> 77f5110c64b34912bb2ca93e6b52cf4396ab9196
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
