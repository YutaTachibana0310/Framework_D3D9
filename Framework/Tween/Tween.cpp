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
�N���A����
***************************************/
void Tween::ClearAll()
{
	for (auto&& tweener : tweenerContainer)
	{
		SAFE_DELETE(tweener);
	}

	tweenerContainer.clear();
}

/**************************************
�ړ�����
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	MoveTweener *tweener = new MoveTweener(ref.transform, start, end, duration, type, callback);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
�ړ�����
***************************************/
void Tween::Move(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	D3DXVECTOR3 start = ref.transform->GetPosition();
	Move(ref, start, end, duration, type, callback);
}

/**************************************
�X�P�[������
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	ScaleTweener *tweener = new ScaleTweener(ref.transform, start, end, duration, type, callback);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
�X�P�[������
***************************************/
void Tween::Scale(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	D3DXVECTOR3 start = ref.transform->GetScale();
	Scale(ref, start, end, duration, type, callback);
}

/**************************************
��]����
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	RotateTweener *tweener = new RotateTweener(ref.transform, start, end, duration, type, callback);
	mInstance->tweenerContainer.push_back(tweener);
}

/**************************************
��]����
***************************************/
void Tween::Rotate(GameObject& ref, const D3DXVECTOR3& end, int duration, EaseType type, std::function<void(void)> callback)
{
	D3DXVECTOR3 start = ref.transform->GetEulerAngle();
	Rotate(ref, start, end, duration, type, callback);
}

/**************************************
Tweener�R���X�g���N�^
***************************************/
Tween::Tweener::Tweener(std::shared_ptr<Transform>& ref, int duration, EaseType type, Callback callback) :
	reference(ref),
	cntFrame(0),
	duration(duration),
	type(type),
	callback(callback)
{

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
	if (reference.expired())
		return true;

	return cntFrame >= duration;
}

/**************************************
�R�[���o�b�N�̃`�F�b�N����
***************************************/
inline void Tween::Tweener::CheckCallback()
{
	if (cntFrame < duration)
		return;

	if (callback == nullptr)
		return;

	callback();
}

/**************************************
MoveTweener�R���X�g���N�^
***************************************/
Tween::MoveTweener::MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Callback callback) :
	Tweener(ref, duration, type, callback),
	start(start),
	end(end)
{

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
		transform->SetPosition(Easing::EaseValue(t, start, end, type));
		CheckCallback();
	}
}

/**************************************
ScaleTweener�R���X�g���N�^
***************************************/
Tween::ScaleTweener::ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Callback callback) :
	Tweener(ref, duration, type, callback),
	start(start),
	end(end)
{

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
		transform->SetScale(Easing::EaseValue(t, start, end, type));
		CheckCallback();
	}
}

/**************************************
RotateTweener�R���X�g���N�^
***************************************/
Tween::RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Callback callback) :
	Tweener(ref, duration, type, callback),
	start(Quaternion::ToQuaternion(start)),
	end(Quaternion::ToQuaternion(end))
{

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
		float t = Easing::EaseValue((float)cntFrame / duration, 0.0f, 1.0f, type);
		D3DXQUATERNION quaternion;
		D3DXQuaternionSlerp(&quaternion, &start, &end, t);
		transform->SetRotation(quaternion);
		CheckCallback();
	}
}