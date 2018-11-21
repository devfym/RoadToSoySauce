#pragma once
#include <DxLib.h>
#include "DataList.h"

class Boss2Handler
{
public:

	int Model[5]; // load all model in once
	int Model_Attack[4];
	int Life;

	int BossNumber;
	int EnemyType;

	int DamageFlag;
	int DamageIntervalCount;

	float radius;
	VECTOR Position;
	VECTOR Angle;

	VECTOR ATTACK_ANGLE;
	VECTOR ATTACK[4]; // 4 directions

	int MovementPattern;
	int MovementCount;
	int MovementInRest;

	int B5Count;
	int B3Count;
	int img_BossName[5], img_BossLife;

	Boss2Handler(void);
	~Boss2Handler(void);

	// after stage load
	void BossInitialization(void);
	void BossMovement(VECTOR PlayerPos);
	void BossAction(void);
	int BossUpdate(void);
	void BossDraw(void);
	void BossStatusDraw(void);

	void ReleaseData(void);
};

