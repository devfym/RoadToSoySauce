#pragma once
#include "DataList.h"
#include <DxLib.h>
class R_Option
{
	int img_OptionBG;

	int img_VolumeBGM;
	int img_VolumeSE;
	int img_TextSpeed;

	int img_Save;
	int img_Reset;
	int img_ResetAll;
	int img_Cancel;
	int img_LeftArrow;
	int img_RightArrow;

	int img_Mute, img_XS, img_S, img_M, img_L, img_XL;

	GalleryStatus gStat;
	StoryRank sRank;
	BossRushRank	brRank;

public:
	SystemConfiguration sysc;
	int loadFlag;
	R_Option(void);
	~R_Option(void);
	void LoadOptionImages(SystemConfiguration sc);
	void DisplayOptionImages(int x, int y);
	int ActionTakenOP(int cursorX, int cursorY, int cursorFlag, int x, int y);
	void SaveSystemConfiguration(void);
	void SaveDefaulSystemConfiguration(void);
	void SaveAllDefaultSystemData(void);
	void LoadCurrentSystemConfiguration(void);
	void ReleaseData(void);
};

