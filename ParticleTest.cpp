//=====================================
//
//パーティクルテスト処理[ParticleTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ParticleTest.h"
#include "Framework\Tool\DebugWindow.h"
#include "Framework\Tool\ProfilerCPU.h"
#include "Framework\PostEffect\PostEffectManager.h"
#include "Framework\PostEffect\SpikeNoiseController.h"

/**************************************
マクロ定義
***************************************/
void ParticleTest::Init()
{
	manager = new TestParticleManager();
	manager->Init();
}

void ParticleTest::Uninit()
{
	SAFE_DELETE(manager);
}

void ParticleTest::Update()
{
	Debug::Begin("Particle");
	if (Debug::Button("Set"))
	{
		manager->Set();
	}
	if (Debug::Button("SpileNoise"))
	{
		SpikeNoiseController::Instance()->SetNoise(20.0f, 120);
	}
	Debug::End();

	manager->Update();
}

void ParticleTest::Draw()
{
	manager->Draw();
	PostEffectManager::Instance()->Draw();
}

/**************************************
クラス定義
***************************************/
TestParticleManager::TestParticleManager()
{
	controllers.push_back(new ParticleController());
}

/**************************************
グローバル変数
***************************************/
TestParticleManager::~TestParticleManager()
{
	SceneParticleManager::Uninit();
}

/**************************************
プロトタイプ宣言
***************************************/
void TestParticleManager::Init()
{
	SceneParticleManager::Init();
}

void TestParticleManager::Set()
{
	controllers[0]->SetEmitter(Vector3::Zero);
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