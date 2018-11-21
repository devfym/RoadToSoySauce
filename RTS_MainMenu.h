#pragma once
#include "R_MainMenu.h"
#include "R_Gallery.h"
#include "R_Option.h"
#include "F_LoadingScreen.h"
#include "DataList.h"

class RTS_MainMenu
{

	// CURSOR measurements
	int x, y, flag;

	// STORYMODE measuements
	int storyFlag;

	// BOSSRUSH measurements
	int  bossFlag;



	// LOAD SCREEN measurements
	int Status, Wait;

	// SaveData measurements
	int img_SD1, img_SD2, img_SD3, img_SD4, img_SD5;
	SaveData SD1, SD2, SD3, SD4, SD5;
	int sdFlag1, sdFlag2, sdFlag3, sdFlag4, sdFlag5;

	// BGM measurements
	int snd_MainMenu;
	int snd_Gallery;
	int snd_Option;
	int snd_Select;


	R_MainMenu rMM;
	R_Gallery		rGL;
	R_Option		rOP;
	F_LoadingScreen fls;
	SystemConfiguration syscon;
	SaveData sd;
public:

	int SaveSelect;
	// GALLERY measurements
	int galLag, galFade, galFlag;
	RTS_MainMenu(SystemConfiguration m_syscon);
	~RTS_MainMenu(void);

	int GetStatus(void);
	void SetStatus(int stat);

	int CaseSplash(int count); // status = 0;
	void CaseMainMenu(void);   // status = 1;
	int CaseStoryMode(void); // status = 2;
	void CaseBossRush(void); // status = 3;
	void CaseGallery(void); /// status = 4;
	void CaseOption(void); // status = 5;
	void CaseExit(void); // status = 6:

	void OperateStoryMode(void); // kapag nakapag select na kung new, load,  except ranking
	void OperateBossRush(void);

	void LoadScreen(void);
	void LoadScreen2(void);
	int GetWait(void);
	void ResetWait(void);
	void RefreshWait(void);


	void CreateSaveData(int SaveNumber, int ModelNumber);

	void SetCursor(int cx, int cy, int cf);

	void LoadSaveData(void);
	void DrawSaveData(void);



	int	  ActionNewSaveData(void);
	int	  ActionLoadSaveData(void);
};

