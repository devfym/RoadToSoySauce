#include "StoryManager.h"
#include "K_KinectHandler.h"
#include "PlayerHandler.h"
#include "EnemyHandler.h"
#include "BossHandler.h"
#include "StageHandler.h"
#include "ObjectHandler.h"
#include "F_LoadingScreen.h"
StoryManager::StoryManager(K_KinectHandler *m_kh)
{
	kh = m_kh;
	ph = new PlayerHandler();

	for (int i = 0; i < 5; i++)
		eh[i] = new EnemyHandler();

	bh = new BossHandler();

	sh = new StageHandler();
	for (int i = 0; i < 3;i++)
		oh[i] = new ObjectHandler(); // TEST GARLIC

	fls = new F_LoadingScreen();
	snd_StoryTelling = LoadSoundMem(BGM_STORY);
	InitializeFlag = 0;
}


StoryManager::~StoryManager(void)
{

}

void StoryManager::StoryLoad(int SaveNumber)
{
	if (InitializeFlag == 1)
		// 1st loop
	{
		// - Read System Config  -//
		FILE *fgi = fopen("SysDat01.dat", "rb");
		if (fgi != NULL)
		{
			fread(&syscon, sizeof(syscon), 1, fgi);
		}
		fclose(fgi);

		// LOAD SAVE DATA FILE
		SaveDataLoad(SaveNumber);

		currentStage = sd.CurrentStage;
		currentArea = sd.CurrentArea;
		currentAreaOld = sd.CurrentAreaOld;
	}
	//////////
	if (InitializeFlag == 11)
		// 3rd loop
	{
		// SOUNDS INIT
		snd_GameOver = LoadSoundMem(BGM_GAMEOVER);
		snd_NewStage = LoadSoundMem(BGM_NEWSTAGE);

	}
	if (InitializeFlag == 21)
	{
		snd_GetItem1 = LoadSoundMem(SE_GETITEM1);
		snd_GetItem2 = LoadSoundMem(SE_GETITEM2);
	}
	if (InitializeFlag == 31)
	{
		snd_Damaged = LoadSoundMem(SE_DAMAGED);
		snd_Attack1 = LoadSoundMem(SE_ATTACK1);
		snd_Attack2 = LoadSoundMem(SE_ATTACK2);
	}
	/////////
	if (InitializeFlag == 41)
		// 4th loop
	{
		img_GameOver = LoadGraph(GAMEOVER);
		img_PBorder = LoadGraph(PAUSE_BORDER);
		img_PContinue = LoadGraph(PAUSE_CONTINUE);
		img_PExit = LoadGraph(PAUSE_EXIT);
		FontScore = CreateFontToHandle(NULL, 30, -1, DX_FONTTYPE_NORMAL);
	}
	//////////
	if (InitializeFlag == 51)
		// 5th loop
	{
		switch (currentStage)
		{
		case 1:
			if (currentArea != Stage1BossArea)
				snd_StageTheme = LoadSoundMem(BGM_STAGE1);
			else
				snd_StageTheme = LoadSoundMem(BGM_BOSS);
			break;
		case 2:
			if (currentArea != Stage2BossArea)
				snd_StageTheme = LoadSoundMem(BGM_STAGE2);
			else
				snd_StageTheme = LoadSoundMem(BGM_BOSS);
			break;
		case 3:
			if (currentArea != Stage3BossArea)
				snd_StageTheme = LoadSoundMem(BGM_STAGE3);
			else
				snd_StageTheme = LoadSoundMem(BGM_BOSS);
			break;
		case 4:
			if (currentArea != Stage4BossArea)
				snd_StageTheme = LoadSoundMem(BGM_STAGE4);
			else
				snd_StageTheme = LoadSoundMem(BGM_BOSS);
			break;
		case 5:
			if (currentArea != Stage5BossArea)
				snd_StageTheme = LoadSoundMem(BGM_STAGE5);
			else
				snd_StageTheme = LoadSoundMem(BGM_BOSS);
			break;
		}
	}
	//////////
	if (InitializeFlag == 61)
		// 6th loop
	{
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_GameOver);
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_StageTheme);
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_NewStage);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_GetItem1);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_GetItem2);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Damaged);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Attack1);
		ChangeVolumeSoundMem(syscon.VolumeSE, snd_Attack2);
		ChangeVolumeSoundMem(syscon.VolumeBGM, snd_StoryTelling);
	}
	/////////
	if (InitializeFlag == 71)
		// 7th loop
	{
		sh->StageInitialization(sd);
	}
	///////
	if (InitializeFlag == 81)
		// 8th loop
	{
		ph->PlayerInitialization(syscon.VolumeSE, sh->playerDirection, sh->playerCount, sh->playerAngle, sh->playerPosition, sh->playerCamera, sd); ///////
	}
	////////
	if (InitializeFlag == 91)
		// 9th loop
	{
		for (int i = 0;i < 3;i++)
			oh[i]->ObjectInitialization(sd, i + 1);
	}
	///////
	if (InitializeFlag == 101)
	{
		eh[0]->EnemyInitialization(sd.CurrentStage, sd.CurrentArea, 0);
		bh->BossInitialization(sd);
	}
	if (InitializeFlag == 111)
	{
		eh[1]->EnemyInitialization(sd.CurrentStage, sd.CurrentArea, 1);
	}
	if (InitializeFlag == 121)
	{
		eh[2]->EnemyInitialization(sd.CurrentStage, sd.CurrentArea, 2);
	}
	if (InitializeFlag == 131)
	{
		eh[3]->EnemyInitialization(sd.CurrentStage, sd.CurrentArea, 3);
	}
	if (InitializeFlag == 141)
	{
		eh[4]->EnemyInitialization(sd.CurrentStage, sd.CurrentArea, 4);
	}
	//////
	if (InitializeFlag == 151)
		// 11th loop
	{
		HitFlag = 0;
		endOver = 0;
		StageNew = 0;
		//////////// set up coll info
		MV1SetupCollInfo(ph->Model, -1, 8, 8, 8);
		MV1SetupCollInfo(sh->Model, -1, 8, 8, 8);
		for (int i = 0; i < 5; i++)
			MV1SetupCollInfo(eh[i]->Model, -1, 8, 8, 8);
		MV1SetupCollInfo(bh->Model, -1, 8, 8, 8);
		///////////
	}
	//////

}

