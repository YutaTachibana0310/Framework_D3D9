//=====================================
//
//�g�����X�t�H�[������[Transform.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Transform.h"
#include "../Math/Quaternion.h"
#include "../Camera/Camera.h"

/**************************************
�R���X�g���N�^
***************************************/
Transform::Transform() :
	position(Vector3::Zero),
	rotation(Quaternion::Identity),
	scale(Vector3::One)
{

}

/**************************************
�R���X�g���N�^
***************************************/
Transform::Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale) :
	position(pos),
	rotation(Quaternion::Identity),
	scale(scale)
{
	D3DXQuaternionRotationYawPitchRoll(&this->rotation, rot.y, rot.x, rot.z);
}

/**************************************
�R���X�g���N�^
***************************************/
Transform::Transform(const Transform &src) :
	position(src.position),
	rotation(src.rotation),
	scale(src.scale)
{

}

/**************************************
������Z�q
***************************************/
Transform Transform::operator=(const Transform &src)
{
	this->position = src.position;
	this->rotation = src.rotation;
	this->scale = src.scale;

	return *this;
}

/**************************************
�ړ�����
***************************************/
void Transform::Move(float x, float y, float z)
{
	position += D3DXVECTOR3(x, y, z);
}

/**************************************
�ړ�����
***************************************/
void Transform::Move(const D3DXVECTOR3 & velocity)
{
	position += velocity;
}

/**************************************
�ړ�����
***************************************/
void Transform::SetPosition(const D3DXVECTOR3 & position)
{
	this->position = position;
}

/**************************************
�ړ�����
***************************************/
D3DXVECTOR3 Transform::GetPosition()
{
	return position;
}

/**************************************
��]����
***************************************/
void Transform::Rotate(float degX, float degY, float degZ)
{
	D3DXQUATERNION q;
	D3DXQuaternionRotationYawPitchRoll(&q, D3DXToRadian(degY), D3DXToRadian(degX), D3DXToRadian(degZ));
	D3DXQuaternionMultiply(&rotation, &rotation, &q);
}

/***************************************
��]����
***************************************/
void Transform::Rotate(float deg, const D3DXVECTOR3& axis)
{
	D3DXQUATERNION q;
	D3DXQuaternionRotationAxis(&q, &axis, D3DXToRadian(deg));
	D3DXQuaternionMultiply(&rotation, &rotation, &q);
}

/***************************************
��]�ݒ菈��
***************************************/
void Transform::SetRotation(float x, float y, float z)
{
	rotation = Quaternion::Identity;
	Rotate(x, y, z);
}

/**************************************
�ړ�����
***************************************/
void Transform::SetRotation(const D3DXVECTOR3 & rotation)
{
	this->rotation = Quaternion::ToQuaternion(rotation);
}

/**************************************
�ړ�����
***************************************/
void Transform::SetRotation(const D3DXQUATERNION & rotation)
{
	this->rotation = rotation;
}

/***************************************
�I�C���[�p�擾����
***************************************/
D3DXVECTOR3 Transform::GetEulerAngle()
{
	return Quaternion::ToEuler(rotation);
}

/**************************************
�ړ�����
***************************************/
D3DXQUATERNION Transform::GetRotation()
{
	return rotation;
}

/**************************************
�ړ�����
***************************************/
void Transform::Scale(float deltaX, float deltaY, float deltaZ)
{
	scale.x *= deltaX;
	scale.y *= deltaY;
	scale.z *= deltaZ;
}

/**************************************
�ړ�����
***************************************/
void Transform::ScaleX(float delta)
{
	scale.x *= delta;
}

/**************************************
�ړ�����
***************************************/
void Transform::ScaleY(float delta)
{
	scale.y *= delta;
}

/**************************************
�ړ�����
***************************************/
void Transform::ScaleZ(float delta)
{
	scale.z *= delta;
}

/**************************************
�ړ�����
***************************************/
void Transform::SetScale(const D3DXVECTOR3 & scale)
{
	this->scale = scale;
}

/**************************************
�ړ�����
***************************************/
D3DXVECTOR3 Transform::GetScale()
{
	return scale;
}

