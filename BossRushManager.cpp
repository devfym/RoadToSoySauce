#include "BossRushManager.h"
#include "K_KinectHandler.h"
#include "PlayerHandler.h"
#include "Boss2Handler.h"
BossRushManager::BossRushManager(K_KinectHandler *m_kh)
{
	kh = m_kh;
	ph = new PlayerHandler();
	bh = new Boss2Handler();
	InitializeFlag = 0;

}


BossRushManager::~BossRushManager(void)
{
}

void BossRushManager::BossRushLoad(void)
{

	if (InitializeFlag == 10)
	{

		// #1 Loading of System Configuration
		// - Read System Config  -//
		FILE *fgi = fopen("SysDat01.dat", "rb");
		if (fgi != NULL)
		{
			fread(&syscon, sizeof(syscon), 1, fgi);
		}
		fclose(fgi);

		// - Read System Config  -//
		FILE *fgi2 = fopen("SysDat04.dat", "rb");
		if (fgi2 != NULL)
		{
			fread(&rank, sizeof(rank), 1, fgi2);
		}
		fclose(fgi2);
	}
	if (InitializeFlag == 20)
	{
		// # load image
		img_NewStage = LoadGraph(GUI_BOSSRUSHLOGO);
		img_GameOver = LoadGraph(GAMEOVER);

		FontScore = CreateFontToHandle(NULL, 30, -1, DX_FONTTYPE_NORMAL);
	}
	if (InitializeFlag == 30)
	{
		// #2 Loading of Game BGM
		snd_StageTheme = LoadSoundMem(BGM_BOSS);
		snd_GameOver = LoadSoundMem(BGM_GAMEOVER);
	}
	if (InitializeFlag == 40)
	{
		snd_Damaged = LoadSoundMem(SE_DAMAGED);
		snd_Attack1 = LoadSoundMem(SE_ATTACK1);
	}
	if (InitializeFlag == 50)
	{
		snd_Attack2 = LoadSoundMem(SE_ATTACK2);
		snd_NewStage = LoadSoundMem(BGM_NEWSTAGE);
	}
	if (InitializeFlag == 60)
	{
		// #4 Loading of Stage Model
		model_Stage = MV1LoadModel(M3D_BOSSRUSH);
	}
	if (InitializeFlag == 70)
	{
		// #5 Changeing Volume of BGM & SE
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Attack1);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Attack2);
	}
	if (InitializeFlag == 80)
	{
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_GameOver);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Damaged);
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_NewStage);
	}
	if (InitializeFlag == 90)
	{
		// # 6 Initialization of Player Class
		ph->PlayerInitializationForBossRush(syscon.VolumeSE);
	}
	if (InitializeFlag == 100)
	{
		bh->BossInitialization();
	}
	if (InitializeFlag == 110)
	{
		// # Set up Collision Info
		MV1SetupCollInfo(ph->Model, -1, 8, 8, 8);
		MV1SetupCollInfo(model_Stage, -1, 8, 8, 8);
		for (int i = 0;i < 5; i++)
			MV1SetupCollInfo(bh->Model[i], -1, 8, 8, 8);
	}
	if (InitializeFlag == 120)
	{
		// # init parameters
		HighScore = rank.TopScore[0];
		RoundNo = 1;
		StageNew = 0;
		endOver = 0;
		StartTime = 0;
		//InitializeFlag=1;

	}
}

