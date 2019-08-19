//=====================================
//
//�Q�[���I�u�W�F�N�g����[GameObject.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "GameObject.h"
#include "Transform.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
GameObject::GameObject()
{
	transform = std::make_shared<Transform>();
	active = true;
}

/**************************************
�f�X�g���N�^
***************************************/
GameObject::~GameObject()
{
	transform.reset();
}

/**************************************
�A�N�e�B�u����
***************************************/
bool GameObject::IsActive() const 
{
	return active;
}

/**************************************
�A�N�e�B�u��ԃZ�b�g����
***************************************/
void GameObject::SetActive(bool active)
{
	this->active = active;
}

/**************************************
���W�Z�b�g
***************************************/
D3DXVECTOR3 GameObject::GetPosition() const
{
	return transform->pos;
}
/**************************************
���W�Q�b�g
***************************************/
void GameObject::SetPosition(const D3DXVECTOR3& position)
{
	transform->pos = position;
}

/**************************************
��]�p�x�Q�b�g
***************************************/
D3DXVECTOR3 GameObject::GetRotation() const
{
	return transform->GetEulerAngle();
}

/**************************************
��]�p�x�Z�b�g
***************************************/
void GameObject::SetRotatition(const D3DXVECTOR3& rotation)
{
	transform->rot = Quaternion::ToQuaternion(rotation);
}

/**************************************
�X�P�[���Q�b�g
***************************************/
D3DXVECTOR3 GameObject::GetScale() const
{
	return transform->scale;
}

/**************************************
�X�P�[���Z�b�g
***************************************/
void GameObject::SetScale(const D3DXVECTOR3& scale)
{
	transform->scale = scale;
}

/**************************************
SRT���Q�b�g
***************************************/
Transform GameObject::GetTransform() const
{
	return *transform;
}

/**************************************
�X�P�[�����Q�b�g
***************************************/
void GameObject::SetTransform(const Transform& transform)
{
	*this->transform = transform;
}