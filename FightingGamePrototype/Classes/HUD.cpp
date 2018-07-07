#include "HUD.h"

HUD::HUD()
{
	mHealthBar1 = new Image(70, 30, "Assets/HealthBar.png");
	mHealthBar2 = new Image(710, 30, "Assets/HealthBar.png");
	mCursor = new Image(0, 0, "Assets/Fist.png");

	mHealthOffset1 = 0;
	mHealthOffset2 = 0;
}

HUD::~HUD()
{

}

void HUD::UpdateHUD(int Playerhealth, int EnemyHealth)
{
	if (mHealthOffset1 >= 100 || mHealthOffset2 >= 100)
		return;

	mHealthOffset1 = (Playerhealth - 100) * -1;
	mHealthOffset2 = (EnemyHealth - 100) * -1;
}

void HUD::Render()
{
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);

	SDL_Rect HealthBar1Rect = {70 + (mHealthOffset1 * 5), 30, 500 - (mHealthOffset1 * 5), 50};
	SDL_Rect HealthBar2Rect = { 710, 30, 500 - (mHealthOffset2 * 5), 50 };
	
	SDL_RenderFillRect(gRenderer, &HealthBar1Rect);
	SDL_RenderFillRect(gRenderer, &HealthBar2Rect);

	mHealthBar1->Render();
	mHealthBar2->Render();
	mCursor->Render();
}

Image* HUD::GetCursor()
{
	return mCursor;
}
