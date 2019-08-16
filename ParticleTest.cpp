//=====================================
//
//�p�[�e�B�N���e�X�g����[ParticleTest.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "ParticleTest.h"
#include "Framework\Tool\DebugWindow.h"
#include "Framework\Tool\ProfilerCPU.h"
#include "Framework\PostEffect\PostEffectManager.h"
#include "Framework\PostEffect\SpikeNoiseController.h"

/**************************************
�}�N����`
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
�N���X��`
***************************************/
TestParticleManager::TestParticleManager()
{
	controllers.push_back(new ParticleController());
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

void TestParticleManager::Set()
{
	controllers[0]->SetEmitter(Vector3::Zero);
}
/**************************************
�v���g�^�C�v�錾
***************************************/
ParticleController::ParticleController()
{
	MakeUnitBuffer(D3DXVECTOR2(5.0f, 5.0f));
	LoadTexture("data/TEXTURE/particle.png");

	MakeParticleContainer();
	MakeEmitterContainer();
}

/**************************************
�v���g�^�C�v�錾
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
�v���g�^�C�v�錾
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
	cntFrame++;

	transform.pos += moveDir * speed;

	if (cntFrame == lifeFrame)
		active = false;
}