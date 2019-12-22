//=====================================
//
//�g�����X�t�H�[���I�u�W�F�N�g����[TransformObject.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "TransformObject.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
TransformObject::TransformObject()
{
	mesh = MeshContainer::Create();
	mesh->Load("data/MODEL/transform.x");
}

/**************************************
�f�X�g���N�^
***************************************/
TransformObject::~TransformObject()
{
	SAFE_RELEASE(mesh);
}

/**************************************
�`�揈��
***************************************/
void TransformObject::Draw()
{
	transform->SetWorld();
	mesh->Draw();
}

/**************************************
�w��̍��W����������
***************************************/
void TransformObject::LookAt(const D3DXVECTOR3 & target)
{
	transform->LookAt(target);
}
