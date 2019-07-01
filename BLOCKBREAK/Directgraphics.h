#ifndef DIRECTGRAPHICS
#define DIRECTGRAPHICS
#include "DirectX.h"
#include <d3dx9.h>

CONST DWORD FVF_CUSTOM = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);				// ���_���t���O
CONST INT number_of_polygons = 2;																	// �`�悷��|���S���̖���

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

class VERTEXINITIALIZATION
{
public:
	CUSTOMVERTEX customvertex[4];
	RECTANGLE rectangle;
};

// �e���_�̏�����
VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle);

// �|���S���̕`��
VOID DrawPolygon(VERTEXINITIALIZATION* vertexinitialization, CREATEDIRECTX createdurectx);

#endif // !DIRECTGRAPHICS

