//=====================================
//
//���V�[���w�b�_[BaseScene.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BASESCENE_H_
#define _BASESCENE_H_

/**************************************
�}�N����`
***************************************/

/**************************************
BaseScene�N���X
�p�����
void Init()
void Uninit()
void Update()
void Draw()
����������
***************************************/
class BaseScene
{
public:
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif