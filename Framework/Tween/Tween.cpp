//=====================================
//
//トゥイーン処理[Tween.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "Tween.h"
#include "../Math/Quaternion.h"
#include <algorithm>

using namespace std;
/**************************************
マクロ定義
***************************************/

/**************************************
コンストラクタ
***************************************/
Tween::Tween()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

/**************************************
デストラクタ
***************************************/
Tween::~Tween()
{
	for (auto&& tweener : tweenerContainer)
	{
		SAFE_DELETE(tweener);
	}
	tweenerContainer.clear();

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

/**************************************
更新処理
***************************************/
void Tween::Update()
{
	for (auto&& tweener : tweenerContainer)
	{
		tweener->Update();
	}

	ClearContainer();
}

/**************************************
コンテナクリア処理
***************************************/
void Tween::ClearContainer()
{
	for (auto&& tweener : tweenerContainer)
	{
		if (!tweener->IsFinished())
			continue;

		SAFE_DELETE(tweener);
	}

	tweenerContainer.remove_if([](auto&& tweener)
	{
		return tweener == NULL;
	});
}

/**************************************
移動処理
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	MoveTweener *tweener = new MoveTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
移動処理
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->pos;
	Move(ref, start, end, duration, type);
}

/**************************************
スケール処理
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	ScaleTweener *tweener = new ScaleTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
スケール処理
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->scale;
	Scale(ref, start, end, duration, type);
}

/**************************************
回転処理
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	RotateTweener *tweener = new RotateTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
回転処理
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->GetEulerAngle();
	Rotate(ref, start, end, duration, type);
}

/**************************************
Tweenerコンストラクタ
***************************************/
Tween::Tweener::Tweener(std::shared_ptr<Transform>& ref, int duration, EaseType type)
{
	this->reference = ref;
	cntFrame = 0;
	this->duration = duration;
	this->type = type;
}

/**************************************
Tweenerデストラクタ
***************************************/
Tween::Tweener::~Tweener()
{
	reference.reset();
}

/**************************************
Tweener終了判定
***************************************/
inline bool Tween::Tweener::IsFinished()
{
	return cntFrame >= duration;
}

/**************************************
MoveTweenerコンストラクタ
***************************************/
Tween::MoveTweener::MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = start;
	this->end = end;
}

/**************************************
MoveTweener更新処理
***************************************/
void Tween::MoveTweener::Update()
{
	cntFrame++;

	float t = (float)cntFrame / duration;
	reference->pos = Easing::EaseValue(t, start, end, type);
}

/**************************************
ScaleTweenerコンストラクタ
***************************************/
Tween::ScaleTweener::ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = start;
	this->end = end;
}

/**************************************
ScaleTweener更新処理
***************************************/
void Tween::ScaleTweener::Update()
{
	cntFrame++;

	float t = (float)cntFrame / duration;
	reference->scale = Easing::EaseValue(t, start, end, type);
}

/**************************************
RotateTweenerコンストラクタ
***************************************/
Tween::RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = Quaternion::ToQuaternion(start);
	this->end = Quaternion::ToQuaternion(end);
}

/**************************************
RotateTweener更新処理
***************************************/
void Tween::RotateTweener::Update()
{
	cntFrame++;

	float t = (float)cntFrame / duration;
	reference->rot = Easing::EaseValue(t, start, end, type);
	D3DXQuaternionNormalize(&reference->rot, &reference->rot);
}