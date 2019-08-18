//=====================================
//
//トランスフォームオブジェクト処理[TransformObject.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TransformObject.h"

/**************************************
マクロ定義
***************************************/

/**************************************
コンストラクタ
***************************************/
TransformObject::TransformObject()
{
	mesh = new MeshContainer();
	mesh->Load("data/MODEL/transform.x");
}

/**************************************
デストラクタ
***************************************/
TransformObject::~TransformObject()
{
	SAFE_DELETE(mesh);
}

/**************************************
描画処理
***************************************/
void TransformObject::Draw()
{
	transform->SetWorld();
	mesh->Draw();
}