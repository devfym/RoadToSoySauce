#include "R_Option.h"


R_Option::R_Option(void)
{
	loadFlag = 0;
}


R_Option::~R_Option(void)
{

}

void R_Option::LoadOptionImages(SystemConfiguration sc)
{
	if (loadFlag == 0)
	{

		FILE *fgi = fopen("SysDat01.dat", "rb");
		if (fgi != NULL)
		{
			fread(&sysc, sizeof(sysc), 1, fgi);
		}
		fclose(fgi);

		img_OptionBG = LoadGraph(OP_BACKGROUND);
		img_VolumeBGM = LoadGraph(OP_VOLUMEBGM);
		img_VolumeSE = LoadGraph(OP_VOLUMESE);
		img_TextSpeed = LoadGraph(OP_TEXTSPEED);
		img_Save = LoadGraph(OP_SAVE);
		img_Reset = LoadGraph(OP_RESET);
		img_ResetAll = LoadGraph(OP_RESETALL);
		img_Cancel = LoadGraph(OP_CANCEL);

		img_Mute = LoadGraph(OP_BAR_1);
		img_XS = LoadGraph(OP_BAR_2);
		img_S = LoadGraph(OP_BAR_3);
		img_M = LoadGraph(OP_BAR_4);
		img_L = LoadGraph(OP_BAR_5);
		img_XL = LoadGraph(OP_BAR_6);

		// ++++++
		img_LeftArrow = LoadGraph(OP_LEFTARROW);
		img_RightArrow = LoadGraph(OP_RIGHTARROW);
		loadFlag = 1;
	}


}

void R_Option::DisplayOptionImages(int x, int y)
{
	DrawExtendGraph(0, 0, x, y, img_OptionBG, TRUE);
	switch (sysc.VolumeBGM)
	{
	case OP_VOLUME_MUTE: DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_Mute, TRUE); break;
	case OP_VOLUME_XS:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_XS, TRUE);  break;
	case OP_VOLUME_S:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_S, TRUE); break;
	case OP_VOLUME_M:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_M, TRUE);  break;
	case OP_VOLUME_L:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_L, TRUE);  break;
	case OP_VOLUME_XL:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_XL, TRUE);  break;
	}
	switch (sysc.VolumeSE)
	{
	case OP_VOLUME_MUTE: DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_Mute, TRUE); break;
	case OP_VOLUME_XS:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_XS, TRUE); break;
	case OP_VOLUME_S:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_S, TRUE); break;
	case OP_VOLUME_M:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_M, TRUE); break;
	case OP_VOLUME_L:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_L, TRUE); break;
	case OP_VOLUME_XL:		 DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_XL, TRUE); break;
	}
	switch (sysc.TextSpeed)
	{
	case TXT_SPEED_SLOW:		DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 6) + (OP_LOGO_Y * 5)), img_Mute, TRUE); break;
	case TXT_SPEED_MEDIUM:	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 6) + (OP_LOGO_Y * 5)), img_M, TRUE); break;
	case TXT_SPEED_FAST:		DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 6) + (OP_LOGO_Y * 5)), img_XL, TRUE); break;
	}
	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 1) + (OP_LOGO_Y * 0)), img_VolumeBGM, TRUE);

	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_LeftArrow, TRUE);
	DrawGraph(x - OP_SPACE_X - OP_ARROW_X, ((OP_SPACE_Y * 2) + (OP_LOGO_Y * 1)), img_RightArrow, TRUE);
	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 3) + (OP_LOGO_Y * 2)), img_VolumeSE, TRUE);

	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_LeftArrow, TRUE);
	DrawGraph(x - OP_SPACE_X - OP_ARROW_X, ((OP_SPACE_Y * 4) + (OP_LOGO_Y * 3)), img_RightArrow, TRUE);
	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 5) + (OP_LOGO_Y * 4)), img_TextSpeed, TRUE);

	DrawGraph(OP_SPACE_X, ((OP_SPACE_Y * 6) + (OP_LOGO_Y * 5)), img_LeftArrow, TRUE);
	DrawGraph(x - OP_SPACE_X - OP_ARROW_X, ((OP_SPACE_Y * 6) + (OP_LOGO_Y * 5)), img_RightArrow, TRUE);



	DrawGraph((0 * OP_ICON_X), y - OP_ICON_Y, img_Save, TRUE);
	DrawGraph((1 * OP_ICON_X), y - OP_ICON_Y, img_Reset, TRUE);
	DrawGraph((2 * OP_ICON_X), y - OP_ICON_Y, img_ResetAll, TRUE);
	DrawGraph((3 * OP_ICON_X), y - OP_ICON_Y, img_Cancel, TRUE);
}

