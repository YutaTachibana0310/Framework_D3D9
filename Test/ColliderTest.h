//=====================================
//
// ColliderTest.h
// 機能:
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _COLLIDERTEST_H_
#define _COLLIDERTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Core/GameObject.h"
#include "../Framework/Collider/BoxCollider3D.h"

#include <vector>
/**************************************
前方宣言
***************************************/
class ColliderObject;

/**************************************
クラス定義
***************************************/
class ColliderTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	std::vector<ColliderObject*> objectList;
};

class ColliderObject : public GameObject, public ColliderObserver
{
public:
	ColliderObject();
	~ColliderObject();

	void Draw();
	void Move(const D3DXVECTOR3& dir);
private:
	void OnColliderHit(const std::string & other) override;

	std::shared_ptr<BoxCollider3D> collider;
};

#endif