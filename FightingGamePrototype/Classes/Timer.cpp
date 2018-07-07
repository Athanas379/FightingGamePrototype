#include "Timer.h"

Timer::Timer()
{
	mStartTicks = 0;
	mPausedTicks = 0;
	mPaused = false;
	mStarted = false;
}

Timer::~Timer()
{

}

void Timer::Start(void)
{
	mStarted = true;
	mPaused = false;
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void Timer::Stop(void)
{
	mStarted = false;
	mPaused = false;
	mStartTicks = 0;
	mPausedTicks = 0;
}

void Timer::Pause(void)
{
	if (mStarted && !mPaused)
	{
		mPaused = true;
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void Timer::Unpause(void)
{
	if (mStarted && mPaused)
	{
		mPaused = false;
		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

Uint32 Timer::GetTicks(void)
{
	Uint32 time = 0;

	if (mStarted)
	{
		if (mPaused)
		{
			time = mPausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

void Timer::Reset()
{
	mStartTicks = 0;
	mPausedTicks = 0;
}

bool Timer::GetStarted(void)
{
	return mStarted;
}

void Timer::SetStarted(bool Started)
{
	mStarted = Started;
}

bool Timer::GetPaused(void)
{
	return mPaused;
}

void Timer::SetPaused(bool Paused)
{
	mPaused = Paused;
}
