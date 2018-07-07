#include "MainMenu.h"

MainMenu::MainMenu()
{
	mMenuBackground = new Image(0, 0, "Assets/MainMenuBackground.jpg");
}

MainMenu::~MainMenu()
{

}

void MainMenu::Update(void)
{

}

void MainMenu::Render(void)
{
	mMenuBackground->Render();
}