int StoryManager::StoryLoop(void)
{
	if (CheckSoundMem(snd_StageTheme) != 1)
		PlaySoundMem(snd_StageTheme, DX_PLAYTYPE_LOOP, TRUE);

	/////////////////// COLLISION UPDATE
	MV1RefreshCollInfo(ph->Model, -1);
	MV1RefreshCollInfo(sh->Model, -1);
	for (int i = 0;i < 5; i++)
		MV1RefreshCollInfo(eh[i]->Model, -1);
	MV1RefreshCollInfo(bh->Model, -1);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// PLAYER UPDATE

	// ++ COLLISION CHECK FOR  MOVEMENT ACTION
	N = MV1CollCheck_Line(sh->Model, -1, ph->A1, ph->A2);		if (N.HitFlag == 1)		HitFlag = 1;
	E = MV1CollCheck_Line(sh->Model, -1, ph->A2, ph->A3);		if (E.HitFlag == 1)		HitFlag = 1;
	S = MV1CollCheck_Line(sh->Model, -1, ph->A3, ph->A4);		if (S.HitFlag == 1)		HitFlag = 1;
	W = MV1CollCheck_Line(sh->Model, -1, ph->A4, ph->A1);	if (W.HitFlag == 1)	HitFlag = 1;
	ph->PlayerUpdateMovement(kh->CheckMovement(), HitFlag, kh->CheckDirection());
	HitFlag = 0;
	// ++ COLLISION OF MOVEMENT ACTION

	// ++ COLLISION CHECK FOR JUMP ACTION
	Middle = MV1CollCheck_Line(sh->Model, -1, VGet(ph->Position.x, ph->Position.y, ph->Position.z), VGet(ph->Position.x, ph->Position.y + ph->Radius, ph->Position.z));
	if (Middle.HitFlag == 1)		HitFlag = 1;
	N = MV1CollCheck_Line(sh->Model, -1, VGet(ph->A1.x, ph->Position.y, ph->A1.z), VGet(ph->A2.x, ph->Position.y, ph->A2.z));		if (N.HitFlag == 1)		HitFlag = 1;
	E = MV1CollCheck_Line(sh->Model, -1, VGet(ph->A2.x, ph->Position.y, ph->A2.z), VGet(ph->A3.x, ph->Position.y, ph->A3.z));		if (E.HitFlag == 1)		HitFlag = 1;
	S = MV1CollCheck_Line(sh->Model, -1, VGet(ph->A3.x, ph->Position.y, ph->A3.z), VGet(ph->A4.x, ph->Position.y, ph->A4.z));		if (S.HitFlag == 1)		HitFlag = 1;
	W = MV1CollCheck_Line(sh->Model, -1, VGet(ph->A4.x, ph->Position.y, ph->A4.z), VGet(ph->A1.x, ph->Position.y, ph->A1.z));		if (W.HitFlag == 1)		HitFlag = 1;
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
			AttackToEnemy = MV1CollCheck_Sphere(bh->Model, -1, ph->AR1, 800.f);
			if (AttackToEnemy.HitNum >= 1 && bh->EnemyType == 1)	bh->DamageFlag = 1;
		}
		else
		{
			AttackToEnemy = MV1CollCheck_Sphere(bh->Model, -1, ph->AR1, 1600.f);
			if (AttackToEnemy.HitNum >= 1 && bh->EnemyType == 2)	bh->DamageFlag = 1;
		}
		MV1CollResultPolyDimTerminate(AttackToEnemy);

		for (int i = 0;i < 5;i++) // ATTACK TO ENEMY
		{
			if (ph->ItemFlag == 1) // attack pattern for land type
			{
				AttackToEnemy = MV1CollCheck_Sphere(eh[i]->Model, -1, ph->AR1, 800.f);
				if (AttackToEnemy.HitNum >= 1 && eh[i]->EnemyType == 1)	eh[i]->DamageFlag = 1;
			}
			else // attack pattern for fly type
			{
				AttackToEnemy = MV1CollCheck_Sphere(eh[i]->Model, -1, ph->AR1, 1600.f);
				if (AttackToEnemy.HitNum >= 1 && eh[i]->EnemyType == 2)	eh[i]->DamageFlag = 1;
			}
			MV1CollResultPolyDimTerminate(AttackToEnemy);
		}
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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// STAGE UPDATE

	// ++ UPDATE STAGE INFO
	sh->StageFlag();
	// ++ UPDATE STAGE INFO

	// ++ COLLISION CHECK FOR AREA END
	AreaEnd = MV1CollCheck_Line(ph->Model, -1, sh->AreaEnd1, sh->AreaEnd2);
	if (AreaEnd.HitFlag == 1)
	{
		InitializeFlag = 0;
		currentAreaOld = currentArea;
		currentArea += 1;
		StopSoundMem(snd_StageTheme);
		return 1;
	}
	// ++ COLLISION OF AREA END

	// ++ COLLISION CHECK FOR AREA BACK
	AreaBack = MV1CollCheck_Line(ph->Model, -1, sh->AreaBack1, sh->AreaBack2);
	if (AreaBack.HitFlag == 1)
	{
		InitializeFlag = 0;
		currentAreaOld = currentArea;
		currentArea -= 1;
		StopSoundMem(snd_StageTheme);
		return 1;
	}
	// ++ COLLISION OF AREA BACK

	// ++ COLLISION CHECK FOR NEXT STAGE
	NextStage = MV1CollCheck_Line(ph->Model, -1, sh->NextStage1, sh->NextStage2);
	if (NextStage.HitFlag == 1)
	{
		InitializeFlag = 0;
		currentAreaOld = 0;
		currentArea = 1;
		currentStage += 1;
		StopSoundMem(snd_StageTheme);
		return 1;

	}
	// ++ COLLISION OF NEXT STAGE

	//////////////////////////////////////////////////////////////////////////////////////////////////////	ENEMY UPDATE

	// ++ MOVEMENT: SEARCH PLAYER LOCATION
	for (int i = 0;i < 5;i++)
		if (eh[i]->SearchPlayer(ph->Position) == 1)	eh[i]->EnemyMove(ph->Position);
	// ++ MOVEMENT: SEARCH PLAYER LOCATION

	// ++  LIFE: ENEMY DAMAGED PATTERNS
	for (int i = 0; i < 5; i++)
	{
		if (eh[i]->DamageIntervalCount == 0)
		{
			if ((eh[i]->DamageFlag == 1) && (eh[i]->Exist == 1))
			{
				eh[i]->Life--;
				if (eh[i]->EnemyCheck() == 1) { ph->EnemyDefeated[eh[i]->EnemyID] += 1;		ph->Score += 200; }
				eh[i]->DamageIntervalCount++;		eh[i]->DamageFlag = 0;
			}
		}
		else
		{
			eh[i]->DamageIntervalCount++;			if (eh[i]->DamageIntervalCount == 20)	eh[i]->DamageIntervalCount = 0;	eh[i]->DamageFlag = 0;
		}
	}
	// ++ LIFE: ENEMY DAMAGED PATTERNS

	// ++  ATTACK : COLLISION CHECK FOR ENEMY
	for (int i = 0; i < 5;i++)
	{
		if (eh[i]->Exist == 1)
		{
			EnemyCol[i] = MV1CollCheck_Sphere(ph->Model, -1, eh[i]->Position, 450.f);
			if (EnemyCol[i].HitNum >= 1)		ph->EnemyFlag = 1;
			MV1CollResultPolyDimTerminate(EnemyCol[i]);
		}
	}
	// ++ ATTACK : COLLISION OF ENEMY

	///////////////////////////////////////////////////////////////////////////////////////////////////// BOSS UPDATE
	// ++ Boss Update
	bh->BossUpdate(sh->StageBossDefeated[currentStage - 1]);
	// ++ Boss Update

	// movement
	bh->BossMovement();

	// ++ damaged
	if (bh->DamageIntervalCount == 0)
	{
		if ((bh->DamageFlag == 1) && (bh->Exist == 1))
		{
			bh->Life--;
			if (bh->CheckExist() == 1) { sh->StageBossDefeated[currentStage - 1] = 1;		ph->Score += 1500;StopSoundMem(snd_StageTheme); }
			bh->DamageIntervalCount++;		bh->DamageFlag = 0;
		}
	}
	else
	{
		bh->DamageIntervalCount++;			if (bh->DamageIntervalCount == 30)	bh->DamageIntervalCount = 0; bh->DamageFlag = 0;
	}
	// ++ damaged

	// attack

	// collision of boss body
	if (bh->Exist == 1)
	{
		BossCol = MV1CollCheck_Sphere(ph->Model, -1, VGet(bh->Position.x, bh->Position.y + 400, bh->Position.z), 450.f);
		if (BossCol.HitNum >= 1)		ph->EnemyFlag = 1;
		MV1CollResultPolyDimTerminate(BossCol);
	}
	// ++ collision of body

	// attack update
	bh->BossAction();
	if (bh->Exist == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			BossCol = MV1CollCheck_Sphere(ph->Model, -1, VGet(bh->ATTACK[i].x, bh->ATTACK[i].y, bh->ATTACK[i].z), 250.f);
			if (BossCol.HitNum >= 1)		ph->EnemyFlag = 1;
			MV1CollResultPolyDimTerminate(BossCol);
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////// OBJECT UPDATE

	// ++ Object Update
	oh[2]->ObjectUpdate(sh->StageBossDefeated[currentStage - 1], sh->StageKeys[currentStage - 1]);
	// ++ Object Update

	//// COLLISION CHECK FOR OBJECTS
	for (int i = 0;i < 3;i++)
	{

		if (oh[i]->Exist == 1)
		{
			ObjCol[i] = MV1CollCheck_Sphere(ph->Model, -1, oh[i]->Position, 200.0f);
			if (ObjCol[i].HitNum >= 1)
			{
				switch (oh[i]->ObjectTouched())
				{
				case 1:
					if (ph->Life < 5) { PlaySoundMem(snd_GetItem1, DX_PLAYTYPE_BACK, TRUE);	ph->Life++; }
					else					oh[i]->Exist = 1;
					break;

				case 2:
					PlaySoundMem(snd_GetItem2, DX_PLAYTYPE_BACK, TRUE);	ph->Score += 1000;
					break;

				case 3:
					PlaySoundMem(snd_GetItem1, DX_PLAYTYPE_BACK, TRUE);
					switch (currentStage)
					{
					case 1:
						sh->StageKeys[0] ++;
						if (sh->StageKeys[0] == 3)		sh->StageGoNextFlag[0] = 1;
						break;
					case 2:
						sh->StageKeys[1]++;
						if (sh->StageKeys[1] == 3)
						{
							InitializeFlag = 0;		currentAreaOld = 3;		currentArea = 4;		currentStage = 2;
							StopSoundMem(snd_StageTheme);				return 1;
						}
						if (sh->StageKeys[1] == 4)		sh->StageGoNextFlag[1] = 1;

						break;
					case 3:
						sh->StageKeys[2]++;
						if (sh->StageKeys[2] == 3)
						{
							InitializeFlag = 0;		currentAreaOld = 3;		currentArea = 4;		currentStage = 3;
							StopSoundMem(snd_StageTheme);				return 1;
						}
						if (sh->StageKeys[2] == 4)		sh->StageGoNextFlag[2] = 1;
						break;
					case 4:
						sh->StageKeys[3]++;
						if (sh->StageKeys[3] == 3)
						{
							InitializeFlag = 0;		currentAreaOld = 3;		currentArea = 4;		currentStage = 4;
							StopSoundMem(snd_StageTheme);				return 1;
						}
						if (sh->StageKeys[3] == 4)		sh->StageGoNextFlag[3] = 1;
						break;
					case 5:
						sh->StageKeys[4]++;
						if (sh->StageKeys[4] == 3)
						{
							InitializeFlag = 0;		currentAreaOld = 3;		currentArea = 4;		currentStage = 5;
							StopSoundMem(snd_StageTheme);				return 1;
						}
						if (sh->StageKeys[4] == 4)
						{
							sh->StageGoNextFlag[4] = 1;
							StopSoundMem(snd_StageTheme);
							return 4;
							// CALL GAME CLEAR FUNCTION set all to free
						}
						break;
					} // ++ KEY PROPERTY
					break;
				}		// ++ OBJ TOUCHED
			} // ++ HIT COLLISION OBJ
			MV1CollResultPolyDimTerminate(ObjCol[i]);
		} // if Obj exist
	}// loop end
	// ++ COLLISION OF OBJECT

	///////////////////////////////////////////////////////////////////////////////////////////////////////////// SYSTEM UPDATE
	// ++ CALL GAME OVER
	if (ph->Life == 0)
		return -1;
	// ++ CALL GAME OVER

	// ++ IF EXIT
	if (kh->CheckEscapeGame() == 1) { StopSoundMem(snd_StageTheme);		return 2; }
	// ++ IF EXIT

	// ++ IF PAUSED
	else if (kh->CheckEscapeGame() == 2) { StopSoundMem(snd_StageTheme);		return 3; }
	// ++ IF PAUSED



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// SCREEN UPDATE
	// ++ DRAW ALL
	ph->PlayerDraw();
	for (int i = 0;i < 3;i++)
		oh[i]->ObjectDraw();
	for (int i = 0;i < 5;i++)
		eh[i]->EnemyDraw();
	bh->BossDraw();
	sh->StageDraw();
	ph->PlayerStatusDraw(syscon.screensizeX, syscon.screensizeY);
	bh->BossStatusDraw();

	DrawLine3D(sh->AreaEnd1, sh->AreaEnd2, BC_WHITE);
	DrawLine3D(sh->AreaBack1, sh->AreaBack2, BC_WHITE);
	DrawLine3D(sh->NextStage1, sh->NextStage2, BC_WHITE);
	// ++ DRAW ALL

	return 0; // CONTINUE LOOPING
}

