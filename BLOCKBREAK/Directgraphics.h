#ifndef DIRECTGRAPHICS
#define DIRECTGRAPHICS

#include "DirectX.h"
#include <d3dx9.h>

const DWORD FVF_CUSTOM = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);

typedef struct
{
	FLOAT x, y, z, rhw; // 座標
	DWORD color; // 色
	FLOAT tu, tv; // テクスチャ座標
} CUSTOMVERTEX;

typedef struct
{
	FLOAT width, height; // 矩形の幅、高さ
	FLOAT x, y;
} RECTANGLE;

VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle);
VOID DrawPolygon(CUSTOMVERTEX* customvertex, CREATEDIRECTX createdurectx);

#endif // !DIRECTGRAPHICS

