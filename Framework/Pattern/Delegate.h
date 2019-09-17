//=====================================
//
// Delegate.h
// �@�\:
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _DELEGATE_H_
#define _DELEGATE_H_

/**************************************
�O���錾
***************************************/

/**************************************
Delegater���N���X
***************************************/
class DelegateBase
{
public:
	DelegateBase() {}
	virtual ~DelegateBase() {}

	//int�^�����L��߂�l�����̊֐�
	virtual void operator()(int arg) = 0;
};

/**************************************
Delegater�N���X
***************************************/
template <class T>
class Delegate : public DelegateBase
{
	typedef void(T::*EventFunc)(int);
public:
	Delegate() :
		object(NULL), func(NULL) {}

	virtual ~Delegate() {}

	//�����Ȃ��߂�l�Ȃ��̊֐����s�̃I�y���[�^
	virtual void oprator(int arg)
	{
		//if (object != NULL && func != NULL)
			(object->*func)(arg);
	}

	//�I�u�W�F�N�g�Ɗ֐��̓o�^����
	void Set(T* object, EventFunc func)
	{
		this->object = object;
		this->func = func;
	}

protected:
	T* object;			//�I�u�W�F�N�g
	EventFunc func;		//�֐��|�C���^
};

#endif
