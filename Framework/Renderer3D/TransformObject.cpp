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
	mesh = new MeshContainer();
	mesh->Load("data/MODEL/transform.x");
}

/**************************************
�f�X�g���N�^
***************************************/
TransformObject::~TransformObject()
{
	SAFE_DELETE(mesh);
}

/**************************************
�`�揈��
***************************************/
void TransformObject::Draw()
{
	transform->SetWorld();
	mesh->Draw();
}