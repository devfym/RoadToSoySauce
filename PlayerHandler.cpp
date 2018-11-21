#include "PlayerHandler.h"
#include <string.h>
#include <math.h>
static const float ROTATE_SPEED = DX_PI_F / 90;

void rotate(float *x, float *y, const float ang, const float mx, const float my)
{
	const float ox = *x - mx, oy = *y - my;
	*x = ox * cos(ang) + oy * sin(ang);
	*y = -ox * sin(ang) + oy * cos(ang);
	*x += mx;
	*y += my;

}

void walk(float *ModelPosX, float *ModelPosZ, const float angle, float *cameraX, float *cameraZ, float speed)
{
	float reverse;
	float x, z;
	reverse = (DX_PI / 2) - angle;
	x = sin(angle) * speed / sin(DX_PI / 2);
	z = sin(reverse) * speed / sin(DX_PI / 2);
	*ModelPosX += x;
	*ModelPosZ += z;
	*cameraX += x;
	*cameraZ += z;
}





PlayerHandler::PlayerHandler(void)
{

}


PlayerHandler::~PlayerHandler(void)
{

}

void PlayerHandler::PlayerInitializationForBossRush(int VolumeSE)
{

	ModelFlag = 1;
	if (ModelFlag == 1)
		Model = MV1LoadModel(M3D_MALECHAR);
	Animation = -1;
	Life = 5;
	Position = VGet(0, 0, -7500);
	Direction = 1;
	Angle = VGet(0, 0, 0);
	count = 0;
	Camera = VGet(Position.x + 0, Position.y + 800, Position.z + (-2000));
	SetCameraNearFar(250.f, 50000.f); // 100

	Radius = 100.f;
	ItemFlag = 1; /////
	ItemChangeInterval = 0;

	AttackFlag = 0;
	Score = 0;
	speed = 0.f;
	DamageIntervalCount = 0;
	JumpPower = 0.f;
	JumpFlag = 0;
	StageFlag = 0;
	EnemyFlag = 0;
	AR1 = Position;
	AR2 = Position;
	A1 = VGet(Position.x - 100.f, Position.y + 10.f, Position.z + 100.f);
	A2 = VGet(Position.x + 100.f, Position.y + 10.f, Position.z + 100.f);
	A3 = VGet(Position.x + 100.f, Position.y + 10.f, Position.z - 100.f);
	A4 = VGet(Position.x - 100.f, Position.y + 10.f, Position.z - 100.f);

	snd_Jump = LoadSoundMem(SE_JUMP);
	snd_Run = LoadSoundMem(SE_RUN);
	ChangeVolumeSoundMem(VolumeSE, snd_Run);
	ChangeVolumeSoundMem(VolumeSE, snd_Jump);
	img_Life = LoadGraph(GUI_LIFE);
	img_LifeG = LoadGraph(GUI_LIFEG);
	img_Item1 = LoadGraph(GUI_ITEM1);
	img_Item2 = LoadGraph(GUI_ITEM2);

	FontNormal = CreateFontToHandle(NULL, -1, -1, DX_FONTTYPE_NORMAL);
	FontScore = CreateFontToHandle(NULL, 30, -1, DX_FONTTYPE_NORMAL);
}

