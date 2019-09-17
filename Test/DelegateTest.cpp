//=====================================
//
//テンプレート処理[DelegateTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "DelegateTest.h"
#include "../Framework/Pattern/Delegate.h"
#include "../Framework/Tool/DebugWindow.h"

/**************************************
グローバル変数
***************************************/

/**************************************
プロトタイプ宣言
***************************************/
void DelegateTest::Init()
{
	object = new DelegateObject();
	delegate = Delegate<DelegateObject>::Create(object, &DelegateObject::OnClick);
}

void DelegateTest::Uninit()
{
	SAFE_DELETE(object);
	SAFE_DELETE(delegate);
}

void DelegateTest::Update()
{
	Debug::Begin("Delegate");
	if (Debug::Button("Clock"))
	{
		(*delegate)(0);
	}
	Debug::End();

	object->Update();
}

void DelegateTest::Draw()
{
	object->Draw();
}

DelegateObject::DelegateObject() :
	cnt(0)
{
	
}

DelegateObject::~DelegateObject()
{
}

void DelegateObject::Update()
{

}

void DelegateObject::Draw()
{
	Debug::Begin("Delegate");
	Debug::Text("cnt : %d", cnt);
	Debug::End();
}

void DelegateObject::OnClick(int value)
{
	cnt++;
}
