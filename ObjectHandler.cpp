#include "ObjectHandler.h"
#include <math.h>
static const float ROTATE_SPEED = DX_PI_F / 90;

ObjectHandler::ObjectHandler()
{


}

void ObjectHandler::ObjectInitialization(SaveData m_sd, int ObjNumber)
{
	Exist = 1; // show
	sd = m_sd;
	Angle = VGet(0, 0, 0);

	// ++++ Object Model Load
	switch (ObjNumber)
	{
	case 1: // garlic
		Model = MV1LoadModel(M3D_GARLIC);
		ObjectNumber = 1;
		break;

	case 2: // Treasure Box
		Model = MV1LoadModel(M3D_TREASUREBOX);
		ObjectNumber = 2;
		break;

	case 3: // Key
		if (sd.CurrentStage == 5 && sd.CurrentArea == 3)
			Model = MV1LoadModel(M3D_GOLDENGARLIC);
		else if (sd.CurrentStage == 5 && sd.CurrentArea == 4)
			Model = MV1LoadModel(M3D_SOYSAUCE);
		else
			Model = MV1LoadModel(M3D_KEY);
		ObjectNumber = 3; // if Stage 5 Area 3 = Load Golden Garlic model instead of key
		break;
	}
	////////////////// +++ Object Model Load

	/// ++++ Object Position Set
	switch (ObjectNumber)
	{

	case 1: // GARLIC POSITION
		switch (sd.CurrentStage)
		{
		case 1: // Stage 1 Garlic
			if (sd.CurrentArea == 1)				Position = VGet(-2200, 30, 4250);
			else if (sd.CurrentArea == 2)		Position = VGet(2100, 30, 1000);
			else if (sd.CurrentArea == 3)		Position = VGet(-2700, 30, 4000);
			break; // Stage 1

		case 2: // Stage 2 Garlic
			if (sd.CurrentArea == 1)				Position = VGet(-6500, 30, -2500);
			else if (sd.CurrentArea == 2)		Position = VGet(-9500, 30, 7500);
			else if (sd.CurrentArea == 3)		Position = VGet(-5000, 30, 9000);
			else if (sd.CurrentArea == 4)		Position = VGet(1000, 30, -1100);
			break; // Stage 2

		case 3: // Stage 3 Garlic
			if (sd.CurrentArea == 1)				Position = VGet(-8400, 30, 6000);
			else if (sd.CurrentArea == 2)		Position = VGet(-4450, 30, 3000);
			else if (sd.CurrentArea == 3)		Position = VGet(-6500, 30, -5000);
			else if (sd.CurrentArea == 4)		Position = VGet(-2500, 30, 5000);
			break; // Stage 3

		case 4: // Stage 4 Garlic
			if (sd.CurrentArea == 1)				Position = VGet(-200, 30, -7200);
			else if (sd.CurrentArea == 2)		Position = VGet(600, 30, 3650);
			else if (sd.CurrentArea == 3)		Position = VGet(-5500, 30, -13000);
			else if (sd.CurrentArea == 4)		Position = VGet(0, 30, 2500);
			break; // Stage 4

		case 5: // Stage 5 Garlic
			if (sd.CurrentArea == 1)				Position = VGet(0, 30, 4000);
			else if (sd.CurrentArea == 2)		Position = VGet(14500, 30, 3000);
			else if (sd.CurrentArea == 3)		Position = VGet(0, 30, 0);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 5

		}
		break; // Garlic Objects

	case 2: // Treasure box
		switch (sd.CurrentStage)
		{
		case 1: // Stage 1 Treasure Box
			if (sd.CurrentArea == 1)			Position = VGet(-2000, 10, 8550);
			else if (sd.CurrentArea == 2)		Position = VGet(4900, 10, 1000);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 1

		case 2: // Stage 2 Treasure Box
			if (sd.CurrentArea == 1)				Position = VGet(-17000, 10, 4000);
			else if (sd.CurrentArea == 2)		Position = VGet(-2700, 10, 17000);
			else if (sd.CurrentArea == 3)		Position = VGet(6700, 10, 9000);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 2

		case 3: // Stage 3 Treasure Box
			if (sd.CurrentArea == 1)				Position = VGet(-8400, 10, 0);
			else if (sd.CurrentArea == 2)		Position = VGet(500, 10, -6000);
			else if (sd.CurrentArea == 3)		Position = VGet(-6500, 10, 5000);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 3

		case 4: // Stage 4 Treasure Box
			if (sd.CurrentArea == 1)				Position = VGet(-150, 10, -11500);
			else if (sd.CurrentArea == 2)		Position = VGet(-5500, 10, 6000);
			else if (sd.CurrentArea == 3)		Position = VGet(5600, 10, -13000);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 4

		case 5: // Stage 5 Treasure Box
			if (sd.CurrentArea == 1)				Position = VGet(0, 10, -9500);
			else if (sd.CurrentArea == 2)		Position = VGet(14500, 10, 1500);
			else { Position = VEC_HIDE; Exist = 0; }
			break; // Stage 5

		}
		break; // Treasure Box

	case 3: // Key
		switch (sd.CurrentStage)
		{
		case 1: // Stage 1 Key
			if (sd.CurrentArea == 1 && sd.StageKeys[0] < 1)					Position = VGet(-1750, 30, -3600);
			else if (sd.CurrentArea == 2 && sd.StageKeys[0] < 2)			Position = VGet(13000, 30, 1500);
			//else if(sd.CurrentArea==3 && sd.StageKeys[0] < 3)			Position = VGet(0,30,0); // ++ Add code if Boss 1 Defeated
			else { Position = VEC_HIDE, Exist = 0; }
			break; // Stage 1

		case 2: // Stage 2 Key
			if (sd.CurrentArea == 1 && sd.StageKeys[1] < 1)						Position = VGet(-17000, 30, -2500);
			else if (sd.CurrentArea == 2 && sd.StageKeys[1] < 2)			Position = VGet(-9500, 30, 17000);
			else if (sd.CurrentArea == 3 && sd.StageKeys[1] < 3)			Position = VGet(-11000, 30, -10000);
			//else if(sd.CurrentArea==4 && sd.StageKeys[1]<4)			Position =VGet(0,30,0); // ++ Add Code if Boss 2 Defeated
			else { Position = VEC_HIDE, Exist = 0; }
			break; // Stage 2

		case 3: // Stage 3 Key
			if (sd.CurrentArea == 1 && sd.StageKeys[2] < 1)						Position = VGet(-8400, 30, -6000);
			else if (sd.CurrentArea == 2 && sd.StageKeys[2] < 2)			Position = VGet(-4450, 30, -15000);
			else if (sd.CurrentArea == 3 && sd.StageKeys[2] < 3)			Position = VGet(-14300, 30, 0);
			//else if(sd.CurrentArea==4 && sd.StageKeys[2]<4)			Position =VGet(0,30,0); // ++ Add Code if Boss 3 Defeated
			else { Position = VEC_HIDE, Exist = 0; }
			break; // Stage 3

		case 4: // Stage 4 Key
			if (sd.CurrentArea == 1 && sd.StageKeys[3] < 1)						Position = VGet(50, 30, -16000);
			else if (sd.CurrentArea == 2 && sd.StageKeys[3] < 2)			Position = VGet(7000, 30, 6800);
			else if (sd.CurrentArea == 3 && sd.StageKeys[3] < 3)			Position = VGet(0, 0, -17300);
			//else if(sd.CurrentArea==4 && sd.StageKeys[3]<4)			Position =VGet(0,30,0); // ++ Add Code if Boss 4 Defeated
			else { Position = VEC_HIDE, Exist = 0; }
			break; // Stage 4

		case 5: // Stage 5 Key
			if (sd.CurrentArea == 1 && sd.StageKeys[4] < 1)						Position = VGet(-5000, 30, 6100);
			else if (sd.CurrentArea == 2 && sd.StageKeys[4] < 2)			Position = VGet(14500, 30, 0);
			//else if(sd.CurrentArea==3 && sd.StageKeys[4]<3)			Position =VGet(0,30,6000); // ++ Add Code if Boss 5 Defeated
			else if (sd.CurrentArea == 4 && sd.StageKeys[4] < 4)			Position = VGet(0, 30, 25000); // soy sauce game clear!
			else { Position = VEC_HIDE, Exist = 0; }
			break; // Stage 5
		}
		break; // Key
	}
	// ++++++ Object Position Set
}

