#ifndef DIRECTX
#define DIRECTX
#include <d3dx9.h>

CONST INT number_of_texture = 2;
CONST CHAR* filename[number_of_texture] =
{
	"outerwall035.jpg",
	""
};

class CREATEDIRECTX {
public:
	LPDIRECT3D9 pDirectX;
	LPDIRECT3DDEVICE9 pDevice;
	LPDIRECT3DTEXTURE9 pTexture[number_of_texture]; // �e�N�X�`���I�u�W�F�N�g�z��
	// Direct3D�̏�����
	HRESULT InitD3d(HWND hWnd);
};


#endif // !1