/**************************************
���[���h�ϊ�����
***************************************/
void Transform::SetWorld(const D3DXMATRIX* parent)
{
	D3DXMATRIX world = GetMatrix();
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�𔽉f
	if (parent != NULL)
	{
		D3DXMatrixMultiply(&world, parent, &world);
	}

	pDevice->SetTransform(D3DTS_WORLD, &world);
}

/**************************************
�r���{�[�h����
***************************************/
void Transform::SetWorldInvView(const D3DXMATRIX* parent)
{
	D3DXMATRIX world, rotation, view, invView;
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//��]
	D3DXMatrixRotationQuaternion(&world, &this->rotation);

	//�r���{�[�h����
	pDevice->GetTransform(D3DTS_VIEW, &view);
	D3DXMatrixInverse(&invView, NULL, &view);
	D3DXMatrixMultiply(&world, &world, &invView);

	//�X�P�[��
	world._11 *= scale.x;
	world._12 *= scale.x;
	world._13 *= scale.x;

	world._21 *= scale.y;
	world._22 *= scale.y;
	world._23 *= scale.y;

	world._31 *= scale.z;
	world._32 *= scale.z;
	world._33 *= scale.z;

	//�ړ�
	world._41 = position.x;
	world._42 = position.y;
	world._43 = position.z;

	//�e�𔽉f
	if (parent != NULL)
	{
		D3DXMatrixMultiply(&world, parent, &world);
	}

	pDevice->SetTransform(D3DTS_WORLD, &world);
}

/**************************************
�O���v�Z����
***************************************/
D3DXVECTOR3 Transform::Forward()
{
	D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &this->rotation);
	D3DXVec3TransformCoord(&forward, &forward, &rotation);

	return forward;
}

/**************************************
�E���v�Z����
***************************************/
D3DXVECTOR3 Transform::Right()
{
	D3DXVECTOR3 right = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &this->rotation);
	D3DXVec3TransformCoord(&right, &right, &rotation);

	return right;
}

/**************************************
����v�Z����
***************************************/
D3DXVECTOR3 Transform::Up()
{
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &this->rotation);
	D3DXVec3TransformCoord(&up, &up, &rotation);

	return up;
}

/**************************************
���[���h�s��擾����
***************************************/
D3DXMATRIX Transform::GetMatrix()
{
	/*************************************
	NOTE:�����ɍs��v�Z������A�v�f�𒼐ڌv�Z�����������������̂�
	��]�����s��ŁA����ȊO�͒��ڌv�Z���Ă���
	*************************************/
	D3DXMATRIX world;

	//��]
	D3DXMatrixRotationQuaternion(&world, &this->rotation);

	//�X�P�[��
	world._11 *= scale.x;
	world._12 *= scale.x;
	world._13 *= scale.x;

	world._21 *= scale.y;
	world._22 *= scale.y;
	world._23 *= scale.y;

	world._31 *= scale.z;
	world._32 *= scale.z;
	world._33 *= scale.z;

	//�ړ�
	world._41 = position.x;
	world._42 = position.y;
	world._43 = position.z;

	return world;
}

/**************************************
���[���h�s��擾����
***************************************/
D3DXMATRIX Transform::GetBillboardMtx()
{
	/*************************************
	NOTE:�����ɍs��v�Z������A�v�f�𒼐ڌv�Z�����������������̂�
	��]�����s��ŁA����ȊO�͒��ڌv�Z���Ă���
	*************************************/
	D3DXMATRIX world;

	//��]
	D3DXMatrixRotationQuaternion(&world, &this->rotation);

	////�r���{�[�h����
	//D3DXMATRIX invView = Camera::GetInverseViewMtx();
	//D3DXMatrixMultiply(&world, &world, &invView);

	//�X�P�[��
	world._11 *= scale.x;
	world._12 *= scale.x;
	world._13 *= scale.x;

	world._21 *= scale.y;
	world._22 *= scale.y;
	world._23 *= scale.y;

	world._31 *= scale.z;
	world._32 *= scale.z;
	world._33 *= scale.z;

	//�ړ�
	world._41 = position.x;
	world._42 = position.y;
	world._43 = position.z;

	return world;
}