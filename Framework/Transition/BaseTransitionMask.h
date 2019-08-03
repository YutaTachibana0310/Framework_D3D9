//=====================================
//
//ベーストランジションヘッダ[BaseTransitionMask.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASETRANSITIONMASK_H_
#define _BASETRANSITIONMASK_H_

#include "../../main.h"

/**************************************
マクロ定義
***************************************/
enum MaskResult
{
	Continuous,
	FinishTransitionIn,
	FinishTransitionOut
};

/**************************************
クラス定義
***************************************/
class Polygon2D;

class BaseTransitionMask
{
public:
	BaseTransitionMask();
	virtual ~BaseTransitionMask();

	virtual MaskResult Update() = 0;

	virtual void Draw();

	virtual void Set(bool isTransitionOut) = 0;

protected:
	bool active;
	bool isTransitionOut;

	Polygon2D *polygon;

	virtual void BeginMask();
	virtual void EndMask();
};

#endif