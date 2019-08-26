//=====================================
//
//エクスプロージョンファイア処理[ExplosionFire.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ExplosionFire.h"
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
const float Asset::ExplosionFire::SpeedMax = 1.2f;		//スピード最大値
const float Asset::ExplosionFire::SpeedMin = 0.5f;		//スピード最小値
const int Asset::ExplosionFire::LifeMax = 30;			//寿命最大値
const int Asset::ExplosionFire::LifeMin = 10;			//寿命最小値
const float Asset::ExplosionFire::TexDiv = 8.0f;		//テクスチャのUV分割数
const float Asset::ExplosionFire::RotateMax = 360.0f;	//最大回転量
const float Asset::ExplosionFire::ScaleMin = 0.8f;		//最大スケール値
const float Asset::ExplosionFire::ScaleMax = 1.2f;		//最小スケール値

/**************************************
コンストラクタ
***************************************/
Asset::ExplosionFire::ExplosionFire() :
	AnimationParticle(TexDiv, TexDiv, LifeMin, LifeMax),
	velocity(Vector3::Random() * Math::RandomRange(SpeedMin, SpeedMax))
{

}

/**************************************
初期化処理
***************************************/
void Asset::ExplosionFire::Init()
{
	//カウントとフラグを初期化
	cntFrame = 0;
	active = true;

	//ランダムにZ軸で回転
	transform->Rotate(0.0f, 0.0f, Math::RandomRange(0.0f, RotateMax));

	//ランダムににスケーリング
	transform->SetScale(Vector3::One * Math::RandomRange(ScaleMin, ScaleMax));
}

/**************************************
更新処理
***************************************/
void Asset::ExplosionFire::Update()
{
	if (!IsActive())
		return;

	cntFrame++;
	
	//どのくらい寿命を消費したか
	float t = 1.0f * cntFrame / lifeFrame;
	
	//アニメーション
	Animation(t);

	//移動
	transform->Move(velocity);
}