int BossRushManager::BossRushLoop(void)
{
	if (CheckSoundMem(snd_StageTheme) != 1)
		PlaySoundMem(snd_StageTheme, DX_PLAYTYPE_LOOP, TRUE);
	if (StartTime == 0)
		StartTime = GetNowCount();
	CurrentTime = (GetNowCount() - StartTime) / 1000;
	/////////////////// COLLISION UPDATE
	MV1RefreshCollInfo(ph->Model, -1);
	for (int i = 0;i < 5; i++)
		MV1RefreshCollInfo(bh->Model[i], -1);

	// ++ COLLISION CHECK FOR  MOVEMENT ACTION
	N = MV1CollCheck_Line(model_Stage, -1, ph->A1, ph->A2);		if (N.HitFlag == 1)		HitFlag = 1;
	E = MV1CollCheck_Line(model_Stage, -1, ph->A2, ph->A3);		if (E.HitFlag == 1)		HitFlag = 1;
	S = MV1CollCheck_Line(model_Stage, -1, ph->A3, ph->A4);		if (S.HitFlag == 1)		HitFlag = 1;
	W = MV1CollCheck_Line(model_Stage, -1, ph->A4, ph->A1);	if (W.HitFlag == 1)	HitFlag = 1;
	ph->PlayerUpdateMovement(kh->CheckMovement(), HitFlag, kh->CheckDirection());
	HitFlag = 0;
	// ++ COLLISION OF MOVEMENT ACTION

	// ++ COLLISION CHECK FOR JUMP ACTION
	Middle = MV1CollCheck_Line(model_Stage, -1, VGet(ph->Position.x, ph->Position.y, ph->Position.z), VGet(ph->Position.x, ph->Position.y + ph->Radius, ph->Position.z));
	if (Middle.HitFlag == 1)		HitFlag = 1;
	N = MV1CollCheck_Line(model_Stage, -1, VGet(ph->A1.x, ph->Position.y, ph->A1.z), VGet(ph->A2.x, ph->Position.y, ph->A2.z));		if (N.HitFlag == 1)		HitFlag = 1;
	E = MV1CollCheck_Line(model_Stage, -1, VGet(ph->A2.x, ph->Position.y, ph->A2.z), VGet(ph->A3.x, ph->Position.y, ph->A3.z));		if (E.HitFlag == 1)		HitFlag = 1;
	S = MV1CollCheck_Line(model_Stage, -1, VGet(ph->A3.x, ph->Position.y, ph->A3.z), VGet(ph->A4.x, ph->Position.y, ph->A4.z));		if (S.HitFlag == 1)		HitFlag = 1;
	W = MV1CollCheck_Line(model_Stage, -1, VGet(ph->A4.x, ph->Position.y, ph->A4.z), VGet(ph->A1.x, ph->Position.y, ph->A1.z));	if (W.HitFlag == 1)	HitFlag = 1;
	ph->PlayerUpdateJump(kh->CheckJump(), HitFlag);
	HitFlag = 0;
	// ++ COLLISION OF JUMP ACTION

	// ++ COLLISION CHECK FOR ATTACK ACTION
	if (ph->PlayerUpdateAction1(kh->CheckAttack(ph->ItemFlag)) == 1) // ++ kh->CheckAttack(ph->ItemFlag)) change CODE !
	{
		if (ph->ItemFlag == 1)
			PlaySoundMem(snd_Attack1, DX_PLAYTYPE_BACK);
		else
			PlaySoundMem(snd_Attack2, DX_PLAYTYPE_BACK);

		if (ph->ItemFlag == 1) // ATTACK TO BOSS
		{
			AttackToEnemy = MV1CollCheck_Sphere(bh->Model[bh->BossNumber], -1, ph->AR1, 800.f);
			if (AttackToEnemy.HitNum >= 1 && bh->EnemyType == 1)	bh->DamageFlag = 1;
		}
		else
		{
			AttackToEnemy = MV1CollCheck_Sphere(bh->Model[bh->BossNumber], -1, ph->AR1, 1600.f);
			if (AttackToEnemy.HitNum >= 1 && bh->EnemyType == 2)	bh->DamageFlag = 1;
		}
		MV1CollResultPolyDimTerminate(AttackToEnemy);
	}
	// ++ COLLISION OF ATTACK ACTION

	// ++ UPDATE PLAYER WEAPON
	ph->PlayerUpdateChangeWeapon(kh->CheckChangeWeapon());
	// ++ UPDATE PLAYER WEAPON

	// ++  PLAYER DAMAGE PATTERNS
	if (ph->DamageIntervalCount == 0)
	{
		if (ph->Position.y <= -100.f) // IF PLAYER IS OUTSIDE THE STAGE MODEL
		{
			ph->Life--;	ph->DamageIntervalCount++;
		}
		if (ph->EnemyFlag == 1) // IF PLAYER IS ATTACK BY ENEMY
		{
			PlaySoundMem(snd_Damaged, DX_PLAYTYPE_BACK);
			ph->Life--;	ph->DamageIntervalCount++;	ph->EnemyFlag = 0;
		}
	}
	else // DAMAGE INTERVAL
	{
		ph->DamageIntervalCount++;	if (ph->DamageIntervalCount == 60)		ph->DamageIntervalCount = 0;	ph->EnemyFlag = 0;
	}
	// ++ PLAYER DAMAGE PATTERNS

	////////////////////////////////////////////// BOSS UPDATE
	// ++ movement
	bh->BossMovement(ph->Position);
	// ++ movement

		// ++ damaged
	if (bh->DamageIntervalCount == 0)
	{
		if ((bh->DamageFlag == 1))
		{
			bh->Life--;
			if (bh->BossUpdate() == 1)
			{
				ph->Score += 150 * ph->Life;		ph->Life = 5; RoundNo++;
				ph->Score += (300 - CurrentTime) * 2; StartTime = GetNowCount(); CurrentTime = 0;

			}
			bh->DamageIntervalCount++;		bh->DamageFlag = 0;
		}
	}
	else
	{
		bh->DamageIntervalCount++;			if (bh->DamageIntervalCount == 30)	bh->DamageIntervalCount = 0; bh->DamageFlag = 0;
	}
	// ++ damaged

	// ++ when touched
	BossCol = MV1CollCheck_Sphere(bh->Model[bh->BossNumber], -1, VGet(ph->Position.x, ph->Position.y + 100, ph->Position.z), 120.f);
	if (BossCol.HitNum >= 1)		ph->EnemyFlag = 1;
	MV1CollResultPolyDimTerminate(BossCol);
	BossCol = MV1CollCheck_Sphere(bh->Model[bh->BossNumber], -1, VGet(ph->Position.x, ph->Position.y + 300, ph->Position.z), 120.f);
	if (BossCol.HitNum >= 1)		ph->EnemyFlag = 1;
	MV1CollResultPolyDimTerminate(BossCol);
	// ++ when touched

	// ++ Attack
	bh->BossAction();
	for (int i = 0; i < 4; i++)
	{
		BossCol = MV1CollCheck_Sphere(ph->Model, -1, VGet(bh->ATTACK[i].x, bh->ATTACK[i].y, bh->ATTACK[i].z), 250.f);
		if (BossCol.HitNum >= 1)		ph->EnemyFlag = 1;
		MV1CollResultPolyDimTerminate(BossCol);
	}
	// ++ Attack

	///////////////////////////////////////////////////////////////////////////////////////////////////////////// SYSTEM UPDATE
	// ++ CALL GAME OVER
	if (ph->Life == 0)
		return -1;
	// ++ CALL GAME OVER

	// ++ IF EXIT
	if (kh->CheckEscapeGame() == 1) { StopSoundMem(snd_StageTheme);		return 2; }
	// ++ IF EXIT

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// SCREEN UPDATE
	// ++ DRAW ALL
	ph->PlayerDraw();
	bh->BossDraw();
	MV1DrawModel(model_Stage);


	ph->PlayerStatusDrawForBossRush(syscon.screensizeX, syscon.screensizeY, HighScore, RoundNo, CurrentTime);
	bh->BossStatusDraw();





	return 0; // CONTINUE LOOPING
}

