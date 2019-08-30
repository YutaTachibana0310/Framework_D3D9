//=====================================
//
//ボックスコライダー3D処理[BoxCollider3D.cpp]
//Author:GP12B332 21 立花雄太
//
//=====================================
#include "BoxCollider3D.h"

using namespace std;

/**************************************
マクロ定義
***************************************/

/**************************************
構造体定義
***************************************/

/**************************************
static変数
***************************************/
UINT BoxCollider3D::instanceCount;
D3DMATERIAL9 BoxCollider3D::material;
LPD3DXMESH BoxCollider3D::mesh;

/**************************************
コンストラクタ
***************************************/
BoxCollider3D::BoxCollider3D(const std::string & tag, const Transform & transform, ColliderObserver & observer) :
	BaseCollider(observer, transform),
	tag(tag)
{
	//サイズを適当な大きさに初期化
	const float InitSize = 10.0;
	size = D3DXVECTOR3(InitSize, InitSize, InitSize);

	//オフセットを初期化
	ZeroMemory(&offset, sizeof(offset));

#ifdef BOXCOLLIDER3D_USE_DEBUG
	//インスタンス数を数えてデバッグ表示用のメッシュを作成
	if (instanceCount == 0)
		CreateRenderTool();

	instanceCount++;
#endif
}

/**************************************
コンストラクタ
***************************************/
BoxCollider3D::BoxCollider3D(const std::string & tag, const Transform & transform, ColliderObserver & observer, const D3DXVECTOR3 & size) :
	BaseCollider(observer, transform),
	size(size),
	tag(tag)
{
	//オフセットを初期化
	ZeroMemory(&offset, sizeof(offset));

#ifdef BOXCOLLIDER3D_USE_DEBUG
	if (instanceCount == 0)
		CreateRenderTool();

	instanceCount++;
#endif
}

/**************************************
デストラクタ
***************************************/
BoxCollider3D::~BoxCollider3D()
{
	//TODO : ColliderManagerに離脱を通知

#ifdef BOXCOLLIDER3D_USE_DEBUG
	instanceCount--;
	if (instanceCount == 0)
	{
		SAFE_RELEASE(mesh);
	}
#endif
}

/**************************************
衝突判定
***************************************/
bool BoxCollider3D::CheckCollision(BoxCollider3D& other)
{
	D3DXVECTOR3 thisPos = this->refTransform.GetPosition() + this->offset;
	D3DXVECTOR3 otherPos = other.refTransform.GetPosition() + other.offset;
	
	D3DXVECTOR3 thisSize = Vector3::Multiply(this->size, this->refTransform.GetScale());
	D3DXVECTOR3 otherSize = Vector3::Multiply(other.size, other.refTransform.GetScale());

	//X方向の判定
	if (thisPos.x + thisSize.x < otherPos.x - otherSize.x || thisPos.x - thisSize.x > otherPos.x + otherSize.x)
		return false;

	//Y方向の判定
	if (thisPos.y + thisSize.y < otherPos.y - otherSize.y || thisPos.y - thisSize.y > otherPos.y + otherSize.y)
		return false;

	//Z方向の判定
	if (thisPos.z + thisSize.z < otherPos.z - otherSize.z || thisPos.z - thisSize.z > otherPos.z + otherSize.z)
		return false;

	//衝突通知
	this->observer.OnColliderHit(other.tag);
	other.observer.OnColliderHit(this->tag);

	return true;
}

/**************************************
サイズセット
***************************************/
void BoxCollider3D::SetSize(D3DXVECTOR3 size)
{
	this->size = size;
}

/**************************************
オフセットセット
***************************************/
void BoxCollider3D::SetOffset(const D3DXVECTOR3 offset)
{
	this->offset = offset;
}

/**************************************
描画マテリアル作成処理
***************************************/
void BoxCollider3D::CreateRenderTool()
{
#ifdef BOXCOLLIDER3D_USE_DEBUG
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//キューブメッシュ作成
	D3DXCreateBox(pDevice,
		1.0f,
		1.0f,
		1.0f,
		&mesh,
		0);

	//マテリアル作成
	ZeroMemory(&material, sizeof(material));
	material.Diffuse.r = 1.0f;
	material.Diffuse.a = 1.0f;
	material.Ambient.r = 1.0f;
	material.Ambient.a = 1.0f;
	material.Specular.r = 1.0f;
	material.Specular.a = 1.0f;
	material.Emissive.r = 1.0f;
	material.Emissive.a = 1.0f;
#endif
}

/**************************************
描画処理
***************************************/
void BoxCollider3D::Draw()
{
#ifdef BOXCOLLIDER3D_USE_DEBUG
	if (!active)
		return;

	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxWorld;
	D3DMATERIAL9 matDef;

	//デフォルトマテリアル取得
	pDevice->GetMaterial(&matDef);

	//レンダーステートとマテリアルを設定
	pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	pDevice->SetMaterial(&material);
	pDevice->SetTexture(0, NULL);

	//行列計算
	D3DXVECTOR3 pos = refTransform.GetPosition() + offset;
	D3DXVECTOR3 scale = Vector3::Multiply(refTransform.GetScale(), size) * 2.0f;

	D3DXMatrixIdentity(&mtxWorld);
	mtxWorld._11 = scale.x;
	mtxWorld._22 = scale.y;
	mtxWorld._33 = scale.z;
	mtxWorld._41 = pos.x;
	mtxWorld._42 = pos.y;
	mtxWorld._43 = pos.z;

	//ワールド情報セット
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	//描画
	mesh->DrawSubset(0);

	//レンダーステートとマテリアル復元
	pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	pDevice->SetMaterial(&matDef);
#endif
}