//=====================================
//
//�x�[�X�G�~�b�^����[BaseEmitter.cpp]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#include "BaseEmitter.h"

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
