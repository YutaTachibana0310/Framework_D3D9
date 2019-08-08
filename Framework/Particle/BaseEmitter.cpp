//=====================================
//
//�x�[�X�G�~�b�^����[BaseEmitter.cpp]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#include "BaseEmitter.h"
#include "BaseParticle.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�\���̒�`
***************************************/

/**************************************
�O���[�o���ϐ�
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter()
{
	active = false;
	emitNum = 1;
	duration = 1;
}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum)
{
	active = false;
	this->emitNum = emitNum;
	duration = 1;
}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int duration)
{
	active = false;
	this->emitNum = emitNum;
	this->duration = duration;
}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int durationMin, int durationMax)
{
	active = false;
	this->emitNum = emitNum;
	this->duration = Math::RandomRange(durationMin, durationMax);
}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNumMin, int emitNumMax, int durationMin, int durationMax)
{
	active = false;
	this->emitNum = Math::RandomRange(emitNumMin, emitNumMax);
	this->duration = Math::RandomRange(durationMin, durationMax);
}

/**************************************
�f�X�g���N�^
***************************************/
BaseEmitter::~BaseEmitter()
{

}

/**************************************
����������
***************************************/
void BaseEmitter::Init()
{
	active = true;
	cntFrame = 0;
}

/**************************************
�X�V����
***************************************/
void BaseEmitter::Update()
{
	cntFrame++;

	if (cntFrame > duration)
		active = false;
}

/**************************************
���o����
***************************************/
bool BaseEmitter::Emit(std::vector<BaseParticle*>& container)
{
	UINT cntEmit = 0;
	for (auto& particle : container)
	{
		if (particle->active)
			continue;

		//����������
		particle->transform = this->transform;
		particle->Init();

		//�J�E���g
		cntEmit++;

		//���߂�ꐔ�������o���Ă�����I��
		if (cntEmit == emitNum)
			return true;
	}

	return false;
}
