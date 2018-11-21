
#ifndef		DATALIST_h
#define		DATALIST_h

#include <Windows.h>
#include <NuiApi.h>
#include <math.h>
#pragma comment (lib, "kinect10.lib")

#define HIP_CENTER					NUI_SKELETON_POSITION_HIP_CENTER
#define SPINE							NUI_SKELETON_POSITION_SPINE
#define SHOULDER_CENTER		NUI_SKELETON_POSITION_SHOULDER_CENTER
#define HEAD							NUI_SKELETON_POSITION_HEAD
#define SHOULDER_LEFT			NUI_SKELETON_POSITION_SHOULDER_LEFT
#define ELBOW_LEFT				NUI_SKELETON_POSITION_ELBOW_LEFT
#define WRIST_LEFT					NUI_SKELETON_POSITION_WRIST_LEFT
#define HAND_LEFT					NUI_SKELETON_POSITION_HAND_LEFT
#define SHOULDER_RIGHT		NUI_SKELETON_POSITION_SHOULDER_RIGHT
#define ELBOW_RIGHT				NUI_SKELETON_POSITION_ELBOW_RIGHT
#define WRIST_RIGHT				NUI_SKELETON_POSITION_WRIST_RIGHT
#define HAND_RIGHT					NUI_SKELETON_POSITION_HAND_RIGHT
#define HIP_LEFT						NUI_SKELETON_POSITION_HIP_LEFT
#define KNEE_LEFT					NUI_SKELETON_POSITION_KNEE_LEFT
#define ANKLE_LEFT					NUI_SKELETON_POSITION_ANKLE_LEFT
#define FOOT_LEFT					NUI_SKELETON_POSITION_FOOT_LEFT
#define HIP_RIGHT					    NUI_SKELETON_POSITION_HIP_RIGHT
#define KNEE_RIGHT					NUI_SKELETON_POSITION_KNEE_RIGHT
#define ANKLE_RIGHT				NUI_SKELETON_POSITION_ANKLE_RIGHT
#define FOOT_RIGHT					NUI_SKELETON_POSITION_FOOT_RIGHT

#define xLine                             1
#define yLine                             2
#define zLine                             3


// - Screen Size - //
const int 	SS_NORMAL_X = 800;
const int	SS_NORMAL_Y = 600;

// - Cursor Pointer Size - //
#define		CP_XY												48

// - Friendly Tips count - //
#define		FT_TOTAL											8

// - Game Status - //
#define		SPLASH											0
#define		MAINMENU										1
#define		STORYMODE									2
#define		BOSSRUSH										3
#define		GALLERY											4
#define		OPTION											5
#define		EXIT													6
#define		STORYNEW										7
#define		BOSSRUSHMODE							8

// - Graphics used in StoryMode SELECTION - //
#define		SM_ICON_X										200
#define		SM_ICON_Y										80
#define		SM_CHAR_X										250
#define		SM_CHAR_Y										400
#define		SM_NEW											"./SourceFiles/SystemDesigns/StoryMode/New.png"
#define		SM_LOAD											"./SourceFiles/SystemDesigns/StoryMode/Load.png"
#define		SM_BOSSRUSH								"./SourceFiles/SystemDesigns/StoryMode/BossRush.png"
#define		SM_RANKING									"./SourceFiles/SystemDesigns/StoryMode/Ranking.png"
#define		SM_CANCEL										"./SourceFiles/SystemDesigns/StoryMode/Cancel.png"
#define		SM_MALE											"./SourceFiles/SystemDesigns/StoryMode/SelectMale.png"
#define		SM_FEMALE									"./SourceFiles/SystemDesigns/StoryMode/SelectFemale.png"

// - Graphics used in LOADING SCREEN - //
#define		G_SPLASHSCREEN							"./SourceFiles/SystemDesigns/MainMenu/ScreenSplash.png"
#define		FT_1													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips1.png"
#define		FT_2													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips2.png"
#define		FT_3													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips3.png"
#define		FT_4													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips4.png"
#define		FT_5													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips5.png"
#define		FT_6													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips6.png"
#define		FT_7													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips7.png"
#define		FT_8													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips8.png"
#define		FT_9													"./SourceFiles/SystemDesigns/FriendlyTips/FriendlyTips9.png"
#define		DYK1												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow1.png"
#define		DYK2												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow2.png"
#define		DYK3												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow3.png"
#define		DYK4												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow4.png"
#define		DYK5												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow5.png"
#define		DYK6												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow6.png"
#define		DYK7												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow7.png"
#define		DYK8												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow8.png"
#define		DYK9												"./SourceFiles/SystemDesigns/FriendlyTips/DidYouKnow9.png"


// Graphics used in scenes
#define		SCENE1											"./SourceFiles/SystemDesigns/StoryMode/Scene1.png"
#define		SCENE2											"./SourceFiles/SystemDesigns/StoryMode/Scene2.png"
#define		SCENE3											"./SourceFiles/SystemDesigns/StoryMode/Scene3.png"
#define		SCENE4											"./SourceFiles/SystemDesigns/StoryMode/Scene4.png"
#define		SCENE5											"./SourceFiles/SystemDesigns/StoryMode/Scene5.png"
#define		SCENE6											"./SourceFiles/SystemDesigns/StoryMode/Scene6.png"
#define		SCENE7											"./SourceFiles/SystemDesigns/StoryMode/Scene7.png"
#define		SCENE8											"./SourceFiles/SystemDesigns/StoryMode/Scene8.png"