int BossRushManager::BossRushGameOver(void)
{
	StopSoundMem(snd_StageTheme);
	if (CheckSoundMem(snd_GameOver) != 1)
		if (endOver == 0)
		{
			PlaySoundMem(snd_GameOver, DX_PLAYTYPE_BACK, TRUE);
			endOver = 1;
			//++ Insert Arrange Ranking System
			int a[7];
			a[0] = 0;
			a[1] = ph->Score;
			a[2] = rank.TopScore[0];
			a[3] = rank.TopScore[1];
			a[4] = rank.TopScore[2];
			a[5] = rank.TopScore[3];
			a[6] = rank.TopScore[4];


			int b[7];
			for (int i = 0; i < 7; i++)
				b[i] = 1;
			for (int i = 2; i <= 6; i++)
			{
				for (int j = 1; j <= i - 1; j++)
				{
					if (a[j] < a[i])	b[j]++;
					if (a[j] >= a[i])	b[i]++;
				}
			}
			for (int i = 1; i <= 6; i++)
			{

				switch (b[i])
				{
				case 1:
					rank.TopScore[0] = a[i];
					// round
					break;
				case 2:
					rank.TopScore[1] = a[i];
					// round
					break;
				case 3:
					rank.TopScore[2] = a[i];
					// round
					break;
				case 4:
					rank.TopScore[3] = a[i];
					// round
					break;
				case 5:
					rank.TopScore[4] = a[i];
					// round
					break;
				}
			}

			FILE *write = fopen("SysDat04.dat", "wb");
			fwrite(&rank, sizeof(rank), 1, write);
			fclose(write);
			// ++ Insert Arrange Ranking System
		}
		else return -1;
		int sx, sy;
		sx = 400 / 2;
		sy = 300 / 2;
		ph->PlayerDraw();
		MV1DrawModel(model_Stage);
		DrawGraph(sx, sy, img_GameOver, TRUE);

		if (HighScore < ph->Score)
			HighScore = ph->Score;
		DrawFormatStringToHandle(sx + 2, sy + GO_Y + 2, BC_BLACK, FontScore, "HIGH SCORE: %d", HighScore);
		DrawFormatStringToHandle(sx, sy + GO_Y, BC_BROWN, FontScore, "HIGH SCORE: %d", HighScore);
		DrawFormatStringToHandle(sx + 2, sy + GO_Y + 2 + 40, BC_BLACK, FontScore, "SCORE: %d", ph->Score);
		DrawFormatStringToHandle(sx, sy + GO_Y + 40, BC_BROWN, FontScore, "SCORE: %d", ph->Score);
		return 0;

}


void BossRushManager::ReleaseData(void)
{
	DeleteSoundMem(snd_StageTheme);
	DeleteSoundMem(snd_Damaged);
	DeleteSoundMem(snd_Attack1);
	DeleteSoundMem(snd_Attack2);
	DeleteSoundMem(snd_GameOver);
	DeleteSoundMem(snd_NewStage);
	DeleteGraph(img_NewStage);
	DeleteGraph(img_GameOver);
	DeleteFontToHandle(FontScore);
	ph->ReleaseData();
	bh->ReleaseData();
	HighScore = 0;
	RoundNo = 0;
	StageNew = 0;
	endOver = 0;
}

int BossRushManager::BossRushStart(void)
{
	if (CheckSoundMem(snd_NewStage) != 1)
		if (StageNew == 0)
		{
			PlaySoundMem(snd_NewStage, DX_PLAYTYPE_BACK, TRUE);
			StageNew = 1;
		}
		else StageNew = 2;
		if (StageNew == 1)
		{
			int sx, sy;
			sx = 400 / 2;
			sy = 300 / 2;
			ph->PlayerDraw();
			MV1DrawModel(model_Stage);

			DrawGraph(sx, sy, img_NewStage, TRUE);
		}
		return 0;

}