int R_Option::ActionTakenOP(int cursorX, int cursorY, int cursorFlag, int x, int y)
{
	int blx1, blx2;
	int bly1, bly2;
	blx1 = OP_SPACE_X;
	blx2 = blx1 + OP_ARROW_X;
	for (int row = 1; row < 6; row += 2)
	{
		bly1 = (OP_SPACE_Y * (row + 1)) + (OP_LOGO_Y * row);
		bly2 = bly1 + OP_ARROW_Y;

		if (cursorX > blx1 && cursorX < blx2 && cursorY > bly1 && cursorY < bly2 && cursorFlag == 1)
		{
			switch (row)
			{
			case 1:

				switch (sysc.VolumeBGM)
				{
				case OP_VOLUME_MUTE: sysc.VolumeBGM = OP_VOLUME_MUTE;			break;
				case OP_VOLUME_XS:		 sysc.VolumeBGM = OP_VOLUME_MUTE;			break;
				case OP_VOLUME_S:		 sysc.VolumeBGM = OP_VOLUME_XS;				break;
				case OP_VOLUME_M:		 sysc.VolumeBGM = OP_VOLUME_S;				break;
				case OP_VOLUME_L:		 sysc.VolumeBGM = OP_VOLUME_M;				break;
				case OP_VOLUME_XL:		 sysc.VolumeBGM = OP_VOLUME_L;				break;
				}
				return 4;
				break;
			case 3:

				switch (sysc.VolumeSE)
				{
				case OP_VOLUME_MUTE: sysc.VolumeSE = OP_VOLUME_MUTE;			break;
				case OP_VOLUME_XS:		 sysc.VolumeSE = OP_VOLUME_MUTE;			break;
				case OP_VOLUME_S:		 sysc.VolumeSE = OP_VOLUME_XS;					break;
				case OP_VOLUME_M:		 sysc.VolumeSE = OP_VOLUME_S;					break;
				case OP_VOLUME_L:		 sysc.VolumeSE = OP_VOLUME_M;					break;
				case OP_VOLUME_XL:		 sysc.VolumeSE = OP_VOLUME_L;					break;
				}
				return 5;
				break;
			case 5:

				switch (sysc.TextSpeed)
				{
				case TXT_SPEED_SLOW:			 sysc.TextSpeed = TXT_SPEED_SLOW;			break;
				case TXT_SPEED_MEDIUM:		 sysc.TextSpeed = TXT_SPEED_SLOW;			break;
				case TXT_SPEED_FAST:			 sysc.TextSpeed = TXT_SPEED_MEDIUM;		break;

				}
				return 6; break;
			}
		}
	}
	int brx1, brx2;
	int bry1, bry2;
	brx1 = x - OP_SPACE_X - OP_ARROW_X;
	brx2 = brx1 + OP_ARROW_X;
	for (int row = 1; row < 6; row += 2)
	{
		bry1 = (OP_SPACE_Y * (row + 1)) + (OP_LOGO_Y * row);
		bry2 = bry1 + OP_ARROW_Y;

		if (cursorX > brx1 && cursorX < brx2 && cursorY > bry1 && cursorY < bry2 && cursorFlag == 1)
		{
			switch (row)
			{
			case 1:
				switch (sysc.VolumeBGM)
				{
				case OP_VOLUME_MUTE: sysc.VolumeBGM = OP_VOLUME_XS;				break;
				case OP_VOLUME_XS:		 sysc.VolumeBGM = OP_VOLUME_S;				break;
				case OP_VOLUME_S:		 sysc.VolumeBGM = OP_VOLUME_M;				break;
				case OP_VOLUME_M:		 sysc.VolumeBGM = OP_VOLUME_L;				break;
				case OP_VOLUME_L:		 sysc.VolumeBGM = OP_VOLUME_XL;				break;
				case OP_VOLUME_XL:		 sysc.VolumeBGM = OP_VOLUME_XL;				break;
				}
				return 7;
				break;
			case 3:
				switch (sysc.VolumeSE)
				{
				case OP_VOLUME_MUTE: sysc.VolumeSE = OP_VOLUME_XS;					break;
				case OP_VOLUME_XS:		 sysc.VolumeSE = OP_VOLUME_S;					break;
				case OP_VOLUME_S:		 sysc.VolumeSE = OP_VOLUME_M;					break;
				case OP_VOLUME_M:		 sysc.VolumeSE = OP_VOLUME_L;					break;
				case OP_VOLUME_L:		 sysc.VolumeSE = OP_VOLUME_XL;					break;
				case OP_VOLUME_XL:		 sysc.VolumeSE = OP_VOLUME_XL;					break;
				}
				return 8;
				break;
			case 5:
				switch (sysc.TextSpeed)
				{
				case TXT_SPEED_SLOW:			 sysc.TextSpeed = TXT_SPEED_MEDIUM;		break;
				case TXT_SPEED_MEDIUM:		 sysc.TextSpeed = TXT_SPEED_FAST;			break;
				case TXT_SPEED_FAST:			 sysc.TextSpeed = TXT_SPEED_FAST;			break;

				}
				return 9; break;
			}
		}
	}
	// MENU BELOW
	int x1, x2;
	int y1 = y - OP_ICON_Y;
	int y2 = y1 + OP_ICON_Y;

	for (int column = 0; column < 4; column++)
	{
		x1 = (column * OP_ICON_X);
		x2 = x1 + OP_ICON_X;
		if (cursorX > x1 && cursorX < x2 && cursorY > y1 && cursorY < y2 && cursorFlag == 1)
		{
			switch (column)
			{
			case 0: return 0; break;
			case 1: return 1; break;
			case 2: return 2; break;
			case 3: return 3; break;
			}
		}
	}
	//////////////////// MENU BELOW
	return -1;
}

