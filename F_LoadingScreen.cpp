#include "F_LoadingScreen.h"
#include <DXLib.h>
#include "DataList.h"

F_LoadingScreen::F_LoadingScreen(void)
{
	img_LoadScreen = NULL;
	screenTime = 0;
	screenFlag = -1;
	rc = 0;
	gc = 0;
	bc = 0;
	loadCount = 0;
}

F_LoadingScreen::~F_LoadingScreen(void)
{
	DeleteGraph(img_LoadScreen);
}


int F_LoadingScreen::ProjectLoadScreen(int screenX, int screenY, int LoadTime)
{
	if (screenFlag == 1)
	{
		SetDrawBright(rc, bc, gc);
		DrawExtendGraph(0, 0, screenX, screenY, img_LoadScreen, TRUE);
		if (screenTime > loadtime + 20)
		{
			screenFlag = -1;	img_LoadScreen = NULL; SetDrawBright(255, 255, 255);  loadCount++; return 1;
		}
		screenTime++;
		if (screenTime < loadtime / 2)
		{
			rc += 4;	bc += 4;	gc += 4;
			//if(loadCount>2) DrawFormatString(20, screenY- 40,  BC_WHITE, "NOW LOADING");
		}
		if (screenTime > loadtime / 2 + 20)
		{
			rc -= 4;	bc -= 4;	gc -= 4;
		}
		/*
		if (screenTime >= loadtime / 2  && loadCount>2)
		{	if(screenTime < loadtime * 6 / 10 )
				DrawFormatString(20, screenY- 40,  BC_WHITE, "NOW LOADING *");
			else if(screenTime < loadtime * 7 / 10 )
				DrawFormatString(20, screenY- 40,  BC_WHITE, "NOW LOADING * *");
			else if(screenTime < loadtime * 8 / 10 + 20)
				DrawFormatString(20, screenY- 40,  BC_WHITE, "NOW LOADING * * *");
			else if(screenTime < loadtime * 9 / 10 + 20)
				DrawFormatString(20, screenY- 40,  BC_WHITE, "NOW LOADING * * * *");
		}
		*/
	}

	if (screenFlag == 0)
	{
		screenFlag = 1;
		screenTime = 0;
		rc = 0;	gc = 0;	bc = 0;
		loadtime = LoadTime;
	}

	if (screenFlag == -1)
	{
		screenFlag = 0;
		return -1;
	}
	return 0;
}

void F_LoadingScreen::RandomFriendlyTips(int random)
{
	switch (random)
	{
	case 1:
		img_LoadScreen = LoadGraph(FT_1);
		break;
	case 2:
		img_LoadScreen = LoadGraph(FT_2);
		break;
	case 3:
		img_LoadScreen = LoadGraph(FT_3);
		break;
	case 4:
		img_LoadScreen = LoadGraph(FT_4);
		break;
	case 5:
		img_LoadScreen = LoadGraph(FT_5);
		break;
	case 6:
		img_LoadScreen = LoadGraph(FT_6);
		break;
	case 7:
		img_LoadScreen = LoadGraph(FT_7);
		break;
	case 8:
		img_LoadScreen = LoadGraph(FT_8);
		break;
	case 9:
		img_LoadScreen = LoadGraph(FT_9);
		break;

	}

}

void F_LoadingScreen::RandomDidYouKnow(int random)
{
	switch (random)
	{
	case 1:
		img_LoadScreen = LoadGraph(DYK1);
		break;
	case 2:
		img_LoadScreen = LoadGraph(DYK2);
		break;
	case 3:
		img_LoadScreen = LoadGraph(DYK3);
		break;
	case 4:
		img_LoadScreen = LoadGraph(DYK4);
		break;
	case 5:
		img_LoadScreen = LoadGraph(DYK5);
		break;
	case 6:
		img_LoadScreen = LoadGraph(DYK6);
		break;
	case 7:
		img_LoadScreen = LoadGraph(DYK7);
		break;
	case 8:
		img_LoadScreen = LoadGraph(DYK8);
		break;
	case 9:
		img_LoadScreen = LoadGraph(DYK9);
		break;

	}

}


/*
screenFlag : -1 No LoadScreen to call
screenFlag :  0 LoadScreen Initialize
screenFlag :  1 Currently LoadScreen
*/
