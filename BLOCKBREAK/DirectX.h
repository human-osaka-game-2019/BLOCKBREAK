#ifndef DIRECTX
#define DIRECTX

#include <d3dx9.h>

class CREATEDIRECTX {
public:
	LPDIRECT3D9 pDirectX;
	LPDIRECT3DDEVICE9 pDevice;
	// Direct3D‚Ì‰Šú‰»ŠÖ”
	HRESULT InitD3d(HWND hWnd);
};


#endif // !1

