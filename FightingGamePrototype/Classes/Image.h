#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "SDLVariables.h"

using namespace std;

class Image : public GameObject
{

private:


protected:

	SDL_Texture* mImage;
	string mFilePath;

public:

	Image(int x, int y, string filepath);
	~Image();

	void LoadImage(void);
	void SetColour(int r, int g, int b);
	void SetBlendMode(SDL_BlendMode blending);
	void SetAlpha(int a);

	void Render(void);
	void Render(SDL_Rect* RenderSection);
};
