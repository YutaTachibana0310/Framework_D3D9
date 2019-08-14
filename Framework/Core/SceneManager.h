//=====================================
//
//シーンマネージャヘッダ[SceneManager.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "../../main.h"
#include <unordered_map>

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
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