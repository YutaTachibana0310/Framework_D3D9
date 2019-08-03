//=====================================
//
//�x�[�X�g�����W�V�����w�b�_[BaseTransitionMask.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASETRANSITIONMASK_H_
#define _BASETRANSITIONMASK_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/
enum MaskResult
{
	Continuous,
	FinishTransitionIn,
	FinishTransitionOut
};

/**************************************
�N���X��`
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