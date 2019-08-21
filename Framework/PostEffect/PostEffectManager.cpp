//=====================================
//
//�|�X�g�G�t�F�N�g�}�l�[�W������[PostEffectManager.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "PostEffectManager.h"

#include "BloomController.h"
#include "CrossFilterController.h"
#include "ShockBlurController.h"
#include "SpeedBlurController.h"
#include "SpikeNoiseController.h"

using namespace std;
/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
PostEffectManager::PostEffectManager()
{
	effectContainer.push_back(BloomController::Instance());
	effectContainer.push_back(CrossFilterController::Instance());
	effectContainer.push_back(ShockBlurController::Instance());
	effectContainer.push_back(SpeedBlurController::Instance());
	effectContainer.push_back(SpikeNoiseController::Instance());
}

/**************************************
�X�V����
***************************************/
void PostEffectManager::Update()
{
	for (auto&& effect : effectContainer)
	{
		effect->Update();
	}
}
/**************************************
�`�揈��
***************************************/
void PostEffectManager::Draw()
{
	for (unsigned i = PostEffect::Bloom; i < PostEffect::Max; i++)
	{
		if (!IsUse(i))
			continue;

		//�u���[���Ȃǂ̋P���n�͉e������������̂�
		//�e�V�[���ɕ`���C����
		if (IsBrightEffect(i))
			continue;

		effectContainer[i]->Draw();
	}
}

/**************************************
�g�p�G�t�F�N�g�ݒ菈��
***************************************/
void PostEffectManager::SetUse(unsigned flgUse)
{
	this->flgUse = flgUse;
}

/**************************************
�g�p�G�t�F�N�g���菈��
***************************************/
bool PostEffectManager::IsUse(unsigned flg)
{
	unsigned check = 0x01;
	check = check << (flg);

	return check & flgUse;
}

/**************************************
�f�t�H���g�^�[�Q�b�g�ݒ菈��
***************************************/
bool PostEffectManager::IsBrightEffect(UINT id)
{
	return id == PostEffect::CrossFilter || id == PostEffect::Bloom;
}

/**************************************
�f�t�H���g�^�[�Q�b�g�ݒ菈��
***************************************/
void PostEffectManager::PassDefaultTarget(LPDIRECT3DTEXTURE9 target)
{
	for (auto& effect : effectContainer)
	{
		effect->SetDefaultTarget(target);
	}
}