int StoryManager::GameOver(void)
{
	StopSoundMem(snd_StageTheme);
	if (CheckSoundMem(snd_GameOver) != 1)
		if (endOver == 0)
		{
			PlaySoundMem(snd_GameOver, DX_PLAYTYPE_BACK, TRUE);
			currentStage = 1;
			currentArea = 1;
			currentAreaOld = 0;
			endOver = 1;
		}
		else return -1;
		int sx, sy;
		sx = 400 / 2;
		sy = 300 / 2;
		ph->PlayerDraw();
		sh->StageDraw();
		DrawGraph(sx, sy, img_GameOver, TRUE);
		DrawFormatStringToHandle(sx + 2, sy + GO_Y + 2, BC_BLACK, FontScore, "SCORE = %d", ph->Score);
		DrawFormatStringToHandle(sx, sy + GO_Y, BC_BROWN, FontScore, "SCORE = %d", ph->Score);
		return 0;
}

int StoryManager::StageBegin(void)
{
	// ++ IF ALREADY CLEARED
	if (sh->StageGoNextFlag[4] == 1)
	{
		StopSoundMem(snd_StageTheme);
		return 1;
	}
	// ++ IF ALREADY CLEARED


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
			sh->StageDraw();
			switch (currentStage)
			{
			case 1:
				if (currentArea == 1)				img_NewStage = LoadGraph(GUI_ST1AR1);
				else if (currentArea == 2)		img_NewStage = LoadGraph(GUI_ST1AR2);
				else if (currentArea == 3)		img_NewStage = LoadGraph(GUI_ST1AR3);
				break;
			case 2:
				if (currentArea == 1)				img_NewStage = LoadGraph(GUI_ST2AR1);
				else if (currentArea == 2)		img_NewStage = LoadGraph(GUI_ST2AR2);
				else if (currentArea == 3)		img_NewStage = LoadGraph(GUI_ST2AR3);
				else if (currentArea == 4)		img_NewStage = LoadGraph(GUI_ST2AR4);
				break;
			case 3:
				if (currentArea == 1)				img_NewStage = LoadGraph(GUI_ST3AR1);
				else if (currentArea == 2)		img_NewStage = LoadGraph(GUI_ST3AR2);
				else if (currentArea == 3)		img_NewStage = LoadGraph(GUI_ST3AR3);
				else if (currentArea == 4)		img_NewStage = LoadGraph(GUI_ST3AR4);
				break;
			case 4:
				if (currentArea == 1)				img_NewStage = LoadGraph(GUI_ST4AR1);
				else if (currentArea == 2)		img_NewStage = LoadGraph(GUI_ST4AR2);
				else if (currentArea == 3)		img_NewStage = LoadGraph(GUI_ST4AR3);
				else if (currentArea == 4)		img_NewStage = LoadGraph(GUI_ST4AR4);
				break;
			case 5:
				if (currentArea == 1)				img_NewStage = LoadGraph(GUI_ST5AR1);
				else if (currentArea == 2)		img_NewStage = LoadGraph(GUI_ST5AR2);
				else if (currentArea == 3)		img_NewStage = LoadGraph(GUI_ST5AR3);
				else if (currentArea == 4)		img_NewStage = LoadGraph(GUI_ST5AR4);
				break;
			}
			DrawGraph(sx, sy, img_NewStage, TRUE);
		}
		return 0;
}

