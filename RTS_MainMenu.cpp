#include "RTS_MainMenu.h"
#include <DxLib.h>


RTS_MainMenu::RTS_MainMenu(SystemConfiguration m_syscon)
{
	// - System Configuration LOAD - //
	syscon = m_syscon;

	// - MENU SELECT STATUS - //
	Status = SPLASH;

	// - Loading Screen Flag - //
	Wait = 1;

	//- Gallery Flags - //
	galFlag = -1, galLag = 0; galFade = 255;

	// Sounds Load - //
	snd_MainMenu = LoadSoundMem(BGM_MAINMENU);
	snd_Gallery = LoadSoundMem(BGM_GALLERY);
	snd_Option = LoadSoundMem(BGM_OPTION);
	snd_Select = LoadSoundMem(SE_SELECT);
	ChangeVolumeSoundMem(syscon.VolumeBGM, snd_MainMenu);
	ChangeVolumeSoundMem(syscon.VolumeBGM, snd_Gallery);
	ChangeVolumeSoundMem(syscon.VolumeBGM, snd_Option);
	ChangeVolumeSoundMem(syscon.VolumeSE, snd_Select);

}


RTS_MainMenu::~RTS_MainMenu(void)
{
	DeleteSoundMem(snd_MainMenu);
	DeleteSoundMem(snd_Gallery);
	DeleteSoundMem(snd_Option);
	DeleteSoundMem(snd_Select);
}

int RTS_MainMenu::CaseSplash(int count)
{
	switch (fls.ProjectLoadScreen(syscon.screensizeX, syscon.screensizeY, 130))
	{
	case -1:
		if (count == 0)					fls.img_LoadScreen = LoadGraph(G_SPLASHSCREEN);
		else if (count == 1)		fls.RandomFriendlyTips(1);
		else if (count == 2)		fls.RandomFriendlyTips(2);
		break;
	case 1:
		return 1;
		break;
	}
	return 0;
}

void RTS_MainMenu::CaseMainMenu(void)
{
	if (CheckSoundMem(snd_MainMenu) != 1)
		PlaySoundMem(snd_MainMenu, DX_PLAYTYPE_LOOP, TRUE);
	switch (rMM.ActionTaken(x, y, flag))
	{
	case 1:		Status = STORYMODE;					Wait = 0;
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		storyFlag = -1;																																	break;
	case 2:		Status = BOSSRUSH;					Wait = 0;
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		bossFlag = -1;																																	break;
	case 3:		Status = GALLERY;						rGL.UpdateGallery();	Wait = 0;
		StopSoundMem(snd_MainMenu);	PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		galLag = 0;									rGL.ReadData();																			break;
	case 4:		Status = OPTION;							Wait = 0;
		StopSoundMem(snd_MainMenu);	PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		rOP.loadFlag = 0;																																break;
	case 5:		Status = EXIT;									Wait = 0;
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																break;
	}
	rMM.LoadGraphs(syscon.screensizeX, syscon.screensizeY);
}

