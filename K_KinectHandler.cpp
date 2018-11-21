#include "K_KinectHandler.h"
#include <DxLib.h>
#include "DataList.h"

K_KinectHandler::K_KinectHandler(void)
{

	// START: Initialization of Body Points
	for (int i = 0; i < 2;i++)
	{
		pb[i].centerHip = VGet(0, 0, 0);
		pb[i].centerShoulder = VGet(0, 0, 0);
		pb[i].spine = VGet(0, 0, 0);
		pb[i].head = VGet(0, 0, 0);
		pb[i].leftShoulder = VGet(0, 0, 0);
		pb[i].leftElbow = VGet(0, 0, 0);
		pb[i].leftWrist = VGet(0, 0, 0);
		pb[i].leftHand = VGet(0, 0, 0);
		pb[i].rightShoulder = VGet(0, 0, 0);
		pb[i].rightElbow = VGet(0, 0, 0);
		pb[i].rightWrist = VGet(0, 0, 0);
		pb[i].rightHand = VGet(0, 0, 0);
		pb[i].leftHip = VGet(0, 0, 0);
		pb[i].leftKnee = VGet(0, 0, 0);
		pb[i].leftAnkle = VGet(0, 0, 0);
		pb[i].leftFoot = VGet(0, 0, 0);
		pb[i].rightHip = VGet(0, 0, 0);
		pb[i].rightKnee = VGet(0, 0, 0);
		pb[i].rightAnkle = VGet(0, 0, 0);
		pb[i].rightFoot = VGet(0, 0, 0);
	}


	// END: Initialization of Body Points

   // START: Initialization of KINECT
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX | NUI_INITIALIZE_FLAG_USES_SKELETON);
	m_hNextEvent[0] = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hNextEvent[1] = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_pDepthStreamHandle = NULL;
	HRESULT hr =
		NuiImageStreamOpen(NUI_IMAGE_TYPE_DEPTH_AND_PLAYER_INDEX, NUI_IMAGE_RESOLUTION_320x240, 0, 2, m_hNextEvent[0], &m_pDepthStreamHandle);
	if (FAILED(hr))
	{
		kinect_init = -1;
		return;
	}
	hr = NuiSkeletonTrackingEnable(m_hNextEvent[1], 0);
	if (FAILED(hr))
	{
		kinect_init = -1;
		return;
	}
	kinect_init = 0;
	// END: Initialization of KINECT

	MovementFlag = 0;	MovementReadableInterval = 0;	MovementWhileInMotion = 0; // 0 rest, 1 do
	MovementFlagR = 0;	MovementReadableIntervalR = 0;	MovementWhileInMotionR = 0; // 0 rest, 1 do
	MovementFlagL = 0;	MovementReadableIntervalL = 0;	MovementWhileInMotionL = 0; // 0 rest, 1 do
	JumpFlag = 0;
	ChangeWeaponFlag = 0;

	//SetMouseDispFlag( TRUE );
	//GetMousePoint( &cursorX, &cursorY );

	cursorFlag = 0;
	img_CursorPointer = LoadGraph(G_CURSORPOINTER);

}

