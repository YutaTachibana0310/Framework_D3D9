//=====================================
//
//�x�[�X�G�t�F�N�g�R���g���[���w�b�_[BaseEffectController.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEEFFECTCONTROLLER_H_
#define _BASEEFFECTCONTROLLER_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class BaseEffectController
{
public:
	virtual void Update() = 0;
	virtual void Draw(LPDIRECT3DTEXTURE9 targetTexture = NULL) = 0;

	virtual void SetDefaultTarget(LPDIRECT3DTEXTURE9 texture);

protected:
	LPDIRECT3DTEXTURE9 defaultTarget;
};

#endif