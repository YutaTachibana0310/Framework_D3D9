//=====================================
//
//�G�N�X�v���[�W�����t�@�C�A����[ExplosionFire.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "ExplosionFire.h"
#include "../../Framework/Math/Easing.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/

/**************************************
�O���[�o���ϐ�
***************************************/
const float Asset::ExplosionFire::SpeedMax = 1.2f;		//�X�s�[�h�ő�l
const float Asset::ExplosionFire::SpeedMin = 0.5f;		//�X�s�[�h�ŏ��l
const int Asset::ExplosionFire::LifeMax = 30;			//�����ő�l
const int Asset::ExplosionFire::LifeMin = 10;			//�����ŏ��l
const float Asset::ExplosionFire::TexDiv = 8.0f;		//�e�N�X�`����UV������
const float Asset::ExplosionFire::RotateMax = 360.0f;	//�ő��]��
const float Asset::ExplosionFire::ScaleMin = 0.8f;		//�ő�X�P�[���l
const float Asset::ExplosionFire::ScaleMax = 1.2f;		//�ŏ��X�P�[���l

/**************************************
�R���X�g���N�^
***************************************/
Asset::ExplosionFire::ExplosionFire() :
	AnimationParticle(TexDiv, TexDiv, LifeMin, LifeMax),
	velocity(Vector3::Random() * Math::RandomRange(SpeedMin, SpeedMax))
{

}

/**************************************
����������
***************************************/
void Asset::ExplosionFire::Init()
{
	//�J�E���g�ƃt���O��������
	cntFrame = 0;
	active = true;

	//�����_����Z���ŉ�]
	transform->Rotate(0.0f, 0.0f, Math::RandomRange(0.0f, RotateMax));

	//�����_���ɂɃX�P�[�����O
	transform->SetScale(Vector3::One * Math::RandomRange(ScaleMin, ScaleMax));
}

/**************************************
�X�V����
***************************************/
void Asset::ExplosionFire::Update()
{
	if (!IsActive())
		return;

	cntFrame++;
	
	//�ǂ̂��炢�������������
	float t = 1.0f * cntFrame / lifeFrame;
	
	//�A�j���[�V����
	Animation(t);

	//�ړ�
	transform->Move(velocity);
}
