#pragma once
#include <DxLib.h>
#include "DataList.h"

class K_KinectHandler;
class PlayerHandler;
class Boss2Handler;
class BossRushManager
{

public:

	SystemConfiguration syscon;
	BossRushRank rank;
	int HighScore;
	int RoundNo;
	int StartTime, CurrentTime;

	// stage begin measurements;
	int StageNew;
	int img_NewStage;
	int snd_NewStage;

	// for game over measurements;
	int img_GameOver;
	int snd_GameOver;
	int endOver;
	int FontScore;

	K_KinectHandler *kh;
	PlayerHandler *ph;
	Boss2Handler *bh;
	int InitializeFlag;

	// enemy measurements;
	int snd_Damaged;
	int snd_Attack1;
	int snd_Attack2;

	// for bgm
	int snd_StageTheme;

	// Stage model
	int model_Stage;


	// Collision Handler
	int HitFlag; // COLLISION TESTER
	MV1_COLL_RESULT_POLY_DIM PlayerCol;
	MV1_COLL_RESULT_POLY_DIM AttackToEnemy;
	MV1_COLL_RESULT_POLY_DIM BossCol;
	MV1_COLL_RESULT_POLY N, E, S, W, Middle; // addressed to Stage Model

	BossRushManager(K_KinectHandler *m_kh);
	~BossRushManager(void);
	void BossRushLoad(void);
	int BossRushLoop(void);
	int BossRushStart(void);
	int BossRushGameOver(void);
	void ReleaseData(void);
	void BossRushRanking(void);

};

