#pragma once
//=====================================
//
//�G�N�X�v���[�W�����t�@�C�A�w�b�_[ExplosionFire.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _EXPLOSIONFIRE_H_
#define _EXPLOSIONFIRE_H_

#include "../../Framework/Particle/AnimationParticle.h"

/**************************************
�O���錾
***************************************/

/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
***************************************/
namespace Asset
{
	class ExplosionFire : public AnimationParticle
	{
		using AnimationParticle::AnimationParticle;
	public:
		ExplosionFire();		//�R���X�g���N�^

		void Init();			//����������
		void Update();			//�X�V����

	private:
		D3DXVECTOR3 velocity;	//�ړ�����

		//�萔
		static const float SpeedMax, SpeedMin;
		static const int LifeMax, LifeMin;
		static const float TexDiv;
		static const float RotateMax;
		static const float ScaleMax, ScaleMin;
	};
}

#endif