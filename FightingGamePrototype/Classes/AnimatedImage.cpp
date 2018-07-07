#include "AnimatedImage.h"

AnimatedImage::AnimatedImage(int x, int y, string filepath, int NumSpritesWidth, int NumSpritesHeight, int NumOfSprites) : Image(x, y, filepath)
{
	mSpriteWidth = mWidth / NumSpritesWidth;
	mSpriteHeight = mHeight / NumSpritesHeight;
	mNumOfSprites = NumOfSprites;
	mSprites = new SDL_Rect[mNumOfSprites];

	for (int spritecounter = 0, i = 0, j = 0; spritecounter < NumOfSprites; spritecounter++, i++)
	{
		if (i * mSpriteWidth == mWidth)
		{
			i = 0;
			j++;
		}

		mSprites[spritecounter] = { i * mSpriteWidth, j * mSpriteHeight, mSpriteWidth, mSpriteHeight };
	}
}

AnimatedImage::~AnimatedImage()
{

}

void AnimatedImage::Render(int SpriteTag)
{
	SDL_Rect Location = { mXPos, mYPos, mWidth, mHeight };

	Location.w = mSprites[SpriteTag].w;
	Location.h = mSprites[SpriteTag].h;

	SDL_RenderSetViewport(gRenderer, NULL);
	SDL_RenderCopy(gRenderer, mImage, &mSprites[SpriteTag], &Location);
}



