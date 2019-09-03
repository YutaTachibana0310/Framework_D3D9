//=====================================
//
//�^�X�N�}�l�[�W������[TaskManager.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "TaskManager.h"
#include "DelayedTask.h"
#include "PeriodicTask.h"
#include "Task.h"
#include "../Tool/DebugWindow.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�x���^�X�N�쐬����
***************************************/
std::unique_ptr<TaskInterface> TaskManager::CreateDelayedTask(int delay, const std::function<void(void)>& task)
{
	std::shared_ptr<DelayedTask> ptr = std::make_shared<DelayedTask>(delay, task);
	taskList.push_back(ptr);

	return std::unique_ptr<TaskInterface>(new TaskInterface(ptr));
}

/**************************************
����^�X�N�쐬����
***************************************/
std::unique_ptr<TaskInterface> TaskManager::CreatePeriodicTask(int interval, const std::function<void(void)>& task)
{
	std::shared_ptr<PeriodicTask> ptr = std::make_shared<PeriodicTask>(interval, task);
	taskList.push_back(ptr);

	return std::unique_ptr<TaskInterface>(new TaskInterface(ptr));
}

/**************************************
TaskManager�X�V����
***************************************/
void TaskManager::Update()
{
	//�I�������^�X�N���폜
	taskList.remove_if([](std::shared_ptr<Task> task)
	{
		return task->IsFinished();
	});

	//�^�X�N���s
	for (auto&& task : taskList)
	{
		task->Run();
	}

	Debug::Begin("TaskManager");
	Debug::Text("task count : %d", taskList.size());
	Debug::End();
}

/**************************************
TaskInterface�R���X�g���N�^
***************************************/
TaskInterface::TaskInterface()
{

}

/**************************************
TaskInterface�R���X�g���N�^
***************************************/
TaskInterface::TaskInterface(std::shared_ptr<Task> task) :
	task(task)
{
}

/**************************************
TaskInterface�f�X�g���N�^
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
TaskInterface������Z�q
***************************************/
TaskInterface & TaskInterface::operator=(const TaskInterface & src)
{
	task.reset();
	task = src.task;

	return *this;
}

/**************************************
TaskInterface��~����
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
TaskInterface�ĊJ����
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
TaskInterface���f����
***************************************/
void TaskInterface::Pause()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Pause();
	}
}
