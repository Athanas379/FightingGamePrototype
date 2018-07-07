#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Input.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Timer.h"
#include "Player.h"
#include "HUD.h"
#include "Enemy.h"

using namespace std;

class GameManager
{

private:

	Enemy* mEnemy;

	Input* mInput;
	HUD* mHUD;

	//Game Elements
	Image* mBackground;

	SDL_Event mEvent;

	const int mFramesPerSecond = 60;
	const int mFrameTicksPerSecond = 1000 / mFramesPerSecond;
	Timer* mFpsTimer;
	Timer* mFpsCapTimer;
	int mCountedFrames;

	bool mQuitFlag;

public:

	GameManager();
	~GameManager();

	void GameSetup(void);

	void Update(void);
	bool LoadMedia(void);
	void Render(void);


};