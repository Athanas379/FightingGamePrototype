#include "Image.h"

Image::Image(int x, int y, string filepath) : GameObject( x, y)
{
	mFilePath = filepath;
	LoadImage();
}

Image::~Image()
{
	SDL_DestroyTexture(mImage);
	mImage = NULL;
}

void Image::LoadImage(void)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(mFilePath.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", mFilePath.c_str(), SDL_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		mImage = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (mImage == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", mFilePath.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
			SetBlendMode(SDL_BLENDMODE_BLEND);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

void Image::SetColour(int r, int g, int b)
{
	SDL_SetTextureColorMod(mImage, r, g, b);
}

void Image::SetBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mImage, blending);
}

void Image::SetAlpha(int a)
{
	SDL_SetTextureAlphaMod(mImage, a);
}

void Image::Render(void)
{
	SDL_Rect Location = { mXPos, mYPos, mWidth, mHeight };

	SDL_RenderSetViewport(gRenderer, NULL);
	SDL_RenderCopy(gRenderer, mImage, NULL, &Location);
}

void Image::Render(SDL_Rect* RenderSection)
{
	SDL_Rect Location = { mXPos, mYPos, mWidth, mHeight };

	if (RenderSection != NULL)
	{
		Location.w = RenderSection->w;
		Location.h = RenderSection->h;
	}

	SDL_RenderSetViewport(gRenderer, NULL);
	SDL_RenderCopy(gRenderer, mImage, RenderSection, &Location);
}

