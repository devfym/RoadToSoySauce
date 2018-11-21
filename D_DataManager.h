#pragma once
#include "DataList.h"
#include <DxLib.h>
class D_DataManager
{
	SystemConfiguration sysconf;
	GalleryStatus gStat;
	StoryRank sRank;
	BossRushRank brRank;

public:
	D_DataManager(void);
	~D_DataManager(void);

	void CheckDataFiles(void);

	void SetSystemConfiguration(SystemConfiguration sc); // SysDat01
	void SetGalleryStatus(GalleryStatus gs); // SysDat02
	void SetStoryRank(StoryRank sr); // SysDat03
	void SetBossRushRank(BossRushRank brr); // SysDat04
};

