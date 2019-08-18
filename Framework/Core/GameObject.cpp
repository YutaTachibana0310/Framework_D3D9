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
inline bool GameObject::IsActive()
{
	return active;
}

/**************************************
�A�N�e�B�u��ԃZ�b�g����
***************************************/
inline void GameObject::SetActive(bool active)
{
	this->active = active;
}

/**************************************
���W�Z�b�g
***************************************/
D3DXVECTOR3 GameObject::GetPosition()
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
D3DXVECTOR3 GameObject::GetRotation()
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
D3DXVECTOR3 GameObject::GetScale()
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