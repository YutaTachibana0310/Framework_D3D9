//=====================================
//
// TweenTest.h
// �@�\:�g�D�C�[���e�X�g
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TWEENTEST_H_
#define _TWEENTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"

/**************************************
�O���錾
***************************************/
class Polygon2D;
enum class ExpandType: int;
enum class CloseType : int;
enum EaseType : int;

/**************************************
�N���X��`
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