void StoryManager::SaveDataLoad(int SaveNumber)
{
	if (SaveNumber == 1)
	{
		FILE *fgi1 = fopen("SaveData01.sav", "rb");
		if (fgi1 != NULL)
		{
			fread(&sd, sizeof(sd), 1, fgi1);
		}
		fclose(fgi1);
	}
	else if (SaveNumber == 2)
	{
		FILE *fgi2 = fopen("SaveData02.sav", "rb");
		if (fgi2 != NULL)
		{
			fread(&sd, sizeof(sd), 1, fgi2);
		}
		fclose(fgi2);
	}
	else if (SaveNumber == 3)
	{
		FILE *fgi3 = fopen("SaveData03.sav", "rb");
		if (fgi3 != NULL)
		{
			fread(&sd, sizeof(sd), 1, fgi3);
		}
		fclose(fgi3);
	}
	else if (SaveNumber == 4)
	{
		FILE *fgi4 = fopen("SaveData04.sav", "rb");
		if (fgi4 != NULL)
		{
			fread(&sd, sizeof(sd), 1, fgi4);
		}
		fclose(fgi4);
	}
	else if (SaveNumber == 5)
	{
		FILE *fgi5 = fopen("SaveData05.sav", "rb");
		if (fgi5 != NULL)
		{
			fread(&sd, sizeof(sd), 1, fgi5);
		}
		fclose(fgi5);
	}
}

