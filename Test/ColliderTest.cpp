//=====================================
//
//テンプレート処理[ColliderTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ColliderTest.h"
#include "../Framework/Collider/ColliderManager.h"
#include "../Framework/Tool/DebugWindow.h"
#include "../Framework/Math/TMath.h"
#include "../Framework/Input/input.h"

/**************************************
グローバル変数
***************************************/

/**************************************
プロトタイプ宣言
***************************************/
void ColliderTest::Init()
{
	const int ObjectMax = 5;
	for (int i = 0; i < ObjectMax; i++)
	{
		objectList.push_back(new ColliderObject());
	}
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderTest::Uninit()
{
	Utility::DeleteContainer(objectList);
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderTest::Update()
{
	float x = Input::GetPressHorizontail(0);
	float y = Input::GetPressVertical(0);
	float z = Keyboard::GetPress(DIK_W) ? 1.0f : Keyboard::GetPress(DIK_S) ? -1.0f : 0.0f;

	objectList[0]->Move(D3DXVECTOR3(x, y, z));

	ColliderManager::Instance()->CheckCollision();
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderTest::Draw()
{
	for (auto&& object : objectList)
	{
		object->Draw();
	}
}

/**************************************
プロトタイプ宣言
***************************************/
ColliderObject::ColliderObject()
{
	collider = ColliderManager::Instance()->CreateBoxCollider("Test", transform, Vector3::One * 5.0f);
	collider->AddObserver(this);

	const float Positionrange = 30.0f;
	D3DXVECTOR3 position = D3DXVECTOR3(Math::RandomRange(-Positionrange, Positionrange), Math::RandomRange(-Positionrange, Positionrange), Math::RandomRange(-Positionrange, Positionrange));
	transform->SetPosition(position);
}

/**************************************
プロトタイプ宣言
***************************************/
ColliderObject::~ColliderObject()
{
	collider.reset();
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderObject::Draw()
{
	collider->Draw();
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderObject::Move(const D3DXVECTOR3 & dir)
{
	transform->Move(dir * 3.0f);
}

/**************************************
プロトタイプ宣言
***************************************/
void ColliderObject::OnColliderHit(const std::string & other)
{
	Debug::Log("%d is hitted", collider->GetUniqueID());
}
