//=====================================
//
// DelegateTest.h
// �@�\:
// Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _DELEGATETEST_H_
#define _DELEGATETEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Pattern/Delegate.h"

/**************************************
�O���錾
***************************************/
class DelegateObject;

/**************************************
�N���X��`
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
	DelegateBase<int(void)> *delegate;
};

class DelegateObject
{
public:
	DelegateObject();
	~DelegateObject();

	void Update();
	void Draw();

	int OnClick();

private:
	int cnt;
};
#endif