void PlayerHandler::PlayerInitialization(int VolumeSE, int playerDirection, int playerCount, VECTOR playerAngle, VECTOR playerPosition, float CameraRotate, SaveData m_sd)
{
	sd = m_sd;
	ModelFlag = sd.ModelFlag;
	if (ModelFlag == 1)
		Model = MV1LoadModel(M3D_MALECHAR);
	else if (ModelFlag == 2)
		Model = MV1LoadModel(M3D_FEMALECHAR);
	Animation = -1;
	Life = sd.Life;
	Position = playerPosition;
	Direction = playerDirection;
	Angle = playerAngle;
	count = playerCount;;
	Camera = VGet(Position.x + 0, Position.y + 800, Position.z + (-2000));
	rotate(&Camera.x, &Camera.z, -CameraRotate, Position.x, Position.z);
	MV1SetRotationXYZ(Model, Angle);
	SetCameraNearFar(250.f, 50000.f); // 100
	for (int i = 0; i < 17; i++)
		EnemyDefeated[i] = sd.EnemyDefeatedNumber[i];

	Radius = 100.f;
	ItemFlag = sd.ItemFlag; /////
	ItemChangeInterval = 0;

	AttackFlag = 0;
	Score = sd.Score;
	speed = 0.f;
	DamageIntervalCount = 0;
	JumpPower = 0.f;
	JumpFlag = 0;
	StageFlag = 0;
	EnemyFlag = 0;
	AR1 = Position;
	AR2 = Position;
	A1 = VGet(Position.x - 100.f, Position.y + 10.f, Position.z + 100.f);
	A2 = VGet(Position.x + 100.f, Position.y + 10.f, Position.z + 100.f);
	A3 = VGet(Position.x + 100.f, Position.y + 10.f, Position.z - 100.f);
	A4 = VGet(Position.x - 100.f, Position.y + 10.f, Position.z - 100.f);

	img_CompassN = LoadGraph(GUI_COMPASS_N);
	img_CompassE = LoadGraph(GUI_COMPASS_E);
	img_CompassS = LoadGraph(GUI_COMPASS_S);
	img_CompassW = LoadGraph(GUI_COMPASS_W);
	img_CompassNE = LoadGraph(GUI_COMPASS_NE);
	img_CompassNW = LoadGraph(GUI_COMPASS_NW);
	img_CompassSE = LoadGraph(GUI_COMPASS_SE);
	img_CompassSW = LoadGraph(GUI_COMPASS_SW);
	img_Life = LoadGraph(GUI_LIFE);
	img_LifeG = LoadGraph(GUI_LIFEG);
	img_Item1 = LoadGraph(GUI_ITEM1);
	img_Item2 = LoadGraph(GUI_ITEM2);
	img_Score = LoadGraph(GUI_SCORE);

	switch (sd.CurrentStage)
	{
	case 1:
		if (sd.CurrentArea == 1)	img_Map = LoadGraph(GUI_MAP_ST1AR1);
		if (sd.CurrentArea == 2)	img_Map = LoadGraph(GUI_MAP_ST1AR2);
		if (sd.CurrentArea == 3)	img_Map = LoadGraph(GUI_MAP_ST1AR3);
		break;
	case 2:
		if (sd.CurrentArea == 1)	img_Map = LoadGraph(GUI_MAP_ST2AR1);
		if (sd.CurrentArea == 2)	img_Map = LoadGraph(GUI_MAP_ST2AR2);
		if (sd.CurrentArea == 3)	img_Map = LoadGraph(GUI_MAP_ST2AR3);
		if (sd.CurrentArea == 4)	img_Map = LoadGraph(GUI_MAP_ST2AR4);
		break;
	case 3:
		if (sd.CurrentArea == 1)	img_Map = LoadGraph(GUI_MAP_ST3AR1);
		if (sd.CurrentArea == 2)	img_Map = LoadGraph(GUI_MAP_ST3AR2);
		if (sd.CurrentArea == 3)	img_Map = LoadGraph(GUI_MAP_ST3AR3);
		if (sd.CurrentArea == 4)	img_Map = LoadGraph(GUI_MAP_ST3AR4);
		break;
	case 4:
		if (sd.CurrentArea == 1)	img_Map = LoadGraph(GUI_MAP_ST4AR1);
		if (sd.CurrentArea == 2)	img_Map = LoadGraph(GUI_MAP_ST4AR2);
		if (sd.CurrentArea == 3)	img_Map = LoadGraph(GUI_MAP_ST4AR3);
		if (sd.CurrentArea == 4)	img_Map = LoadGraph(GUI_MAP_ST4AR4);
		break;
	case 5:
		if (sd.CurrentArea == 1)	img_Map = LoadGraph(GUI_MAP_ST5AR1);
		if (sd.CurrentArea == 2)	img_Map = LoadGraph(GUI_MAP_ST5AR2);
		if (sd.CurrentArea == 3)	img_Map = LoadGraph(GUI_MAP_ST5AR3);
		if (sd.CurrentArea == 4)	img_Map = LoadGraph(GUI_MAP_ST5AR4);
		break;
	}

	snd_Jump = LoadSoundMem(SE_JUMP);
	snd_Run = LoadSoundMem(SE_RUN);
	ChangeVolumeSoundMem(VolumeSE, snd_Run);
	ChangeVolumeSoundMem(VolumeSE, snd_Jump);

	FontNormal = CreateFontToHandle(NULL, -1, -1, DX_FONTTYPE_NORMAL);
	FontScore = CreateFontToHandle(NULL, 30, -1, DX_FONTTYPE_NORMAL);

}

