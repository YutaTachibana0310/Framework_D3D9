//=====================================
//
//トランスフォームテストヘッダ[TransformTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TRANSFORMTEST_H_
#define _TRANSFORMTEST_H_

#include "../main.h"
#include "../Framework\Core\BaseScene.h"
#include "../Framework/Renderer3D/TransformObject.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class TransformTest : public BaseScene
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