void ObjectHandler::ObjectUpdate(int BossDefeatedFlag, int KeyNumber) // bossdefeated flag
{
	if (sd.CurrentStage == 1 && sd.CurrentArea == 3 && KeyNumber < 3 && BossDefeatedFlag == 1) { Position = VGet(0, 30, 0); Exist = 1; }
	else if (sd.CurrentStage == 2 && sd.CurrentArea == 4 && KeyNumber < 4 && BossDefeatedFlag == 1) { Position = VGet(0, 30, 0); Exist = 1; }
	else if (sd.CurrentStage == 3 && sd.CurrentArea == 4 && KeyNumber < 4 && BossDefeatedFlag == 1) { Position = VGet(0, 30, 0); Exist = 1; }
	else if (sd.CurrentStage == 4 && sd.CurrentArea == 4 && KeyNumber < 4 && BossDefeatedFlag == 1) { Position = VGet(0, 30, 0); Exist = 1; }
	else if (sd.CurrentStage == 5 && sd.CurrentArea == 3 && KeyNumber < 4 && BossDefeatedFlag == 1) { Position = VGet(0, 30, 6000); Exist = 1; }
}

void ObjectHandler::ObjectDraw(void)
{
	if (Exist == 1)
	{
		if (ObjectNumber == 1 || ObjectNumber == 3)
		{
			Angle.y += ROTATE_SPEED;
			MV1SetRotationXYZ(Model, Angle);
		}
		MV1SetPosition(Model, Position);
		MV1DrawModel(Model);
	}

}

int ObjectHandler::ObjectTouched(void)
{
	if (Exist == 1)
	{
		switch (ObjectNumber)
		{
		case 1: // Garlic
			Exist = 0;
			return 1; // life 1 up
			break;

		case 2: // Treasure Box
			Exist = 0;
			return 2; // score += 1000
			break;
		case 3: // Key
			Exist = 0;
			return 3; // inform sh->StageKey[i] that ++ 1;
			break;
		}
	}
	return 0;
}

ObjectHandler::~ObjectHandler(void)
{

}

void ObjectHandler::ReleaseData(void)
{
	MV1DeleteModel(Model);
	Position = VEC_ORIGIN;
	Angle = VEC_ORIGIN;
	Exist = 0;
	ObjectNumber = 0;
}