int RTS_MainMenu::CaseStoryMode(void)
{
	SetDrawBright(100, 100, 100);
	rMM.LoadGraphs(syscon.screensizeX, syscon.screensizeY);

	SetDrawBright(255, 255, 255);
	if (storyFlag == -1) // Choose New, Load, Ranking, or Cancel
	{
		rMM.LoadStorySelect(syscon.screensizeX, syscon.screensizeY);
		switch (rMM.ActionTakenSS(x, y, flag, syscon.screensizeX, syscon.screensizeY))
		{
		case 0: storyFlag = 0;												  PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		case 1:	storyFlag = 1;
			PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		case 2: storyFlag = 2;rMM.UpdateStoryRanking();    PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break; // ranking
		case 3: Status = MAINMENU; Wait = 1; storyFlag = -1; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		}
	}
	else if (storyFlag == 0) // Choose Male or Female or Cancel
	{
		rMM.LoadCharacterSelect(syscon.screensizeX, syscon.screensizeY);
		switch (rMM.ActionTakenCS(x, y, flag, syscon.screensizeX, syscon.screensizeY))
		{
			// ++++++++++++++++++++++++++++++++
		case 1:	storyFlag = 3;
			//Status=STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); ////////////// NEw game
			//CreateSaveData();
			PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		case 2:
			storyFlag = 4;
			PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break; // CREATE SAVEDATA, Status =proceed
// ++++++++++++++++++++++++++++++++
		case 3: Status = MAINMENU; Wait = 1; storyFlag = -1; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		}
	}
	else if (storyFlag == 2) // View Rankings
	{
		rMM.LoadStoryRanking(syscon.screensizeX, syscon.screensizeY);
		if (rMM.ActionTakenSR(x, y, flag, syscon.screensizeX, syscon.screensizeY) == 0)
		{
			Status = MAINMENU; Wait = 1; storyFlag = -1; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		} ////////////////////////////////////////////////////////////////// +++++++++++++++++++++++++++++++++++++++++++++++++++ RANKING
	}
	else if (storyFlag == 1)
	{
		LoadSaveData();
		storyFlag = 5;

	}
	else if (storyFlag == 3)
	{
		LoadSaveData();
		storyFlag = 6;
	}
	else if (storyFlag == 4)
	{
		LoadSaveData();
		storyFlag = 7;
	}
	else if (storyFlag == 5)
	{
		DrawSaveData();
		switch (ActionLoadSaveData())
		{
		case 1:				storyFlag = -1;
			SaveSelect = 1;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			break;
		case 2:				storyFlag = -1;
			SaveSelect = 2;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			break;
		case 3:				storyFlag = -1;
			SaveSelect = 3;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			break;
		case 4:				storyFlag = -1;
			SaveSelect = 4;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			break;
		case 5:				storyFlag = -1;
			SaveSelect = 5;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			break;
		}
	}
	else if (storyFlag == 6)
	{
		DrawSaveData();
		switch (ActionNewSaveData())
		{
		case 1:				storyFlag = -1;
			SaveSelect = 1;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			CreateSaveData(1, 1);
			break;
		case 2:				storyFlag = -1;
			SaveSelect = 2;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(2, 1);
			break;
		case 3:				storyFlag = -1;
			SaveSelect = 3;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(3, 1);
			break;
		case 4:				storyFlag = -1;
			SaveSelect = 4;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(4, 1);
			break;
		case 5:				storyFlag = -1;
			SaveSelect = 5;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			CreateSaveData(5, 1);
			break;
		}
		return 1;
	}
	else if (storyFlag == 7)
	{
		DrawSaveData();
		switch (ActionNewSaveData())
		{
		case 1:				storyFlag = -1;
			SaveSelect = 1;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(1, 2);
			break;
		case 2:				storyFlag = -1;
			SaveSelect = 2;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(2, 2);
			break;
		case 3:				storyFlag = -1;
			SaveSelect = 3;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			CreateSaveData(3, 2);
			break;
		case 4:				storyFlag = -1;
			SaveSelect = 4;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE); ////////////// NEw game
			CreateSaveData(4, 2);
			break;
		case 5:				storyFlag = -1;
			SaveSelect = 5;
			Status = STORYNEW;	 Wait = 0;		StopSoundMem(snd_MainMenu);PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);  ////////////// NEw game
			CreateSaveData(5, 2);
			break;
		}
		return 1;
	}
	return 0;
}

void RTS_MainMenu::CaseBossRush(void)
{
	SetDrawBright(100, 100, 100);
	rMM.LoadGraphs(syscon.screensizeX, syscon.screensizeY);

	SetDrawBright(255, 255, 255);
	if (bossFlag == -1) // Choose New, Load, Ranking, or Cancel
	{
		rMM.LoadBossRushSelect(syscon.screensizeX, syscon.screensizeY);
		switch (rMM.ActionTakenBRS(x, y, flag, syscon.screensizeX, syscon.screensizeY))
		{
			// +++++++++++++++++++++++++++++++++++++++
		case 0:	Status = BOSSRUSHMODE; Wait = 0;		StopSoundMem(snd_MainMenu); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;  // enter boss rush mode
		case 1: bossFlag = 1;													PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break; // view ranking
		// +++++++++++++++++++++++++++++++++++++++
		case 2: Status = MAINMENU; Wait = 1; bossFlag = -1; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		break;
		}
	}
	else if (bossFlag == 1) // view ranking
	{
		rMM.LoadBossRushRanking(syscon.screensizeX, syscon.screensizeY);
		if (rMM.ActionTakenBRR(x, y, flag, syscon.screensizeX, syscon.screensizeY) == 0)
		{
			Status = MAINMENU; Wait = 1; bossFlag = -1; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
		}
	}
}

