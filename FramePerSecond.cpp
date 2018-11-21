#include "FramePerSecond.h"
#include <DxLib.h>

FramePerSecond::FramePerSecond(void)
{
	startTime = 0;
	frameCount = 0;
	averageFPS = 0;
	displayFPS = 0;
}


FramePerSecond::~FramePerSecond(void)
{
}

bool FramePerSecond::UpdateFPS()
{
	if (frameCount == 0)
		startTime = GetNowCount();
	if (frameCount == averageFrame)
	{
		lastTime = GetNowCount();
		averageFPS = 1000.f / ((lastTime - startTime) / (float)averageFrame);
		frameCount = 0;
		startTime = lastTime;
		lastTime = 0;
	}

	frameCount++;
	return true;
}

void FramePerSecond::GetFPS()
{
	if (averageFPS != 0)
		displayFPS = averageFPS;
}

void FramePerSecond::WaitFPS()
{
	int currentTime = GetNowCount() - startTime;
	int waitTime = frameCount * 1000 / totalFrame - currentTime;
	if (waitTime > 0)
		Sleep(waitTime);
}

void FramePerSecond::DrawFPS()
{
	DrawFormatString(0, 0, GetColor(0, 255, 255), "FPS=%f", displayFPS);

}
