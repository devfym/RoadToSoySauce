#include "EnemyHandler.h"


EnemyHandler::EnemyHandler()
{


}


EnemyHandler::~EnemyHandler(void)
{
}

void EnemyHandler::EnemyInitialization(int StageNumber, int AreaNumber, int EnemyNumber)
{
	DamageFlag = 0;
	DamageIntervalCount = 0;
	Angle = VGet(0, 0, 0);
	AngleInterval = 0;

	Exist = 1;
	//////////// ENEMY RANDOM SPAWN
	switch (StageNumber)
	{
	case 1: // Stage 1
		EnemyID = GetRand(3); // 0 ~4 , Dwende, Tiyanak, Engkanto, Mambabarang
		if (EnemyID == 0) { Model = MV1LoadModel(M3D_DWENDE); EnemyType = 1; }
		else if (EnemyID == 1) { Model = MV1LoadModel(M3D_TIYANAK);	 EnemyType = 1; }
		else if (EnemyID == 2) { Model = MV1LoadModel(M3D_ENGKANTO); EnemyType = 1; }
		else if (EnemyID == 3) { Model = MV1LoadModel(M3D_MAMBABARANG); EnemyType = 1; }
		break; // Stage 1

	case 2: // Stage 2
		EnemyID = 5; // Sigbin
		if (EnemyID == 5) { Model = MV1LoadModel(M3D_SIGBIN); EnemyType = 1; }
		break; // Stage 2

	case 3: // Stage 3
		EnemyID = GetRand(3) + 7; // 7~10, Santelmo, Pasatsat, Ekek, Wakwak
		if (EnemyID == 7) { Model = MV1LoadModel(M3D_SANTELMO); EnemyType = 2; }
		else if (EnemyID == 8) { Model = MV1LoadModel(M3D_PASATSAT); EnemyType = 1; }
		else if (EnemyID == 9) { Model = MV1LoadModel(M3D_EKEK); EnemyType = 2; }
		else if (EnemyID == 10) { Model = MV1LoadModel(M3D_WAKWAK); EnemyType = 2; }
		break; // Stage 3

	case 4: // Stage 4
		EnemyID = 12; // Multo
		if (EnemyID == 12) { Model = MV1LoadModel(M3D_MULTO); EnemyType = 2; }
		break; // Stage 4

	case 5: // Stage 5
		EnemyID = GetRand(1) + 14; // 14~15, Berberoka, Tikbalang
		if (EnemyID == 14) { Model = MV1LoadModel(M3D_BERBEROKA); EnemyType = 1; }
		else if (EnemyID == 15) { Model = MV1LoadModel(M3D_TIKBALANG); EnemyType = 1; }
		break; // Stage 5
	}
	//////////// +++++++++++++++++++++ ENEMY RANDOM SPAWN

	//////////////////////////////////////////// ENEMY POSITION SET
	switch (StageNumber)
	{
	case 1: // Stage 1
		switch (AreaNumber)
		{
		case 1: // Stage 1 Area 1
			if (EnemyNumber == 0)				Position = VGet(500, 0, 7400);
			else if (EnemyNumber == 1)		Position = VGet(-1250, 0, -3000);
			else if (EnemyNumber == 2)		Position = VGet(100, 0, -4650);
			else if (EnemyNumber == 3)		Position = VGet(-3500, 0, 2500);
			else if (EnemyNumber == 4)		Position = VGet(-3200, 0, 8800);
			break; // Stage 1 Area 1

		case	2: // Stage 1 Area 2
			if (EnemyNumber == 0)				Position = VGet(3500, 0, 0);
			else if (EnemyNumber == 1)		Position = VGet(7000, 0, 0);
			else if (EnemyNumber == 2)		Position = VGet(12000, 0, -1400);
			else if (EnemyNumber == 3)		Position = VGet(14400, 0, 1500);
			else if (EnemyNumber == 4)		Position = VGet(17000, 0, 500);
			break; // Stage 1 Area 2

		default: // Stage 1 Area 3 = BOSS AREA no exist Enemy
			Exist = 0;
			Position = VEC_HIDE;
			break;
		}
		break; // Stage 1

	case 2: // Stage 2
		switch (AreaNumber)
		{
		case 1: // Stage 2 Area 1
			if (EnemyNumber == 0)				Position = VGet(-11300, 0, 600);
			else if (EnemyNumber == 1)		Position = VGet(-14000, 0, 4000);
			else if (EnemyNumber == 2)		Position = VGet(-17000, 0, 600);
			else if (EnemyNumber == 3)		Position = VGet(-14000, 0, -2200);
			else if (EnemyNumber == 4)		Position = VGet(-5000, 0, 2000);
			break; // Stage 2 Area 1

		case 2: // Stage 2 Area 2
			if (EnemyNumber == 0)				Position = VGet(2000, 0, 7500);
			else if (EnemyNumber == 1)		Position = VGet(-4000, 0, 3000);
			else if (EnemyNumber == 2)		Position = VGet(-9500, 0, 3000);
			else if (EnemyNumber == 3)		Position = VGet(-9500, 0, 12700);
			else if (EnemyNumber == 4)		Position = VGet(-2700, 0, 12700);
			break; //Stage 2 Area 2

		case 3: // Stage 2 Area 3
			if (EnemyNumber == 0)				Position = VGet(1000, 0, 9000);
			else if (EnemyNumber == 1)		Position = VGet(6700, 0, -100);
			else if (EnemyNumber == 2)		Position = VGet(-11000, 0, 8000);
			else if (EnemyNumber == 3)		Position = VGet(-11000, 0, 1000);
			else if (EnemyNumber == 4)		Position = VGet(-11000, 0, -5000);
			break; // Stage 2 Area 3

		default: // Stage 2 Area 4 = BOSS AREA no exist Enemy
			Exist = 0;
			Position = VEC_HIDE;
			break;
		}
		break; // Stage 2

	case 3: // Stage 3
		switch (AreaNumber)
		{
		case 1: // Stage 3 Area 1
			if (EnemyNumber == 0)				Position = VGet(-6000, 0, -6000);
			else if (EnemyNumber == 1)		Position = VGet(-3000, 0, -6000);
			else if (EnemyNumber == 2)		Position = VGet(-6000, 0, 6000);
			else if (EnemyNumber == 3)		Position = VGet(-3000, 0, 6000);
			else if (EnemyNumber == 4)		Position = VGet(-6000, 0, 0);
			break; // Stage 3 Area 1

		case 2: // Stage 3 Area 2
			if (EnemyNumber == 0)				Position = VGet(-4450, 0, -12000);
			else if (EnemyNumber == 1)		Position = VGet(-4450, 0, -6000);
			else if (EnemyNumber == 2)		Position = VGet(-2000, 0, -6000);
			else if (EnemyNumber == 3)		Position = VGet(-6000, 0, -6000);
			else if (EnemyNumber == 4)		Position = VGet(-2000, 0, -12000);
			break; //Stage 3 Area 2

		case 3: // Stage 3 Area 3
			if (EnemyNumber == 0)				Position = VGet(-9000, 0, 0);
			else if (EnemyNumber == 1)		Position = VGet(-6500, 0, -2000);
			else if (EnemyNumber == 2)		Position = VGet(-6500, 0, 2000);
			else if (EnemyNumber == 3)		Position = VGet(-4000, 0, 600);
			else if (EnemyNumber == 4)		Position = VGet(-4000, 0, -600);
			break; // Stage 3 Area 3

		default: // Stage 3 Area 4 = BOSS AREA no exist Enemy
			Exist = 0;
			Position = VEC_HIDE;
			break;
		}
		break; // Stage 3

	case 4: // Stage 4
		switch (AreaNumber)
		{
		case 1: // Stage 4 Area 1
			if (EnemyNumber == 0)				Position = VGet(50, 0, -16800);
			else if (EnemyNumber == 1)		Position = VGet(-300, 0, -13800);
			else if (EnemyNumber == 2)		Position = VGet(0, 0, -10000);
			else if (EnemyNumber == 3)		Position = VGet(1500, 0, -4000);
			else if (EnemyNumber == 4)		Position = VGet(-1800, 0, -4000);
			break; // Stage 4 Area 1

		case 2: // Stage 4 Area 2
			if (EnemyNumber == 0)				Position = VGet(4600, 0, 6000);
			else if (EnemyNumber == 1)		Position = VGet(3700, 0, 3200);
			else if (EnemyNumber == 2)		Position = VGet(-4500, 0, 4000);
			else if (EnemyNumber == 3)		Position = VGet(-3300, 0, 7000);
			else if (EnemyNumber == 4)		Position = VGet(-200, 0, 5000);
			break; //Stage 4 Area 2

		case 3: // Stage 4 Area 3
			if (EnemyNumber == 0)				Position = VGet(-5500, 0, -16000);
			else if (EnemyNumber == 1)		Position = VGet(5600, 0, -16000);
			else if (EnemyNumber == 2)		Position = VGet(3000, 0, -9000);
			else if (EnemyNumber == 3)		Position = VGet(-3500, 0, -9000);
			else if (EnemyNumber == 4)		Position = VGet(0, 0, -15500);
			break; // Stage 4 Area 3

		default: // Stage 4 Area 4 = BOSS AREA no exist Enemy
			Exist = 0;
			Position = VEC_HIDE;
			break;
		}
		break; // Stage 4

	case 5: // Stage 5
		switch (AreaNumber)
		{
		case 1: // Stage 5 Area 1
			if (EnemyNumber == 0)				Position = VGet(-6300, 0, 4500);
			else if (EnemyNumber == 1)		Position = VGet(-8000, 0, 500);
			else if (EnemyNumber == 2)		Position = VGet(-6000, 0, -9000);
			else if (EnemyNumber == 3)		Position = VGet(-250, 0, -6000);
			else if (EnemyNumber == 4)		Position = VGet(-4400, 0, -3000);
			break; //Stage 5 Area 1

		case 2: // Stage 5 Area 2
			if (EnemyNumber == 0)				Position = VGet(4000, 0, 8000);
			else if (EnemyNumber == 1)		Position = VGet(5800, 0, 0);
			else if (EnemyNumber == 2)		Position = VGet(12000, 0, 3000);
			else if (EnemyNumber == 3)		Position = VGet(10000, 0, 15000);
			else if (EnemyNumber == 4)		Position = VGet(12000, 0, 8000);
			break; // Stage 5 Area 2

		default: // Stage 5 Area 3 = BOSS AREA no exist Enemy && Stage 5 Area 4 = Sari Sari Store no exist Enemy
			Exist = 0;
			Position = VEC_HIDE;
			break;
		}
		break; // Stage 5

	}
	// ++++++++++++++++++ ENEMY POSITION SET
	Life = 1;
	Radius = 200.f;

}

