#include "R_Gallery2.h"


R_Gallery2::R_Gallery2(void)
{
	loadFlag = 0;

}


R_Gallery2::~R_Gallery2(void)
{

}

void R_Gallery2::LoadGalleryImage(int galleryNumber)
{

	loadFlag = 1;
	img_LeftArrow = LoadGraph(GAL_LEFTARROW);
	img_RightArrow = LoadGraph(GAL_RIGHTARROW);
	img_BackGround = LoadGraph(GAL_GALLERY_BG);
	img_Back = LoadGraph(GAL_BACK_ICON);

	switch (galleryNumber)
	{
	case 0:	img_Gallery = LoadGraph(GAL_DWENDE_ILLUST);					img_Description = LoadGraph(GAL_DWENDE_DESC);						break;
	case 1: img_Gallery = LoadGraph(GAL_TIYANAK_ILLUST);					img_Description = LoadGraph(GAL_TIYANAK_DESC);						break;
	case 2: img_Gallery = LoadGraph(GAL_ENGKANTO_ILLUST);				img_Description = LoadGraph(GAL_ENGKANTO_DESC);					break;
	case 3: img_Gallery = LoadGraph(GAL_MAMBABARANG_ILLUST);		img_Description = LoadGraph(GAL_MAMBABARANG_DESC);			break;
	case 4: img_Gallery = LoadGraph(GAL_MANGKUKULAM_ILLUST);		img_Description = LoadGraph(GAL_MANGKUKULAM_DESC);			break;
	case 5: img_Gallery = LoadGraph(GAL_SIGBIN_ILLUST);						img_Description = LoadGraph(GAL_SIGBIN_DESC);							break;
	case 6: img_Gallery = LoadGraph(GAL_ASWANG_ILLUST);					img_Description = LoadGraph(GAL_ASWANG_DESC);						break;
	case 7: img_Gallery = LoadGraph(GAL_SANTELMO_ILLUST);				img_Description = LoadGraph(GAL_SANTELMO_DESC);					break;
	case 8: img_Gallery = LoadGraph(GAL_PASATSAT_ILLUST);				img_Description = LoadGraph(GAL_PASATSAT_DESC);					break;
	case 9: img_Gallery = LoadGraph(GAL_EKEK_ILLUST);						img_Description = LoadGraph(GAL_EKEK_DESC);							break;
	case 10: img_Gallery = LoadGraph(GAL_WAKWAK_ILLUST);				img_Description = LoadGraph(GAL_WAKWAK_DESC);					break;
	case 11: img_Gallery = LoadGraph(GAL_BUNGISNGIS_ILLUST);			img_Description = LoadGraph(GAL_BUNGISNGIS_DESC);				break;
	case 12: img_Gallery = LoadGraph(GAL_MULTO_ILLUST);					img_Description = LoadGraph(GAL_MULTO_DESC);							break;
	case 13: img_Gallery = LoadGraph(GAL_BANGUNGOT_ILLUST);			img_Description = LoadGraph(GAL_BANGUNGOT_DESC);				break;
	case 14: img_Gallery = LoadGraph(GAL_BERBEROKA_ILLUST);			img_Description = LoadGraph(GAL_BERBEROKA_DESC);				break;
	case 15: img_Gallery = LoadGraph(GAL_TIKBALANG_ILLUST);			img_Description = LoadGraph(GAL_TIKBALANG_DESC);					break;
	case 16: img_Gallery = LoadGraph(GAL_BAKUNAWA_ILLUST);			img_Description = LoadGraph(GAL_BAKUNAWA_DESC);				break;
	case 17: img_Gallery = LoadGraph(GAL_MALECHAR_ILLUST);			img_Description = LoadGraph(GAL_MALECHAR_DESC);					break;
	case 18: img_Gallery = LoadGraph(GAL_FEMALECHAR_ILLUST);		img_Description = LoadGraph(GAL_FEMALECHAR_DESC);				break;
	case 19: img_Gallery = LoadGraph(GAL_MOTHER_ILLUST);					img_Description = LoadGraph(GAL_MOTHER_DESC);						break;
	case 20: img_Gallery = LoadGraph(GAL_DRIVER_ILLUST);					img_Description = LoadGraph(GAL_DRIVER_DESC);						break;
	case 21: img_Gallery = LoadGraph(GAL_SARISARISTORE_ILLUST);	img_Description = LoadGraph(GAL_SARISARISTORE_DESC);			break;
	}
}

void R_Gallery2::ShowGalleryImage(int screensizeX, int screensizeY, int galleryNumber)
{
	DrawExtendGraph(0, 0, screensizeX, screensizeY, img_BackGround, TRUE);
	DrawGraph(20, 0, img_Gallery, TRUE);
	DrawGraph((50 + (GAL_INT_ICON_X * 3) + (30 * 3)), (50 + (GAL_INT_ICON_Y * 5) + (10 * 5)), img_Back, TRUE);
	DrawGraph(screensizeX - G_DESC_X - 50, 0, img_Description, TRUE);
}

int R_Gallery2::ActionTaken(int cursorX, int cursorY, int cursorFlag)
{
	int x1, x2;
	int y1, y2;
	x1 = (50 + (GAL_INT_ICON_X * 3) + (30 * 3));
	y1 = (50 + (GAL_INT_ICON_Y * 5) + (10 * 5));
	x2 = x1 + GAL_INT_ICON_X;
	y2 = y1 + GAL_INT_ICON_Y;

	if ((cursorX > x1 && cursorX < x2) && (cursorY > y1 && cursorY < y2) && cursorFlag == 1)
		return 1;

	return -1;
}

void R_Gallery2::ReleaseData(void)
{
	DeleteGraph(img_Gallery);
	DeleteGraph(img_LeftArrow);
	DeleteGraph(img_RightArrow);
	DeleteGraph(img_BackGround);
	DeleteGraph(img_Back);
	DeleteGraph(img_Description);

}
