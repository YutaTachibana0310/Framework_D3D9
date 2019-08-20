//=====================================
//
//�V�[���}�l�[�W������[SceneManager.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "SceneManager.h"
#include "BaseScene.h"
#include "../Resource/ResourceManager.h"

using namespace std;
/**************************************
static�����o
***************************************/
SceneManager* SceneManager::mInstance = NULL;

/**************************************
�R���X�g���N�^
***************************************/
SceneManager::SceneManager()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

/**************************************
�f�X�g���N�^
***************************************/
SceneManager::~SceneManager()
{
	Utility::DeleteMap(sceneContainer);

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

/**************************************
�V�[���`�F���W����
***************************************/
void SceneManager::ChangeScene(const char* sceneName)
{
	//�V�[���̑��݊m�F
	if (!mInstance->ExistsScene(sceneName))
	{
		MessageBox(0, "NextScene is Not Found", "Error", 0);
		return;
	}

	//�V�[���؂�ւ�
	mInstance->_ChengeScene(string(sceneName));
}

/**************************************
�V�[���`�F���W����(����)
***************************************/
void SceneManager::_ChengeScene(string next)
{
	//���݂̃V�[�����I��
	if (current != NULL)
	{
		current->Uninit();
		ResourceManager::Instance()->AllRelease();
	}

	//�؂�ւ�
	prev = current;
	current = sceneContainer[next];

	//������
	current->Init();
}

/**************************************
�V�[���ǉ�����
***************************************/
void SceneManager::Add(const char* sceneName, BaseScene* scene)
{
	if (ExistsScene(sceneName))
		return;

	sceneContainer[string(sceneName)] = scene;
}

/**************************************
�X�V����
***************************************/
void SceneManager::Update()
{
	current->Update();
}

/**************************************
�`�揈��
***************************************/
void SceneManager::Draw()
{
	current->Draw();
}

/**************************************
�V�[���̑��݊m�F
***************************************/
bool SceneManager::ExistsScene(const char* sceneName)
{
	return sceneContainer.count(string(sceneName)) != 0;
}