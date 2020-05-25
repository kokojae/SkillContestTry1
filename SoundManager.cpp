#include "DXUT.h"
#include "SoundManager.h"
#include "SDKsound.h"

CSoundManager* SoundManager::soundManager = nullptr;
std::map<std::wstring, CSound*> SoundManager::soundMap = std::map<std::wstring, CSound*>();

void SoundManager::Init()
{
	soundManager = new CSoundManager;
	soundManager->Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	soundManager->SetPrimaryBufferFormat(2, 22050, 16);
}

CSound* SoundManager::SearchSFX(std::wstring path)
{
	CSound* sfx;

	if (soundMap.count(path))
	{
		sfx = soundMap.find(path)->second;
	}
	else
	{
		soundManager->Create(
			&sfx,
			const_cast<wchar_t*>(path.c_str()),
			0,
			GUID_NULL);

		soundMap[path] = sfx;
	}

	return sfx;
}

void SoundManager::PlaySFX(std::wstring path, bool isBGM)
{
	CSound* sfx = SearchSFX(path);

	if (isBGM)
	{
		sfx->Play(0, DSBPLAY_LOOPING);
	}
	else
	{
		sfx->Reset();
		sfx->Play(0, NULL);
	}
}

void SoundManager::EndSFX(std::wstring path)
{
	if (soundMap.count(path))
	{
		CSound* sfx = soundMap.find(path)->second;
		sfx->Stop();
		sfx->Reset();
	}
}

void SoundManager::EndAllSFX()
{
	std::map<std::wstring, CSound*>::iterator it = soundMap.begin();

	while (it!=soundMap.end())
	{
		it->second->Stop();
		(it++)->second->Reset();
	}
}
