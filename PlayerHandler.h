#pragma once
#include <DxLib.h>
#include "DataList.h"

class PlayerHandler
{
public:
	int Model;
	int ModelFlag;
	int Animation;
	int Life;
	int img_Life, img_LifeG;
	VECTOR Position, Camera;
	VECTOR Angle;
	int count;
	int Direction;

	int img_CompassN, img_CompassE, img_CompassS, img_CompassW, img_CompassNE, img_CompassNW, img_CompassSE, img_CompassSW;
	int img_Map;
	int img_Item1, img_Item2;
	int img_Score;
	int EnemyDefeated[17];
	float Radius;
	int ItemFlag;
	int ItemChangeInterval;
	int AttackFlag;
	int Score;
	float speed;
	float JumpPower;
	int JumpFlag;
	int StageFlag;
	int EnemyFlag;
	int snd_Jump, snd_Run;
	int DamageIntervalCount;
	VECTOR AR1, AR2;
	VECTOR A1, A2, A3, A4;

	SaveData sd;
	int FontNormal, FontScore;

	PlayerHandler(void);
	~PlayerHandler(void);
	void PlayerInitialization(int VolumeSE, int playerDirection, int playerCount, VECTOR playerAngle, VECTOR playerPosition, float CameraRotate, SaveData m_sd);
	void PlayerDraw(void);
	void PlayerStatusDraw(int ssX, int ssY);
	void PlayerUpdateMovement(int MovementNumber, int CollisionFlag, int DirectionNumber); // 1 = walk, 0 = rest // 1 = hit, 0 = Not
	void PlayerUpdateJump(int MovementNumber, int CollisionFlag); // 1 jump 0 not // 1 = hit, 0 = not
	int PlayerUpdateAction1(int ActionNumber); // 1 = attack arnis
	void PlayerUpdateWeapon(void); // 1 = change weapon, -1 not
	void PlayerUpdateChangeWeapon(int changeFlag); // 0 = no change, 1 = change,  1 = arnis, 2 = tirador, 3  = shield
	void ReleaseData(void);


	// For Boss Rush
	void PlayerInitializationForBossRush(int VolumeSE);
	//	  PlayerDraw(void)
	void PlayerStatusDrawForBossRush(int ssX, int ssY, int HighScore, int RoundNo, int CurrentTime);
	//	 PlayerUpdateMovement
	//   PlayerUpdateJump
	//	 PlayerUpdateAction1
	//   PlayerUpdateChangeWeapon
	//   ReleaseData(void);
};

