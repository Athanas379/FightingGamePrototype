#include "Player.h"

Player::Player(int x, int y, string spritefilename) : GameObject(x, y)
{
	mSpriteFilename = spritefilename;
	mSprite = new Image(x, y, spritefilename);
}

Player::~Player()
{

}

void Player::MoveUp(void)
{
	SetY(GetY() - 5);
}

void Player::MoveDown(void)
{
	SetY(GetY() + 5);
}

void Player::MoveLeft(void)
{
	SetX(GetX() - 5);
}

void Player::MoveRight(void)
{
	SetX(GetX() + 5);
}

void Player::Render(void)
{
	mSprite->SetX(GetX());
	mSprite->SetY(GetY());
	mSprite->Render();
}

