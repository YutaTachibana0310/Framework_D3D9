//=====================================
//
//エクスプロージョンフレア処理[ExplosionFlare.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ExplosionFlare.h"
#include "../../Framework/Math/Easing.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/

/**************************************
グローバル変数
***************************************/
const float Asset::ExplosionFlare::SpeedMax = 10.0f;
const float Asset::ExplosionFlare::SpeedMin = 5.0f;
const int Asset::ExplosionFlare::LifeMax = 40;
const int Asset::ExplosionFlare::LifeMin = 30;
const int Asset::ExplosionFlare::TexDivX = 2;
const int Asset::ExplosionFlare::TexDivY = 2;
const float Asset::ExplosionFlare::RotateMax = 360.0f;
const float Asset::ExplosionFlare::ScaleMax = 1.0f;
const float Asset::ExplosionFlare::ScaleMin = 0.75f;
const float Asset::ExplosionFlare::RotateAngle = 12.0f;

/**************************************
コンストラクタ
***************************************/
Asset::ExplosionFlare::ExplosionFlare() :
	BaseParticle(1.0f * Math::RandomRange(0, TexDivX) / TexDivX, 1.0f * Math::RandomRange(0, TexDivY) / TexDivY, LifeMin, LifeMax),
	moveDir(Vector3::Random()),
	speed(Math::RandomRange(SpeedMin, SpeedMax))
{
}

void Asset::ExplosionFlare::Init()
{
	cntFrame = 0;
	active = true;

	transform->Rotate(0.0f, 0.0f, Math::RandomRange(0.0f, RotateMax));
	transform->SetScale(Vector3::One * Math::RandomRange(ScaleMin, ScaleMax));
}

void Asset::ExplosionFlare::Update()
{
	if (!IsActive())
		return;

	cntFrame++;

	float t = 1.0f * cntFrame / lifeFrame;

	float currentSpeed = Easing::EaseValue(t, speed, 0.0f, EaseType::OutSine);
	transform->Move(currentSpeed * moveDir);

	float currentScale = Easing::EaseValue(t, 1.0f, 0.0f, EaseType::InSine);
	transform->SetScale(Vector3::One * currentScale);

	transform->Rotate(0.0f, 0.0f, RotateAngle);
}
