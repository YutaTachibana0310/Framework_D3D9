//=====================================
//
//�g�D�C�[������[Tween.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Tween.h"
#include "../Math/Quaternion.h"
#include <algorithm>

using namespace std;
/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
Tween::Tween()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

/**************************************
�f�X�g���N�^
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
�X�V����
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
�R���e�i�N���A����
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
�ړ�����
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	MoveTweener *tweener = new MoveTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
�ړ�����
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->pos;
	Move(ref, start, end, duration, type);
}

/**************************************
�X�P�[������
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	ScaleTweener *tweener = new ScaleTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
�X�P�[������
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->scale;
	Scale(ref, start, end, duration, type);
}

/**************************************
��]����
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
{
	RotateTweener *tweener = new RotateTweener(ref.transform, start, end, duration, type);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
��]����
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type)
{
	D3DXVECTOR3 start = ref.transform->GetEulerAngle();
	Rotate(ref, start, end, duration, type);
}

/**************************************
Tweener�R���X�g���N�^
***************************************/
Tween::Tweener::Tweener(std::shared_ptr<Transform>& ref, int duration, EaseType type)
{
	this->reference = ref;
	cntFrame = 0;
	this->duration = duration;
	this->type = type;
}

/**************************************
Tweener�f�X�g���N�^
***************************************/
Tween::Tweener::~Tweener()
{
	reference.reset();
}

/**************************************
Tweener�I������
***************************************/
inline bool Tween::Tweener::IsFinished()
{
	if (!reference.lock())
		return true;

	return cntFrame >= duration;
}

/**************************************
MoveTweener�R���X�g���N�^
***************************************/
Tween::MoveTweener::MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = start;
	this->end = end;
}

/**************************************
MoveTweener�X�V����
***************************************/
void Tween::MoveTweener::Update()
{
	cntFrame++;

	shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float t = (float)cntFrame / duration;
		transform->pos = Easing::EaseValue(t, start, end, type);
	}
}

/**************************************
ScaleTweener�R���X�g���N�^
***************************************/
Tween::ScaleTweener::ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = start;
	this->end = end;
}

/**************************************
ScaleTweener�X�V����
***************************************/
void Tween::ScaleTweener::Update()
{
	cntFrame++;

	shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float t = (float)cntFrame / duration;
		transform->scale = Easing::EaseValue(t, start, end, type);
	}
}

/**************************************
RotateTweener�R���X�g���N�^
***************************************/
Tween::RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type)
	: Tweener(ref, duration, type)
{
	this->start = Quaternion::ToQuaternion(start);
	this->end = Quaternion::ToQuaternion(end);
}

/**************************************
RotateTweener�X�V����
***************************************/
void Tween::RotateTweener::Update()
{
	cntFrame++;

	shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float t = (float)cntFrame / duration;
		transform->rot = Easing::EaseValue(t, start, end, type);
		D3DXQuaternionNormalize(&transform->rot, &transform->rot);
	}
}