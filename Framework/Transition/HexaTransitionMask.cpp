//=====================================
//
//�w�L�T�g�����W�V��������[HexaTransitionMask.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "HexaTransitionMask.h"
#include "../Renderer2D/Polygon2D.h"

/**************************************
�}�N����`
***************************************/
#define HEXATRANSITION_DURATION		(60)

/**************************************
�X�V����
***************************************/
MaskResult HexaTransitionMask::Update()
{
	if (!active)
		return Continuous;

	MaskResult result = MaskResult::Continuous;

	cntFrame++;

	//�}�X�N�摜�̃X�P�[�����C�[�W���O����
	float t = 1.f * cntFrame / HEXATRANSITION_DURATION;
	polygon->transform.scale = Easing::EaseValue(t, initScale, goalScale, easeType);

	//��]������
	polygon->transform.Rotate(0.0f, 0.0f, 10.0f);

	//�g�����W�V�����̏I���m�F
	if (cntFrame == HEXATRANSITION_DURATION)
	{
		//�}�X�N���I�t��
		active = false;
		
		result = isTransitionOut ? FinishTransitionOut : FinishTransitionIn;
	}

	return result;
}

/**************************************
�g�����W�V�����J�n����
***************************************/
void HexaTransitionMask::Set(bool isTransitionOut)
{
	//���łɃ}�X�N���ł���ΊJ�n���Ȃ�
	if (active)
		return;

	//�C�[�W���O�p�̃p�����[�^������
	initScale = isTransitionOut ? D3DXVECTOR3(0.0f, 0.0f, 0.0f) : D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	goalScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f) - initScale;
	easeType = isTransitionOut ? EaseType::InExpo : EaseType::OutExpo;
	cntFrame = 0;

	//�t���O������
	active = true;
	this->isTransitionOut = isTransitionOut;
}

