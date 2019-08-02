//=============================================================================
//
// イージングヘッダ [Easing.h]
// Author : GP12B332 21 立花雄太
//
//=============================================================================
#ifndef _EASING_H_
#define _EASING_H_

#include "TMath.h"

//*****************************************************************************
// クラス宣言
//*****************************************************************************
class Easing
{
public:
	/***************************
	InCubic計算クラス
	***************************/
	template <class T>
	static T InCubic(float time, const T& start, const T& end)
	{

		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		return (end - start) * time * time + start;

	}

	/***************************
	OutCubic計算クラス
	***************************/
	template <class T>
	static T OutCubic(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		return -(end - start) * time * (time - 2.0f) + start;
	}

	/***************************
	InOutCubic計算クラス
	***************************/
	template <class T>
	static T InOutCubic(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		time *= 2.0f;

		if (time < 1.0f)
			return (end - start) / 2.0f * time * time + start;
		else
		{
			time -= 1.0f;
			return -(end - start) / 2.0f * (time * (time - 2.0f) - 1.0f) + start;
		}
	}

	/***************************
	Linear計算クラス
	***************************/
	template <class T>
	static T Linear(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		return (end - start) * time + start;
	}

	/***************************
	InExponential計算クラス
	***************************/
	template<class T>
	static T InExponential(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		return (end - start) * powf(2.0f, 10.0f * (time - 1.0f)) + start;
	}

	/***************************
	OutExponential計算クラス
	***************************/
	template<class T>
	static T OutExponential(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		return (end - start) * (-powf(2.0f, (-10 * time)) + 1.0f) + start;
	}

	/***************************
	InOutExponential計算処理
	***************************/
	template<class T>
	static T InOutExponential(float time, const T& start, const T& end)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		float per = Math::Bezier3(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 0.0f), D3DXVECTOR2(0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f), time).y;
		return (end - start) * per + start;
	}

};
#endif