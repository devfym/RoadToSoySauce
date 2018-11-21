#include "DisplayDebugData.h"
#include <DxLib.h>
#include "DataList.h"

DisplayDebugData::DisplayDebugData(void)
{
}


DisplayDebugData::~DisplayDebugData(void)
{
}

void DisplayDebugData::DisplayK_KinectHandler(int cursorX, int cursorY, int cursorFlag)
{

	DrawFormatString(STR_LEFT_X, 10, BC_BLACK, "Cursor X = %d", cursorX);
	DrawFormatString(STR_LEFT_X, 30, BC_BLACK, "Cursor Y = %d", cursorY);
	DrawFormatString(STR_LEFT_X, 50, BC_BLACK, "Cursor FLAG = %d", cursorFlag);

}
