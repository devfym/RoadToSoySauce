#include "Boss2Handler.h"

static const float ROTATE_SPEED = DX_PI_F / 90;

void Boss2Rotate(float *x, float *y, const float ang, const float mx, const float my)
{
	const float ox = *x - mx, oy = *y - my;
	*x = ox * cos(ang) + oy * sin(ang);
	*y = -ox * sin(ang) + oy * cos(ang);
	*x += mx;
	*y += my;
}

Boss2Handler::Boss2Handler(void)
{
	//Nothing
}


Boss2Handler::~Boss2Handler(void)
{
	//Nothing
}

void Boss2Handler::BossInitialization(void)
{
	Model[0] = MV1LoadModel(M3D_MANGKUKULAM);
	Model[1] = MV1LoadModel(M3D_ASWANG);
	Model[2] = MV1LoadModel(M3D_BUNGISNGIS);
	Model[3] = MV1LoadModel(M3D_BANGUNGOT);
	Model[4] = MV1LoadModel(M3D_BAKUNAWA);

	for (int i = 0;i < 4;i++)
		Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);
	Life = 3;
	BossNumber = 0;
	EnemyType = 1;
	B5Count = 0;
	B3Count = 0;
	DamageFlag = 0;
	DamageIntervalCount = 0;

	radius = 400;
	Position = VEC_ORIGIN;
	Angle = VEC_B;

	ATTACK_ANGLE = VEC_ORIGIN;

	for (int i = 0;i < 4;i++)
		ATTACK[i] = VEC_HIDE; // 4 directions

	MovementPattern = 1;
	MovementCount = 0;
	MovementInRest = 0;

	img_BossName[0] = LoadGraph(GUI_BOSS_NAME1);
	img_BossName[1] = LoadGraph(GUI_BOSS_NAME2);
	img_BossName[2] = LoadGraph(GUI_BOSS_NAME3);
	img_BossName[3] = LoadGraph(GUI_BOSS_NAME4);
	img_BossName[4] = LoadGraph(GUI_BOSS_NAME5);
	img_BossLife = LoadGraph(GUI_BOSS_LIFE);

	MV1SetPosition(Model[0], VEC_HIDE);
	MV1SetPosition(Model[1], VEC_HIDE);
	MV1SetPosition(Model[2], VEC_HIDE);
	MV1SetPosition(Model[3], VEC_HIDE);
	MV1SetPosition(Model[4], VEC_HIDE);

	MV1SetRotationXYZ(Model[0], VEC_B);
	MV1SetRotationXYZ(Model[1], VEC_B);
	MV1SetRotationXYZ(Model[2], VEC_B);
	MV1SetRotationXYZ(Model[3], VEC_B);
	MV1SetRotationXYZ(Model[4], VEC_B);

}

void Boss2Handler::BossDraw(void)
{
	MV1SetRotationXYZ(Model[BossNumber], Angle);
	MV1SetPosition(Model[BossNumber], Position);
	MV1DrawModel(Model[BossNumber]);

	for (int i = 0; i < 4; i++)
	{
		MV1SetPosition(Model_Attack[i], ATTACK[i]);
		MV1SetRotationXYZ(Model_Attack[i], ATTACK_ANGLE);
		MV1DrawModel(Model_Attack[i]);
	}
}

void Boss2Handler::BossStatusDraw(void)
{
	DrawGraph(20, 600 - GUI_BOSS_NAME_Y, img_BossName[BossNumber], TRUE);
	for (int i = 0; i < Life; i++)
		DrawGraph(30 + GUI_BOSS_NAME_X + (10 * i) + (GUI_BOSS_LIFE_X * i), 600 - (GUI_BOSS_NAME_Y * 3 / 4), img_BossLife, TRUE);
}

