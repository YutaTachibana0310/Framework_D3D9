//=====================================
//
//コライダーマネージャヘッダ[ColliderManager.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _COLLIDERMANAGER_H_
#define _COLLIDERMANAGER_H_

#include "BoxCollider3D.h"
#include "../Pattern/BaseSingleton.h"

#include <unordered_map>
#include <list>
#include <string>
#include <memory>
#include <string>

/**************************************
前方宣言
***************************************/

/**************************************
クラス定義
***************************************/
class ColliderManager : public BaseSingleton<ColliderManager>
{
public:
	//ボックスコライダー作成処理
	std::shared_ptr<BoxCollider3D> CreateBoxCollider(const std::string& tag, const Transform& transform, ColliderObserver& observer);
	std::shared_ptr<BoxCollider3D> CreateBoxCollider(const std::string& tag, const Transform& transform, ColliderObserver& observer, const D3DXVECTOR3& size);

	//更新処理
	void CheckCollision();

	//クリア処理
	void Clear();

private:
	//ボックスコライダーコンテナ
	std::unordered_map <std::string, std::list<std::weak_ptr<BoxCollider3D>>> boxColliderMap;
	
	void CheckRoundRobin(const std::string& tag1, const std::string& tag2);
};

#endif