void PlayerHandler::PlayerDraw(void) // CAN USE
{
	MV1SetPosition(Model, Position);
	if (AttackFlag == 0)
		SetCameraPositionAndTarget_UpVecY(Camera, VGet(Position.x, Position.y + 200.f, Position.z));
	MV1DrawModel(Model);
}

void PlayerHandler::PlayerStatusDrawForBossRush(int ssX, int ssY, int HighScore, int RoundNo, int CurrentTime)
{
	DrawGraph(20, 20, img_Life, TRUE);
	for (int i = 0; i < Life; i++)
		DrawGraph(20 + GUI_LIFE_X + (10 * i) + (GUI_LIFEG_X * i), 20, img_LifeG, TRUE);

	switch (ItemFlag)
	{
	case 1:
		DrawGraph(ssX - GUI_ITEM_X - 20, ssY - GUI_ITEM_Y - 20, img_Item1, TRUE);
		break;
	case 2:
		DrawGraph(ssX - GUI_ITEM_X - 20, ssY - GUI_ITEM_Y - 20, img_Item2, TRUE);
		break;
	}

	if (HighScore < Score)
	{
		DrawFormatStringToHandle(800 - 250 - 20 + 2, 20 + 2, BC_BLACK, FontScore, "HIGH SCORE: %d", Score);
		DrawFormatStringToHandle(800 - 250 - 20, 20, BC_BROWN, FontScore, "HIGH SCORE: %d", Score);
	}
	else
	{
		DrawFormatStringToHandle(800 - 250 - 20 + 2, 20 + 2, BC_BLACK, FontScore, "HIGH SCORE:%d", HighScore);
		DrawFormatStringToHandle(800 - 250 - 20, 20, BC_BROWN, FontScore, "HIGH SCORE:%d", HighScore);
	}
	DrawFormatStringToHandle(800 - 200 + 2 + 10, 60 + 2, BC_BLACK, FontScore, "SCORE:%d", Score);
	DrawFormatStringToHandle(800 - 200 + 10, 60, BC_BROWN, FontScore, "SCORE:%d", Score);

	DrawFormatStringToHandle(40 + GUI_LIFE_X + 2, 10 + GUI_LIFEG_Y + (GUI_SCORE_Y / 2) + 2, BC_BLACK, FontScore, "Round: %d", RoundNo);
	DrawFormatStringToHandle(40 + GUI_LIFE_X, 10 + GUI_LIFEG_Y + (GUI_SCORE_Y / 2), BC_BROWN, FontScore, "Round: %d", RoundNo);

	DrawFormatStringToHandle(800 - 200 + 2 + 10, 100 + 2, BC_BLACK, FontScore, "TIME:%d", CurrentTime);
	DrawFormatStringToHandle(800 - 200 + 10, 100, BC_BROWN, FontScore, "TIME:%d", CurrentTime);

}

void PlayerHandler::PlayerStatusDraw(int ssX, int ssY)
{

	DrawGraph(20, 20, img_Life, TRUE);
	for (int i = 0; i < Life; i++)
	{
		DrawGraph(20 + GUI_LIFE_X + (10 * i) + (GUI_LIFEG_X * i), 20, img_LifeG, TRUE);
	}

	DrawGraph(40 + GUI_LIFE_X, 20 + GUI_LIFEG_Y, img_Score, TRUE);
	DrawFormatStringToHandle(40 + GUI_LIFE_X + GUI_SCORE_X + 2, 10 + GUI_LIFEG_Y + (GUI_SCORE_Y / 2) + 2, BC_BLACK, FontScore, "%d", Score);
	DrawFormatStringToHandle(40 + GUI_LIFE_X + GUI_SCORE_X, 10 + GUI_LIFEG_Y + (GUI_SCORE_Y / 2), BC_BROWN, FontScore, "%d", Score);
	//DrawFormatString(10, 10, BC_WHITE, "HP = %d", Life);
	//DrawFormatString(10, 30, BC_WHITE, "SCORE = %d", Score);
	//DrawFormatString(10, 50, BC_WHITE, "ITEM = %s", ItemName);

	switch (ItemFlag)
	{
	case 1:
		DrawGraph(ssX - GUI_ITEM_X - 20, ssY - GUI_ITEM_Y - 20, img_Item1, TRUE);
		break;
	case 2:
		DrawGraph(ssX - GUI_ITEM_X - 20, ssY - GUI_ITEM_Y - 20, img_Item2, TRUE);
		break;
	}

	DrawGraph(ssX - GUI_MAP_X - 20, 0 + 20, img_Map, TRUE);
	switch (Direction)
	{
	case 1:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassN, TRUE); break;
	case 2:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassE, TRUE); break;
	case 3:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassS, TRUE); break;
	case 4:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassW, TRUE); break;
	case 5:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassNE, TRUE); break;
	case 6:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassSE, TRUE); break;
	case 7:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassSW, TRUE); break;
	case 8:	DrawGraph(ssX - GUI_COMPASS_X - 10, GUI_MAP_Y, img_CompassNW, TRUE); break;
	}

}

