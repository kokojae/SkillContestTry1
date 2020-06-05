#include "DXUT.h"
#include "GameManager.h"
#include "SkillContestTry1.h"

Player* GameManager::player = nullptr;
bool GameManager::isBombing = false;

void GameManager::Init()
{
	GraphicManager::Init();
	SoundManager::Init();
	SceneManager::LoadScene(SceneManager::Scene::TITLE);

	RankManager::AddRank(L"IAM", 5882);
	RankManager::AddRank(L"ASE", 6974);
	RankManager::AddRank(L"XYK", 4064);
	RankManager::AddRank(L"ING", 7941);
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
		// F1Ű ���� �÷��� �� ����/���� ���°� �ȴ�. ��۷� ó��
		if (player != nullptr)
			player->isImmortal = !player->isImmortal;
	}
	if (GetAsyncKeyState(VK_F2))
	{
		// F2Ű ������ 1�ܰ� ��½�Ų��. (������ ���� ó�� ����) 5������ �ƴ� ���
		if (player != nullptr)
			player->LevelUp(true);
	}
	if (GetAsyncKeyState(VK_F3))
	{
		// F3Ű �������� 1�� ������Ų��.
	}
	if (GetAsyncKeyState(VK_F4))
	{
		// F4Ű �޴� ȭ������ ��ȯ
		SceneManager::LoadScene(SceneManager::Scene::TITLE);
	}
	if (GetAsyncKeyState(VK_F5))
	{
		// F5Ű ��������1�� ��ȯ
		SceneManager::LoadScene(SceneManager::Scene::STAGE1);
	}
	if (GetAsyncKeyState(VK_F6))
	{
		// F6Ű ��������2�� ��ȯ
		SceneManager::LoadScene(SceneManager::Scene::STAGE2);
	}
	if (GetAsyncKeyState(VK_F7))
	{
		// F7Ű	�÷��̾� ����, ������� ������ ����ġ, �� ���� ���� �ʿ��� ����ġ ���̺� ������ ȭ�鿡 ǥ��
	}

}