int Boss2Handler::BossUpdate(void)
{
	if (Life == 0)
	{
		if (BossNumber == 0) { BossNumber = 1; EnemyType = 2; }
		else if (BossNumber == 1)
		{
			BossNumber = 2; EnemyType = 1;
		}
		else if (BossNumber == 2)
		{
			BossNumber = 3; EnemyType = 1;
		}
		else if (BossNumber == 3)
		{
			BossNumber = 4; EnemyType = 2;
		}
		else if (BossNumber == 4)
		{
			BossNumber = 0; EnemyType = 1;
		}
		Life = 3;

		DamageFlag = 0;
		DamageIntervalCount = 0;
		B5Count = 0;B3Count = 0;
		Position = VEC_ORIGIN;
		Angle = VEC_B;

		ATTACK_ANGLE = VEC_ORIGIN;
		for (int i = 0;i < 4;i++)
			ATTACK[i] = VEC_HIDE; // 4 directions

		MovementPattern = 1;
		MovementCount = 0;
		MovementInRest = 0;

		MV1SetPosition(Model[0], VEC_HIDE);
		MV1SetPosition(Model[1], VEC_HIDE);
		MV1SetPosition(Model[2], VEC_HIDE);
		MV1SetPosition(Model[3], VEC_HIDE);
		MV1SetPosition(Model[4], VEC_HIDE);

		MV1SetRotationXYZ(Model[0], VEC_B);
		MV1SetRotationXYZ(Model[1], VEC_B);
		MV1SetRotationXYZ(Model[2], VEC_B);
		MV1SetRotationXYZ(Model[3], VEC_B);
		MV1SetRotationXYZ(Model[4], VEC_B);
		if (BossNumber == 1)
		{
			ATTACK[0] = VGet(Position.x + 0, Position.y + 200, Position.z + 800);
			ATTACK[1] = VGet(Position.x + 800, Position.y + 200, Position.z + 0);
			ATTACK[2] = VGet(Position.x + 0, Position.y + 200, Position.z - 800);
			ATTACK[3] = VGet(Position.x - 800, Position.y + 200, Position.z + 0);
		}
		return 1;
	}

	return 0;
}

void Boss2Handler::ReleaseData(void)
{
	for (int i = 0; i < 5; i++)
		MV1DeleteModel(Model[i]); // load all model in once
	for (int i = 0; i < 4; i++)
		MV1DeleteModel(Model_Attack[i]);
	Life = 0;

	BossNumber = 0;
	EnemyType = 0;

	DamageFlag = 0;
	DamageIntervalCount = 0;

	radius = 0;
	Position = VEC_ORIGIN;
	Angle = VEC_ORIGIN;

	ATTACK_ANGLE = VEC_ORIGIN;
	for (int i = 0; i < 4; i++)
		ATTACK[i] = VEC_ORIGIN; // 4 directions
	B5Count = 0;B3Count = 0;
	MovementPattern = 0;
	MovementCount = 0;
	MovementInRest = 0;
	for (int i = 0;i < 5;i++)
		DeleteGraph(img_BossName[i]);
	DeleteGraph(img_BossLife);
}

