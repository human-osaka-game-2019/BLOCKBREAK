#include "Directgraphics.h"
#include <d3dx9.h>

// �e���_������������
VOID SetCoordinate(CUSTOMVERTEX* customvertex, RECTANGLE rectangle)
{
	// ���㒸�_���
	customvertex[0] = {
		rectangle.x,										// x���W
		rectangle.y,										// y���W
		0.0f,													// z���W
		1.0f,													// rhw
		0xffffffff,												// �F
		0.0f,													// tu(�e�N�X�`�����W_x)
		0.0f,													// tv(�e�N�X�`�����W_y)
	};

	// �E�㒸�_���
	customvertex[1] = {
		rectangle.x + rectangle.width,				// x���W
		rectangle.y,										// y���W
		0.0f,													// z���W
		1.0f,													// rhw
		0xffffffff,												// �F
		1.0f,													// tu(�e�N�X�`�����W_x)
		0.0f,													// tv(�e�N�X�`�����W_y)
	};

	// �E�����_���
	customvertex[2] = {
		rectangle.x + rectangle.width,				// x���W
		rectangle.y + rectangle.height,				// y���W
		0.0f,													// z���W
		1.0f,													// rhw
		0xffffffff,												// �F
		1.0f,													// tu(�e�N�X�`�����W_x)
		1.0f,													// tv(�e�N�X�`�����W_y)
	};

	// �������_���
	customvertex[3] = {
		rectangle.x,										// x���W
		rectangle.y + rectangle.height,				// y���W
		0.0f,													// z���W
		1.0f,													// rhw
		0xffffffff,												// �F
		0.0f,													// tu(�e�N�X�`�����W_x)
		1.0f,													// tv(�e�N�X�`�����W_y)
	};
}

// �|���S����`�悷��
VOID DrawPolygon(VERTEXINITIALIZATION* vertexinitialization, CREATEDIRECTX createdirectx)
{
	createdirectx.pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
	if (SUCCEEDED(createdirectx.pDevice->BeginScene())) //�����������ǂ���
	{
		createdirectx.pDevice->SetFVF(FVF_CUSTOM);
		for (int i = 0; i < number_of_polygons; i++)
		{
			createdirectx.pDevice->SetTexture(0, createdirectx.pTexture[i]);
			// pDevice->DrawPrimitiveUP(�|���S���̕`����@,�|���S���̐�,���_�f�[�^�̃|�C���^,���_�f�[�^�̃T�C�Y)
			createdirectx.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, &vertexinitialization[i], sizeof(CUSTOMVERTEX));
		}
		createdirectx.pDevice->EndScene();
	}
	createdirectx.pDevice->Present(NULL, NULL, NULL, NULL); //��ʂ̍X�V
}
