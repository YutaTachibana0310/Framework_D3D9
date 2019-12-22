//=====================================
//
//�e���v���[�g����[Framework.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Framework.h"
#include "Framework\Tool\DebugWindow.h"

#include "Scene/TweenTest.h"

/**************************************
�}�N����`
***************************************/
Framework::Framework(HINSTANCE hInstance, HWND hWnd) : BaseGame(hInstance, hWnd)
{
	sceneManager->Add(0, new TweenTestScene(renderTexture, renderSurface));

	sceneManager->ChangeScene(0);
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

