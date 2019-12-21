//=====================================
//
// TweenTest.cpp
// �@�\:�g�D�C�[���e�X�g
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#include "TweenTest.h"
#include "../Framework/Camera/Camera.h"

/**************************************
�O���[�o���ϐ�
***************************************/

/**************************************
����������
***************************************/
void TweenTestScene::Init()
{
	sceneCamera = new Camera();
	Camera::SetMainCamera(sceneCamera);
}

/**************************************
�I������
***************************************/
void TweenTestScene::Uninit()
{
	SAFE_DELETE(sceneCamera);
}

/**************************************
�X�V����
***************************************/
void TweenTestScene::Update()
{
	sceneCamera->Update();
}

/**************************************
�`�揈��
***************************************/
void TweenTestScene::Draw()
{
	sceneCamera->Set();
}
