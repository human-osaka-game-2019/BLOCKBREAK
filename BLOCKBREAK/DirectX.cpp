#include "DirectX.h"
#include <d3dx9.h>

HRESULT CREATEDIRECTX::InitD3d(HWND hWnd)
{
	//�uDirect3D�v�I�u�W�F�N�g�̍쐬
	if (NULL == (pDirectX = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3D�̍쐬�Ɏ��s���܂���", "", MB_OK);
		return E_FAIL;
	}

	//�uDIRECT3D�f�o�C�X�v�I�u�W�F�N�g�̍쐬
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;				// �t�H�[�}�b�g�Ȃ�
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;												// �A�v���P�[�V�����̕\���`��

	if (FAILED(pDirectX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, // HAL:�n�[�h�E�F�A
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &pDevice)))
	{
		MessageBox(0, "HAL���[�h��DIRECT3D�f�o�C�X���쐬�ł��܂���\nREF���[�h�ōĎ��s���܂�", NULL, MB_OK);
		if (FAILED(pDirectX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, // REF:�\�t�g�E�F�A
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&d3dpp, &pDevice)))
		{
			MessageBox(0, "DIRECT3D�f�o�C�X�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
			return E_FAIL;
		}
	}

	// �e�N�X�`���I�u�W�F�N�g�̍쐬
	for (int i = 0; i < number_of_texture; i++)
	{
		if (FAILED(D3DXCreateTextureFromFile(pDevice, filename[i], &pTexture[i])))
		{
			MessageBox(0, "�e�N�X�`���̍쐬�Ɏ��s���܂���", "", MB_OK);
			return E_FAIL;
		}
	}
}