// Graphics used in R_MainMenu
#define		G_INT_MAINMENU_X							120
#define		G_INT_MAINMENU_Y						60
#define		G_MAINMENU									"./SourceFiles/SystemDesigns/MainMenu/MainMenu.png"
#define		G_STORYMODE								"./SourceFiles/SystemDesigns/MainMenu/StoryMode.png"
#define		G_BOSSRUSH									"./SourceFiles/SystemDesigns/MainMenu/BossRush.png"
#define		G_GALLERY										"./SourceFiles/SystemDesigns/MainMenu/Gallery.png"
#define		G_OPTION										"./SourceFiles/SystemDesigns/MainMenu/Option.png"
#define		G_EXIT												"./SourceFiles/SystemDesigns/MainMenu/Exit.png"
#define		G_CURSORPOINTER						"./SourceFiles/SystemDesigns/CursorPointer2.png"

// Graphics used in R_Gallery
#define		GAL_INT_ICON_X								150
#define		GAL_INT_ICON_Y								80
#define		G_ILLUST_X										400
#define		G_ILLUST_Y										600
#define		G_DESC_X										300
#define		G_DESC_Y										500
#define		GAL_TITLEMARK								"./SourceFiles/SystemDesigns/Gallery/Title_Mark.png"
#define		GAL_TIPSBAR									"./SourceFiles/SystemDesigns/Gallery/TipsBar.png"
#define		GAL_GALLERY_BG							"./SourceFiles/SystemDesigns/Gallery/Gallery.png"
#define		GAL_BACK_ICON								"./SourceFiles/SystemDesigns/Gallery/Back.png"
#define		GAL_LEFTARROW							"./SourceFiles/SystemDesigns/Gallery/LeftArrow.png"
#define		GAL_RIGHTARROW							"./SourceFiles/SystemDesigns/Gallery/RightArrow.png"
#define		GAL_DWENDE_ICON						"./SourceFiles/SystemDesigns/Gallery/Dwende.png"
#define		GAL_DWENDE_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Dwende_L.png"
#define		GAL_DWENDE_ILLUST						"./SourceFiles/SystemDesigns/Gallery/Dwende_Illust.png"
#define		GAL_DWENDE_DESC						"./SourceFiles/SystemDesigns/Gallery/Dwende_Text.png"
#define		GAL_TIYANAK_ICON							"./SourceFiles/SystemDesigns/Gallery/Tiyanak.png"
#define		GAL_TIYANAK_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Tiyanak_L.png"
#define		GAL_TIYANAK_ILLUST						"./SourceFiles/SystemDesigns/Gallery/Tiyanak_Illust.png"
#define		GAL_TIYANAK_DESC						"./SourceFiles/SystemDesigns/Gallery/Tiyanak_Text.png"
#define		GAL_ENGKANTO_ICON						"./SourceFiles/SystemDesigns/Gallery/Engkanto.png"
#define		GAL_ENGKANTO_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Engkanto_L.png"
#define		GAL_ENGKANTO_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Engkanto_Illust.png"
#define		GAL_ENGKANTO_DESC					"./SourceFiles/SystemDesigns/Gallery/Engkanto_Text.png"
#define		GAL_MAMBABARANG_ICON				"./SourceFiles/SystemDesigns/Gallery/Mambabarang.png"
#define		GAL_MAMBABARANG_ICON_L			"./SourceFiles/SystemDesigns/Gallery/Mambabarang_L.png"
#define		GAL_MAMBABARANG_ILLUST			"./SourceFiles/SystemDesigns/Gallery/Mambabarang_Illust.png"
#define		GAL_MAMBABARANG_DESC			"./SourceFiles/SystemDesigns/Gallery/Mambabarang_Text.png"
#define		GAL_MANGKUKULAM_ICON				"./SourceFiles/SystemDesigns/Gallery/Mangkukulam.png"
#define		GAL_MANGKUKULAM_ICON_L			"./SourceFiles/SystemDesigns/Gallery/Mangkukulam_L.png"
#define		GAL_MANGKUKULAM_ILLUST			"./SourceFiles/SystemDesigns/Gallery/Mangkukulam_Illust.png"
#define		GAL_MANGKUKULAM_DESC			"./SourceFiles/SystemDesigns/Gallery/Mangkukulam_Text.png"
#define		GAL_SIGBIN_ICON							"./SourceFiles/SystemDesigns/Gallery/Sigbin.png"
#define		GAL_SIGBIN_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Sigbin_L.png"
#define		GAL_SIGBIN_ILLUST							"./SourceFiles/SystemDesigns/Gallery/Sigbin_Illust.png"
#define		GAL_SIGBIN_DESC							"./SourceFiles/SystemDesigns/Gallery/Sigbin_Text.png"
#define		GAL_ASWANG_ICON						"./SourceFiles/SystemDesigns/Gallery/Aswang.png"
#define		GAL_ASWANG_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Aswang_L.png"
#define		GAL_ASWANG_ILLUST						"./SourceFiles/SystemDesigns/Gallery/Aswang_Illust.png"
#define		GAL_ASWANG_DESC						"./SourceFiles/SystemDesigns/Gallery/Aswang_Text.png"
#define		GAL_SANTELMO_ICON						"./SourceFiles/SystemDesigns/Gallery/Santelmo.png"
#define		GAL_SANTELMO_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Santelmo_L.png"
#define		GAL_SANTELMO_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Santelmo_Illust.png"
#define		GAL_SANTELMO_DESC					"./SourceFiles/SystemDesigns/Gallery/Santelmo_Text.png"
#define		GAL_PASATSAT_ICON						"./SourceFiles/SystemDesigns/Gallery/Pasatsat.png"
#define		GAL_PASATSAT_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Pasatsat_L.png"
#define		GAL_PASATSAT_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Pasatsat_Illust.png"
#define		GAL_PASATSAT_DESC						"./SourceFiles/SystemDesigns/Gallery/Pasatsat_Text.png"
#define		GAL_EKEK_ICON								"./SourceFiles/SystemDesigns/Gallery/Ekek.png"
#define		GAL_EKEK_ICON_L							"./SourceFiles/SystemDesigns/Gallery/Ekek_L.png"
#define		GAL_EKEK_ILLUST							"./SourceFiles/SystemDesigns/Gallery/Ekek_Illust.png"
#define		GAL_EKEK_DESC							"./SourceFiles/SystemDesigns/Gallery/Ekek_Text.png"
#define		GAL_WAKWAK_ICON						"./SourceFiles/SystemDesigns/Gallery/Wakwak.png"
#define		GAL_WAKWAK_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Wakwak_L.png"
#define		GAL_WAKWAK_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Wakwak_Illust.png"
#define		GAL_WAKWAK_DESC						"./SourceFiles/SystemDesigns/Gallery/Wakwak_Text.png"
#define		GAL_BUNGISNGIS_ICON					"./SourceFiles/SystemDesigns/Gallery/Bungisngis.png"
#define		GAL_BUNGISNGIS_ICON_L				"./SourceFiles/SystemDesigns/Gallery/Bungisngis_L.png"
#define		GAL_BUNGISNGIS_ILLUST				"./SourceFiles/SystemDesigns/Gallery/Bungisngis_Illust.png"
#define		GAL_BUNGISNGIS_DESC					"./SourceFiles/SystemDesigns/Gallery/Bungisngis_Text.png"
#define		GAL_MULTO_ICON							"./SourceFiles/SystemDesigns/Gallery/Multo.png"
#define		GAL_MULTO_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Multo_L.png"
#define		GAL_MULTO_ILLUST							"./SourceFiles/SystemDesigns/Gallery/Multo_Illust.png"
#define		GAL_MULTO_DESC							"./SourceFiles/SystemDesigns/Gallery/Multo_Text.png"
#define		GAL_BANGUNGOT_ICON					"./SourceFiles/SystemDesigns/Gallery/Bangungot.png"
#define		GAL_BANGUNGOT_ICON_L				"./SourceFiles/SystemDesigns/Gallery/Bangungot_L.png"
#define		GAL_BANGUNGOT_ILLUST				"./SourceFiles/SystemDesigns/Gallery/Bangungot_Illust.png"
#define		GAL_BANGUNGOT_DESC					"./SourceFiles/SystemDesigns/Gallery/Bangungot_Text.png"
#define		GAL_BERBEROKA_ICON					"./SourceFiles/SystemDesigns/Gallery/Berberoka.png"
#define		GAL_BERBEROKA_ICON_L				"./SourceFiles/SystemDesigns/Gallery/Berberoka_L.png"
#define		GAL_BERBEROKA_ILLUST				"./SourceFiles/SystemDesigns/Gallery/Berberoka_Illust.png"
#define		GAL_BERBEROKA_DESC					"./SourceFiles/SystemDesigns/Gallery/Berberoka_Text.png"
#define		GAL_TIKBALANG_ICON						"./SourceFiles/SystemDesigns/Gallery/Tikbalang.png"
#define		GAL_TIKBALANG_ICON_L					"./SourceFiles/SystemDesigns/Gallery/Tikbalang_L.png"
#define		GAL_TIKBALANG_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Tikbalang_Illust.png"
#define		GAL_TIKBALANG_DESC					"./SourceFiles/SystemDesigns/Gallery/Tikbalang_Text.png"
#define		GAL_BAKUNAWA_ICON					"./SourceFiles/SystemDesigns/Gallery/Bakunawa.png"
#define		GAL_BAKUNAWA_ICON_L				"./SourceFiles/SystemDesigns/Gallery/Bakunawa_L.png"
#define		GAL_BAKUNAWA_ILLUST					"./SourceFiles/SystemDesigns/Gallery/Bakunawa_Illust.png"
#define		GAL_BAKUNAWA_DESC					"./SourceFiles/SystemDesigns/Gallery/Bakunawa_Text.png"
#define		GAL_MALECHAR_ICON						"./SourceFiles/SystemDesigns/Gallery/MaleChar.png"
#define		GAL_MALECHAR_ICON_L					"./SourceFiles/SystemDesigns/Gallery/MaleChar_L.png"
#define		GAL_MALECHAR_ILLUST					"./SourceFiles/SystemDesigns/Gallery/MaleChar_Illust.png"
#define		GAL_MALECHAR_DESC					"./SourceFiles/SystemDesigns/Gallery/MaleChar_Text.png"
#define		GAL_FEMALECHAR_ICON				"./SourceFiles/SystemDesigns/Gallery/FemaleChar.png"
#define		GAL_FEMALECHAR_ICON_L				"./SourceFiles/SystemDesigns/Gallery/FemaleChar_L.png"
#define		GAL_FEMALECHAR_ILLUST				"./SourceFiles/SystemDesigns/Gallery/FemaleChar_Illust.png"
#define		GAL_FEMALECHAR_DESC				"./SourceFiles/SystemDesigns/Gallery/FemaleChar_Text.png"
#define		GAL_MOTHER_ICON							"./SourceFiles/SystemDesigns/Gallery/Mother.png"
#define		GAL_MOTHER_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Mother_L.png"
#define		GAL_MOTHER_ILLUST						"./SourceFiles/SystemDesigns/Gallery/Mother_Illust.png"
#define		GAL_MOTHER_DESC						"./SourceFiles/SystemDesigns/Gallery/Mother_Text.png"
#define		GAL_DRIVER_ICON							"./SourceFiles/SystemDesigns/Gallery/Driver.png"
#define		GAL_DRIVER_ICON_L						"./SourceFiles/SystemDesigns/Gallery/Driver_L.png"
#define		GAL_DRIVER_ILLUST						"./SourceFiles/SystemDesigns/Gallery/Driver_Illust.png"
#define		GAL_DRIVER_DESC							"./SourceFiles/SystemDesigns/Gallery/Driver_Text.png"
#define		GAL_SARISARISTORE_ICON				"./SourceFiles/SystemDesigns/Gallery/SariSariStore.png"
#define		GAL_SARISARISTORE_ICON_L			"./SourceFiles/SystemDesigns/Gallery/SariSariStore_L.png"
#define		GAL_SARISARISTORE_ILLUST			"./SourceFiles/SystemDesigns/Gallery/SariSariStore_Illust.png"
#define		GAL_SARISARISTORE_DESC			"./SourceFiles/SystemDesigns/Gallery/SariSariStore_Text.png"

