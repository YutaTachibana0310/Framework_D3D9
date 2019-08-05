//=============================================================================
//
// ステートインターフェースヘッダ [IState.h]
// Author : 立花雄太
//
//=============================================================================
#ifndef _ISTATE_H_
#define _ISTATE_H_

#define STATE_CONTINUOUS	(0)		//ステートを続行する
#define STATE_FINISHED		(1)		//ステートは終了した

/*****************************************************
IStateMachineクラス
継承先でOnUpdate(), OnStart()を実装する
*****************************************************/
template <class T>
class IState {
public:
	virtual int OnUpdate(T& entity) = 0;
	virtual void OnStart(T& entity) = 0;
};

#endif