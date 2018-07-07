#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "Image.h"
#include "SDLVariables.h"

using namespace std;

class Enemy : public GameObject
{

private:

	string mSpriteFilename;
	Image* mSprite;

public:

	Enemy(int x, int y, string spritefilename);
	~Enemy();

	void Render(void);

};
