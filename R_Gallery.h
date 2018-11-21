#pragma once
#include "R_Gallery2.h"
#include "DataList.h"

class R_Gallery
{
	R_Gallery2 rGL2;

public:
	int loadFlag, loadFlag2;
	GalleryStatus gStat;
	SaveData SD1, SD2, SD3, SD4, SD5;

	struct
	{
		int img_Enemy[17];
		int img_MaleChar;
		int img_FemaleChar;
		int img_Mother;
		int img_Driver;
		int img_SariSariStore;
		int img_GalleryBG;
		int img_Back;
		int img_TitleMark;
		int img_TipsBar;
	} iconList;


	R_Gallery(void);
	~R_Gallery(void);

	void LoadGalleryIcons(void);
	void DisplayGalleryIcons(int screensizeX, int screensizeY);
	int ActionTaken(int cursorX, int cursorY, int cursorFlag);
	int ShowGallery(int cursorX, int cursorY, int cursorFlag, int galleryNumber, int screensizeX, int screensizeY);
	void ReadData(void);
	void LoadGal(int galleryNumber);

	void UpdateGallery(void);

	void ReleaseData(void);
};



