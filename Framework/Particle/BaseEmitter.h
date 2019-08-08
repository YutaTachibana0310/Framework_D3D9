//=====================================
//
//ベースエミッタヘッダ[BaseEmitter.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASEEMITTER_H_
#define _BASEEMITTER_H_

#include "../../main.h"
#include <vector>
#include <memory>

/**************************************
前方宣言
***************************************/
class BaseParticle;

/**************************************
BaseEmitterクラス
※継承先でInit(), Update()を実装する
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