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

	virtual BaseEmitter* SetEmitter(const D3DXVECTOR3& pos);	//�G�~�b�^�Z�b�g����
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

	//�P�ʒ��_�o�b�t�@�쐬����
	void MakeUnitBuffer(const D3DXVECTOR2& size, const D3DXVECTOR2& texDix = D3DXVECTOR2(1.0f, 1.0f));	
	void LoadTexture(const char* filePath);			//�e�N�X�`���ǂݍ��ݏ���

	//�R���e�i�쐬
	virtual void MakeParticleContainer() = 0;
	virtual void MakeEmitterContainer() = 0;

private:
	//�C���X�^���V���O�ɕK�v�ȐÓI�����o
	static ParticleRenderer* renderer;
	static UINT instanceCount;
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