//=====================================
//
//�|�X�g�G�t�F�N�g�}�l�[�W���w�b�_[PostEffectManager.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _POSTEFFECTMANAGER_H_
#define _POSTEFFECTMANAGER_H_

#include "../../main.h"
#include "BaseEffectController.h"
#include "../Pattern/BaseSingleton.h"

#include <vector>

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class PostEffectManager : public BaseSingleton<PostEffectManager>
{
	friend class BaseSingleton<PostEffectManager>;
public:
	void Update();
	void Draw();

	void SetUse(unsigned flgUse);
	void PassDefaultTarget(LPDIRECT3DTEXTURE9 target);

	enum PostEffect
	{
		Bloom,
		CrossFilter,
		ShockBlur,
		SpeedBlur,
		SpikeNoiset,
		Max,
	};

private:
	unsigned flgUse;
	std::vector<BaseEffectController*> effectContainer;

	bool IsUse(unsigned flg);

	PostEffectManager();
	PostEffectManager(const PostEffectManager&){}
	~PostEffectManager() {}
};

#endif