//=====================================
//
//テンプレート処理[Framework.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "Framework.h"
#include "Framework\Tool\DebugWindow.h"

#include "Scene/TweenTest.h"
#include "Scene/TransformTest.h"

/**************************************
マクロ定義
***************************************/
Framework::Framework(HINSTANCE hInstance, HWND hWnd) : BaseGame(hInstance, hWnd)
{
	sceneManager->Add(0, new TweenTestScene(renderTexture, renderSurface));
	sceneManager->Add(1, new TransformTestScene(renderTexture, renderSurface));

	sceneManager->ChangeScene(1);
}

/**************************************
クラス定義
***************************************/
void Framework::Update()
{
	BaseGame::Update();
}

/**************************************
グローバル変数
***************************************/

/**************************************
プロトタイプ宣言
***************************************/

