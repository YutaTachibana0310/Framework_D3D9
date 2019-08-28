//=====================================
//
//パーティクルテスト処理[ParticleTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "ParticleTest.h"
#include "../Framework\Tool\DebugWindow.h"
#include "../Framework\Tool\ProfilerCPU.h"
#include "../Framework\PostEffect\PostEffectManager.h"
#include "../Framework\PostEffect\SpikeNoiseController.h"
#include "../Asset/Particle/ExplosionFire.h"
#include "../Asset/Particle/ExplosionFlare.h"

/**************************************
マクロ定義
***************************************/
void ParticleTest::Init()
{
	manager = new TestParticleManager();
	manager->Init();
}

/**************************************
マクロ定義
***************************************/
void ParticleTest::Uninit()
{
	SAFE_DELETE(manager);
}

/**************************************
マクロ定義
***************************************/
void ParticleTest::Update()
{
	Debug::Begin("ParticleTest");

	if (Debug::Button("ParticleTest"))
	{
		manager->Generate(1, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		manager->Generate(2, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	Debug::End();

	static int cntFrame = 0;
	if (cntFrame == 0)
	{
		manager->Generate(1, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		manager->Generate(2, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	cntFrame = Math::WrapAround(0, 20, cntFrame + 1);

	manager->Update();
}

/**************************************
マクロ定義
***************************************/
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
	controllers.push_back(new BaseParticleController(Particle(), ParticleJsonParser("test2")));
	controllers.push_back(new BaseParticleController(Asset::ExplosionFire(), ParticleJsonParser("ExplosionEffect")));
	controllers.push_back(new BaseParticleController(Asset::ExplosionFlare(), ParticleJsonParser("ExplosionFlare")));
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

/**************************************
プロトタイプ宣言
***************************************/
void TestParticleManager::Set()
{
	controllers[0]->SetEmitter(Vector3::Zero);
}

/**************************************
プロトタイプ宣言
***************************************/
void TestParticleManager::Update()
{
	Debug::Begin("Particle");
	for (UINT i = 0; i < controllers.size(); i++)
	{
		std::string label = "Set" + std::to_string(i);
		if (Debug::Button(label.c_str()))
		{
			controllers[i]->SetEmitter(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		}
	}
	Debug::End();

	SceneParticleManager::Update();
}

/**************************************
プロトタイプ宣言
***************************************/
Particle::Particle() :
	BaseParticle(60, 120)
{

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
	if (!IsActive())
		return;

	cntFrame++;

	transform->Move(moveDir * speed);
}