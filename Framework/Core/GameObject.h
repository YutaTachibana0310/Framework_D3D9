//=====================================
//
//ゲームオブジェクトヘッダ[GameObject.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

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

	//描画処理
	virtual void Draw() = 0;

	//アクティブ判定
	bool IsActive();

	//アクティブ状態セット処理
	void SetActive(bool active);

private:
	//SRT情報
	Transform* transform;

	//アクティブ状態
	bool active;
};

#endif