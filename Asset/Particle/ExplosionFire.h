#pragma once
//=====================================
//
//エクスプロージョンファイアヘッダ[ExplosionFire.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _EXPLOSIONFIRE_H_
#define _EXPLOSIONFIRE_H_

#include "../../Framework/Particle/AnimationParticle.h"

/**************************************
前方宣言
***************************************/

/**************************************
マクロ・列挙子定義
***************************************/

/**************************************
クラス定義
***************************************/
namespace Asset
{
	class ExplosionFire : public AnimationParticle
	{
		using AnimationParticle::AnimationParticle;
	public:
		ExplosionFire();		//コンストラクタ

		void Init();			//初期化処理
		void Update();			//更新処理

	private:
		D3DXVECTOR3 velocity;	//移動方向

		//定数
		static const float SpeedMax, SpeedMin;
		static const int LifeMax, LifeMin;
		static const float TexDiv;
		static const float RotateMax;
		static const float ScaleMax, ScaleMin;
	};
}

#endif