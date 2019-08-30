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
BaseCollider::BaseCollider(ColliderObserver & observer, const Transform& transform) :
	observer(observer),
	refTransform(transform),
	active(true)
{

}

/**************************************
デストラクタ
***************************************/
BaseCollider::~BaseCollider()
{
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
