//=====================================
//
//ベースパーティクルヘッダ[BaseParticle.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASEPARTICLE_H_
#define _BASEPARTICLE_H_

#include "../../main.h"

/**************************************
マクロ定義
***************************************/

/**************************************
BaseParticleクラス
※継承先でInit(), Update()を実装する
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