// - Graphics used in OPTION -//
#define		OP_ICON_X										200
#define		OP_ICON_Y										80
#define		OP_LOGO_X										200
#define		OP_LOGO_Y										50
#define		OP_BAR_X										650
#define		OP_BAR_Y										50
#define		OP_SPACE_X									75
#define		OP_SPACE_Y									30
#define		OP_ARROW_X									50
#define		OP_ARROW_Y									50
#define		OP_BACKGROUND							"./SourceFiles/SystemDesigns/Option/Option.png"
#define		OP_VOLUMEBGM								"./SourceFiles/SystemDesigns/Option/VolumeBGM.png"
#define		OP_VOLUMESE								"./SourceFiles/SystemDesigns/Option/VolumeSE.png"
#define		OP_TEXTSPEED								"./SourceFiles/SystemDesigns/Option/TextSpeed.png"
#define		OP_LEFTARROW								"./SourceFiles/SystemDesigns/Option/LeftArrow.png"
#define		OP_RIGHTARROW							"./SourceFiles/SystemDesigns/Option/RightArrow.png"
#define		OP_BAR_1										"./SourceFiles/SystemDesigns/Option/Bar1.png"
#define		OP_BAR_2										"./SourceFiles/SystemDesigns/Option/Bar2.png"
#define		OP_BAR_3										"./SourceFiles/SystemDesigns/Option/Bar3.png"
#define		OP_BAR_4										"./SourceFiles/SystemDesigns/Option/Bar4.png"
#define		OP_BAR_5										"./SourceFiles/SystemDesigns/Option/Bar5.png"
#define		OP_BAR_6										"./SourceFiles/SystemDesigns/Option/Bar6.png"
#define		OP_SAVE											"./SourceFiles/SystemDesigns/Option/Save.png"
#define		OP_RESET										"./SourceFiles/SystemDesigns/Option/Reset.png"
#define		OP_RESETALL									"./SourceFiles/SystemDesigns/Option/ResetAll.png"
#define		OP_CANCEL										"./SourceFiles/SystemDesigns/Option/Cancel.png"
// - Basic Color - //
#define		BC_WHITE										GetColor(255,255,255)
#define		BC_BLACK										GetColor(0,0,0)
#define		BC_BROWN										GetColor(180, 92, 33)

