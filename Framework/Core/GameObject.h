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
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	GameObject();
	virtual ~GameObject();

	//�A�N�e�B�u����
	inline bool IsActive();

	//�A�N�e�B�u��ԃZ�b�g����
	inline void SetActive(bool active);

	//SRT���
	std::shared_ptr<Transform> transform;

protected:
	//�A�N�e�B�u���
	bool active;
};

#endif