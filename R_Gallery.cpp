#include "R_Gallery.h"
#include <DxLib.h>
#include "DataList.h"

R_Gallery::R_Gallery(void)
{
	loadFlag = 0;


}

void R_Gallery::ReadData(void)
{

}

R_Gallery::~R_Gallery(void)
{
}

void R_Gallery::LoadGalleryIcons(void)
{
	if (loadFlag == 0)
	{
		iconList.img_GalleryBG = LoadGraph(GAL_GALLERY_BG);
		iconList.img_Back = LoadGraph(GAL_BACK_ICON);
		iconList.img_TitleMark = LoadGraph(GAL_TITLEMARK);
		iconList.img_TipsBar = LoadGraph(GAL_TIPSBAR);

		if (gStat.enemyflag[0] == 0)
			iconList.img_Enemy[0] = LoadGraph(GAL_DWENDE_ICON_L);
		else
			iconList.img_Enemy[0] = LoadGraph(GAL_DWENDE_ICON);

		if (gStat.enemyflag[1] == 0)
			iconList.img_Enemy[1] = LoadGraph(GAL_TIYANAK_ICON_L);
		else
			iconList.img_Enemy[1] = LoadGraph(GAL_TIYANAK_ICON);

		if (gStat.enemyflag[2] == 0)
			iconList.img_Enemy[2] = LoadGraph(GAL_ENGKANTO_ICON_L);
		else
			iconList.img_Enemy[2] = LoadGraph(GAL_ENGKANTO_ICON);

		if (gStat.enemyflag[3] == 0)
			iconList.img_Enemy[3] = LoadGraph(GAL_MAMBABARANG_ICON_L);
		else
			iconList.img_Enemy[3] = LoadGraph(GAL_MAMBABARANG_ICON);

		if (gStat.enemyflag[4] == 0)
			iconList.img_Enemy[4] = LoadGraph(GAL_MANGKUKULAM_ICON_L);
		else
			iconList.img_Enemy[4] = LoadGraph(GAL_MANGKUKULAM_ICON);

		if (gStat.enemyflag[5] == 0)
			iconList.img_Enemy[5] = LoadGraph(GAL_SIGBIN_ICON_L);
		else
			iconList.img_Enemy[5] = LoadGraph(GAL_SIGBIN_ICON);

		if (gStat.enemyflag[6] == 0)
			iconList.img_Enemy[6] = LoadGraph(GAL_ASWANG_ICON_L);
		else
			iconList.img_Enemy[6] = LoadGraph(GAL_ASWANG_ICON);

		if (gStat.enemyflag[7] == 0)
			iconList.img_Enemy[7] = LoadGraph(GAL_SANTELMO_ICON_L);
		else
			iconList.img_Enemy[7] = LoadGraph(GAL_SANTELMO_ICON);

		if (gStat.enemyflag[8] == 0)
			iconList.img_Enemy[8] = LoadGraph(GAL_PASATSAT_ICON_L);
		else
			iconList.img_Enemy[8] = LoadGraph(GAL_PASATSAT_ICON);

		if (gStat.enemyflag[9] == 0)
			iconList.img_Enemy[9] = LoadGraph(GAL_EKEK_ICON_L);
		else
			iconList.img_Enemy[9] = LoadGraph(GAL_EKEK_ICON);

		if (gStat.enemyflag[10] == 0)
			iconList.img_Enemy[10] = LoadGraph(GAL_WAKWAK_ICON_L);
		else
			iconList.img_Enemy[10] = LoadGraph(GAL_WAKWAK_ICON);

		if (gStat.enemyflag[11] == 0)
			iconList.img_Enemy[11] = LoadGraph(GAL_BUNGISNGIS_ICON_L);
		else
			iconList.img_Enemy[11] = LoadGraph(GAL_BUNGISNGIS_ICON);

		if (gStat.enemyflag[12] == 0)
			iconList.img_Enemy[12] = LoadGraph(GAL_MULTO_ICON_L);
		else
			iconList.img_Enemy[12] = LoadGraph(GAL_MULTO_ICON);

		if (gStat.enemyflag[13] == 0)
			iconList.img_Enemy[13] = LoadGraph(GAL_BANGUNGOT_ICON_L);
		else
			iconList.img_Enemy[13] = LoadGraph(GAL_BANGUNGOT_ICON);

		if (gStat.enemyflag[14] == 0)
			iconList.img_Enemy[14] = LoadGraph(GAL_BERBEROKA_ICON_L);
		else
			iconList.img_Enemy[14] = LoadGraph(GAL_BERBEROKA_ICON);

		if (gStat.enemyflag[15] == 0)
			iconList.img_Enemy[15] = LoadGraph(GAL_TIKBALANG_ICON_L);
		else
			iconList.img_Enemy[15] = LoadGraph(GAL_TIKBALANG_ICON);

		if (gStat.enemyflag[16] == 0)
			iconList.img_Enemy[16] = LoadGraph(GAL_BAKUNAWA_ICON_L);
		else
			iconList.img_Enemy[16] = LoadGraph(GAL_BAKUNAWA_ICON);

		if (gStat.malecharflag == 0)
			iconList.img_MaleChar = LoadGraph(GAL_MALECHAR_ICON_L);
		else
			iconList.img_MaleChar = LoadGraph(GAL_MALECHAR_ICON);

		if (gStat.femalecharflag == 0)
			iconList.img_FemaleChar = LoadGraph(GAL_FEMALECHAR_ICON_L);
		else
			iconList.img_FemaleChar = LoadGraph(GAL_FEMALECHAR_ICON);

		if (gStat.motherflag == 0)
			iconList.img_Mother = LoadGraph(GAL_MOTHER_ICON_L);
		else
			iconList.img_Mother = LoadGraph(GAL_MOTHER_ICON);

		if (gStat.driverflag == 0)
			iconList.img_Driver = LoadGraph(GAL_DRIVER_ICON_L);
		else
			iconList.img_Driver = LoadGraph(GAL_DRIVER_ICON);

		if (gStat.sarisaristoreflag == 0)
			iconList.img_SariSariStore = LoadGraph(GAL_SARISARISTORE_ICON_L);
		else
			iconList.img_SariSariStore = LoadGraph(GAL_SARISARISTORE_ICON);
		loadFlag = 1;
	}
}

