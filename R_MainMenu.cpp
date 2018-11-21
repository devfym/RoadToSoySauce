#include "R_MainMenu.h"


R_MainMenu::R_MainMenu(void)
{
	px = SS_NORMAL_X;

	ms.IconX = px - G_INT_MAINMENU_X - 20;
	fontHandle = CreateFontToHandle(NULL, 40, NULL, DX_FONTTYPE_NORMAL);

	ms.img_MainMenu = LoadGraph(G_MAINMENU);
	ms.img_StoryMode = LoadGraph(G_STORYMODE);
	ms.img_BossRush = LoadGraph(G_BOSSRUSH);
	ms.img_Gallery = LoadGraph(G_GALLERY);
	ms.img_Option = LoadGraph(G_OPTION);
	ms.img_Exit = LoadGraph(G_EXIT);

	// - Story Mode Images Load - //
	img_New = LoadGraph(SM_NEW);
	img_Load = LoadGraph(SM_LOAD);
	img_BossRush = LoadGraph(SM_BOSSRUSH);

	img_Ranking = LoadGraph(SM_RANKING);
	img_Cancel = LoadGraph(SM_CANCEL);

	img_Male = LoadGraph(SM_MALE);
	img_Female = LoadGraph(SM_FEMALE);

}


R_MainMenu::~R_MainMenu(void)
{
	DeleteGraph(ms.img_MainMenu);
	DeleteGraph(ms.img_StoryMode);
	DeleteGraph(ms.img_BossRush);
	DeleteGraph(ms.img_Gallery);
	DeleteGraph(ms.img_Option);
	DeleteGraph(ms.img_Exit);
	DeleteGraph(img_New);
	DeleteGraph(img_Load);
	DeleteGraph(img_Ranking);
	DeleteGraph(img_Cancel);
	DeleteGraph(img_Male);
	DeleteGraph(img_Female);
	DeleteGraph(img_BossRush);
	DeleteFontToHandle(fontHandle);
}

void R_MainMenu::LoadGraphs(int x, int y)
{
	DrawExtendGraph(0, 0, x, y, ms.img_MainMenu, TRUE);
	DrawGraph(ms.IconX, 20, ms.img_StoryMode, TRUE);
	DrawGraph(ms.IconX, 40 + (G_INT_MAINMENU_Y * 1), ms.img_BossRush, TRUE);
	DrawGraph(ms.IconX, 60 + (G_INT_MAINMENU_Y * 2), ms.img_Gallery, TRUE);
	DrawGraph(ms.IconX, 80 + (G_INT_MAINMENU_Y * 3), ms.img_Option, TRUE);
	DrawGraph(ms.IconX, 100 + (G_INT_MAINMENU_Y * 4), ms.img_Exit, TRUE);
}

void R_MainMenu::LoadStorySelect(int x, int y)
{
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 1) + (SM_ICON_Y * 0), img_New, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 2) + (SM_ICON_Y * 1), img_Load, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 3) + (SM_ICON_Y * 2), img_Ranking, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 4) + (SM_ICON_Y * 3), img_Cancel, TRUE);
}

void R_MainMenu::LoadBossRushSelect(int x, int y)
{
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 1) + (SM_ICON_Y * 0), img_BossRush, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 2) + (SM_ICON_Y * 1), img_Ranking, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), (50 * 3) + (SM_ICON_Y * 2), img_Cancel, TRUE);
}

void R_MainMenu::LoadCharacterSelect(int x, int y)
{
	DrawGraph((0 + 100), 50, img_Male, TRUE);
	DrawGraph((x - 100 - SM_CHAR_X), 50, img_Female, TRUE);
	DrawGraph((x / 2) - (SM_ICON_X / 2), 100 + SM_CHAR_Y, img_Cancel, TRUE);
}

void R_MainMenu::LoadStoryRanking(int x, int y)
{
	/*
		FILE *fgi = fopen( "SysDat03.dat", "rb" );
	   if( fgi != NULL )
	   {
		fread( &storyrank, sizeof(storyrank), 1, fgi );
	   }
		fclose( fgi );
	*/
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			DrawFormatStringToHandle(x / 2 - 100 - 170, 30, BC_BROWN, fontHandle, "STORY MODE: TOP RANK PLAYERS");
		DrawFormatStringToHandle(x / 2 - 100, (i * 50) + 80, BC_BROWN, fontHandle, "%s %d", storyrank.TopPlayer[i], storyrank.TopScore[i]);
	}
	//////////////////// RANKING CHUCHU ADDED ! ! !
	DrawGraph((x / 2) - (SM_ICON_X / 2), 100 + SM_CHAR_Y, img_Cancel, TRUE); //////////////////////////////////// ++++++++++++++++++++++++++++++++;
}

