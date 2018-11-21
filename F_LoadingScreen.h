#pragma once
class F_LoadingScreen
{
	float screenTime;
	int screenFlag;
	int rc, gc, bc;
	int loadtime;
	int loadCount;
public:
	int img_LoadScreen;

	F_LoadingScreen(void);
	~F_LoadingScreen(void);

	int ProjectLoadScreen(int screenX, int screenY, int LoadTime);
	void RandomFriendlyTips(int random);
	void RandomDidYouKnow(int random);
};

