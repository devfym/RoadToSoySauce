#include "StageHandler.h"


const float CameraRotate = DX_PI_F / 90;
const float CameraNorth = CameraRotate * 45;
const float CameraEast = CameraRotate * 135;
const float CameraSouth = CameraRotate * 0;
const float CameraWest = CameraRotate * 90;

void playerDir(VECTOR *pa, float *pca, int dir)
{
	switch (dir)
	{
	case 1: // NORTH
		*pa = VGet(0, 0, 0);
		*pca = CameraSouth;
		break;
	case 2: // EAST
		*pa = VGet(0, DX_PI_F / 2, 0);
		*pca = CameraEast;
		break;
	case 3: //SOUTH
		*pa = VGet(0, DX_PI_F, 0);
		*pca = CameraWest;
		break;
	case 4: // WEST
		*pa = VGet(0, DX_PI_F * 3 / 2, 0);
		*pca = CameraNorth;
		break;
	}
}

void playerCompass(int *count, int *direction, int dir)
{
	switch (dir)
	{
	case NORTH:
		*count = 0;
		*direction = 1;
		break;
	case EAST:
		*count = 45;
		*direction = 2;
		break;
	case SOUTH:
		*count = 90;
		*direction = 3;
		break;
	case WEST:
		*count = 135;
		*direction = 4;
		break;
	}
}

StageHandler::StageHandler(void)
{

}


StageHandler::~StageHandler(void)
{
}

