//=====================================
//
//�e�X�g�g�����W�V��������[TestTransition.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "TestTransition.h"
#include "../Framework\Tool\DebugWindow.h"
#include "../Framework\Pattern\BaseState.h"
/**************************************
�}�N����`
***************************************/

/**************************************
�f�X�g���N�^
***************************************/
void TestTransition::Uninit()
{
	
}

/**************************************
����������
***************************************/
void TestTransition::Init()
{
	type = TransitionType::HexaRotation;
	transitionOut = false;
}

/**************************************
�X�V����
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
�`�揈��
***************************************/
void TestTransition::Draw()
{
	TransitionController::Instance()->DrawMask();

	TransitionController::Instance()->DrawTransition();
}