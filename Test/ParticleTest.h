//=====================================
//
//パーティクルテストヘッダ[ParticleTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _PARTICLETEST_H_
#define _PARTICLETEST_H_

#include "../main.h"
#include "TestObject.h"
#include "../Framework\Particle\BaseParticleController.h"
#include "../Framework\Particle\SceneParticleManager.h"
#include "../Framework\Particle\BaseParticle.h"
#include "../Framework\Particle\BaseEmitter.h"
#include "../Framework\Core\BaseScene.h"

/**************************************
マクロ定義
***************************************/
class TestParticleManager;

/**************************************
クラス定義
***************************************/
class ParticleTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	TestParticleManager* manager;

};

class TestParticleManager : public SceneParticleManager
{
public:
	TestParticleManager();
	~TestParticleManager();

	void Init();
	void Set();
	void Draw();
};

class ParticleController : public BaseParticleController
{
public:
	ParticleController();

private:
	void MakeParticleContainer();
	void MakeEmitterContainer();
};

class Particle : public BaseParticle
{
public:
	using BaseParticle::BaseParticle;

	void Init();
	void Update();

private:
	D3DXVECTOR3 moveDir;
	float speed;
};

#endif