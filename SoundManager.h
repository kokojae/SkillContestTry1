#pragma once
#include <iostream>
#include <map>
class CSoundManager;
class CSound;

class SoundManager
{
public:
	static CSoundManager* soundManager;

	static std::map<std::wstring, CSound*> soundMap;

	static void Init();

	static CSound* SearchSFX(std::wstring path);
	static void PlaySFX(std::wstring path, bool isBGM = false);
	static void EndSFX(std::wstring path);
	static void EndAllSFX();
};

