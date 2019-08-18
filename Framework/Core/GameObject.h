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
	friend class Tween;
public:
	//コンストラクタ、デストラクタ
	GameObject();
	virtual ~GameObject();

	//アクティブ判定
	inline bool IsActive();

	//アクティブ状態セット処理
	inline void SetActive(bool active);

	//SRT情報ゲッター（なるべく使いたくない）
	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();
	D3DXVECTOR3 GetScale();

	//SRT情報セッター（なるべく使いたくない）
	void SetPosition(const D3DXVECTOR3& position);
	void SetRotatition(const D3DXVECTOR3& rotation);
	void SetScale(const D3DXVECTOR3& scale);

protected:
	//アクティブ状態
	bool active;

	//SRT情報
	std::shared_ptr<Transform> transform;
};

#endif