//=====================================
//
//トランスフォームテスト処理[TransformTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TransformTest.h"
#include "../Framework\Input\input.h"
#include "../Framework\Tool\DebugWindow.h"
#include "../Framework\Camera\Camera.h"
#include "../Framework\Camera\CameraShakePlugin.h"

/**************************************
マクロ定義
***************************************/

/**************************************
デストラクタ
***************************************/
void TransformTest::Uninit()
{
	SAFE_DELETE(mesh);
}

/**************************************
初期化処理
***************************************/
void TransformTest::Init()
{
	mesh = new MeshContainer();
	mesh->Load("data/MODEL/transform.x");

	transform.pos = D3DXVECTOR3(0.0f, -15.0f, 0.0f);
	transform.scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	transform.IdentifyRotation();
	transform.Rotate(0.0f, 45.0f, 0.0f);
}

/**************************************
更新処理
***************************************/
void TransformTest::Update()
{
	Debug::Begin("Transform");

	float x = Input::GetPressHorizontail(0);
	float y = Input::GetPressVertical(0);

	float rotAngle = 2.0f;
	transform.Rotate(0.0f, x * rotAngle, 0.0f);
	transform.RotateByAxis(rotAngle * y, transform.Right());

	D3DXVECTOR3 dir;
	ZeroMemory(&dir, sizeof(dir));
	x = Keyboard::GetPress(DIK_W) ? -1.0f : Keyboard::GetPress(DIK_S) ? 1.0f : 0.0f;
	y = Keyboard::GetPress(DIK_A) ? -1.0f : Keyboard::GetPress(DIK_D) ? 1.0f : 0.0f;
	transform.pos += x * transform.Right();
	transform.pos += y * transform.Forward();

	if (Debug::Button("Init Angle"))
		transform.IdentifyRotation();

	if (Debug::Button("Init Pos"))
		transform.pos = D3DXVECTOR3(0.0f, -15.0f, 0.0f);

	static float scale = 1.0f;
	Debug::Slider("scale", scale, 0.0f, 10.0f);
	transform.scale = scale * D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	if (Debug::Button("Shake"))
		Camera::ShakePlugin::Instance()->Set(D3DXVECTOR3(10.0f, 10.0f, 10.0f), 300);

	Debug::End();
}

/**************************************
描画処理
***************************************/
void TransformTest::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	transform.SetWorld();

	mesh->Draw();
}