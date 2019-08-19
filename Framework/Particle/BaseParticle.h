//=====================================
//
//�x�[�X�p�[�e�B�N���w�b�_[BaseParticle.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEPARTICLE_H_
#define _BASEPARTICLE_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
BaseParticle�N���X
���p�����Init(), Update()����������
***************************************/
class BaseParticle : public GameObject
{
public:
	BaseParticle();
	BaseParticle(int life);
	BaseParticle(int lifeMin, int lifeMax);
	virtual ~BaseParticle();

	virtual void Init() = 0;
	virtual void Update() = 0;

	ParticleUV uv;

protected:
	int cntFrame;
	int lifeFrame;

};

#endif