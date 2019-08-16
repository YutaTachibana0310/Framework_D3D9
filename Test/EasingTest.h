//=====================================
//
//�C�[�W���O�e�X�g�w�b�_[EasingTest.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _EASINGTEST_H_
#define _EASINGTEST_H_

#include "../main.h"
#include "../Framework\Renderer2D\Polygon2D.h"
#include "../Framework\Math\Easing.h"
#include "../Framework\Core\BaseScene.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class EasingTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	int cntFrame;
	Polygon2D* polygon;
	int type;

};

#endif