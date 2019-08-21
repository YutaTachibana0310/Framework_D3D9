//=====================================
//
//トランスフォームヘッダ[Transform.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "../../main.h"
#include "../Math/Quaternion.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class Transform
{
public:

	//コンストラクタ
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);

	//移動処理
	void Move(float x, float y, float z);
	void Move(const D3DXVECTOR3& velocity);
	void SetPosition(const D3DXVECTOR3& position);
	D3DXVECTOR3 GetPosition();

	//回転処理
	void Rotate(float degX, float degY, float degZ);
	void Rotate(float deg, const D3DXVECTOR3& axis);
	void SetRotation(float x, float y, float z);
	void SetRotation(const D3DXVECTOR3& rotation);
	void SetRotation(const D3DXQUATERNION& rotation);
	D3DXVECTOR3 GetEulerAngle();
	D3DXQUATERNION GetRotation();

	//スケール処理
	void Scale(float deltaX, float deltaY, float deltaZ);
	void ScaleX(float delta);
	void ScaleY(float delta);
	void ScaleZ(float delta);
	void SetScale(const D3DXVECTOR3& scale);
	D3DXVECTOR3 GetScale();

	//向き
	D3DXVECTOR3 Forward();
	D3DXVECTOR3 Right();
	D3DXVECTOR3 Up();

	//ワールド変換設定処理
	void SetWorld(const D3DXMATRIX* parent = NULL);
	void SetWorldInvView(const D3DXMATRIX* parent = NULL);
	D3DXMATRIX GetMatrix();
	
private:
	D3DXVECTOR3 pos;	//座標
	D3DXVECTOR3 scale;	//スケール
	D3DXQUATERNION rot;	//回転
};

#endif