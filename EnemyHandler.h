#pragma once
#include <DxLib.h>
#include "DataList.h"
#include <math.h>
class EnemyHandler
{

public:

	int Model;
	int Life;
	int EnemyID;
	int Exist;
	int EnemyType; // 1 = Arnis, 2 = Tirador need to attack
	int DamageFlag;
	int DamageIntervalCount;
	VECTOR Position;
	float Radius;
	VECTOR Angle;
	int AngleInterval;
	EnemyHandler(void);
	~EnemyHandler(void);

	void EnemyInitialization(int StageNumber, int AreaNumber, int EnemyNumber);
	void EnemyDraw(void);
	void EnemyMovement(void);
	void CountRespawn(void);
	int CheckExist(void);
	int EnemyCheck(void);

	int SearchPlayer(VECTOR playerPos);
	void EnemyMove(VECTOR playerPos);
	void ReleaseData(void);

};