// - Basic Measurement - //
#define		STR_LEFT_X										10

// - SOUNDS - //
#define		BGM_MAINMENU								"./SourceFiles/Sounds/MainMenu.mp3"
#define		BGM_GALLERY								"./SourceFiles/Sounds/Gallery.mp3"
#define		BGM_OPTION									"./SourceFiles/Sounds/Option.mp3"
#define		BGM_GAMEOVER							"./SourceFiles/Sounds/GameOver.mp3"
#define		SE_SELECT										"./SourceFiles/Sounds/SelectSE.mp3"
#define		BGM_STAGE1									"./SourceFiles/Sounds/Stage1.mp3"
#define		BGM_STAGE2									"./SourceFiles/Sounds/Stage2.mp3"
#define		BGM_STAGE3									"./SourceFiles/Sounds/Stage3.mp3"
#define		BGM_STAGE4									"./SourceFiles/Sounds/Stage4.mp3"
#define		BGM_STAGE5									"./SourceFiles/Sounds/Stage5.mp3"
#define		SE_GETITEM1									"./SourceFiles/Sounds/GetItem1.mp3"
#define		SE_GETITEM2									"./SourceFiles/Sounds/GetItem2.mp3"
#define		SE_DAMAGED									"./SourceFiles/Sounds/Damaged.mp3"
#define		SE_ATTACK1									"./SourceFiles/Sounds/Attack1.mp3"
#define		SE_ATTACK2									"./SourceFiles/Sounds/Attack2.mp3"
#define		BGM_STORY									"./SourceFiles/Sounds/Story.mp3"

#define		SE_JUMP											"./SourceFiles/Sounds/Jump.mp3"
#define		SE_RUN											"./SourceFiles/Sounds/Run.mp3"
#define		BGM_BOSS										"./SourceFiles/Sounds/Boss.mp3"
#define		BGM_NEWSTAGE								"./SourceFiles/Sounds/NewStage.mp3"

// - SOUND VOLUME - //
#define		OP_VOLUME_MUTE						0
#define		OP_VOLUME_XS							(255 * 10 / 100)
#define		OP_VOLUME_S							(255 * 30  / 100)
#define		OP_VOLUME_M							(255 * 50 / 100)
#define		OP_VOLUME_L								(255 * 75 / 100)
#define		OP_VOLUME_XL							(255 * 100 / 100)

// - TEXT SPEED - //
#define		TXT_SPEED_SLOW						510
#define		TXT_SPEED_MEDIUM					380
#define		TXT_SPEED_FAST						250

