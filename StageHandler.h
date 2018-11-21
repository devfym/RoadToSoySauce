#pragma once
#include <DxLib.h>
#include "DataList.h"

class StageHandler
{


public:

	int Model;
	int BackGround;
	VECTOR Position;
	VECTOR AreaEnd1, AreaEnd2;
	VECTOR AreaBack1, AreaBack2;
	VECTOR NextStage1, NextStage2;


	int playerCount;
	int playerDirection;
	VECTOR playerAngle;
	VECTOR playerPosition;
	float playerCamera;
	SaveData sd;

	int StageBossDefeated[5];
	int StageGoNextFlag[5];
	int StageKeys[5];

	StageHandler(void);
	~StageHandler(void);
	void StageInitialization(SaveData m_sd);
	void StageDraw(void);
	void StageFlag(void);
	void ReleaseData(void);
};

