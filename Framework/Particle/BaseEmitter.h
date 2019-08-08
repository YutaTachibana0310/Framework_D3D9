//=====================================
//
//�x�[�X�G�~�b�^�w�b�_[BaseEmitter.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEEMITTER_H_
#define _BASEEMITTER_H_

#include "../../main.h"
#include <vector>
#include <memory>

/**************************************
�O���錾
***************************************/
class BaseParticle;

/**************************************
BaseEmitter�N���X
���p�����Init(), Update()����������
***************************************/
class BaseEmitter
{
public:
	BaseEmitter();
	BaseEmitter(int emitNum);
	BaseEmitter(int emitNum, int duration);
	BaseEmitter(int emitNum, int durationMin, int durationMax);
	BaseEmitter(int emitNumMin, int emitNumMax, int durationMin, int durationMax);

	virtual ~BaseEmitter();

	virtual void Init();
	virtual void Update();
	
	bool active;
	Transform transform;

protected:
	int cntFrame;
	int duration;
	int emitNum;
};

#endif