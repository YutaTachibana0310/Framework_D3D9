//=====================================
//
//�g�D�C�[������[Tween.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Tween.h"

#include "Tweener/MoveTweener.h"
#include "Tweener/RotateTweener.h"
#include "Tweener/ScaleTweener.h"

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
��������
***************************************/
void Tween::Turn(GameObject & ref, const D3DXVECTOR3 & end, int duration, EaseType type, const D3DXVECTOR3& dummyAxis, std::function<void()> callback)
{
	//�n�_�ƂȂ�N�H�[�^�j�I�������߂�
	D3DXQUATERNION start = ref.transform->GetRotation();

	//�I�_�ƂȂ�N�H�[�^�j�I�������߂�
	D3DXVECTOR3 axis = Vector3::Axis(ref.transform->Forward(), end);
	float angle = Vector3::Angle(ref.transform->Forward(), end);

	//axis���[���x�N�g���i�n�_�̌����ƏI�_�̌��������s�j�̏ꍇ�̓_�~�[�A�N�V�X���g�p
	if (Vector3::Equal(axis, Vector3::Zero))
	{
		axis = dummyAxis;
	}

	D3DXQUATERNION rotQ;
	D3DXQuaternionRotationAxis(&rotQ, &axis, D3DXToRadian(angle));

	D3DXQUATERNION endQuaternion = start * rotQ;

	//��]Tweener�쐬
	RotateTweener *tweener = new RotateTweener(ref.transform, start, endQuaternion, duration, type, callback);
	mInstance->tweenerContainer.push_back(tweener);
}