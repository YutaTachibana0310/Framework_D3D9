//=====================================
//
//�p�[�e�B�N���e�X�g����[ParticleTest.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "ParticleTest.h"
#include "Framework\Tool\DebugWindow.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
TestParticle::TestParticle()
{
	controllers.push_back(new ParticleController());
}

/**************************************
�O���[�o���ϐ�
***************************************/
TestParticle::~TestParticle()
{
	SceneParticleManager::Uninit();
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void TestParticle::Init()
{
	SceneParticleManager::Init();
}

/**************************************
�v���g�^�C�v�錾
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
�v���g�^�C�v�錾
***************************************/
void TestParticle::Draw()
{
	SceneParticleManager::Draw();
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