//=====================================
//
//�N�H�[�^�j�I���w�b�_[Quaternion.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "../../main.h"

/**************************************
�O���錾
***************************************/

/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
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