void StageHandler::StageInitialization(SaveData m_sd)
{

	Position = VGet(0, 0, 0);
	BackGround = MV1LoadModel(M3D_BACKGROUND2);

	// ++ Load Stage Flags
	sd = m_sd;
	for (int i = 0; i < 5; i++)
	{
		StageBossDefeated[i] = sd.StageBossFlag[i];
		StageGoNextFlag[i] = sd.StageNextFlag[i];
		StageKeys[i] = sd.StageKeys[i];
	}
	// ++ Load Stage Flags

	// ++ Initialize all Collision line to move area
	AreaEnd1 = VEC_HIDE;
	AreaEnd2 = VEC_HIDE;
	AreaBack1 = VEC_HIDE;
	AreaBack2 = VEC_HIDE;
	NextStage1 = VEC_HIDE;
	NextStage2 = VEC_HIDE;
	// ++ Initialize all Collision line to move area

	// ++ Load Constant Stage Values and Flags
	switch (sd.CurrentStage)
	{
	case 1: // Stage 1
		if (sd.CurrentArea == 1)	// Stage 1 Area 1 = START STAGE
		{
			Model = MV1LoadModel(M3D_ST1AR1);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
			else
			{
				playerPosition = VGet(2200, 0, 8400);		playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, WEST);
			}
		} // Stage 1 Area 1
		if (sd.CurrentArea == 2)	// Stage 1 Area 2
		{
			Model = MV1LoadModel(M3D_ST1AR2);		AreaBack1 = VGet(-750, 100.f, 250.f);				AreaBack2 = VGet(-750, 100.f, -300.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 2);		playerCompass(&playerCount, &playerDirection, EAST);
			}
			else
			{
				playerPosition = VGet(17500, 0, -1350);	playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, WEST);
			}
		}
		if (sd.CurrentArea == 3) // Stage 1 Area 3 = BOSS STAGE
		{
			Model = MV1LoadModel(M3D_ST1AR3);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, EAST);
			}
		}
		break; // Stage 1

	case 2: // Stage 2
		if (sd.CurrentArea == 1)	// Stage 2 Area 1 = START STAGE
		{
			Model = MV1LoadModel(M3D_ST2AR1);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
			else
			{
				playerPosition = VGet(-2000, 0, 5500);		playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, EAST);
			}
		} // Stage 2 Area 1
		if (sd.CurrentArea == 2)	// Stage 2 Area 2
		{
			Model = MV1LoadModel(M3D_ST2AR2);		AreaBack1 = VGet(-1500, 100.f, -1100.f);				AreaBack2 = VGet(1500, 100.f, -1100.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, WEST);
			}
			else
			{
				playerPosition = VGet(2200, 0, 16000);	playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, EAST);
			}
		}
		if (sd.CurrentArea == 3)	// Stage 2 Area 3
		{
			Model = MV1LoadModel(M3D_ST2AR3);		AreaBack1 = VGet(-600, 100.f, -1500.f);				AreaBack2 = VGet(700, 100.f, -1500.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, WEST);
			}

		}
		if (sd.CurrentArea == 4) // Stage 2 Area 4 = BOSS STAGE
		{
			Model = MV1LoadModel(M3D_ST2AR4);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 2);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		}
		break; // Stage 2

	case 3: // Stage 3
		if (sd.CurrentArea == 1)	// Stage 3 Area 1 = START STAGE
		{
			Model = MV1LoadModel(M3D_ST3AR1);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
			else
			{
				playerPosition = VGet(-9250, 0, -6000);		playerDir(&playerAngle, &playerCamera, 2);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		} // Stage 3 Area 1
		if (sd.CurrentArea == 2)	// Stage 3 Area 2
		{
			Model = MV1LoadModel(M3D_ST3AR2);		AreaBack1 = VGet(1000, 100.f, 900.f);				AreaBack2 = VGet(1000, 100.f, -900.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
			else
			{
				playerPosition = VGet(2200, 0, 16000);	playerDir(&playerAngle, &playerCamera, 2);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		}
		if (sd.CurrentArea == 3)	// Stage 3 Area 3
		{
			Model = MV1LoadModel(M3D_ST3AR3);		AreaBack1 = VGet(1300, 100.f, 2600.f);				AreaBack2 = VGet(1300, 100.f, -2600.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}

		}
		if (sd.CurrentArea == 4) // Stage 3 Area 4 = BOSS STAGE
		{
			Model = MV1LoadModel(M3D_ST3AR4);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
		}
		break; // Stage 3

	case 4: // Stage 4
		if (sd.CurrentArea == 1)	// Stage 4 Area 1 = START STAGE
		{
			Model = MV1LoadModel(M3D_ST4AR1);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
			else
			{
				playerPosition = VGet(0, 0, -19000);		playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
		} // Stage 4 Area 1
		if (sd.CurrentArea == 2)	// Stage 4 Area 2
		{
			Model = MV1LoadModel(M3D_ST4AR2);		AreaBack1 = VGet(-2000, 100.f, -1000.f);				AreaBack2 = VGet(1300, 100.f, -1000.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
			else
			{
				playerPosition = VGet(2200, 0, 16000);	playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
		}
		if (sd.CurrentArea == 3)	// Stage 4 Area 3
		{
			Model = MV1LoadModel(M3D_ST4AR3);		AreaBack1 = VGet(-1100, 100.f, 1000.f);				AreaBack2 = VGet(1500, 100.f, 1000.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 3);		playerCompass(&playerCount, &playerDirection, NORTH);
			}

		}
		if (sd.CurrentArea == 4) // Stage 4 Area 4 = BOSS STAGE
		{
			Model = MV1LoadModel(M3D_ST4AR4);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		}
		break; // Stage 4

	case 5: // Stage 5
		if (sd.CurrentArea == 1)	// Stage 5 Area 1 = START STAGE
		{
			Model = MV1LoadModel(M3D_ST5AR1);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 4);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
			else
			{
				playerPosition = VGet(-8000, 0, -2000);		playerDir(&playerAngle, &playerCamera, 2);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		} // Stage 5 Area 1
		if (sd.CurrentArea == 2)	// Stage 5 Area 2
		{
			Model = MV1LoadModel(M3D_ST5AR2);		AreaBack1 = VGet(-1800, 100.f, -1500.f);				AreaBack2 = VGet(1300, 100.f, -1500.f);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, SOUTH);
			}
		}
		if (sd.CurrentArea == 3) // Stage 5 Area 3 = BOSS STAGE
		{
			Model = MV1LoadModel(M3D_ST5AR3);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, WEST);
			}
		}
		if (sd.CurrentArea == 4) // GAME END
		{
			Model = MV1LoadModel(M3D_ST5AR4);
			if (sd.CurrentAreaOld < sd.CurrentArea)
			{
				playerPosition = VEC_ORIGIN;				playerDir(&playerAngle, &playerCamera, 1);		playerCompass(&playerCount, &playerDirection, NORTH);
			}
		}
		break; // Stage 5

	}
	// ++ Load Constant Stage values and Flags
}

void StageHandler::StageDraw(void)
{
	MV1SetPosition(Model, Position);
	MV1SetPosition(BackGround, VGet(0, 0, 0));
	MV1DrawModel(Model);
	MV1DrawModel(BackGround);

}

