#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "Image.h"
#include "SDLVariables.h"

using namespace std;

class Player : public GameObject
{

private:

	string mSpriteFilename;
	Image* mSprite;

public:

	Player(int x, int y, string spritefilename);
	~Player();

	void MoveUp(void);
	void MoveDown(void);
	void MoveLeft(void);
	void MoveRight(void);

	void Render(void);

};
