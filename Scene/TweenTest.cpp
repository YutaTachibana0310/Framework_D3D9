//=====================================
//
// TweenTest.cpp
// 機能:トゥイーンテスト
// Author:GP12B332 21 立花雄太
//
//=====================================
#include "TweenTest.h"
#include "../Framework/Camera/Camera.h"

/**************************************
グローバル変数
***************************************/

/**************************************
初期化処理
***************************************/
void TweenTestScene::Init()
{
	sceneCamera = new Camera();
	Camera::SetMainCamera(sceneCamera);
}

/**************************************
終了処理
***************************************/
void TweenTestScene::Uninit()
{
	SAFE_DELETE(sceneCamera);
}

/**************************************
更新処理
***************************************/
void TweenTestScene::Update()
{
	sceneCamera->Update();
}

/**************************************
描画処理
***************************************/
void TweenTestScene::Draw()
{
	sceneCamera->Set();
}
