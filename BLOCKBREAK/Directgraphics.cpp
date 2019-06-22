#include "Directgraphics.h"
#include "DirectX.h"
#include <d3dx9.h>

VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle)
{
	customvertex[0] = {
		rectangle.x, // x���W
		rectangle.y, // y���W
		0.0f, // z���W
		1.0f, // rhw
		0xffffffff,	 // �F
		0.0f, // tu(�e�N�X�`�����W)
		0.0f, // tv(�e�N�X�`�����W)
	};

	customvertex[1] = {
		rectangle.x + rectangle.width, // x���W
		rectangle.y, // y���W
		0.0f, // z���W
		1.0f, // rhw
		0xffffffff,	 // �F
		0.0f, // tu(�e�N�X�`�����W)
		0.0f, // tv(�e�N�X�`�����W)
	};

	customvertex[2] = {
		rectangle.x + rectangle.width, // x���W
		rectangle.y + rectangle.height, // y���W
		0.0f, // z���W
		1.0f, // rhw
		0xffffffff,	 // �F
		0.0f, // tu(�e�N�X�`�����W)
		0.0f, // tv(�e�N�X�`�����W)
	};

	customvertex[3] = {
		rectangle.x, // x���W
		rectangle.y + rectangle.height, // y���W
		0.0f, // z���W
		1.0f, // rhw
		0xffffffff,	 // �F
		0.0f, // tu(�e�N�X�`�����W)
		0.0f, // tv(�e�N�X�`�����W)
	};
}

VOID DrawPolygon(CUSTOMVERTEX* customvertex, CREATEDIRECTX createdirectx)
{
	createdirectx.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
	if (SUCCEEDED(createdirectx.pDevice->BeginScene())) //�����������ǂ���
	{
		createdirectx.pDevice->SetFVF(FVF_CUSTOM);
		// pDevice->DrawPrimitiveUP(�|���S���̕`����@,�|���S���̐�,���_�f�[�^�̃|�C���^,���_�f�[�^�̃T�C�Y)
		createdirectx.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 1, customvertex, sizeof(CUSTOMVERTEX));
		createdirectx.pDevice->EndScene();
	}
	createdirectx.pDevice->Present(NULL, NULL, NULL, NULL); //��ʂ̍X�V
}
