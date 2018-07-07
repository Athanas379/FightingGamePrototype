#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
#include <vector>

using namespace std;

class SoundManager
{

private:

	struct SoundEffect
	{
		SoundEffect(string filepath, int ID)
		{
			mFilepath = filepath;
			mSoundEffect = Mix_LoadWAV(filepath.c_str());
			mID = ID;
		}

		Mix_Chunk* GetSound(void)
		{
			return mSoundEffect;
		}

		string mFilepath;
		Mix_Chunk* mSoundEffect;
		int mID;
	};

	struct MusicTrack
	{
		MusicTrack(string filepath, int ID)
		{
			mFilepath = filepath;
			mMusicTrack = Mix_LoadMUS(filepath.c_str());
			mID = ID;
		}

		Mix_Music* GetMusic(void)
		{
			return mMusicTrack;
		}

		string mFilepath;
		Mix_Music* mMusicTrack;
		int mID;
	};

	vector<SoundEffect*> mAllSoundEffects;
	vector<MusicTrack*> mAllMusicTracks;

public:

	SoundManager();
	~SoundManager();

	void LoadSounds();

	void PlayMusic(int MusicID);
	void StopMusic(int MusicID);
	void PauseMusic(int MusicID);

	void PlaySound(int SoundID);

	Mix_Music* GetMusicFromID(int ID);
	Mix_Chunk* GetSoundFromID(int ID);
};
