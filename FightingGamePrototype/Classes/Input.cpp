#include "Input.h"

Input::Input()
{
	mUp = false;
	mDown = false;
	mLeft = false;
	mRight = false;
	mSpace = false;

	mLeftClick = false;
	mRightClick = false;
	mMiddleClick = false;

	mMousePosX = 0;
	mMousePosY = 0;
	mMouseOnScreen = false;

	mSinglePressLeft = 0;
	mSinglePressRight = 0;
	mSinglePressUp = 0;
	mSinglePressDown = 0;
}

Input::~Input()
{

}

bool Input::Up()
{
	return mUp;
}

bool Input::SinglePressUp()
{
	if (mSinglePressUp == 0)
		return mUp;
	else if (mSinglePressUp == 1)
	{
		mSinglePressUp = 2;
		return mUp;
	}
	else if (mSinglePressUp == 2)
		return false;
}

bool Input::Down()
{
	return mDown;
}

bool Input::SinglePressDown()
{
	if (mSinglePressDown == 0)
		return mDown;
	else if (mSinglePressDown == 1)
	{
		mSinglePressDown = 2;
		return mDown;
	}
	else if (mSinglePressDown == 2)
		return false;
}

bool Input::Left()
{
	return mLeft;
}

bool Input::SinglePressLeft()
{
	if (mSinglePressLeft == 0)
		return mLeft;
	else if (mSinglePressLeft == 1)
	{		
		mSinglePressLeft = 2;
		return mLeft;
	}
	else if(mSinglePressLeft == 2)
		return false;
}

bool Input::Right()
{
	return mRight;
}

bool Input::SinglePressRight()
{
	if (mSinglePressRight == 0)
		return mRight;
	else if (mSinglePressRight == 1)
	{
		mSinglePressRight = 2;
		return mRight;
	}
	else if (mSinglePressRight == 2)
		return false;
}

bool Input::LeftClick()
{
	return mLeftClick;
}

bool Input::SinglePressLeftClick()
{
	return 0;
}

bool Input::RightClick()
{
	return mRightClick;
}

bool Input::SinglePressRightClick()
{
	return 0;
}

bool Input::Space()
{
	return mSpace;
}

int Input::GetMouseX()
{
	return mMousePosX;
}

int Input::GetMouseY()
{
	return mMousePosY;
}

bool Input::GetMouseOnscreen()
{
	return mMouseOnScreen;
}

void Input::UpdateMouse(SDL_Event* MouseEvent)
{
	if (MouseEvent->type == SDL_MOUSEMOTION)
	{
		SDL_GetMouseState(&mMousePosX, &mMousePosY);

		if (mMousePosX == 0 || mMousePosX == 1280 || mMousePosY == 0 || mMousePosY == 800)
			mMouseOnScreen = false;
		else
			mMouseOnScreen = true;
	}

	if (MouseEvent->type == SDL_MOUSEBUTTONDOWN)
	{
		if (MouseEvent->button.button == SDL_BUTTON_LEFT)
		{
			mLeftClick = true;
		}
		if (MouseEvent->button.button == SDL_BUTTON_RIGHT)
		{
			mRightClick = true;
		}
		if (MouseEvent->button.button == SDL_BUTTON_MIDDLE)
		{
			mMiddleClick = true;
		}			
	}

	if (MouseEvent->type == SDL_MOUSEBUTTONUP)
	{
		if (MouseEvent->button.button == SDL_BUTTON_LEFT)
		{
			mLeftClick = false;
		}
		if (MouseEvent->button.button == SDL_BUTTON_RIGHT)
		{
			mRightClick = false;
		}
		if (MouseEvent->button.button == SDL_BUTTON_MIDDLE)
		{
			mMiddleClick = false;
		}
	}
}

void Input::UpdateKeyboard(SDL_Event* KeyboardEvent)
{
	if (KeyboardEvent->type == SDL_KEYDOWN)
	{
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_UP || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_W)
		{
			mUp = true;

			if(mSinglePressUp == 0)
				mSinglePressUp = 1;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_DOWN || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_S)
		{
			mDown = true;

			if(mSinglePressDown == 0)
				mSinglePressDown = 1;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_LEFT || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_A)
		{
			mLeft = true;

			if(mSinglePressLeft == 0)
				mSinglePressLeft = 1;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_RIGHT || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_D)
		{
			mRight = true;

			if (mSinglePressRight == 0)
				mSinglePressRight = 1;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_SPACE)
			mSpace = true;
	}
	if (KeyboardEvent->type == SDL_KEYUP)
	{
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_UP || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_W)
		{
			mUp = false;
			mSinglePressUp = 0;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_DOWN || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_S)
		{
			mDown = false;
			mSinglePressDown = 0;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_LEFT || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_A)
		{
			mLeft = false;
			mSinglePressLeft = 0;
		}			
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_RIGHT || KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_D)
		{
			mRight = false;
			mSinglePressRight = 0;
		}
		if (KeyboardEvent->key.keysym.scancode == SDL_SCANCODE_SPACE)
			mSpace = false;
	}
}