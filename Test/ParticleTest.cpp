//=====================================
//
//�p�[�e�B�N���e�X�g����[ParticleTest.cpp]
//Author:GP12A332 21 ���ԗY��
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
�}�N����`
***************************************/
void ParticleTest::Init()
{
	manager = new TestParticleManager();
	manager->Init();
}

/**************************************
�}�N����`
***************************************/
void ParticleTest::Uninit()
{
	SAFE_DELETE(manager);
}

/**************************************
�}�N����`
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
�}�N����`
***************************************/
void ParticleTest::Draw()
{
	manager->Draw();
	PostEffectManager::Instance()->Draw();
}

/**************************************
�N���X��`
***************************************/
TestParticleManager::TestParticleManager()
{
	controllers.push_back(new BaseParticleController(Particle(), ParticleJsonParser("test2")));
	controllers.push_back(new BaseParticleController(Asset::ExplosionFire(), ParticleJsonParser("ExplosionEffect")));
	controllers.push_back(new BaseParticleController(Asset::ExplosionFlare(), ParticleJsonParser("ExplosionFlare")));
}

/**************************************
�O���[�o���ϐ�
***************************************/
TestParticleManager::~TestParticleManager()
{
	SceneParticleManager::Uninit();
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void TestParticleManager::Init()
{
	SceneParticleManager::Init();
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void TestParticleManager::Set()
{
	controllers[0]->SetEmitter(Vector3::Zero);
}

/**************************************
�v���g�^�C�v�錾
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
�v���g�^�C�v�錾
***************************************/
Particle::Particle() :
	BaseParticle(60, 120)
{

}

/**************************************
�v���g�^�C�v�錾
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
�v���g�^�C�v�錾
***************************************/
void Particle::Update()
{
	if (!IsActive())
		return;

	cntFrame++;

	transform->Move(moveDir * speed);
}