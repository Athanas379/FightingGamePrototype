#include "GameObject.h"

GameObject::GameObject(int x, int y)
{
	mXPos = x;
	mYPos = y;
}

GameObject::~GameObject()
{

}

int GameObject::GetX(void)
{
	return mXPos;
}

int GameObject::GetY(void)
{
	return mYPos;
}

int GameObject::GetWidth(void)
{
	return mWidth;
}

int GameObject::GetHeight(void)
{
	return mHeight;
}

void GameObject::SetX(int x)
{
	mXPos = x;
}

void GameObject::SetY(int y)
{
	mYPos = y;
}

void GameObject::SetWidth(int width)
{
	mWidth = width;
}

void GameObject::SetHeight(int height)
{
	mHeight = height;
}
