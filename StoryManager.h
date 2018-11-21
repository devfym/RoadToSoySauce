#pragma once
#include <DxLib.h>
#include "DataList.h"
class K_KinectHandler;
class PlayerHandler;
class EnemyHandler;
class BossHandler;
class StageHandler;
class ObjectHandler;
class F_LoadingScreen;
class StoryManager
{

public:

	SystemConfiguration syscon;
	SaveData sd;
	K_KinectHandler *kh;
	PlayerHandler *ph;
	EnemyHandler *eh[5];
	BossHandler *bh;
	StageHandler *sh;
	ObjectHandler *oh[3];
	F_LoadingScreen *fls;

	MV1_COLL_RESULT_POLY_DIM ObjCol[3]; // COLLISION Of Object;
	MV1_COLL_RESULT_POLY_DIM	EnemyCol[5]; // COLLISION Of Enemy;
	MV1_COLL_RESULT_POLY_DIM AttackToEnemy;
	MV1_COLL_RESULT_POLY_DIM BossCol;
	int InitializeFlag; // Loading of files
	int currentStage;
	int currentArea;
	int currentAreaOld;
	int HitFlag; // COLLISION TESTER

	// for game over measurements;
	int img_GameOver;
	int snd_GameOver;
	int endOver;
	int FontScore;

	// stage begin measurements;
	int StageNew;
	int img_NewStage;
	int snd_NewStage;

	// object measurements;
	int snd_GetItem1;
	int snd_GetItem2;


	// enemy measurements;
	int snd_Damaged;
	int snd_Attack1;
	int snd_Attack2;


	// for bgm
	int snd_StageTheme;
	int snd_StoryTelling;

	MV1_COLL_RESULT_POLY N, E, S, W, Middle; // addressed to Stage Model
	MV1_COLL_RESULT_POLY AreaEnd, AreaBack, NextStage; // addressed to Player;

	// for pause
	int img_PBorder;
	int img_PContinue;
	int img_PExit;


	StoryManager(K_KinectHandler *m_kh);
	~StoryManager(void);
	void StoryLoad(int SaveNumber); // change to save data load
	int StoryLoop(void);
	int GameOver(void);
	int StageBegin(void);
	void SaveDataLoad(int SaveNumber);
	void SaveDataSave(int SaveNumber);
	void ReleaseData(void);
	void WhilePause(void);
	int  ActionWhilePause(int cx, int cy, int cf);

	int GameNew(int count); // for New Player story
	int GameClear(int count); // for Game Cleared when get soysauce story
};