void StoryManager::SaveDataSave(int SaveNumber)
{
	sd.ModelFlag = ph->ModelFlag;
	sd.Life = ph->Life;
	sd.ItemFlag = ph->ItemFlag;
	sd.Score = ph->Score;
	for (int i = 0; i < 5; i++)
	{
		sd.StageBossFlag[i] = sh->StageBossDefeated[i];
		sd.StageNextFlag[i] = sh->StageGoNextFlag[i];
		sd.StageKeys[i] = sh->StageKeys[i];
	}
	for (int i = 0; i < 17; i++)
	{
		sd.EnemyDefeatedNumber[i] = ph->EnemyDefeated[i];
	}
	sd.CurrentStage = currentStage;
	sd.CurrentArea = currentArea;
	sd.CurrentAreaOld = currentAreaOld;

	if (SaveNumber == 1)
	{
		FILE *fp1 = fopen("SaveData01.sav", "wb");
		fwrite(&sd, sizeof(sd), 1, fp1);
		fclose(fp1);
	}
	else if (SaveNumber == 2)
	{
		FILE *fp2 = fopen("SaveData02.sav", "wb");
		fwrite(&sd, sizeof(sd), 1, fp2);
		fclose(fp2);
	}
	else if (SaveNumber == 3)
	{
		FILE *fp3 = fopen("SaveData03.sav", "wb");
		fwrite(&sd, sizeof(sd), 1, fp3);
		fclose(fp3);
	}
	else if (SaveNumber == 4)
	{
		FILE *fp4 = fopen("SaveData04.sav", "wb");
		fwrite(&sd, sizeof(sd), 1, fp4);
		fclose(fp4);
	}
	else if (SaveNumber == 5)
	{
		FILE *fp5 = fopen("SaveData05.sav", "wb");
		fwrite(&sd, sizeof(sd), 1, fp5);
		fclose(fp5);
	}
}

