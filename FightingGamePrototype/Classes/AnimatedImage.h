#pragma once

#include <SDL.h>
#include <iostream>
#include "Image.h"
#include "SDLVariables.h"

using namespace std;

class AnimatedImage : public Image
{

private:

	int mSpriteWidth;
	int mSpriteHeight;
	int mNumOfSprites;
	SDL_Rect* mSprites = NULL;

public:

	AnimatedImage(int x, int y, string filepath, int NumSpritesWidth, int NumSpritesHeight, int NumOfSprites);
	~AnimatedImage();

	void Render(int SpriteTag);
};
