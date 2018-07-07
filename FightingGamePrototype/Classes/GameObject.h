#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "SDLVariables.h"

using namespace std;

class GameObject
{

private:

protected: 

	int mXPos;
	int mYPos;
	int mWidth;
	int mHeight;

public:

	GameObject(int x, int y);
	~GameObject();

	int GetX(void);
	int GetY(void);
	int GetWidth(void);
	int GetHeight(void);
	void SetX(int x);
	void SetY(int y);
	void SetWidth(int width);
	void SetHeight(int height);

};
