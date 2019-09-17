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
#include "DelegateTest.h"

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
	sceneManager->Add("Delegate", new DelegateTest());

	sceneManager->ChangeScene("Particle");
}

#include "../Framework/Input/input.h"

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

	if (Debug::Button("Delegate"))
		SceneManager::ChangeScene("Delegate");

	if(Keyboard::GetTrigger(DIK_1))
		SceneManager::ChangeScene("Easing");

	if (Keyboard::GetTrigger(DIK_2))
		SceneManager::ChangeScene("Transform");

	if (Keyboard::GetTrigger(DIK_3))
		SceneManager::ChangeScene("Transition");

	if (Keyboard::GetTrigger(DIK_4))
		SceneManager::ChangeScene("Vector");

	if (Keyboard::GetTrigger(DIK_5))
		SceneManager::ChangeScene("Particle");

	if (Keyboard::GetTrigger(DIK_6))
		SceneManager::ChangeScene("Tween");

	if (Keyboard::GetTrigger(DIK_7))
		SceneManager::ChangeScene("Task");

	if (Keyboard::GetTrigger(DIK_8))
		SceneManager::ChangeScene("Collider");
}

/**************************************
グローバル変数
***************************************/

/**************************************
プロトタイプ宣言
***************************************/

