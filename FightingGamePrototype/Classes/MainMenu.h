#pragma once

#include <SDL.h>
#include <iostream>
#include "Image.h"
#include "SDLVariables.h"

using namespace std;

class MainMenu
{

private:

	Image* mMenuBackground;

public:

	MainMenu();
	~MainMenu();
	void Update(void);
	void Render(void);
};
