//=====================================
//
//�^�X�N�e�X�g�w�b�_[TaskTest.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TASKTEST_H_
#define _TASKTEST_H_

#include "../main.h"
#include "../Framework/Core/BaseScene.h"
#include "../Framework/Task/TaskManager.h"
#include <memory>

/**************************************
�O���錾
***************************************/
class TaskInterface;
/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
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
		std::unique_ptr<TaskInterface> periodicTask;
		std::unique_ptr<TaskInterface> delayedTask;

		int numDelay;
		int numPeriodic;
	};

	TestUnit* unit;
};

#endif