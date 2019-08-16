//=====================================
//
//ベクトルテストヘッダ[VectorTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _VECTORTEST_H_
#define _VECTORTEST_H_

#include "../main.h"
#include "../Framework\Renderer3D\MeshContainer.h"
#include "../Framework\Renderer2D\Polygon2D.h"
#include "../Framework\Core\BaseScene.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class VectorTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	Transform transform3D;
	MeshContainer* mesh;

	Transform transform2D;
};

#endif