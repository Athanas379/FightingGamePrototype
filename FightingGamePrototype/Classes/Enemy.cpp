#include "Enemy.h"

Enemy::Enemy(int x, int y, string spritefilename) : GameObject(x, y)
{
	mSpriteFilename = spritefilename;
	mSprite = new Image(x, y, spritefilename);
	mWidth = mSprite->GetWidth();
	mHeight = mSprite->GetHeight();
}

Enemy::~Enemy()
{

}


void Enemy::Render(void)
{
	mSprite->SetX(GetX());
	mSprite->SetY(GetY());
	mSprite->Render();
}