void StoryManager::ReleaseData()
{
	DeleteGraph(img_GameOver);
	DeleteSoundMem(snd_GameOver);
	DeleteGraph(img_NewStage);
	DeleteSoundMem(snd_NewStage);
	DeleteSoundMem(snd_StageTheme);
	DeleteSoundMem(snd_GetItem1);
	DeleteSoundMem(snd_GetItem2);
	DeleteSoundMem(snd_Damaged);
	DeleteSoundMem(snd_Attack1);
	DeleteSoundMem(snd_Attack2);
	//DeleteSoundMem(snd_StoryTelling);
	DeleteFontToHandle(FontScore);
	DeleteGraph(img_PBorder);
	DeleteGraph(img_PContinue);
	DeleteGraph(img_PExit);
	currentStage = 0;
	currentArea = 0;
	currentAreaOld = 0;
	HitFlag = 0;
	endOver = 0;

	ph->ReleaseData();
	sh->ReleaseData();
	for (int i = 0; i < 3; i++)
		oh[i]->ReleaseData();
	for (int i = 0; i < 5; i++)
		eh[i]->ReleaseData();
	bh->ReleaseData();
}

void StoryManager::WhilePause(void)
{

	ph->PlayerDraw();
	for (int i = 0;i < 3;i++)
		oh[i]->ObjectDraw();
	for (int i = 0;i < 5;i++)
		eh[i]->EnemyDraw();
	bh->BossDraw();
	sh->StageDraw();
	ph->PlayerStatusDraw(syscon.screensizeX, syscon.screensizeY);
	DrawGraph(0, 0, img_PContinue, TRUE);
	DrawGraph(400, 0, img_PExit, TRUE);
	DrawGraph(399, 0, img_PBorder, TRUE);
}

