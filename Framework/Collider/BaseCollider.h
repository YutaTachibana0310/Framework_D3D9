//=====================================
//
//�x�[�X�R���C�_�[�w�b�_[BaseCollider.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASECOLLIDER_H_
#define _BASECOLLIDER_H_

#include "../../main.h"
#include "ColliderObserver.h"
#include <vector>

/**************************************
�O���錾
***************************************/

/**************************************
�N���X��`
***************************************/
class BaseCollider
{
public:
	BaseCollider(ColliderObserver& observer, const Transform& transform);
	virtual ~BaseCollider();

	void SetActive(bool state);
	bool IsActive();

protected:
	bool active;
	ColliderObserver& observer;
	const Transform& refTransform;
};

#endif