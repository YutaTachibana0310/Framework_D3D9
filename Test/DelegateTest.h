//=====================================
//
// DelegateTest.h
// 機能:
// Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _DELEGATETEST_H_
#define _DELEGATETEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"

/**************************************
前方宣言
***************************************/
class DelegateObject;
class DelegateBase;

/**************************************
クラス定義
***************************************/
class DelegateTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	DelegateObject *object;
	DelegateBase* delegate;
};

class DelegateObject
{
public:
	DelegateObject();
	~DelegateObject();

	void Update();
	void Draw();

	void OnClick(int value);

private:
	int cnt;
};
#endif