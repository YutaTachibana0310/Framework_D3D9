//=====================================
//
//ゲームヘッダ[Game.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASEGAME_H_
#define _BASEGAME_H_

#include "../../main.h"
#include "SceneManager.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class BaseGame
{
public:
	//コンストラクタ、デストラクタ
	BaseGame(HINSTANCE hInstance, HWND hWnd);
	virtual ~BaseGame();

	//更新処理、描画処理
	virtual void Update();
	virtual void Draw();

protected:
	//シーンマネージャ
	SceneManager* sceneManager;

	//描画領域
	LPDIRECT3DTEXTURE9 renderTexture;
	LPDIRECT3DSURFACE9 renderSurface;
	LPDIRECT3DVERTEXBUFFER9 screenVtx;

	//描画領域作成処理
	virtual void MakeScreen();
	virtual void MakeRenderTarget();
};

#endif