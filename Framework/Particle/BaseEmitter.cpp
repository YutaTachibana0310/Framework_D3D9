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
BaseEmitter::BaseEmitter() :
	GameObject(false),
	emitNum(1),
	duration(1)
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum) :
	GameObject(false),
	emitNum(emitNum),
	duration(2)
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int duration) :
	GameObject(false),
	emitNum(emitNum),
	duration(duration)
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int durationMin, int durationMax) :
	GameObject(false),
	emitNum(emitNum),
	duration(Math::RandomRange(durationMin, durationMax))
{

}

/**************************************
�R���X�g���N�^
***************************************/
BaseEmitter::BaseEmitter(int emitNumMin, int emitNumMax, int durationMin, int durationMax) :
	GameObject(false),
	emitNum(Math::RandomRange(emitNumMin, emitNumMax)),
	duration(Math::RandomRange(durationMin, durationMax))
{

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
	if (!active)
		return;

	cntFrame++;

	if (cntFrame > duration)
		active = false;
}

/**************************************
���o����
***************************************/
bool BaseEmitter::Emit(std::vector<BaseParticle*>& container)
{
	if (!active)
		return true;

	UINT cntEmit = 0;
	for (auto& particle : container)
	{
		if (particle->IsActive())
			continue;

		//����������
		particle->SetTransform(*transform);
		particle->Init();

		//�J�E���g
		cntEmit++;

		//���߂�ꐔ�������o���Ă�����I��
		if (cntEmit == emitNum)
			return true;
	}

	return false;
}