// - Gallery Information - //
typedef struct
{
	/*
		enemy 0 : Dwende				enemy 1: Tiyanak				enemy 2: Engkanto				enemy 3: Mambabarang
		enemy 4: Mangkukulam		enemy 5: Sigbin					enemy 6: Aswang					enemy 7: Santelmo
		enemy 8: Pasatsat				enemy 9: Ekek					enemy 10: Wakwak				enemy 11: Bungisngis
		enemy 12: Multo				enemy 13: Bangungot			enemy 14: Berberoka				enemy 15: Tikbalang
		enemy 16: Bakunawa
	*/
	int enemyflag[17];
	int malecharflag;
	int femalecharflag;
	int motherflag;
	int driverflag;
	int sarisaristoreflag;

}GalleryStatus;


// - SYSTEM CONFIGURATION - //
typedef struct
{
	int screensizeX;
	int screensizeY;
	int VolumeSE;
	int VolumeBGM;
	int TextSpeed;
}SystemConfiguration;

// - STORY MODE RANKING - //
typedef struct
{
	int			TopScore[5];
	char		TopPlayer[5][10];

}StoryRank;

// - BOSS RUSH RANKING - //
typedef struct
{
	int			  TopScore[5];
	char		  TopPlayer[5][10];

}BossRushRank;


/////////////////////////////////// 3D MODELS
#define			M3D_MALECHAR					"./SourceFiles/3DModels/MaleChar/MaleChar.mqo"
#define			M3D_FEMALECHAR				"./SourceFiles/3DModels/FemaleChar/FemaleChar.mqo"
#define			M3D_BACKGROUND1			"./SourceFiles/3DModels/BackGround/BackGround1.mqo"
#define			M3D_BACKGROUND2			"./SourceFiles/3DModels/BackGround/BackGround2.mqo"
#define			M3D_ST1AR1						"./SourceFiles/3DModels/StageArea/Stage1/Area1.mqo"
#define			M3D_ST1AR2						"./SourceFiles/3DModels/StageArea/Stage1/Area2.mqo"
#define			M3D_ST1AR3						"./SourceFiles/3DModels/StageArea/Stage1/Area3.mqo"
#define			M3D_ST2AR1						"./SourceFiles/3DModels/StageArea/Stage2/Area1.mqo"
#define			M3D_ST2AR2						"./SourceFiles/3DModels/StageArea/Stage2/Area2.mqo"
#define			M3D_ST2AR3						"./SourceFiles/3DModels/StageArea/Stage2/Area3.mqo"
#define			M3D_ST2AR4						"./SourceFiles/3DModels/StageArea/Stage2/Area4.mqo"
#define			M3D_ST3AR1						"./SourceFiles/3DModels/StageArea/Stage3/Area1.mqo"
#define			M3D_ST3AR2						"./SourceFiles/3DModels/StageArea/Stage3/Area2.mqo"
#define			M3D_ST3AR3						"./SourceFiles/3DModels/StageArea/Stage3/Area3.mqo"
#define			M3D_ST3AR4						"./SourceFiles/3DModels/StageArea/Stage3/Area4.mqo"
#define			M3D_ST4AR1						"./SourceFiles/3DModels/StageArea/Stage4/Area1.mqo"
#define			M3D_ST4AR2						"./SourceFiles/3DModels/StageArea/Stage4/Area2.mqo"
#define			M3D_ST4AR3						"./SourceFiles/3DModels/StageArea/Stage4/Area3.mqo"
#define			M3D_ST4AR4						"./SourceFiles/3DModels/StageArea/Stage4/Area4.mqo"
#define			M3D_ST5AR1						"./SourceFiles/3DModels/StageArea/Stage5/Area1.mqo"
#define			M3D_ST5AR2						"./SourceFiles/3DModels/StageArea/Stage5/Area2.mqo"
#define			M3D_ST5AR3						"./SourceFiles/3DModels/StageArea/Stage5/Area3.mqo"
#define			M3D_ST5AR4						"./SourceFiles/3DModels/StageArea/Stage5/Area4.mqo"
#define			M3D_BOSSRUSH					"./SourceFiles/3DModels/StageArea/BossRush/Stage.mqo"

// ENEMIES
#define			Enemy_Radius						200.f
#define			Enemy_Height						400.f
#define			Boss_Radius							400.f
#define			Boss_Height							800.f
#define			M3D_DWENDE						"./SourceFiles/3DModels/Enemies/Dwende/Dwende.mqo"
#define			M3D_TIYANAK						"./SourceFiles/3DModels/Enemies/Tiyanak/Tiyanak.mqo"
#define			M3D_ENGKANTO					"./SourceFiles/3DModels/Enemies/Engkanto/Engkanto.mqo"
#define			M3D_MAMBABARANG			"./SourceFiles/3DModels/Enemies/Mambabarang/Mambabarang.mqo"
#define			M3D_MANGKUKULAM			"./SourceFIles/3DModels/Enemies/Mangkukulam/Mangkukulam.mqo"
#define			M3D_SIGBIN							"./SourceFiles/3DModels/Enemies/Sigbin/Sigbin.mqo"
#define			M3D_ASWANG						"./SourceFiles/3DModels/Enemies/Aswang/Aswang.mqo"
#define			M3D_SANTELMO					"./SourceFiles/3DModels/Enemies/Santelmo/Santelmo.mqo"
#define			M3D_PASATSAT					"./SourceFiles/3DModels/Enemies/Pasatsat/Pasatsat.mqo"
#define			M3D_EKEK							"./SourceFiles/3DModels/Enemies/Ekek/Ekek.mqo"
#define			M3D_WAKWAK					"./SourceFiles/3DModels/Enemies/Wakwak/Wakwak.mqo"
#define			M3D_BUNGISNGIS				"./SourceFiles/3DModels/Enemies/Bungisngis/Bungisngis.mqo"
#define			M3D_MULTO							"./SourceFiles/3DModels/Enemies/Multo/Multo.mqo"
#define			M3D_BANGUNGOT				"./SourceFiles/3DModels/Enemies/Bangungot/Bangungot.mqo"
#define			M3D_BERBEROKA				"./SourceFiles/3DModels/Enemies/Berberoka/Berberoka.mqo"
#define			M3D_TIKBALANG					"./SourceFiles/3DModels/Enemies/Tikbalang/Tikbalang.mqo"
#define			M3D_BAKUNAWA					"./SourceFiles/3DModels/Enemies/Bakunawa/Bakunawa.mqo"
#define			M3D_ATTACK1						"./SourceFiles/3DModels/Enemies/Attack1.mqo"

