//=====================================
//
//ゲームオブジェクトヘッダ[GameObject.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Transform.h"
#include <memory>

class Transform;
/**************************************
マクロ定義
***************************************/

/**************************************
ゲームオブジェクト基底クラス
***************************************/
class GameObject
{
public:
	//コンストラクタ、デストラクタ
	GameObject();
	virtual ~GameObject();

	//アクティブ判定
	inline bool IsActive();

	//アクティブ状態セット処理
	inline void SetActive(bool active);

	//SRT情報
	std::shared_ptr<Transform> transform;

protected:
	//アクティブ状態
	bool active;
};

#endif