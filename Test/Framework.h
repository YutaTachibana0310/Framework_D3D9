//=====================================
//
//�t���[�����[�N�w�b�_[Framework.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

#include "../main.h"
#include "../Framework\Core\BaseGame.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class Framework : public BaseGame
{
public:
	Framework(HINSTANCE hInstance, HWND hWnd);

	void Update();
};

#endif