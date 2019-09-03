//=====================================
//
//タスクテスト処理[TaskTest.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TaskTest.h"
#include "../Framework/Tool/DebugWindow.h"

/**************************************
初期化処理
***************************************/
void TaskTest::Init()
{
	unit = new TestUnit();

	unit->numDelay = 0;
	unit->numPeriodic = 0;

	unit->periodicTask = TaskManager::Instance()->CreatePeriodicTask(20, [&]()
	{
		unit->numPeriodic++;
	});
}

/**************************************
終了処理
***************************************/
void TaskTest::Uninit()
{
	SAFE_DELETE(unit);
}

/**************************************
更新処理
***************************************/
void TaskTest::Update()
{
	Debug::Begin("Task");

	if (Debug::Button("Delete") && unit != NULL)
	{
		SAFE_DELETE(unit);
	}

	if (Debug::Button("Create") && unit == NULL)
	{
		unit = new TestUnit();
		unit->periodicTask = TaskManager::Instance()->CreatePeriodicTask(20, [&]()
		{
			unit->numPeriodic++;
		});
	}

	if (unit != NULL)
	{
		if (Debug::Button("Delay"))
		{
			unit->delayedTask = TaskManager::Instance()->CreateDelayedTask(20, [&]()
			{
				unit->numDelay++;
			});
		}

		if (Debug::Button("Pause"))
		{
			unit->periodicTask->Pause();
		}

		if (Debug::Button("Resume"))
		{
			unit->periodicTask->Resume();
		}

		if (Debug::Button("Stop"))
		{
			unit->periodicTask->Stop();
		}

		Debug::Text("delay : %d", unit->numDelay);
		Debug::Text("periodic : %d", unit->numPeriodic);
	}

	Debug::End();
}

/**************************************
描画処理
***************************************/
void TaskTest::Draw()
{
}