// 3D OBJECTS
#define			M3D_GARLIC						"./SourceFiles/3DModels/Objects/Garlic.mqo"
#define			M3D_GOLDENGARLIC			"./SourceFiles/3DModels/Objects/GoldenGarlic.mqo"
#define			M3D_SOYSAUCE					"./SourceFiles/3DModels/Objects/SoySauce.mqo"
#define			M3D_TREASUREBOX			"./SourceFiles/3DModels/Objects/TreasureBox.mqo"
#define			M3D_KEY								"./SourceFiles/3DModels/Objects/Key.mqo"

///// GAME OVER
#define			GO_X									400
#define			GO_Y									300
#define			GAMEOVER							"./SourceFiles/SystemDesigns/StoryMode/GameOver.png"

// GUI of 3D ACTION PART:
#define			GUI_COMPASS_X					50
#define			GUI_COMPASS_Y					50
#define			GUI_COMPASS_N					"./SourceFiles/SystemDesigns/Map/CompassN.png"
#define			GUI_COMPASS_E					"./SourceFiles/SystemDesigns/Map/CompassE.png"
#define			GUI_COMPASS_S					"./SourceFiles/SystemDesigns/Map/CompassS.png"
#define			GUI_COMPASS_W				"./SourceFiles/SystemDesigns/Map/CompassW.png"
#define			GUI_COMPASS_NE				"./SourceFiles/SystemDesigns/Map/CompassNE.png"
#define			GUI_COMPASS_NW				"./SourceFiles/SystemDesigns/Map/CompassNW.png"
#define			GUI_COMPASS_SE				"./SourceFiles/SystemDesigns/Map/CompassSE.png"
#define			GUI_COMPASS_SW				"./SourceFiles/SystemDesigns/Map/CompassSW.png"
#define			GUI_MAP_X							200
#define			GUI_MAP_Y							100
#define			GUI_MAP_ST1AR1				"./SourceFiles/SystemDesigns/Map/Stage1Area1.png"
#define			GUI_MAP_ST1AR2				"./SourceFiles/SystemDesigns/Map/Stage1Area2.png"
#define			GUI_MAP_ST1AR3				"./SourceFiles/SystemDesigns/Map/Stage1Area3.png"
#define			GUI_MAP_ST2AR1				"./SourceFIles/SystemDesigns/Map/Stage2Area1.png"
#define			GUI_MAP_ST2AR2				"./SourceFIles/SystemDesigns/Map/Stage2Area2.png"
#define			GUI_MAP_ST2AR3				"./SourceFiles/SystemDesigns/Map/Stage2Area3.png"
#define			GUI_MAP_ST2AR4				"./SourceFiles/SystemDesigns/Map/Stage2Area4.png"
#define			GUI_MAP_ST3AR1				"./SourceFIles/SystemDesigns/Map/Stage3Area1.png"
#define			GUI_MAP_ST3AR2				"./SourceFIles/SystemDesigns/Map/Stage3Area2.png"
#define			GUI_MAP_ST3AR3				"./SourceFiles/SystemDesigns/Map/Stage3Area3.png"
#define			GUI_MAP_ST3AR4				"./SourceFiles/SystemDesigns/Map/Stage3Area4.png"
#define			GUI_MAP_ST4AR1				"./SourceFIles/SystemDesigns/Map/Stage4Area1.png"
#define			GUI_MAP_ST4AR2				"./SourceFIles/SystemDesigns/Map/Stage4Area2.png"
#define			GUI_MAP_ST4AR3				"./SourceFiles/SystemDesigns/Map/Stage4Area3.png"
#define			GUI_MAP_ST4AR4				"./SourceFiles/SystemDesigns/Map/Stage4Area4.png"
#define			GUI_MAP_ST5AR1				"./SourceFIles/SystemDesigns/Map/Stage5Area1.png"
#define			GUI_MAP_ST5AR2				"./SourceFIles/SystemDesigns/Map/Stage5Area2.png"
#define			GUI_MAP_ST5AR3				"./SourceFiles/SystemDesigns/Map/Stage5Area3.png"
#define			GUI_MAP_ST5AR4				"./SourceFiles/SystemDesigns/Map/Stage5Area4.png"

