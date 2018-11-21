
// DxLibのファイルを読み込む
#include <DxLib.h>

// リソースファイルを読み込む
#include "DataList.h"

#include "K_KinectHandler.h"
#include "FramePerSecond.h"
#include "RTS_MainMenu.h"
#include "D_DataManager.h"
#include "StoryManager.h"
#include "BossRushManager.h"

SystemConfiguration syscon;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// If Failed to Load DxLib, Close the application
	if (DxLib_Init() < 0)
		return -1;

	D_DataManager dDM;
	dDM.CheckDataFiles();

	// Application Name
	SetMainWindowText("ROAD TO SOYSAUCE");

	// Read System Config
	FILE *fgi = fopen("SysDat01.dat", "rb");
	if (fgi != NULL)
	{
		fread(&syscon, sizeof(syscon), 1, fgi);
	}
	fclose(fgi);

	// ScreenSize
	SetGraphMode(syscon.screensizeX, syscon.screensizeY, 32);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	// Load Kinect
	K_KinectHandler *kh = new K_KinectHandler();

	// FPS
	FramePerSecond fps;

	// Load Main Menu Class
	RTS_MainMenu *rtsMM = new RTS_MainMenu(syscon);

	// Load Story Manager
	StoryManager *STM = new StoryManager(kh);

	// Load Boss Rush Mode Manager
	BossRushManager *BRM = new BossRushManager(kh);

	int pointercursorDispFlag = 0;
	int FriendlyTips = 0;
	int res = 0;
	int GameNew = 0;
	int GameEnd = 0;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{
		kh->GetBodyPoint();
		kh->GetCursorPointer(syscon.screensizeX, syscon.screensizeY);
		kh->CheckBodyMovement();
		rtsMM->SetCursor(kh->cursorX, kh->cursorY, kh->cursorFlag);

		switch (rtsMM->GetStatus())
		{
		case SPLASH:
			pointercursorDispFlag = 0;
			if (FriendlyTips != 3 && rtsMM->CaseSplash(FriendlyTips) == 1)
				FriendlyTips++;
			else if (FriendlyTips == 3)
				rtsMM->SetStatus(MAINMENU);
			break;

		case MAINMENU:
			if (rtsMM->GetWait() == 0
			{
				rtsMM->LoadScreen();
				pointercursorDispFlag = 0;
			}
			else if (rtsMM->GetWait() == 2)
			{
				rtsMM->LoadScreen2();
				STM->ReleaseData();
				pointercursorDispFlag = 0;
			}	// delete all 3D action part resources
			else
			{
				rtsMM->CaseMainMenu();
				pointercursorDispFlag = 1;
			}
			break;

		case STORYMODE:
			if (rtsMM->CaseStoryMode() == 1)
				res = 5;
			pointercursorDispFlag = 1;
			break;

		case BOSSRUSH:
			rtsMM->CaseBossRush();
			pointercursorDispFlag = 1;
			break;

		case GALLERY:
			if (rtsMM->GetWait() == 0)
			{
				rtsMM->LoadScreen();
				pointercursorDispFlag = 0;
			}
			else
			{
				rtsMM->CaseGallery();
				pointercursorDispFlag = 1;
			}
			break;

		case OPTION:
			if (rtsMM->GetWait() == 0)
			{
				rtsMM->LoadScreen();
				pointercursorDispFlag = 0;
			}
			else
			{
				rtsMM->CaseOption();
				pointercursorDispFlag = 1;
			}
			break;

		case STORYNEW:
			if (rtsMM->GetWait() == 0)
			{
				rtsMM->LoadScreen();
				STM->StoryLoad(rtsMM->SaveSelect);
				pointercursorDispFlag = 0;
				STM->InitializeFlag++;
			}
			else
			{
				if (res != -1 && res != 3 && res != 2 && res != 4 && res != 5) // while in area;
				{
					if (STM->StageBegin() == 1)
						res = 4;
					else
						if (STM->StageNew == 2)
							res = STM->StoryLoop();
				}
				if (res == 1) // load another area;
				{
					rtsMM->ResetWait();
					STM->InitializeFlag = 0;
					STM->SaveDataSave(rtsMM->SaveSelect);
					STM->ReleaseData();
					res = 0;
				}
				if (res == -1) // if game over
				{
					if (STM->GameOver() == -1)
					{
						STM->endOver = 0;
						rtsMM->RefreshWait();
						STM->InitializeFlag = 0;
						res = 0;
						rtsMM->SetStatus(MAINMENU);
					}
				}
				if (res == 2)
				{
					rtsMM->RefreshWait();
					STM->InitializeFlag = 0;
					res = 0;
					rtsMM->SetStatus(MAINMENU);
				}
				if (res == 3) // while PAUSE state
				{
					pointercursorDispFlag = 1;
					STM->WhilePause();
					switch (STM->ActionWhilePause(kh->cursorX, kh->cursorY, kh->cursorFlag))
					{
					case 1:
						res = 0;
						pointercursorDispFlag = 0;
						break;
					case 2:
						res = 2;
						pointercursorDispFlag = 0;
						break;
					}
				}
				if (res == 4) // Game Clear, when StageFlag[4]==1
				{
					pointercursorDispFlag = 0;
					if ((GameEnd != 4) && (STM->GameClear(GameEnd) == 1))
						GameEnd++;
					else if (GameEnd == 4)
					{
						GameEnd = 0;
						rtsMM->RefreshWait();
						STM->InitializeFlag = 0;
						STM->SaveDataSave(rtsMM->SaveSelect);
						res = 0;
						rtsMM->SetStatus(MAINMENU);
					}
				}
				if (res == 5) // NEW GAME,
				{
					pointercursorDispFlag = 0;
					if ((GameNew != 4) && (STM->GameNew(GameNew) == 1))
						GameNew++;
					else if (GameNew == 4)
					{
						GameNew = 0;
						res = 0;
					}
				}
			}
			break;

		case BOSSRUSHMODE:
			if (rtsMM->GetWait() == 0)
			{
				rtsMM->LoadScreen();
				pointercursorDispFlag = 0;
				BRM->BossRushLoad();
				BRM->InitializeFlag++;
			}
			else
			{
				if (res != -1)
				{
					BRM->BossRushStart();
					if (BRM->StageNew == 2)
						res = BRM->BossRushLoop();
				}
				if (res == -1)
				{
					if (BRM->BossRushGameOver() == -1)
					{
						rtsMM->ResetWait();
						BRM->InitializeFlag = 0;
						BRM->ReleaseData();
						res = 0;
						rtsMM->SetStatus(MAINMENU);
					}
				}
			}
			break;

		case EXIT:
			DxLib_End();
			return 0;
			break;
		}
		if (pointercursorDispFlag == 1)
			kh->DisplayCursorPointer();
		fps.UpdateFPS();
		fps.GetFPS();

		//fps.DrawFPS();
		fps.WaitFPS();
	}

	DxLib_End();
	return 0;
}
