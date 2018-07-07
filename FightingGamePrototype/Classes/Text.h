#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"
#include "SDLVariables.h"

using namespace std;

class Text : public GameObject
{

private:

	string mText;
	SDL_Color mColour;
	TTF_Font *mFont;
	SDL_Texture* mTextImage;

public:

	Text(int x, int y, string text, SDL_Color textcolour);
	~Text();

	void LoadText(void);
	void SetText(string text);
	string GetText(void);

	void Render(void);
	void Render(SDL_Rect* RenderSection);
};
