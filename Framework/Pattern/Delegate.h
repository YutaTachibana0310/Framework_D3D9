//=====================================
//
// Delegate.h
// �@�\:
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _DELEGATE_H_
#define _DELEGATE_H_

#include <memory>

/**************************************
Delegater���N���X�錾
***************************************/
template<class TFunc>
class DelegateBase;

/**************************************
Delegater���N���X��`
***************************************/
template<class TResult, class ...TArgs>
class DelegateBase<TResult(TArgs...)>
{
public:
	DelegateBase() {}
	virtual ~DelegateBase() {}

	virtual TResult operator()(TArgs... args) = 0;
};

///**************************************
//Delegater���N���X��`�i����void�̓��ꉻ�j
//***************************************/
//template<class TResult>
//class DelegateBase<TResult(void)>
//{
//public:
//	DelegateBase() {}
//	virtual ~DelegateBase() {}
//
//	virtual TResult operator()() = 0;
//};

/**************************************
Delegater�N���X
***************************************/
template<class TObject, class TFunc>
class Delegate;

template <class TObject, class TResult, class ...TArgs>
class Delegate<TObject, TResult(TArgs...)> : public DelegateBase<TResult(TArgs...)>
{
	typedef TResult(TObject::*EventFunc)(TArgs...);
public:
	Delegate() :
		object(NULL), func(NULL) {}

	virtual ~Delegate() {}

	//�֐����s�̃I�y���[�^
	virtual TResult operator()(TArgs... args)
	{
		return (object->*func)(args...);
	}

	//�I�u�W�F�N�g�Ɗ֐��̓o�^����
	void Set(TObject* object, EventFunc func)
	{
		this->object = object;
		this->func = func;
	}

	//�f���Q�[�^�쐬����
	static DelegateBase<TResult(TArgs...)>* Create(TObject* object, TResult (TObject::*func)(TArgs...))
	{
		Delegate<TObject, TResult(TArgs...)>* delegate = new Delegate<TObject, TResult(TArgs...)>;
		delegate->Set(object, func);
		return  delegate;
	}

protected:
	TObject *object;			//�I�u�W�F�N�g
	EventFunc func;			//�֐��|�C���^
};

#endif
