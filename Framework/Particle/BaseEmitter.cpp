//=====================================
//
//ベースエミッタ処理[BaseEmitter.cpp]
//Author:GP12B332 21 立花雄太
//
//=====================================
#include "BaseEmitter.h"

/**************************************
マクロ定義
***************************************/

/**************************************
構造体定義
***************************************/

/**************************************
グローバル変数
***************************************/

/**************************************
コンストラクタ
***************************************/
BaseEmitter::BaseEmitter()
{
	active = false;
	emitNum = 1;
	duration = 1;
}

/**************************************
コンストラクタ
***************************************/
BaseEmitter::BaseEmitter(int emitNum)
{
	active = false;
	this->emitNum = emitNum;
	duration = 1;
}

/**************************************
コンストラクタ
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int duration)
{
	active = false;
	this->emitNum = emitNum;
	this->duration = duration;
}

/**************************************
コンストラクタ
***************************************/
BaseEmitter::BaseEmitter(int emitNum, int durationMin, int durationMax)
{
	active = false;
	this->emitNum = emitNum;
	this->duration = Math::RandomRange(durationMin, durationMax);
}

/**************************************
コンストラクタ
***************************************/
BaseEmitter::BaseEmitter(int emitNumMin, int emitNumMax, int durationMin, int durationMax)
{
	active = false;
	this->emitNum = Math::RandomRange(emitNumMin, emitNumMax);
	this->duration = Math::RandomRange(durationMin, durationMax);
}

/**************************************
デストラクタ
***************************************/
BaseEmitter::~BaseEmitter()
{

}

/**************************************
初期化処理
***************************************/
void BaseEmitter::Init()
{
	active = true;
	cntFrame = 0;
}

/**************************************
更新処理
***************************************/
void BaseEmitter::Update()
{
	cntFrame++;

	if (cntFrame > duration)
		active = false;
}