void RTS_MainMenu::CaseGallery(void)
{

	if (CheckSoundMem(snd_Gallery) != 1)
		PlaySoundMem(snd_Gallery, DX_PLAYTYPE_LOOP, TRUE);
	rGL.LoadGalleryIcons();
	if (galFlag == -1)
	{
		if (galLag == 0)
		{
			SetDrawBright(255, 255, 255); rGL.loadFlag2 = 0;
			rGL.DisplayGalleryIcons(syscon.screensizeX, syscon.screensizeY);
			int gF = rGL.ActionTaken(x, y, flag);
			if (gF >= 0 && gF <= 23)
				if (gF < 22)
				{
					galFlag = gF;	rGL.loadFlag = 0; rGL.LoadGal(gF); galLag = 0; galFade = 255; PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
				}
				else if (gF == 23)
				{
					rGL.loadFlag = 0; Wait = 0; Status = MAINMENU; rGL.ReleaseData(); StopSoundMem(snd_Gallery); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);
				}
		}
		else
		{
			if (galLag > 45)
			{
				SetDrawBright(galFade, galFade, galFade);
				rGL.ShowGallery(x, y, flag, galFlag, syscon.screensizeX, syscon.screensizeY);galLag--; galFade -= 6;
			}
			else if (galLag <= 45)
			{
				SetDrawBright(galFade, galFade, galFade);
				rGL.DisplayGalleryIcons(syscon.screensizeX, syscon.screensizeY); galLag--; galFade += 6;
			}
		}
	}
	else if (galFlag != -1)
	{
		if (galLag > 45)
		{
			if (galLag > 90)
				SetDrawBright(255, 255, 255);
			else
			{
				SetDrawBright(galFade, galFade, galFade);
				galLag++; galFade += 6;
			}

			int oldFlag = galFlag;
			galFlag = rGL.ShowGallery(x, y, flag, galFlag, syscon.screensizeX, syscon.screensizeY);
			if (oldFlag != galFlag)
			{
				galLag = 90; galFade = 255;
			}
		}
		else
		{
			SetDrawBright(galFade, galFade, galFade);
			rGL.DisplayGalleryIcons(syscon.screensizeX, syscon.screensizeY);
			galLag++; galFade -= 6;
		}
	}

}

void RTS_MainMenu::CaseOption(void)
{
	if (CheckSoundMem(snd_Option) != 1)
		PlaySoundMem(snd_Option, DX_PLAYTYPE_LOOP, TRUE);

	rOP.LoadOptionImages(syscon);
	rOP.DisplayOptionImages(syscon.screensizeX, syscon.screensizeY);
	switch (rOP.ActionTakenOP(x, y, flag, syscon.screensizeX, syscon.screensizeY))
	{
	case 0: PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		rOP.SaveSystemConfiguration();
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		break;
	case 1: PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		rOP.SaveDefaulSystemConfiguration();
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		break;
	case 2: PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);		rOP.SaveAllDefaultSystemData();
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		break;
	case 3:	rOP.LoadCurrentSystemConfiguration();
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		StopSoundMem(snd_Option);
		Status = MAINMENU; Wait = 0;	rOP.ReleaseData(); PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);					break;
	case 4: ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																break;
	case 5:	ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																break;
	case 6: PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																	break; // TEXT SPEED ++++++++
	case 7: ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_MainMenu);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Gallery);
		ChangeVolumeSoundMem(rOP.sysc.VolumeBGM, snd_Option);
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																break;
	case 8:	ChangeVolumeSoundMem(rOP.sysc.VolumeSE, snd_Select);
		PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																break;
	case 9: PlaySoundMem(snd_Select, DX_PLAYTYPE_BACK, TRUE);																	break; // TEXT SPEED ++++++++
	}
}

