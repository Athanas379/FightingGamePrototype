#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

class Timer
{

private:

	Uint32 mStartTicks;
	Uint32 mPausedTicks;
	bool mPaused;
	bool mStarted;

public:

	Timer();
	~Timer();

	void Start(void);
	void Stop(void);
	void Pause(void);
	void Unpause(void);
	Uint32 GetTicks(void);
	void Reset();

	bool GetStarted(void);
	void SetStarted(bool Started);
	bool GetPaused(void);
	void SetPaused(bool Paused);
};
