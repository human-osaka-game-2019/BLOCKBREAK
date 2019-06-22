#include "Directgraphics.h"
#include "DirectX.h"
#include <d3dx9.h>

VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle)
{
	customvertex[0] = {
		rectangle.x, // x座標
		rectangle.y, // y座標
		0.0f, // z座標
		1.0f, // rhw
		0xffffffff,	 // 色
		0.0f, // tu(テクスチャ座標)
		0.0f, // tv(テクスチャ座標)
	};

	customvertex[1] = {
		rectangle.x + rectangle.width, // x座標
		rectangle.y, // y座標
		0.0f, // z座標
		1.0f, // rhw
		0xffffffff,	 // 色
		0.0f, // tu(テクスチャ座標)
		0.0f, // tv(テクスチャ座標)
	};

	customvertex[2] = {
		rectangle.x + rectangle.width, // x座標
		rectangle.y + rectangle.height, // y座標
		0.0f, // z座標
		1.0f, // rhw
		0xffffffff,	 // 色
		0.0f, // tu(テクスチャ座標)
		0.0f, // tv(テクスチャ座標)
	};

	customvertex[3] = {
		rectangle.x, // x座標
		rectangle.y + rectangle.height, // y座標
		0.0f, // z座標
		1.0f, // rhw
		0xffffffff,	 // 色
		0.0f, // tu(テクスチャ座標)
		0.0f, // tv(テクスチャ座標)
	};
}

VOID DrawPolygon(CUSTOMVERTEX* customvertex, CREATEDIRECTX createdirectx)
{
	createdirectx.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
	if (SUCCEEDED(createdirectx.pDevice->BeginScene())) //成功したかどうか
	{
		createdirectx.pDevice->SetFVF(FVF_CUSTOM);
		// pDevice->DrawPrimitiveUP(ポリゴンの描画方法,ポリゴンの数,頂点データのポインタ,頂点データのサイズ)
		createdirectx.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, customvertex, sizeof(CUSTOMVERTEX));
		createdirectx.pDevice->EndScene();
	}
	createdirectx.pDevice->Present(NULL, NULL, NULL, NULL); //画面の更新
}
