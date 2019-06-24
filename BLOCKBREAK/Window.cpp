#include "Window.h"
#include <Windows.h>
#include <d3dx9.h>

// �E�B���h�E�������s��
HWND WINDOWGENERATION::OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME, FLOAT* wnd_width, FLOAT* wnd_height)
{
	// Wndclass�̏�����
	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;											// �E�B���h�E�X�^�C��
	Wndclass.lpfnWndProc = WndProc;																// �E�B���h�E�v���V�[�W��
	Wndclass.cbClsExtra = 0;																				// �������m��
	Wndclass.cbWndExtra = 0;																			// �������m��
	Wndclass.hInstance = *hInstance;																// �n���h���C���X�^���X
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);									// �A�C�R��
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);										// �J�[�\��
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);			// �w�i�̃u���V,�F
	Wndclass.lpszMenuName = NULL;																// ���j���[��ʂ̖��O
	Wndclass.lpszClassName = API_NAME;															// �A�v���P�[�V�����̖��O

	// �E�B���h�E�N���X�̓o�^
	RegisterClass(&Wndclass);

	// �E�B���h�E�n���h����createwindow�֐��ō����������
	return *hWnd = CreateWindow(
		API_NAME,																								// �N���X�̖��O
		API_NAME,																								// �A�v���P�[�V�����̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,												// �E�B���h�E�̃X�^�C��
		0,		            																						// x�̈ʒu
		0,		            																						// y�̈ʒu
		*wnd_width,																							// ��
		*wnd_height,																							// ����
		NULL,																									// �e�E�B���h�E�̃n���h��
		NULL,																									// ���j���[�̃n���h��
		*hInstance,																							// �C���X�^���X�n���h��
		NULL																										// ���b�Z�[�W�ɓn�����p�����[�^
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