void RTS_MainMenu::LoadScreen(void)
{
	switch (fls.ProjectLoadScreen(syscon.screensizeX, syscon.screensizeY, 160))
	{
	case -1:			fls.RandomFriendlyTips(GetRand(FT_TOTAL) + 1);		break;
	case 1:			Wait = 1;																	break;
	}
}

void RTS_MainMenu::LoadScreen2(void)
{
	switch (fls.ProjectLoadScreen(syscon.screensizeX, syscon.screensizeY, 160))
	{
	case -1:			fls.RandomDidYouKnow(GetRand(FT_TOTAL) + 1);		break;
	case 1:			Wait = 1;																	break;
	}
}


int RTS_MainMenu::GetStatus(void)
{
	return Status;
}

void RTS_MainMenu::SetStatus(int stat)
{
	Status = stat;
}

int RTS_MainMenu::GetWait(void)
{
	return Wait;
}

void RTS_MainMenu::ResetWait(void)
{
	Wait = 0;
}

void RTS_MainMenu::SetCursor(int cx, int cy, int cf)
{
	x = cx;
	y = cy;
	flag = cf;
}

void RTS_MainMenu::CreateSaveData(int SaveNumber, int ModelNumber)
{
	sd.ModelFlag = ModelNumber;
	sd.Life = 3;
	sd.ItemFlag = 1;
	sd.Score = 0;
	for (int i = 0; i < 5; i++)
	{
		sd.StageBossFlag[i] = 0; ///////////// ++++++++ it should be 0;
		sd.StageNextFlag[i] = 0;
		sd.StageKeys[i] = 0;
	}
	for (int i = 0;i < 17;i++)
		sd.EnemyDefeatedNumber[i] = 0;
	sd.CurrentStage = 1;
	sd.CurrentArea = 1;
	sd.CurrentAreaOld = 0;

	// - If no data created, create New File for SAVE DATA - //
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

void RTS_MainMenu::LoadSaveData(void)
{
	sdFlag1 = 0;
	sdFlag2 = 0;
	sdFlag3 = 0;
	sdFlag4 = 0;
	sdFlag5 = 0;

	// Read Save Data 01
	int ExistFlag1 = 0;
	FILE *fr1 = fopen("SaveData01.sav", "rb");
	if (fr1 == NULL)
		ExistFlag1 = -1;  // no data
	else
	{
		fread(&SD1, sizeof(SD1), 1, fr1);
		sdFlag1 = 1; // exist
		fclose(fr1);
	}


	// Read Save Data 02
	int ExistFlag2 = 0;
	FILE *fr2 = fopen("SaveData02.sav", "rb");
	if (fr2 == NULL)
		ExistFlag2 = -1;  // no data
	else
	{
		fread(&SD2, sizeof(SD2), 1, fr2);
		sdFlag2 = 1; // exist
		fclose(fr2);
	}


	// Read Save Data 03
	int ExistFlag3 = 0;
	FILE *fr3 = fopen("SaveData03.sav", "rb");
	if (fr3 == NULL)
		ExistFlag3 = -1;  // no data
	else
	{
		fread(&SD3, sizeof(SD3), 1, fr3);
		sdFlag3 = 1; // exist
		fclose(fr3);
	}


	// Read Save Data 04
	int ExistFlag4 = 0;
	FILE *fr4 = fopen("SaveData04.sav", "rb");
	if (fr4 == NULL)
		ExistFlag4 = -1;  // no data
	else
	{
		fread(&SD4, sizeof(SD4), 1, fr4);
		sdFlag4 = 1; // exist
		fclose(fr4);
	}


	// Read Save Data 05
	int ExistFlag5 = 0;
	FILE *fr5 = fopen("SaveData05.sav", "rb");
	if (fr5 == NULL)
		ExistFlag5 = -1;  // no data
	else
	{
		fread(&SD5, sizeof(SD5), 1, fr5);
		sdFlag5 = 1; // exist
		fclose(fr5);
	}


	// load image for SD1
	if (ExistFlag1 == -1)
		img_SD1 = LoadGraph(SAVE_SD1NO);
	else
	{
		switch (SD1.ModelFlag)
		{
		case 1: // male
			switch (SD1.CurrentStage)
			{
			case 1: img_SD1 = LoadGraph(SAVE_SD1MST1); break;
			case 2: img_SD1 = LoadGraph(SAVE_SD1MST2); break;
			case 3: img_SD1 = LoadGraph(SAVE_SD1MST3); break;
			case 4: img_SD1 = LoadGraph(SAVE_SD1MST4); break;
			case 5: img_SD1 = LoadGraph(SAVE_SD1MST5);  break;
			}
			break;
		case 2:
			switch (SD1.CurrentStage)
			{
			case 1: img_SD1 = LoadGraph(SAVE_SD1FST1); break;
			case 2: img_SD1 = LoadGraph(SAVE_SD1FST2); break;
			case 3: img_SD1 = LoadGraph(SAVE_SD1FST3); break;
			case 4: img_SD1 = LoadGraph(SAVE_SD1FST4); break;
			case 5: img_SD1 = LoadGraph(SAVE_SD1FST5); break;
			}
			break; // female
		}
	} // end loading image for SD1

	// load image for SD2
	if (ExistFlag2 == -1)
		img_SD2 = LoadGraph(SAVE_SD2NO);
	else
	{
		switch (SD2.ModelFlag)
		{
		case 1: // male
			switch (SD2.CurrentStage)
			{
			case 1: img_SD2 = LoadGraph(SAVE_SD2MST1); break;
			case 2: img_SD2 = LoadGraph(SAVE_SD2MST2); break;
			case 3: img_SD2 = LoadGraph(SAVE_SD2MST3); break;
			case 4: img_SD2 = LoadGraph(SAVE_SD2MST4); break;
			case 5: img_SD2 = LoadGraph(SAVE_SD2MST5);  break;
			}
			break;
		case 2:
			switch (SD2.CurrentStage)
			{
			case 1: img_SD2 = LoadGraph(SAVE_SD2FST1); break;
			case 2: img_SD2 = LoadGraph(SAVE_SD2FST2); break;
			case 3: img_SD2 = LoadGraph(SAVE_SD2FST3); break;
			case 4: img_SD2 = LoadGraph(SAVE_SD2FST4); break;
			case 5: img_SD2 = LoadGraph(SAVE_SD2FST5); break;
			}
			break; // female
		}
	} // end loading image for SD2

	// load image for SD3
	if (ExistFlag3 == -1)
		img_SD3 = LoadGraph(SAVE_SD3NO);
	else
	{
		switch (SD3.ModelFlag)
		{
		case 1: // male
			switch (SD3.CurrentStage)
			{
			case 1: img_SD3 = LoadGraph(SAVE_SD3MST1); break;
			case 2: img_SD3 = LoadGraph(SAVE_SD3MST2); break;
			case 3: img_SD3 = LoadGraph(SAVE_SD3MST3); break;
			case 4: img_SD3 = LoadGraph(SAVE_SD3MST4); break;
			case 5: img_SD3 = LoadGraph(SAVE_SD3MST5);  break;
			}
			break;
		case 2:
			switch (SD3.CurrentStage)
			{
			case 1: img_SD3 = LoadGraph(SAVE_SD3FST1); break;
			case 2: img_SD3 = LoadGraph(SAVE_SD3FST2); break;
			case 3: img_SD3 = LoadGraph(SAVE_SD3FST3); break;
			case 4: img_SD3 = LoadGraph(SAVE_SD3FST4); break;
			case 5: img_SD3 = LoadGraph(SAVE_SD3FST5); break;
			}
			break; // female
		}
	} // end loading image for SD3

// load image for SD4
	if (ExistFlag4 == -1)
		img_SD4 = LoadGraph(SAVE_SD4NO);
	else
	{
		switch (SD4.ModelFlag)
		{
		case 1: // male
			switch (SD4.CurrentStage)
			{
			case 1: img_SD4 = LoadGraph(SAVE_SD4MST1); break;
			case 2: img_SD4 = LoadGraph(SAVE_SD4MST2); break;
			case 3: img_SD4 = LoadGraph(SAVE_SD4MST3); break;
			case 4: img_SD4 = LoadGraph(SAVE_SD4MST4); break;
			case 5: img_SD4 = LoadGraph(SAVE_SD4MST5);  break;
			}
			break;
		case 2:
			switch (SD4.CurrentStage)
			{
			case 1: img_SD4 = LoadGraph(SAVE_SD4FST1); break;
			case 2: img_SD4 = LoadGraph(SAVE_SD4FST2); break;
			case 3: img_SD4 = LoadGraph(SAVE_SD4FST3); break;
			case 4: img_SD4 = LoadGraph(SAVE_SD4FST4); break;
			case 5: img_SD4 = LoadGraph(SAVE_SD4FST5); break;
			}
			break; // female
		}
	} // end loading image for SD4

	// load image for SD5
	if (ExistFlag5 == -1)
		img_SD5 = LoadGraph(SAVE_SD5NO);
	else
	{
		switch (SD5.ModelFlag)
		{
		case 1: // male
			switch (SD5.CurrentStage)
			{
			case 1: img_SD5 = LoadGraph(SAVE_SD5MST1); break;
			case 2: img_SD5 = LoadGraph(SAVE_SD5MST2); break;
			case 3: img_SD5 = LoadGraph(SAVE_SD5MST3); break;
			case 4: img_SD5 = LoadGraph(SAVE_SD5MST4); break;
			case 5: img_SD5 = LoadGraph(SAVE_SD5MST5);  break;
			}
			break;
		case 2:
			switch (SD5.CurrentStage)
			{
			case 1: img_SD5 = LoadGraph(SAVE_SD5FST1); break;
			case 2: img_SD5 = LoadGraph(SAVE_SD5FST2); break;
			case 3: img_SD5 = LoadGraph(SAVE_SD5FST3); break;
			case 4: img_SD5 = LoadGraph(SAVE_SD5FST4); break;
			case 5: img_SD5 = LoadGraph(SAVE_SD5FST5); break;
			}
			break; // female
		}
	} // end loading image for SD1

}

void RTS_MainMenu::DrawSaveData(void)
{
	DrawGraph((10 * 1) + (SAVE_X * 0), (syscon.screensizeY / 2) - (SAVE_Y / 2), img_SD1, TRUE);
	DrawGraph((10 * 2) + (SAVE_X * 1), (syscon.screensizeY / 2) - (SAVE_Y / 2), img_SD2, TRUE);
	DrawGraph((10 * 3) + (SAVE_X * 2), (syscon.screensizeY / 2) - (SAVE_Y / 2), img_SD3, TRUE);
	DrawGraph((10 * 4) + (SAVE_X * 3), (syscon.screensizeY / 2) - (SAVE_Y / 2), img_SD4, TRUE);
	DrawGraph((10 * 5) + (SAVE_X * 4), (syscon.screensizeY / 2) - (SAVE_Y / 2), img_SD5, TRUE);

}

int RTS_MainMenu::ActionNewSaveData(void)
{
	int x1, x2;
	int y1 = (syscon.screensizeY / 2) - (SAVE_Y / 2);
	int y2 = y1 + SAVE_Y;
	for (int i = 1; i <= 5; i++)
	{
		x1 = (10 * i) + (SAVE_X * (i - 1));
		x2 = x1 + SAVE_X;
		if (((x > x1) && (x < x2)) && ((y > y1) && (y < y2)) && flag == 1)
			return i;
	}
	return -1;
}

int RTS_MainMenu::ActionLoadSaveData(void)
{
	int x1, x2;
	int y1 = (syscon.screensizeY / 2) - (SAVE_Y / 2);
	int y2 = y1 + SAVE_Y;
	for (int i = 1; i <= 5; i++)
	{
		x1 = (10 * i) + (SAVE_X * (i - 1));
		x2 = x1 + SAVE_X;
		if (((x > x1) && (x < x2)) && ((y > y1) && (y < y2)) && flag == 1)
		{
			if (i == 1 && sdFlag1 == 1)
				return 1;
			else if (i == 2 && sdFlag2 == 1)
				return 2;
			else if (i == 3 && sdFlag3 == 1)
				return 3;
			else if (i == 4 && sdFlag4 == 1)
				return 4;
			else if (i == 5 && sdFlag5 == 1)
				return 5;
		}
	}
	return -1;
}

void RTS_MainMenu::RefreshWait()
{
	Wait = 2;
}
