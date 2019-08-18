//=====================================
//
//テストトランジション処理[TestTransition.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TestTransition.h"
#include "../Framework\Tool\DebugWindow.h"
#include "../Framework\Pattern\BaseState.h"
/**************************************
マクロ定義
***************************************/

/**************************************
デストラクタ
***************************************/
void TestTransition::Uninit()
{
	
}

/**************************************
初期化処理
***************************************/
void TestTransition::Init()
{
	type = TransitionType::HexaRotation;
	transitionOut = false;
}

/**************************************
更新処理
***************************************/
void TestTransition::Update()
{
	Debug::Begin("Transition");

	Debug::RadioButton("HexaRot", type, (int)TransitionType::HexaRotation);
	Debug::RadioButton("HexaPop", type, (int)TransitionType::HexaPop);
	Debug::RadioButton("Mist", type, (int)TransitionType::Mist);

	Debug::NewLine();


	if (Debug::Button("Transition In"))
	{
		TransitionController::Instance()->SetTransition(false, (TransitionType)type);
	}
	if (Debug::Button("Transition Out"))
	{
		TransitionController::Instance()->SetTransition(true, (TransitionType)type);
	}

	Debug::End();

	TransitionController::Instance()->Update();
}

/**************************************
描画処理
***************************************/
void TestTransition::Draw()
{
	TransitionController::Instance()->DrawMask();

	TransitionController::Instance()->DrawTransition();
}