void Boss2Handler::BossMovement(VECTOR PlayerPos)
{
	int x, z;

	switch (BossNumber)
	{
	case 0:
		if (MovementInRest == 0)
		{
			if (MovementPattern == 1)
			{
				Angle = VGet(0, DX_PI_F / 2, 0);
				Position.x += 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F * 3 / 2, 0);
					MovementPattern = 2;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 2)
			{
				Angle = VGet(0, DX_PI_F * 7 / 4, 0);
				Position.x -= 40;
				Position.z += 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F, 0);
					MovementPattern = 3;
					MovementCount = 0;
				}
			}

			else if (MovementPattern == 3)
			{
				Angle = VGet(0, DX_PI_F * 5 / 4, 0);
				Position.x -= 40;
				Position.z -= 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F / 2, 0);
					MovementPattern = 4;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 4)
			{
				Angle = VGet(0, DX_PI_F * 3 / 4, 0);
				Position.x += 40;
				Position.z -= 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, 0, 0);
					MovementPattern = 5;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 5)
			{
				Angle = VGet(0, DX_PI_F / 4, 0);
				Position.x += 40;
				Position.z += 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F * 3 / 2, 0);
					MovementPattern = 2;
					MovementCount = 0;
				}
			}
		}
		else
		{
			MovementInRest++;
			if (MovementInRest == 100)
				MovementInRest = 0;
		}
		break;

	case 1:
		if (MovementInRest == 0)
		{
			if (PlayerPos.x > Position.x)
			{
				Position.x += 10;
				x = 1;
				for (int i = 0; i < 4; i++)
					ATTACK[i].x += 10;
			}
			else
			{
				Position.x -= 10;
				x = 2;
				for (int i = 0; i < 4; i++)
					ATTACK[i].x -= 10;
			}
			if (PlayerPos.z > Position.z)
			{
				Position.z += 10;
				z = 3;
				for (int i = 0; i < 4; i++)
					ATTACK[i].z += 10;
			}
			else
			{
				Position.z -= 10;
				z = 4;
				for (int i = 0; i < 4; i++)
					ATTACK[i].z -= 10;
			}
			if (x == 1 && z == 3)
				Angle = VGet(0, DX_PI_F / 4, 0);
			else if (x == 2 && z == 3)
				Angle = VGet(0, DX_PI_F * 7 / 4, 0);
			else if (x == 1 && z == 4)
				Angle = VGet(0, DX_PI_F * 3 / 4, 0);
			else if (x == 2 && z == 4)
				Angle = VGet(0, DX_PI_F * 5 / 4, 0);
			MovementCount++;
			if (MovementCount == 100)
			{
				MovementInRest = 1;
				MovementCount = 0;
			}
		}
		else
		{
			MovementInRest++;
			if (MovementInRest == 100)
				MovementInRest = 0;
		}
		break;

	case 2:
		if (MovementInRest == 0)
		{
			if (MovementPattern == 1)
			{
				Angle = VGet(0, DX_PI_F, 0);
				Position.z -= 40;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F * 3 / 2, 0);
					MovementPattern = 2;
					MovementCount = 0;
				}

			}
			else if (MovementPattern == 2)
			{
				Boss2Rotate(&Position.x, &Position.z, +ROTATE_SPEED / 2, 0, 0);
				Angle.y += ROTATE_SPEED / 2;
				MovementCount++;
				if (MovementCount == 90)
				{
					MovementCount = 0;
					MovementInRest = 1;
				}
			}
		}
		else
		{
			MovementInRest++;
			if (MovementInRest == 100)
				MovementInRest = 0;
		}
		break;

	case 3:
		if (MovementInRest == 0)
		{
			if (PlayerPos.x > Position.x)
			{
				Position.x += 10;
				x = 1;
			}
			else
			{
				Position.x -= 10;
				x = 2;
			}
			if (PlayerPos.z > Position.z)
			{
				Position.z += 10;
				z = 3;
			}
			else
			{
				Position.z -= 10;
				z = 4;
			}
			if (x == 1 && z == 3)
				Angle = VGet(0, DX_PI_F / 4, 0);
			else if (x == 2 && z == 3)
				Angle = VGet(0, DX_PI_F * 7 / 4, 0);
			else if (x == 1 && z == 4)
				Angle = VGet(0, DX_PI_F * 3 / 4, 0);
			else if (x == 2 && z == 4)
				Angle = VGet(0, DX_PI_F * 5 / 4, 0);
			MovementCount++;
			if (MovementCount == 100)
			{
				MovementInRest = 1;
				MovementCount = 0;
			}
		}
		else
		{
			MovementInRest++;
			if (MovementInRest == 100)
				MovementInRest = 0;
		}
		break;

	case 4:
		if (MovementInRest == 0)
		{
			B5Count++;
			if (MovementPattern == 1)
			{
				Position.x += 70;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F * 5 / 4, 0);
					MovementPattern = 2;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 2)
			{

				Position.x -= 70;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F, 0);
					MovementPattern = 3;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 3)
			{
				Position.x -= 70;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F * 3 / 4, 0);
					MovementPattern = 4;
					MovementCount = 0;
				}
			}
			else if (MovementPattern == 4)
			{
				Position.x += 70;
				MovementCount++;
				if (MovementCount == 100)
				{
					MovementInRest = 1;
					Angle = VGet(0, DX_PI_F, 0);
					MovementPattern = 1;
					MovementCount = 0;
				}
			}

		}
		else
		{
			B5Count = 0;
			MovementInRest++;
			if (MovementInRest == 60)
			{
				MovementInRest = 0;Angle = VGet(0, DX_PI_F, 0);
			}
		}
		break;
	}
}

