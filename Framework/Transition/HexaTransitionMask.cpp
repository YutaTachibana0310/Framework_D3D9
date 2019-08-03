//=====================================
//
//ヘキサトランジション処理[HexaTransitionMask.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "HexaTransitionMask.h"
#include "../Renderer2D/Polygon2D.h"

/**************************************
マクロ定義
***************************************/
#define HEXATRANSITION_DURATION		(60)

/**************************************
更新処理
***************************************/
MaskResult HexaTransitionMask::Update()
{
	if (!active)
		return Continuous;

	MaskResult result = MaskResult::Continuous;

	cntFrame++;

	//マスク画像のスケールをイージングする
	float t = 1.f * cntFrame / HEXATRANSITION_DURATION;
	polygon->transform.scale = Easing::EaseValue(t, initScale, goalScale, easeType);

	//回転させる
	polygon->transform.Rotate(0.0f, 0.0f, 10.0f);

	//トランジションの終了確認
	if (cntFrame == HEXATRANSITION_DURATION)
	{
		//マスクをオフに
		active = false;
		
		result = isTransitionOut ? FinishTransitionOut : FinishTransitionIn;
	}

	return result;
}

/**************************************
トランジション開始処理
***************************************/
void HexaTransitionMask::Set(bool isTransitionOut)
{
	//すでにマスク中であれば開始しない
	if (active)
		return;

	//イージング用のパラメータ初期化
	initScale = isTransitionOut ? D3DXVECTOR3(0.0f, 0.0f, 0.0f) : D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	goalScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f) - initScale;
	easeType = isTransitionOut ? EaseType::InExpo : EaseType::OutExpo;
	cntFrame = 0;

	//フラグ初期化
	active = true;
	this->isTransitionOut = isTransitionOut;
}