void K_KinectHandler::GetBodyPoint()
{
	NUI_SKELETON_FRAME SkeletonFrame; ///<typedef="NUI_SKELETON_FRAME"> Construct a Skeleton </typedef>///
	HRESULT hr = NuiSkeletonGetNextFrame(0, &SkeletonFrame); ///<Method="NuiSkeletonGetNextFrame">Initialize the SkeletonFrame</Method>///

	if (FAILED(hr))
		return;


	for (int cursor = 0; cursor < NUI_SKELETON_COUNT; cursor++)
	{
		if (SkeletonFrame.SkeletonData[cursor].eTrackingState == NUI_SKELETON_TRACKED)
		{
			NUI_SKELETON_DATA data = SkeletonFrame.SkeletonData[cursor];

			for (int count = 0; count < NUI_SKELETON_POSITION_COUNT; count++)
			{
				switch (count)
				{

				case HIP_CENTER:
					pb[1].centerHip =
						VGet(data.SkeletonPositions[HIP_CENTER].x, data.SkeletonPositions[HIP_CENTER].y, data.SkeletonPositions[HIP_CENTER].z);
					break;

				case SHOULDER_CENTER:
					pb[1].centerShoulder =
						VGet(data.SkeletonPositions[SHOULDER_CENTER].x, data.SkeletonPositions[SHOULDER_CENTER].y, data.SkeletonPositions[SHOULDER_CENTER].z);
					break;

				case SPINE:
					pb[1].spine =
						VGet(data.SkeletonPositions[SPINE].x, data.SkeletonPositions[SPINE].y, data.SkeletonPositions[SPINE].z);
					break;

				case HEAD:
					pb[1].head =
						VGet(data.SkeletonPositions[HEAD].x, data.SkeletonPositions[HEAD].y, data.SkeletonPositions[HEAD].z);
					break;

				case SHOULDER_LEFT:
					pb[1].leftShoulder =
						VGet(data.SkeletonPositions[SHOULDER_LEFT].x, data.SkeletonPositions[SHOULDER_LEFT].y, data.SkeletonPositions[SHOULDER_LEFT].z);
					break;

				case ELBOW_LEFT:
					pb[1].leftElbow =
						VGet(data.SkeletonPositions[ELBOW_LEFT].x, data.SkeletonPositions[ELBOW_LEFT].y, data.SkeletonPositions[ELBOW_LEFT].z);
					break;

				case WRIST_LEFT:
					pb[1].leftWrist =
						VGet(data.SkeletonPositions[WRIST_LEFT].x, data.SkeletonPositions[WRIST_LEFT].y, data.SkeletonPositions[WRIST_LEFT].z);
					break;

				case HAND_LEFT:
					pb[1].leftHand =
						VGet(data.SkeletonPositions[HAND_LEFT].x, data.SkeletonPositions[HAND_LEFT].y, data.SkeletonPositions[HAND_LEFT].z);
					break;

				case SHOULDER_RIGHT:
					pb[1].rightShoulder =
						VGet(data.SkeletonPositions[SHOULDER_RIGHT].x, data.SkeletonPositions[SHOULDER_RIGHT].y, data.SkeletonPositions[SHOULDER_RIGHT].z);
					break;

				case ELBOW_RIGHT:
					pb[1].rightElbow =
						VGet(data.SkeletonPositions[ELBOW_RIGHT].x, data.SkeletonPositions[ELBOW_RIGHT].y, data.SkeletonPositions[ELBOW_RIGHT].z);
					break;

				case WRIST_RIGHT:
					pb[1].rightWrist =
						VGet(data.SkeletonPositions[WRIST_RIGHT].x, data.SkeletonPositions[WRIST_RIGHT].y, data.SkeletonPositions[WRIST_RIGHT].z);
					break;

				case HAND_RIGHT:
					pb[1].rightHand =
						VGet(data.SkeletonPositions[HAND_RIGHT].x, data.SkeletonPositions[HAND_RIGHT].y, data.SkeletonPositions[HAND_RIGHT].z);
					break;

				case HIP_LEFT:
					pb[1].leftHip =
						VGet(data.SkeletonPositions[HIP_LEFT].x, data.SkeletonPositions[HIP_LEFT].y, data.SkeletonPositions[HIP_LEFT].z);
					break;

				case KNEE_LEFT:
					pb[1].leftKnee =
						VGet(data.SkeletonPositions[KNEE_LEFT].x, data.SkeletonPositions[KNEE_LEFT].y, data.SkeletonPositions[KNEE_LEFT].z);
					break;

				case ANKLE_LEFT:
					pb[1].leftAnkle =
						VGet(data.SkeletonPositions[ANKLE_LEFT].x, data.SkeletonPositions[ANKLE_LEFT].y, data.SkeletonPositions[ANKLE_LEFT].z);
					break;

				case FOOT_LEFT:
					pb[1].leftFoot =
						VGet(data.SkeletonPositions[FOOT_LEFT].x, data.SkeletonPositions[FOOT_LEFT].y, data.SkeletonPositions[FOOT_LEFT].z);
					break;

				case HIP_RIGHT:
					pb[1].rightHip =
						VGet(data.SkeletonPositions[HIP_RIGHT].x, data.SkeletonPositions[HIP_RIGHT].y, data.SkeletonPositions[HIP_RIGHT].z);
					break;

				case KNEE_RIGHT:
					pb[1].rightKnee =
						VGet(data.SkeletonPositions[KNEE_RIGHT].x, data.SkeletonPositions[KNEE_RIGHT].y, data.SkeletonPositions[KNEE_RIGHT].z);
					break;

				case ANKLE_RIGHT:
					pb[1].rightAnkle =
						VGet(data.SkeletonPositions[ANKLE_RIGHT].x, data.SkeletonPositions[ANKLE_RIGHT].y, data.SkeletonPositions[ANKLE_RIGHT].z);
					break;

				case FOOT_RIGHT:
					pb[1].rightFoot =
						VGet(data.SkeletonPositions[FOOT_RIGHT].x, data.SkeletonPositions[FOOT_RIGHT].y, data.SkeletonPositions[FOOT_RIGHT].z);
					break;
				} // END: switch statement : pass value from SKELETON DATA to the VECTOR typedef
			} // END: for statement : looping to find the SKEETON DATA
		} // END: if statement : If tracked that Body Point, then create a DATA
	} // END: for statement : looping for the number of Body Points

} // GetBodyPoint: END

