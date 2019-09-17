//=====================================
//
//�R���C�_�[�I�u�U�[�o�[����[ColliderObserver.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "ColliderObserver.h"
#include "BaseCollider.h"

/**************************************
�R���X�g���N�^
***************************************/
BaseCollider::BaseCollider(const std::shared_ptr<Transform> transform) :
	active(true)
{
	refTransform = transform;
}

/**************************************
�f�X�g���N�^
***************************************/
BaseCollider::~BaseCollider()
{
	refTransform.reset();
}

/**************************************
�A�N�e�B�u�Z�b�g����
***************************************/
void BaseCollider::SetActive(bool state)
{
	active = state;
}

/**************************************
�A�N�e�B�u����
***************************************/
bool BaseCollider::IsActive()
{
	return active;
}
