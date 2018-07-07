#pragma once

#include <SDL.h>
#include <iostream>
#include "Image.h"

using namespace std;

class HUD
{

private:

	Image* mCursor;
	Image* mHealthBar1;
	Image* mHealthBar2;

	int mHealthOffset1;
	int mHealthOffset2;

public:

	HUD();
	~HUD();

	void UpdateHUD(int Playerhealth, int Enemyhealth);
	void Render();
	Image* GetCursor();
};
