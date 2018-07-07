#include "SoundManager.h"

SoundManager::SoundManager()
{
	LoadSounds();
}

SoundManager::~SoundManager()
{
	for (int i = 0; i < mAllMusicTracks.size(); i++)
		delete(mAllMusicTracks[i]);

	mAllMusicTracks.clear();

	for (int i = 0; i < mAllSoundEffects.size(); i++)
		delete(mAllSoundEffects[i]);

	mAllSoundEffects.clear();
}

void SoundManager::LoadSounds(void)
{
	//SoundEffects
	mAllSoundEffects.push_back(new SoundEffect("Assets/TESTWAV.wav", mAllSoundEffects.size() + 1));
	
	//MusicTracks
	mAllMusicTracks.push_back(new MusicTrack("Assets/TESTMUS.wav", mAllMusicTracks.size() + 1));
}

void SoundManager::PlayMusic(int MusicID)
{
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(GetMusicFromID(MusicID), -1);	
}

void SoundManager::StopMusic(int MusicID)
{
	Mix_HaltMusic();
}

void SoundManager::PauseMusic(int MusicID)
{
	if (Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
	else
		Mix_PauseMusic();
}

void SoundManager::PlaySound(int SoundID)
{
	Mix_PlayChannel(-1, GetSoundFromID(SoundID), 0);
}

Mix_Music* SoundManager::GetMusicFromID(int ID)
{
	for (int i = 0; i < mAllMusicTracks.size(); i++)
	{
		if (mAllMusicTracks[i]->mID == ID)
			return mAllMusicTracks[i]->mMusicTrack;
	}
}

Mix_Chunk* SoundManager::GetSoundFromID(int ID)
{
	for (int i = 0; i < mAllSoundEffects.size(); i++)
	{
		if (mAllSoundEffects[i]->mID == ID)
			return mAllSoundEffects[i]->mSoundEffect;
	}
}
