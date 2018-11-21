#pragma once
#include "DataList.h"
#include <DxLib.h>

typedef struct
{
	VECTOR centerHip;
	VECTOR centerShoulder;
	VECTOR spine;
	VECTOR head;
	VECTOR leftShoulder;
	VECTOR leftElbow;
	VECTOR leftWrist;
	VECTOR leftHand;
	VECTOR rightShoulder;
	VECTOR rightElbow;
	VECTOR rightWrist;
	VECTOR rightHand;
	VECTOR leftHip;
	VECTOR leftKnee;
	VECTOR leftAnkle;
	VECTOR leftFoot;
	VECTOR rightHip;
	VECTOR rightKnee;
	VECTOR rightAnkle;
	VECTOR rightFoot;

}PlayerBone;

class K_KinectHandler
{
	HANDLE m_pDepthStreamHandle;  ///<typedef="HANDLE"> Event Handler </typdef>///
	HANDLE m_hNextEvent[2];
	PlayerBone pb[2]; // 0 = old, 1 = now;

	int img_CursorPointer;

	// CheckMovement flag = if click
	int MovementFlag, MovementReadableInterval, MovementWhileInMotion;
	// CheckWalk flag = if walked
	int MovementFlagR, MovementReadableIntervalR, MovementWhileInMotionR;
	int MovementFlagL, MovementReadableIntervalL, MovementWhileInMotionL;
	// CheckAttack flag
	int AttackFlag, AttackWhileInMotion;
	int JumpFlag;
	int ChangeWeaponFlag;
public:
	int kinect_init;
	int cursorX;
	int cursorY;
	int cursorFlag;

	K_KinectHandler(void);
	~K_KinectHandler(void);

	void GetBodyPoint(void);
	void DisplayCursorPointer(void);
	void GetCursorPointer(int ssx, int ssy);
	float Get3DPythagorean(VECTOR From, VECTOR To);
	float GetDistancePercentage(VECTOR Origin, VECTOR Pointer, int Line, float tLength);
	void CheckBodyMovement(void);
	int CheckMovement(void); // 1 Walk or 0 not
	int CheckJump(void); // 1 Jump or 0 not
	int CheckDirection(void); // 0 front, 1 left, 2 right
	int CheckAttack(int ItemFlag); // 1 attack 2 not : Arnis
	int CheckChangeWeapon(void); // 0 not, 1 change;
	int CheckEscapeGame(void);
	void Kinect_End(void);
};

