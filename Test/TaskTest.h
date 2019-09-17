//=====================================
//
//タスクテストヘッダ[TaskTest.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _TASKTEST_H_
#define _TASKTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Task/TaskManager.h"
#include <memory>

/**************************************
前方宣言
***************************************/
class TaskHandle;
/**************************************
マクロ・列挙子定義
***************************************/

/**************************************
クラス定義
***************************************/
class TaskTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	class TestUnit {
	public:
		std::unique_ptr<TaskHandle> periodicTask;
		std::unique_ptr<TaskHandle> delayedTask;

		int numDelay;
		int numPeriodic;
	};

	TestUnit* unit;
};

#endif