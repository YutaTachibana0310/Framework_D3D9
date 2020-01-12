//=====================================
//
// TransformTest.h
// �@�\:
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TRANSFORMTEST_H_
#define _TRANSFORMTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Renderer3D/BillboardObject.h"

/**************************************
�O���錾
***************************************/
class TransformObject;
class BoardPolygon;
class ChildObject;

/**************************************
�N���X��`
***************************************/
class TransformTestScene : public BaseScene
{
	using BaseScene::BaseScene;
public:
	virtual void Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

private:
	TransformObject* parent;
	ChildObject* child;
};

class ChildObject : public BillboardObject
{
public:
	ChildObject();
	~ChildObject();

	void Draw();

private:
	BoardPolygon* polygon;
};

#endif