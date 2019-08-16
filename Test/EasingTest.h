//=====================================
//
//イージングテストヘッダ[EasingTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _EASINGTEST_H_
#define _EASINGTEST_H_

#include "../main.h"
#include "../Framework\Renderer2D\Polygon2D.h"
#include "../Framework\Math\Easing.h"
#include "../Framework\Core\BaseScene.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class EasingTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	int cntFrame;
	Polygon2D* polygon;
	int type;

};

#endif