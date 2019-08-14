//=====================================
//
//�V�[���}�l�[�W���w�b�_[SceneManager.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "../../main.h"
#include <unordered_map>

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class BaseScene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static void ChangeScene(const char* sceneName);

	void Add(const char* sceneName, BaseScene* scene);

	void Update();
	void Draw();
	bool ExistsScene(const char* sceneName);

private:
	std::unordered_map<std::string, BaseScene*> sceneContainer;
	BaseScene *current, *prev;

	void _ChengeScene(std::string next);

	static SceneManager* mInstance;
};

#endif