int StoryManager::ActionWhilePause(int cx, int cy, int cf)
{
	if ((cx > 400 && cx < 800) && (cy > 0 && cy < 600) && cf == 1)
		return 2;
	if ((cx > 0 && cx < 400) && (cy > 0 && cy < 600) && cf == 1)
		return 1;


	return 0;
}

int StoryManager::GameClear(int count) // text speed load here
{
	if (CheckSoundMem(snd_StoryTelling) != 1)
		PlaySoundMem(snd_StoryTelling, DX_PLAYTYPE_LOOP, TRUE);

	switch (fls->ProjectLoadScreen(syscon.screensizeX, syscon.screensizeY, syscon.TextSpeed))
	{
	case -1:
		if (count == 0)					fls->img_LoadScreen = LoadGraph(SCENE5); // change to story end dialogue
		else if (count == 1)		fls->img_LoadScreen = LoadGraph(SCENE6); // change to story end dialogue
		else if (count == 2)		fls->img_LoadScreen = LoadGraph(SCENE7); // change to story end dialogue
		else if (count == 3)		fls->img_LoadScreen = LoadGraph(SCENE8); // change to story end dialogue
		break;
	case 1:
		if (count == 3)
			StopSoundMem(snd_StoryTelling);
		return 1;
		break;
	}

	return 0;
}

int StoryManager::GameNew(int count) // text speed load here
{
	if (CheckSoundMem(snd_StoryTelling) != 1)
		PlaySoundMem(snd_StoryTelling, DX_PLAYTYPE_LOOP, TRUE);

	switch (fls->ProjectLoadScreen(syscon.screensizeX, syscon.screensizeY, syscon.TextSpeed))
	{
	case -1:
		if (count == 0)					fls->img_LoadScreen = LoadGraph(SCENE1); // change to story end dialogue
		else if (count == 1)		fls->img_LoadScreen = LoadGraph(SCENE2); // change to story end dialogue
		else if (count == 2)		fls->img_LoadScreen = LoadGraph(SCENE3); // change to story end dialogue
		else if (count == 3)		fls->img_LoadScreen = LoadGraph(SCENE4); // change to story end dialogue
		break;
	case 1:
		if (count == 3)
			StopSoundMem(snd_StoryTelling);
		return 1;
		break;
	}

	return 0;

}
