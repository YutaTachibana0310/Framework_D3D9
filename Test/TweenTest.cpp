//=====================================
//
//�g�D�C�[���e�X�g����[TweenTest.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "TweenTest.h"
#include "../Framework/Tool/DebugWindow.h"
#include "../Framework/Tween/Tween.h"
/**************************************
�}�N����`
***************************************/

/**************************************
������
***************************************/
void TweenTest::Init()
{
	if (object == NULL)
		object = new TransformObject();
}

/**************************************
�I��
***************************************/
void TweenTest::Uninit()
{
	SAFE_DELETE(object);
}

/**************************************
�X�V����
***************************************/
void TweenTest::Update()
{
	Debug::Begin("Tween");

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


	static D3DXVECTOR3 targetPos;
	static D3DXVECTOR3 targetScale;
	static D3DXVECTOR3 targetRot;

	if (Debug::Button("position"))
	{
		targetPos.x = Math::RandomRange(-150.0f, 50.0f);
		targetPos.y = Math::RandomRange(-150.0f, 50.0f);
		targetPos.z = Math::RandomRange(0.0f, 100.0f);

		if (object != NULL)
			Tween::Move(object->transform, targetPos, 30, (EaseType)type);
	}

	if (Debug::Button("scale"))
	{
		targetScale = Vector3::One * Math::RandomRange(0.5f, 5.0f);

		if (object != NULL)
			Tween::Scale(object->transform, targetScale, 30, (EaseType)type);
	}

	if (Debug::Button("rotate"))
	{
		targetRot.x = Math::RandomRange(0.0f, 360.0f);
		targetRot.y = Math::RandomRange(0.0f, 360.0f);
		targetRot.z = Math::RandomRange(0.0f, 360.0f);

		if (object != NULL)
			Tween::Rotate(object->transform, targetRot, 30, (EaseType)type);
	}

	if (Debug::Button("delete"))
		SAFE_DELETE(object);

	if (Debug::Button("Create") && object == NULL)
		object = new TransformObject();

	Debug::Text(targetPos, "TargetPos");
	Debug::Text(targetRot, "TargetRot");
	Debug::Text(targetScale, "TargetScale");
	Debug::Text(object->transform->pos, "position");
	Debug::Text(object->transform->GetEulerAngle(), "rotation");
	Debug::Text(object->transform->scale, "scale");

	Debug::End();
}

/**************************************
�`��
***************************************/
void TweenTest::Draw()
{
	if (object != NULL)
		object->Draw();
}