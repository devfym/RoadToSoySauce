#pragma once
#include "DataList.h"
#include <DxLib.h>
class R_Gallery2
{

	int img_Gallery;
	int img_LeftArrow;
	int img_RightArrow;
	int img_BackGround;
	int img_Back;
	int img_Description;
public:

	int loadFlag;

	R_Gallery2(void);
	~R_Gallery2(void);
	void LoadGalleryImage(int galleryNumber);
	void ShowGalleryImage(int screensizeX, int screensizeY, int galleryNumber);
	int ActionTaken(int cursorX, int cursorY, int cursorFlag);
	void ReleaseData(void);
};

