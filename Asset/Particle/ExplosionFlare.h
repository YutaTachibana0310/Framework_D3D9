//=====================================
//
//エクスプロージョンフレアヘッダ[ExplosionFlare.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _EXPLOSIONFLARE_H_
#define _EXPLOSIONFLARE_H_

#include "../../Framework/Particle/BaseParticle.h"

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
	class ExplosionFlare : public BaseParticle
	{
		using BaseParticle::BaseParticle;
	public:
		ExplosionFlare();

		void Init();
		void Update();

	private:
		D3DXVECTOR3 moveDir;
		float speed;

		static const float SpeedMax;
		static const float SpeedMin;
		static const int LifeMax;
		static const int LifeMin;
		static const int TexDivX;
		static const int TexDivY;
		static const float RotateMax;
		static const float ScaleMax;
		static const float ScaleMin;
		static const float RotateAngle;
	};
}

#endif