#define			GUI_LIFE_X							130
#define			GUI_LIFE_Y							130
#define			GUI_LIFE								"./SourceFiles/SystemDesigns/Map/Life.png"
#define			GUI_LIFEG_X						64
#define			GUI_LIFEG_Y						64
#define			GUI_LIFEG							"./SourceFiles/SystemDesigns/Map/LifeGarlic.png"
#define			GUI_ITEM_X							130
#define			GUI_ITEM_Y							130
#define			GUI_ITEM1							"./SourceFiles/SystemDesigns/Map/Item1.png"
#define			GUI_ITEM2							"./SourceFiles/SystemDesigns/Map/Item2.png"
#define			GUI_SCORE_X						100
#define			GUI_SCORE_Y						64
#define			GUI_SCORE							"./SourceFiles/SystemDesigns/Map/Score.png"
#define			GUI_GAMECLEAR					"./SourceFiles/SystemDesigns/StoryMode/GameClear.png"
#define			GUI_ST1AR1							"./SourceFiles/SystemDesigns/StoryMode/ST1AR1.png"
#define			GUI_ST1AR2							"./SourceFIles/SystemDesigns/StoryMode/ST1AR2.png"
#define			GUI_ST1AR3							"./SourceFiles/SystemDesigns/StoryMode/ST1AR3.png"
#define			GUI_ST2AR1							"./SourceFiles/SystemDesigns/StoryMode/ST2AR1.png"
#define			GUI_ST2AR2							"./SourceFiles/SystemDesigns/StoryMode/ST2AR2.png"
#define			GUI_ST2AR3							"./SourceFIles/SystemDesigns/StoryMode/ST2AR3.png"
#define			GUI_ST2AR4							"./SourceFiles/SystemDesigns/StoryMode/ST2AR4.png"
#define			GUI_ST3AR1							"./SourceFiles/SystemDesigns/StoryMode/ST3AR1.png"
#define			GUI_ST3AR2							"./SourceFiles/SystemDesigns/StoryMode/ST3AR2.png"
#define			GUI_ST3AR3							"./SourceFIles/SystemDesigns/StoryMode/ST3AR3.png"
#define			GUI_ST3AR4							"./SourceFiles/SystemDesigns/StoryMode/ST3AR4.png"
#define			GUI_ST4AR1							"./SourceFiles/SystemDesigns/StoryMode/ST4AR1.png"
#define			GUI_ST4AR2							"./SourceFiles/SystemDesigns/StoryMode/ST4AR2.png"
#define			GUI_ST4AR3							"./SourceFIles/SystemDesigns/StoryMode/ST4AR3.png"
#define			GUI_ST4AR4							"./SourceFiles/SystemDesigns/StoryMode/ST4AR4.png"
#define			GUI_ST5AR1							"./SourceFiles/SystemDesigns/StoryMode/ST5AR1.png"
#define			GUI_ST5AR2							"./SourceFiles/SystemDesigns/StoryMode/ST5AR2.png"
#define			GUI_ST5AR3							"./SourceFIles/SystemDesigns/StoryMode/ST5AR3.png"
#define			GUI_ST5AR4							"./SourceFiles/SystemDesigns/StoryMode/ST5AR4.png"
#define			GUI_BOSSRUSHLOGO			"./SourceFiles/SystemDesigns/StoryMode/BossRushLogo.png"
#define			GUI_BOSS_NAME_X				150
#define			GUI_BOSS_NAME_Y				64
#define			GUI_BOSS_LIFE_X				32
#define			GUI_BOSS_LIFE_Y				32
#define			GUI_BOSS_NAME1				"./SourceFiles/SystemDesigns/Map/BossName1.png"
#define			GUI_BOSS_NAME2				"./SourceFiles/SystemDesigns/Map/BossName2.png"
#define			GUI_BOSS_NAME3				"./SourceFiles/SystemDesigns/Map/BossName3.png"
#define			GUI_BOSS_NAME4				"./SourceFiles/SystemDesigns/Map/BossName4.png"
#define			GUI_BOSS_NAME5				"./SourceFiles/SystemDesigns/Map/BossName5.png"
#define			GUI_BOSS_LIFE					"./SourceFiles/SystemDesigns/Map/BossLife.png"

#define			SAVE_X								150
#define			SAVE_Y								200
#define			SAVE_SD1NO						"./SourceFiles/SystemDesigns/SaveData/SD1NO.png"
#define			SAVE_SD2NO						"./SourceFiles/SystemDesigns/SaveData/SD2NO.png"
#define			SAVE_SD3NO						"./SourceFiles/SystemDesigns/SaveData/SD3NO.png"
#define			SAVE_SD4NO						"./SourceFiles/SystemDesigns/SaveData/SD4NO.png"
#define			SAVE_SD5NO						"./SourceFiles/SystemDesigns/SaveData/SD5NO.png"

#define			SAVE_SD1MST1					"./SourceFIles/SystemDesigns/SaveData/SD1MST1.png"
#define			SAVE_SD1MST2					"./SourceFiles/SystemDesigns/SaveData/SD1MST2.png"
#define			SAVE_SD1MST3					"./SourceFiles/SystemDesigns/SaveData/SD1MST3.png"
#define			SAVE_SD1MST4					"./SourceFiles/SystemDesigns/SaveData/SD1MST4.png"
#define			SAVE_SD1MST5					"./SourceFiles/SystemDesigns/SaveData/SD1MST5.png"

#define			SAVE_SD2MST1					"./SourceFiles/SystemDesigns/SaveData/SD2MST1.png"
#define			SAVE_SD2MST2					"./SourceFiles/SystemDesigns/SaveData/SD2MST2.png"
#define			SAVE_SD2MST3					"./SourceFiles/SystemDesigns/SaveData/SD2MST3.png"
#define			SAVE_SD2MST4					"./SourceFiles/SystemDesigns/SaveData/SD2MST4.png"
#define			SAVE_SD2MST5					"./SourceFiles/SystemDesigns/SaveData/SD2MST5.png"

#define			SAVE_SD3MST1					"./SourceFiles/SystemDesigns/SaveData/SD3MST1.png"
#define			SAVE_SD3MST2					"./SourceFiles/SystemDesigns/SaveData/SD3MST2.png"
#define			SAVE_SD3MST3					"./SourceFiles/SystemDesigns/SaveData/SD3MST3.png"
#define			SAVE_SD3MST4					"./SourceFiles/SystemDesigns/SaveData/SD3MST4.png"
#define			SAVE_SD3MST5					"./SourceFiles/SystemDesigns/SaveData/SD3MST5.png"

