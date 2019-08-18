//=====================================
//
//トゥイーンテストヘッダ[TweenTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TWEENTEST_H_
#define _TWEENTEST_H_

#include "../main.h"
#include "../Framework\Core\BaseScene.h"
#include "../Framework/Renderer3D/TransformObject.h"

/**************************************
前方宣言
***************************************/

/**************************************
マクロ・列挙子定義
***************************************/

/**************************************
クラス定義
***************************************/
class TweenTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	TransformObject *object;
};

#endif