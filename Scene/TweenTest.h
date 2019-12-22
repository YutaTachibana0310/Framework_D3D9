//=====================================
//
// TweenTest.h
// 機能:トゥイーンテスト
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TWEENTEST_H_
#define _TWEENTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"

/**************************************
前方宣言
***************************************/
class Polygon2D;
enum class ExpandType: int;
enum class CloseType : int;
enum EaseType : int;

/**************************************
クラス定義
***************************************/
class TweenTestScene : public BaseScene
{
	using BaseScene::BaseScene;
public:
	virtual void Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

private:
	std::shared_ptr<Polygon2D> polygon;

	bool useExpand;
	int expand, close;
	ExpandType expandType;
	CloseType closeType;
	EaseType easeType;

	void OnFinish();
};


#endif