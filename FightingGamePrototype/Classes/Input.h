#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

class Input
{

private:

	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;
	bool mSpace;
	bool mLeftClick;
	bool mRightClick;
	bool mMiddleClick;
	const Uint8 *mKeyboardState;

	int mMousePosX;
	int mMousePosY;
	bool mMouseOnScreen;

	int mSinglePressRight;
	int mSinglePressLeft;
	int mSinglePressUp;
	int mSinglePressDown;

public:

	Input();
	~Input();
	bool Up();
	bool Down();
	bool Left();
	bool Right();
	bool Space();
	bool LeftClick();
	bool RightClick();

	bool SinglePressLeft();
	bool SinglePressRight();
	bool SinglePressUp();
	bool SinglePressDown();
	bool SinglePressLeftClick();
	bool SinglePressRightClick();

	int GetMouseX();
	int GetMouseY();
	bool GetMouseOnscreen();



	void UpdateMouse(SDL_Event* MouseEvent);
	void UpdateKeyboard(SDL_Event* KeyboardEvent);

};
