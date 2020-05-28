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

	switch (scene)
	{
	case SceneManager::Scene::TITLE:
		ObjectManager::Instantiate<Player>();
		break;
	case SceneManager::Scene::RANK_BOARD:
		break;
	case SceneManager::Scene::STAGE1:
		break;
	case SceneManager::Scene::STAGE2:
		break;
	case SceneManager::Scene::RESULT:
		break;
	case SceneManager::Scene::RANK_INPUT:
		break;
	default:
		break;
	}
}
