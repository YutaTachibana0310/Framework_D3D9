//=====================================
//
// Delegate.h
// 機能:
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _DELEGATE_H_
#define _DELEGATE_H_

#include <memory>

/**************************************
Delegater基底クラス宣言
***************************************/
template<class TFunc>
class DelegateBase;

/**************************************
Delegater基底クラス定義
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
//Delegater基底クラス定義（引数voidの特殊化）
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
Delegaterクラス
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

	//関数実行のオペレータ
	virtual TResult operator()(TArgs... args)
	{
		return (object->*func)(args...);
	}

	//オブジェクトと関数の登録処理
	void Set(TObject* object, EventFunc func)
	{
		this->object = object;
		this->func = func;
	}

	//デリゲータ作成処理
	static DelegateBase<TResult(TArgs...)>* Create(TObject* object, TResult (TObject::*func)(TArgs...))
	{
		Delegate<TObject, TResult(TArgs...)>* delegate = new Delegate<TObject, TResult(TArgs...)>;
		delegate->Set(object, func);
		return  delegate;
	}

protected:
	TObject *object;			//オブジェクト
	EventFunc func;			//関数ポインタ
};

#endif
