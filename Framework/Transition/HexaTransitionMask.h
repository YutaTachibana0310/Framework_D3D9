//=====================================
//
//�w�L�T�g�����W�V�����w�b�_[HexaTransitionMask.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _HEXATRANSITIONMASK_H_
#define _HEXATRANSITIONMASK_H_

#include "../../main.h"
#include "BaseTransitionMask.h"
#include "../Math/Easing.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
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