#define			SAVE_SD4MST1					"./SourceFiles/SystemDesigns/SaveData/SD4MST1.png"
#define			SAVE_SD4MST2					"./SourceFiles/SystemDesigns/SaveData/SD4MST2.png"
#define			SAVE_SD4MST3					"./SourceFiles/SystemDesigns/SaveData/SD4MST3.png"
#define			SAVE_SD4MST4					"./SourceFiles/SystemDesigns/SaveData/SD4MST4.png"
#define			SAVE_SD4MST5					"./SourceFiles/SystemDesigns/SaveData/SD4MST5.png"

#define			SAVE_SD5MST1					"./SourceFiles/SystemDesigns/SaveData/SD5MST1.png"
#define			SAVE_SD5MST2					"./SourceFiles/SystemDesigns/SaveData/SD5MST2.png"
#define			SAVE_SD5MST3					"./SourceFiles/SystemDesigns/SaveData/SD5MST3.png"
#define			SAVE_SD5MST4					"./SourceFiles/SystemDesigns/SaveData/SD5MST4.png"
#define			SAVE_SD5MST5					"./SourceFiles/SystemDesigns/SaveData/SD5MST5.png"
//////////////////////// ++++
#define			SAVE_SD1FST1					"./SourceFIles/SystemDesigns/SaveData/SD1FST1.png"
#define			SAVE_SD1FST2					"./SourceFiles/SystemDesigns/SaveData/SD1FST2.png"
#define			SAVE_SD1FST3					"./SourceFiles/SystemDesigns/SaveData/SD1FST3.png"
#define			SAVE_SD1FST4					"./SourceFiles/SystemDesigns/SaveData/SD1FST4.png"
#define			SAVE_SD1FST5					"./SourceFiles/SystemDesigns/SaveData/SD1FST5.png"

#define			SAVE_SD2FST1					"./SourceFiles/SystemDesigns/SaveData/SD2FST1.png"
#define			SAVE_SD2FST2					"./SourceFiles/SystemDesigns/SaveData/SD2FST2.png"
#define			SAVE_SD2FST3					"./SourceFiles/SystemDesigns/SaveData/SD2FST3.png"
#define			SAVE_SD2FST4					"./SourceFiles/SystemDesigns/SaveData/SD2FST4.png"
#define			SAVE_SD2FST5					"./SourceFiles/SystemDesigns/SaveData/SD2FST5.png"

#define			SAVE_SD3FST1					"./SourceFiles/SystemDesigns/SaveData/SD3FST1.png"
#define			SAVE_SD3FST2					"./SourceFiles/SystemDesigns/SaveData/SD3FST2.png"
#define			SAVE_SD3FST3					"./SourceFiles/SystemDesigns/SaveData/SD3FST3.png"
#define			SAVE_SD3FST4					"./SourceFiles/SystemDesigns/SaveData/SD3FST4.png"
#define			SAVE_SD3FST5					"./SourceFiles/SystemDesigns/SaveData/SD3FST5.png"

#define			SAVE_SD4FST1					"./SourceFiles/SystemDesigns/SaveData/SD4FST1.png"
#define			SAVE_SD4FST2					"./SourceFiles/SystemDesigns/SaveData/SD4FST2.png"
#define			SAVE_SD4FST3					"./SourceFiles/SystemDesigns/SaveData/SD4FST3.png"
#define			SAVE_SD4FST4					"./SourceFiles/SystemDesigns/SaveData/SD4FST4.png"
#define			SAVE_SD4FST5					"./SourceFiles/SystemDesigns/SaveData/SD4FST5.png"

#define			SAVE_SD5FST1					"./SourceFiles/SystemDesigns/SaveData/SD5FST1.png"
#define			SAVE_SD5FST2					"./SourceFiles/SystemDesigns/SaveData/SD5FST2.png"
#define			SAVE_SD5FST3					"./SourceFiles/SystemDesigns/SaveData/SD5FST3.png"
#define			SAVE_SD5FST4					"./SourceFiles/SystemDesigns/SaveData/SD5FST4.png"
#define			SAVE_SD5FST5					"./SourceFiles/SystemDesigns/SaveData/SD5FST5.png"

const float max_speed = 40.f;
const float gravity = 9.8f;
const int Stage1BossArea = 3;
const int Stage2BossArea = 4;
const int Stage3BossArea = 4;
const int Stage4BossArea = 4;
const int Stage5BossArea = 3;

typedef struct
{
	int ModelFlag; // 1 = Male, 2 = Female
	int Life; // maximum of 5 live
	int ItemFlag; // 1 = Arnis, 2 = Tirador
	int Score; // scoring
	int StageBossFlag[5]; // 0 = stage 1, 4 = stage5 if bossdefeated // 0 = not yet defeated, 1  = defeated
	int StageNextFlag[5]; // 1 = open collision for next stage
	int StageKeys[5]; // Keys get from each stage
	int EnemyDefeatedNumber[17]; // number of enemy defeated
	int CurrentStage;
	int CurrentArea;
	int CurrentAreaOld;
}SaveData;

////////// pause images
#define		PAUSE_BORDER							"./SourceFiles/SystemDesigns/StoryMode/PauseBorder.png"
#define		PAUSE_CONTINUE						"./SourceFiles/SystemDesigns/StoryMode/PauseContinue.png"
#define		PAUSE_EXIT									"./SourceFiles/SystemDesigns/StoryMode/PauseExit.png"

////////////////////////// VECTOR POSITION
#define		VEC_ORIGIN									VGet(0,0,0)
#define		VEC_HIDE									VGet(0,10000, 0)
#define		VEC_B											VGet(0,DX_PI_F, 0)

#define		NORTH									1
#define		EAST									2
#define		SOUTH									3
#define		WEST									4

#endif
