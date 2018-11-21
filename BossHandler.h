#pragma once
#include <DxLib.h>
#include "DataList.h"

class BossHandler
{
public:

	int Model;
	int Model_Attack[4];
	int Life;
	int Exist;
	int BossNumber;
	int EnemyType;
	int DamageFlag;
	int DamageIntervalCount;
	float radius;
	VECTOR Position;
	VECTOR Angle;
	VECTOR ATTACK_ANGLE;
	SaveData sd;

	int MovementPattern;
	int MovementCount;
	int MovementInRest;
	int B5Count;
	VECTOR ATTACK[4]; // 4 directions

	int img_BossName, img_BossLife;

	BossHandler(void);
	~BossHandler(void);

	// after stage load
	void BossInitialization(SaveData m_sd);
	void BossMovement(void);
	void BossAction(void);
	void BossUpdate(int BossDefeatedFlag);
	void BossDraw(void);
	void BossStatusDraw(void);
	int CheckExist(void);

	void ReleaseData(void);

};

