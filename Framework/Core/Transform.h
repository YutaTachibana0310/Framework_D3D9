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
	Transform(const Transform&);
	virtual ~Transform() {}

	//���Z�q
	virtual Transform operator = (const Transform&);

	//�ړ�����
	virtual void Move(const D3DXVECTOR3& velocity);
	virtual void SetPosition(const D3DXVECTOR3& position);
	virtual D3DXVECTOR3 GetPosition();

	//��]����
	virtual void Rotate(float degreeX, float degreeY, float degreeZ);
	virtual void Rotate(float degree, const D3DXVECTOR3& axis);
	virtual void SetRotation(const D3DXVECTOR3& rotation);
	virtual void SetRotation(const D3DXQUATERNION& rotation);
	virtual D3DXVECTOR3 GetEulerAngle();
	virtual D3DXQUATERNION GetRotation();

	//�X�P�[������
	virtual void Scale(const D3DXVECTOR3& delta);
	virtual void SetScale(const D3DXVECTOR3& scale);
	virtual D3DXVECTOR3 GetScale();

	//����
	virtual D3DXVECTOR3 Forward();
	virtual D3DXVECTOR3 Right();
	virtual D3DXVECTOR3 Up();

	//���[���h�ϊ��ݒ菈��
	virtual void SetWorld(const D3DXMATRIX* parent = NULL);
	virtual D3DXMATRIX GetMatrix();
	
protected:
	D3DXVECTOR3 position;	//���W
	D3DXVECTOR3 scale;	//�X�P�[��
	D3DXQUATERNION rotation;	//��]
};

#endif