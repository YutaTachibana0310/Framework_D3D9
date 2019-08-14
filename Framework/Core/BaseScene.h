//=====================================
//
//ξκV[wb_[BaseScene.h]
//Author:GP12B332 21 §ΤYΎ
//
//=====================================
#ifndef _BASESCENE_H_
#define _BASESCENE_H_

/**************************************
}Nθ`
***************************************/

/**************************************
BaseSceneNX
p³ζΕ
void Init()
void Uninit()
void Update()
void Draw()
πΐ·ι
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