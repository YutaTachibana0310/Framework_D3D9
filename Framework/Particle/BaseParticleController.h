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
#define PARTICLE_NUM_MAX	(1024)

/**************************************
前方宣言
***************************************/

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
	static LPDIRECT3DVERTEXDECLARATION9 declare;
	static LPD3DXEFFECT effect;
	static LPDIRECT3DINDEXBUFFER9 indexBuff;	
	static LPDIRECT3DVERTEXBUFFER9 transformBuff, uvBuff;
	static UINT instanceCount;
	static D3DXHANDLE hMtxView, hMtxProj, hMtxInvView;

	//頂点バッファへの各情報セット処理
	UINT EmbedParameterUV();
	UINT EmbedParameterTransform();

	//静的メンバ準備処理
	static void LoadEffect();
	static void MakeVertexDeclaration();
	static void MakeTransformBuffer();
	static void MakeUVBuffer();
	static void MakeIndexBuffer();
};

#endif