void R_Gallery::DisplayGalleryIcons(int screensizeX, int screensizeY)
{
	int count = 0;

	DrawExtendGraph(0, 0, screensizeX, screensizeY, iconList.img_GalleryBG, TRUE);
	DrawExtendGraph(380, 20, 800, 40, iconList.img_TipsBar, TRUE);
	DrawGraph(0, 0, iconList.img_TitleMark, TRUE);

	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (count < 17)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_Enemy[count], TRUE);
			else if (count == 17)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_MaleChar, TRUE);
			else if (count == 18)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_FemaleChar, TRUE);
			else if (count == 19)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_Mother, TRUE);
			else if (count == 20)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_Driver, TRUE);
			else if (count == 21)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_SariSariStore, TRUE);
			else if (count == 23)
				DrawGraph((50 + (GAL_INT_ICON_X * column) + (30 * column)), (50 + (GAL_INT_ICON_Y * row) + (10 * row)), iconList.img_Back, TRUE);
			count++;
		}

	}

}

int R_Gallery::ActionTaken(int cursorX, int cursorY, int cursorFlag)
{
	int x1, x2;
	int y1, y2;
	int count = 0;

	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			x1 = (50 + (GAL_INT_ICON_X * column) + (30 * column));
			x2 = x1 + GAL_INT_ICON_X;

			y1 = (50 + (GAL_INT_ICON_Y * row) + (10 * row));
			y2 = y1 + GAL_INT_ICON_Y;

			if (((cursorX >= x1) && (cursorX <= x2)) && ((cursorY >= y1) && (cursorY <= y2)))
			{
				switch (count)
				{
				case 0:
					if (cursorFlag == 1 && gStat.enemyflag[0] != 0)		return 0;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips: Defeat 3 Dwende");
					break;
				case 1:
					if (cursorFlag == 1 && gStat.enemyflag[1] != 0)		return 1;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 3 Tiyanak");
					break;
				case 2:
					if (cursorFlag == 1 && gStat.enemyflag[2] != 0)		return 2;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 3 Engkanto");
					break;
				case 3:
					if (cursorFlag == 1 && gStat.enemyflag[3] != 0)		return 3;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 3 Mambabarang");
					break;
				case 4:
					if (cursorFlag == 1 && gStat.enemyflag[4] != 0)		return 4;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips: Clear Stage 1");
					break;
				case 5:
					if (cursorFlag == 1 && gStat.enemyflag[5] != 0)		return 5;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Sigbin");
					break;
				case 6:
					if (cursorFlag == 1 && gStat.enemyflag[6] != 0)		return 6;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Stage 2");
					break;
				case 7:
					if (cursorFlag == 1 && gStat.enemyflag[7] != 0)		return 7;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Santelmo");
					break;
				case 8:
					if (cursorFlag == 1 && gStat.enemyflag[8] != 0)		return 8;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Pasatsat");
					break;
				case 9:
					if (cursorFlag == 1 && gStat.enemyflag[9] != 0)		return 9;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Ekek");
					break;
				case 10:
					if (cursorFlag == 1 && gStat.enemyflag[10] != 0)		return 10;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Wakwak");
					break;
				case 11:
					if (cursorFlag == 1 && gStat.enemyflag[11] != 0)		return 11;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips: Clear Stage 3");
					break;
				case 12:
					if (cursorFlag == 1 && gStat.enemyflag[12] != 0)		return 12;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Multo");
					break;
				case 13:
					if (cursorFlag == 1 && gStat.enemyflag[13] != 0)		return 13;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Stage 4");
					break;
				case 14:
					if (cursorFlag == 1 && gStat.enemyflag[14] != 0)		return 14;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Berberoka");
					break;
				case 15:
					if (cursorFlag == 1 && gStat.enemyflag[15] != 0)		return 15;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Defeat 5 Tikbalang");
					break;
				case 16:
					if (cursorFlag == 1 && gStat.enemyflag[16] != 0)		return 16;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Stage 5");
					break;
				case 17:
					if (cursorFlag == 1 && gStat.malecharflag != 0)		return 17;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips: Clear Story Mode");
					break;
				case 18:
					if (cursorFlag == 1 && gStat.femalecharflag != 0)		return 18;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Story Mode");
					break;
				case 19:
					if (cursorFlag == 1 && gStat.motherflag != 0)		return 19;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Story Mode");
					break;
				case 20:
					if (cursorFlag == 1 && gStat.driverflag != 0)		return 20;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Story Mode");
					break;
				case 21:
					if (cursorFlag == 1 && gStat.sarisaristoreflag != 0)		return 21;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips:	Clear Story Mode");
					break;

				case 23:
					if (cursorFlag == 1)		return 23;
					else							DrawFormatString(480, 21, BC_BLACK, "Tips: Back to Main Menu");
					break;

				}
			}

			count++;
		}
	}
	return -1;
}

