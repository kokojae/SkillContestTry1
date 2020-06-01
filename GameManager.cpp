#include "DXUT.h"
#include "GameManager.h"
#include "SkillContestTry1.h"

Player* GameManager::player = nullptr;

void GameManager::Init()
{
	GraphicManager::Init();
	SoundManager::Init();
	SceneManager::LoadScene(SceneManager::Scene::TITLE);
}

void GameManager::Update()
{
	CheatKey();
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

void GameManager::CheatKey()
{
	if (GetAsyncKeyState(VK_F1))
	{
		// F1키 게임 플레이 시 무적/비무적 상태가 된다. 토글로 처리
		if (player != nullptr)
			player->isImmortal = !player->isImmortal;
	}
	if (GetAsyncKeyState(VK_F2))
	{
		// F2키 레벨을 1단계 상승시킨다. (레벨업 보상 처리 동일) 5레벨이 아닌 경우
		if (player != nullptr)
			player->LevelUp(true);
	}
	if (GetAsyncKeyState(VK_F3))
	{
		// F3키 아이템을 1개 생성시킨다.
	}
	if (GetAsyncKeyState(VK_F4))
	{
		// F4키 메뉴 화면으로 전환
		SceneManager::LoadScene(SceneManager::Scene::TITLE);
	}
	if (GetAsyncKeyState(VK_F5))
	{
		// F5키 스테이지1로 전환
		SceneManager::LoadScene(SceneManager::Scene::STAGE1);
	}
	if (GetAsyncKeyState(VK_F6))
	{
		// F6키 스테이지2로 전환
		SceneManager::LoadScene(SceneManager::Scene::STAGE2);
	}
	if (GetAsyncKeyState(VK_F7))
	{
		// F7키	플레이어 레벨, 현재까지 누적된 경험치, 각 레벨 업에 필요한 경험치 테이블 제시한 화면에 표현
	}

}
