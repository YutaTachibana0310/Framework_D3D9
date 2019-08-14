//=====================================
//
//�Q�[���w�b�_[Game.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASEGAME_H_
#define _BASEGAME_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class BaseGame
{
public:
	BaseGame(HINSTANCE hInstance, HWND hWnd);
	virtual ~BaseGame();

	virtual void Update();
	virtual void Draw();

protected:
	LPDIRECT3DTEXTURE9 renderTexture;
	LPDIRECT3DSURFACE9 renderSurface;
	LPDIRECT3DVERTEXBUFFER9 screenVtx;

	virtual void MakeScreen();
	virtual void MakeRenderTarget();
};

#endif