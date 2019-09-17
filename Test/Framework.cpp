//=====================================
//
//テンプレート処理[Framework.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "Framework.h"
#include "TransformTest.h"
#include "EasingTest.h"
#include "TestTransition.h"
#include "VectorTest.h"
#include "ParticleTest.h"
#include "TweenTest.h"
#include "TaskTest.h"
#include "ColliderTest.h"

#include "../Framework\Tool\DebugWindow.h"

/**************************************
マクロ定義
***************************************/
Framework::Framework(HINSTANCE hInstance, HWND hWnd) : BaseGame(hInstance, hWnd)
{
	sceneManager->Add("Transform", new TransformTest());
	sceneManager->Add("Easing", new EasingTest());
	sceneManager->Add("Transition", new TestTransition());
	sceneManager->Add("Vector", new VectorTest());
	sceneManager->Add("Particle", new ParticleTest());
	sceneManager->Add("Tween", new TweenTest());
	sceneManager->Add("Task", new TaskTest());
	sceneManager->Add("Collider", new ColliderTest());

	sceneManager->ChangeScene("Particle");
}

/**************************************
クラス定義
***************************************/
void Framework::Update()
{
	BaseGame::Update();

	if (Debug::Button("Easing"))
		SceneManager::ChangeScene("Easing");

	if (Debug::Button("Transform"))
		SceneManager::ChangeScene("Transform");

	if (Debug::Button("Transition"))
		SceneManager::ChangeScene("Transition");

	if (Debug::Button("Vector"))
		SceneManager::ChangeScene("Vector");

	if (Debug::Button("Particle"))
		SceneManager::ChangeScene("Particle");

	if (Debug::Button("Tween"))
		SceneManager::ChangeScene("Tween");

	if (Debug::Button("Task"))
		SceneManager::ChangeScene("Task");

	if (Debug::Button("Collider"))
		SceneManager::ChangeScene("Collider");
}

/**************************************
グローバル変数
***************************************/

/**************************************
プロトタイプ宣言
***************************************/

