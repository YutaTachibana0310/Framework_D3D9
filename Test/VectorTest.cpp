//=====================================
//
//テンプレート処理[VectorTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "VectorTest.h"
#include "../Framework\Tool\DebugWindow.h"

/**************************************
マクロ定義
***************************************/

/**************************************
グローバル変数
***************************************/
void VectorTest::Uninit()
{
	SAFE_RELEASE(mesh);
}

/**************************************
プロトタイプ宣言
***************************************/
void VectorTest::Init()
{
	mesh = MeshContainer::Create();
	mesh->Load("data/MODEL/transform.x");

	transform3D.SetPosition(Vector3::Zero);
	transform3D.SetRotation(Vector3::Zero);
}

/**************************************
プロトタイプ宣言
***************************************/
void VectorTest::Update()
{
	Debug::Begin("Vector");

	static D3DXVECTOR3 target = Vector3::Forward;
	if (Debug::Button("Set"))
	{
		target.x = Math::RandomRange(-20.0f, 20.0f);
		target.y = Math::RandomRange(-20.0f, 20.0f);
		target.z = Math::RandomRange(-20.0f, 20.0f);
	}

	float angle = Vector3::Angle(transform3D.Forward(), target);
	D3DXVECTOR3 axis = Vector3::Axis(transform3D.Forward(), target);
	transform3D.Rotate(angle * 0.3f, axis);
	
	Debug::Text("target : %f, %f, %f", target.x, target.y, target.z);
	Debug::Text("angle : %f", angle);
	Debug::Text("axis : %f, %f, %f", axis.x, axis.y, axis.z);
	Debug::Text("forward : %f, %f, %f", transform3D.Forward().x, transform3D.Forward().y, transform3D.Forward().z);

	Debug::End();
}

/**************************************
プロトタイプ宣言
***************************************/
void VectorTest::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	transform3D.SetWorld();
	mesh->Draw();
}
