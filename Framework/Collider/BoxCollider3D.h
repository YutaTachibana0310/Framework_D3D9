//=====================================
//
//ボックスコライダー3Dヘッダ[BoxCollider3D.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _BOXCOLLIDER3D_H_
#define _BOXCOLLIDER3D_H_

#define BOXCOLLIDER3D_USE_DEBUG

#include "../../main.h"
#include "BaseCollider.h"
#include "ColliderObserver.h"

/**************************************
BoxCollider3Dクラス
***************************************/
class BoxCollider3D : public BaseCollider
{
public:
	//コンストラクタ、デストラクタ
	BoxCollider3D(const std::string& tag, const Transform& transform, ColliderObserver& observer);
	BoxCollider3D(const std::string& tag, const Transform& transform, ColliderObserver& observer, const D3DXVECTOR3& size);
	~BoxCollider3D();

	//衝突判定、サイズセット、座標アドレスセット
	bool CheckCollision(BoxCollider3D& other);
	void SetSize(const D3DXVECTOR3 size);
	void SetOffset(const D3DXVECTOR3 offset);

	//デバッグ表示
	void Draw();

private:
	std::string tag;
	D3DXVECTOR3 size;		//サイズ
	D3DXVECTOR3 offset;		//オフセット

	static UINT instanceCount;		//インスタンスカウント
#ifdef BOXCOLLIDER3D_USE_DEBUG
	static void CreateRenderTool();
	static D3DMATERIAL9 material;	//描画用マテリアル
	static LPD3DXMESH mesh;			//描画用メッシュ
#endif
};
#endif