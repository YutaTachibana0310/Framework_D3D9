//=====================================
//
//�Q�[���I�u�W�F�N�g�w�b�_[GameObject.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Transform.h"
#include <memory>

class Transform;
/**************************************
�}�N����`
***************************************/

/**************************************
�Q�[���I�u�W�F�N�g���N���X
***************************************/
class GameObject
{
	friend class Tween;
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	GameObject();
	virtual ~GameObject();

	//�A�N�e�B�u����
	inline bool IsActive();

	//�A�N�e�B�u��ԃZ�b�g����
	inline void SetActive(bool active);

	//SRT���Q�b�^�[�i�Ȃ�ׂ��g�������Ȃ��j
	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();
	D3DXVECTOR3 GetScale();

	//SRT���Z�b�^�[�i�Ȃ�ׂ��g�������Ȃ��j
	void SetPosition(const D3DXVECTOR3& position);
	void SetRotatition(const D3DXVECTOR3& rotation);
	void SetScale(const D3DXVECTOR3& scale);

protected:
	//�A�N�e�B�u���
	bool active;

	//SRT���
	std::shared_ptr<Transform> transform;
};

#endif