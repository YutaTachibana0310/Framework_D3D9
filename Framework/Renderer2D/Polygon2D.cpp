//=====================================
//
//�|���S��2D����[Polygon2D.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Polygon2D.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
Polygon2D::Polygon2D()
{
	radius = D3DXVec2Length(&D3DXVECTOR2(5.0f, 5.0f));
	angle = atan2f(5.0f, 5.0f);

	vtxWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	vtxWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	vtxWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	vtxWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	vtxWk[0].diffuse =
		vtxWk[1].diffuse =
		vtxWk[2].diffuse =
		vtxWk[3].diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	vtxWk[0].rhw =
		vtxWk[1].rhw =
		vtxWk[2].rhw =
		vtxWk[3].rhw = 1.0f;

	pDevice = GetDevice();
}

/**************************************
�f�X�g���N�^
***************************************/
Polygon2D::~Polygon2D()
{
	SAFE_RELEASE(texture);
}

/**************************************
�`�揈��
***************************************/
void Polygon2D::Draw()
{
	pDevice->SetTexture(0, texture);

	pDevice->SetFVF(FVF_VERTEX_2D);

	SetVertex();

	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_POLYGON, vtxWk, sizeof(VERTEX_2D));
}

/**************************************
�T�C�Y�Z�b�g����
***************************************/
void Polygon2D::SetSize(float x, float y)
{
	radius = D3DXVec2Length(&D3DXVECTOR2(x, y));
	angle = atan2f(y, x);
}

/**************************************
�J���[�Z�b�g����
***************************************/
void Polygon2D::SetColor(D3DXCOLOR color)
{
	vtxWk[0].diffuse =
		vtxWk[1].diffuse =
		vtxWk[2].diffuse =
		vtxWk[3].diffuse = color;
}

/**************************************
UV���W�ݒ菈��
***************************************/
void Polygon2D::SetUV(float left, float top, float width, float height)
{
	vtxWk[0].tex = D3DXVECTOR2(left, top);
	vtxWk[1].tex = D3DXVECTOR2(left + width, top);
	vtxWk[2].tex = D3DXVECTOR2(left, top + height);
	vtxWk[3].tex = D3DXVECTOR2(left + width, top + height);
}

/**************************************
�e�N�X�`���ǂݍ��ݏ���
***************************************/
void Polygon2D::LoadTexture(const char* path)
{
	SAFE_RELEASE(texture);

	D3DXCreateTextureFromFile(pDevice, path, &texture);
}

/**************************************
���_���W�ݒ菈��
***************************************/
void Polygon2D::SetVertex()
{
	vtxWk[0].vtx.x = transform.pos.x - cosf(angle + transform.rot.z) * radius * transform.scale.x;
	vtxWk[0].vtx.y = transform.pos.y - sinf(angle + transform.rot.z) * radius * transform.scale.y;
	vtxWk[1].vtx.x = transform.pos.x + cosf(angle - transform.rot.z) * radius * transform.scale.x;
	vtxWk[1].vtx.y = transform.pos.y - sinf(angle - transform.rot.z) * radius * transform.scale.y;
	vtxWk[2].vtx.x = transform.pos.x - cosf(angle - transform.rot.z) * radius * transform.scale.x;
	vtxWk[2].vtx.y = transform.pos.y + sinf(angle - transform.rot.z) * radius * transform.scale.y;
	vtxWk[3].vtx.x = transform.pos.x + cosf(angle + transform.rot.z) * radius * transform.scale.x;
	vtxWk[3].vtx.y = transform.pos.y + sinf(angle + transform.rot.z) * radius * transform.scale.y;
}