void EnemyHandler::EnemyDraw(void)
{

	if (Exist == 1)
	{

		MV1SetPosition(Model, Position);
		MV1SetRotationXYZ(Model, Angle);
		MV1DrawModel(Model);
	}
}

int EnemyHandler::CheckExist(void)
{
	return Exist;
}

int EnemyHandler::EnemyCheck(void)
{
	if (Exist == 1)
	{
		if (Life == 0)
		{
			Exist = 0;
			Position = VGet(0, 10000, 0);
			return 1;
		}
	}
	return 0;
}

int EnemyHandler::SearchPlayer(VECTOR playerPos)
{
	float xLength = Position.x - playerPos.x;
	float yLength = Position.y - playerPos.y;
	float zLength = Position.z - playerPos.z;
	float pythagorean_3d = sqrt((xLength * xLength) + (yLength * yLength) + (zLength * zLength));

	if (pythagorean_3d <= 4000.f)
		return 1;

	return 0;

}

void EnemyHandler::EnemyMove(VECTOR playerPos)
{
	int x, z;
	if (playerPos.x > Position.x)
	{
		Position.x += 8;
		x = 1;
	}
	else
	{
		Position.x -= 8;
		x = 2;
	}
	if (playerPos.z > Position.z)
	{
		Position.z += 8;
		z = 3;
	}
	else
	{
		Position.z -= 8;
		z = 4;
	}
	if (x == 1 && z == 3)
		Angle = VGet(0, DX_PI_F * 5 / 4, 0);
	else if (x == 2 && z == 3)
		Angle = VGet(0, DX_PI_F * 3 / 4, 0);
	else if (x == 1 && z == 4)
		Angle = VGet(0, DX_PI_F * 7 / 4, 0);
	else if (x == 2 && z == 4)
		Angle = VGet(0, DX_PI_F / 4, 0);
}

void EnemyHandler::ReleaseData(void)
{
	MV1DeleteModel(Model);
	Life = 0;
	Exist = 0;
	EnemyType = 0;
	DamageFlag = 0;
	DamageIntervalCount = 0;
	Position = VEC_ORIGIN;
	Radius = 0;
	Angle = VEC_ORIGIN;
	AngleInterval = 0;
	EnemyID = 0;
}
