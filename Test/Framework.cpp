//=====================================
//
//�e���v���[�g����[Framework.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Framework.h"
#include "TransformTest.h"
#include "EasingTest.h"
#include "TestTransition.h"
#include "VectorTest.h"
#include "ParticleTest.h"
#include "TweenTest.h"

#include "../Framework\Tool\DebugWindow.h"

/**************************************
�}�N����`
***************************************/
Framework::Framework(HINSTANCE hInstance, HWND hWnd) : BaseGame(hInstance, hWnd)
{
	sceneManager->Add("Transform", new TransformTest());
	sceneManager->Add("Easing", new EasingTest());
	sceneManager->Add("Transition", new TestTransition());
	sceneManager->Add("Vector", new VectorTest());
	sceneManager->Add("Particle", new ParticleTest());
	sceneManager->Add("Tween", new TweenTest());

	sceneManager->ChangeScene("Particle");
}

/**************************************
�N���X��`
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
}

/**************************************
�O���[�o���ϐ�
***************************************/

/**************************************
�v���g�^�C�v�錾
***************************************/

