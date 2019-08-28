//=====================================
//
//�x�[�X�p�[�e�B�N������[BaseParticle.cpp]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#include "BaseParticle.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�\���̒�`
***************************************/

/**************************************
�O���[�o���ϐ�
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
BaseParticle::BaseParticle() :
	BillboardObject(false),
	uv(ParticleUV())
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseParticle::BaseParticle(int life) :
	BillboardObject(false),
	uv(ParticleUV()),
	lifeFrame(life)
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseParticle::BaseParticle(int lifeMin, int lifeMax) :
	BillboardObject(false),
	uv(ParticleUV()),
	lifeFrame(Math::RandomRange(lifeMin, lifeMax))
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseParticle::BaseParticle(float u, float v, int lifeMin, int lifeMax) :
	BillboardObject(false),
	uv(ParticleUV(u, v)),
	lifeFrame(Math::RandomRange(lifeMin, lifeMax))
{
}

/**************************************
�f�X�g���N�^
***************************************/
BaseParticle::~BaseParticle()
{
}

/**************************************
�A�N�e�B�u����
***************************************/
bool BaseParticle::IsActive() const
{
	if (!active)
		return false;

	return cntFrame <= lifeFrame;
}

/**************************************
���[���h�s��s��擾����
***************************************/
D3DXMATRIX BaseParticle::GetWorldMtx()
{
	return transform->GetMatrix();
}
