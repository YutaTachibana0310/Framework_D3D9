//=====================================
//
// TransformTest.h
// 機能:
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TRANSFORMTEST_H_
#define _TRANSFORMTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Renderer3D/BillboardObject.h"

/**************************************
前方宣言
***************************************/
class TransformObject;
class BoardPolygon;
class ChildObject;

/**************************************
クラス定義
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