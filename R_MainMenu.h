#pragma once
#include <DxLib.h>
#include "DataList.h"
class R_MainMenu
{

	int px;

	// STORYMODE measurements
	int img_New, img_Load, img_Ranking, img_Cancel;
	int img_Male, img_Female;
	int img_BossRush;
	int fontHandle;
	StoryRank storyrank;
	BossRushRank bossrank;

	SaveData SD1, SD2, SD3, SD4, SD5;

	struct MAINSET
	{
		int img_MainMenu;
		int img_StoryMode;
		int img_BossRush;
		int img_Gallery;
		int img_Option;
		int img_Exit;

		int IconX;

	}ms;

public:

	R_MainMenu(void);
	~R_MainMenu(void);

	void LoadGraphs(int x, int y);
	int ActionTaken(int cursorX, int cursorY, int cursorFlag);

	void LoadStorySelect(int x, int y);
	int ActionTakenSS(int cursorX, int cursorY, int cursorFlag, int x, int y);

	void LoadCharacterSelect(int x, int y);
	int ActionTakenCS(int cursorX, int cursorY, int cursorFlag, int x, int y);

	void LoadStoryRanking(int x, int y);
	int ActionTakenSR(int cursorX, int cursorY, int cursorFlag, int x, int y);

	void LoadBossRushSelect(int x, int y);
	int ActionTakenBRS(int cursorX, int cursorY, int cursorFlag, int x, int y);

	void LoadBossRushRanking(int x, int y);
	int ActionTakenBRR(int cursorX, int cursroY, int cursorFlag, int x, int y);

	void UpdateStoryRanking(void);

};

