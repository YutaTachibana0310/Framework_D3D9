//=====================================
//
//ベースパーティクルコントローラヘッダ[BaseParticleController.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BASEPARTICLECONTROLLER_H_
#define _BASEPARTICLECONTROLLER_H_

#include "../../main.h"
#include "BaseParticle.h"
#include "BaseEmitter.h"
#include <vector>

/**************************************
マクロ定義
***************************************/

/**************************************
前方宣言
***************************************/
class ParticleRenderer;
class ParticleUnit;

/**************************************
BasePartlceControllerクラス
継承先で
・単位頂点バッファ作成、テクスチャ読み込み
・void MakeParticleContainer(), MakeEmitterContainer()
を実装する
***************************************/
class BaseParticleController
{
public:
	//コンストラクタ、デストラクタ
	BaseParticleController();
	virtual ~BaseParticleController();

	virtual BaseEmitter* SetEmitter(const D3DXVECTOR3& pos);	//エミッタセット処理
	virtual void Uninit();				//終了処理
	void Update();						//更新処理
	bool Draw();						//描画処理

	//描画開始・終了処理
	static void BeginDraw();		
	static void EndDraw();			

protected:
	LPDIRECT3DVERTEXBUFFER9 unitBuff;				//単位頂点バッファ
	LPDIRECT3DTEXTURE9 texture;						//テクスチャ
	std::vector<BaseParticle*> particleContainer;	//パーティクルコンテナ
	std::vector<BaseEmitter*> emitterContainer;		//エミッタコンテナ

	//単位頂点バッファ作成処理
	void MakeUnitBuffer(const D3DXVECTOR2& size, const D3DXVECTOR2& texDix = D3DXVECTOR2(1.0f, 1.0f));	
	void LoadTexture(const char* filePath);			//テクスチャ読み込み処理

	//コンテナ作成
	virtual void MakeParticleContainer() = 0;
	virtual void MakeEmitterContainer() = 0;

private:
	//インスタンシングに必要な静的メンバ
	static ParticleRenderer* renderer;
	static UINT instanceCount;
};

/**************************************
パーティクルの単位頂点
***************************************/
class ParticleUnit
{
public:
	D3DXVECTOR3 vtx;	//頂点座標
	D3DXVECTOR2 tex;	//UV座標
};

#endif