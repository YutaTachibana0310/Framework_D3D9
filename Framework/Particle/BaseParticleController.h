//=====================================
//
//�x�[�X�p�[�e�B�N���R���g���[���w�b�_[BaseParticleController.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEPARTICLECONTROLLER_H_
#define _BASEPARTICLECONTROLLER_H_

#include "../../main.h"
#include "BaseParticle.h"
#include "BaseEmitter.h"
#include "ParticleJsonParser.h"
#include "ParticleRenderer.h"
#include <vector>

/**************************************
�}�N����`
***************************************/

/**************************************
�O���錾
***************************************/
class ParticleRenderer;
class ParticleUnit;

/**************************************
BasePartlceController�N���X
�p�����
�E�P�ʒ��_�o�b�t�@�쐬�A�e�N�X�`���ǂݍ���
�Evoid MakeParticleContainer(), MakeEmitterContainer()
����������
***************************************/
class BaseParticleController
{
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	BaseParticleController();
	virtual ~BaseParticleController();

	template<class T>
	BaseParticleController(const T& src, const ParticleJsonParser& data)
	{
		if (!mRenderer)
		{
			mRenderer.reset(new ParticleRenderer());
		}
		renderer = mRenderer;

		//�e�N�X�`�����[�h
		LoadTexture(data.GetTexturePath().c_str());

		//�P�ʒ��_�o�b�t�@�쐬
		MakeUnitBuffer(data.GetSize(), data.GetTexDiv());

		//�p�[�e�B�N���R���e�i�쐬
		particleContainer.resize(data.GetParticleMax());
		for (auto&& particle : particleContainer)
		{
			particle = new T();
		}

		//�G�~�b�^�R���e�i�쐬
		MakeEmitterContainer(data);

	};

	//�G�~�b�^�Z�b�g����
	virtual BaseEmitter* SetEmitter(const D3DXVECTOR3& pos);	
	virtual BaseEmitter* SetEmitter(const Transform& transform);

	virtual void Uninit();				//�I������
	void Update();						//�X�V����
	bool Draw();						//�`�揈��

	//�`��J�n�E�I������
	static void BeginDraw();		
	static void EndDraw();			

protected:
	LPDIRECT3DVERTEXBUFFER9 unitBuff;				//�P�ʒ��_�o�b�t�@
	LPDIRECT3DTEXTURE9 texture;						//�e�N�X�`��
	std::vector<BaseParticle*> particleContainer;	//�p�[�e�B�N���R���e�i
	std::vector<BaseEmitter*> emitterContainer;		//�G�~�b�^�R���e�i
	std::shared_ptr<ParticleRenderer> renderer;		//�����_���[

	//�P�ʒ��_�o�b�t�@�쐬����
	void MakeUnitBuffer(const D3DXVECTOR2& size, const D3DXVECTOR2& texDix = D3DXVECTOR2(1.0f, 1.0f));	
	void LoadTexture(const char* filePath);			//�e�N�X�`���ǂݍ��ݏ���

	//�R���e�i�쐬
	virtual void MakeEmitterContainer(const ParticleJsonParser& data);

private:
	//�C���X�^���V���O�ɕK�v�ȐÓI�����o
	static std::shared_ptr<ParticleRenderer> mRenderer;
};

/**************************************
�p�[�e�B�N���̒P�ʒ��_
***************************************/
class ParticleUnit
{
public:
	D3DXVECTOR3 vtx;	//���_���W
	D3DXVECTOR2 tex;	//UV���W
};

#endif