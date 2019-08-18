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
	D3DXVECTOR3 pos;	//���W
	D3DXVECTOR3 scale;	//�X�P�[��
	D3DXQUATERNION rot;	//��]

	//�R���X�g���N�^
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);

	//��]����
	void Rotate(float degX, float degY, float degZ);
	void RotateByAxis(float deg, D3DXVECTOR3 axis);
	void SetRotation(float x, float y, float z);
	D3DXVECTOR3 GetEulerAngle();
	void IdentifyRotation();

	//����
	D3DXVECTOR3 Forward();
	D3DXVECTOR3 Right();
	D3DXVECTOR3 Up();

	//���[���h�ϊ��ݒ菈��
	void SetWorld();
	void SetWorldInvView();
	D3DXMATRIX GetMatrix();
	
};

#endif