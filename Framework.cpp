//=====================================
//
//�e���v���[�g����[Framework.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Framework.h"
#include "Framework\Tool\DebugWindow.h"

#include "Scene/TweenTest.h"
#include "Scene/TransformTest.h"

/**************************************
�}�N����`
***************************************/
Framework::Framework(HINSTANCE hInstance, HWND hWnd) : BaseGame(hInstance, hWnd)
{
	sceneManager->Add(0, new TweenTestScene(renderTexture, renderSurface));
	sceneManager->Add(1, new TransformTestScene(renderTexture, renderSurface));

	sceneManager->ChangeScene(1);
}

/**************************************
�N���X��`
***************************************/
void Framework::Update()
{
	BaseGame::Update();
}

/**************************************
�O���[�o���ϐ�
***************************************/

/**************************************
�v���g�^�C�v�錾
***************************************/

