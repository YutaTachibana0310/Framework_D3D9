//=====================================
//
//ゲームオブジェクト処理[GameObject.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "GameObject.h"
#include "Transform.h"

/**************************************
マクロ定義
***************************************/

/**************************************
コンストラクタ
***************************************/
GameObject::GameObject()
{
	transform = std::make_shared<Transform>();
	active = true;
}

/**************************************
デストラクタ
***************************************/
GameObject::~GameObject()
{
	transform.reset();
}

/**************************************
アクティブ判定
***************************************/
inline bool GameObject::IsActive()
{
	return active;
}

/**************************************
アクティブ状態セット処理
***************************************/
inline void GameObject::SetActive(bool active)
{
	this->active = active;
}

/**************************************
座標セット
***************************************/
D3DXVECTOR3 GameObject::GetPosition()
{
	return transform->pos;
}
/**************************************
座標ゲット
***************************************/
void GameObject::SetPosition(const D3DXVECTOR3& position)
{
	transform->pos = position;
}

/**************************************
回転角度ゲット
***************************************/
D3DXVECTOR3 GameObject::GetRotation()
{
	return transform->GetEulerAngle();
}

/**************************************
回転角度セット
***************************************/
void GameObject::SetRotatition(const D3DXVECTOR3& rotation)
{
	transform->rot = Quaternion::ToQuaternion(rotation);
}

/**************************************
スケールゲット
***************************************/
D3DXVECTOR3 GameObject::GetScale()
{
	return transform->scale;
}

/**************************************
スケールセット
***************************************/
void GameObject::SetScale(const D3DXVECTOR3& scale)
{
	transform->scale = scale;
}