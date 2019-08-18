//=====================================
//
//クォータニオン処理[Quaternion.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "Quaternion.h"
#include "TMath.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
D3DXVECTOR3 Quaternion::ToEuler(const D3DXQUATERNION& q)
{
	float x = q.x;
	float y = q.y;
	float z = q.z;
	float w = q.w;

	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float xy = x * y;
	float xz = x * z;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	// 1 - 2y^2 - 2z^2
	float m00 = 1.0f - (2.0f * y2) - (2.0f * z2);

	// 2xy + 2wz
	float m01 = (2.0f * xy) + (2.0f * wz);

	// 2xy - 2wz
	float m10 = (2.0f * xy) - (2.0f * wz);

	// 1 - 2x^2 - 2z^2
	float m11 = 1.0f - (2.0f * x2) - (2.0f * z2);

	// 2xz + 2wy
	float m20 = (2.0f * xz) + (2.0f * wy);

	// 2yz+2wx
	float m21 = (2.0f * yz) - (2.0f * wx);

	// 1 - 2x^2 - 2y^2
	float m22 = 1.0f - (2.0f * x2) - (2.0f * y2);


	float tx, ty, tz;

	if (Math::Approximately(m21, 1.0f))
	{
		tx = D3DX_PI / 2.0f;
		ty = 0;
		tz = atan2f(m10, m00);
	}
	else if (Math::Approximately(m21, -1.0f))
	{
		tx = -D3DX_PI / 2.0f;
		ty = 0;
		tz = atan2f(m10, m00);
	}
	else
	{
		tx = asinf(-m21);
		ty = atan2f(m20, m22);
		tz = atan2f(m01, m11);
	}

	D3DXVECTOR3 out;
	out.x = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(tx));
	out.y = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(ty));
	out.z = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(tz));

	return out;
}
