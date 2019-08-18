//=====================================
//
//クォータニオンヘッダ[Quaternion.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "../../main.h"

/**************************************
前方宣言
***************************************/

/**************************************
マクロ・列挙子定義
***************************************/

/**************************************
クラス定義
***************************************/
class Quaternion
{
public:
	static D3DXVECTOR3 ToEuler(const D3DXQUATERNION& q);
	static D3DXQUATERNION ToQuaternion(const D3DXVECTOR3& euler);
private:
	Quaternion();
};

#endif