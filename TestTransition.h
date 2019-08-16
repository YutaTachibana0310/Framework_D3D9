//=====================================
//
//テストトランジションヘッダ[TestTransition.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TESTTRANSITION_H_
#define _TESTTRANSITION_H_

#include "main.h"
#include "Framework\Transition\TransitionController.h"
#include "Framework\Core\BaseScene.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
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