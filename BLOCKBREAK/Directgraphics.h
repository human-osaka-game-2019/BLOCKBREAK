#ifndef DIRECTGRAPHICS
#define DIRECTGRAPHICS

#include "DirectX.h"
#include <d3dx9.h>

const DWORD FVF_CUSTOM = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE); // ���_���t���O

typedef struct
{
	FLOAT x, y, z, rhw;			// ���W
	DWORD color;				// �F
	FLOAT tu, tv;					// �e�N�X�`�����W
} CUSTOMVERTEX;

typedef struct
{
	FLOAT width, height;		// ��`�̕��A����
	FLOAT x, y;					// ���㒸�_�̍��W
} RECTANGLE;

// �e���_�̏�����
VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle);

// �|���S���̕`��
VOID DrawPolygon(CUSTOMVERTEX* customvertex, CREATEDIRECTX createdurectx);

#endif // !DIRECTGRAPHICS

