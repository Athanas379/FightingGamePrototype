#include "Text.h"

Text::Text(int x, int y, string text, SDL_Color textcolour) : GameObject(x, y)
{
	mText = text;
	mColour = textcolour;
	mFont = TTF_OpenFont("Assets/vgafix.fon", 28);
	LoadText();
}

Text::~Text()
{
	SDL_DestroyTexture(mTextImage);
	mTextImage = NULL;
}

void Text::LoadText(void)
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText.c_str(), mColour);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTextImage = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTextImage == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
}

void Text::Render(void)
{
	SDL_Rect Location = { mXPos, mYPos, mWidth, mHeight };

	SDL_RenderSetViewport(gRenderer, NULL);
	SDL_RenderCopy(gRenderer, mTextImage, NULL, &Location);
}

void Text::Render(SDL_Rect* RenderSection)
{
	SDL_Rect Location = { mXPos, mYPos, mWidth, mHeight };

	if (RenderSection != NULL)
	{
		Location.w = RenderSection->w;
		Location.h = RenderSection->h;
	}

	SDL_RenderSetViewport(gRenderer, NULL);
	SDL_RenderCopy(gRenderer, mTextImage, RenderSection, &Location);
}

void Text::SetText(string text)
{
	mText = text;
	LoadText();
}

string Text::GetText(void)
{
	return mText;
}

