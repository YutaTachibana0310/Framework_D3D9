//=====================================
//
//�g�����X�t�H�[���w�b�_[Transform.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "../../main.h"
#include "../Math/Quaternion.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class Transform
{
public:

	//�R���X�g���N�^
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);

	//�ړ�����
	void Move(float x, float y, float z);
	void Move(const D3DXVECTOR3& velocity);
	void SetPosition(const D3DXVECTOR3& position);
	D3DXVECTOR3 GetPosition();

	//��]����
	void Rotate(float degX, float degY, float degZ);
	void Rotate(float deg, const D3DXVECTOR3& axis);
	void SetRotation(float x, float y, float z);
	void SetRotation(const D3DXVECTOR3& rotation);
	void SetRotation(const D3DXQUATERNION& rotation);
	D3DXVECTOR3 GetEulerAngle();
	D3DXQUATERNION GetRotation();

	//�X�P�[������
	void Scale(float deltaX, float deltaY, float deltaZ);
	void ScaleX(float delta);
	void ScaleY(float delta);
	void ScaleZ(float delta);
	void SetScale(const D3DXVECTOR3& scale);
	D3DXVECTOR3 GetScale();

	//����
	D3DXVECTOR3 Forward();
	D3DXVECTOR3 Right();
	D3DXVECTOR3 Up();

	//���[���h�ϊ��ݒ菈��
	void SetWorld(const D3DXMATRIX* parent = NULL);
	void SetWorldInvView(const D3DXMATRIX* parent = NULL);
	D3DXMATRIX GetMatrix();
	
private:
	D3DXVECTOR3 pos;	//���W
	D3DXVECTOR3 scale;	//�X�P�[��
	D3DXQUATERNION rot;	//��]
};

#endif