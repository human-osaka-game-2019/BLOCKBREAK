#include "DirectX.h"
#include <d3dx9.h>

HRESULT CREATEDIRECTX::InitD3d(HWND hWnd)
{
	//「Direct3D」オブジェクトの作成
	if (NULL == (pDirectX = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}

	//「DIRECT3Dデバイス」オブジェクトの作成
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;				// フォーマットなし
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE;												// アプリケーションの表示形式

	if (FAILED(pDirectX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, // HAL:ハードウェア
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &pDevice)))
	{
		MessageBox(0, "HALモードでDIRECT3Dデバイスを作成できません\nREFモードで再試行します", NULL, MB_OK);
		if (FAILED(pDirectX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, // REF:ソフトウェア
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&d3dpp, &pDevice)))
		{
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
			return E_FAIL;
		}
	}

	// テクスチャオブジェクトの作成
	for (int i = 0; i < number_of_texture; i++)
	{
		if (FAILED(D3DXCreateTextureFromFile(pDevice, filename[i], &pTexture[i])))
		{
			MessageBox(0, "テクスチャの作成に失敗しました", "", MB_OK);
			return E_FAIL;
		}
	}
}