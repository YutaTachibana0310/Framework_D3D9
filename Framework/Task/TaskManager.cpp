//=====================================
//
//タスクマネージャ処理[TaskManager.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "TaskManager.h"
#include "DelayedTask.h"
#include "PeriodicTask.h"
#include "Task.h"
#include "../Tool/DebugWindow.h"

/**************************************
マクロ定義
***************************************/

/**************************************
遅延タスク作成処理
***************************************/
std::unique_ptr<TaskInterface> TaskManager::CreateDelayedTask(int delay, const std::function<void(void)>& task)
{
	std::shared_ptr<DelayedTask> ptr = std::make_shared<DelayedTask>(delay, task);
	taskList.push_back(ptr);

	return std::unique_ptr<TaskInterface>(new TaskInterface(ptr));
}

/**************************************
定期タスク作成処理
***************************************/
std::unique_ptr<TaskInterface> TaskManager::CreatePeriodicTask(int interval, const std::function<void(void)>& task)
{
	std::shared_ptr<PeriodicTask> ptr = std::make_shared<PeriodicTask>(interval, task);
	taskList.push_back(ptr);

	return std::unique_ptr<TaskInterface>(new TaskInterface(ptr));
}

/**************************************
TaskManager更新処理
***************************************/
void TaskManager::Update()
{
	//終了したタスクを削除
	taskList.remove_if([](std::shared_ptr<Task> task)
	{
		return task->IsFinished();
	});

	//タスク実行
	for (auto&& task : taskList)
	{
		task->Run();
	}

	Debug::Begin("TaskManager");
	Debug::Text("task count : %d", taskList.size());
	Debug::End();
}

/**************************************
TaskInterfaceコンストラクタ
***************************************/
TaskInterface::TaskInterface()
{

}

/**************************************
TaskInterfaceコンストラクタ
***************************************/
TaskInterface::TaskInterface(std::shared_ptr<Task> task) :
	task(task)
{
}

/**************************************
TaskInterfaceデストラクタ
***************************************/
TaskInterface::~TaskInterface()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Stop();
	}
}

/**************************************
TaskInterface代入演算子
***************************************/
TaskInterface & TaskInterface::operator=(const TaskInterface & src)
{
	task.reset();
	task = src.task;

	return *this;
}

/**************************************
TaskInterface停止処理
***************************************/
void TaskInterface::Stop()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Stop();
	}
}

/**************************************
TaskInterface再開処理
***************************************/
void TaskInterface::Resume()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Resume();
	}
}

/**************************************
TaskInterface中断処理
***************************************/
void TaskInterface::Pause()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Pause();
	}
}
