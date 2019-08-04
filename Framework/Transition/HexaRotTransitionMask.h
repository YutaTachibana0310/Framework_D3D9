//=====================================
//
//�w�L�T�g�����W�V�����w�b�_[HexaRotTransitionMask.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _HEXAROTTRANSITIONMASK_H_
#define _HEXAROTTRANSITIONMASK_H_

#include "../../main.h"
#include "BaseTransitionMask.h"
#include "../Math/Easing.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class HexaRotTransitionMask : public BaseTransitionMask
{
public:
	HexaRotTransitionMask()
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