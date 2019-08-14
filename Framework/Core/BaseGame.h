//=====================================
//
//�Q�[���w�b�_[Game.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEGAME_H_
#define _BASEGAME_H_

#include "../../main.h"
#include "SceneManager.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class BaseGame
{
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	BaseGame(HINSTANCE hInstance, HWND hWnd);
	virtual ~BaseGame();

	//�X�V�����A�`�揈��
	virtual void Update();
	virtual void Draw();

protected:
	//�V�[���}�l�[�W��
	SceneManager* sceneManager;

	//�`��̈�
	LPDIRECT3DTEXTURE9 renderTexture;
	LPDIRECT3DSURFACE9 renderSurface;
	LPDIRECT3DVERTEXBUFFER9 screenVtx;

	//�`��̈�쐬����
	virtual void MakeScreen();
	virtual void MakeRenderTarget();
};

#endif