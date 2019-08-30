//=====================================
//
//ベースコライダーヘッダ[BaseCollider.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASECOLLIDER_H_
#define _BASECOLLIDER_H_

#include "../../main.h"
#include "ColliderObserver.h"
#include <vector>

/**************************************
前方宣言
***************************************/

/**************************************
クラス定義
***************************************/
class BaseCollider
{
public:
	BaseCollider(ColliderObserver& observer, const Transform& transform);
	virtual ~BaseCollider();

	void SetActive(bool state);
	bool IsActive();

protected:
	bool active;
	ColliderObserver& observer;
	const Transform& refTransform;
};

#endif