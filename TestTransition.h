//=====================================
//
//�e�X�g�g�����W�V�����w�b�_[TestTransition.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TESTTRANSITION_H_
#define _TESTTRANSITION_H_

#include "main.h"
#include "Framework\Transition\TransitionController.h"
#include "Framework\Core\BaseScene.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class TestTransition: public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

	int type;
	bool transitionOut;
private:
};

#endif