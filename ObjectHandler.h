#pragma once
#include <DxLib.h>
#include "DataList.h"
class ObjectHandler
{
public:

	int Model;
	VECTOR Position, Angle;
	int Exist;
	int ObjectNumber;
	SaveData sd, upSD;

	ObjectHandler(void);
	void ObjectInitialization(SaveData m_sd, int ObjNumber);
	void ObjectDraw(void);
	int ObjectTouched(void);
	void ObjectUpdate(int BossDefeatedFlag, int KeyNumbers);
	~ObjectHandler(void);
	void ReleaseData(void);
};