void R_MainMenu::LoadBossRushRanking(int x, int y)
{
	FILE *fgi = fopen("SysDat04.dat", "rb");
	if (fgi != NULL)
	{
		fread(&bossrank, sizeof(bossrank), 1, fgi);
	}
	fclose(fgi);
	for (int s = 0; s < 5; s++)
	{
		if (s == 0)
			DrawFormatStringToHandle(x / 2 - 100 - 150, 30, BC_BROWN, fontHandle, "BOSS RUSH: TOP RANK PLAYERS");
		DrawFormatStringToHandle(x / 2 - 100, (s * 50) + 80, BC_BROWN, fontHandle, "%s %d", bossrank.TopPlayer[s], bossrank.TopScore[s]);
	}

	//////////////////// RANKING CHUCHU ADDED ! ! !
	DrawGraph((x / 2) - (SM_ICON_X / 2), 100 + SM_CHAR_Y, img_Cancel, TRUE); //////////////////////////////////// ++++++++++++++++++++++++++++++++;
}

int R_MainMenu::ActionTakenSR(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int x1, y1;
	x1 = (x / 2) - (SM_ICON_X / 2);
	y1 = (100 + SM_CHAR_Y);
	if (cursorX > x1 && cursorX < x1 + SM_ICON_X && cursorY > y1 && cursorY < y1 + SM_ICON_Y && cursorFlag == 1)
		return 0;
	return -1;
}

int R_MainMenu::ActionTakenBRR(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int x1, y1;
	x1 = (x / 2) - (SM_ICON_X / 2);
	y1 = (100 + SM_CHAR_Y);
	if (cursorX > x1 && cursorX < x1 + SM_ICON_X && cursorY > y1 && cursorY < y1 + SM_ICON_Y && cursorFlag == 1)
		return 0;
	return -1;
}


int R_MainMenu::ActionTakenBRS(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int x1 = ((x / 2) - (SM_ICON_X / 2));
	int x2 = x1 + SM_ICON_X;
	int y1, y2;
	for (int iconNum = 0; iconNum < 3; iconNum++)
	{
		y1 = ((50 * (iconNum + 1)) + (SM_ICON_Y * iconNum));
		y2 = y1 + SM_ICON_Y;
		if (cursorX > x1 && cursorX < x2 && cursorY > y1 && cursorY < y2  && cursorFlag == 1)
		{
			switch (iconNum)
			{
			case 0: return 0; break;
			case 1: return 1; break;
			case 2: return 2; break;
			}
		}
	}
	return -1;
}


int R_MainMenu::ActionTakenCS(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int x1, y1;
	x1 = (x / 2) - (SM_ICON_X / 2);
	y1 = (100 + SM_CHAR_Y);

	if (cursorX > 100 && cursorX < (100 + SM_CHAR_X) && cursorY >  50 && cursorY < (50 + SM_CHAR_Y) && cursorFlag == 1)
		return 1;
	else if (cursorX < (x - 100) && cursorX >(x - 100 - SM_CHAR_X) && cursorY > 50 && cursorY < (50 + SM_CHAR_Y) && cursorFlag == 1)
		return 2;
	else if (cursorX > x1 && cursorX < x1 + SM_ICON_X && cursorY > y1 && cursorY < y1 + SM_ICON_Y && cursorFlag == 1)
		return 3;
	return -1;
}
int R_MainMenu::ActionTakenSS(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int x1 = ((x / 2) - (SM_ICON_X / 2));
	int x2 = x1 + SM_ICON_X;
	int y1, y2;
	for (int iconNum = 0; iconNum < 4; iconNum++)
	{
		y1 = ((50 * (iconNum + 1)) + (SM_ICON_Y * iconNum));
		y2 = y1 + SM_ICON_Y;
		if (cursorX > x1 && cursorX < x2 && cursorY > y1 && cursorY < y2  && cursorFlag == 1)
		{
			switch (iconNum)
			{
			case 0: return 0; break;
			case 1: return 1; break;
			case 2: return 2; break;
			case 3: return 3; break;
			}
		}
	}

	return -1;
}