void PlayerHandler::PlayerUpdateMovement(int MovementNumber, int CollisionFlag, int DirectionNumber)
{
	switch (MovementNumber)
	{
	case 1: // WALK
		if (CollisionFlag == 0)
		{
			if (speed <= max_speed)
				speed += 12.f;
			walk(&Position.x, &Position.z, Angle.y, &Camera.x, &Camera.z, speed);
			EnemyFlag = 0;

		}
		else if (CollisionFlag == 1)
		{
			speed = 1.0f;
			walk(&Position.x, &Position.z, Angle.y, &Camera.x, &Camera.z, speed);
			speed = 0.f;
			EnemyFlag = 0;
		}

		if (CheckSoundMem(snd_Run) != 1)
			PlaySoundMem(snd_Run, DX_PLAYTYPE_BACK, TRUE);
		break;
	case 0:
		if (speed > 0.f)
		{
			walk(&Position.x, &Position.z, Angle.y, &Camera.x, &Camera.z, speed);
			speed -= 0.4f;
		}
		if (speed < 0.f)
			speed = 0.f;
		StopSoundMem(snd_Run);
		break;
	}


	switch (DirectionNumber)
	{
	case 0:
		break;
	case 1:
		Angle.y -= ROTATE_SPEED;
		count--;
		rotate(&Camera.x, &Camera.z, -ROTATE_SPEED, Position.x, Position.z);
		break;
	case 2:
		Angle.y += ROTATE_SPEED;
		rotate(&Camera.x, &Camera.z, +ROTATE_SPEED, Position.x, Position.z);
		count++;
		break;
	}
	MV1SetRotationXYZ(Model, Angle);
	if (count == 180 || count == -180)
		count = 0;
	if ((count >= 0 && count <= 15) || (count >= 165 && count <= 180) || (count <= -1 && count >= -15) || (count <= -165 && count >= -180))
		Direction = 1;
	else if ((count >= 30 && count <= 60) || (count <= -120 && count >= -150))
		Direction = 2;
	else if ((count >= 75 && count <= 105) || (count <= -75 && count >= -105))
		Direction = 3;
	else if ((count >= 120 && count <= 150) || (count <= -30 && count >= -60))
		Direction = 4;
	else if ((count >= 16 && count <= 29) || (count <= -151 && count >= -164))
		Direction = 5;
	else if ((count >= 61 && count <= 74) || (count <= -106 && count >= -119))
		Direction = 6;
	else if ((count >= 106 && count <= 119) || (count <= -61 && count >= -74))
		Direction = 7;
	else if ((count >= 151 && count <= 164) || (count <= -16 && count >= -29))
		Direction = 8;
	A1 = VGet(Position.x - 90.f, Position.y + 10.f, Position.z + 90.f);
	A2 = VGet(Position.x + 90.f, Position.y + 10.f, Position.z + 90.f);
	A3 = VGet(Position.x + 90.f, Position.y + 10.f, Position.z - 90.f);
	A4 = VGet(Position.x - 90.f, Position.y + 10.f, Position.z - 90.f);
}

