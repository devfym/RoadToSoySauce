#include "D_DataManager.h"


D_DataManager::D_DataManager(void)
{
}


D_DataManager::~D_DataManager(void)
{
}

void D_DataManager::CheckDataFiles(void)
{
	///////////////////////////////////// SysDat01
	sysconf.screensizeX = SS_NORMAL_X;
	sysconf.screensizeY = SS_NORMAL_Y;
	sysconf.TextSpeed = TXT_SPEED_MEDIUM;
	sysconf.VolumeBGM = OP_VOLUME_M;
	sysconf.VolumeSE = OP_VOLUME_M;

	// - If no data created, create New File for System Configuration data - //
	int createDataFlag1 = 0;
	FILE *fr1 = fopen("SysDat01.dat", "rb");
	if (fr1 == NULL)
		createDataFlag1 = 1;
	else
		fclose(fr1);
	if (createDataFlag1 == 1)
	{
		FILE *fp1 = fopen("SysDat01.dat", "wb");
		fwrite(&sysconf, sizeof(sysconf), 1, fp1);
		fclose(fp1);
	}

	///////////////////////////////////// SysDat02
		// - Gallery Information Initialization - //
	for (int loop = 0; loop < 17; loop++)
		gStat.enemyflag[loop] = 0;
	gStat.malecharflag = 0;
	gStat.femalecharflag = 0;
	gStat.motherflag = 0;
	gStat.driverflag = 0;
	gStat.sarisaristoreflag = 0;

	// - If no data created, create New File for Gallery Information - //
	int createDataFlag2 = 0;
	FILE *fr2 = fopen("SysDat02.dat", "rb");
	if (fr2 == NULL)
		createDataFlag2 = 1;
	else
		fclose(fr2);
	if (createDataFlag2 == 1)
	{
		FILE *fp2 = fopen("SysDat02.dat", "wb");
		fwrite(&gStat, sizeof(gStat), 1, fp2);
		fclose(fp2);
	}
	///////////////////////////////////// SysDat03
	for (int y = 1; y < 5; y++)
	{
		strcpy(sRank.TopPlayer[y], "PLAYER");
		sRank.TopScore[y] = 1000;
	}
	strcpy(sRank.TopPlayer[0], "YAS");
	sRank.TopScore[0] = 10000;

	// - If no data created, create New File for Story Rank - //
	int createDataFlag3 = 0;
	FILE *fr3 = fopen("SysDat03.dat", "rb");
	if (fr3 == NULL)
		createDataFlag3 = 1;
	else
		fclose(fr3);
	if (createDataFlag3 == 1)
	{
		FILE *fp3 = fopen("SysDat03.dat", "wb");
		fwrite(&sRank, sizeof(sRank), 1, fp3);
		fclose(fp3);
	}
	///////////////////////////////////// SysDat04
	strcpy(brRank.TopPlayer[0], "1ST \0");
	brRank.TopScore[0] = 250;
	strcpy(brRank.TopPlayer[1], "2ND \0");
	brRank.TopScore[1] = 200;
	strcpy(brRank.TopPlayer[2], "3RD \0");
	brRank.TopScore[2] = 150;
	strcpy(brRank.TopPlayer[3], "4TH \0");
	brRank.TopScore[3] = 100;
	strcpy(brRank.TopPlayer[4], "5TH \0");
	brRank.TopScore[4] = 50;
	// - If no data created, create New File for Story Rank - //
	int createDataFlag4 = 0;
	FILE *fr4 = fopen("SysDat04.dat", "rb");
	if (fr4 == NULL)
		createDataFlag4 = 1;
	else
		fclose(fr4);
	if (createDataFlag4 == 1)
	{
		FILE *fp4 = fopen("SysDat04.dat", "wb");
		fwrite(&brRank, sizeof(brRank), 1, fp4);
		fclose(fp4);
	}

}

