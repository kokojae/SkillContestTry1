#include "DXUT.h"
#include "GameManager.h"
#include "SkillContestTry1.h"

void GameManager::Init()
{
	GraphicManager::Init();
	SoundManager::Init();
	SceneManager::LoadScene(SceneManager::Scene::TITLE);
}

void GameManager::Update()
{
	ObjectManager::Update();
}

void GameManager::LateUpdate()
{
	ObjectManager::LateUpdate();
}

void GameManager::Render()
{
	GraphicManager::Render();
}

void GameManager::Release()
{
	SoundManager::EndAllSFX();
	ObjectManager::Release();
	TextureManager::ReleaseTexture();
	GraphicManager::Release();
}
