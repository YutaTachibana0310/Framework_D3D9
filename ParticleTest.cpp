//=====================================
//
//パーティクルテスト処理[ParticleTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ParticleTest.h"
#include "Framework\Tool\DebugWindow.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
TestParticle::TestParticle()
{
	controllers.push_back(new ParticleController());
}

/**************************************
グローバル変数
***************************************/
TestParticle::~TestParticle()
{
	SceneParticleManager::Uninit();
}

/**************************************
プロトタイプ宣言
***************************************/
void TestParticle::Init()
{
	SceneParticleManager::Init();
}

/**************************************
プロトタイプ宣言
***************************************/
void TestParticle::Update()
{
	BeginDebugWindow("Particle");

	if (DebugButton("Set"))
		controllers[0]->SetEmitter(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	EndDebugWindow("Particle");

	SceneParticleManager::Update();
}

/**************************************
プロトタイプ宣言
***************************************/
void TestParticle::Draw()
{
	SceneParticleManager::Draw();
}

/**************************************
プロトタイプ宣言
***************************************/
ParticleController::ParticleController()
{
	MakeUnitBuffer(D3DXVECTOR2(5.0f, 5.0f));
	LoadTexture("data/TEXTURE/particle.png");

	MakeParticleContainer();
	MakeEmitterContainer();
}

/**************************************
プロトタイプ宣言
***************************************/
void ParticleController::MakeParticleContainer()
{
	particleContainer.resize(1024);
	for (auto& particle : particleContainer)
	{
		particle = new Particle(60, 120);
	}
}

/**************************************
プロトタイプ宣言
***************************************/
void ParticleController::MakeEmitterContainer()
{
	emitterContainer.resize(5);
	for (auto& emitter : emitterContainer)
	{
		emitter = new BaseEmitter(20, 100, 10, 60);
	}
}

/**************************************
プロトタイプ宣言
***************************************/
void Particle::Init()
{
	moveDir.x = Math::RandomRange(-1.0f, 1.0f);
	moveDir.y = Math::RandomRange(-1.0f, 1.0f);
	moveDir.z = Math::RandomRange(-1.0f, 1.0f);
	D3DXVec3Normalize(&moveDir, &moveDir);

	speed = Math::RandomRange(0.5f, 2.0f);

	cntFrame = 0;
	active = true;
}

/**************************************
プロトタイプ宣言
***************************************/
void Particle::Update()
{
	cntFrame++;

	transform.pos += moveDir * speed;

	if (cntFrame == lifeFrame)
		active = false;
}