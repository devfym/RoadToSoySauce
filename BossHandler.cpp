#include "BossHandler.h"

static const float ROTATE_SPEED = DX_PI_F / 90;

void BossRotate(float *x, float *y, const float ang, const float mx, const float my)
{
	const float ox = *x - mx, oy = *y - my;
	*x = ox * cos(ang) + oy * sin(ang);
	*y = -ox * sin(ang) + oy * cos(ang);
	*x += mx;
	*y += my;
}



BossHandler::BossHandler(void)
{
}


BossHandler::~BossHandler(void)
{
}

void BossHandler::BossInitialization(SaveData m_sd)
{
	Exist = 0;
	Life = 0;
	Position = VEC_HIDE;
	Angle = VEC_ORIGIN;
	radius = 800;
	DamageFlag = 0;
	DamageIntervalCount = 0;
	sd = m_sd;
	img_BossLife = LoadGraph(GUI_BOSS_LIFE);
	ATTACK_ANGLE = VEC_ORIGIN;
	MovementPattern = 0;
	MovementCount = 0;
	MovementInRest = 0;

	for (int i = 0;i < 4;i++)
		ATTACK[i] = VEC_HIDE;

	switch (sd.CurrentStage)
	{
	case 1: // Stage 1
		if (sd.CurrentArea == 3)
		{
			Exist = 1;
			Life = 3;
			BossNumber = 1;
			EnemyType = 1; // land
			Model = MV1LoadModel(M3D_MANGKUKULAM);
			img_BossName = LoadGraph(GUI_BOSS_NAME1);
			Position = VGet(-5000, 0, 0);
			Angle = VGet(0, DX_PI_F / 4, 0);
			MovementPattern = 1;
			for (int i = 0; i < 4; i++)
				Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);
		}
		break;
	case 2:  // Stage 2
		if (sd.CurrentArea == 4)
		{
			Exist = 1;
			Life = 3;
			BossNumber = 2;
			EnemyType = 2; // fly
			Model = MV1LoadModel(M3D_ASWANG);
			img_BossName = LoadGraph(GUI_BOSS_NAME2);
			Position = VGet(2000, 0, -7500);
			Angle = VGet(0, 0, 0);
			MovementPattern = 1;
			for (int i = 0; i < 4; i++)
				Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);

		}
		break;
	case 3: // Stage 3
		if (sd.CurrentArea == 4)
		{
			Exist = 1;
			Life = 3;
			BossNumber = 3;
			EnemyType = 1; // land
			Model = MV1LoadModel(M3D_BUNGISNGIS);
			img_BossName = LoadGraph(GUI_BOSS_NAME3);
			Position = VGet(-7300, 0, 0);
			Angle = VGet(0, DX_PI_F / 4, 0);
			MovementPattern = 1;
			for (int i = 0; i < 4; i++)
				Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);
		}
		break;
	case 4: // Stage 4
		if (sd.CurrentArea == 4)
		{
			Exist = 1;
			Life = 3;
			BossNumber = 4;
			EnemyType = 1; // land
			Model = MV1LoadModel(M3D_BANGUNGOT);
			img_BossName = LoadGraph(GUI_BOSS_NAME4);
			Position = VGet(0, 0, 16000);
			Angle = VGet(0, DX_PI_F / 2, 0);
			for (int i = 0; i < 4; i++)
				Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);
		}
		break;
	case 5: // Stage 5
		if (sd.CurrentArea == 3)
		{
			Exist = 1;
			Life = 3;
			BossNumber = 5;
			EnemyType = 2; // land
			Model = MV1LoadModel(M3D_BAKUNAWA);
			img_BossName = LoadGraph(GUI_BOSS_NAME5);
			Position = VGet(0, 0, 6000);
			Angle = VGet(0, DX_PI_F, 0);
			MovementPattern = 1;
			for (int i = 0; i < 4; i++)
				Model_Attack[i] = MV1LoadModel(M3D_ATTACK1);
			B5Count = 0;
		}
		break;
	}// end switch

}
void BossHandler::BossMovement(void)
{
	if (Exist == 1)
	{
		switch (sd.CurrentStage)
		{
		case 1:
			if (MovementInRest == 0)
			{

				if (MovementPattern == 1)
				{
					Position.x += 40;
					Position.z += 40;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F, 0);
						MovementPattern = 2;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 2)
				{
					Position.z -= 40;
					MovementCount++;
					if (MovementCount == 200)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F * 7 / 4, 0);
						MovementPattern = 3;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 3)
				{
					Position.x -= 40;
					Position.z += 40;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F / 4, 0);
						MovementPattern = 1;
						MovementCount = 0;
					}

				}
			}
			else
			{
				MovementInRest++;
				if (MovementInRest == 60)
					MovementInRest = 0;
			}
			break;

		case 2:
			if (MovementInRest == 0)
			{
				if (MovementPattern == 1)
				{
					Position.z += 75;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F, 0);
						MovementPattern = 2;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 2)
				{
					Position.z -= 125;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, 0, 0);
						MovementPattern = 3;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 3)
				{
					Position.z += 125;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F, 0);
						MovementPattern = 2;
						MovementCount = 0;
					}
				}

			}
			else
			{
				MovementInRest++;
				if (MovementInRest == 60)
					MovementInRest = 0;
			}



			break;

		case 3:
			if (MovementInRest == 0)
			{
				if (MovementPattern == 1)
				{
					Position.x += 70;
					Position.z += 40;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F, 0);
						MovementPattern = 2;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 2)
				{
					Position.z -= 40;
					MovementCount++;
					if (MovementCount == 200)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F * 7 / 4, 0);
						MovementPattern = 3;
						MovementCount = 0;
					}
				}
				else if (MovementPattern == 3)
				{
					Position.x -= 70;
					Position.z += 40;
					MovementCount++;
					if (MovementCount == 100)
					{
						MovementInRest = 1;
						Angle = VGet(0, DX_PI_F / 4, 0);
						MovementPattern = 1;
						MovementCount = 0;
					}

				}
			}
			else
			{
				MovementInRest++;
				if (MovementInRest == 60)
					MovementInRest = 0;
			}


			break;

		case 4:
			if (MovementInRest == 0)
			{
				BossRotate(&Position.x, &Position.z, +ROTATE_SPEED / 2, 0, 8500);
				Angle.y += ROTATE_SPEED / 2;
				MovementCount++;
				if (MovementCount == 90)
				{
					MovementCount = 0;
					MovementInRest = 1;
				}
			}
			else
			{
				MovementInRest++;
				if (MovementInRest == 60)
					MovementInRest = 0;
			}
			break;

		case 5:
			if (MovementInRest == 0)
			{
				B5Count++;
				if (MovementPattern == 1)
				{
					Position.x += 60;
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

					Position.x -= 60;
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
					Position.x -= 50;
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
					Position.x += 50;
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
}
void BossHandler::BossAction(void)
{
	if (Exist == 1)
	{
		switch (sd.CurrentStage)
		{
		case 1:
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
			}

			break;

		case 2:
			ATTACK[0] = VGet(Position.x - 600, Position.y + 200, Position.z + 0);
			ATTACK[1] = VGet(Position.x - 1200, Position.y + 200, Position.z + 0);
			ATTACK[2] = VGet(Position.x + 600, Position.y + 200, Position.z + 0);
			ATTACK[3] = VGet(Position.x + 1200, Position.y + 200, Position.z + 0);
			ATTACK_ANGLE.y += ROTATE_SPEED;
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
			}

			break;

		case 4:
			if (MovementInRest == 0) // while in movement no attack occurs
			{
				for (int i = 0;i < 4;i++)
					ATTACK[i] = VEC_HIDE;
				MovementPattern = 0;
			}
			else if (MovementInRest == 1 || MovementInRest == 10 || MovementInRest == 20 || MovementInRest == 30 || MovementInRest == 40 || MovementInRest == 50 || MovementInRest == 59) // initialize pos of attacks
			{
				MovementPattern++;
				ATTACK[0] = VGet(Position.x + 0, Position.y + 200, Position.z + 400 + (MovementPattern * 100));
				ATTACK[1] = VGet(Position.x + 400 + (MovementPattern * 100), Position.y + 200, Position.z + 0);
				ATTACK[2] = VGet(Position.x + 0, Position.y + 200, Position.z - 400 - (MovementPattern * 100));
				ATTACK[3] = VGet(Position.x - 400 - (MovementPattern * 100), Position.y + 200, Position.z + 0);
			}

			else // attack movements
			{
				for (int i = 0; i < 4;i++)
					BossRotate(&ATTACK[i].x, &ATTACK[i].z, +ROTATE_SPEED * 5, Position.x, Position.z);
			}
			break;

		case 5:
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


}



void BossHandler::BossUpdate(int BossDefeatedFlag)
{
	if (BossDefeatedFlag == 1)
	{
		Exist = 0;
		Life = 0;
		Position = VEC_HIDE;
		Angle = VEC_ORIGIN;
		radius = 800;
		DamageFlag = 0;
		DamageIntervalCount = 0;
	}
}

void BossHandler::BossDraw(void)
{
	if (Exist == 1)
	{
		MV1SetPosition(Model, Position);
		MV1SetRotationXYZ(Model, Angle);
		MV1DrawModel(Model);

		for (int i = 0; i < 4; i++)
		{
			MV1SetPosition(Model_Attack[i], ATTACK[i]);
			MV1SetRotationXYZ(Model_Attack[i], ATTACK_ANGLE);
			MV1DrawModel(Model_Attack[i]);
		}

	}

}
int BossHandler::CheckExist(void)
{
	if (Exist == 1)
	{
		if (Life == 0)
		{
			Exist = 0;
			Position = VEC_HIDE;
			return 1;
		}
	}
	return 0;
}


void BossHandler::ReleaseData(void)
{
	MV1DeleteModel(Model);
	Life = 0;
	Exist = 0;
	BossNumber = 0;
	EnemyType = 0;
	MovementPattern = 0;
	MovementCount = 0;
	MovementInRest = 0;
	Position = VEC_HIDE;
	Angle = VEC_HIDE;
	DeleteGraph(img_BossLife);
	DeleteGraph(img_BossName);
}

void BossHandler::BossStatusDraw(void)
{
	if (Exist == 1)
	{
		DrawGraph(20, 600 - GUI_BOSS_NAME_Y, img_BossName, TRUE);
		for (int i = 0; i < Life; i++)
			DrawGraph(30 + GUI_BOSS_NAME_X + (10 * i) + (GUI_BOSS_LIFE_X * i), 600 - (GUI_BOSS_NAME_Y * 3 / 4), img_BossLife, TRUE);

	}
}
