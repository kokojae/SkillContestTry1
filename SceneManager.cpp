#include "DXUT.h"
#include "SceneManager.h"
#include "SkillContestTry1.h"

SceneManager::Scene SceneManager::currentScene = SceneManager::Scene();

void SceneManager::LoadScene(Scene scene)
{
	currentScene = scene;

	Camera::position = { 0,0 };
	Camera::degree = 0;
	Camera::scale = 1;

	ObjectManager::Clear();
	SoundManager::EndAllSFX();

	GameManager::player = nullptr;

	switch (scene)
	{
	case SceneManager::Scene::TITLE:
		ObjectManager::Instantiate<Title>();
		break;
	case SceneManager::Scene::RANK_BOARD:
		ObjectManager::Instantiate<RankBoard>();
		break;
	case SceneManager::Scene::STAGE1:
		ObjectManager::Instantiate<BackGround>({ 2600 - SCREEN_WIDTH / 2,0 });
		ObjectManager::Instantiate<Player>();
		ObjectManager::Instantiate<ItemHeal>({ 500 ,0 });
		ObjectManager::Instantiate<ItemHeal>({ 1000 ,0 });
		for (int i = 0; i < 5; i++)
		{
			ObjectManager::Instantiate<Enemy>({ 300,((float)i * 150) - 180 });
		}
		ObjectManager::Instantiate<Boss>({ SCREEN_WIDTH, 0 });
		break;
	case SceneManager::Scene::STAGE2:
		break;
	case SceneManager::Scene::RESULT:
		break;
	case SceneManager::Scene::RANK_INPUT:
		ObjectManager::Instantiate<RankInput>();
		break;
	default:
		break;
	}
}
