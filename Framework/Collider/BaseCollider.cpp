//=====================================
//
//コライダーオブザーバー処理[ColliderObserver.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ColliderObserver.h"
#include "BaseCollider.h"

/**************************************
コンストラクタ
***************************************/
BaseCollider::BaseCollider(const std::shared_ptr<Transform> transform) :
	active(true)
{
	refTransform = transform;
}

/**************************************
デストラクタ
***************************************/
BaseCollider::~BaseCollider()
{
	refTransform.reset();
}

/**************************************
アクティブセット処理
***************************************/
void BaseCollider::SetActive(bool state)
{
	active = state;
}

/**************************************
アクティブ判定
***************************************/
bool BaseCollider::IsActive()
{
	return active;
}
