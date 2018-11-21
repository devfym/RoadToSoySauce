#pragma once
#include <DxLib.h>
class FramePerSecond
{

	int startTime;
	int lastTime;
	int frameCount;
	float averageFPS;
	static const int averageFrame = 30;
	static const int totalFrame = 30;

public:
	float displayFPS;
	FramePerSecond(void);
	~FramePerSecond(void);
	bool UpdateFPS();
	void GetFPS();
	void WaitFPS();
	void DrawFPS();
};

