#include "Directgraphics.h"
#include <d3dx9.h>

// 各頂点を初期化する
VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle)
{
	// 左上頂点情報
	customvertex[0] = {
		rectangle.x,										// x座標
		rectangle.y,										// y座標
		0.0f,													// z座標
		1.0f,													// rhw
		0xffffffff,												// 色
		0.0f,													// tu(テクスチャ座標_x)
		0.0f,													// tv(テクスチャ座標_y)
	};

	// 右上頂点情報
	customvertex[1] = {
		rectangle.x + rectangle.width,				// x座標
		rectangle.y,										// y座標
		0.0f,													// z座標
		1.0f,													// rhw
		0xffffffff,												// 色
		1.0f,													// tu(テクスチャ座標_x)
		0.0f,													// tv(テクスチャ座標_y)
	};

	// 右下頂点情報
	customvertex[2] = {
		rectangle.x + rectangle.width,				// x座標
		rectangle.y + rectangle.height,				// y座標
		0.0f,													// z座標
		1.0f,													// rhw
		0xffffffff,												// 色
		1.0f,													// tu(テクスチャ座標_x)
		1.0f,													// tv(テクスチャ座標_y)
	};

	// 左下頂点情報
	customvertex[3] = {
		rectangle.x,										// x座標
		rectangle.y + rectangle.height,				// y座標
		0.0f,													// z座標
		1.0f,													// rhw
		0xffffffff,												// 色
		0.0f,													// tu(テクスチャ座標_x)
		1.0f,													// tv(テクスチャ座標_y)
	};
}

// ポリゴンを描画する
VOID DrawPolygon(VERTEXINITIALIZATION* vertexinitialization, CREATEDIRECTX createdirectx)
{
	createdirectx.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
	if (SUCCEEDED(createdirectx.pDevice->BeginScene())) //成功したかどうか
	{
		createdirectx.pDevice->SetFVF(FVF_CUSTOM);
		for (int i = 0; i < number_of_polygons; i++)
		{
			createdirectx.pDevice->SetTexture(0, createdirectx.pTexture[i]);
			// pDevice->DrawPrimitiveUP(ポリゴンの描画方法,ポリゴンの数,頂点データのポインタ,頂点データのサイズ)
			createdirectx.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, &vertexinitialization[i], sizeof(CUSTOMVERTEX));
		}
		createdirectx.pDevice->EndScene();
	}
	createdirectx.pDevice->Present(NULL, NULL, NULL, NULL); //画面の更新
}
