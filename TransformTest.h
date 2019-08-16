//=====================================
//
//トランスフォームテストヘッダ[TransformTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TRANSFORMTEST_H_
#define _TRANSFORMTEST_H_

#include "main.h"
#include "Framework\Renderer3D\MeshContainer.h"
#include "Framework\Core\BaseScene.h"

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

	Transform transform;
private:
	MeshContainer *mesh;
};

#endif