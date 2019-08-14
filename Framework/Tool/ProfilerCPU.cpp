//=====================================
//
//テンプレート処理[template.cpp]
//Author:GP12B332 21 立花雄太
//
//=====================================
#include "ProfilerCPU.h"
#include "DebugWindow.h"
#include <string.h>
#include <assert.h>

using namespace std;

/**************************************
マクロ定義
***************************************/
#define PROFILER_CPU_COUNT_INTERBAL	(20)
#define PROFILER_CPU_BAR_SIZE			(D3DXVECTOR2(75.0f, 0.0f))

/**************************************
ProfilerCPUコ更新処理
***************************************/
void ProfilerCPU::Update()
{
#ifdef USE_PROFILER_CPU
	cntFrame++;
#endif
}

/**************************************
描画処理
***************************************/
void ProfilerCPU::Draw()
{
#ifdef USE_PROFILER_CPU
	CalcElapsed();

	for (auto&& profiler : profilerMap)
	{
		Debug::Begin(profiler.first.c_str());

		//FPS表示

		//総経過時間表示
		double progress = 0.0;
		for (auto&& nodeMap : profiler.second)
		{
			progress += nodeMap.second.GetElapsed();
		}
		Debug::Text("%3f[msec]", progress);

		//各ノード表示
		for (auto&& nodeMap : profiler.second)
		{
			double elapsed = nodeMap.second.GetElapsed();
			Debug::ProgressBar(NULL, (float)(elapsed / progress), PROFILER_CPU_BAR_SIZE);
			Debug::SameLine();
			Debug::Text("%s : %3f[msec]", nodeMap.first.c_str(), elapsed);
		}

		Debug::End();
	}
#endif
}

/**************************************
クリア処理
***************************************/
void ProfilerCPU::Clear()
{
	for (auto&& nodeMap : profilerMap)
	{
		nodeMap.second.clear();
	}
	profilerMap.clear();
}

/**************************************
計測開始処理
***************************************/
void ProfilerCPU::BeginProfile(const char* tag, const char* label)
{
#ifdef USE_PROFILER_CPU
	if (cntFrame % 20 != 0)
		return;

	profilerMap[string(tag)][string(label)].Count(true);
#endif
}

/**************************************
計測終了処理
***************************************/
void ProfilerCPU::EndProfile(const char* tag, const char* label)
{
#ifdef USE_PROFILER_CPU
	if (cntFrame % 20 != 0)
		return;

	profilerMap[string(tag)][string(label)].Count(false);
#endif
}

/**************************************
経過時間計算
***************************************/
void ProfilerCPU::CalcElapsed()
{
#ifdef USE_PROFILER_CPU
	LARGE_INTEGER frequencty;
	QueryPerformanceFrequency(&frequencty);

	for (auto&& profiler : profilerMap)
	{
		for (auto&& node : profiler.second)
		{
			node.second.CalcElapsed(frequencty);
		}
	}
#endif
}

/**************************************
ProfilerNodeコンストラクタ
***************************************/
ProfilerNode::ProfilerNode()
{
	ZeroMemory(&start, sizeof(start));
	ZeroMemory(&end, sizeof(end));
	elapsedTime = 0.0;
}

/**************************************
ProfilerNodeカウント処理
***************************************/
void ProfilerNode::Count(bool isStart)
{
	if (isStart)
	{
		QueryPerformanceCounter(&start);
	}
	else
	{
		QueryPerformanceCounter(&end);
	}
}

/**************************************
ProfilerNode経過時間計算処理
***************************************/
void ProfilerNode::CalcElapsed(const LARGE_INTEGER& frequency)
{
	LONGLONG span = end.QuadPart - start.QuadPart;
	elapsedTime = (double)span * 1000.0 / (double)frequency.QuadPart;
}
/**************************************
ProfilerNode経過時間取得処理
***************************************/
double ProfilerNode::GetElapsed()
{
	return elapsedTime;
}