void R_Option::SaveSystemConfiguration(void)
{
	int createDataFlag1 = 0;
	FILE *fr1 = fopen("SysDat01.dat", "rb");
	if (fr1 == NULL)
		createDataFlag1 = 1;
	else
		fclose(fr1);
	if (createDataFlag1 != 1)
	{
		FILE *fp1 = fopen("SysDat01.dat", "wb");
		fwrite(&sysc, sizeof(sysc), 1, fp1);
		fclose(fp1);
	}
}

void R_Option::SaveDefaulSystemConfiguration(void)
{
	///////////////////////////////////// SysDat01
	sysc.screensizeX = SS_NORMAL_X;
	sysc.screensizeY = SS_NORMAL_Y;
	sysc.TextSpeed = TXT_SPEED_MEDIUM;
	sysc.VolumeBGM = OP_VOLUME_M;
	sysc.VolumeSE = OP_VOLUME_M;

	// - If no data created, create New File for System Configuration data - //
	int createDataFlag1 = 0;
	FILE *fr1 = fopen("SysDat01.dat", "rb");
	if (fr1 == NULL)
		createDataFlag1 = 1;
	else
		fclose(fr1);
	if (createDataFlag1 != 1)
	{
		FILE *fp1 = fopen("SysDat01.dat", "wb");
		fwrite(&sysc, sizeof(sysc), 1, fp1);
		fclose(fp1);
	}

}

void R_Option::SaveAllDefaultSystemData(void)
{
	///////////////////////////////////// SysDat01
	sysc.screensizeX = SS_NORMAL_X;
	sysc.screensizeY = SS_NORMAL_Y;
	sysc.TextSpeed = TXT_SPEED_MEDIUM;
	sysc.VolumeBGM = OP_VOLUME_M;
	sysc.VolumeSE = OP_VOLUME_M;

	// - If no data created, create New File for System Configuration data - //
	int createDataFlag1 = 0;
	FILE *fr1 = fopen("SysDat01.dat", "rb");
	if (fr1 == NULL)
		createDataFlag1 = 1;
	else
		fclose(fr1);
	if (createDataFlag1 != 1)
	{
		FILE *fp1 = fopen("SysDat01.dat", "wb");
		fwrite(&sysc, sizeof(sysc), 1, fp1);
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
	if (createDataFlag2 != 1)
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
	if (createDataFlag3 != 1)
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
	if (createDataFlag4 != 1)
	{
		FILE *fp4 = fopen("SysDat04.dat", "wb");
		fwrite(&brRank, sizeof(brRank), 1, fp4);
		fclose(fp4);
	}
}
void R_Option::LoadCurrentSystemConfiguration(void)
{
	if (loadFlag == 0)
	{

		FILE *fgi = fopen("SysDat01.dat", "rb");
		if (fgi != NULL)
		{
			fread(&sysc, sizeof(sysc), 1, fgi);
		}
		fclose(fgi);
	}
}

void R_Option::ReleaseData(void)
{
	DeleteGraph(img_OptionBG);
	DeleteGraph(img_VolumeBGM);
	DeleteGraph(img_VolumeSE);
	DeleteGraph(img_TextSpeed);
	DeleteGraph(img_Save);
	DeleteGraph(img_Reset);
	DeleteGraph(img_ResetAll);
	DeleteGraph(img_Cancel);
	DeleteGraph(img_LeftArrow);
	DeleteGraph(img_RightArrow);
	DeleteGraph(img_Mute);
	DeleteGraph(img_XS);
	DeleteGraph(img_S);
	DeleteGraph(img_M);
	DeleteGraph(img_L);
	DeleteGraph(img_XL);
}