int R_Gallery::ShowGallery(int cursorX, int cursorY, int cursorFlag, int galleryNumber, int screensizeX, int screensizeY)
{

	rGL2.ShowGalleryImage(screensizeX, screensizeY, galleryNumber);
	switch (rGL2.ActionTaken(cursorX, cursorY, cursorFlag))
	{
	case 1:  /*rGL2.ReleaseData();*/	 return -1;		break;

	}
	return galleryNumber;
}

void R_Gallery::LoadGal(int galleryNumber)
{
	if (loadFlag2 == 0)
		rGL2.LoadGalleryImage(galleryNumber);
	loadFlag2 = rGL2.loadFlag;
}

void R_Gallery::ReleaseData(void)
{
	for (int loop = 0; loop < 17; loop++)
		DeleteGraph(iconList.img_Enemy[loop]);
	DeleteGraph(iconList.img_MaleChar);
	DeleteGraph(iconList.img_FemaleChar);
	DeleteGraph(iconList.img_Mother);
	DeleteGraph(iconList.img_Driver);
	DeleteGraph(iconList.img_SariSariStore);
	DeleteGraph(iconList.img_GalleryBG);
	rGL2.ReleaseData();
}

void R_Gallery::UpdateGallery(void)
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

	// - Read Gallery Info - //
	FILE *fgi = fopen("SysDat02.dat", "rb");
	if (fgi != NULL)
	{
		fread(&gStat, sizeof(gStat), 1, fgi);
	}
	fclose(fgi);

	if (ExistFlag1 == 1)
	{
		for (int i = 0; i < 4; i++)
			if (SD1.EnemyDefeatedNumber[i] >= 3) // 1st stage rules defeat 3 enemies
				gStat.enemyflag[i] = 1;
		for (int i = 4; i < 17;i++)
			if (SD1.EnemyDefeatedNumber[i] >= 5 && (i != 4 && i != 6 && i != 11 && i != 13 && i != 16)) // >= 5; but may be added difficulty depends
				gStat.enemyflag[i] = 1;

		if (SD1.StageNextFlag[0] == 1) // if cleared stage 1
			gStat.enemyflag[4] = 1;
		if (SD1.StageNextFlag[1] == 1) // if cleared stage 2
			gStat.enemyflag[6] = 1;
		if (SD1.StageNextFlag[2] == 1) // if cleared stage 3
			gStat.enemyflag[11] = 1;
		if (SD1.StageNextFlag[3] == 1) // if cleared stage 4
			gStat.enemyflag[13] = 1;
		if (SD1.StageNextFlag[4] == 1)// if cleared stage 5
		{
			gStat.enemyflag[16] = 1;
			gStat.malecharflag = 1;
			gStat.femalecharflag = 1;
			gStat.motherflag = 1;
			gStat.driverflag = 1;
			gStat.sarisaristoreflag = 1;
		}
	}

	if (ExistFlag2 == 1)
	{
		for (int i = 0; i < 4; i++)
			if (SD2.EnemyDefeatedNumber[i] >= 3) // 1st stage rules defeat 3 enemies
				gStat.enemyflag[i] = 1;
		for (int i = 4; i < 17;i++)
			if (SD2.EnemyDefeatedNumber[i] >= 5 && (i != 4 && i != 6 && i != 11 && i != 13 && i != 16)) // >= 5; but may be added difficulty depends
				gStat.enemyflag[i] = 1;

		if (SD2.StageNextFlag[0] == 1) // if cleared stage 1
			gStat.enemyflag[4] = 1;
		if (SD2.StageNextFlag[1] == 1) // if cleared stage 2
			gStat.enemyflag[6] = 1;
		if (SD2.StageNextFlag[2] == 1) // if cleared stage 3
			gStat.enemyflag[11] = 1;
		if (SD2.StageNextFlag[3] == 1) // if cleared stage 4
			gStat.enemyflag[13] = 1;
		if (SD2.StageNextFlag[4] == 1)// if cleared stage 5
		{
			gStat.enemyflag[16] = 1;
			gStat.malecharflag = 1;
			gStat.femalecharflag = 1;
			gStat.motherflag = 1;
			gStat.driverflag = 1;
			gStat.sarisaristoreflag = 1;
		}
	}

	if (ExistFlag3 == 1)
	{
		for (int i = 0; i < 4; i++)
			if (SD3.EnemyDefeatedNumber[i] >= 3) // 1st stage rules defeat 3 enemies
				gStat.enemyflag[i] = 1;
		for (int i = 4; i < 17;i++)
			if (SD3.EnemyDefeatedNumber[i] >= 5 && (i != 4 && i != 6 && i != 11 && i != 13 && i != 16)) // >= 5; but may be added difficulty depends
				gStat.enemyflag[i] = 1;

		if (SD3.StageNextFlag[0] == 1) // if cleared stage 1
			gStat.enemyflag[4] = 1;
		if (SD3.StageNextFlag[1] == 1) // if cleared stage 2
			gStat.enemyflag[6] = 1;
		if (SD3.StageNextFlag[2] == 1) // if cleared stage 3
			gStat.enemyflag[11] = 1;
		if (SD3.StageNextFlag[3] == 1) // if cleared stage 4
			gStat.enemyflag[13] = 1;
		if (SD3.StageNextFlag[4] == 1)// if cleared stage 5
		{
			gStat.enemyflag[16] = 1;
			gStat.malecharflag = 1;
			gStat.femalecharflag = 1;
			gStat.motherflag = 1;
			gStat.driverflag = 1;
			gStat.sarisaristoreflag = 1;
		}
	}

	if (ExistFlag4 == 1)
	{
		for (int i = 0; i < 4; i++)
			if (SD4.EnemyDefeatedNumber[i] >= 3) // 1st stage rules defeat 3 enemies
				gStat.enemyflag[i] = 1;
		for (int i = 4; i < 17;i++)
			if (SD4.EnemyDefeatedNumber[i] >= 5 && (i != 4 && i != 6 && i != 11 && i != 13 && i != 16)) // >= 5; but may be added difficulty depends
				gStat.enemyflag[i] = 1;

		if (SD4.StageNextFlag[0] == 1) // if cleared stage 1
			gStat.enemyflag[4] = 1;
		if (SD4.StageNextFlag[1] == 1) // if cleared stage 2
			gStat.enemyflag[6] = 1;
		if (SD4.StageNextFlag[2] == 1) // if cleared stage 3
			gStat.enemyflag[11] = 1;
		if (SD4.StageNextFlag[3] == 1) // if cleared stage 4
			gStat.enemyflag[13] = 1;
		if (SD4.StageNextFlag[4] == 1)// if cleared stage 5
		{
			gStat.enemyflag[16] = 1;
			gStat.malecharflag = 1;
			gStat.femalecharflag = 1;
			gStat.motherflag = 1;
			gStat.driverflag = 1;
			gStat.sarisaristoreflag = 1;
		}
	}

	if (ExistFlag5 == 1)
	{
		for (int i = 0; i < 4; i++)
			if (SD5.EnemyDefeatedNumber[i] >= 3) // 1st stage rules defeat 3 enemies
				gStat.enemyflag[i] = 1;
		for (int i = 4; i < 17;i++)
			if (SD5.EnemyDefeatedNumber[i] >= 5 && (i != 4 && i != 6 && i != 11 && i != 13 && i != 16)) // >= 5; but may be added difficulty depends
				gStat.enemyflag[i] = 1;

		if (SD5.StageNextFlag[0] == 1) // if cleared stage 1
			gStat.enemyflag[4] = 1;
		if (SD5.StageNextFlag[1] == 1) // if cleared stage 2
			gStat.enemyflag[6] = 1;
		if (SD5.StageNextFlag[2] == 1) // if cleared stage 3
			gStat.enemyflag[11] = 1;
		if (SD5.StageNextFlag[3] == 1) // if cleared stage 4
			gStat.enemyflag[13] = 1;
		if (SD5.StageNextFlag[4] == 1)// if cleared stage 5
		{
			gStat.enemyflag[16] = 1;
			gStat.malecharflag = 1;
			gStat.femalecharflag = 1;
			gStat.motherflag = 1;
			gStat.driverflag = 1;
			gStat.sarisaristoreflag = 1;
		}
	}

	FILE *write = fopen("SysDat02.dat", "wb");
	fwrite(&gStat, sizeof(gStat), 1, write);
	fclose(write);
}
