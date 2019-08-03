//=====================================
//
//�g�����X�t�H�[���w�b�_[Transform.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "../main.h"

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

	//�R���X�g���N�^
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);

	//��]����
	void Rotate(float degX, float degY, float degZ);
	void RotateByAxis(float deg, D3DXVECTOR3 axis);
	void IdentifyRotation();

	//����
	D3DXVECTOR3 Forward();
	D3DXVECTOR3 Right();
	D3DXVECTOR3 Up();

	//�I�C���[�p�擾����
	D3DXVECTOR3 GetEulerAngle();

	//���[���h�ϊ��ݒ菈��
	void SetWorld();
	void SetWorldInvView();

private:
	D3DXQUATERNION rot;	//��]
	
};

#endif