void Boss2Handler::BossAction(void)
{
	switch (BossNumber)
	{
	case 0:
		if (MovementInRest == 0) // while in movement no attack occurs
		{
			for (int i = 0;i < 4;i++)
				ATTACK[i] = VEC_HIDE;
		}
		else if (MovementInRest == 1) // initialize pos of attacks
		{
			ATTACK[0] = VGet(Position.x + 0, Position.y + 200, Position.z + 400);
			ATTACK[1] = VGet(Position.x + 400, Position.y + 200, Position.z + 0);
			ATTACK[2] = VGet(Position.x + 0, Position.y + 200, Position.z - 400);
			ATTACK[3] = VGet(Position.x - 400, Position.y + 200, Position.z + 0);
		}
		else
		{
			ATTACK[0].z += 100;
			ATTACK[1].x += 100;
			ATTACK[2].z -= 100;
			ATTACK[3].x -= 100;
			ATTACK_ANGLE.y += ROTATE_SPEED;
		}

		break;

	case 1:
		for (int i = 0; i < 4; i++)
			Boss2Rotate(&ATTACK[i].x, &ATTACK[i].z, +ROTATE_SPEED * 5, Position.x, Position.z);
		ATTACK_ANGLE.y += ROTATE_SPEED;
		break;

	case 2:
		if (MovementInRest == 0) // while in movement no attack occurs
		{
			for (int i = 0;i < 4;i++)
				ATTACK[i] = VEC_HIDE;
			B3Count = 0;
		}
		else if (MovementInRest == 1 || MovementInRest == 20 || MovementInRest == 40 || MovementInRest == 60 || MovementInRest == 80 || MovementInRest == 99) // initialize pos of attacks
		{
			B3Count++;
			ATTACK[0] = VGet(Position.x + 0, Position.y + 200, Position.z + 400 + (B3Count * 400));
			ATTACK[1] = VGet(Position.x + 400 + (B3Count * 400), Position.y + 200, Position.z + 0);
			ATTACK[2] = VGet(Position.x + 0, Position.y + 200, Position.z - 400 - (B3Count * 400));
			ATTACK[3] = VGet(Position.x - 400 - (B3Count * 400), Position.y + 200, Position.z + 0);
		}
		else // attack movements
		{
			for (int i = 0; i < 4;i++)
				Boss2Rotate(&ATTACK[i].x, &ATTACK[i].z, +ROTATE_SPEED * 5, Position.x, Position.z);
		}
		break;

	case 3:
		if (MovementInRest == 0) // while in movement no attack occurs
		{
			for (int i = 0;i < 4;i++)
				ATTACK[i] = VEC_HIDE;
		}
		else if (MovementInRest == 1) // initialize pos of attacks
		{
			ATTACK[0] = VGet(Position.x + 0, Position.y + 200, Position.z + 400);
			ATTACK[1] = VGet(Position.x + 400, Position.y + 200, Position.z + 0);
			ATTACK[2] = VGet(Position.x + 0, Position.y + 200, Position.z - 400);
			ATTACK[3] = VGet(Position.x - 400, Position.y + 200, Position.z + 0);
		}
		else
		{
			ATTACK[0].z += 100;
			ATTACK[1].x += 100;
			ATTACK[2].z -= 100;
			ATTACK[3].x -= 100;
			ATTACK_ANGLE.y += ROTATE_SPEED;
		}
		break;

	case 4:
		if (MovementInRest == 0)
		{
			if (B5Count == 0)
				ATTACK[0] = VGet(Position.x, Position.y + 200, Position.z - 200);
			else if (B5Count == 25)
				ATTACK[1] = VGet(Position.x, Position.y + 200, Position.z - 200);
			else if (B5Count == 50)
				ATTACK[2] = VGet(Position.x, Position.y + 200, Position.z - 200);
			else if (B5Count == 75)
				ATTACK[3] = VGet(Position.x, Position.y + 200, Position.z - 200);
			else
				for (int i = 0;i < 4;i++)
					ATTACK[i].z -= 100;
		}
		else
		{
			for (int i = 0;i < 4;i++)
				ATTACK[i] = VEC_HIDE;
		}
		break;

	}
}
