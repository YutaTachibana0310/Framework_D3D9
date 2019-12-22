//=====================================
//
// ValueTweener.h
// 機能:値トゥイーナー
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _VALUETWEENER_H_
#define _VALUETWEENER_H_

#include "../../../main.h"
#include "Tweener.h"

/**************************************
前方宣言
***************************************/

/**************************************
クラス定義
***************************************/
template<class T>
class ValueTweener : Tweener<T>
{
public:
	ValueTweener(std::shared_ptr<T>& ref, const T& start, const T& end, int duration, EaseType type, Callback callback) :
		Tweener(ref, duration, type, callback),
		start(start),
		end(end)
	{

	}

	void Update()
	{
		cntFrame++;

		std::shared_ptr<T> value = reference.lock();
		if (value)
		{
			float t = (float)cntFrame / duration;
			*value = Easing::EaseValue(t, start, end, easeType);
			CheckCallback();
		}
	}

protected:
	T start, end;
};

#endif