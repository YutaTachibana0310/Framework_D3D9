//=====================================
//
//�Q�[���I�u�W�F�N�g�w�b�_[GameObject.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

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

	//�`�揈��
	virtual void Draw() = 0;

	//�A�N�e�B�u����
	bool IsActive();

	//�A�N�e�B�u��ԃZ�b�g����
	void SetActive(bool active);

private:
	//SRT���
	Transform* transform;

	//�A�N�e�B�u���
	bool active;
};

#endif