K_KinectHandler::~K_KinectHandler(void)
{
	DeleteGraph(img_CursorPointer);
}

void K_KinectHandler::DisplayCursorPointer(void)
{

	DrawGraph(cursorX - (CP_XY / 2), cursorY - (CP_XY / 2), img_CursorPointer, TRUE);

}

void K_KinectHandler::GetCursorPointer(int ssx, int ssy)
{
	float xlengthSE = 0;
	float xlengthEH = 0;
	float xtLength = 0;
	float xPercentage = 0;
	float xCursorPosition = 0;

	xlengthSE = Get3DPythagorean(pb[1].rightShoulder, pb[1].rightElbow);
	xlengthEH = Get3DPythagorean(pb[1].rightElbow, pb[1].rightHand);
	xtLength = (xlengthSE + xlengthEH) * 7 / 10;/////////////////// /2
	xPercentage = GetDistancePercentage(pb[1].rightShoulder, pb[1].rightHand, xLine, xtLength);


	xCursorPosition = (ssx / 2 - 1) - (xPercentage * ssx / 100 / 2);

	float ylengthSE = 0;
	float ylengthEH = 0;
	float ytLength = 0;
	float yPercentage = 0;
	float yCursorPosition = 0;

	ylengthSE = Get3DPythagorean(pb[1].rightShoulder, pb[1].rightElbow);
	ylengthEH = Get3DPythagorean(pb[1].rightElbow, pb[1].rightHand);
	ytLength = (ylengthSE + ylengthEH) * 7 / 10;/////////////////// /2
	yPercentage = GetDistancePercentage(pb[1].rightShoulder, pb[1].rightHand, yLine, ytLength);


	yCursorPosition = (ssy / 2 - 1) - (yPercentage * ssy / 100 / 2);

	cursorX = xCursorPosition;
	cursorY = yCursorPosition;

	//GetMousePoint( &cursorX, &cursorY);
}

float K_KinectHandler::Get3DPythagorean(VECTOR From, VECTOR To)
{
	float xLength = From.x - To.x;
	float yLength = From.y - To.y;
	float zLength = From.z - To.z;
	float pythagorean_3d = sqrt((xLength * xLength) + (yLength * yLength) + (zLength * zLength));
	return pythagorean_3d;
}

float K_KinectHandler::GetDistancePercentage(VECTOR Origin, VECTOR Pointer, int Line, float tLength)
{
	float Length = 0;

	if (Line == xLine)
		Length = Origin.x - Pointer.x;
	else if (Line == yLine)
		Length = Pointer.y - Origin.y;

	float Percentage = (Length / tLength * 100); // + 10 added

	return Percentage;
}

void K_KinectHandler::CheckBodyMovement(void)
{
	cursorFlag = 0;
	float a1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightKnee);
	float b1 = Get3DPythagorean(pb[1].rightKnee, pb[1].rightAnkle);
	float c1 = a1 + b1;
	float d1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightAnkle);
	if (c1 * 5 / 6 > d1)
	{
		if (MovementWhileInMotion == 0)
		{
			MovementFlag = 1; // start counting;
			MovementReadableInterval = 1;
		}
		MovementWhileInMotion = 1;

	}
	else
	{
		MovementWhileInMotion = 0;
		if (MovementFlag == 1)
		{
			MovementFlag = 0;
			MovementReadableInterval = 0;
			cursorFlag = 1;
		}
	}

	if (MovementReadableInterval > 0 && MovementReadableInterval < 60)
		MovementReadableInterval++;
	else if (MovementReadableInterval >= 60)
	{
		MovementReadableInterval = 0;
		MovementFlag = 0;
	}


	//cursorFlag = GetMouseInput( );
}