void PlayerHandler::PlayerUpdateJump(int MovementNumber, int CollisionFlag)
{
	if (CollisionFlag != 1)
	{
		Position.y -= gravity;
		Camera.y -= gravity;
		StopSoundMem(snd_Run);

	}
	else
	{
		JumpFlag = 0;
		JumpPower = 0;

	}

	if (MovementNumber == 1)
	{
		if (JumpFlag == 0)
		{
			JumpFlag = 1;
			walk(&Position.x, &Position.z, Angle.y, &Camera.x, &Camera.z, 10.f);
			JumpPower = 80.f;
			PlaySoundMem(snd_Jump, DX_PLAYTYPE_BACK, TRUE);
		}
	}
	if (JumpFlag == 1)
	{
		if (JumpPower > -20.f)
			JumpPower -= 4.0f;
		Position.y += JumpPower;
		Camera.y += JumpPower;
	}

}

int PlayerHandler::PlayerUpdateAction1(int ActionNumber)
{
	if (ActionNumber == 1)
	{
		if (ItemFlag == 1)
		{
			float reverse;
			float x, z;
			reverse = (DX_PI / 2) - Angle.y;
			x = sin(Angle.y) * 400.f / sin(DX_PI / 2);
			z = sin(reverse) * 400.f / sin(DX_PI / 2);
			AR1.x = x + Position.x;
			AR1.z = z + Position.z;
			AR1.y = Position.y + Radius;
			AR2 = VGet(Position.x, Position.y + Radius, Position.z);
			DrawLine3D(AR1, AR2, BC_WHITE);
			return 1;
		}
		if (ItemFlag == 2)
		{
			float reverse;
			float x, z;
			reverse = (DX_PI / 2) - Angle.y;
			x = sin(Angle.y) * 800.f / sin(DX_PI / 2);
			z = sin(reverse) * 800.f / sin(DX_PI / 2);
			AR1.x = x + Position.x;
			AR1.z = z + Position.z;
			AR1.y = Position.y + Radius;
			AR2 = VGet(Position.x, Position.y + Radius, Position.z);
			DrawLine3D(AR1, AR2, BC_WHITE);
			return 1;
		}
	}
	else
	{
		AR1 = VGet(Position.x, Position.y + 10000, Position.z);
		AR2 = VGet(Position.x, Position.y + 10000, Position.z);
	}
	return 0;
}

void PlayerHandler::PlayerUpdateChangeWeapon(int ChangeFlag)
{
	if (ItemChangeInterval == 0)
	{
		if (ChangeFlag == 1)
		{
			if (ItemFlag == 1)
				ItemFlag = 2;
			else if (ItemFlag == 2)
				ItemFlag = 1;
			ItemChangeInterval = 1;
		}
	}
	else
	{
		if (ItemChangeInterval < 40)
			ItemChangeInterval++;
		else
			ItemChangeInterval = 0;
	}
}

void PlayerHandler::ReleaseData(void)
{
	MV1DeleteModel(Model);
	ModelFlag = 0;
	Animation = 0;
	Life = 0;
	DeleteGraph(img_Life);
	DeleteGraph(img_LifeG);
	Position = VEC_ORIGIN;
	Camera = VEC_ORIGIN;
	Angle = VEC_ORIGIN;
	count = 0;
	Direction = 0;
	DeleteGraph(img_CompassN);
	DeleteGraph(img_CompassE);
	DeleteGraph(img_CompassW);
	DeleteGraph(img_CompassS);
	DeleteGraph(img_CompassNE);
	DeleteGraph(img_CompassNW);
	DeleteGraph(img_CompassSE);
	DeleteGraph(img_CompassSW);
	DeleteGraph(img_Map);
	DeleteGraph(img_Item1);
	DeleteGraph(img_Item2);
	DeleteGraph(img_Score);
	for (int i = 0; i < 17; i++)
		EnemyDefeated[i] = 0;
	Radius = 0;
	ItemFlag = 0;
	ItemChangeInterval = 0;
	AttackFlag = 0;
	Score = 0;
	speed = 0;
	JumpPower = 0;
	JumpFlag = 0;
	StageFlag = 0;
	EnemyFlag = 0;
	DeleteSoundMem(snd_Jump);
	DeleteSoundMem(snd_Run);
	DamageIntervalCount = 0;
	AR1 = VEC_ORIGIN;
	AR2 = VEC_ORIGIN;
	A1 = VEC_ORIGIN;
	A2 = VEC_ORIGIN;
	A3 = VEC_ORIGIN;
	A4 = VEC_ORIGIN;
	DeleteFontToHandle(FontNormal);
	DeleteFontToHandle(FontScore);

}
