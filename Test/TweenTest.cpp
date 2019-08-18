//=====================================
//
//トゥイーンテスト処理[TweenTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TweenTest.h"
#include "../Framework/Tool/DebugWindow.h"
#include "../Framework/Tween/Tween.h"
/**************************************
マクロ定義
***************************************/

/**************************************
初期化
***************************************/
void TweenTest::Init()
{
	object = new TransformObject();
}

/**************************************
終了
***************************************/
void TweenTest::Uninit()
{
	SAFE_DELETE(object);
}

/**************************************
更新処理
***************************************/
void TweenTest::Update()
{
	Debug::Begin("Ease");

	static int type;
	Debug::RadioButton("Linear", type, EaseType::Linear);
	Debug::RadioButton("InSine", type, EaseType::InSine);
	Debug::RadioButton("OutSine", type, EaseType::OutSine);
	Debug::RadioButton("InOutSine", type, EaseType::InOutSine);
	Debug::RadioButton("InQuad", type, EaseType::InQuad);
	Debug::RadioButton("OutQuad", type, EaseType::OutQuad);
	Debug::RadioButton("InOutQuad", type, EaseType::InOutQuad);
	Debug::RadioButton("InCubic", type, EaseType::InCubic);
	Debug::RadioButton("OutCubic", type, EaseType::OutCubic);
	Debug::RadioButton("InOutCubic", type, EaseType::InOutCubic);
	Debug::RadioButton("InQuart", type, EaseType::InQuart);
	Debug::RadioButton("OutQuart", type, EaseType::OutQuart);
	Debug::RadioButton("InOutQuart", type, EaseType::InOutQuart);
	Debug::RadioButton("InQuint", type, EaseType::InQuint);
	Debug::RadioButton("OutQuint", type, EaseType::OutQuint);
	Debug::RadioButton("InOutQuint", type, EaseType::InOutQuint);
	Debug::RadioButton("InExpo", type, EaseType::InExpo);
	Debug::RadioButton("OutExpo", type, EaseType::OutExpo);
	Debug::RadioButton("InOutExpo", type, EaseType::InOutExpo);
	Debug::RadioButton("InCirc", type, EaseType::InCirc);
	Debug::RadioButton("OutCirc", type, EaseType::OutCirc);
	Debug::RadioButton("InOutCirc", type, EaseType::InOutCirc);
	Debug::RadioButton("InBack", type, EaseType::InBack);
	Debug::RadioButton("OutBack", type, EaseType::OutBack);
	Debug::RadioButton("InOutBack", type, EaseType::InOutBack);

	if (Debug::Button("Start"))
	{
		D3DXVECTOR3 target;
		target.x = Math::RandomRange(-150.0f, 50.0f);
		target.y = Math::RandomRange(-150.0f, 50.0f);
		target.z = Math::RandomRange(0.0f, 100.0f);

		Tween::Move(object->transform, target, 120, (EaseType)type);
	}

	Debug::End();
}

/**************************************
描画
***************************************/
void TweenTest::Draw()
{
	object->Draw();
}