void StageHandler::StageFlag(void)
{
	// Stage Flags that are flexible
	switch (sd.CurrentStage)
	{
	case 1: // Stage 1
		if (sd.CurrentArea == 1) // Stage 1 Area 1
		{
			// ++ Check The Area End
			if (StageKeys[0] >= 1) // If Already Get Key then Show Next Area
			{
				AreaEnd1 = VGet(1600, 100.f, 9400.f);			AreaEnd2 = VGet(2800, 100.f, 9400.f);
			}
			else						   // If Not yet Get Key then Hide Next Area
			{
				AreaEnd1 = VEC_HIDE;								AreaEnd2 = VEC_HIDE;
			}
			// ++ Check The Area End

			// ++ Check The Boss Area
			// This Area has no Boss

			// ++ Check The Stage Next
			// This Area has no Stage Next
		} // Stage 1 Area 1

		if (sd.CurrentArea == 2) // Stage 1 Area 2 , This Area Has Next Stage
		{
			// ++ Check Area End
			if (StageKeys[0] >= 2)
			{
				AreaEnd1 = VGet(18300, 100.f, -1050.f);		AreaEnd2 = VGet(18300, 100.f, -1600.f);
			}
			else
			{
				AreaEnd1 = VEC_HIDE;				AreaEnd2 = VEC_HIDE;
			}

			// ++ Check Next Stage
			if (StageGoNextFlag[0] == 1)
			{
				NextStage1 = VGet(1400, 100.f, -2100.f);	NextStage2 = VGet(2400, 100.f, -2100.f);
			}
			else
			{
				NextStage1 = VEC_HIDE;							NextStage2 = VEC_HIDE;
			}

			// ++ Check Boss Area
		} // Stage 1 Area 2
		if (sd.CurrentArea == 3)
		{
			if (StageBossDefeated[0] == 1)
			{
				AreaBack1 = VGet(600, 100, -4700);			AreaBack2 = VGet(600, 100, 5400);
			}
			else
			{
				AreaBack1 = VEC_HIDE;							AreaBack2 = VEC_HIDE;
			}
		}
		break; // Stage 1

	case 2: // Stage 2
		if (sd.CurrentArea == 1) // Stage 2 Area 1
		{
			// ++ Check The Area End
			if (StageKeys[1] >= 1) // If Already Get Key then Show Next Area
			{
				AreaEnd1 = VGet(-3900, 100.f, 7100.f);			AreaEnd2 = VGet(-400, 100.f, 7100.f);
			}
			else						   // If Not yet Get Key then Hide Next Area
			{
				AreaEnd1 = VEC_HIDE;								AreaEnd2 = VEC_HIDE;
			}
			// ++ Check The Area End

			// ++ Check The Boss Area
			// This Area has no Boss

			// ++ Check The Stage Next
			// This Area has no Stage Next
		} // Stage 1 Area 1

		if (sd.CurrentArea == 2) // Stage 2 Area 2 , This Area Has Next Stage
		{
			// ++ Check Area End
			if (StageKeys[1] >= 2)
			{
				AreaEnd1 = VGet(800, 100.f, 17800.f);		AreaEnd2 = VGet(3400, 100.f, 17800.f);
			}
			else
			{
				AreaEnd1 = VEC_HIDE;				AreaEnd2 = VEC_HIDE;
			}

		} // Stage 2 Area 3
		if (sd.CurrentArea == 3)
		{
			// nothing no area end, no next stage
		}
		if (sd.CurrentArea == 4)
		{
			// ++ Check Next Stage
			if (StageGoNextFlag[1] == 1)
			{
				NextStage1 = VGet(-700, 100.f, 1000.f);	NextStage2 = VGet(-700, 100.f, -900.f);
			}
			else
			{
				NextStage1 = VEC_HIDE;							NextStage2 = VEC_HIDE;
			}
		}
		break; // Stage 2

	case 3: // Stage 3
		if (sd.CurrentArea == 1) // Stage 3 Area 1
		{
			// ++ Check The Area End
			if (StageKeys[2] >= 1) // If Already Get Key then Show Next Area
			{
				AreaEnd1 = VGet(-9500, 100.f, 6800.f);			AreaEnd2 = VGet(-9500, 100.f, 5300.f);
			}
			else						   // If Not yet Get Key then Hide Next Area
			{
				AreaEnd1 = VEC_HIDE;								AreaEnd2 = VEC_HIDE;
			}
			// ++ Check The Area End

			// ++ Check The Boss Area
			// This Area has no Boss

			// ++ Check The Stage Next
			// This Area has no Stage Next
		} // Stage 3 Area 1

		if (sd.CurrentArea == 2) // Stage 3 Area 2 , This Area Has Next Stage
		{
			// ++ Check Area End
			if (StageKeys[2] >= 2)
			{
				AreaEnd1 = VGet(-9000, 100.f, -5000.f);		AreaEnd2 = VGet(-9000, 100.f, -7500.f);
			}
			else
			{
				AreaEnd1 = VEC_HIDE;				AreaEnd2 = VEC_HIDE;
			}

		} // Stage 3 Area 3
		if (sd.CurrentArea == 3)
		{
			// nothing no area end, no next stage
		}
		if (sd.CurrentArea == 4)
		{
			// ++ Check Next Stage
			if (StageGoNextFlag[2] == 1)
			{
				NextStage1 = VGet(1700, 100.f, 5000.f);	NextStage2 = VGet(1700, 100.f, -5000.f);
			}
			else
			{
				NextStage1 = VEC_HIDE;							NextStage2 = VEC_HIDE;
			}
		}
		break; // Stage 3

	case 4: // Stage 4
		if (sd.CurrentArea == 1) // Stage 4 Area 1
		{
			// ++ Check The Area End
			if (StageKeys[3] >= 1) // If Already Get Key then Show Next Area
			{
				AreaEnd1 = VGet(-500, 100.f, -19500.f);			AreaEnd2 = VGet(500, 100.f, -19500.f);
			}
			else						   // If Not yet Get Key then Hide Next Area
			{
				AreaEnd1 = VEC_HIDE;								AreaEnd2 = VEC_HIDE;
			}
			// ++ Check The Area End

			// ++ Check The Boss Area
			// This Area has no Boss

			// ++ Check The Stage Next
			// This Area has no Stage Next
		} // Stage 3 Area 1

		if (sd.CurrentArea == 2) // Stage 3 Area 2 , This Area Has Next Stage
		{
			// ++ Check Area End
			if (StageKeys[3] >= 2)
			{
				AreaEnd1 = VGet(-2000, 100.f, 11000.f);		AreaEnd2 = VGet(1300, 100.f, 11000.f);
			}
			else
			{
				AreaEnd1 = VEC_HIDE;				AreaEnd2 = VEC_HIDE;
			}

		} // Stage 4 Area 3
		if (sd.CurrentArea == 3)
		{
			// nothing no area end, no next stage
		}
		if (sd.CurrentArea == 4)
		{
			// ++ Check Next Stage
			if (StageGoNextFlag[3] == 1)
			{
				NextStage1 = VGet(-10000, 100.f, -1500.f);	NextStage2 = VGet(10000, 100.f, -1500.f);
			}
			else
			{
				NextStage1 = VEC_HIDE;							NextStage2 = VEC_HIDE;
			}
		}
		break; // Stage 4

	case 5: // Stage 5
		if (sd.CurrentArea == 1) // Stage 5 Area 1
		{
			// ++ Check The Area End
			if (StageKeys[4] >= 1) // If Already Get Key then Show Next Area
			{
				AreaEnd1 = VGet(-9000, 100.f, -3300.f);			AreaEnd2 = VGet(-9000, 100.f, -1200.f);
			}
			else						   // If Not yet Get Key then Hide Next Area
			{
				AreaEnd1 = VEC_HIDE;								AreaEnd2 = VEC_HIDE;
			}

		}
		if (sd.CurrentArea == 2) // Stage 3 Area 2 , This Area Has Next Stage
		{
			// ++ Check Area End
			if (StageKeys[4] >= 2)
			{
				AreaEnd1 = VGet(16300, 100.f, 7300.f);		AreaEnd2 = VGet(16300, 100.f, 5500.f);
			}
			else
			{
				AreaEnd1 = VEC_HIDE;				AreaEnd2 = VEC_HIDE;
			}
		}
	}
	// Stage Flags that are flexible
}

void StageHandler::ReleaseData()
{

	MV1DeleteModel(Model);
	MV1DeleteModel(BackGround);
	Position = VEC_ORIGIN;
	AreaEnd1 = VEC_ORIGIN;
	AreaEnd2 = VEC_ORIGIN;
	AreaBack1 = VEC_ORIGIN;
	AreaBack2 = VEC_ORIGIN;
	NextStage1 = VEC_ORIGIN;
	NextStage2 = VEC_ORIGIN;
	playerCount = 0;
	playerDirection = 0;
	playerAngle = VEC_ORIGIN;
	playerPosition = VEC_ORIGIN;
	playerCamera = 0;

	for (int i = 0; i < 5; i++)
	{
		StageBossDefeated[i] = 0;
		StageGoNextFlag[i] = 0;
		StageKeys[i] = 0;
	}

}