int R_MainMenu::ActionTaken(int cursorX, int cursorY, int cursorFlag)
{

	if ((cursorX >= ms.IconX && cursorX <= (px - 20)) && (cursorY >= 20 && cursorY <= (G_INT_MAINMENU_Y + 20)) && cursorFlag == 1)
		return 1;

	if ((cursorX >= ms.IconX && cursorX <= (px - 20)) && (cursorY >= (40 + G_INT_MAINMENU_Y) && cursorY <= (G_INT_MAINMENU_Y * 2 + 40)) && cursorFlag == 1)
		return 2;

	if ((cursorX >= ms.IconX && cursorX <= (px - 20)) && (cursorY >= (60 + G_INT_MAINMENU_Y) && cursorY <= (G_INT_MAINMENU_Y * 3 + 60)) && cursorFlag == 1)
		return 3;

	if ((cursorX >= ms.IconX && cursorX <= (px - 20)) && (cursorY >= (80 + G_INT_MAINMENU_Y) && cursorY <= (G_INT_MAINMENU_Y * 4 + 80)) && cursorFlag == 1)
		return 4;

	if ((cursorX >= ms.IconX && cursorX <= (px - 20)) && (cursorY >= (100 + G_INT_MAINMENU_Y) && cursorY <= (G_INT_MAINMENU_Y * 5 + 100)) && cursorFlag == 1)
		return 5;

	return -1;
}

void  R_MainMenu::UpdateStoryRanking(void)
{
	// Read Save Data 01
	int ExistFlag1 = 0;
	FILE *fr1 = fopen("SaveData01.sav", "rb");
	if (fr1 == NULL)
		ExistFlag1 = -1;  // no data
	else
	{
		fread(&SD1, sizeof(SD1), 1, fr1);
		ExistFlag1 = 1; // exist
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
		ExistFlag2 = 1; // exist
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
		ExistFlag3 = 1; // exist
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
		ExistFlag4 = 1; // exist
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
		ExistFlag5 = 1; // exist
		fclose(fr5);
	}

	int a[6];
	a[0] = 0;
	if (ExistFlag1 == 1)	a[1] = SD1.Score;
	else						a[1] = 0;
	if (ExistFlag2 == 1)	a[2] = SD2.Score;
	else						a[2] = 0;
	if (ExistFlag3 == 1)	a[3] = SD3.Score;
	else						a[3] = 0;
	if (ExistFlag4 == 1)	a[4] = SD4.Score;
	else						a[4] = 0;
	if (ExistFlag5 == 1)	a[5] = SD5.Score;
	else						a[5] = 0;
	int b[6];
	for (int i = 0; i < 6; i++)
		b[i] = 1;
	for (int i = 2; i <= 5; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			if (a[j] < a[i])	b[j]++;
			if (a[j] >= a[i])	b[i]++;
		}
	}

	char name[10];


	for (int i = 1; i <= 5; i++)
	{
		if (i == 1)
			strcpy(name, "PLAYER 1");
		else if (i == 2)
			strcpy(name, "PLAYER 2");
		else if (i == 3)
			strcpy(name, "PLAYER 3");
		else if (i == 4)
			strcpy(name, "PLAYER 4");
		else if (i == 5)
			strcpy(name, "PLAYER 5");

		switch (b[i])
		{
		case 1:
			storyrank.TopScore[0] = a[i];
			strcpy(storyrank.TopPlayer[0], name);
			break;
		case 2:
			storyrank.TopScore[1] = a[i];
			strcpy(storyrank.TopPlayer[1], name);
			break;
		case 3:
			storyrank.TopScore[2] = a[i];
			strcpy(storyrank.TopPlayer[2], name);
			break;
		case 4:
			storyrank.TopScore[3] = a[i];
			strcpy(storyrank.TopPlayer[3], name);
			break;
		case 5:
			storyrank.TopScore[4] = a[i];
			strcpy(storyrank.TopPlayer[4], name);
			break;
		}
	}

	FILE *write = fopen("SysDat03.dat", "wb");
	fwrite(&storyrank, sizeof(storyrank), 1, write);
	fclose(write);
}
