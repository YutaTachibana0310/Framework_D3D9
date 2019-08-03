//=====================================
//
//ヘキサトランジションヘッダ[HexaTransitionMask.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _HEXATRANSITIONMASK_H_
#define _HEXATRANSITIONMASK_H_

#include "../../main.h"
#include "BaseTransitionMask.h"
#include "../Math/Easing.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class HexaTransitionMask : public BaseTransitionMask
{
public:
	HexaTransitionMask()
	{
		cntFrame = 120;
	}

	MaskResult Update();

	void Set(bool isTransitionOut);

private:
	int cntFrame;
	D3DXVECTOR3 initScale;
	D3DXVECTOR3 goalScale;
	EaseType easeType;
};

#endif