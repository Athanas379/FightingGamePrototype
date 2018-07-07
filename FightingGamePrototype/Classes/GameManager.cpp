#include "GameManager.h"
#include "Collision.h"
#include "SDLVariables.h"

GameManager::GameManager()
{
	mInput = new Input();

	mQuitFlag = false;

	mFpsTimer = new Timer();
	mFpsCapTimer = new Timer();
	mCountedFrames = 0;
	mFpsTimer->Start();
}

GameManager::~GameManager(void)
{
}

void GameManager::Update(void)
{
	LoadMedia();
	GameSetup();

	//While application is running
	while (!mQuitFlag)
	{
		mFpsCapTimer->Start();

		//Handle events on queue
		while (SDL_PollEvent(&mEvent) != 0)
		{
			//User requests quit
			if (mEvent.type == SDL_QUIT)
			{
				mQuitFlag = true;
			}
			if (mEvent.type == SDL_MOUSEMOTION || mEvent.type == SDL_MOUSEBUTTONDOWN || mEvent.type == SDL_MOUSEBUTTONUP)
			{
				mInput->UpdateMouse(&mEvent);
			}
			if (mEvent.type == SDL_KEYDOWN || mEvent.type == SDL_KEYUP)
			{
				mInput->UpdateKeyboard(&mEvent);
			}

		}

		float avgFPS = mCountedFrames / (mFpsTimer->GetTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		//update cursor location
		mHUD->GetCursor()->SetX(mInput->GetMouseX() - 25);
		mHUD->GetCursor()->SetY(mInput->GetMouseY() - 25);

		
		if (mInput->SinglePressDown())
		{
			mEnemy->SetWidth(mEnemy->GetWidth() - 10);
			cout << mEnemy->GetWidth() << endl;
		}
		else if (mInput->Down())
		{
		}
		else if (mInput->Left())
		{
		}
		else if (mInput->Right())
		{
		}

		Render();

		mCountedFrames++;
		int frameTicks = mFpsCapTimer->GetTicks();
		if (frameTicks < mFrameTicksPerSecond)
		{
			//Wait remaining time
			SDL_Delay(mFrameTicksPerSecond - frameTicks);
		}

	}
}

bool GameManager::LoadMedia(void)
{
	return true;
}

void GameManager::Render(void)
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	mBackground->Render();

	mEnemy->Render();

	mHUD->Render();

	//Update screen
	SDL_RenderPresent(gRenderer);
}

void GameManager::GameSetup(void)
{
	//Create the Player
	//Create the Map
	mBackground = new Image(0, 0, "Assets/Background.png");
	//Create the Enemies
	mEnemy = new Enemy(485, 150, "Assets/Enemy.png");
	//Create the HUD
	mHUD = new HUD();
	//Create the Sounds
}