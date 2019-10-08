//=====================================
//
//イージングテスト処理[EasingTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "EasingTest.h"
#include "../Framework\Tool\DebugWindow.h"
#include "../Framework\Tool\ProfilerCPU.h"

/**************************************
マクロ定義
***************************************/
#define EASING_DURATION		(60)

/**************************************
コンストラクタ
***************************************/
void EasingTest::Init()
{
	polygon = new Polygon2D();
	polygon->LoadTexture("data/TEXTURE/pointer.png");
	polygon->SetSize(50.0f, 50.0f);

	gauge = new CircleGauge(D3DXVECTOR2(200.0f, 200.0f));
	gauge->SetPosition(D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f));
	gauge->LoadTexture("data/TEXTURE/circle.png");

	cntFrame = 0;
}

/**************************************
デストラクタ
***************************************/
void EasingTest::Uninit()
{
	SAFE_DELETE(polygon);
}

/**************************************
更新処理
***************************************/
void EasingTest::Update()
{
	ProfilerCPU::Instance()->BeginLabel("Easing");

	ProfilerCPU::Instance()->Begin("Update");
	Debug::Begin("Ease");
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

	const int buffer = 30;
	cntFrame = Math::WrapAround(0, EASING_DURATION  + buffer * 2,  ++cntFrame);

	const float Start = 300.0f;
	const float End = SCREEN_WIDTH - Start;

	float t = (float)(cntFrame - buffer) / EASING_DURATION;
	float posX = Easing::EaseValue(t, Start, End, (EaseType)type);
	polygon->SetPosition(D3DXVECTOR3(posX, SCREEN_CENTER_Y, 0.0f));

	Debug::Text("t : %f", t);

	Debug::Text("%f", Math::RandomRange(0.0f, 100.0f));

	Debug::End();

	ProfilerCPU::Instance()->End("Update");
	ProfilerCPU::Instance()->EndLabel();
}


/**************************************
描画処理
***************************************/
void EasingTest::Draw()
{
	polygon->Draw();

	gauge->Draw();
}