int K_KinectHandler::CheckMovement(void)
{

	float a1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightKnee);
	float b1 = Get3DPythagorean(pb[1].rightKnee, pb[1].rightAnkle);
	float c1 = a1 + b1;
	float d1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightAnkle);
	if (c1 * 5 / 6 > d1)
	{
		if (MovementWhileInMotionR == 0)
		{
			MovementFlagR = 1; // start counting;
			MovementReadableIntervalR = 1;
		}
		MovementWhileInMotionR = 1;

	}
	else
	{
		MovementWhileInMotionR = 0;
		if (MovementFlagR == 1)
		{
			MovementFlagR = 0;
			MovementReadableIntervalR = 0;
			return 1;
		}
	}

	if (MovementReadableIntervalR > 0 && MovementReadableIntervalR < 120)
		MovementReadableIntervalR++;
	else if (MovementReadableIntervalR >= 120)
	{
		MovementReadableIntervalR = 0;
		MovementFlagR = 0;
	}

	float a2 = Get3DPythagorean(pb[1].leftHip, pb[1].leftKnee);
	float b2 = Get3DPythagorean(pb[1].leftKnee, pb[1].leftAnkle);
	float c2 = a2 + b2;
	float d2 = Get3DPythagorean(pb[1].leftHip, pb[1].leftAnkle);
	if (c2 * 5 / 6 > d2)
	{
		if (MovementWhileInMotionL == 0)
		{
			MovementFlagL = 1; // start counting;
			MovementReadableIntervalL = 1;
		}
		MovementWhileInMotionL = 1;

	}
	else
	{
		MovementWhileInMotionL = 0;
		if (MovementFlagL == 1)
		{
			MovementFlagL = 0;
			MovementReadableIntervalL = 0;
			return 1;
		}
	}

	if (MovementReadableIntervalL > 0 && MovementReadableIntervalL < 120)
		MovementReadableIntervalL++;
	else if (MovementReadableIntervalL >= 120)
	{
		MovementReadableIntervalL = 0;
		MovementFlagL = 0;
	}

	if (CheckHitKey(KEY_INPUT_UP) > 0)
		return 1;
	return 0;
}

int K_KinectHandler::CheckDirection(void)
{

	if (pb[1].leftWrist.y > pb[1].leftShoulder.y)
	{
		if (pb[1].leftWrist.x < pb[1].leftShoulder.x)
			return 1;
		else
			return 2;
	}



	if (CheckHitKey(KEY_INPUT_LEFT) > 0)
		return 1;
	if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
		return 2;
	else
		return 0;
}

int K_KinectHandler::CheckJump(void)
{

	float a1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightKnee);
	float b1 = Get3DPythagorean(pb[1].rightKnee, pb[1].rightAnkle);
	float c1 = a1 + b1;
	float d1 = Get3DPythagorean(pb[1].rightHip, pb[1].rightAnkle);

	float a2 = Get3DPythagorean(pb[1].leftHip, pb[1].leftKnee);
	float b2 = Get3DPythagorean(pb[1].leftKnee, pb[1].leftAnkle);
	float c2 = a2 + b2;
	float d2 = Get3DPythagorean(pb[1].leftHip, pb[1].leftAnkle);

	if (JumpFlag == -0)
	{
		if ((c1 * 95 / 100 > d1) && (c2 * 95 / 100 > d2))
			JumpFlag = 1;
	}
	else
	{
		if ((c1 * 95 / 100 < d1) && (c2 * 95 / 100 < d2))
		{
			JumpFlag = 0;
			return 1;
		}
	}

	if (CheckHitKey(KEY_INPUT_Z) > 0)
		return 1;
	return 0;

}

int K_KinectHandler::CheckAttack(int ItemFlag)
{

	if (ItemFlag == 1)
	{
		if (pb[1].rightHand.y > pb[1].centerShoulder.y)
		{
			AttackFlag = 1;
		}
		else
		{
			if (AttackFlag == 1)
			{
				AttackFlag = 0;
				return 1;
			}
		}
	}
	else
	{
		// Item Flag 2
		float a = Get3DPythagorean(pb[1].rightHand, pb[1].leftHand);
		float b = Get3DPythagorean(pb[1].rightShoulder, pb[1].rightElbow) / 2;
		if (a < b)
			AttackFlag = 1;
		else
		{
			if (AttackFlag == 1)
			{
				AttackFlag = 0;
				return 1;
			}
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE) > 0)
		return 1;
	return 0;
}

int K_KinectHandler::CheckChangeWeapon(void)
{


	if (pb[1].rightWrist.z < pb[1].leftHip.z && pb[1].rightWrist.x < pb[1].leftHip.x && pb[1].rightWrist.y < pb[1].leftHip.y)
		ChangeWeaponFlag = 1;
	else
	{
		if (ChangeWeaponFlag == 1)
		{
			ChangeWeaponFlag = 0;
			return 1;
		}
	}

	if (CheckHitKey(KEY_INPUT_E) > 0)
		return 1;
	return 0;

}

int K_KinectHandler::CheckEscapeGame(void)
{

	if (pb[1].leftElbow.y > pb[1].head.y && pb[1].rightElbow.y > pb[1].head.y)
		return 2;

	if (CheckHitKey(KEY_INPUT_ESCAPE) > 0)
		return 1;
	else if (CheckHitKey(KEY_INPUT_P) > 0)
		return 2;
	return 0;

}

void K_KinectHandler::Kinect_End(void)
{


}
